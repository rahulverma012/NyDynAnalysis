#include <chrono>
const int nClass = 5;
const int nSubSample = 10;
unsigned int seed = 123456789; // Seed value; you can change it to any fixed integer

template<typename T>
void PrintTime(T Start, std::string String){
  auto Stop = chrono::high_resolution_clock::now();
  auto Duration = duration_cast<microseconds>(Stop-Start);
  cout<<String<<float(Duration.count())/float(1000000)<<" seconds"<<endl;
}

Int_t    GetBinFromTHnSparse(THnSparse* hsparse,Int_t AxisNo, double val ){ return hsparse->GetAxis(AxisNo)->FindBin(val);}
Double_t GetBinWidthOfAxis  (THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return hsparse->GetAxis(AxisNo)->GetBinWidth(BinNo);}
Double_t GetBinCenterOfAxis (THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return hsparse->GetAxis(AxisNo)->GetBinCenter(BinNo);}
Double_t GetBinLowEdgeOfAxis(THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return hsparse->GetAxis(AxisNo)->GetBinLowEdge(BinNo);}
Double_t GetBinUpEdgeOfAxis (THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return (hsparse->GetAxis(AxisNo)->GetBinLowEdge(BinNo)+hsparse->GetAxis(AxisNo)->GetBinWidth(BinNo));}

int GetRndmRandomNumber(TRandom3 &randomGenerator, int Length){
  int randomValue = randomGenerator.Rndm()*Length; // Uniform number between 0 and 1
  if (randomValue == Length){ randomValue = Length -1;}
  return randomValue;
}

template<typename T>
void GetMeanAndErrorFromSubSampling(double X_Mean[], double X_Sigma[], 
  const T&SubSampleArr
) {
    double X_Sum [nClass] ;
    double X_Sum2[nClass] ;

    for(int iClass = 0 ; iClass < nClass ; iClass++){
      X_Sum [iClass] = 0;
      X_Sum2[iClass] = 0;
      for(int iSubSample = 0; iSubSample < nSubSample; iSubSample++){
        X_Sum [iClass] += SubSampleArr[iSubSample][iClass];
        X_Sum2[iClass] += std::pow(SubSampleArr[iSubSample][iClass], 2.0);
      }

      X_Mean[iClass] = X_Sum[iClass]/nSubSample;
      double tempVal =   X_Sum2[iClass] 
                      + nSubSample*std::pow(X_Mean[iClass],2)
                      - 2.0*X_Mean[iClass]*X_Sum[iClass];

      double sigma2 = tempVal/static_cast<double>(nSubSample-1);
      double error  = std::sqrt(sigma2/nSubSample);
      X_Sigma[iClass] = error; 
    }
}

template<typename T> 
int64_t FindEntriesPerSubSample(T hist, int nSubSample){
  cout<<endl<<"Finding Entries Per SubSample"<<endl;
  cout<<hist->GetName()<<" Total Entries = "<<std::setprecision(20)<<hist->GetEntries()<<endl;
  int64_t TotalEntries = hist->GetEntries();
  int64_t Entries = TotalEntries/nSubSample;
  int64_t Remainder  = TotalEntries%nSubSample;
  cout<<"Entries              = "<<Entries<<endl; //9995026
  cout<<"Remainder            = "<<Remainder<<endl;
  if( Remainder != 0){Entries++;}
  cout<<endl;
  // cout<<"Entries Per SubSample = "<<Entries<<endl;
  return Entries;
}

template<typename T, typename G>
void SparseAnalysis(const T& hSparse, const int& nClass, const std::vector<double> classLow, std::vector<double> classUp,
  const int &axisCl, const int& pairType, const int& axisA0, const int & axisA1, const int& axisB0, const int& axisB1,
  std::vector<double>& Rab, std::vector<double>& Raa, std::vector<double>& Rbb, std::vector<double>& NDy,
  G &grRab, G &grRaa, G &grRbb, G &grNDy,
  std::vector<double>& Rab_CBWC, std::vector<double>& Raa_CBWC, std::vector<double>& Rbb_CBWC, std::vector<double>& NDy_CBWC,
  G &grRab_CBWC, G &grRaa_CBWC, G &grRbb_CBWC, G &grNDy_CBWC)
{
  int BinCountCheck= 200000;
  const int nDim = hSparse->GetNdimensions();
  int THnBinValue[nDim];
  Double_t Xvar[nDim];
  Long64_t nBinsSparse = hSparse->GetNbins();
  Long64_t iBinEntries = 0;
  cout<<"    nBinsSparse :: "<<nBinsSparse<<endl;

  //Variables for analysis
  int Na ;
  int Nb ;

  double nEntries[nClass] ;
  double mean_Na[nClass]  ; double Sum_Na[nClass]   ;
  double mean_Na2[nClass] ; double Sum_Na2[nClass]  ;// 2 represents square
  double mean_Nb[nClass]  ; double Sum_Nb[nClass]   ;
  double mean_Nb2[nClass] ; double Sum_Nb2[nClass]  ;
  double mean_NaNb[nClass]; double Sum_NaNb[nClass] ;

  //debugger //debugging varaibles to check if everything is working
  double mean_NaCorr[nClass] ; double Sum_NaCorr[nClass] ;
  double mean_NbCorr[nClass] ; double Sum_NbCorr[nClass] ;

  double Raa_Corr[nClass];
  double Rbb_Corr[nClass];
  double Rab_Corr[nClass];
  // std::fill(&dN_PowerSum_nClass_NoCBWC[0][0], &dN_PowerSum_nClass_NoCBWC[0][0] + nClass*(nOrder+1), 0);
  //Initialize all to zero
  for (int iClass=0; iClass<nClass; iClass++){
    nEntries[iClass]  = 0;
    mean_Na[iClass]   = 0; Sum_Na[iClass]    = 0 ;
    mean_Na2[iClass]  = 0; Sum_Na2[iClass]   = 0 ;
    mean_Nb[iClass]   = 0; Sum_Nb[iClass]    = 0 ;
    mean_Nb2[iClass]  = 0; Sum_Nb2[iClass]   = 0 ;
    mean_NaNb[iClass] = 0; Sum_NaNb[iClass]  = 0 ;

    mean_NaCorr[iClass] = 0 ; Sum_NaCorr[iClass] = 0;
    mean_NbCorr[iClass] = 0 ; Sum_NbCorr[iClass] = 0;
  }

  //Debugging Part //Get all 1D hist definitions so that you can match and debug what you have filled
  TH1D* h1D[nDim];
  TH1D* h1D_nClass[nDim][nClass]; 
  for(int iAxis = 0 ; iAxis < nDim ; iAxis++){
    h1D[iAxis] = Get1DHist(hSparse,iAxis);
    for (int iClass = 0; iClass < nClass; iClass++) {
      h1D_nClass[iAxis][iClass] = GetClonedHist(h1D[iAxis], Form("nClass_%d",iClass), Form(":: centFT0C[%2.0f,%2.0f]",classLow[iClass], classUp[iClass]));
    }
  }

  // 2 represents square in the following
  //Error Analysis Part
  double nEntries_nSubSample  [nSubSample][nClass];
  double mean_Na_nSubSample   [nSubSample][nClass]; double Sum_Na_nSubSample   [nSubSample][nClass] ;
  double mean_Na2_nSubSample  [nSubSample][nClass]; double Sum_Na2_nSubSample  [nSubSample][nClass] ;
  double mean_Nb_nSubSample   [nSubSample][nClass]; double Sum_Nb_nSubSample   [nSubSample][nClass] ;
  double mean_Nb2_nSubSample  [nSubSample][nClass]; double Sum_Nb2_nSubSample  [nSubSample][nClass] ;
  double mean_NaNb_nSubSample [nSubSample][nClass]; double Sum_NaNb_nSubSample [nSubSample][nClass] ;

  //debugger //debugging varaibles to check if everything is working
  double mean_NaCorr_nSubSample[nSubSample][nClass] ; double Sum_NaCorr_nSubSample[nSubSample][nClass] ;
  double mean_NbCorr_nSubSample[nSubSample][nClass] ; double Sum_NbCorr_nSubSample[nSubSample][nClass] ;

  double Raa_Corr_nSubSample[nSubSample][nClass];
  double Rbb_Corr_nSubSample[nSubSample][nClass];
  double Rab_Corr_nSubSample[nSubSample][nClass];
  
  //Initialize all to zero _nSubSample[iSubSample]
  for (int iClass=0; iClass<nClass; iClass++){
    for( int iSubSample = 0; iSubSample<nSubSample; iSubSample++){
      nEntries_nSubSample[iSubSample][iClass]  = 0;
      mean_Na_nSubSample[iSubSample][iClass]   = 0; Sum_Na_nSubSample[iSubSample][iClass]    = 0 ;
      mean_Na2_nSubSample[iSubSample][iClass]  = 0; Sum_Na2_nSubSample[iSubSample][iClass]   = 0 ;
      mean_Nb_nSubSample[iSubSample][iClass]   = 0; Sum_Nb_nSubSample[iSubSample][iClass]    = 0 ;
      mean_Nb2_nSubSample[iSubSample][iClass]  = 0; Sum_Nb2_nSubSample[iSubSample][iClass]   = 0 ;
      mean_NaNb_nSubSample[iSubSample][iClass] = 0; Sum_NaNb_nSubSample[iSubSample][iClass]  = 0 ;

      mean_NaCorr_nSubSample[iSubSample][iClass] = 0 ; Sum_NaCorr_nSubSample[iSubSample][iClass] = 0;
      mean_NbCorr_nSubSample[iSubSample][iClass] = 0 ; Sum_NbCorr_nSubSample[iSubSample][iClass] = 0;
    }
  }

  const int nSmallClass = 100;
  double smallClassLow[nSmallClass];
  double smallClassUp[nSmallClass];
  for(int i = 0; i < nSmallClass; i++) { smallClassLow[i] = i * 100.0/double(nSmallClass) ; smallClassUp[i] = (i+1) * 100.0/double(nSmallClass) ;}
  smallClassLow[0] = -1.0; smallClassUp[nSmallClass-1] = 101.0;


  double nEntries_nSmallClass  [nSmallClass];
  double mean_Na_nSmallClass   [nSmallClass]; double Sum_Na_nSmallClass   [nSmallClass] ;
  double mean_Na2_nSmallClass  [nSmallClass]; double Sum_Na2_nSmallClass  [nSmallClass] ;
  double mean_Nb_nSmallClass   [nSmallClass]; double Sum_Nb_nSmallClass   [nSmallClass] ;
  double mean_Nb2_nSmallClass  [nSmallClass]; double Sum_Nb2_nSmallClass  [nSmallClass] ;
  double mean_NaNb_nSmallClass [nSmallClass]; double Sum_NaNb_nSmallClass [nSmallClass] ;

  //debugger //debugging varaibles to check if everything is working
  double mean_NaCorr_nSmallClass[nSmallClass] ; double Sum_NaCorr_nSmallClass[nSmallClass] ;
  double mean_NbCorr_nSmallClass[nSmallClass] ; double Sum_NbCorr_nSmallClass[nSmallClass] ;

  double Raa_Corr_nSmallClass[nSmallClass];
  double Rbb_Corr_nSmallClass[nSmallClass];
  double Rab_Corr_nSmallClass[nSmallClass];

  //Initialize all to zero _nSubSample[iSubSample]
    for( int iSmallClass = 0; iSmallClass < nSmallClass; iSmallClass++){
      nEntries_nSmallClass[iSmallClass]  = 0;
      mean_Na_nSmallClass[iSmallClass]   = 0; Sum_Na_nSmallClass[iSmallClass]    = 0 ;
      mean_Na2_nSmallClass[iSmallClass]  = 0; Sum_Na2_nSmallClass[iSmallClass]   = 0 ;
      mean_Nb_nSmallClass[iSmallClass]   = 0; Sum_Nb_nSmallClass[iSmallClass]    = 0 ;
      mean_Nb2_nSmallClass[iSmallClass]  = 0; Sum_Nb2_nSmallClass[iSmallClass]   = 0 ;
      mean_NaNb_nSmallClass[iSmallClass] = 0; Sum_NaNb_nSmallClass[iSmallClass]  = 0 ;

      mean_NaCorr_nSmallClass[iSmallClass] = 0 ; Sum_NaCorr_nSmallClass[iSmallClass] = 0;
      mean_NbCorr_nSmallClass[iSmallClass] = 0 ; Sum_NbCorr_nSmallClass[iSmallClass] = 0;
    }

  //Find Entries Per SubSample
  int64_t EntriesPerSubSample = FindEntriesPerSubSample(hSparse, nSubSample);
  cout<<"Entries Per SubSample = "<<EntriesPerSubSample<<endl;
  int64_t SubSampleEntryCounter[nSubSample]; int iSubSample = -1;
  for (int i = 0 ; i < nSubSample; i++){ SubSampleEntryCounter[i] = 0;}

  TRandom3 randomGenerator(seed);
  
  //Now looping over the bins
  auto Start1 = chrono::high_resolution_clock::now();
  auto Start2 = chrono::high_resolution_clock::now();

  int classNumber = -1;
  long int countFillCheck = 0 ;

  for(int iBin = 0 ; iBin < nBinsSparse ; iBin++){
    if(iBin % BinCountCheck == 0){
      cout<<endl;
      PrintTime(Start2, Form("    %s :: BinReading :: BinTime     :: iBin = %d :: ",hSparse->GetName(),iBin));
      PrintTime(Start1, Form("    %s :: BinReading :: ElapsedTime :: iBin = %d :: ",hSparse->GetName(),iBin));
      Start2 = chrono::high_resolution_clock::now();
    }
    hSparse->GetBinContent(int(iBin),THnBinValue);
    for(int iAxis = 0 ; iAxis < nDim ; iAxis++){
      Xvar[iAxis] = GetBinCenterOfAxis(hSparse, iAxis,THnBinValue[iAxis]);
    }
    iBinEntries = hSparse->GetBinContent(int(iBin));
    // //Direct Weight Filling
    // MasterHistogram->Fill(Xvar,iBinEntries);

    if(pairType == 0) { Na = int(Xvar[axisA0])                    ; Nb = int(Xvar[axisB0])                    ; }
    if(pairType == 1) { Na = int(Xvar[axisA0]) + int(Xvar[axisA1]); Nb = int(Xvar[axisB0])                    ; }
    if(pairType == 2) { Na = int(Xvar[axisA0]) + int(Xvar[axisA1]); Nb = int(Xvar[axisB0]) + int(Xvar[axisB1]); }
  
    classNumber = -1;
    for(int iClass = 0 ; iClass < nClass; iClass++){
      if(classLow[iClass] < Xvar[axisCl] && Xvar[axisCl] <= classUp[iClass]){
        classNumber = iClass;
        break;
      }
    }//classloop block

    Sum_Na[classNumber]   += iBinEntries*Na;
    Sum_Na2[classNumber]  += iBinEntries*Na*Na;
    Sum_Nb[classNumber]   += iBinEntries*Nb;
    Sum_Nb2[classNumber]  += iBinEntries*Nb*Nb;
    Sum_NaNb[classNumber] += iBinEntries*Na*Nb;
    nEntries[classNumber] += iBinEntries;

    Sum_NaCorr[classNumber] += iBinEntries*(Na*(Na-1));
    Sum_NbCorr[classNumber] += iBinEntries*(Nb*(Nb-1));

    // for(int iAxis = 0 ; iAxis < nDim ; iAxis++){
    //   h1D[iAxis]                     ->Fill(Xvar[iAxis], iBinEntries);
    //   h1D_nClass[iAxis][classNumber] ->Fill(Xvar[iAxis], iBinEntries);
    //  }

    int smallClassNumber = -1;
    for(int iSmallClass = 0 ; iSmallClass < nSmallClass; iSmallClass++){
      if(smallClassLow[iSmallClass] < Xvar[axisCl] && Xvar[axisCl] <= smallClassUp[iSmallClass]){
        smallClassNumber = iSmallClass;
        break;
      }
    }//classloop block

    Sum_Na_nSmallClass[smallClassNumber]    += iBinEntries*Na;
    Sum_Na2_nSmallClass[smallClassNumber]   += iBinEntries*Na*Na;
    Sum_Nb_nSmallClass[smallClassNumber]    += iBinEntries*Nb;
    Sum_Nb2_nSmallClass[smallClassNumber]   += iBinEntries*Nb*Nb;
    Sum_NaNb_nSmallClass[smallClassNumber]  += iBinEntries*Na*Nb;
    nEntries_nSmallClass[smallClassNumber]  += iBinEntries;

    Sum_NaCorr_nSmallClass[smallClassNumber] += iBinEntries*(Na*(Na-1));
    Sum_NbCorr_nSmallClass[smallClassNumber] += iBinEntries*(Nb*(Nb-1));

    for (int64_t iEntry = 0 ; iEntry < iBinEntries; iEntry++){
      iSubSample = GetRndmRandomNumber(randomGenerator, nSubSample);
      while ( SubSampleEntryCounter[iSubSample] >= EntriesPerSubSample ){ 
        iSubSample = GetRndmRandomNumber(randomGenerator, nSubSample); 
      }
      SubSampleEntryCounter[iSubSample]++;
      if(SubSampleEntryCounter[iSubSample] > EntriesPerSubSample){ cout<<"Problem :"<<iSubSample<<" :: ";}

      Sum_Na_nSubSample[iSubSample][classNumber]   += 1*Na;
      Sum_Na2_nSubSample[iSubSample][classNumber]  += 1*Na*Na;
      Sum_Nb_nSubSample[iSubSample][classNumber]   += 1*Nb;
      Sum_Nb2_nSubSample[iSubSample][classNumber]  += 1*Nb*Nb;
      Sum_NaNb_nSubSample[iSubSample][classNumber] += 1*Na*Nb;
      nEntries_nSubSample[iSubSample][classNumber] += 1;
  
      Sum_NaCorr_nSubSample[iSubSample][classNumber] += 1*(Na*(Na-1));
      Sum_NbCorr_nSubSample[iSubSample][classNumber] += 1*(Nb*(Nb-1));  
    }
  }//_nSubSample[iSubSample]Bin loop ends

  int64_t nEntries_nSubSampleTotal[nSubSample];
  int64_t nTotalEnt = 0;
  for(int iSubSample = 0; iSubSample<nSubSample; iSubSample++){
    nEntries_nSubSampleTotal[iSubSample] = 0;
    for (int iClass=0; iClass<nClass; iClass++){
      nEntries_nSubSampleTotal[iSubSample] += nEntries_nSubSample[iSubSample][iClass];
    }
    nTotalEnt += nEntries_nSubSampleTotal[iSubSample];
    cout<<"iSubSample_"<<iSubSample<<" :: "<<nEntries_nSubSampleTotal[iSubSample]
        <<" :: diff = "<<EntriesPerSubSample-nEntries_nSubSampleTotal[iSubSample]
        <<endl;
  }
  
  int64_t diff = hSparse->GetEntries()-nTotalEnt;
  cout<<"nTotalEnt = "<<nTotalEnt<<endl
      <<"h Entries = "<<hSparse->GetEntries()<<endl
      <<"  :: diff = "<<diff<<endl;
      
  // double Raa_nSubSample[nSubSample][nClass] ;
  // double Rbb_nSubSample[nSubSample][nClass] ;
  // double Rab_nSubSample[nSubSample][nClass] ;
  // double NDy_nSubSample[nSubSample][nClass] ;

  vector<vector<double>> Raa_nSubSample(nSubSample, vector<double>(nClass));
  vector<vector<double>> Rbb_nSubSample(nSubSample, vector<double>(nClass));
  vector<vector<double>> Rab_nSubSample(nSubSample, vector<double>(nClass));
  vector<vector<double>> NDy_nSubSample(nSubSample, vector<double>(nClass));


  //Calculation of Raa, Rbb, Rab & NDy
  for (int iClass=0; iClass<nClass; iClass++){
    cout<<"iClass = "<<iClass<<" :: "<<nEntries[iClass]<<endl;
    mean_Na[iClass]   = Sum_Na[iClass]  /nEntries[iClass] ;
    mean_Na2[iClass]  = Sum_Na2[iClass] /nEntries[iClass] ;
    mean_Nb[iClass]   = Sum_Nb[iClass]  /nEntries[iClass] ;
    mean_Nb2[iClass]  = Sum_Nb2[iClass] /nEntries[iClass] ;
    mean_NaNb[iClass] = Sum_NaNb[iClass]/nEntries[iClass] ;

    Raa[iClass] = (mean_Na2[iClass] - mean_Na[iClass]*mean_Na[iClass] - mean_Na[iClass]) / (mean_Na[iClass]*mean_Na[iClass]);
    Rbb[iClass] = (mean_Nb2[iClass] - mean_Nb[iClass]*mean_Nb[iClass] - mean_Nb[iClass]) / (mean_Nb[iClass]*mean_Nb[iClass]);
    Rab[iClass] = (mean_NaNb[iClass]- mean_Na[iClass]*mean_Nb[iClass]) / (mean_Na[iClass]*mean_Nb[iClass]);

    NDy[iClass] = Raa[iClass] + Rbb[iClass] - 2.0*Rab[iClass];

    mean_NaCorr[iClass] = Sum_NaCorr[iClass]/nEntries[iClass];
    mean_NbCorr[iClass] = Sum_NbCorr[iClass]/nEntries[iClass];

    Raa_Corr[iClass] = mean_NaCorr[iClass]/(mean_Na[iClass]*mean_Na[iClass]) - 1.0;
    Rbb_Corr[iClass] = mean_NbCorr[iClass]/(mean_Nb[iClass]*mean_Nb[iClass]) - 1.0;
    Rab_Corr[iClass] = mean_NaNb[iClass]/(mean_Na[iClass]*mean_Nb[iClass]) - 1.0;

    //Subsample Analysis
    for(int iSubSample = 0 ; iSubSample < nSubSample; iSubSample++){
      //add debug command of divide by zero
      mean_Na_nSubSample[iSubSample][iClass]   = Sum_Na_nSubSample[iSubSample][iClass]  /nEntries_nSubSample[iSubSample][iClass] ;
      mean_Na2_nSubSample[iSubSample][iClass]  = Sum_Na2_nSubSample[iSubSample][iClass] /nEntries_nSubSample[iSubSample][iClass] ;
      mean_Nb_nSubSample[iSubSample][iClass]   = Sum_Nb_nSubSample[iSubSample][iClass]  /nEntries_nSubSample[iSubSample][iClass] ;
      mean_Nb2_nSubSample[iSubSample][iClass]  = Sum_Nb2_nSubSample[iSubSample][iClass] /nEntries_nSubSample[iSubSample][iClass] ;
      mean_NaNb_nSubSample[iSubSample][iClass] = Sum_NaNb_nSubSample[iSubSample][iClass]/nEntries_nSubSample[iSubSample][iClass] ;

      Raa_nSubSample[iSubSample][iClass] = (mean_Na2_nSubSample[iSubSample][iClass] - mean_Na_nSubSample[iSubSample][iClass]*mean_Na_nSubSample[iSubSample][iClass] - mean_Na_nSubSample[iSubSample][iClass]) / (mean_Na_nSubSample[iSubSample][iClass]*mean_Na_nSubSample[iSubSample][iClass]);
      Rbb_nSubSample[iSubSample][iClass] = (mean_Nb2_nSubSample[iSubSample][iClass] - mean_Nb_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass] - mean_Nb_nSubSample[iSubSample][iClass]) / (mean_Nb_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]);
      Rab_nSubSample[iSubSample][iClass] = (mean_NaNb_nSubSample[iSubSample][iClass]- mean_Na_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]) / (mean_Na_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]);

      NDy_nSubSample[iSubSample][iClass] = Raa_nSubSample[iSubSample][iClass] + Rbb_nSubSample[iSubSample][iClass] - 2.0*Rab_nSubSample[iSubSample][iClass];

      mean_NaCorr_nSubSample[iSubSample][iClass] = Sum_NaCorr_nSubSample[iSubSample][iClass]/nEntries_nSubSample[iSubSample][iClass];
      mean_NbCorr_nSubSample[iSubSample][iClass] = Sum_NbCorr_nSubSample[iSubSample][iClass]/nEntries_nSubSample[iSubSample][iClass];

      Raa_Corr_nSubSample[iSubSample][iClass] = mean_NaCorr_nSubSample[iSubSample][iClass]/(mean_Na_nSubSample[iSubSample][iClass]*mean_Na_nSubSample[iSubSample][iClass]) - 1.0;
      Rbb_Corr_nSubSample[iSubSample][iClass] = mean_NbCorr_nSubSample[iSubSample][iClass]/(mean_Nb_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]) - 1.0;
      Rab_Corr_nSubSample[iSubSample][iClass] = mean_NaNb_nSubSample[iSubSample][iClass]/(mean_Na_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]) - 1.0;
    }

    // cout<<"iClass = "<<iClass<<" :: "<<nEntries[iClass]<<endl
    //   <<iClass<<" :: mean_Na["<<iClass<<"]   :: "<<mean_Na[iClass]  <<endl
    //   <<iClass<<" :: mean_Na2["<<iClass<<"]  :: "<<mean_Na2[iClass] <<endl
    //   <<iClass<<" :: mean_Nb["<<iClass<<"]   :: "<<mean_Nb[iClass]  <<endl
    //   <<iClass<<" :: mean_Nb2["<<iClass<<"]  :: "<<mean_Nb2[iClass] <<endl
    //   <<iClass<<" :: mean_NaNb["<<iClass<<"] :: "<<mean_NaNb[iClass]<<endl
    //   <<iClass<<" :: Raa["<<iClass<<"] = "<<Raa[iClass]<<" :: CorrValues "<<Raa_Corr[iClass]<<endl
    //   <<iClass<<" :: Rbb["<<iClass<<"] = "<<Rbb[iClass]<<" :: CorrValues "<<Rbb_Corr[iClass]<<endl
    //   <<iClass<<" :: Rab["<<iClass<<"] = "<<Rab[iClass]<<" :: CorrValues "<<Rab_Corr[iClass]<<endl
    //   <<iClass<<" :: NDy["<<iClass<<"] = "<<NDy[iClass]<<endl
    // ;
    
  }

  double Raa_nSmallClass[nSmallClass];
  double Rbb_nSmallClass[nSmallClass];
  double Rab_nSmallClass[nSmallClass];
  double NDy_nSmallClass[nSmallClass];

  //CBWC values
  //Calculation of Raa, Rbb, Rab & NDy
  for (int iSmallClass=0; iSmallClass<nSmallClass; iSmallClass++){
    cout<<"iSmallClass = "<<iSmallClass<<" :: "<<nEntries_nSmallClass[iSmallClass]<<endl;
    mean_Na_nSmallClass[iSmallClass]   = Sum_Na_nSmallClass[iSmallClass]  /nEntries_nSmallClass[iSmallClass] ;
    mean_Na2_nSmallClass[iSmallClass]  = Sum_Na2_nSmallClass[iSmallClass] /nEntries_nSmallClass[iSmallClass] ;
    mean_Nb_nSmallClass[iSmallClass]   = Sum_Nb_nSmallClass[iSmallClass]  /nEntries_nSmallClass[iSmallClass] ;
    mean_Nb2_nSmallClass[iSmallClass]  = Sum_Nb2_nSmallClass[iSmallClass] /nEntries_nSmallClass[iSmallClass] ;
    mean_NaNb_nSmallClass[iSmallClass] = Sum_NaNb_nSmallClass[iSmallClass]/nEntries_nSmallClass[iSmallClass] ;

    Raa_nSmallClass[iSmallClass] = (mean_Na2_nSmallClass[iSmallClass] - mean_Na_nSmallClass[iSmallClass]*mean_Na_nSmallClass[iSmallClass] - mean_Na_nSmallClass[iSmallClass]) / (mean_Na_nSmallClass[iSmallClass]*mean_Na_nSmallClass[iSmallClass]);
    Rbb_nSmallClass[iSmallClass] = (mean_Nb2_nSmallClass[iSmallClass] - mean_Nb_nSmallClass[iSmallClass]*mean_Nb_nSmallClass[iSmallClass] - mean_Nb_nSmallClass[iSmallClass]) / (mean_Nb_nSmallClass[iSmallClass]*mean_Nb_nSmallClass[iSmallClass]);
    Rab_nSmallClass[iSmallClass] = (mean_NaNb_nSmallClass[iSmallClass]- mean_Na_nSmallClass[iSmallClass]*mean_Nb_nSmallClass[iSmallClass]) / (mean_Na_nSmallClass[iSmallClass]*mean_Nb_nSmallClass[iSmallClass]);
    NDy_nSmallClass[iSmallClass] = Raa_nSmallClass[iSmallClass] + Rbb_nSmallClass[iSmallClass] - 2.0*Rab_nSmallClass[iSmallClass];
  }

  double sumForCBWC_Raa_nClass[nClass];
  double sumForCBWC_Rbb_nClass[nClass];
  double sumForCBWC_Rab_nClass[nClass];
  double sumForCBWC_NDy_nClass[nClass];
  
  for(int iClass = 0; iClass < nClass; iClass++) { //upper bound was included
    double countSum = 0;
    sumForCBWC_Raa_nClass[iClass] = 0;
    sumForCBWC_Rbb_nClass[iClass] = 0;
    sumForCBWC_Rab_nClass[iClass] = 0;
    sumForCBWC_NDy_nClass[iClass] = 0;
    // cout<<"iClass =  "<<iClass<<" :: "<<classLow[iClass]<<" :: "<<classUp[iClass]<<endl;
    for(int iSmallClass = 0 ; iSmallClass < nSmallClass ; iSmallClass++){
      if( classLow[iClass] < smallClassLow[iSmallClass] && smallClassLow[iSmallClass] <= classUp[iClass] ){
        // cout<<"iSmallClass = "<<iSmallClass<<"  :: its Class = "<<iClass<<" :: "<<smallClassLow[iSmallClass]<<" : "<<smallClassUp[iSmallClass]<<endl;
        countSum += nEntries_nSmallClass[iSmallClass];
        sumForCBWC_Raa_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*Raa_nSmallClass[iSmallClass];
        sumForCBWC_Rbb_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*Rbb_nSmallClass[iSmallClass];
        sumForCBWC_Rab_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*Rab_nSmallClass[iSmallClass];
        sumForCBWC_NDy_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*NDy_nSmallClass[iSmallClass];
      } else {
          if(iSmallClass == 0 && iClass == 0 ) {
            // cout<<"iSmallClass = "<<iSmallClass<<"  :: its Class = "<<iClass<<" :: "<<smallClassLow[iSmallClass]<<" : "<<smallClassUp[iSmallClass]<<endl;
            countSum += nEntries_nSmallClass[iSmallClass];
            sumForCBWC_Raa_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*Raa_nSmallClass[iSmallClass];
            sumForCBWC_Rbb_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*Rbb_nSmallClass[iSmallClass];
            sumForCBWC_Rab_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*Rab_nSmallClass[iSmallClass];
            sumForCBWC_NDy_nClass[iClass] +=  nEntries_nSmallClass[iSmallClass]*NDy_nSmallClass[iSmallClass];
          }else {
            cout<<"iSmallClass = "<<iSmallClass <<" ERROR NO BIN "<<endl;
          }
      }
    }//smallClass loop is over
    Raa_CBWC[iClass] = sumForCBWC_Raa_nClass[iClass]/countSum;
    Rbb_CBWC[iClass] = sumForCBWC_Rbb_nClass[iClass]/countSum;
    Rab_CBWC[iClass] = sumForCBWC_Rab_nClass[iClass]/countSum;
    NDy_CBWC[iClass] = sumForCBWC_NDy_nClass[iClass]/countSum;
  }


  SetXYRange(h1D[0],1,-1.0,101.0, 0, 0.0,0.0);
  SetXYRange(h1D[1],1,-1.5,150.5, 0, 0.0,0.0);
  SetXYRange(h1D[2],1,-1.5, 20.5, 0, 0.0,0.0);
  SetXYRange(h1D[3],1,-1.5, 10.5, 0, 0.0,0.0);
  SetXYRange(h1D[4],1,-1.5, 10.5, 0, 0.0,0.0);
  SetXYRange(h1D[5],1,-1.5,100.5, 0, 0.0,0.0);
  SetXYRange(h1D[6],1,-1.5,100.5, 0, 0.0,0.0);
  SetXYRange(h1D[7],1,-1.5, 40.5, 0, 0.0,0.0);
  SetXYRange(h1D[8],1,-1.5, 40.5, 0, 0.0,0.0);

  for (classNumber=0; classNumber<nClass; classNumber++){
    SetXYRange(h1D_nClass[0][classNumber],1,-1.0,101.0, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[1][classNumber],1,-1.5,150.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[2][classNumber],1,-1.5, 20.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[3][classNumber],1,-1.5, 10.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[4][classNumber],1,-1.5, 10.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[5][classNumber],1,-1.5,100.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[6][classNumber],1,-1.5,100.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[7][classNumber],1,-1.5, 40.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[8][classNumber],1,-1.5, 40.5, 0, 0.0,0.0);
  }

  // Raa[0] = 0.15688 ;// :: CorrValues 0.15688
  // Rbb[0] = 0.157596 ;// :: CorrValues 0.157596
  // Rab[0] = 0.312259 ;// :: CorrValues 0.312259
  // NDy[0] = -0.310041 ;//
  // Raa[1] = 0.190106 ;// :: CorrValues 0.190106
  // Rbb[1] = 0.190739 ;// :: CorrValues 0.190739
  // Rab[1] = 0.437924 ;// :: CorrValues 0.437924
  // NDy[1] = -0.495002 ;//
  // Raa[2] = 0.261415 ;// :: CorrValues 0.261415
  // Rbb[2] = 0.262389 ;// :: CorrValues 0.262389
  // Rab[2] = 0.622808 ;// :: CorrValues 0.622808
  // NDy[2] = -0.721812 ;//
  // Raa[3] = 0.320478 ;// :: CorrValues 0.320478
  // Rbb[3] = 0.320073 ;// :: CorrValues 0.320073
  // Rab[3] = 0.84439 ;// :: CorrValues 0.84439
  // NDy[3] = -1.04823 ;//
  // Raa[4] = 0.293928 ;// :: CorrValues 0.293928
  // Rbb[4] = 0.301875 ;// :: CorrValues 0.301875
  // Rab[4] = 1.03838 ;// :: CorrValues 1.03838
  // NDy[4] = -1.48096 ;//

  // if(DrawHistograms == 1){

    // for(int iAxis = 0 ; iAxis < nDim ; iAxis++){
    //   // setObjStyle(h1D[iAxis] , getMultiBit({hT,xT,yT}), {HIST(hSparse->GetName())+h1D[iAxis]->GetXaxis()->GetTitle(), hist->GetXaxis()->GetTitle(), "Counts"});
    //   CanvasSaver(h1D[iAxis] , getMultiBit({yL, hist})); 
    //   for (int iClass = 0; iClass < nClass; iClass++) {
    //     if(nClass > 0){ DrawSix1DLogPlots(h1D_nClass[iAxis][0], h1D_nClass[iAxis][1], h1D_nClass[iAxis][2], h1D_nClass[iAxis][3], h1D_nClass[iAxis][4]);}
    //     if(nClass > 5){ DrawSix1DLogPlots(h1D_nClass[iAxis][5], h1D_nClass[iAxis][6], h1D_nClass[iAxis][7], h1D_nClass[iAxis][8], h1D_nClass[iAxis][9]);}
    //   }
    // }

    double x[nClass] ;
    x[0] = 10;
    x[1] = 30;
    x[2] = 50;
    x[3] = 70;
    x[4] = 90;

    // for(int ii = 0 ; ii< nClass; ii++){
    //   cout<<"x["<<ii<<"] = "<<x[ii]<<endl;
    // }

    Double_t ex[nClass];
    ex[0] = 10; 
    ex[1] = 10;
    ex[2] = 10;
    ex[3] = 10;
    ex[4] = 10;

    double ey[nClass];

    double Raa_SubSampling_Mean[nClass]; double Raa_SubSampling_Sigma[nClass];
    double Rbb_SubSampling_Mean[nClass]; double Rbb_SubSampling_Sigma[nClass];
    double Rab_SubSampling_Mean[nClass]; double Rab_SubSampling_Sigma[nClass];
    double NDy_SubSampling_Mean[nClass]; double NDy_SubSampling_Sigma[nClass];

    GetMeanAndErrorFromSubSampling(Raa_SubSampling_Mean, Raa_SubSampling_Sigma, Raa_nSubSample);
    GetMeanAndErrorFromSubSampling(Rbb_SubSampling_Mean, Rbb_SubSampling_Sigma, Rbb_nSubSample);
    GetMeanAndErrorFromSubSampling(Rab_SubSampling_Mean, Rab_SubSampling_Sigma, Rab_nSubSample);
    GetMeanAndErrorFromSubSampling(NDy_SubSampling_Mean, NDy_SubSampling_Sigma, NDy_nSubSample);

    for(int iClass = 0 ; iClass < nClass ; iClass++){
      cout<<"iClassS = "<<iClass<<" :: "<<NDy_SubSampling_Sigma[iClass]<<endl;
    }

    for(int iClass =0 ; iClass< nClass; iClass++){
      cout<<"iClassM = "<<iClass<<" :: "<<NDy_SubSampling_Mean[iClass]<<endl;
    }

    // iClass = 0 :: 0.0003892196817162238919
    // iClass = 1 :: 0.00058835806571465223275
    // iClass = 2 :: 0.00068272484505879063501
    // iClass = 3 :: 0.0013420365366080681032
    // iClass = 4 :: 0.0020932575772351739996      

    // cout<<"iClass = "<<iClass<<" :: "<<error<<endl;
    
    // for(int iClass = 0 ; iClass < nClass ; iClass++){
    //   NDy_SubSampling_Sum [iClass] = 0;
    //   NDy_SubSampling_Sum2[iClass] = 0;
    //   for(int iSubSample = 0; iSubSample < nSubSample; iSubSample++){
    //     NDy_SubSampling_Sum [iClass] += NDy_nSubSample[iSubSample][iClass];
    //     NDy_SubSampling_Sum2[iClass] += std::pow(NDy_nSubSample[iSubSample][iClass], 2.0);
    //   }

    //   NDy_SubSampling_Mean[iClass] = NDy_SubSampling_Sum[iClass]/nSubSample;
    //   double tempVal =   NDy_SubSampling_Sum2[iClass] 
    //                    + nSubSample*std::pow(NDy_SubSampling_Mean[iClass],2)
    //                    - 2.0*NDy_SubSampling_Mean[iClass]*NDy_SubSampling_Sum[iClass];

    //   double sigma2 = tempVal/static_cast<double>(nSubSample-1);
    //   double error  = std::sqrt(sigma2/nSubSample);
    //   NDy_SubSampling_Sigma[iClass] = error; 

    //   // iClass = 0 :: 0.0003892196817162238919
    //   // iClass = 1 :: 0.00058835806571465223275
    //   // iClass = 2 :: 0.00068272484505879063501
    //   // iClass = 3 :: 0.0013420365366080681032
    //   // iClass = 4 :: 0.0020932575772351739996      

    //   cout<<"iClass = "<<iClass<<" :: "<<error<<endl;
    // }

    // Raa_nSubSample[iSubSample][iClass] = (mean_Na2_nSubSample[iSubSample][iClass] - mean_Na_nSubSample[iSubSample][iClass]*mean_Na_nSubSample[iSubSample][iClass] - mean_Na_nSubSample[iSubSample][iClass]) / (mean_Na_nSubSample[iSubSample][iClass]*mean_Na_nSubSample[iSubSample][iClass]);
    // Rbb_nSubSample[iSubSample][iClass] = (mean_Nb2_nSubSample[iSubSample][iClass] - mean_Nb_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass] - mean_Nb_nSubSample[iSubSample][iClass]) / (mean_Nb_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]);
    // Rab_nSubSample[iSubSample][iClass] = (mean_NaNb_nSubSample[iSubSample][iClass]- mean_Na_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]) / (mean_Na_nSubSample[iSubSample][iClass]*mean_Nb_nSubSample[iSubSample][iClass]);

    // NDy_nSubSample[iSubSample][iClass] = Raa_nSubSample[iSubSample][iClass] + Rbb_nSubSample[iSubSample][iClass] - 2.0*Rab_nSubSample[iSubSample][iClass];

    //Get Statistical Error from the data//

    grRab = new TGraphErrors(nClass,x,&Rab[0],ex, Rab_SubSampling_Sigma);grRab->SetMarkerStyle(kOpenSquare    );grRab->SetMarkerColor(kBlack);grRab->SetLineColor(kBlack); grRab->SetLineStyle(1);grRab->SetLineWidth(1);grRab->SetMarkerSize(1.3);
    grRaa = new TGraphErrors(nClass,x,&Raa[0],ex, Raa_SubSampling_Sigma);grRaa->SetMarkerStyle(kOpenTriangleUp);grRaa->SetMarkerColor(kBlue );grRaa->SetLineColor(kBlue ); grRaa->SetLineStyle(2);grRaa->SetLineWidth(1);grRaa->SetMarkerSize(1.3);
    grRbb = new TGraphErrors(nClass,x,&Rbb[0],ex, Rbb_SubSampling_Sigma);grRbb->SetMarkerStyle(kOpenCircle    );grRbb->SetMarkerColor(kRed  );grRbb->SetLineColor(kRed  ); grRbb->SetLineStyle(5);grRbb->SetLineWidth(1);grRbb->SetMarkerSize(1.3);
    grNDy = new TGraphErrors(nClass,x,&NDy[0],ex, NDy_SubSampling_Sigma);grNDy->SetMarkerStyle(kOpenSquare    );grNDy->SetMarkerColor(kBlack);grNDy->SetLineColor(kBlack); grNDy->SetLineStyle(1);grNDy->SetLineWidth(1);grNDy->SetMarkerSize(1.3);


    grRab_CBWC = new TGraphErrors(nClass,x,&Rab_CBWC[0],ex, Rab_SubSampling_Sigma);grRab_CBWC->SetMarkerStyle(kOpenSquare    );grRab_CBWC->SetMarkerColor(kBlack);grRab_CBWC->SetLineColor(kBlack); grRab_CBWC->SetLineStyle(1);grRab_CBWC->SetLineWidth(1);grRab_CBWC->SetMarkerSize(1.3);
    grRaa_CBWC = new TGraphErrors(nClass,x,&Raa_CBWC[0],ex, Raa_SubSampling_Sigma);grRaa_CBWC->SetMarkerStyle(kOpenTriangleUp);grRaa_CBWC->SetMarkerColor(kBlue );grRaa_CBWC->SetLineColor(kBlue ); grRaa_CBWC->SetLineStyle(2);grRaa_CBWC->SetLineWidth(1);grRaa_CBWC->SetMarkerSize(1.3);
    grRbb_CBWC = new TGraphErrors(nClass,x,&Rbb_CBWC[0],ex, Rbb_SubSampling_Sigma);grRbb_CBWC->SetMarkerStyle(kOpenCircle    );grRbb_CBWC->SetMarkerColor(kRed  );grRbb_CBWC->SetLineColor(kRed  ); grRbb_CBWC->SetLineStyle(5);grRbb_CBWC->SetLineWidth(1);grRbb_CBWC->SetMarkerSize(1.3);
    grNDy_CBWC = new TGraphErrors(nClass,x,&NDy_CBWC[0],ex, NDy_SubSampling_Sigma);grNDy_CBWC->SetMarkerStyle(kOpenSquare    );grNDy_CBWC->SetMarkerColor(kBlack);grNDy_CBWC->SetLineColor(kBlack); grNDy_CBWC->SetLineStyle(1);grNDy_CBWC->SetLineWidth(1);grNDy_CBWC->SetMarkerSize(1.3);
}



  THnSparseD* Sparse_Full_K0sPiKa   = (THnSparseD*)inFile->Get((HIST(MainDir[0])+"recoAnalysis/Sparse_Full_K0sPiKa").c_str()  ); 
  Sparse_Full_K0sPiKa  ->Print();
  PrintAllAxisOfSparse(Sparse_Full_K0sPiKa  ); 
  Get1dDistributionOfAllAxis(Sparse_Full_K0sPiKa);

  int axisCl   =  0; //Class axis 
  int pairType =  0;
  int axisA0   = -1;
  int axisA1   = -1;
  int axisB0   = -1;
  int axisB1   = -1;

  int axisK0s = 2;
  int axisPiPlus = 5;
  int axisPiMinus = 6;
  int axisKaPlus = 7; 
  int axisKaMinus = 8; 

  //Begin = [K+, K-] Analysis
    axisCl = 0;
    pairType = 0;
    if(pairType == 0) { axisA0 = axisKaPlus; axisB0 = axisKaMinus;  } //Two different Axis
    if(pairType == 1) { axisA0 = axisKaPlus; axisA1 = axisKaMinus; axisB0 = axisK0s; } // Sum of two different Axis and Third axis
    if(pairType == 2) { axisA0 = axisKaPlus; axisA1 = axisKaMinus; axisB0 = axisPiPlus; axisB1 = axisPiMinus; } //Sum two axis on each variable

    std::vector<double> Raa_Kp_Km(nClass);
    std::vector<double> Rbb_Kp_Km(nClass);
    std::vector<double> Rab_Kp_Km(nClass);
    std::vector<double> NDy_Kp_Km(nClass);
    TGraphErrors* grRab_Kp_Km;
    TGraphErrors* grRaa_Kp_Km;
    TGraphErrors* grRbb_Kp_Km;
    TGraphErrors* grNDy_Kp_Km;


    std::vector<double> Raa_Kp_Km_CBWC(nClass);
    std::vector<double> Rbb_Kp_Km_CBWC(nClass);
    std::vector<double> Rab_Kp_Km_CBWC(nClass);
    std::vector<double> NDy_Kp_Km_CBWC(nClass);
    TGraphErrors* grRab_Kp_Km_CBWC;
    TGraphErrors* grRaa_Kp_Km_CBWC;
    TGraphErrors* grRbb_Kp_Km_CBWC;
    TGraphErrors* grNDy_Kp_Km_CBWC;

    SparseAnalysis(Sparse_Full_K0sPiKa, nClass, classLow, classUp,
                    axisCl, pairType, axisA0, axisA1, axisB0, axisB1,
                      Rab_Kp_Km,  Raa_Kp_Km,  Rbb_Kp_Km,  NDy_Kp_Km, 
                    grRab_Kp_Km,grRaa_Kp_Km,grRbb_Kp_Km,grNDy_Kp_Km,
                      Rab_Kp_Km_CBWC,  Raa_Kp_Km_CBWC,  Rbb_Kp_Km_CBWC,  NDy_Kp_Km_CBWC,
                    grRab_Kp_Km_CBWC,grRaa_Kp_Km_CBWC,grRbb_Kp_Km_CBWC,grNDy_Kp_Km_CBWC
                  );



