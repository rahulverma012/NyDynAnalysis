#include <chrono>
#include <filesystem>
#include "printOptions.h"
namespace fs = std::filesystem;

using namespace chrono;

#define bitSet(mask, ithBit) ((mask) |= (1 << (ithBit))) // avoid name bitset as std::bitset is already there
#define bitCheck(mask, ithBit) ((mask) & (1 << (ithBit))) // bit check will return int value, not bool, use bitCheck != 0 in Analysis

template<typename T, typename U>
void checkObject(const T& obj, const U& objPath, const int index = -1){
  if (!obj) {
    cout<<"ERROR :: Obj Pointer Invalid :: "<<index<<" :: "<<objPath<<endl;  //!file -> TFile::Open(), Returned a null pointer --> File doesn't exit
  } else if (obj->IsZombie()) {
    cout<<"ERROR :: Zombie Obj :: "<<index<<" :: "<<objPath<<endl;//Obj->IsZombie()  :: file is there but it is corrupt or couldn't be read properly
  }
}

template<typename T, typename U>
void loadTFiles(T &inFiles, const U& inFileList){
  cout<<"==> Loading Files"<<endl;
  cout<<"nFiles = "<<inFileList.size()<<endl;

  for(int iFile = 0 ; iFile < inFileList.size(); iFile++){
    inFiles[iFile] = new TFile(inFileList[iFile].c_str());
    checkObject(inFiles[iFile], inFileList[iFile], iFile);
  }
  cout<<"==> Files Loaded"<<endl;
}

template<typename T, typename U, typename P> 
void loadHistograms(std::vector<T> &histList, const U& inFiles, const P& path, int printOption = 0){
  int64_t totalEntries = 0;
  for(int iFile = 0 ; iFile < inFiles.size(); iFile++){
    histList[iFile] = (T)inFiles[iFile]->Get(path.c_str());
    checkObject(histList[iFile], path, iFile);
    totalEntries += histList[iFile]->GetEntries();
    if(printOption == 1){ histList[iFile]->Print();}
  }
  cout<<"Loaded Histograms :: totalEntries = "<<totalEntries<<endl;
}

template<typename T>
T getMergedHist(vector<T> histList){
  T h = (T)histList[0]->Clone("newHist");
  h->Reset();    
  for(int i = 0 ; i < histList.size(); i++){
    h->Add(histList[i]);
  }
  return h;
}

template<typename I>
TH1* loadMergedHistogram(const I& inFiles, std::string pathString, bool printHist = 0){
 cout<<"pathString = "<<pathString<<endl;
 TH1* h = (TH1*)inFiles[0]->Get(pathString.c_str())->Clone();
 int64_t totEntries = 0;
 h->Reset();
 if( h->GetEntries() != 0) {cout<<"ERROR :: Histogram Reset Failed";}
 for(int i = 0 ; i < inFiles.size(); i++){
   auto tempHist = (TH1*)inFiles[i]->Get(pathString.c_str());
   h->Add(tempHist);
   totEntries += tempHist->GetEntries();
 }
 if(printHist) {h->Print();}
 if(totEntries != h->GetEntries()){ cout<<"ERROR :: Histogram Entry Mismatch";}
 return h;
}

template<typename I>
TH2F* loadMergedTH2FHistogram(const I& inFiles, std::string pathString, bool printHist = 0){
 cout<<"pathString = "<<pathString<<endl;
 TH2F* h = (TH2F*)inFiles[0]->Get(pathString.c_str())->Clone();
 int64_t totEntries = 0;
 h->Reset();
 if( h->GetEntries() != 0) {cout<<"ERROR :: Histogram Reset Failed";}
 for(int i = 0 ; i < inFiles.size(); i++){
   auto tempHist = (TH2*)inFiles[i]->Get(pathString.c_str());
   h->Add(tempHist);
   totEntries += tempHist->GetEntries();
 }
 if(printHist) {h->Print();}
 if(totEntries != h->GetEntries()){ cout<<"ERROR :: Histogram Entry Mismatch";}
 return h;
}

bool folderExists(const fs::path& folderPath) {
    return fs::exists(folderPath) && fs::is_directory(folderPath);
}

void createFolderWithParents(const fs::path& folderPath, bool errorPrint = false) {
  if (!folderExists(folderPath)) {
      if (fs::create_directories(folderPath)) {
          std::cout << "Folder created: " << folderPath << std::endl;
      } else {
          std::cerr << "Failed to create folder: " << folderPath << std::endl;
      }
  } else {
      if(errorPrint){
        std::cout << "Folder already exists: " << folderPath << std::endl;
      }
  }
}

template<typename T>
void PrintTime(T Start, std::string String){
  auto Stop = chrono::high_resolution_clock::now();
  auto Duration = duration_cast<microseconds>(Stop-Start);
  cout<<String<<float(Duration.count())/float(1000000)<<" seconds"<<endl;
}

void SetStyle(Bool_t graypalette=kFALSE);
void SetStyle(Bool_t graypalette) {
  cout << "Setting style!" << endl; 

  //https://root.cern/doc/master/TStyle_8h.html#ace94cabdcf18c1e8a7856d8c3f388cfe  // link to gStyle file

    gStyle->Reset("Plain"); //In Plain Style -> The plot title completely goes to left
    // gStyle->SetOptTitle(0); //Will remove plot Title completely


    //Statistics Box
    //   gStyle->SetOptStat(0);  //Will remove the statistics box 
    //   gStyle->SetOptStat(1111); // Enable statistics box with mean, RMS, etc.
      gStyle->SetOptStat(  1111111);
      //                 ksiourmen
      gStyle->SetStatX(0.9);        // X position (right-aligned)
      gStyle->SetStatY(0.9);        // Y position (top-aligned)

        // mode = ksiourmen (default =000001111)
        //        001111111
        // n = 1 the name of histogram is printed
        // e = 1 the number of entries
        // m = 1 the mean value // m = 2 the mean and mean error values
        // r = 1 the root mean square (RMS) // r = 2 the RMS and RMS error
        // u = 1 the number of underflows
        // o = 1 the number of overflows
        // i = 1 the integral of bins
        // s = 1 the skewness // s = 2 the skewness and the skewness error
        // k = 1 the kurtosis // k = 2 the kurtosis and the kurtosis error

    // if(graypalette) gStyle->SetPalette(8,0);
    // else gStyle->SetPalette(1);

      gStyle->SetCanvasColor(10);  //Sets the background color of the canvas
      // I think opacity of canvas cant be changed from 1 to any other value
      // But there is a fill option called hollow
      gStyle->SetCanvasBorderMode(0); //sunken border, no border and raised border etc
  
    //Frame option // Frame = axis box in which the plot is drawn  
      gStyle->SetFrameLineWidth(1); //plot box boudary size
      gStyle->SetFrameFillColor(kWhite); // plot box color
      gStyle->SetLineWidth(2);// This is showing its effect on frame border not on histogram line

      //Pad Options
      gStyle->SetPadColor(10); //this option doesn't seem to be doing anything
      gStyle->SetPadTickX(1);
      gStyle->SetPadTickY(1);

      gStyle->SetPadBottomMargin(0.1); // gStyle->SetPadBottomMargin(0.15);
      gStyle->SetPadLeftMargin(0.1);   // gStyle->SetPadLeftMargin(0.15);  

      // gStyle->SetHistLineWidth(1);// this option not showning any effect
      // gStyle->SetHistLineColor(kRed); // No effect of this option as well

      // gStyle->SetFuncWidth(2);
      // gStyle->SetFuncColor(kGreen);

    // gStyle->SetLabelSize(0.045,"xyz"); // no effect of this option as well //maybe this will work on bin labels
    // gStyle->SetLabelOffset(0.01,"y"); // no effect of this option
    // gStyle->SetLabelOffset(0.01,"x"); // no effect of this option
    // gStyle->SetLabelColor(kBlack,"xyz"); // no effect of this option

    //Following options are also not working
    // gStyle->SetTitleSize(0.05,"xyz"); //Not working
    // gStyle->SetTitleOffset(1.25,"y");
    // gStyle->SetTitleOffset(1.2,"x");
    // gStyle->SetTitleFillColor(kWhite);
    // gStyle->SetTextSizePixels(26);
    // gStyle->SetTextFont(42);
    //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y"); 

    gStyle->SetLegendBorderSize(0);
    gStyle->SetLegendFillColor(kWhite);
    //  gStyle->SetFillColor(kWhite);
    gStyle->SetLegendFont(42);

//   // The default settings 
//     gStyle->Reset("Plain"); //In Plain Style -> The plot title completely goes to left
//     gStyle->SetOptTitle(0); //Will remove plot Title completely
//     gStyle->SetOptStat(0);  //Will remove the statistics box
//     if(graypalette) gStyle->SetPalette(8,0);
//     else gStyle->SetPalette(1);
//           gStyle->SetCanvasColor(10);
//           gStyle->SetCanvasBorderMode(0);
//     gStyle->SetFrameLineWidth(1);
//     gStyle->SetFrameFillColor(kWhite);
//     gStyle->SetPadColor(10);
//     gStyle->SetPadTickX(1);
//     gStyle->SetPadTickY(1);

//     gStyle->SetPadBottomMargin(0.1); // gStyle->SetPadBottomMargin(0.15);
//     gStyle->SetPadLeftMargin(0.1);   // gStyle->SetPadLeftMargin(0.15);  

//     gStyle->SetHistLineWidth(1);
//     gStyle->SetHistLineColor(kRed);
//     gStyle->SetFuncWidth(2);
//     gStyle->SetFuncColor(kGreen);
//     gStyle->SetLineWidth(2);
//     gStyle->SetLabelSize(0.045,"xyz");
//     gStyle->SetLabelOffset(0.01,"y");
//     gStyle->SetLabelOffset(0.01,"x");
//     gStyle->SetLabelColor(kBlack,"xyz");
//     gStyle->SetTitleSize(0.05,"xyz");
//     gStyle->SetTitleOffset(1.25,"y");
//     gStyle->SetTitleOffset(1.2,"x");
//     gStyle->SetTitleFillColor(kWhite);
//     gStyle->SetTextSizePixels(26);
//     gStyle->SetTextFont(42);
//     //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y"); 

//     gStyle->SetLegendBorderSize(0);
//     gStyle->SetLegendFillColor(kWhite);
//     //  gStyle->SetFillColor(kWhite);
//     gStyle->SetLegendFont(42);
//   //
}




template<typename T>
void SetXYRange(T hist, bool setXaxis = false , double xLow = 0 , double xUp = 0, bool setYaxis = false, double yLow = 0 , double yUp = 0){
  if(setXaxis) {hist->GetXaxis()->SetRangeUser(xLow, xUp);}
  if(setYaxis) {hist->GetYaxis()->SetRangeUser(yLow, yUp);}
}


//___________________________________________________________________________________________My New Processing_______________________________________________________________________

  template<typename T>
  std::string HIST(T x){
    return std::string(x);
  }
  
  std::string PATH(std::string pathString) {
    return pathString;
  }
  
  void multiBitSet(int &mask, const std::vector<int>& bitVectors ){
    for (auto ithBit : bitVectors){
      bitSet(mask, ithBit);
    }
  }
  
  int getMultiBit(const std::vector<int>& bitVectors ){
    int mask = 0;
    for (auto ithBit : bitVectors){
      bitSet(mask, ithBit);
    }
    return mask;
  }
  
  template<typename T>
  void setObjStyle(T obj, const int& config, std::vector<std::string> stringList){
    int idx = -1;
    if(bitCheck(config, hT) != 0) {idx++; obj->SetTitle(stringList[idx].c_str());}
    if(bitCheck(config, xT) != 0) {idx++; obj->GetXaxis()->SetTitle(stringList[idx].c_str()); obj->GetXaxis()->CenterTitle(true);}
    if(bitCheck(config, yT) != 0) {idx++; obj->GetYaxis()->SetTitle(stringList[idx].c_str()); obj->GetYaxis()->CenterTitle(true);}
    // if(bitCheck(config, zT) != 0) {idx++; obj->GetZaxis()->SetTitle(stringList[idx].c_str()); obj->GetZaxis()->CenterTitle(true);}
  }
  
  template<typename T>
  void CanvasSaver(T obj, const int& config){
    gCanvasNo++; gCounterNo++;
    TCanvas *c = new TCanvas(Form("c_%d_%s",gCanvasNo, obj->GetName()),Form("c_%d_%s",gCanvasNo, obj->GetName()));
    c->SetWindowSize(h,w);
    if(bitCheck(config, xL) != 0) {c->SetLogx();}
    if(bitCheck(config, yL) != 0) {c->SetLogy();}
    if(bitCheck(config, zL) != 0) {c->SetLogz();}
  
    if(bitCheck(config, colz) != 0) {obj->Draw("colz");}
    else if(bitCheck(config, hist) != 0) {obj->Draw("hist");}
    else if(bitCheck(config, ap  ) != 0) {obj->Draw("ap");}
    else {
      obj->Draw();
    }
    // c->SaveAs(Form("SavePlots/p%d_%s.png",gCounterNo, c->GetName()));
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  std::string getModfiedStr(const std::string & myString ){
    size_t pos = myString.rfind('/'); //Find last occurance of "/" in your string
    if (pos != std::string::npos) {
      // If "/" is found, create a new string excluding the last "/" and characters after it
      std::string subString = myString.substr(0, pos);
      return subString;
    } else {
      std::cout << "No '/' found in the string." << std::endl;
      return myString;
    }
  }
      
  template<typename T>
  void CanvasSaver(T obj, std::string pathString, const int& config){
    cout<<"Path String = "<<pathString<<endl;
    gCanvasNo++; gCounterNo++;
    TCanvas *c = new TCanvas(Form("c_%d_%s",gCanvasNo, obj->GetName()),Form("c_%d_%s",gCanvasNo, obj->GetName()));
    c->SetWindowSize(h,w);
    if(bitCheck(config, xL) != 0) {c->SetLogx();}
    if(bitCheck(config, yL) != 0) {c->SetLogy();}
    if(bitCheck(config, zL) != 0) {c->SetLogz();}
  
    if(bitCheck(config, colz) != 0) {obj->Draw("colz");}
    else if(bitCheck(config, hist) != 0) {obj->Draw("hist");}
    else if(bitCheck(config, ap  ) != 0) {obj->Draw("ap");}
    else {
      obj->Draw();
    }
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  
  template<typename T>
  void DrawFour1DPlots(T h1, T h2, T h3){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
    c->cd(3);c->cd(3)->SetLogy();h3->Draw("hist");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawFour1DPlots(T h1, T h2, T h3, T h4){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
    c->cd(3);c->cd(3)->SetLogy();h3->Draw("hist");
    c->cd(4);c->cd(4)->SetLogy();h4->Draw("hist");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawTwo1DPlots(T h1, T h2){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawOnePairPlot(T h1){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2);
  
    c->cd(1);;h1->Draw();
    c->cd(2);c->cd(2)->SetLogy();h1->Draw("colz");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  // template<typename T>
  TH1* AddTwoHistograms(string histName  = "histName", TH1* hist1 = nullptr, TH1* hist2 = nullptr){
    TH1* hist3 = (TH1*)hist1->Clone();
    hist3->SetName(histName.c_str());
    hist3->Add(hist2);
    return hist3;
  }
  
  template<typename T>
  void DrawSix2DPlots( T h1, T h2, T h3 ){ //}, T h4, T h5, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogz();h1->Draw("colz");
    c->cd(2);c->cd(2)->SetLogz();h2->Draw("colz");
    c->cd(3);c->cd(3)->SetLogz();h3->Draw("colz");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawSix2DPlots(T h1, T h2, T h3, T h4, T h5 ){//, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogz();h1->Draw("colz");
    c->cd(2);c->cd(2)->SetLogz();h2->Draw("colz");
    c->cd(3);c->cd(3)->SetLogz();h3->Draw("colz");
    c->cd(4);c->cd(4)->SetLogz();h4->Draw("colz");
    c->cd(5);c->cd(5)->SetLogz();h5->Draw("colz");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawSix2DPlots(T h1, T h2, T h3, T h4, T h5, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogz();h1->Draw("colz");
    c->cd(2);c->cd(2)->SetLogz();h2->Draw("colz");
    c->cd(3);c->cd(3)->SetLogz();h3->Draw("colz");
    c->cd(4);c->cd(4)->SetLogz();h4->Draw("colz");
    c->cd(5);c->cd(5)->SetLogz();h5->Draw("colz");
    c->cd(6);c->cd(6)->SetLogz();h6->Draw("colz");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawSix1DLogPlots( T h1, T h2, T h3, T h4, T h5 ){ //}, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
    c->cd(3);c->cd(3)->SetLogy();h3->Draw("hist");
    c->cd(4);c->cd(4)->SetLogy();h4->Draw("hist");
    c->cd(5);c->cd(5)->SetLogy();h5->Draw("hist");
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  void DrawMultigraphWithLegend( TMultiGraph* mg, TLegend* leg){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d",gCanvasNo),Form("c_%d",gCanvasNo));
    c->SetWindowSize(h,w);
    mg->Draw("alp");
    leg->Draw();
  
    c->SaveAs(Form("SavePlots/%s/%s.%s", ext.c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  //____________________________________________________________________With String _________________________________
  template<typename T>
  void DrawFour1DPlots(std::string pathString, T h1, T h2, T h3){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
    c->cd(3);c->cd(3)->SetLogy();h3->Draw("hist");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawFour1DPlots(std::string pathString, T h1, T h2, T h3, T h4){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
    c->cd(3);c->cd(3)->SetLogy();h3->Draw("hist");
    c->cd(4);c->cd(4)->SetLogy();h4->Draw("hist");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawTwo1DPlots(std::string pathString, T h1, T h2){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawOnePairPlot(std::string pathString, T h1){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(2);
  
    c->cd(1);;h1->Draw();
    c->cd(2);c->cd(2)->SetLogy();h1->Draw("colz");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  // // template<typename T>
  // TH1* AddTwoHistograms(string histName  = "histName", TH1* hist1 = nullptr, TH1* hist2 = nullptr){
  //   TH1* hist3 = (TH1*)hist1->Clone();
  //   hist3->SetName(histName.c_str());
  //   hist3->Add(hist2);
  //   return hist3;
  // }
  
  template<typename T>
  void DrawSix2DPlots( std::string pathString, T h1, T h2, T h3 ){ //}, T h4, T h5, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogz();h1->Draw("colz");
    c->cd(2);c->cd(2)->SetLogz();h2->Draw("colz");
    c->cd(3);c->cd(3)->SetLogz();h3->Draw("colz");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawSix2DPlots(std::string pathString, T h1, T h2, T h3, T h4, T h5 ){//, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogz();h1->Draw("colz");
    c->cd(2);c->cd(2)->SetLogz();h2->Draw("colz");
    c->cd(3);c->cd(3)->SetLogz();h3->Draw("colz");
    c->cd(4);c->cd(4)->SetLogz();h4->Draw("colz");
    c->cd(5);c->cd(5)->SetLogz();h5->Draw("colz");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawSix2DPlots(std::string pathString, T h1, T h2, T h3, T h4, T h5, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogz();h1->Draw("colz");
    c->cd(2);c->cd(2)->SetLogz();h2->Draw("colz");
    c->cd(3);c->cd(3)->SetLogz();h3->Draw("colz");
    c->cd(4);c->cd(4)->SetLogz();h4->Draw("colz");
    c->cd(5);c->cd(5)->SetLogz();h5->Draw("colz");
    c->cd(6);c->cd(6)->SetLogz();h6->Draw("colz");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  template<typename T>
  void DrawSix1DLogPlots(std::string pathString, T h1, T h2, T h3, T h4, T h5 ){ //}, T h6 ){//}, T h7, T h8, T h9){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d_%s",gCanvasNo, h1->GetName()),Form("c_%d_%s",gCanvasNo, h1->GetName()));
    c->SetWindowSize(h,w);
    c->Divide(3,2);
    c->cd(1);c->cd(1)->SetLogy();h1->Draw("hist");
    c->cd(2);c->cd(2)->SetLogy();h2->Draw("hist");
    c->cd(3);c->cd(3)->SetLogy();h3->Draw("hist");
    c->cd(4);c->cd(4)->SetLogy();h4->Draw("hist");
    c->cd(5);c->cd(5)->SetLogy();h5->Draw("hist");
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }
  
  void DrawMultigraphWithLegend( std::string pathString, TMultiGraph* mg, TLegend* leg){
    gCanvasNo++; gCounterNo++;
    TCanvas* c = new TCanvas(Form("c_%d",gCanvasNo),Form("c_%d",gCanvasNo));
    c->SetWindowSize(h,w);
    mg->Draw("alp");
    leg->Draw();
  
    createFolderWithParents(Form("SavePlots/%s/%s", ext.c_str(),getModfiedStr(pathString).c_str()), false);
    c->SaveAs(Form("SavePlots/%s/%s/%s.%s", ext.c_str(),getModfiedStr(pathString).c_str(), c->GetName(), ext.c_str()));
    if(canvasDelete == 1){delete c;}
  }

  TH1* GetZoomed1DHist(TH1* hist, double xlow , double xup){
    auto newHist = (TH1*)hist->Clone();
    newHist->SetName(Form("%s_zoom", hist->GetName()));
    newHist->GetXaxis()->SetRangeUser(xlow, xup);
    return newHist;
  }

  template<typename T>
  void Set2DLabelsAxis(T hist, bool SetTitle=false, string hTitle="hTitle", bool SetXtitle = false, string xTitle = "Xtitle", bool SetYtitle = false, string yTitle = "Ytitle"){
    if(SetTitle ){hist->SetTitle(hTitle.c_str());}
    if(SetXtitle){hist->GetXaxis()->SetTitle(xTitle.c_str());hist->GetXaxis()->CenterTitle(true);}
    if(SetYtitle){hist->GetYaxis()->SetTitle(yTitle.c_str());hist->GetYaxis()->CenterTitle(true);}
  }

  template<typename T>
  void PrintAllAxisOfSparse(const T &hSparse){
    const int nDim = hSparse->GetNdimensions();
    for(int iAxis = 0; iAxis < nDim; iAxis++){
      cout<<"Axis "<<iAxis<<" :: "<<hSparse->GetAxis(iAxis)->GetTitle()<<endl;
    }
  }

  template<typename T>
  void get1DdistributionOfAllAxis( const T&hSparse){
    for(int iAxis = 0; iAxis < hSparse->GetNdimensions(); iAxis++ ){
      auto hist = hSparse->Projection(int(iAxis));
      setObjStyle(hist , getMultiBit({hT,xT,yT}), {HIST(hSparse->GetName())+hist->GetXaxis()->GetTitle(), hist->GetXaxis()->GetTitle(), "Counts"});
      CanvasSaver(hist , getMultiBit({yL})); 
    }
  }

  template<typename T, typename U, typename P>
  void loadSparseHistograms(std::vector<T> &histList, const U& inFiles, const P& path, int printOption = 0){
    int64_t totalEntries = 0;
    for(int iFile = 0 ; iFile < inFiles.size(); iFile++){
      histList[iFile] = (T)inFiles[iFile]->Get(path.c_str());
      checkObject(histList[iFile], path, iFile);
      totalEntries += histList[iFile]->GetEntries();
      if(printOption == 1){ cout<<endl<<"Sparse Hist "<<iFile<<"  ";histList[iFile]->Print();}
    }
    cout<<"Loaded Histograms :: totalEntries = "<<totalEntries<<endl;
  }

  template<typename T> 
  void get1DdistributionOfAllAxis(std::vector<T> &histList, std::string pathString){
    const int nDim = histList[0]->GetNdimensions();
    const int nHist = histList.size();
    for(int iAxis = 0; iAxis < nDim; iAxis++ ){
      int64_t totalEntries = 0;
      auto hist = histList[0]->Projection(int(iAxis));
      hist->SetName(Form("%s_iAxis_%d", histList[0]->GetName(), iAxis));
      hist->Reset();
      for(int iHist = 0 ; iHist < nHist; iHist++){
        auto tempHist = histList[iHist]->Projection(int(iAxis));
        hist->Add(tempHist);
        totalEntries += histList[iHist]->GetEntries();
        delete tempHist;
      }
      if(totalEntries != hist->GetEntries()) { cout<<"ERROR: Hist Entries mismatch"<<endl;}
      setObjStyle(hist, getMultiBit({hT,xT,yT}), {HIST(histList[0]->GetName())+hist->GetXaxis()->GetTitle(), hist->GetXaxis()->GetTitle(), "Counts"});
      CanvasSaver(hist, pathString,  getMultiBit({yL}));
      delete hist;
    }
  }

  template<typename T> 
  TH1D* get1DMergedAxis(std::vector<T> &histList, const int& iAxis){
    int64_t totalEntries = 0;
    const int nHist = histList.size();
    auto hist = histList[0]->Projection(int(iAxis));
    hist->SetName(Form("%s_iAxis_%d", histList[0]->GetName(), iAxis));
    hist->Reset();
    for(int iHist = 0 ; iHist < nHist; iHist++){
      auto tempHist = histList[iHist]->Projection(int(iAxis));
      hist->Add(tempHist);
      totalEntries += histList[iHist]->GetEntries();
      delete tempHist;
    }
    if(totalEntries != hist->GetEntries()) { cout<<"ERROR: Hist Entries mismatch"<<endl;}
    return hist;
  }

  template<typename T>
  TH1D* get1DBlankHistFromSparse(const T &hsparse, int AxisNo ){
    TH1D *hist = new TH1D(Form("%s_Axis_%d",hsparse->GetName(),AxisNo),
                    Form("%s_Axis_%d :: %s",hsparse->GetName(),AxisNo,hsparse->GetAxis(AxisNo)->GetTitle()),
                    hsparse->GetAxis(AxisNo)->GetNbins(),
                    hsparse->GetAxis(AxisNo)->GetXmin() ,
                    hsparse->GetAxis(AxisNo)->GetXmax());
    hist->GetXaxis()->SetTitle(hsparse->GetAxis(AxisNo)->GetTitle());
    hist->GetXaxis()->CenterTitle(true);
    hist->GetYaxis()->SetTitle("Counts");
    hist->GetYaxis()->CenterTitle(true);
    return hist;
  }

  template<typename U, typename V>
  TH1D* GetClonedHist(TH1D* hist, U histName, V histTitle){
    TH1D *histClone = (TH1D*)hist->Clone();
    histClone->SetName(Form("%s_%s",hist->GetName(),histName));
    histClone->SetTitle(Form("%s %s",histClone->GetName(),histTitle));
    return histClone;
  }

  template<typename T> 
  int64_t FindEntriesPerSubSample(const T& hist, const int &nSubSample){
    cout<<endl<<"Finding Entries Per SubSample"<<endl;
    cout<<hist->GetName()<<" Total Entries = "<<std::setprecision(20)<<hist->GetEntries()<<endl;
    int64_t totalEntries = hist->GetEntries();
    int64_t Entries = totalEntries/nSubSample;
    int64_t Remainder  = totalEntries%nSubSample;
    cout<<"Entries              = "<<Entries<<endl; //9995026
    cout<<"Remainder            = "<<Remainder<<endl;
    if( Remainder != 0){Entries++;}
    cout<<endl;
    // cout<<"Entries Per SubSample = "<<Entries<<endl;
    return Entries;
  }

  template<typename T> 
  int64_t FindEntriesPerSubSample(const std::vector<T> &histList, int nSubSample, int64_t &totalEntries){
    cout<<endl<<"Finding Entries Per SubSample"<<endl;
    totalEntries = 0;
    int nHist = histList.size();
    for(int iHist = 0 ; iHist < nHist; iHist++){
      totalEntries += histList[iHist]->GetEntries();
    }
    cout<<histList[0]->GetName()<<" :: total Entries = "<<std::setprecision(20)<<totalEntries<<endl;
    int64_t Entries = totalEntries/nSubSample;
    int64_t Remainder  = totalEntries%nSubSample;
    cout<<"Entries              = "<<Entries<<endl; //9995026
    cout<<"Remainder            = "<<Remainder<<endl;
    if( Remainder != 0){Entries++;}
    cout<<endl;
    cout<<"Entries Per SubSample = "<<Entries<<endl;
    return Entries;
  }

  int GetRndmRandomNumber(TRandom3 &randomGenerator, int Length){
    int randomValue = randomGenerator.Rndm()*Length; // Uniform number between 0 and 1
    if (randomValue == Length){ randomValue = Length -1;}
    return randomValue;
  }

  Int_t    GetBinFromTHnSparse(THnSparse* hsparse,Int_t AxisNo, double val ){ return hsparse->GetAxis(AxisNo)->FindBin(val);}
  Double_t GetBinWidthOfAxis  (THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return hsparse->GetAxis(AxisNo)->GetBinWidth(BinNo);}
  Double_t GetBinCenterOfAxis (THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return hsparse->GetAxis(AxisNo)->GetBinCenter(BinNo);}
  Double_t GetBinLowEdgeOfAxis(THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return hsparse->GetAxis(AxisNo)->GetBinLowEdge(BinNo);}
  Double_t GetBinUpEdgeOfAxis (THnSparse* hsparse,Int_t AxisNo, Int_t BinNo){ return (hsparse->GetAxis(AxisNo)->GetBinLowEdge(BinNo)+hsparse->GetAxis(AxisNo)->GetBinWidth(BinNo));}

  template<typename T>
  int getFirstFilledBin(const T& histAxis){
    int firstFilledBin = -1;
    for(int iBin = 0 ; iBin <= histAxis->GetNbinsX()+1; iBin++){
      if(histAxis->GetBinContent(iBin) != 0) { firstFilledBin = iBin; break;}
    }
    if(firstFilledBin == -1){ cout<<"Histogram is empty"<<endl;}
    else if (firstFilledBin == 0) { cout<<"LastFilledBin is Underflow"<<endl;}
    return firstFilledBin;
  }

  template<typename T>
  int getLastFilledBin(const T& histAxis){
    int lastFilledBin = -1;
    for(int iBin = 0 ; iBin <= histAxis->GetNbinsX()+1; iBin++){
      if(histAxis->GetBinContent(iBin) != 0) { lastFilledBin = iBin;}
    }
    if(lastFilledBin == histAxis->GetNbinsX()+1){ cout<<"LastFilledBin is Overflow";}
    else if (lastFilledBin == -1) { cout<<"Histogram is empty"<<endl;}
    return lastFilledBin;
  }

  template<typename T>
  void getQuantileBinProperEdges(const T& histAxis, const int& nQuantilePoints, vector<double>& quantileArray, const vector<double>& nQuantileArray,
    vector<double>& classLow, vector<double>& classUp ,vector<int>& iBinLow, vector<int>& iBinUp){
    histAxis->Print();
    histAxis->GetQuantiles(nQuantilePoints, quantileArray.data(), nQuantileArray.data());
    for(int i=0 ; i < nQuantilePoints ; i++){
      cout<<"i = "<<i<<" :: "<<nQuantileArray[i];
      cout<<" :: "<<quantileArray[i]<<endl;
    }
    for(int i=0 ; i < nClass ; i++){
      if( quantileArray[i] - int(quantileArray[i]) > 0.5){ classLow[i] = int(quantileArray[i])+1;}
      else                                               { classLow[i] = int(quantileArray[i]);  }
      if( quantileArray[i+1] - int(quantileArray[i+1]) > 0.5){ classUp[i] = int(quantileArray[i+1]);}
      else                                                   { classUp[i] = int(quantileArray[i+1])-1;}
    }
    classLow[0] = -1;
    classUp[nClass-1] = histAxis->GetBinLowEdge(histAxis->GetNbinsX()+1) + histAxis->GetBinWidth(histAxis->GetNbinsX()+1);

    int width = 12;  // Width for each column to make the "::" aligned
    cout<<endl<<"Printing Class Edges "<<endl;
    int64_t totEntryCounter = 0;
    for(int i=0 ; i < nClass ; i++){
      iBinLow[i] = histAxis->FindBin(classLow[i]);
      iBinUp[i]  = histAxis->FindBin(classUp[i]);
      cout<<"i = "<<std::setw(2)<<i<<" :: mult \u2208 "<<"["<<std::setw(5)<<classLow[i]<<","<<std::setw(5)<<classUp[i]<<"] "
      <<" :: binPos \u2208 ["<<std::setw(5)<<iBinLow[i]<<","<<std::setw(5)<<iBinUp[i]<<"] "
      <<" :: \u222B = "<<histAxis->Integral(iBinLow[i], iBinUp[i])
      <<" :: \u0025 = "<<100.0*static_cast<double>(histAxis->Integral(iBinLow[i], iBinUp[i]))/static_cast<double>(histAxis->GetEntries())
      <<endl;
      totEntryCounter += histAxis->Integral(histAxis->FindBin(classLow[i]), histAxis->FindBin(classUp[i]));
    }
    if(totEntryCounter != histAxis->GetEntries()){ cout<<"ERROR :: total entries in classes are not matching"<<endl;}
  }

  template<typename T> 
  void getSmallBinProperEdges(const T& histAxis, const int& nSmallClass, vector<double>& smallClassLow, vector<double>& smallClassUp, 
                              vector<int>& iBinLow_smallClass, vector<int>& iBinUp_smallClass, vector<int>& nClassIDX_smallClass, 
                              const int &nClass, const vector<double>& classLow, const vector<double>& classUp,
                              const int& firstFilledBin, const int& lastFilledBin){
    cout<<"Processing smallClass information for Multiplicity/Centraility bin width correction"<<endl;
    int binPositionsLow  = firstFilledBin;
    // int binPositionsHigh = lastFilledBin;
    for(int i = 0; i < nSmallClass; i++) {
      smallClassLow[i] = histAxis->GetBinLowEdge(binPositionsLow + i) ; 
      //For integer Bins 
      smallClassUp[i]  = smallClassLow[i] ;//+ histAxis->GetBinWidth(i);
      for(int iClass = 0 ; iClass < nClass; iClass++) {
        if( classLow[iClass] <= smallClassLow[i]  && smallClassLow[i]  <= classUp[iClass]) { nClassIDX_smallClass[i] = iClass; break; }
      }
    }
    // smallClassLow[0] = -1.0; smallClassUp[nSmallClass-1] = 101.0;

    int64_t totEntryCounter = 0;
    for(int i=0 ; i < nSmallClass ; i++){
      iBinLow_smallClass[i] = histAxis->FindBin(smallClassLow[i]);
      iBinUp_smallClass[i]  = histAxis->FindBin(smallClassUp[i]);
      cout<<"i = "<<std::setw(3)<<i<<" :: mult \u2208 "<<"["<<std::setw(5)<<smallClassLow[i]<<","<<std::setw(5)<<smallClassUp[i]<<"] "
      <<" :: binPos \u2208 ["<<std::setw(5)<<iBinLow_smallClass[i]<<","<<std::setw(5)<<iBinUp_smallClass[i]<<"] "
      <<" :: nClassIDX = "<<nClassIDX_smallClass[i]
      <<" :: \u222B = "<<std::setw(11)<<histAxis->Integral(iBinLow_smallClass[i], iBinUp_smallClass[i])
      <<" :: \u0025 = "<<100.0*static_cast<double>(histAxis->Integral(iBinLow_smallClass[i], iBinUp_smallClass[i]))/static_cast<double>(histAxis->GetEntries())
      <<endl;
      totEntryCounter += histAxis->Integral(histAxis->FindBin(smallClassLow[i]), histAxis->FindBin(smallClassUp[i]));
    }
    if(totEntryCounter != histAxis->GetEntries()){ cout<<"ERROR :: total entries in classes are not matching"<<endl;}
  }

  template<typename T>
  void checkClassificationHist(const std::vector<T>& h1D_nClass, const int& axisCl, const int& nClass){
    for(int iClass = 0 ; iClass < nClass-1; iClass++){
      int binDiff = getFirstFilledBin(h1D_nClass[axisCl][iClass+1]) - getLastFilledBin(h1D_nClass[axisCl][iClass]);
      if(binDiff != 1){ 
        cout<<"ERROR :: Severe :: bin classification Improper :: "
        <<" :: lastBin  = "<<getLastFilledBin(h1D_nClass[axisCl][iClass])
        <<" :: firstBin = "<<getFirstFilledBin(h1D_nClass[axisCl][iClass+1])
        <<endl;
      }
    }
  }
  
  template<typename T>
  void checkSubSampleEntries(const T& nEntries_nSubSample, const int64_t& EntriesPerSubSample, const int64_t& totalSubSampleEntries){
    cout<<endl<<"Printing Subsample Information"<<endl;
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
    
    int64_t diff = totalSubSampleEntries-nTotalEnt;
    cout<<"nTotalEnt = "<<nTotalEnt<<endl
        <<"h Entries = "<<totalSubSampleEntries<<endl
        <<"  :: diff = "<<diff<<endl;
  }


  template<typename T>
  void GetMeanAndErrorFromSubSampling(const T&SubSampleArr, vector<double>& X_Mean, vector<double>& X_Sigma ) {
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
TMultiGraph* GetMultigraph(T mgName, vector<TGraph*> graphList,T MgTitle, T Xtitle, T Ytitle){
  TMultiGraph *mg = new TMultiGraph();
  for (int i = 0 ; i < graphList.size(); i++){
    mg->Add(graphList[i],"p");
  }
  return mg;
}

TLegend* GetLegendFromVectors(vector<TGraph*> graphList, vector<string>  graphLegTitles, vector<double>  graphLegPosition){
  TLegend* leg = new TLegend(graphLegPosition[0],graphLegPosition[1],graphLegPosition[2],graphLegPosition[3]); //(0.14,0.71,0.44,0.86);
  leg->SetBorderSize(0);
  for(int i = 0; i < graphList.size(); i++){
    leg->AddEntry(graphList[i],graphLegTitles[i].c_str(),"lpe");
  }
  return leg;
}
