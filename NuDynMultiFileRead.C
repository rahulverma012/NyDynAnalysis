#include "helperFunctions.h"

std::vector<std::string> inFileList =  {
  // "Stage_1/001/AnalysisResults.root",
  // "Stage_1/002/AnalysisResults.root",
  // "Stage_1/003/AnalysisResults.root",
  // "Stage_1/004/AnalysisResults.root",
  // "Stage_1/005/AnalysisResults.root",
  // "Stage_1/006/AnalysisResults.root",
  // "Stage_1/007/AnalysisResults.root",
  // "Stage_1/008/AnalysisResults.root",
  // "Stage_1/009/AnalysisResults.root",
  // "Stage_1/010/AnalysisResults.root",
  // "Stage_1/011/AnalysisResults.root",
  // "Stage_1/012/AnalysisResults.root",
  // "Stage_1/013/AnalysisResults.root",
  // "Stage_1/014/AnalysisResults.root",
  // "Stage_1/015/AnalysisResults.root",
  // "Stage_1/016/AnalysisResults.root",
  // "Stage_1/017/AnalysisResults.root",
  // "Stage_1/018/AnalysisResults.root",
  // "Stage_1/019/AnalysisResults.root",
  // "Stage_1/020/AnalysisResults.root",
  // "Stage_1/021/AnalysisResults.root",
  "Stage_1/022/AnalysisResults.root"/**/
 };

template<typename I>
void executeEventInfoPart(const I& inFiles){
  cout<<"INFO :: Print :: BeforEventInfo :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;

  auto ps_h00 = PATH(HIST(MainDir[kMainDir])+"recoEvent/ProcessType"       ); TH1* h00_ProcessType    =  loadMergedHistogram(inFiles, ps_h00); setObjStyle(h00_ProcessType   , getMultiBit({hT,xT,yT}), {"ProcessType"   , "Process Type"  , "DF Counts"});
  auto ps_h01 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h01_CollisionCount"); TH1* h01_CollisionCount =  loadMergedHistogram(inFiles, ps_h01); setObjStyle(h01_CollisionCount, getMultiBit({hT,xT,yT}), {"CollisionCount", "CollisionCount", "Counts"});
  auto ps_h02 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h02_VertexXRec"    ); TH1* h02_VertexXRec     =  loadMergedHistogram(inFiles, ps_h02); setObjStyle(h02_VertexXRec    , getMultiBit({hT,xT,yT}), {"VertexXRec    ", "VertexXRec    ", "Counts"});
  auto ps_h03 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h03_VertexYRec"    ); TH1* h03_VertexYRec     =  loadMergedHistogram(inFiles, ps_h03); setObjStyle(h03_VertexYRec    , getMultiBit({hT,xT,yT}), {"VertexYRec    ", "VertexYRec    ", "Counts"});
  auto ps_h04 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h04_VertexZRec"    ); TH1* h04_VertexZRec     =  loadMergedHistogram(inFiles, ps_h04); setObjStyle(h04_VertexZRec    , getMultiBit({hT,xT,yT}), {"VertexZRec    ", "Collision Vertex Z (cm)", "Counts"});
  // auto ps_h05 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h05_Centrality"    ); TH1* h05_Centrality     =  loadMergedHistogram(inFiles, ps_h05); setObjStyle(h05_Centrality    , getMultiBit({hT,xT,yT}), {"Centrality    ", "Centrality (centFT0C percentile)", "Counts"});
  auto ps_h05 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h05_Centrality"    ); TH1* h05_Centrality     =  loadMergedHistogram(inFiles, ps_h05); setObjStyle(h05_Centrality    , getMultiBit({hT,xT,yT}), {"Centrality    ", "MultV0M", "Counts"});
  auto ps_h06 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h06_V0Size"        ); TH1* h06_V0Size         =  loadMergedHistogram(inFiles, ps_h06); setObjStyle(h06_V0Size        , getMultiBit({hT,xT,yT}), {"V0Size        ", "V0Size        ", "Counts"});
  auto ps_h07 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h07_TracksSize"    ); TH1* h07_TracksSize     =  loadMergedHistogram(inFiles, ps_h07); setObjStyle(h07_TracksSize    , getMultiBit({hT,xT,yT}), {"TracksSize    ", "TracksSize    ", "Counts"});
  auto ps_h08 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h08_nTrack"        ); TH1* h08_nTrack         =  loadMergedHistogram(inFiles, ps_h08); setObjStyle(h08_nTrack        , getMultiBit({hT,xT,yT}), {"nTrack        ", "nTrack        ", "Counts"});
  auto ps_h09 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h09_nK0s"          ); TH1* h09_nK0s           =  loadMergedHistogram(inFiles, ps_h09); setObjStyle(h09_nK0s          , getMultiBit({hT,xT,yT}), {"nK0s          ", "nK0s          ", "Counts"});
  auto ps_h10 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h10_nPiPlus"       ); TH1* h10_nPiPlus        =  loadMergedHistogram(inFiles, ps_h10); setObjStyle(h10_nPiPlus       , getMultiBit({hT,xT,yT}), {"nPiPlus       ", "nPiPlus       ", "Counts"});
  auto ps_h11 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h11_nPiMinus"      ); TH1* h11_nPiMinus       =  loadMergedHistogram(inFiles, ps_h11); setObjStyle(h11_nPiMinus      , getMultiBit({hT,xT,yT}), {"nPiMinus      ", "nPiMinus      ", "Counts"});
  auto ps_h12 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h12_nKaPlus"       ); TH1* h12_nKaPlus        =  loadMergedHistogram(inFiles, ps_h12); setObjStyle(h12_nKaPlus       , getMultiBit({hT,xT,yT}), {"nKaPlus       ", "nKaPlus       ", "Counts"});
  auto ps_h13 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h13_nKaMinus"      ); TH1* h13_nKaMinus       =  loadMergedHistogram(inFiles, ps_h13); setObjStyle(h13_nKaMinus      , getMultiBit({hT,xT,yT}), {"nKaMinus      ", "nKaMinus      ", "Counts"});
  auto ps_h14 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h14_nProton"       ); TH1* h14_nProton        =  loadMergedHistogram(inFiles, ps_h14); setObjStyle(h14_nProton       , getMultiBit({hT,xT,yT}), {"nProton       ", "nProton       ", "Counts"});
  auto ps_h15 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h15_nPBar"         ); TH1* h15_nPBar          =  loadMergedHistogram(inFiles, ps_h15); setObjStyle(h15_nPBar         , getMultiBit({hT,xT,yT}), {"nPBar         ", "nPBar         ", "Counts"});
  auto ps_h16 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h16_nElPlus"       ); TH1* h16_nElPlus        =  loadMergedHistogram(inFiles, ps_h16); setObjStyle(h16_nElPlus       , getMultiBit({hT,xT,yT}), {"nElPlus       ", "nElPlus       ", "Counts"});
  auto ps_h17 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h17_nElMinus"      ); TH1* h17_nElMinus       =  loadMergedHistogram(inFiles, ps_h17); setObjStyle(h17_nElMinus      , getMultiBit({hT,xT,yT}), {"nElMinus      ", "nElMinus      ", "Counts"});
  auto ps_h18 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h18_nDePlus"       ); TH1* h18_nDePlus        =  loadMergedHistogram(inFiles, ps_h18); setObjStyle(h18_nDePlus       , getMultiBit({hT,xT,yT}), {"nDePlus       ", "nDePlus       ", "Counts"});
  auto ps_h19 = PATH(HIST(MainDir[kMainDir])+"recoEvent/h19_nDeMinus"      ); TH1* h19_nDeMinus       =  loadMergedHistogram(inFiles, ps_h19); setObjStyle(h19_nDeMinus      , getMultiBit({hT,xT,yT}), {"nDeMinus      ", "nDeMinus      ", "Counts"});

  SetXYRange(h05_Centrality    , 1, -1, 250, 0 ,0 ,0 );//ps_h05, getMultiBit({yL}));

  CanvasSaver(h00_ProcessType   , ps_h00, 0);
  CanvasSaver(h01_CollisionCount, ps_h01, 0);
  CanvasSaver(h02_VertexXRec    , ps_h02, 0);
  CanvasSaver(h03_VertexYRec    , ps_h03, 0);
  CanvasSaver(h04_VertexZRec    , ps_h04, 0);
  CanvasSaver(h05_Centrality    , ps_h05, getMultiBit({yL}));
  CanvasSaver(h06_V0Size        , ps_h06, 0);
  CanvasSaver(h07_TracksSize    , ps_h07, 0);
  CanvasSaver(h08_nTrack        , ps_h08, getMultiBit({yL}));
  CanvasSaver(h09_nK0s          , ps_h09, getMultiBit({yL}));
  CanvasSaver(h10_nPiPlus       , ps_h10, getMultiBit({yL}));
  CanvasSaver(h11_nPiMinus      , ps_h11, getMultiBit({yL}));
  CanvasSaver(h12_nKaPlus       , ps_h12, getMultiBit({yL}));
  CanvasSaver(h13_nKaMinus      , ps_h13, getMultiBit({yL}));
  CanvasSaver(h14_nProton       , ps_h14, getMultiBit({yL}));
  CanvasSaver(h15_nPBar         , ps_h15, getMultiBit({yL}));
  CanvasSaver(h16_nElPlus       , ps_h16, getMultiBit({yL}));
  CanvasSaver(h17_nElMinus      , ps_h17, getMultiBit({yL}));
  CanvasSaver(h18_nDePlus       , ps_h18, getMultiBit({yL}));
  CanvasSaver(h19_nDeMinus      , ps_h19, getMultiBit({yL}));

  cout<<"INFO :: Collision Count = "<<std::setprecision(15)<<h01_CollisionCount->GetEntries()<<std::endl;  

  cout<<"INFO :: Print :: AfterEventInfo :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;

}

template<int Mode, int pidMode, typename I>
void fillGenTrackQA(I inFiles){
  auto ps_h12 = PATH(HIST(MainDir[kMainDir]) + HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode])+HIST("h12_p"       )) ; auto h12_p        = loadMergedHistogram(inFiles, ps_h12); setObjStyle(h12_p       , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode])+"h12_p       ", "p       ", "Counts"});  
  auto ps_h13 = PATH(HIST(MainDir[kMainDir]) + HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode])+HIST("h13_pt"      )) ; auto h13_pt       = loadMergedHistogram(inFiles, ps_h13); setObjStyle(h13_pt      , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode])+"h13_pt      ", "pt      ", "Counts"}); 
  auto ps_h14 = PATH(HIST(MainDir[kMainDir]) + HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode])+HIST("h14_eta"     )) ; auto h14_eta      = loadMergedHistogram(inFiles, ps_h14); setObjStyle(h14_eta     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode])+"h14_eta     ", "eta     ", "Counts"}); 
  auto ps_h15 = PATH(HIST(MainDir[kMainDir]) + HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode])+HIST("h15_phi"     )) ; auto h15_phi      = loadMergedHistogram(inFiles, ps_h15); setObjStyle(h15_phi     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode])+"h15_phi     ", "phi     ", "Counts"}); 
  auto ps_h16 = PATH(HIST(MainDir[kMainDir]) + HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode])+HIST("h16_rapidity")) ; auto h16_rapidity = loadMergedHistogram(inFiles, ps_h16); setObjStyle(h16_rapidity, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode])+"h16_rapidity", "rapidity", "Counts"}); 
  auto ps_h20 = PATH(HIST(MainDir[kMainDir]) + HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode])+HIST("h20_pt_eta"  )) ; auto h20_pt_eta   = loadMergedHistogram(inFiles, ps_h20); setObjStyle(h20_pt_eta  , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode])+"h20_pt_eta"  , "p_{T} (GeV/c)", "#eta"});
  if(DrawSwitch){
    CanvasSaver(h12_p       , ps_h12, getMultiBit({yL}));
    CanvasSaver(h13_pt      , ps_h13, getMultiBit({yL}));
    CanvasSaver(h14_eta     , ps_h14,                 0);
    CanvasSaver(h15_phi     , ps_h15,                 0);
    CanvasSaver(h16_rapidity, ps_h16,                 0);
    CanvasSaver(h20_pt_eta  , ps_h20, getMultiBit({zL, colz}));
  }
}

template <int Mode, int pidMode, int detMode, bool fillSignal, typename I, typename T>
void fillIdentificationQA(const I &inFiles
  ,T &h20_pt_eta
  ,T &h20_p_pt            
  ,T &h21_p_tpcInnerParam 
  ,T &h22_p_tofExpMom    

  ,T &h23_p_tpcSignal             
  ,T &h24_tpcInnerParam_tpcSignal 
  ,T &h25_tofExpMom_tpcSignal     

  ,T &h26_p_beta            
  ,T &h27_tpcInnerParam_beta
  ,T &h28_tofExpMom_beta    

  ,T &h29_p_tpcNSigma            
  ,T &h30_pt_tpcNSigma           
  ,T &h31_tpcInnerParam_tpcNSigma
  ,T &h32_tofExpMom_tpcNSigma    
  ,T &h33_p_tofNSigma            
  ,T &h34_pt_tofNSigma           
  ,T &h35_tpcInnerParam_tofNSigma
  ,T &h36_tofExpMom_tofNSigma    
  ,T &h37_tpcNSigma_tofNSigma    
)
{
  if (fillSignal) {
    // momemtum
    // tpcSignal
    // tofBeta
    auto ps_h19 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h20_pt_eta"                 )); h20_pt_eta                  = loadMergedHistogram(inFiles, ps_h19); setObjStyle(h20_pt_eta                 , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h20_pt_eta"                 , "p_{T} (GeV/c)"        , "#eta"           });
    auto ps_h20 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h20_p_pt"                   )); h20_p_pt                    = loadMergedHistogram(inFiles, ps_h20); setObjStyle(h20_p_pt                   , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h20_p_pt"                   , "p (GeV/c)"            , "pt (GeV/c)"           });
    auto ps_h21 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h21_p_tpcInnerParam"        )); h21_p_tpcInnerParam         = loadMergedHistogram(inFiles, ps_h21); setObjStyle(h21_p_tpcInnerParam        , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h21_p_tpcInnerParam"        , "p (GeV/c)"            , "tpcInnerParam (GeV/c)"});
    auto ps_h22 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h22_p_tofExpMom"            )); h22_p_tofExpMom             = loadMergedHistogram(inFiles, ps_h22); setObjStyle(h22_p_tofExpMom            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h22_p_tofExpMom"            , "p (GeV/c)"            , "tofExpMom (GeV/c)"    });
    auto ps_h23 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h23_p_tpcSignal"            )); h23_p_tpcSignal             = loadMergedHistogram(inFiles, ps_h23); setObjStyle(h23_p_tpcSignal            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h23_p_tpcSignal"            , "p (GeV/c)"            , "tpcSignal"});
    auto ps_h24 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h24_tpcInnerParam_tpcSignal")); h24_tpcInnerParam_tpcSignal = loadMergedHistogram(inFiles, ps_h24); setObjStyle(h24_tpcInnerParam_tpcSignal, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h24_tpcInnerParam_tpcSignal", "tpcInnerParam (GeV/c)", "tpcSignal"});
    auto ps_h25 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h25_tofExpMom_tpcSignal"    )); h25_tofExpMom_tpcSignal     = loadMergedHistogram(inFiles, ps_h25); setObjStyle(h25_tofExpMom_tpcSignal    , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h25_tofExpMom_tpcSignal"    , "tofExpMom (GeV/c)"    , "tpcSignal"});
    auto ps_h26 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h26_p_beta"                 )); h26_p_beta                  = loadMergedHistogram(inFiles, ps_h26); setObjStyle(h26_p_beta                 , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h26_p_beta"                 , "p (GeV/c)"            , "beta"});
    auto ps_h27 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h27_tpcInnerParam_beta"     )); h27_tpcInnerParam_beta      = loadMergedHistogram(inFiles, ps_h27); setObjStyle(h27_tpcInnerParam_beta     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h27_tpcInnerParam_beta"     , "tpcInnerParam (GeV/c)", "beta"});
    auto ps_h28 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h28_tofExpMom_beta"         )); h28_tofExpMom_beta          = loadMergedHistogram(inFiles, ps_h28); setObjStyle(h28_tofExpMom_beta         , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h28_tofExpMom_beta"         , "tofExpMom (GeV/c)"    , "beta"});

    if(DrawSwitch){
    CanvasSaver(h20_pt_eta                 , ps_h19,getMultiBit({zL, colz}));
    CanvasSaver(h20_p_pt                   , ps_h20, getMultiBit({zL, colz}));
    CanvasSaver(h21_p_tpcInnerParam        , ps_h21, getMultiBit({zL, colz}));
    CanvasSaver(h22_p_tofExpMom            , ps_h22, getMultiBit({zL, colz}));
    CanvasSaver(h23_p_tpcSignal            , ps_h23, getMultiBit({zL, colz}));
    CanvasSaver(h24_tpcInnerParam_tpcSignal, ps_h24, getMultiBit({zL, colz}));
    CanvasSaver(h25_tofExpMom_tpcSignal    , ps_h25, getMultiBit({zL, colz}));
    CanvasSaver(h26_p_beta                 , ps_h26, getMultiBit({zL, colz}));
    CanvasSaver(h27_tpcInnerParam_beta     , ps_h27, getMultiBit({zL, colz}));
    CanvasSaver(h28_tofExpMom_beta         , ps_h28, getMultiBit({zL, colz}));
    }
  }
  // NSigma
  auto ps_h29 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h29_p_tpcNSigma"            )) ; h29_p_tpcNSigma             = loadMergedHistogram(inFiles, ps_h29); setObjStyle(h29_p_tpcNSigma             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h29_p_tpcNSigma            ", "p (GeV/c)"            , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
  auto ps_h30 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h30_pt_tpcNSigma"           )) ; h30_pt_tpcNSigma            = loadMergedHistogram(inFiles, ps_h30); setObjStyle(h30_pt_tpcNSigma            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h30_pt_tpcNSigma           ", "pt (GeV/c)"           , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
  auto ps_h31 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h31_tpcInnerParam_tpcNSigma")) ; h31_tpcInnerParam_tpcNSigma = loadMergedHistogram(inFiles, ps_h31); setObjStyle(h31_tpcInnerParam_tpcNSigma , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h31_tpcInnerParam_tpcNSigma", "tpcInnerParam (GeV/c)", "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
  auto ps_h32 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h32_tofExpMom_tpcNSigma"    )) ; h32_tofExpMom_tpcNSigma     = loadMergedHistogram(inFiles, ps_h32); setObjStyle(h32_tofExpMom_tpcNSigma     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h32_tofExpMom_tpcNSigma    ", "tofExpMom (GeV/c)"    , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
  auto ps_h33 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h33_p_tofNSigma"            )) ; h33_p_tofNSigma             = loadMergedHistogram(inFiles, ps_h33); setObjStyle(h33_p_tofNSigma             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h33_p_tofNSigma            ", "p (GeV/c)"            , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
  auto ps_h34 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h34_pt_tofNSigma"           )) ; h34_pt_tofNSigma            = loadMergedHistogram(inFiles, ps_h34); setObjStyle(h34_pt_tofNSigma            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h34_pt_tofNSigma           ", "pt (GeV/c)"           , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
  auto ps_h35 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h35_tpcInnerParam_tofNSigma")) ; h35_tpcInnerParam_tofNSigma = loadMergedHistogram(inFiles, ps_h35); setObjStyle(h35_tpcInnerParam_tofNSigma , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h35_tpcInnerParam_tofNSigma", "tpcInnerParam (GeV/c)", "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
  auto ps_h36 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h36_tofExpMom_tofNSigma"    )) ; h36_tofExpMom_tofNSigma     = loadMergedHistogram(inFiles, ps_h36); setObjStyle(h36_tofExpMom_tofNSigma     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h36_tofExpMom_tofNSigma    ", "tofExpMom (GeV/c)"    , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
  auto ps_h37 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h37_tpcNSigma_tofNSigma"    )) ; h37_tpcNSigma_tofNSigma     = loadMergedHistogram(inFiles, ps_h37); setObjStyle(h37_tpcNSigma_tofNSigma     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h37_tpcNSigma_tofNSigma    ", "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}" , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});

  if(DrawSwitch){
  CanvasSaver(h29_p_tpcNSigma            ,ps_h29, getMultiBit({zL, colz}));
  CanvasSaver(h30_pt_tpcNSigma           ,ps_h30, getMultiBit({zL, colz}));
  CanvasSaver(h31_tpcInnerParam_tpcNSigma,ps_h31, getMultiBit({zL, colz}));
  CanvasSaver(h32_tofExpMom_tpcNSigma    ,ps_h32, getMultiBit({zL, colz}));
  CanvasSaver(h33_p_tofNSigma            ,ps_h33, getMultiBit({zL, colz}));
  CanvasSaver(h34_pt_tofNSigma           ,ps_h34, getMultiBit({zL, colz}));
  CanvasSaver(h35_tpcInnerParam_tofNSigma,ps_h35, getMultiBit({zL, colz}));
  CanvasSaver(h36_tofExpMom_tofNSigma    ,ps_h36, getMultiBit({zL, colz}));
  CanvasSaver(h37_tpcNSigma_tofNSigma    ,ps_h37, getMultiBit({zL, colz}));
  }
}

template <int Mode, typename I>
void fillTrackQA(const I &inFiles)
{
  // FullTrack
  auto ps_h01 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h01_p"            )); auto h01_p              = loadMergedHistogram(inFiles, ps_h01); setObjStyle(h01_p             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h01_p"            ), "p (GeV/c)"             , "Counts"});
  auto ps_h02 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h02_pt"           )); auto h02_pt             = loadMergedHistogram(inFiles, ps_h02); setObjStyle(h02_pt            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h02_pt"           ), "p_{T} (GeV/c)"            , "Counts"});
  auto ps_h03 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h03_tpcInnerParam")); auto h03_tpcInnerParam  = loadMergedHistogram(inFiles, ps_h03); setObjStyle(h03_tpcInnerParam , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h03_tpcInnerParam"), "tpcInnerParam (GeV/c)" , "Counts"});
  auto ps_h04 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h04_tofExpMom"    )); auto h04_tofExpMom      = loadMergedHistogram(inFiles, ps_h04); setObjStyle(h04_tofExpMom     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h04_tofExpMom"    ), "tofExpMom (GeV/c)"     , "Counts"});
  auto ps_h05 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h05_eta"          )); auto h05_eta            = loadMergedHistogram(inFiles, ps_h05); setObjStyle(h05_eta           , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h05_eta"          ), "#eta"           , "Counts"});
  auto ps_h06 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h06_phi"          )); auto h06_phi            = loadMergedHistogram(inFiles, ps_h06); setObjStyle(h06_phi           , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h06_phi"          ), "#phi"           , "Counts"});
  auto ps_h07 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h07_dcaXY"        )); auto h07_dcaXY          = loadMergedHistogram(inFiles, ps_h07); setObjStyle(h07_dcaXY         , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h07_dcaXY"        ), "dcaXY"         , "Counts"});
  auto ps_h08 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h08_dcaZ"         )); auto h08_dcaZ           = loadMergedHistogram(inFiles, ps_h08); setObjStyle(h08_dcaZ          , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h08_dcaZ"         ), "dcaZ"          , "Counts"});
  auto ps_h09 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h09_sign"         )); auto h09_sign           = loadMergedHistogram(inFiles, ps_h09); setObjStyle(h09_sign          , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h09_sign"         ), "sign"          , "Counts"});
  // DcaXY
  auto ps_h10 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h10_p_dcaXY"            )); auto h10_p_dcaXY             = loadMergedHistogram(inFiles, ps_h10); setObjStyle(h10_p_dcaXY             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h10_p_dcaXY"            ), "p (GeV/c)"            , "dcaXY (cm)"});
  auto ps_h11 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h11_pt_dcaXY"           )); auto h11_pt_dcaXY            = loadMergedHistogram(inFiles, ps_h11); setObjStyle(h11_pt_dcaXY            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h11_pt_dcaXY"           ), "p_{T} (GeV/c)"           , "dcaXY (cm)"});
  auto ps_h12 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h12_tpcInnerParam_dcaXY")); auto h12_tpcInnerParam_dcaXY = loadMergedHistogram(inFiles, ps_h12); setObjStyle(h12_tpcInnerParam_dcaXY , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h12_tpcInnerParam_dcaXY"), "tpcInnerParam (GeV/c)", "dcaXY (cm)"});
  auto ps_h13 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h13_tofExpMom_dcaXY"    )); auto h13_tofExpMom_dcaXY     = loadMergedHistogram(inFiles, ps_h13); setObjStyle(h13_tofExpMom_dcaXY     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h13_tofExpMom_dcaXY"    ), "tofExpMom (GeV/c)"    , "dcaXY (cm)"});

  // DcaZ
  auto ps_h14 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h14_p_dcaZ"            )); auto h14_p_dcaZ             = loadMergedHistogram(inFiles, ps_h14); setObjStyle(h14_p_dcaZ             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h14_p_dcaZ"            ), "p (GeV/c)"            , "dcaZ (cm)"});
  auto ps_h15 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h15_pt_dcaZ"           )); auto h15_pt_dcaZ            = loadMergedHistogram(inFiles, ps_h15); setObjStyle(h15_pt_dcaZ            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h15_pt_dcaZ"           ), "p_{T} (GeV/c)"           , "dcaZ (cm)"});
  auto ps_h16 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h16_tpcInnerParam_dcaZ")); auto h16_tpcInnerParam_dcaZ = loadMergedHistogram(inFiles, ps_h16); setObjStyle(h16_tpcInnerParam_dcaZ , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h16_tpcInnerParam_dcaZ"), "tpcInnerParam (GeV/c)", "dcaZ (cm)"});
  auto ps_h17 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h17_tofExpMom_dcaZ"    )); auto h17_tofExpMom_dcaZ     = loadMergedHistogram(inFiles, ps_h17); setObjStyle(h17_tofExpMom_dcaZ     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h17_tofExpMom_dcaZ"    ), "tofExpMom (GeV/c)"    , "dcaZ (cm)"});

  auto ps_h19 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h20_pt_eta"            )); auto h19_pt_eta             = loadMergedHistogram(inFiles, ps_h19); setObjStyle(h19_pt_eta             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h19_pt_eta"           ), "p_{T} (GeV/c)" , "#eta"           });
  // momemtum
  auto ps_h20 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h20_p_pt"           )) ; auto h20_p_pt            = loadMergedHistogram(inFiles, ps_h20); setObjStyle(h20_p_pt            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h20_p_pt"           ), "p (GeV/c)" , "p_{T} (GeV/c)"           });
  auto ps_h21 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h21_p_tpcInnerParam")) ; auto h21_p_tpcInnerParam = loadMergedHistogram(inFiles, ps_h21); setObjStyle(h21_p_tpcInnerParam , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h21_p_tpcInnerParam"), "p (GeV/c)" , "tpcInnerParam (GeV/c)"});
  auto ps_h22 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h22_p_tofExpMom"    )) ; auto h22_p_tofExpMom     = loadMergedHistogram(inFiles, ps_h22); setObjStyle(h22_p_tofExpMom     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h22_p_tofExpMom"    ), "p (GeV/c)" , "tofExpMom (GeV/c)"    });

  // tpcSignal
  auto ps_h23 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h23_p_tpcSignal"            )); auto h23_p_tpcSignal             = loadMergedHistogram(inFiles, ps_h23); setObjStyle(h23_p_tpcSignal             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h23_p_tpcSignal"             ), "p (GeV/c)"             , "-dE/dx (a.u.)"});
  auto ps_h24 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h24_tpcInnerParam_tpcSignal")); auto h24_tpcInnerParam_tpcSignal = loadMergedHistogram(inFiles, ps_h24); setObjStyle(h24_tpcInnerParam_tpcSignal , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h24_tpcInnerParam_tpcSignal" ), "tpcInnerParam (GeV/c)" , "-dE/dx (a.u.)"});
  auto ps_h25 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h25_tofExpMom_tpcSignal"    )); auto h25_tofExpMom_tpcSignal     = loadMergedHistogram(inFiles, ps_h25); setObjStyle(h25_tofExpMom_tpcSignal     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h25_tofExpMom_tpcSignal"     ), "tofExpMom (GeV/c)"     , "-dE/dx (a.u.)"});

  // tofBeta
  auto ps_h26 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h26_p_beta"            )); auto h26_p_beta             = loadMergedHistogram(inFiles, ps_h26); setObjStyle(h26_p_beta             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h26_p_beta"            ), "p (GeV/c)"            , "#beta"});
  auto ps_h27 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h27_tpcInnerParam_beta")); auto h27_tpcInnerParam_beta = loadMergedHistogram(inFiles, ps_h27); setObjStyle(h27_tpcInnerParam_beta , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h27_tpcInnerParam_beta"), "tpcInnerParam (GeV/c)", "#beta"});
  auto ps_h28 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h28_tofExpMom_beta"    )); auto h28_tofExpMom_beta     = loadMergedHistogram(inFiles, ps_h28); setObjStyle(h28_tofExpMom_beta     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST("h28_tofExpMom_beta"    ), "tofExpMom (GeV/c)"    , "#beta"});

  double pLow = 0.0, pUp = 3.0;          
  double tpcLow = -5.0 , tpcHigh = 5.0;
  double tofLow = -5.0 , tofHigh = 5.0;

  SetXYRange(h01_p             ,1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h02_pt            ,1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h03_tpcInnerParam ,1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h04_tofExpMom     ,1, pLow, pUp, 0, pLow, pUp);
  // SetXYRange(h05_eta           ,1, pLow, pUp, 1, pLow, pUp);
  // SetXYRange(h06_phi           ,1, pLow, pUp, 1, pLow, pUp);
  // SetXYRange(h07_dcaXY         ,1, pLow, pUp, 1, pLow, pUp);
  // SetXYRange(h08_dcaZ          ,1, pLow, pUp, 1, pLow, pUp);
  // SetXYRange(h09_sign          ,1, pLow, pUp, 1, pLow, pUp);

  SetXYRange(h10_p_dcaXY             ,1, pLow, pUp, 1, -3, 3);
  SetXYRange(h11_pt_dcaXY            ,1, pLow, pUp, 1, -3, 3);
  SetXYRange(h12_tpcInnerParam_dcaXY ,1, pLow, pUp, 1, -3, 3);
  SetXYRange(h13_tofExpMom_dcaXY     ,1, pLow, pUp, 1, -3, 3);
 
  SetXYRange(h14_p_dcaZ             ,1, pLow, pUp, 1, -3, 3);
  SetXYRange(h15_pt_dcaZ            ,1, pLow, pUp, 1, -3, 3);
  SetXYRange(h16_tpcInnerParam_dcaZ ,1, pLow, pUp, 1, -3, 3);
  SetXYRange(h17_tofExpMom_dcaZ     ,1, pLow, pUp, 1, -3, 3);

  SetXYRange(h20_p_pt                   , 1, pLow, pUp, 1, pLow, pUp);
  SetXYRange(h21_p_tpcInnerParam        , 1, pLow, pUp, 1, pLow, pUp);
  SetXYRange(h22_p_tofExpMom            , 1, pLow, pUp, 1, pLow, pUp);
  SetXYRange(h23_p_tpcSignal            , 1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h24_tpcInnerParam_tpcSignal, 1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h25_tofExpMom_tpcSignal    , 1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h26_p_beta                 , 1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h27_tpcInnerParam_beta     , 1, pLow, pUp, 0, pLow, pUp);
  SetXYRange(h28_tofExpMom_beta         , 1, pLow, pUp, 0, pLow, pUp);
  // SetXYRange(h29_p_tpcNSigma              [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h30_pt_tpcNSigma             [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h31_tpcInnerParam_tpcNSigma  [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h32_tofExpMom_tpcNSigma      [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h33_p_tofNSigma              [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h34_pt_tofNSigma             [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h35_tpcInnerParam_tofNSigma  [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h36_tofExpMom_tofNSigma      [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
  // SetXYRange(h37_tpcNSigma_tofNSigma      [pidMode][3], 1, tpcLow, tpcHigh, 1, tpcLow, tpcHigh);

  if(DrawSwitch){
    CanvasSaver(h01_p                       , ps_h01, getMultiBit({yL}));
    CanvasSaver(h02_pt                      , ps_h02, getMultiBit({yL}));
    CanvasSaver(h03_tpcInnerParam           , ps_h03, getMultiBit({yL}));
    CanvasSaver(h04_tofExpMom               , ps_h04, getMultiBit({yL}));
    CanvasSaver(h05_eta                     , ps_h05, 0);//getMultiBit({yL}));
    CanvasSaver(h06_phi                     , ps_h06, 0);//getMultiBit({yL}));
    CanvasSaver(h07_dcaXY                   , ps_h07, 0);//getMultiBit({yL}));
    CanvasSaver(h08_dcaZ                    , ps_h08, 0);//getMultiBit({yL}));
    CanvasSaver(h09_sign                    , ps_h09, 0);//getMultiBit({yL}));
    CanvasSaver(h10_p_dcaXY                 , ps_h10, getMultiBit({zL,colz}));
    CanvasSaver(h11_pt_dcaXY                , ps_h11, getMultiBit({zL,colz}));
    CanvasSaver(h12_tpcInnerParam_dcaXY     , ps_h12, getMultiBit({zL,colz}));
    CanvasSaver(h13_tofExpMom_dcaXY         , ps_h13, getMultiBit({zL,colz}));
    CanvasSaver(h14_p_dcaZ                  , ps_h14, getMultiBit({zL,colz}));
    CanvasSaver(h15_pt_dcaZ                 , ps_h15, getMultiBit({zL,colz}));
    CanvasSaver(h16_tpcInnerParam_dcaZ      , ps_h16, getMultiBit({zL,colz}));
    CanvasSaver(h17_tofExpMom_dcaZ          , ps_h17, getMultiBit({zL,colz}));    
    CanvasSaver(h20_p_pt                    , ps_h20, getMultiBit({zL,colz}));
    CanvasSaver(h21_p_tpcInnerParam         , ps_h21, getMultiBit({zL,colz}));
    CanvasSaver(h22_p_tofExpMom             , ps_h22, getMultiBit({zL,colz}));
    CanvasSaver(h23_p_tpcSignal             , ps_h23, getMultiBit({zL,colz}));
    CanvasSaver(h24_tpcInnerParam_tpcSignal , ps_h24, getMultiBit({zL,colz}));
    CanvasSaver(h25_tofExpMom_tpcSignal     , ps_h25, getMultiBit({zL,colz}));
    CanvasSaver(h26_p_beta                  , ps_h26, getMultiBit({zL,colz}));
    CanvasSaver(h27_tpcInnerParam_beta      , ps_h27, getMultiBit({zL,colz}));
    CanvasSaver(h28_tofExpMom_beta          , ps_h28, getMultiBit({zL,colz}));
  }


  // TH1* xh20_p_pt;            
  // TH1* xh21_p_tpcInnerParam; 
  // TH1* xh22_p_tofExpMom;    
  // TH1* xh23_p_tpcSignal;             
  // TH1* xh24_tpcInnerParam_tpcSignal; 
  // TH1* xh25_tofExpMom_tpcSignal;     
  // TH1* xh26_p_beta;            
  // TH1* xh27_tpcInnerParam_beta;
  // TH1* xh28_tofExpMom_beta;    

  TH1* h29_p_tpcNSigma;            
  TH1* h30_pt_tpcNSigma;           
  TH1* h31_tpcInnerParam_tpcNSigma;
  TH1* h32_tofExpMom_tpcNSigma;    
  TH1* h33_p_tofNSigma;            
  TH1* h34_pt_tofNSigma;           
  TH1* h35_tpcInnerParam_tofNSigma;
  TH1* h36_tofExpMom_tofNSigma;    
  TH1* h37_tpcNSigma_tofNSigma;    

  fillIdentificationQA<Mode, kPi, NoId, false>(inFiles,
                                                h19_pt_eta,
                                                h20_p_pt,
                                                h21_p_tpcInnerParam,
                                                h22_p_tofExpMom,
                                                h23_p_tpcSignal,
                                                h24_tpcInnerParam_tpcSignal,
                                                h25_tofExpMom_tpcSignal,
                                                h26_p_beta,
                                                h27_tpcInnerParam_beta,
                                                h28_tofExpMom_beta,
                                                h29_p_tpcNSigma,
                                                h30_pt_tpcNSigma,
                                                h31_tpcInnerParam_tpcNSigma,
                                                h32_tofExpMom_tpcNSigma,
                                                h33_p_tofNSigma,
                                                h34_pt_tofNSigma,
                                                h35_tpcInnerParam_tofNSigma,
                                                h36_tofExpMom_tofNSigma,
                                                h37_tpcNSigma_tofNSigma); // Look at Pion
  fillIdentificationQA<Mode, kKa, NoId, false>(inFiles,
                                                h19_pt_eta,
                                                h20_p_pt,
                                                h21_p_tpcInnerParam,
                                                h22_p_tofExpMom,
                                                h23_p_tpcSignal,
                                                h24_tpcInnerParam_tpcSignal,
                                                h25_tofExpMom_tpcSignal,
                                                h26_p_beta,
                                                h27_tpcInnerParam_beta,
                                                h28_tofExpMom_beta,
                                                h29_p_tpcNSigma,
                                                h30_pt_tpcNSigma,
                                                h31_tpcInnerParam_tpcNSigma,
                                                h32_tofExpMom_tpcNSigma,
                                                h33_p_tofNSigma,
                                                h34_pt_tofNSigma,
                                                h35_tpcInnerParam_tofNSigma,
                                                h36_tofExpMom_tofNSigma,
                                                h37_tpcNSigma_tofNSigma); // Look at Kaon
  fillIdentificationQA<Mode, kPr, NoId, false>(inFiles,
                                                h19_pt_eta,
                                                h20_p_pt,
                                                h21_p_tpcInnerParam,
                                                h22_p_tofExpMom,
                                                h23_p_tpcSignal,
                                                h24_tpcInnerParam_tpcSignal,
                                                h25_tofExpMom_tpcSignal,
                                                h26_p_beta,
                                                h27_tpcInnerParam_beta,
                                                h28_tofExpMom_beta,
                                                h29_p_tpcNSigma,
                                                h30_pt_tpcNSigma,
                                                h31_tpcInnerParam_tpcNSigma,
                                                h32_tofExpMom_tpcNSigma,
                                                h33_p_tofNSigma,
                                                h34_pt_tofNSigma,
                                                h35_tpcInnerParam_tofNSigma,
                                                h36_tofExpMom_tofNSigma,
                                                h37_tpcNSigma_tofNSigma); // Look at Proton
  fillIdentificationQA<Mode, kEl, NoId, false>(inFiles,
                                                h19_pt_eta,
                                                h20_p_pt,
                                                h21_p_tpcInnerParam,
                                                h22_p_tofExpMom,
                                                h23_p_tpcSignal,
                                                h24_tpcInnerParam_tpcSignal,
                                                h25_tofExpMom_tpcSignal,
                                                h26_p_beta,
                                                h27_tpcInnerParam_beta,
                                                h28_tofExpMom_beta,
                                                h29_p_tpcNSigma,
                                                h30_pt_tpcNSigma,
                                                h31_tpcInnerParam_tpcNSigma,
                                                h32_tofExpMom_tpcNSigma,
                                                h33_p_tofNSigma,
                                                h34_pt_tofNSigma,
                                                h35_tpcInnerParam_tofNSigma,
                                                h36_tofExpMom_tofNSigma,
                                                h37_tpcNSigma_tofNSigma); // Look at Electron
  fillIdentificationQA<Mode, kDe, NoId, false>(inFiles,
                                                h19_pt_eta,
                                                h20_p_pt,
                                                h21_p_tpcInnerParam,
                                                h22_p_tofExpMom,
                                                h23_p_tpcSignal,
                                                h24_tpcInnerParam_tpcSignal,
                                                h25_tofExpMom_tpcSignal,
                                                h26_p_beta,
                                                h27_tpcInnerParam_beta,
                                                h28_tofExpMom_beta,
                                                h29_p_tpcNSigma,
                                                h30_pt_tpcNSigma,
                                                h31_tpcInnerParam_tpcNSigma,
                                                h32_tofExpMom_tpcNSigma,
                                                h33_p_tofNSigma,
                                                h34_pt_tofNSigma,
                                                h35_tpcInnerParam_tofNSigma,
                                                h36_tofExpMom_tofNSigma,
                                                h37_tpcNSigma_tofNSigma); // Look at Deuteron

}

template <int Mode, int pidMode, int detMode, typename I, typename T>
void fillV0DaughterQA(const I &inFiles
  ,T &h01_p                             
  ,T &h02_pt                           
  ,T &h03_tpcInnerParam     
  ,T &h04_tofExpMom             
  ,T &h05_eta                         
  ,T &h06_phi                         
  ,T &h07_rapidity               
  ,T &h08_isPVContributor 
  ,T &h09_isGlobalTrack     
  ,T &h10_dcaXY                     
  ,T &h11_dcaZ                       
  ,T &h12_p_dcaXY                 
  ,T &h13_p_dcaZ                   
  ,T &h14_pt_dcaXY               
  ,T &h15_pt_dcaZ                 
  ,T &h16_dcaXYwide             
  ,T &h17_dcaZwide         
  ,T &h20_pt_eta

  ,T &h20_p_pt           
  ,T &h21_p_tpcInnerParam 
  ,T &h22_p_tofExpMom    

  ,T &h23_p_tpcSignal             
  ,T &h24_tpcInnerParam_tpcSignal 
  ,T &h25_tofExpMom_tpcSignal     

  ,T &h26_p_beta            
  ,T &h27_tpcInnerParam_beta
  ,T &h28_tofExpMom_beta    

  ,T &h29_p_tpcNSigma            
  ,T &h30_pt_tpcNSigma           
  ,T &h31_tpcInnerParam_tpcNSigma
  ,T &h32_tofExpMom_tpcNSigma    
  ,T &h33_p_tofNSigma            
  ,T &h34_pt_tofNSigma           
  ,T &h35_tpcInnerParam_tofNSigma
  ,T &h36_tofExpMom_tofNSigma    
  ,T &h37_tpcNSigma_tofNSigma    
)// histReg, const T& track, double particleMass)
{
  // K0s-Daughter Info
  auto ps_h01 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h01_p"              )); h01_p                = loadMergedHistogram(inFiles, ps_h01); setObjStyle(h01_p               , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"p              ", "p"              , "Counts"});
  auto ps_h02 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h02_pt"             )); h02_pt               = loadMergedHistogram(inFiles, ps_h02); setObjStyle(h02_pt              , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"pt             ", "pt"             , "Counts"});
  auto ps_h03 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h03_tpcInnerParam"  )); h03_tpcInnerParam    = loadMergedHistogram(inFiles, ps_h03); setObjStyle(h03_tpcInnerParam   , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"tpcInnerParam  ", "tpcInnerParam"  , "Counts"});
  auto ps_h04 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h04_tofExpMom"      )); h04_tofExpMom        = loadMergedHistogram(inFiles, ps_h04); setObjStyle(h04_tofExpMom       , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"tofExpMom      ", "tofExpMom"      , "Counts"});
  auto ps_h05 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h05_eta"            )); h05_eta              = loadMergedHistogram(inFiles, ps_h05); setObjStyle(h05_eta             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"eta            ", "eta"            , "Counts"});
  auto ps_h06 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h06_phi"            )); h06_phi              = loadMergedHistogram(inFiles, ps_h06); setObjStyle(h06_phi             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"phi            ", "phi"            , "Counts"});
  auto ps_h07 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h07_rapidity"       )); h07_rapidity         = loadMergedHistogram(inFiles, ps_h07); setObjStyle(h07_rapidity        , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"rapidity       ", "rapidity"       , "Counts"});
  auto ps_h08 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h08_isPVContributor")); h08_isPVContributor  = loadMergedHistogram(inFiles, ps_h08); setObjStyle(h08_isPVContributor , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"isPVContributor", "isPVContributor", "Counts"});
  auto ps_h09 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h09_isGlobalTrack"  )); h09_isGlobalTrack    = loadMergedHistogram(inFiles, ps_h09); setObjStyle(h09_isGlobalTrack   , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"isGlobalTrack  ", "isGlobalTrack"  , "Counts"});
  auto ps_h10 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h10_dcaXY"          )); h10_dcaXY            = loadMergedHistogram(inFiles, ps_h10); setObjStyle(h10_dcaXY           , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaXY          ", "dcaXY"          , "Counts"});
  auto ps_h11 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h11_dcaZ"           )); h11_dcaZ             = loadMergedHistogram(inFiles, ps_h11); setObjStyle(h11_dcaZ            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaZ           ", "dcaZ"           , "Counts"});
  auto ps_h12 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h12_p_dcaXY"        )); h12_p_dcaXY          = loadMergedHistogram(inFiles, ps_h12); setObjStyle(h12_p_dcaXY         , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"p_dcaXY        ", "p"              , "dcaXY"});
  auto ps_h13 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h13_p_dcaZ"         )); h13_p_dcaZ           = loadMergedHistogram(inFiles, ps_h13); setObjStyle(h13_p_dcaZ          , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"p_dcaZ         ", "p"              , "dcaZ"});
  auto ps_h14 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h14_pt_dcaXY"       )); h14_pt_dcaXY         = loadMergedHistogram(inFiles, ps_h14); setObjStyle(h14_pt_dcaXY        , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"pt_dcaXY       ", "pt"             , "dcaXY"});
  auto ps_h15 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h15_pt_dcaZ"        )); h15_pt_dcaZ          = loadMergedHistogram(inFiles, ps_h15); setObjStyle(h15_pt_dcaZ         , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"pt_dcaZ        ", "pt"             , "dcaZ"});
  auto ps_h16 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h16_dcaXYwide"      )); h16_dcaXYwide        = loadMergedHistogram(inFiles, ps_h16); setObjStyle(h16_dcaXYwide       , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaXYwide      ", "dcaXYwide"      , "Counts"});
  auto ps_h17 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h17_dcaZwide"       )); h17_dcaZwide         = loadMergedHistogram(inFiles, ps_h17); setObjStyle(h17_dcaZwide        , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaZwide       ", "dcaZwide"       , "Counts"});
  // auto ps_h19 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h20_pt_eta"         )); h19_pt_eta           = loadMergedHistogram(inFiles, ps_h19); setObjStyle(h19_pt_eta          , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"pt_eta"         , "p_{T} [GeV/c]"  , "#eta"});
  if(DrawSwitch){
  CanvasSaver(h01_p              , ps_h01, getMultiBit({yL}));
  CanvasSaver(h02_pt             , ps_h02, getMultiBit({yL}));
  CanvasSaver(h03_tpcInnerParam  , ps_h03, getMultiBit({yL}));
  CanvasSaver(h04_tofExpMom      , ps_h04, getMultiBit({yL}));
  CanvasSaver(h05_eta            , ps_h05, 0);//getMultiBit({yL}));
  CanvasSaver(h06_phi            , ps_h06, 0);//getMultiBit({yL}));
  CanvasSaver(h07_rapidity       , ps_h07, 0);//getMultiBit({yL}));
  CanvasSaver(h08_isPVContributor, ps_h08, 0);//getMultiBit({yL}));
  CanvasSaver(h09_isGlobalTrack  , ps_h09, 0);//getMultiBit({yL}));
  CanvasSaver(h10_dcaXY          , ps_h10, 0);//getMultiBit({yL}));
  CanvasSaver(h11_dcaZ           , ps_h11, 0);//getMultiBit({yL}));
  CanvasSaver(h12_p_dcaXY        , ps_h12, getMultiBit({zL,colz}));
  CanvasSaver(h13_p_dcaZ         , ps_h13, getMultiBit({zL,colz}));
  CanvasSaver(h14_pt_dcaXY       , ps_h14, getMultiBit({zL,colz}));
  CanvasSaver(h15_pt_dcaZ        , ps_h15, getMultiBit({zL,colz}));
  CanvasSaver(h16_dcaXYwide      , ps_h16, getMultiBit({yL}));
  CanvasSaver(h17_dcaZwide       , ps_h17, getMultiBit({yL}));
}

  fillIdentificationQA<Mode, kPi, detMode, true>(inFiles
  ,h20_pt_eta
  ,h20_p_pt            
  ,h21_p_tpcInnerParam 
  ,h22_p_tofExpMom    

  ,h23_p_tpcSignal             
  ,h24_tpcInnerParam_tpcSignal 
  ,h25_tofExpMom_tpcSignal     

  ,h26_p_beta            
  ,h27_tpcInnerParam_beta
  ,h28_tofExpMom_beta    

  ,h29_p_tpcNSigma            
  ,h30_pt_tpcNSigma           
  ,h31_tpcInnerParam_tpcNSigma
  ,h32_tofExpMom_tpcNSigma    
  ,h33_p_tofNSigma            
  ,h34_pt_tofNSigma           
  ,h35_tpcInnerParam_tofNSigma
  ,h36_tofExpMom_tofNSigma    
  ,h37_tpcNSigma_tofNSigma      
  );
}



template <int Mode, typename I>//, typename T, typename U>
void fillV0QA(I inFiles) //H histReg, const T& v0, const U& posDaughterTrack, const U& negDaughterTrack, const int& v0Tag, const int& v0DauCollisionIndexTag, const int& posPiIdMethod, const int& negPiIdMethod)
{
  auto ps_h01 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h01_K0s_Mass"                   )); auto h01_K0s_Mass                    = loadMergedHistogram(inFiles, ps_h01); setObjStyle(h01_K0s_Mass                   , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"K0s_Mass                   ", "mass ::(#pi^{+}#pi^{-}) #it{M}_{inv} [GeV/#it{c}^{2}]", "Counts"});
  auto ps_h02 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h02_Lambda_Mass"                )); auto h02_Lambda_Mass                 = loadMergedHistogram(inFiles, ps_h02); setObjStyle(h02_Lambda_Mass                , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"Lambda_Mass                ", "Lambda_Mass                ", "Counts"});
  auto ps_h03 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h03_AntiLambda_Mass"            )); auto h03_AntiLambda_Mass             = loadMergedHistogram(inFiles, ps_h03); setObjStyle(h03_AntiLambda_Mass            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"AntiLambda_Mass            ", "AntiLambda_Mass            ", "Counts"});
  auto ps_h04 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h04_v0DaughterCollisionIndexTag")); auto h04_v0DaughterCollisionIndexTag = loadMergedHistogram(inFiles, ps_h04); setObjStyle(h04_v0DaughterCollisionIndexTag, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"v0DaughterCollisionIndexTag", "v0DaughterCollisionIndexTag", "Counts"});
  auto ps_h05 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h05_V0Tag"                      )); auto h05_V0Tag                       = loadMergedHistogram(inFiles, ps_h05); setObjStyle(h05_V0Tag                      , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"V0Tag                      ", "V0Tag                      ", "Counts"});
  
  if(DrawSwitch){
  CanvasSaver(h01_K0s_Mass                   , ps_h01, 0);                 
  CanvasSaver(h02_Lambda_Mass                , ps_h02, 0);                 
  CanvasSaver(h03_AntiLambda_Mass            , ps_h03, 0);                 
  CanvasSaver(h04_v0DaughterCollisionIndexTag, ps_h04, getMultiBit({yL})); 
  CanvasSaver(h05_V0Tag                      , ps_h05, getMultiBit({yL}));
  }

  // Topological Cuts
  auto ps_h06 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h06_dcapostopv"    )) ; auto h06_dcapostopv     = loadMergedHistogram(inFiles, ps_h06); setObjStyle(h06_dcapostopv    , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"dcapostopv    ", "DCA of positive daughter to PV(cm)", "Counts"}); 
  auto ps_h07 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h07_dcanegtopv"    )) ; auto h07_dcanegtopv     = loadMergedHistogram(inFiles, ps_h07); setObjStyle(h07_dcanegtopv    , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"dcanegtopv    ", "DCA of negative daughter to PV(cm)", "Counts"}); 
  auto ps_h08 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h08_dcaV0daughters")) ; auto h08_dcaV0daughters = loadMergedHistogram(inFiles, ps_h08); setObjStyle(h08_dcaV0daughters, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"dcaV0daughters", "DCA of V0daughters (cm)", "Counts"}); 
  auto ps_h09 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h09_v0cosPA"       )) ; auto h09_v0cosPA        = loadMergedHistogram(inFiles, ps_h09); setObjStyle(h09_v0cosPA       , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"v0cosPA       ", "cosine of Pointing Angle", "Counts"}); 
  auto ps_h10 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h10_v0radius"      )) ; auto h10_v0radius       = loadMergedHistogram(inFiles, ps_h10); setObjStyle(h10_v0radius      , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"v0radius      ", "v0 Radius (cm)", "Counts"}); 

  auto h06_dcapostopv_zoom     = GetZoomed1DHist(h06_dcapostopv    , -0.5,0.5 );
  auto h07_dcanegtopv_zoom     = GetZoomed1DHist(h07_dcanegtopv    , -0.5,0.5 );
  auto h08_dcaV0daughters_zoom = GetZoomed1DHist(h08_dcaV0daughters, -1.0,2.0 );
  auto h09_v0cosPA_zoom        = GetZoomed1DHist(h09_v0cosPA       , 0.97,1.02);
  auto h10_v0radius_zoom       = GetZoomed1DHist(h10_v0radius      , -1.0,2.0 );

  if(DrawSwitch){
    CanvasSaver(h06_dcapostopv_zoom    , ps_h06, 0);                 
    CanvasSaver(h07_dcanegtopv_zoom    , ps_h07, 0);                 
    CanvasSaver(h08_dcaV0daughters_zoom, ps_h08, 0);                 
    CanvasSaver(h09_v0cosPA_zoom       , ps_h09, getMultiBit({yL})); 
    CanvasSaver(h10_v0radius_zoom      , ps_h10, getMultiBit({yL}));
  }

  if(DrawSwitch){
  CanvasSaver(h06_dcapostopv    , ps_h06, getMultiBit({yL}));
  CanvasSaver(h07_dcanegtopv    , ps_h07, getMultiBit({yL}));
  CanvasSaver(h08_dcaV0daughters, ps_h08, getMultiBit({yL}));
  CanvasSaver(h09_v0cosPA       , ps_h09, getMultiBit({yL}));
  CanvasSaver(h10_v0radius      , ps_h10, getMultiBit({yL}));

  DrawFour1DPlots(ps_h06, h06_dcapostopv    , h06_dcapostopv_zoom    , h07_dcanegtopv, h07_dcanegtopv_zoom );
  DrawFour1DPlots(ps_h06, h08_dcaV0daughters, h08_dcaV0daughters_zoom, h09_v0cosPA   , h09_v0cosPA_zoom    );
  DrawTwo1DPlots (ps_h06, h10_v0radius      , h10_v0radius_zoom                                            );
  }

  // K0s-FullInformation
  auto ps_h11 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h11_mass"    )) ;auto h11_mass     = loadMergedHistogram(inFiles, ps_h11); setObjStyle(h11_mass    , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"mass    ", "mass ::(#pi^{+}#pi^{-}) #it{M}_{inv} [GeV/#it{c}^{2}]", "Counts"}); 
  auto ps_h12 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h12_p"       )) ;auto h12_p        = loadMergedHistogram(inFiles, ps_h12); setObjStyle(h12_p       , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"p       ", "p (GeV/c)", "Counts"});                                                 
  auto ps_h13 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h13_pt"      )) ;auto h13_pt       = loadMergedHistogram(inFiles, ps_h13); setObjStyle(h13_pt      , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"pt      ", "p_{T} (GeV/c)", "Counts"});                                                 
  auto ps_h14 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h14_eta"     )) ;auto h14_eta      = loadMergedHistogram(inFiles, ps_h14); setObjStyle(h14_eta     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"eta     ", "#eta", "Counts"});                                                 
  auto ps_h15 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h15_phi"     )) ;auto h15_phi      = loadMergedHistogram(inFiles, ps_h15); setObjStyle(h15_phi     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"phi     ", "#phi", "Counts"});                                                 
  auto ps_h16 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h16_rapidity")) ;auto h16_rapidity = loadMergedHistogram(inFiles, ps_h16); setObjStyle(h16_rapidity, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"rapidity", "y ", "Counts"});                                                 

  auto ps_h17 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h17_alpha"      ));auto h17_alpha       = loadMergedHistogram(inFiles, ps_h17); setObjStyle(h17_alpha      , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"alpha"      , "|#alpha_{arm}|"   , "Counts"           });
  auto ps_h18 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h18_qtarm"      ));auto h18_qtarm       = loadMergedHistogram(inFiles, ps_h18); setObjStyle(h18_qtarm      , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"qtarm"      , "q_{#perp} (GeV/c)", "Counts"           });
  auto ps_h19 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h19_alpha_qtarm"));auto h19_alpha_qtarm = loadMergedHistogram(inFiles, ps_h19); setObjStyle(h19_alpha_qtarm, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"alpha_qtarm", "|#alpha_{arm}|"   , "q_{#perp} (GeV/c)"});
  auto ps_h20 = PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST("h20_pt_eta"     ));auto h20_pt_eta      = loadMergedHistogram(inFiles, ps_h20); setObjStyle(h20_pt_eta     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+"pt_eta"     , "p_{T} (GeV/c)"    , "#eta"             });


  //Momentum
  SetXYRange(h12_p        ,1, 0.0, 3.0, 0, 0.0, 3.0);
  SetXYRange(h13_pt       ,1, 0.0, 3.0, 0, 0.0, 3.0);
  // SetXYRange(h14_eta      ,1, 0.0, 3.0, 0, 0.0, 3.0);
  // SetXYRange(h15_phi      ,1, 0.0, 3.0, 0, 0.0, 3.0);
  SetXYRange(h16_rapidity ,1, -1.0, 1.0, 0, 0.0, 3.0);

  if(DrawSwitch){
  CanvasSaver(h11_mass          , ps_h11, 0                );
  CanvasSaver(h12_p             , ps_h12, getMultiBit({yL}));
  CanvasSaver(h13_pt            , ps_h13, getMultiBit({yL}));
  CanvasSaver(h14_eta           , ps_h14, 0                );
  CanvasSaver(h15_phi           , ps_h15, 0                );
  CanvasSaver(h16_rapidity      , ps_h16, 0                );

  CanvasSaver(h17_alpha      , ps_h17, 0                );
  CanvasSaver(h18_qtarm      , ps_h18, 0                );
  CanvasSaver(h19_alpha_qtarm, ps_h19, getMultiBit({zL, colz}));
  CanvasSaver(h20_pt_eta     , ps_h20, getMultiBit({zL,colz}));
  
  DrawOnePairPlot(ps_h11, h11_mass                            );
  DrawFour1DPlots(ps_h11, h12_p, h13_pt, h14_eta, h16_rapidity);
  }

    TH1* h01_p               [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h01_p"              )).c_str())); setObjStyle(h01_p               , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"p              ", "p              ", "Counts"}); CanvasSaver(h01_p              , getMultiBit({yL}));
    TH1* h02_pt              [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h02_pt"             )).c_str())); setObjStyle(h02_pt              , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"pt             ", "pt             ", "Counts"}); CanvasSaver(h02_pt             , getMultiBit({yL}));
    TH1* h03_tpcInnerParam   [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h03_tpcInnerParam"  )).c_str())); setObjStyle(h03_tpcInnerParam   , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"tpcInnerParam  ", "tpcInnerParam  ", "Counts"}); CanvasSaver(h03_tpcInnerParam  , getMultiBit({yL}));
    TH1* h04_tofExpMom       [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h04_tofExpMom"      )).c_str())); setObjStyle(h04_tofExpMom       , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"tofExpMom      ", "tofExpMom      ", "Counts"}); CanvasSaver(h04_tofExpMom      , getMultiBit({yL}));
    TH1* h05_eta             [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h05_eta"            )).c_str())); setObjStyle(h05_eta             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"eta            ", "eta            ", "Counts"}); CanvasSaver(h05_eta            , 0);//getMultiBit({yL}));
    TH1* h06_phi             [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h06_phi"            )).c_str())); setObjStyle(h06_phi             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"phi            ", "phi            ", "Counts"}); CanvasSaver(h06_phi            , 0);//getMultiBit({yL}));
    TH1* h07_rapidity        [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h07_rapidity"       )).c_str())); setObjStyle(h07_rapidity        , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"rapidity       ", "rapidity       ", "Counts"}); CanvasSaver(h07_rapidity       , 0);//getMultiBit({yL}));
    TH1* h08_isPVContributor [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h08_isPVContributor")).c_str())); setObjStyle(h08_isPVContributor , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"isPVContributor", "isPVContributor", "Counts"}); CanvasSaver(h08_isPVContributor, 0);//getMultiBit({yL}));
    TH1* h09_isGlobalTrack   [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h09_isGlobalTrack"  )).c_str())); setObjStyle(h09_isGlobalTrack   , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"isGlobalTrack  ", "isGlobalTrack  ", "Counts"}); CanvasSaver(h09_isGlobalTrack  , 0);//getMultiBit({yL}));
    TH1* h10_dcaXY           [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h10_dcaXY"          )).c_str())); setObjStyle(h10_dcaXY           , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaXY          ", "dcaXY          ", "Counts"}); CanvasSaver(h10_dcaXY          , 0);//getMultiBit({yL}));
    TH1* h11_dcaZ            [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h11_dcaZ"           )).c_str())); setObjStyle(h11_dcaZ            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaZ           ", "dcaZ           ", "Counts"}); CanvasSaver(h11_dcaZ           , 0);//getMultiBit({yL}));
    TH1* h12_p_dcaXY         [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h12_p_dcaXY"        )).c_str())); setObjStyle(h12_p_dcaXY         , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"p_dcaXY        ", "p_dcaXY        ", "Counts"}); CanvasSaver(h12_p_dcaXY        , getMultiBit({zL,colz}));
    TH1* h13_p_dcaZ          [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h13_p_dcaZ"         )).c_str())); setObjStyle(h13_p_dcaZ          , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"p_dcaZ         ", "p_dcaZ         ", "Counts"}); CanvasSaver(h13_p_dcaZ         , getMultiBit({zL,colz}));
    TH1* h14_pt_dcaXY        [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h14_pt_dcaXY"       )).c_str())); setObjStyle(h14_pt_dcaXY        , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"pt_dcaXY       ", "pt_dcaXY       ", "Counts"}); CanvasSaver(h14_pt_dcaXY       , getMultiBit({zL,colz}));
    TH1* h15_pt_dcaZ         [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h15_pt_dcaZ"        )).c_str())); setObjStyle(h15_pt_dcaZ         , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"pt_dcaZ        ", "pt_dcaZ        ", "Counts"}); CanvasSaver(h15_pt_dcaZ        , getMultiBit({zL,colz}));
    TH1* h16_dcaXYwide       [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h16_dcaXYwide"      )).c_str())); setObjStyle(h16_dcaXYwide       , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaXYwide      ", "dcaXYwide      ", "Counts"}); CanvasSaver(h16_dcaXYwide      , getMultiBit({yL}));
    TH1* h17_dcaZwide        [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h17_dcaZwide"       )).c_str())); setObjStyle(h17_dcaZwide        , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) + HIST(DetDire[detMode])+"dcaZwide       ", "dcaZwide       ", "Counts"}); CanvasSaver(h17_dcaZwide       , getMultiBit({yL}));
    TH1* h19_pt_eta          [4] ;

    TH1* h20_p_pt             [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h20_p_pt"           )).c_str())); setObjStyle(h20_p_pt           , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h20_p_pt"           , "p", "pt"           }); CanvasSaver(h20_p_pt           , getMultiBit({zL, colz}));
    TH1* h21_p_tpcInnerParam  [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h21_p_tpcInnerParam")).c_str())); setObjStyle(h21_p_tpcInnerParam, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h21_p_tpcInnerParam", "p", "tpcInnerParam"}); CanvasSaver(h21_p_tpcInnerParam, getMultiBit({zL, colz}));
    TH1* h22_p_tofExpMom      [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h22_p_tofExpMom"    )).c_str())); setObjStyle(h22_p_tofExpMom    , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h22_p_tofExpMom"    , "p", "tofExpMom"    }); CanvasSaver(h22_p_tofExpMom    , getMultiBit({zL, colz}));
    // tpcSignal
    TH1* h23_p_tpcSignal             [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h23_p_tpcSignal"            )).c_str())); setObjStyle(h23_p_tpcSignal            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h23_p_tpcSignal"            , "p            ","tpcSignal"}); CanvasSaver(h23_p_tpcSignal            , getMultiBit({zL, colz}));
    TH1* h24_tpcInnerParam_tpcSignal [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h24_tpcInnerParam_tpcSignal")).c_str())); setObjStyle(h24_tpcInnerParam_tpcSignal, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h24_tpcInnerParam_tpcSignal", "tpcInnerParam","tpcSignal"}); CanvasSaver(h24_tpcInnerParam_tpcSignal, getMultiBit({zL, colz}));
    TH1* h25_tofExpMom_tpcSignal     [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h25_tofExpMom_tpcSignal"    )).c_str())); setObjStyle(h25_tofExpMom_tpcSignal    , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h25_tofExpMom_tpcSignal"    , "tofExpMom    ","tpcSignal"}); CanvasSaver(h25_tofExpMom_tpcSignal    , getMultiBit({zL, colz}));
    // tofBeta
    TH1* h26_p_beta             [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h26_p_beta"            )).c_str())); setObjStyle(h26_p_beta            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h26_p_beta"             , "p"            , "beta"}); CanvasSaver(h26_p_beta            , getMultiBit({zL, colz}));
    TH1* h27_tpcInnerParam_beta [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h27_tpcInnerParam_beta")).c_str())); setObjStyle(h27_tpcInnerParam_beta, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h27_tpcInnerParam_beta" , "tpcInnerParam", "beta"}); CanvasSaver(h27_tpcInnerParam_beta, getMultiBit({zL, colz}));
    TH1* h28_tofExpMom_beta     [4] ;//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h28_tofExpMom_beta"    )).c_str())); setObjStyle(h28_tofExpMom_beta    , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h28_tofExpMom_beta"     , "tofExpMom"    , "beta"}); CanvasSaver(h28_tofExpMom_beta    , getMultiBit({zL, colz}));

    // NSigma
    TH1* h29_p_tpcNSigma             [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h29_p_tpcNSigma"            )).c_str())); setObjStyle(h29_p_tpcNSigma             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h29_p_tpcNSigma            ", "p            "    , "tpcNSigma"}); CanvasSaver(h29_p_tpcNSigma            , getMultiBit({zL, colz}));
    TH1* h30_pt_tpcNSigma            [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h30_pt_tpcNSigma"           )).c_str())); setObjStyle(h30_pt_tpcNSigma            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h30_pt_tpcNSigma           ", "pt           "    , "tpcNSigma"}); CanvasSaver(h30_pt_tpcNSigma           , getMultiBit({zL, colz}));
    TH1* h31_tpcInnerParam_tpcNSigma [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h31_tpcInnerParam_tpcNSigma")).c_str())); setObjStyle(h31_tpcInnerParam_tpcNSigma , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h31_tpcInnerParam_tpcNSigma", "tpcInnerParam"    , "tpcNSigma"}); CanvasSaver(h31_tpcInnerParam_tpcNSigma, getMultiBit({zL, colz}));
    TH1* h32_tofExpMom_tpcNSigma     [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h32_tofExpMom_tpcNSigma"    )).c_str())); setObjStyle(h32_tofExpMom_tpcNSigma     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h32_tofExpMom_tpcNSigma    ", "tofExpMom    "    , "tpcNSigma"}); CanvasSaver(h32_tofExpMom_tpcNSigma    , getMultiBit({zL, colz}));
    TH1* h33_p_tofNSigma             [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h33_p_tofNSigma"            )).c_str())); setObjStyle(h33_p_tofNSigma             , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h33_p_tofNSigma            ", "p            "    , "tofNSigma"}); CanvasSaver(h33_p_tofNSigma            , getMultiBit({zL, colz}));
    TH1* h34_pt_tofNSigma            [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h34_pt_tofNSigma"           )).c_str())); setObjStyle(h34_pt_tofNSigma            , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h34_pt_tofNSigma           ", "pt           "    , "tofNSigma"}); CanvasSaver(h34_pt_tofNSigma           , getMultiBit({zL, colz}));
    TH1* h35_tpcInnerParam_tofNSigma [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h35_tpcInnerParam_tofNSigma")).c_str())); setObjStyle(h35_tpcInnerParam_tofNSigma , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h35_tpcInnerParam_tofNSigma", "tpcInnerParam"    , "tofNSigma"}); CanvasSaver(h35_tpcInnerParam_tofNSigma, getMultiBit({zL, colz}));
    TH1* h36_tofExpMom_tofNSigma     [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h36_tofExpMom_tofNSigma"    )).c_str())); setObjStyle(h36_tofExpMom_tofNSigma     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h36_tofExpMom_tofNSigma    ", "tofExpMom    "    , "tofNSigma"}); CanvasSaver(h36_tofExpMom_tofNSigma    , getMultiBit({zL, colz}));
    TH1* h37_tpcNSigma_tofNSigma     [4];//= dynamic_cast<TH1*>(inFile->Get(PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + HIST("h37_tpcNSigma_tofNSigma"    )).c_str())); setObjStyle(h37_tpcNSigma_tofNSigma     , getMultiBit({hT,xT,yT}), {HIST(HistRegDire[Mode]) + HIST(PidDire[pidMode]) + HIST(DetDire[detMode]) + "h37_tpcNSigma_tofNSigma    ", "tpcNSigma    "    , "tofNSigma"}); CanvasSaver(h37_tpcNSigma_tofNSigma    , getMultiBit({zL, colz}));

  
    //Info of Daughters 
  // if (posPiIdMethod == 0) {
    fillV0DaughterQA<Mode, kPi, tpcId>(inFiles
      ,h01_p               [0]               
      ,h02_pt              [0]              
      ,h03_tpcInnerParam   [0]   
      ,h04_tofExpMom       [0]       
      ,h05_eta             [0]             
      ,h06_phi             [0]             
      ,h07_rapidity        [0]        
      ,h08_isPVContributor [0] 
      ,h09_isGlobalTrack   [0]   
      ,h10_dcaXY           [0]           
      ,h11_dcaZ            [0]            
      ,h12_p_dcaXY         [0]         
      ,h13_p_dcaZ          [0]          
      ,h14_pt_dcaXY        [0]        
      ,h15_pt_dcaZ         [0]         
      ,h16_dcaXYwide       [0]       
      ,h17_dcaZwide        [0]  
      ,h19_pt_eta          [0]  

      ,h20_p_pt            [0] 
      ,h21_p_tpcInnerParam [0] 
      ,h22_p_tofExpMom     [0] 
      // tpcSignal
      ,h23_p_tpcSignal             [0]
      ,h24_tpcInnerParam_tpcSignal [0]
      ,h25_tofExpMom_tpcSignal     [0]
      // tofBeta
      ,h26_p_beta             [0]
      ,h27_tpcInnerParam_beta [0]
      ,h28_tofExpMom_beta     [0]
  
      // NSigma
      ,h29_p_tpcNSigma             [0]
      ,h30_pt_tpcNSigma            [0]
      ,h31_tpcInnerParam_tpcNSigma [0]
      ,h32_tofExpMom_tpcNSigma     [0]
      ,h33_p_tofNSigma             [0]
      ,h34_pt_tofNSigma            [0]
      ,h35_tpcInnerParam_tofNSigma [0]
      ,h36_tofExpMom_tofNSigma     [0]
      ,h37_tpcNSigma_tofNSigma     [0]
    );

    // // } else if (posPiIdMethod == 1) {
    fillV0DaughterQA<Mode, kPi, tpctofId>(inFiles
      ,h01_p               [1]               
      ,h02_pt              [1]              
      ,h03_tpcInnerParam   [1]   
      ,h04_tofExpMom       [1]       
      ,h05_eta             [1]             
      ,h06_phi             [1]             
      ,h07_rapidity        [1]        
      ,h08_isPVContributor [1] 
      ,h09_isGlobalTrack   [1]   
      ,h10_dcaXY           [1]           
      ,h11_dcaZ            [1]            
      ,h12_p_dcaXY         [1]         
      ,h13_p_dcaZ          [1]          
      ,h14_pt_dcaXY        [1]        
      ,h15_pt_dcaZ         [1]         
      ,h16_dcaXYwide       [1]       
      ,h17_dcaZwide        [1]  
      ,h19_pt_eta          [1]  

      ,h20_p_pt            [1] 
      ,h21_p_tpcInnerParam [1] 
      ,h22_p_tofExpMom     [1]

      // tpcSignal
      ,h23_p_tpcSignal             [1]
      ,h24_tpcInnerParam_tpcSignal [1]
      ,h25_tofExpMom_tpcSignal     [1]
      // tofBeta
      ,h26_p_beta             [1]
      ,h27_tpcInnerParam_beta [1]
      ,h28_tofExpMom_beta     [1]
  
      // NSigma
      ,h29_p_tpcNSigma             [1]
      ,h30_pt_tpcNSigma            [1]
      ,h31_tpcInnerParam_tpcNSigma [1]
      ,h32_tofExpMom_tpcNSigma     [1]
      ,h33_p_tofNSigma             [1]
      ,h34_pt_tofNSigma            [1]
      ,h35_tpcInnerParam_tofNSigma [1]
      ,h36_tofExpMom_tofNSigma     [1]
      ,h37_tpcNSigma_tofNSigma     [1]
    );
  // // // } else if (posPiIdMethod == -1) {
    fillV0DaughterQA<Mode, kPi, NoId>(inFiles
      ,h01_p               [2]               
      ,h02_pt              [2]              
      ,h03_tpcInnerParam   [2]   
      ,h04_tofExpMom       [2]       
      ,h05_eta             [2]             
      ,h06_phi             [2]             
      ,h07_rapidity        [2]        
      ,h08_isPVContributor [2] 
      ,h09_isGlobalTrack   [2]   
      ,h10_dcaXY           [2]           
      ,h11_dcaZ            [2]            
      ,h12_p_dcaXY         [2]         
      ,h13_p_dcaZ          [2]          
      ,h14_pt_dcaXY        [2]        
      ,h15_pt_dcaZ         [2]         
      ,h16_dcaXYwide       [2]       
      ,h17_dcaZwide        [2]  
      ,h19_pt_eta          [2]  
      
      ,h20_p_pt            [2] 
      ,h21_p_tpcInnerParam [2] 
      ,h22_p_tofExpMom     [2]

      // tpcSignal
      ,h23_p_tpcSignal             [2]
      ,h24_tpcInnerParam_tpcSignal [2]
      ,h25_tofExpMom_tpcSignal     [2]
      // tofBeta
      ,h26_p_beta             [2]
      ,h27_tpcInnerParam_beta [2]
      ,h28_tofExpMom_beta     [2]
  
      // NSigma
      ,h29_p_tpcNSigma             [2]
      ,h30_pt_tpcNSigma            [2]
      ,h31_tpcInnerParam_tpcNSigma [2]
      ,h32_tofExpMom_tpcNSigma     [2]
      ,h33_p_tofNSigma             [2]
      ,h34_pt_tofNSigma            [2]
      ,h35_tpcInnerParam_tofNSigma [2]
      ,h36_tofExpMom_tofNSigma     [2]
      ,h37_tpcNSigma_tofNSigma     [2]
    );

    // // }

  //Get the histograms from above functions
  // K0s-Daughter Info

    ps_h01 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/p              " ;  h01_p               [3]= AddTwoHistograms("sh01_p"                   , h01_p               [0], h01_p               [1]); setObjStyle(h01_p               [3], getMultiBit({hT,xT,yT}), {ps_h01.c_str(), "p (GeV/c)              ", "Counts"});
    ps_h02 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/pt             " ;  h02_pt              [3]= AddTwoHistograms("sh02_pt_sum"              , h02_pt              [0], h02_pt              [1]); setObjStyle(h02_pt              [3], getMultiBit({hT,xT,yT}), {ps_h02.c_str(), "p_{T} (GeV/c)             ", "Counts"});
    ps_h03 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/tpcInnerParam  " ;  h03_tpcInnerParam   [3]= AddTwoHistograms("sh03_tpcInnerParam_sum"   , h03_tpcInnerParam   [0], h03_tpcInnerParam   [1]); setObjStyle(h03_tpcInnerParam   [3], getMultiBit({hT,xT,yT}), {ps_h03.c_str(), "tpcInnerParam (GeV/c)  ", "Counts"});
    ps_h04 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/tofExpMom      " ;  h04_tofExpMom       [3]= AddTwoHistograms("sh04_tofExpMom_sum"       , h04_tofExpMom       [0], h04_tofExpMom       [1]); setObjStyle(h04_tofExpMom       [3], getMultiBit({hT,xT,yT}), {ps_h04.c_str(), "tofExpMom (GeV/c)      ", "Counts"});
    ps_h05 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/eta            " ;  h05_eta             [3]= AddTwoHistograms("sh05_eta_sum"             , h05_eta             [0], h05_eta             [1]); setObjStyle(h05_eta             [3], getMultiBit({hT,xT,yT}), {ps_h05.c_str(), "#eta            ", "Counts"});
    ps_h06 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/phi            " ;  h06_phi             [3]= AddTwoHistograms("sh06_phi_sum"             , h06_phi             [0], h06_phi             [1]); setObjStyle(h06_phi             [3], getMultiBit({hT,xT,yT}), {ps_h06.c_str(), "#phi           ", "Counts"});
    ps_h07 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/rapidity       " ;  h07_rapidity        [3]= AddTwoHistograms("sh07_rapidity_sum"        , h07_rapidity        [0], h07_rapidity        [1]); setObjStyle(h07_rapidity        [3], getMultiBit({hT,xT,yT}), {ps_h07.c_str(), "y       ", "Counts"});
    ps_h08 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/isPVContributor" ;  h08_isPVContributor [3]= AddTwoHistograms("sh08_isPVContributor_sum" , h08_isPVContributor [0], h08_isPVContributor [1]); setObjStyle(h08_isPVContributor [3], getMultiBit({hT,xT,yT}), {ps_h08.c_str(), "isPVContributor", "Counts"});
    ps_h09 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/isGlobalTrack  " ;  h09_isGlobalTrack   [3]= AddTwoHistograms("sh09_isGlobalTrack_sum"   , h09_isGlobalTrack   [0], h09_isGlobalTrack   [1]); setObjStyle(h09_isGlobalTrack   [3], getMultiBit({hT,xT,yT}), {ps_h09.c_str(), "isGlobalTrack  ", "Counts"});
    ps_h10 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/dcaXY          " ;  h10_dcaXY           [3]= AddTwoHistograms("sh10_dcaXY_sum"           , h10_dcaXY           [0], h10_dcaXY           [1]); setObjStyle(h10_dcaXY           [3], getMultiBit({hT,xT,yT}), {ps_h10.c_str(), "dcaXY          ", "Counts"});
    ps_h11 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/dcaZ           " ;  h11_dcaZ            [3]= AddTwoHistograms("sh11_dcaZ_sum"            , h11_dcaZ            [0], h11_dcaZ            [1]); setObjStyle(h11_dcaZ            [3], getMultiBit({hT,xT,yT}), {ps_h11.c_str(), "dcaZ           ", "Counts"});
    ps_h12 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/p_dcaXY        " ;  h12_p_dcaXY         [3]= AddTwoHistograms("sh12_p_dcaXY_sum"         , h12_p_dcaXY         [0], h12_p_dcaXY         [1]); setObjStyle(h12_p_dcaXY         [3], getMultiBit({hT,xT,yT}), {ps_h12.c_str(), "p (GeV/c)", "dcaXY (cm)" });
    ps_h13 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/p_dcaZ         " ;  h13_p_dcaZ          [3]= AddTwoHistograms("sh13_p_dcaZ_sum"          , h13_p_dcaZ          [0], h13_p_dcaZ          [1]); setObjStyle(h13_p_dcaZ          [3], getMultiBit({hT,xT,yT}), {ps_h13.c_str(), "p (GeV/c)", "dcaZ (cm)"  });
    ps_h14 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/pt_dcaXY       " ;  h14_pt_dcaXY        [3]= AddTwoHistograms("sh14_pt_dcaXY_sum"        , h14_pt_dcaXY        [0], h14_pt_dcaXY        [1]); setObjStyle(h14_pt_dcaXY        [3], getMultiBit({hT,xT,yT}), {ps_h14.c_str(), "p_{T} (GeV/c)", "dcaXY (cm)" });
    ps_h15 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/pt_dcaZ        " ;  h15_pt_dcaZ         [3]= AddTwoHistograms("sh15_pt_dcaZ_sum"         , h15_pt_dcaZ         [0], h15_pt_dcaZ         [1]); setObjStyle(h15_pt_dcaZ         [3], getMultiBit({hT,xT,yT}), {ps_h15.c_str(), "p_{T} (GeV/c)", "dcaZ (cm) " });
    ps_h16 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/dcaXYwide      " ;  h16_dcaXYwide       [3]= AddTwoHistograms("sh16_dcaXYwide_sum"       , h16_dcaXYwide       [0], h16_dcaXYwide       [1]); setObjStyle(h16_dcaXYwide       [3], getMultiBit({hT,xT,yT}), {ps_h16.c_str(), "dcaXYwide"    , "Counts"});
    ps_h17 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/dcaZwide"        ;  h17_dcaZwide        [3]= AddTwoHistograms("sh17_dcaZwide_sum"        , h17_dcaZwide        [0], h17_dcaZwide        [1]); setObjStyle(h17_dcaZwide        [3], getMultiBit({hT,xT,yT}), {ps_h17.c_str(), "dcaZwide"     , "Counts"});
    ps_h19 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/pt_eta"          ;  h19_pt_eta          [3]= AddTwoHistograms("sh19_pt_eta"              , h19_pt_eta          [0], h19_pt_eta          [1]); setObjStyle(h19_pt_eta          [3], getMultiBit({hT,xT,yT}), {ps_h19.c_str(), "p_{T} (GeV/c)", "#eta"});

    SetXYRange(h01_p               [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h02_pt              [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h03_tpcInnerParam   [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h04_tofExpMom       [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    // SetXYRange(h05_eta             [3], 1, 
    // SetXYRange(h06_phi             [3], 1, 
    // SetXYRange(h07_rapidity        [3], 1, 
    // SetXYRange(h08_isPVContributor [3], 1, 
    // SetXYRange(h09_isGlobalTrack   [3], 1, 
    // SetXYRange(h10_dcaXY           [3], 1, 
    // SetXYRange(h11_dcaZ            [3], 1, 
    // SetXYRange(h12_p_dcaXY         [3], 1, 
    // SetXYRange(h13_p_dcaZ          [3], 1, 
    SetXYRange(h14_pt_dcaXY        [3], 1, 0.0, 3.0, 1, -3.0, 3.0); 
    SetXYRange(h15_pt_dcaZ         [3], 1, 0.0, 3.0, 1, -3.0, 3.0); 
    // SetXYRange(h16_dcaXYwide       [3], 1, 

    // SetXYRange(h12_p        ,1, 0.0, 3.0, 0, 0.0, 3.0);
    // //Momentum
    // SetXYRange(h12_p        ,1, 0.0, 3.0, 0, 0.0, 3.0);
    // SetXYRange(h13_pt       ,1, 0.0, 3.0, 0, 0.0, 3.0);
    // // SetXYRange(h14_eta      ,1, 0.0, 3.0, 0, 0.0, 3.0);
    // // SetXYRange(h15_phi      ,1, 0.0, 3.0, 0, 0.0, 3.0);
    // SetXYRange(h16_rapidity ,1, -1.0, 1.0, 0, 0.0, 3.0);

    if(DrawSwitch){
    CanvasSaver(h01_p               [3], HIST(MainDir[kMainDir])+ps_h01, getMultiBit({yL}));
    CanvasSaver(h02_pt              [3], HIST(MainDir[kMainDir])+ps_h02, getMultiBit({yL}));
    CanvasSaver(h03_tpcInnerParam   [3], HIST(MainDir[kMainDir])+ps_h03, getMultiBit({yL}));
    CanvasSaver(h04_tofExpMom       [3], HIST(MainDir[kMainDir])+ps_h04, getMultiBit({yL}));
    CanvasSaver(h05_eta             [3], HIST(MainDir[kMainDir])+ps_h05, 0);//getMultiBit({yL}));
    CanvasSaver(h06_phi             [3], HIST(MainDir[kMainDir])+ps_h06, 0);//getMultiBit({yL}));
    CanvasSaver(h07_rapidity        [3], HIST(MainDir[kMainDir])+ps_h07, 0);//getMultiBit({yL}));
    CanvasSaver(h08_isPVContributor [3], HIST(MainDir[kMainDir])+ps_h08, 0);//getMultiBit({yL}));
    CanvasSaver(h09_isGlobalTrack   [3], HIST(MainDir[kMainDir])+ps_h09, 0);//getMultiBit({yL}));
    CanvasSaver(h10_dcaXY           [3], HIST(MainDir[kMainDir])+ps_h10, 0);//getMultiBit({yL}));
    CanvasSaver(h11_dcaZ            [3], HIST(MainDir[kMainDir])+ps_h11, 0);//getMultiBit({yL}));
    CanvasSaver(h12_p_dcaXY         [3], HIST(MainDir[kMainDir])+ps_h12, getMultiBit({zL,colz}));
    CanvasSaver(h13_p_dcaZ          [3], HIST(MainDir[kMainDir])+ps_h13, getMultiBit({zL,colz}));
    CanvasSaver(h14_pt_dcaXY        [3], HIST(MainDir[kMainDir])+ps_h14, getMultiBit({zL,colz}));
    CanvasSaver(h15_pt_dcaZ         [3], HIST(MainDir[kMainDir])+ps_h15, getMultiBit({zL,colz}));
    CanvasSaver(h16_dcaXYwide       [3], HIST(MainDir[kMainDir])+ps_h16, getMultiBit({yL}));
    CanvasSaver(h17_dcaZwide        [3], HIST(MainDir[kMainDir])+ps_h17, getMultiBit({yL}));
    CanvasSaver(h19_pt_eta          [3], HIST(MainDir[kMainDir])+ps_h19, getMultiBit({zL,colz}));    
    }

    //momemtum
    //tpcSignal                                                                                                                     
    //tofBeta  
    //Look at Pion
    int pidMode = kPi;
    /*TH1* */     ps_h19 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh20_pt_eta"                  ; h19_pt_eta                  [3] = AddTwoHistograms("sh19_pt_eta"                   , h19_pt_eta                  [0], h19_pt_eta                  [1]); setObjStyle(h19_pt_eta                  [3], getMultiBit({hT,xT,yT}), {ps_h19, "p_{T}  (GeV/c)"                 , "#eta"});
    /*TH1* */     ps_h20 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh20_p_pt"                    ; h20_p_pt                    [3] = AddTwoHistograms("sh20_p_pt"                     , h20_p_pt                    [0], h20_p_pt                    [1]); setObjStyle(h20_p_pt                    [3], getMultiBit({hT,xT,yT}), {ps_h20, "p (GeV/c)"                      , "p_{T}  (GeV/c)"});
    /*TH1* */auto ps_h21 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh21_p_tpcInnerParam"         ; h21_p_tpcInnerParam         [3] = AddTwoHistograms("sh21_p_tpcInnerParam"          , h21_p_tpcInnerParam         [0], h21_p_tpcInnerParam         [1]); setObjStyle(h21_p_tpcInnerParam         [3], getMultiBit({hT,xT,yT}), {ps_h21, "p (GeV/c)"                      , "tpcInnerParam  (GeV/c)"});
    /*TH1* */auto ps_h22 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh22_p_tofExpMom"             ; h22_p_tofExpMom             [3] = AddTwoHistograms("sh22_p_tofExpMom"              , h22_p_tofExpMom             [0], h22_p_tofExpMom             [1]); setObjStyle(h22_p_tofExpMom             [3], getMultiBit({hT,xT,yT}), {ps_h22, "p (GeV/c)"                      , "tofExpMom  (GeV/c)    "});
    /*TH1* */auto ps_h23 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh23_p_tpcSignal"             ; h23_p_tpcSignal             [3] = AddTwoHistograms("sh23_p_tpcSignDrawSwitchal"    , h23_p_tpcSignal             [0], h23_p_tpcSignal             [1]); setObjStyle(h23_p_tpcSignal             [3], getMultiBit({hT,xT,yT}), {ps_h23, "p (GeV/c)"                      , "-dE/dx (a.u.) "}); //(i.e. tpcSignal in a.u.)    
    /*TH1* */auto ps_h24 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh24_tpcInnerParam_tpcSignal" ; h24_tpcInnerParam_tpcSignal [3] = AddTwoHistograms("sh24_tpcInnerParam_tpcSignal"  , h24_tpcInnerParam_tpcSignal [0], h24_tpcInnerParam_tpcSignal [1]); setObjStyle(h24_tpcInnerParam_tpcSignal [3], getMultiBit({hT,xT,yT}), {ps_h24, "tpcInnerParam (GeV/c)"          , "-dE/dx (a.u.) "}); //(i.e. tpcSignal in a.u.)    
    /*TH1* */auto ps_h25 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh25_tofExpMom_tpcSignal"     ; h25_tofExpMom_tpcSignal     [3] = AddTwoHistograms("sh25_tofExpMom_tpcSignal"      , h25_tofExpMom_tpcSignal     [0], h25_tofExpMom_tpcSignal     [1]); setObjStyle(h25_tofExpMom_tpcSignal     [3], getMultiBit({hT,xT,yT}), {ps_h25, "tofExpMom (GeV/c)"              , "-dE/dx (a.u.) "}); //(i.e. tpcSignal in a.u.)    
    /*TH1* */auto ps_h26 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh26_p_beta"                  ; h26_p_beta                  [3] = AddTwoHistograms("sh26_p_beta"                   , h26_p_beta                  [0], h26_p_beta                  [1]); setObjStyle(h26_p_beta                  [3], getMultiBit({hT,xT,yT}), {ps_h26, "p (GeV/c)"                      , "#beta"         });
    /*TH1* */auto ps_h27 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh27_tpcInnerParam_beta"      ; h27_tpcInnerParam_beta      [3] = AddTwoHistograms("sh27_tpcInnerParam_beta"       , h27_tpcInnerParam_beta      [0], h27_tpcInnerParam_beta      [1]); setObjStyle(h27_tpcInnerParam_beta      [3], getMultiBit({hT,xT,yT}), {ps_h27, "tpcInnerParam (GeV/c)"          , "#beta"         });
    /*TH1* */auto ps_h28 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh28_tofExpMom_beta"          ; h28_tofExpMom_beta          [3] = AddTwoHistograms("sh28_tofExpMom_beta"           , h28_tofExpMom_beta          [0], h28_tofExpMom_beta          [1]); setObjStyle(h28_tofExpMom_beta          [3], getMultiBit({hT,xT,yT}), {ps_h28, "tofExpMom (GeV/c)"              , "#beta"         });
    /*TH1* */auto ps_h29 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh29_p_tpcNSigma"             ; h29_p_tpcNSigma             [3] = AddTwoHistograms("sh29_p_tpcNSigma"              , h29_p_tpcNSigma             [0], h29_p_tpcNSigma             [1]); setObjStyle(h29_p_tpcNSigma             [3], getMultiBit({hT,xT,yT}), {ps_h29, "p (GeV/c)"            , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    /*TH1* */auto ps_h30 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh30_pt_tpcNSigma"            ; h30_pt_tpcNSigma            [3] = AddTwoHistograms("sh30_pt_tpcNSigma"             , h30_pt_tpcNSigma            [0], h30_pt_tpcNSigma            [1]); setObjStyle(h30_pt_tpcNSigma            [3], getMultiBit({hT,xT,yT}), {ps_h30, "p_{T} (GeV/c)"           , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    /*TH1* */auto ps_h31 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh31_tpcInnerParam_tpcNSigma" ; h31_tpcInnerParam_tpcNSigma [3] = AddTwoHistograms("sh31_tpcInnerParam_tpcNSigma"  , h31_tpcInnerParam_tpcNSigma [0], h31_tpcInnerParam_tpcNSigma [1]); setObjStyle(h31_tpcInnerParam_tpcNSigma [3], getMultiBit({hT,xT,yT}), {ps_h31, "tpcInnerParam (GeV/c)", "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    /*TH1* */auto ps_h32 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh32_tofExpMom_tpcNSigma"     ; h32_tofExpMom_tpcNSigma     [3] = AddTwoHistograms("sh32_tofExpMom_tpcNSigma"      , h32_tofExpMom_tpcNSigma     [0], h32_tofExpMom_tpcNSigma     [1]); setObjStyle(h32_tofExpMom_tpcNSigma     [3], getMultiBit({hT,xT,yT}), {ps_h32, "tofExpMom (GeV/c)"    , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    /*TH1* */auto ps_h33 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh33_p_tofNSigma"             ; h33_p_tofNSigma             [3] = AddTwoHistograms("sh33_p_tofNSigma"              , h33_p_tofNSigma             [0], h33_p_tofNSigma             [1]); setObjStyle(h33_p_tofNSigma             [3], getMultiBit({hT,xT,yT}), {ps_h33, "p (GeV/c)"            , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    /*TH1* */auto ps_h34 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh34_pt_tofNSigma"            ; h34_pt_tofNSigma            [3] = AddTwoHistograms("sh34_pt_tofNSigma"             , h34_pt_tofNSigma            [0], h34_pt_tofNSigma            [1]); setObjStyle(h34_pt_tofNSigma            [3], getMultiBit({hT,xT,yT}), {ps_h34, "p_{T} (GeV/c)"           , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    /*TH1* */auto ps_h35 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh35_tpcInnerParam_tofNSigma" ; h35_tpcInnerParam_tofNSigma [3] = AddTwoHistograms("sh35_tpcInnerParam_tofNSigma"  , h35_tpcInnerParam_tofNSigma [0], h35_tpcInnerParam_tofNSigma [1]); setObjStyle(h35_tpcInnerParam_tofNSigma [3], getMultiBit({hT,xT,yT}), {ps_h35, "tpcInnerParam (GeV/c)", "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    /*TH1* */auto ps_h36 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh36_tofExpMom_tofNSigma"     ; h36_tofExpMom_tofNSigma     [3] = AddTwoHistograms("sh36_tofExpMom_tofNSigma"      , h36_tofExpMom_tofNSigma     [0], h36_tofExpMom_tofNSigma     [1]); setObjStyle(h36_tofExpMom_tofNSigma     [3], getMultiBit({hT,xT,yT}), {ps_h36, "tofExpMom (GeV/c)"    , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    /*TH1* */auto ps_h37 = HIST(HistRegDire[Mode])+HIST(PidDire[kPi]) +"sum/sh37_tpcNSigma_tofNSigma"     ; h37_tpcNSigma_tofNSigma     [3] = AddTwoHistograms("sh37_tpcNSigma_tofNSigma"      , h37_tpcNSigma_tofNSigma     [0], h37_tpcNSigma_tofNSigma     [1]); setObjStyle(h37_tpcNSigma_tofNSigma     [3], getMultiBit({hT,xT,yT}), {ps_h37, "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}" , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});  

    // SetXYRange(h01_p               [3], 1, 0.0, 3.0, 0, 0.0, 3.0);

    SetXYRange(h19_pt_eta                  [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h20_p_pt                    [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h21_p_tpcInnerParam         [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h22_p_tofExpMom             [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h23_p_tpcSignal             [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h24_tpcInnerParam_tpcSignal [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h25_tofExpMom_tpcSignal     [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h26_p_beta                  [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h27_tpcInnerParam_beta      [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h28_tofExpMom_beta          [3], 1, 0.0, 3.0, 0, 0.0, 3.0);
    SetXYRange(h29_p_tpcNSigma             [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h30_pt_tpcNSigma            [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h31_tpcInnerParam_tpcNSigma [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h32_tofExpMom_tpcNSigma     [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h33_p_tofNSigma             [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h34_pt_tofNSigma            [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h35_tpcInnerParam_tofNSigma [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h36_tofExpMom_tofNSigma     [3], 1, 0.0, 3.0, 1, -5.0, 5.0);
    SetXYRange(h37_tpcNSigma_tofNSigma     [3], 1, -5.0, 5.0, 1, -5.0, 5.0);


    if(DrawSwitch){
      CanvasSaver(h19_pt_eta                   [3], HIST(MainDir[kMainDir])+ps_h19,getMultiBit({zL,colz}));
      CanvasSaver(h20_p_pt                     [3], HIST(MainDir[kMainDir])+ps_h20, getMultiBit({zL,colz}));
      CanvasSaver(h21_p_tpcInnerParam          [3], HIST(MainDir[kMainDir])+ps_h21, getMultiBit({zL,colz}));
      CanvasSaver(h22_p_tofExpMom              [3], HIST(MainDir[kMainDir])+ps_h22, getMultiBit({zL,colz}));
      CanvasSaver(h23_p_tpcSignal              [3], HIST(MainDir[kMainDir])+ps_h23, getMultiBit({zL,colz}));
      CanvasSaver(h24_tpcInnerParam_tpcSignal  [3], HIST(MainDir[kMainDir])+ps_h24, getMultiBit({zL,colz}));
      CanvasSaver(h25_tofExpMom_tpcSignal      [3], HIST(MainDir[kMainDir])+ps_h25, getMultiBit({zL,colz}));
      CanvasSaver(h26_p_beta                   [3], HIST(MainDir[kMainDir])+ps_h26, getMultiBit({zL,colz}));
      CanvasSaver(h27_tpcInnerParam_beta       [3], HIST(MainDir[kMainDir])+ps_h27, getMultiBit({zL,colz}));
      CanvasSaver(h28_tofExpMom_beta           [3], HIST(MainDir[kMainDir])+ps_h28, getMultiBit({zL,colz}));
      CanvasSaver(h29_p_tpcNSigma              [3], HIST(MainDir[kMainDir])+ps_h29, getMultiBit({zL,colz}));
      CanvasSaver(h30_pt_tpcNSigma             [3], HIST(MainDir[kMainDir])+ps_h30, getMultiBit({zL,colz}));
      CanvasSaver(h31_tpcInnerParam_tpcNSigma  [3], HIST(MainDir[kMainDir])+ps_h31, getMultiBit({zL,colz}));
      CanvasSaver(h32_tofExpMom_tpcNSigma      [3], HIST(MainDir[kMainDir])+ps_h32, getMultiBit({zL,colz}));
      CanvasSaver(h33_p_tofNSigma              [3], HIST(MainDir[kMainDir])+ps_h33, getMultiBit({zL,colz}));
      CanvasSaver(h34_pt_tofNSigma             [3], HIST(MainDir[kMainDir])+ps_h34, getMultiBit({zL,colz}));
      CanvasSaver(h35_tpcInnerParam_tofNSigma  [3], HIST(MainDir[kMainDir])+ps_h35, getMultiBit({zL,colz}));
      CanvasSaver(h36_tofExpMom_tofNSigma      [3], HIST(MainDir[kMainDir])+ps_h36, getMultiBit({zL,colz}));
      CanvasSaver(h37_tpcNSigma_tofNSigma      [3], HIST(MainDir[kMainDir])+ps_h37, getMultiBit({zL,colz}));    
      }
  
    double pLow = 0.0, pUp = 4.0;      
    //Momentum
    SetXYRange(h20_p_pt            [0] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h21_p_tpcInnerParam [0] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h22_p_tofExpMom     [0] ,1, pLow, pUp, 1, pLow, pUp);

    SetXYRange(h20_p_pt            [1] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h21_p_tpcInnerParam [1] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h22_p_tofExpMom     [1] ,1, pLow, pUp, 1, pLow, pUp);

    SetXYRange(h20_p_pt            [3] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h21_p_tpcInnerParam [3] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h22_p_tofExpMom     [3] ,1, pLow, pUp, 1, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h20, h20_p_pt            [0],h20_p_pt            [1],h20_p_pt            [3]
                   ,h21_p_tpcInnerParam [0],h21_p_tpcInnerParam [1],h21_p_tpcInnerParam [3]);
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h22, h22_p_tofExpMom     [0],h22_p_tofExpMom     [1],h22_p_tofExpMom     [3]);
    }
  // //Momenturm
  // //tpcSignal
    SetXYRange(h23_p_tpcSignal             [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h24_tpcInnerParam_tpcSignal [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h25_tofExpMom_tpcSignal     [0], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h23_p_tpcSignal             [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h24_tpcInnerParam_tpcSignal [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h25_tofExpMom_tpcSignal     [1], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h23_p_tpcSignal             [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h24_tpcInnerParam_tpcSignal [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h25_tofExpMom_tpcSignal     [3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h23, h23_p_tpcSignal             [0], h23_p_tpcSignal             [1], h23_p_tpcSignal             [3]
                   ,h24_tpcInnerParam_tpcSignal [0], h24_tpcInnerParam_tpcSignal [1], h24_tpcInnerParam_tpcSignal [3]);
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h25, h25_tofExpMom_tpcSignal     [0], h25_tofExpMom_tpcSignal     [1], h25_tofExpMom_tpcSignal     [3]);
    }
  // //tpcSignal
  // //tofBeta
    SetXYRange(h26_p_beta                   [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h27_tpcInnerParam_beta       [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h28_tofExpMom_beta           [0], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h26_p_beta                   [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h27_tpcInnerParam_beta       [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h28_tofExpMom_beta           [1], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h26_p_beta                   [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h27_tpcInnerParam_beta       [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h28_tofExpMom_beta           [3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h26, h26_p_beta                   [0], h26_p_beta                   [1], h26_p_beta                   [3]
                   ,h27_tpcInnerParam_beta       [0], h27_tpcInnerParam_beta       [1], h27_tpcInnerParam_beta       [3]);
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h28, h28_tofExpMom_beta           [0], h28_tofExpMom_beta           [1], h28_tofExpMom_beta           [3]);
    }
  //tofBeta
  //Look at Pion
    SetXYRange(h29_p_tpcNSigma              [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h30_pt_tpcNSigma             [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h31_tpcInnerParam_tpcNSigma  [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h32_tofExpMom_tpcNSigma      [0], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h29_p_tpcNSigma              [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h30_pt_tpcNSigma             [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h31_tpcInnerParam_tpcNSigma  [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h32_tofExpMom_tpcNSigma      [1], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h29_p_tpcNSigma              [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h30_pt_tpcNSigma             [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h31_tpcInnerParam_tpcNSigma  [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h32_tofExpMom_tpcNSigma      [3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h29,
       h29_p_tpcNSigma              [0] ,h29_p_tpcNSigma              [1], h29_p_tpcNSigma              [3]
      // ,h30_pt_tpcNSigma             [0] ,h30_pt_tpcNSigma             [1], h30_pt_tpcNSigma             [3]
      ,h31_tpcInnerParam_tpcNSigma  [0] ,h31_tpcInnerParam_tpcNSigma  [1], h31_tpcInnerParam_tpcNSigma  [3]
      // ,h32_tofExpMom_tpcNSigma      [0] ,h32_tofExpMom_tpcNSigma      [1], h32_tofExpMom_tpcNSigma      [3]
    );
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h32,
      // h29_p_tpcNSigma              [0] ,h29_p_tpcNSigma              [1], h29_p_tpcNSigma              [3]
      // ,h30_pt_tpcNSigma             [0] ,h30_pt_tpcNSigma             [1], h30_pt_tpcNSigma             [3]
      // ,h31_tpcInnerParam_tpcNSigma  [0] ,h31_tpcInnerParam_tpcNSigma  [1], h31_tpcInnerParam_tpcNSigma  [3]
      h32_tofExpMom_tpcNSigma      [0] ,h32_tofExpMom_tpcNSigma      [1], h32_tofExpMom_tpcNSigma      [3]
    );
     }
    //
    SetXYRange(h33_p_tofNSigma              [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h34_pt_tofNSigma             [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h35_tpcInnerParam_tofNSigma  [0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h36_tofExpMom_tofNSigma      [0], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h33_p_tofNSigma              [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h34_pt_tofNSigma             [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h35_tpcInnerParam_tofNSigma  [1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h36_tofExpMom_tofNSigma      [1], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h33_p_tofNSigma              [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h34_pt_tofNSigma             [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h35_tpcInnerParam_tofNSigma  [3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h36_tofExpMom_tofNSigma      [3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h33,
      h33_p_tofNSigma              [0] ,h33_p_tofNSigma              [1], h33_p_tofNSigma              [3]
      // ,h34_pt_tofNSigma             [0] ,h34_pt_tofNSigma             [1], h34_pt_tofNSigma             [3]
      ,h35_tpcInnerParam_tofNSigma  [0] ,h35_tpcInnerParam_tofNSigma  [1], h35_tpcInnerParam_tofNSigma  [3]
      // ,h36_tofExpMom_tofNSigma      [0] ,h36_tofExpMom_tofNSigma      [1], h36_tofExpMom_tofNSigma      [3]
    );
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h36,
      // ,h33_p_tofNSigma              [0] ,h33_p_tofNSigma              [1], h33_p_tofNSigma              [3]
      // ,h34_pt_tofNSigma             [0] ,h34_pt_tofNSigma             [1], h34_pt_tofNSigma             [3]
      // ,h35_tpcInnerParam_tofNSigma  [0] ,h35_tpcInnerParam_tofNSigma  [1], h35_tpcInnerParam_tofNSigma  [3]
      h36_tofExpMom_tofNSigma      [0] ,h36_tofExpMom_tofNSigma      [1], h36_tofExpMom_tofNSigma      [3]
    );
    }
    // SetXYRange(h37_tpcNSigma_tofNSigma [0], 1, pLow, pUp, 0, pLow, pUp);
    // SetXYRange(h37_tpcNSigma_tofNSigma [1], 1, pLow, pUp, 0, pLow, pUp);
    // SetXYRange(h37_tpcNSigma_tofNSigma [3], 1, pLow, pUp, 0, pLow, pUp);

    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h37, h37_tpcNSigma_tofNSigma [0],h37_tpcNSigma_tofNSigma [1], h37_tpcNSigma_tofNSigma [3]);
}

template<typename I>
void executeV0loop(I inFiles){
  cout<<"INFO :: Print :: EnteringV0Loop :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  fillV0QA<v0TableFull>(inFiles);
  cout<<"INFO :: Print :: v0TableFull    :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;  

  if (cfgFillV0TablePostK0sCheck) {
    fillV0QA<v0TablePostK0sCheck>(inFiles);
    cout<<"INFO :: Print :: v0TablePostK0sCheck    :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  }
  if (cfgFillV0TablePostMassCut) {
    fillV0QA<v0TablePostMassCut>(inFiles);
    cout<<"INFO :: Print :: v0TablePostMassCut     :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  }
  if (cfgFillV0TablePostSelectionCut) {
    fillV0QA<v0TablePostSelectionCut>(inFiles);
    cout<<"INFO :: Print :: v0TablePostSelectionCut:: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  }
  auto hTrueV0TagCount = loadMergedHistogram(inFiles, PATH(HIST(MainDir[kMainDir])+HIST(HistRegDire[v0TablePostSelectionCut]) + HIST("hTrueV0TagCount"))); setObjStyle(hTrueV0TagCount, getMultiBit({hT,xT,yT}), {HIST(HistRegDire[v0TablePostSelectionCut])+"hTrueV0TagCount", "hTrueV0TagCount", "Counts"}); 
  CanvasSaver(hTrueV0TagCount, getMultiBit({yL}));
}

template<typename I>//, typename H>
void executeV0InCollisionloop(I inFile)
{
  cout<<"INFO :: Print :: Enter V0 in collision :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  fillV0QA<recoK0sPreSel >(inFile);
  cout<<"INFO :: Print :: recoK0sPreSel:: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  fillV0QA<recoK0sPostSel>(inFile);
  cout<<"INFO :: Print :: recoK0sPostSel:: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  // recoK0s.fill(HIST(HistRegDire[recoK0sPostSel]) + HIST("mK0s_vs_centFTOC"), centrality, v0.mK0Short()); // centrality dependent mass
}

template<typename I> 
void executeTrackQAPart(I inFile){
  cout<<"INFO :: Print :: Enter TrackQA    :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  fillTrackQA<recoTrackPreSel>(inFile);
  cout<<"INFO :: Print :: recoTrackPreSel  :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  fillTrackQA<recoTrackPostSel>(inFile);
  cout<<"INFO :: Print :: recoTrackPostSel :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
}

template<typename I>
void executeTrackAnalysisPart( I inFiles){
  cout<<"INFO :: Print :: Enter TrackAnalysis :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  TH1* h20_pt_eta[5][4];            
  TH1* h20_p_pt[5][4];            
  TH1* h21_p_tpcInnerParam[5][4]; 
  TH1* h22_p_tofExpMom[5][4];    
  TH1* h23_p_tpcSignal[5][4];             
  TH1* h24_tpcInnerParam_tpcSignal[5][4]; 
  TH1* h25_tofExpMom_tpcSignal[5][4];     
  TH1* h26_p_beta[5][4];            
  TH1* h27_tpcInnerParam_beta[5][4];
  TH1* h28_tofExpMom_beta[5][4];    
  TH1* h29_p_tpcNSigma[5][4];            
  TH1* h30_pt_tpcNSigma[5][4];           
  TH1* h31_tpcInnerParam_tpcNSigma[5][4];
  TH1* h32_tofExpMom_tpcNSigma[5][4];    
  TH1* h33_p_tofNSigma[5][4];            
  TH1* h34_pt_tofNSigma[5][4];           
  TH1* h35_tpcInnerParam_tofNSigma[5][4];
  TH1* h36_tofExpMom_tofNSigma[5][4];    
  TH1* h37_tpcNSigma_tofNSigma[5][4];

  // h20_p_pt                    [pidMode][detMode]
  // h21_p_tpcInnerParam         [pidMode][detMode]
  // h22_p_tofExpMom             [pidMode][detMode]
  // h23_p_tpcSignal             [pidMode][detMode]
  // h24_tpcInnerParam_tpcSignal [pidMode][detMode]
  // h25_tofExpMom_tpcSignal     [pidMode][detMode]
  // h26_p_beta                  [pidMode][detMode]
  // h27_tpcInnerParam_beta      [pidMode][detMode]
  // h28_tofExpMom_beta          [pidMode][detMode]
  // h29_p_tpcNSigma             [pidMode][detMode]
  // h30_pt_tpcNSigma            [pidMode][detMode]
  // h31_tpcInnerParam_tpcNSigma [pidMode][detMode]
  // h32_tofExpMom_tpcNSigma     [pidMode][detMode]
  // h33_p_tofNSigma             [pidMode][detMode]
  // h34_pt_tofNSigma            [pidMode][detMode]
  // h35_tpcInnerParam_tofNSigma [pidMode][detMode]
  // h36_tofExpMom_tofNSigma     [pidMode][detMode]
  // h37_tpcNSigma_tofNSigma     [pidMode][detMode]
  int pidMode = 0, detMode = 0;
  
  // pidMode = kPi; detMode = NoId ; fillIdentificationQA<recoAnalysisDir, kPi, NoId    , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kPi; detMode = tpcId   ; fillIdentificationQA<recoAnalysisDir, kPi, tpcId   , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kPi; detMode = tpctofId; fillIdentificationQA<recoAnalysisDir, kPi, tpctofId, true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  // pidMode = kKa; detMode = NoId ; fillIdentificationQA<recoAnalysisDir, kKa, NoId    , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kKa; detMode = tpcId   ; fillIdentificationQA<recoAnalysisDir, kKa, tpcId   , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kKa; detMode = tpctofId; fillIdentificationQA<recoAnalysisDir, kKa, tpctofId, true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  // pidMode = kPr; detMode = NoId ; fillIdentificationQA<recoAnalysisDir, kPr, NoId    , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kPr; detMode = tpcId   ; fillIdentificationQA<recoAnalysisDir, kPr, tpcId   , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kPr; detMode = tpctofId; fillIdentificationQA<recoAnalysisDir, kPr, tpctofId, true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  // pidMode = kEl; detMode = NoId ; fillIdentificationQA<recoAnalysisDir, kEl, NoId    , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kEl; detMode = tpcId   ; fillIdentificationQA<recoAnalysisDir, kEl, tpcId   , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kEl; detMode = tpctofId; fillIdentificationQA<recoAnalysisDir, kEl, tpctofId, true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  // pidMode = kDe; detMode = NoId ; fillIdentificationQA<recoAnalysisDir, kDe, NoId    , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kDe; detMode = tpcId   ; fillIdentificationQA<recoAnalysisDir, kDe, tpcId   , true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  pidMode = kDe; detMode = tpctofId; fillIdentificationQA<recoAnalysisDir, kDe, tpctofId, true>(inFiles, h20_pt_eta[pidMode][detMode], h20_p_pt[pidMode][detMode], h21_p_tpcInnerParam[pidMode][detMode], h22_p_tofExpMom[pidMode][detMode], h23_p_tpcSignal[pidMode][detMode], h24_tpcInnerParam_tpcSignal[pidMode][detMode], h25_tofExpMom_tpcSignal[pidMode][detMode], h26_p_beta[pidMode][detMode], h27_tpcInnerParam_beta[pidMode][detMode], h28_tofExpMom_beta[pidMode][detMode], h29_p_tpcNSigma[pidMode][detMode], h30_pt_tpcNSigma[pidMode][detMode], h31_tpcInnerParam_tpcNSigma[pidMode][detMode], h32_tofExpMom_tpcNSigma[pidMode][detMode], h33_p_tofNSigma[pidMode][detMode], h34_pt_tofNSigma[pidMode][detMode], h35_tpcInnerParam_tofNSigma[pidMode][detMode], h36_tofExpMom_tofNSigma[pidMode][detMode], h37_tpcNSigma_tofNSigma[pidMode][detMode]);
  // recoAnalysis.fill(HIST("recoAnalysis/SelectedTrack_IdentificationTag"), trackIdTag);

  int Mode = recoAnalysisDir;
  for(int pidMode = 0 ; pidMode < 5 ; pidMode++){
    cout<<"INFO :: Print :: Enter "<<PidDire[pidMode]<<" Analysis :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
    auto ps_h20a= HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh20_pt_eta"                  ; h20_pt_eta                  [pidMode][3] = AddTwoHistograms("sh20_pt_eta"                   , h20_pt_eta                  [pidMode][0], h20_pt_eta                  [pidMode][1]); setObjStyle(h20_pt_eta                  [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h20a,"p_{T} (GeV/c)"        , "#eta"           });
    auto ps_h20 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh20_p_pt"                    ; h20_p_pt                    [pidMode][3] = AddTwoHistograms("sh20_p_pt"                     , h20_p_pt                    [pidMode][0], h20_p_pt                    [pidMode][1]); setObjStyle(h20_p_pt                    [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h20, "p (GeV/c)"            , "p_{T} (GeV/c)"           });
    auto ps_h21 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh21_p_tpcInnerParam"         ; h21_p_tpcInnerParam         [pidMode][3] = AddTwoHistograms("sh21_p_tpcInnerParam"          , h21_p_tpcInnerParam         [pidMode][0], h21_p_tpcInnerParam         [pidMode][1]); setObjStyle(h21_p_tpcInnerParam         [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h21, "p (GeV/c)"            , "tpcInnerParam (GeV/c)"});
    auto ps_h22 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh22_p_tofExpMom"             ; h22_p_tofExpMom             [pidMode][3] = AddTwoHistograms("sh22_p_tofExpMom"              , h22_p_tofExpMom             [pidMode][0], h22_p_tofExpMom             [pidMode][1]); setObjStyle(h22_p_tofExpMom             [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h22, "p (GeV/c)"            , "tofExpMom (GeV/c)"    });
    auto ps_h23 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh23_p_tpcSignal"             ; h23_p_tpcSignal             [pidMode][3] = AddTwoHistograms("sh23_p_tpcSignal"              , h23_p_tpcSignal             [pidMode][0], h23_p_tpcSignal             [pidMode][1]); setObjStyle(h23_p_tpcSignal             [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h23, "p (GeV/c)"            , "-dE/dx (a.u)"});
    auto ps_h24 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh24_tpcInnerParam_tpcSignal" ; h24_tpcInnerParam_tpcSignal [pidMode][3] = AddTwoHistograms("sh24_tpcInnerParam_tpcSignal"  , h24_tpcInnerParam_tpcSignal [pidMode][0], h24_tpcInnerParam_tpcSignal [pidMode][1]); setObjStyle(h24_tpcInnerParam_tpcSignal [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h24, "tpcInnerParam (GeV/c)", "-dE/dx (a.u)"});
    auto ps_h25 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh25_tofExpMom_tpcSignal"     ; h25_tofExpMom_tpcSignal     [pidMode][3] = AddTwoHistograms("sh25_tofExpMom_tpcSignal"      , h25_tofExpMom_tpcSignal     [pidMode][0], h25_tofExpMom_tpcSignal     [pidMode][1]); setObjStyle(h25_tofExpMom_tpcSignal     [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h25, "tofExpMom (GeV/c)"    , "-dE/dx (a.u)"});
    auto ps_h26 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh26_p_beta"                  ; h26_p_beta                  [pidMode][3] = AddTwoHistograms("sh26_p_beta"                   , h26_p_beta                  [pidMode][0], h26_p_beta                  [pidMode][1]); setObjStyle(h26_p_beta                  [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h26, "p (GeV/c)"            , "beta"});
    auto ps_h27 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh27_tpcInnerParam_beta"      ; h27_tpcInnerParam_beta      [pidMode][3] = AddTwoHistograms("sh27_tpcInnerParam_beta"       , h27_tpcInnerParam_beta      [pidMode][0], h27_tpcInnerParam_beta      [pidMode][1]); setObjStyle(h27_tpcInnerParam_beta      [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h27, "tpcInnerParam (GeV/c)", "beta"});
    auto ps_h28 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh28_tofExpMom_beta"          ; h28_tofExpMom_beta          [pidMode][3] = AddTwoHistograms("sh28_tofExpMom_beta"           , h28_tofExpMom_beta          [pidMode][0], h28_tofExpMom_beta          [pidMode][1]); setObjStyle(h28_tofExpMom_beta          [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h28, "tofExpMom (GeV/c)"    , "beta"});
    auto ps_h29 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh29_p_tpcNSigma"             ; h29_p_tpcNSigma             [pidMode][3] = AddTwoHistograms("sh29_p_tpcNSigma"              , h29_p_tpcNSigma             [pidMode][0], h29_p_tpcNSigma             [pidMode][1]); setObjStyle(h29_p_tpcNSigma             [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h29, "p (GeV/c)"            , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    auto ps_h30 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh30_pt_tpcNSigma"            ; h30_pt_tpcNSigma            [pidMode][3] = AddTwoHistograms("sh30_pt_tpcNSigma"             , h30_pt_tpcNSigma            [pidMode][0], h30_pt_tpcNSigma            [pidMode][1]); setObjStyle(h30_pt_tpcNSigma            [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h30, "p_{T} (GeV/c)"           , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    auto ps_h31 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh31_tpcInnerParam_tpcNSigma" ; h31_tpcInnerParam_tpcNSigma [pidMode][3] = AddTwoHistograms("sh31_tpcInnerParam_tpcNSigma"  , h31_tpcInnerParam_tpcNSigma [pidMode][0], h31_tpcInnerParam_tpcNSigma [pidMode][1]); setObjStyle(h31_tpcInnerParam_tpcNSigma [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h31, "tpcInnerParam (GeV/c)", "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    auto ps_h32 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh32_tofExpMom_tpcNSigma"     ; h32_tofExpMom_tpcNSigma     [pidMode][3] = AddTwoHistograms("sh32_tofExpMom_tpcNSigma"      , h32_tofExpMom_tpcNSigma     [pidMode][0], h32_tofExpMom_tpcNSigma     [pidMode][1]); setObjStyle(h32_tofExpMom_tpcNSigma     [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h32, "tofExpMom (GeV/c)"    , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}"});
    auto ps_h33 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh33_p_tofNSigma"             ; h33_p_tofNSigma             [pidMode][3] = AddTwoHistograms("sh33_p_tofNSigma"              , h33_p_tofNSigma             [pidMode][0], h33_p_tofNSigma             [pidMode][1]); setObjStyle(h33_p_tofNSigma             [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h33, "p (GeV/c)"            , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    auto ps_h34 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh34_pt_tofNSigma"            ; h34_pt_tofNSigma            [pidMode][3] = AddTwoHistograms("sh34_pt_tofNSigma"             , h34_pt_tofNSigma            [pidMode][0], h34_pt_tofNSigma            [pidMode][1]); setObjStyle(h34_pt_tofNSigma            [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h34, "p_{T} (GeV/c)"           , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    auto ps_h35 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh35_tpcInnerParam_tofNSigma" ; h35_tpcInnerParam_tofNSigma [pidMode][3] = AddTwoHistograms("sh35_tpcInnerParam_tofNSigma"  , h35_tpcInnerParam_tofNSigma [pidMode][0], h35_tpcInnerParam_tofNSigma [pidMode][1]); setObjStyle(h35_tpcInnerParam_tofNSigma [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h35, "tpcInnerParam (GeV/c)", "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    auto ps_h36 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh36_tofExpMom_tofNSigma"     ; h36_tofExpMom_tofNSigma     [pidMode][3] = AddTwoHistograms("sh36_tofExpMom_tofNSigma"      , h36_tofExpMom_tofNSigma     [pidMode][0], h36_tofExpMom_tofNSigma     [pidMode][1]); setObjStyle(h36_tofExpMom_tofNSigma     [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h36, "tofExpMom (GeV/c)"    , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});
    auto ps_h37 = HIST(HistRegDire[Mode])+HIST(PidDire[pidMode]) +"sum/sh37_tpcNSigma_tofNSigma"     ; h37_tpcNSigma_tofNSigma     [pidMode][3] = AddTwoHistograms("sh37_tpcNSigma_tofNSigma"      , h37_tpcNSigma_tofNSigma     [pidMode][0], h37_tpcNSigma_tofNSigma     [pidMode][1]); setObjStyle(h37_tpcNSigma_tofNSigma     [pidMode][3], getMultiBit({hT,xT,yT}), {ps_h37, "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TPC}" , "n#sigma^{"+getModfiedStr(HIST(PidDire[pidMode]))+"}_{TOF}"});

    // SetXYRange(h29_p_tpcNSigma              [0],

    double pLow = 0.0, pUp = 3.0;          
    double tpcLow = -5.0 , tpcHigh = 5.0;
    double tofLow = -5.0 , tofHigh = 5.0;

    SetXYRange(h20_p_pt                     [pidMode][3], 1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h21_p_tpcInnerParam          [pidMode][3], 1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h22_p_tofExpMom              [pidMode][3], 1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h23_p_tpcSignal              [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h24_tpcInnerParam_tpcSignal  [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h25_tofExpMom_tpcSignal      [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h26_p_beta                   [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h27_tpcInnerParam_beta       [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h28_tofExpMom_beta           [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h29_p_tpcNSigma              [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h30_pt_tpcNSigma             [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h31_tpcInnerParam_tpcNSigma  [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h32_tofExpMom_tpcNSigma      [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h33_p_tofNSigma              [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h34_pt_tofNSigma             [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h35_tpcInnerParam_tofNSigma  [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h36_tofExpMom_tofNSigma      [pidMode][3], 1, pLow, pUp, 1, tpcLow, tpcHigh);
    SetXYRange(h37_tpcNSigma_tofNSigma      [pidMode][3], 1, tpcLow, tpcHigh, 1, tpcLow, tpcHigh);

    if(DrawSwitch){
      CanvasSaver(h20_p_pt                     [pidMode][3], HIST(MainDir[kMainDir])+ps_h20, getMultiBit({zL,colz}));
      CanvasSaver(h21_p_tpcInnerParam          [pidMode][3], HIST(MainDir[kMainDir])+ps_h21, getMultiBit({zL,colz}));
      CanvasSaver(h22_p_tofExpMom              [pidMode][3], HIST(MainDir[kMainDir])+ps_h22, getMultiBit({zL,colz}));
      CanvasSaver(h23_p_tpcSignal              [pidMode][3], HIST(MainDir[kMainDir])+ps_h23, getMultiBit({zL,colz}));
      CanvasSaver(h24_tpcInnerParam_tpcSignal  [pidMode][3], HIST(MainDir[kMainDir])+ps_h24, getMultiBit({zL,colz}));
      CanvasSaver(h25_tofExpMom_tpcSignal      [pidMode][3], HIST(MainDir[kMainDir])+ps_h25, getMultiBit({zL,colz}));
      CanvasSaver(h26_p_beta                   [pidMode][3], HIST(MainDir[kMainDir])+ps_h26, getMultiBit({zL,colz}));
      CanvasSaver(h27_tpcInnerParam_beta       [pidMode][3], HIST(MainDir[kMainDir])+ps_h27, getMultiBit({zL,colz}));
      CanvasSaver(h28_tofExpMom_beta           [pidMode][3], HIST(MainDir[kMainDir])+ps_h28, getMultiBit({zL,colz}));
      CanvasSaver(h29_p_tpcNSigma              [pidMode][3], HIST(MainDir[kMainDir])+ps_h29, getMultiBit({zL,colz}));
      CanvasSaver(h30_pt_tpcNSigma             [pidMode][3], HIST(MainDir[kMainDir])+ps_h30, getMultiBit({zL,colz}));
      CanvasSaver(h31_tpcInnerParam_tpcNSigma  [pidMode][3], HIST(MainDir[kMainDir])+ps_h31, getMultiBit({zL,colz}));
      CanvasSaver(h32_tofExpMom_tpcNSigma      [pidMode][3], HIST(MainDir[kMainDir])+ps_h32, getMultiBit({zL,colz}));
      CanvasSaver(h33_p_tofNSigma              [pidMode][3], HIST(MainDir[kMainDir])+ps_h33, getMultiBit({zL,colz}));
      CanvasSaver(h34_pt_tofNSigma             [pidMode][3], HIST(MainDir[kMainDir])+ps_h34, getMultiBit({zL,colz}));
      CanvasSaver(h35_tpcInnerParam_tofNSigma  [pidMode][3], HIST(MainDir[kMainDir])+ps_h35, getMultiBit({zL,colz}));
      CanvasSaver(h36_tofExpMom_tofNSigma      [pidMode][3], HIST(MainDir[kMainDir])+ps_h36, getMultiBit({zL,colz}));
      CanvasSaver(h37_tpcNSigma_tofNSigma      [pidMode][3], HIST(MainDir[kMainDir])+ps_h37, getMultiBit({zL,colz}));    
      }
  
    pLow = 0.0, pUp = 4.0;      
    //Momentum
    SetXYRange(h20_p_pt            [pidMode][0] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h21_p_tpcInnerParam [pidMode][0] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h22_p_tofExpMom     [pidMode][0] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h20_p_pt            [pidMode][1] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h21_p_tpcInnerParam [pidMode][1] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h22_p_tofExpMom     [pidMode][1] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h20_p_pt            [pidMode][3] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h21_p_tpcInnerParam [pidMode][3] ,1, pLow, pUp, 1, pLow, pUp);
    SetXYRange(h22_p_tofExpMom     [pidMode][3] ,1, pLow, pUp, 1, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots( HIST(MainDir[kMainDir])+ps_h20, h20_p_pt            [pidMode][0],h20_p_pt            [pidMode][1],h20_p_pt            [pidMode][3]
                   ,h21_p_tpcInnerParam [pidMode][0],h21_p_tpcInnerParam [pidMode][1],h21_p_tpcInnerParam [pidMode][3]);
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h22, h22_p_tofExpMom     [pidMode][0],h22_p_tofExpMom     [pidMode][1],h22_p_tofExpMom     [pidMode][3]);
    }
    // //Momenturm
    // //tpcSignal
    SetXYRange(h23_p_tpcSignal             [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h24_tpcInnerParam_tpcSignal [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h25_tofExpMom_tpcSignal     [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h23_p_tpcSignal             [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h24_tpcInnerParam_tpcSignal [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h25_tofExpMom_tpcSignal     [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h23_p_tpcSignal             [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h24_tpcInnerParam_tpcSignal [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h25_tofExpMom_tpcSignal     [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h23, h23_p_tpcSignal             [pidMode][0], h23_p_tpcSignal             [pidMode][1], h23_p_tpcSignal             [pidMode][3]
                   ,h24_tpcInnerParam_tpcSignal [pidMode][0], h24_tpcInnerParam_tpcSignal [pidMode][1], h24_tpcInnerParam_tpcSignal [pidMode][3]);
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h25, h25_tofExpMom_tpcSignal     [pidMode][0], h25_tofExpMom_tpcSignal     [pidMode][1], h25_tofExpMom_tpcSignal     [pidMode][3]);
    }
    // //tpcSignal
    // //tofBeta
    SetXYRange(h26_p_beta              [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h27_tpcInnerParam_beta  [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h28_tofExpMom_beta      [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h26_p_beta              [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h27_tpcInnerParam_beta  [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h28_tofExpMom_beta      [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h26_p_beta              [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h27_tpcInnerParam_beta  [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h28_tofExpMom_beta      [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h26, h26_p_beta             [pidMode][0], h26_p_beta             [pidMode][1], h26_p_beta             [pidMode][3]
                   ,h27_tpcInnerParam_beta [pidMode][0], h27_tpcInnerParam_beta [pidMode][1], h27_tpcInnerParam_beta [pidMode][3]);
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h28, h28_tofExpMom_beta     [pidMode][0], h28_tofExpMom_beta     [pidMode][1], h28_tofExpMom_beta     [pidMode][3]);
    }
    //tofBeta
    //Look at Pion
    SetXYRange(h29_p_tpcNSigma             [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h30_pt_tpcNSigma            [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h31_tpcInnerParam_tpcNSigma [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h32_tofExpMom_tpcNSigma     [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h29_p_tpcNSigma             [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h30_pt_tpcNSigma            [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h31_tpcInnerParam_tpcNSigma [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h32_tofExpMom_tpcNSigma     [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);

    SetXYRange(h29_p_tpcNSigma             [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h30_pt_tpcNSigma            [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h31_tpcInnerParam_tpcNSigma [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h32_tofExpMom_tpcNSigma     [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h29,
       h29_p_tpcNSigma              [pidMode][0] ,h29_p_tpcNSigma              [pidMode][1], h29_p_tpcNSigma              [pidMode][3]
      // ,h30_pt_tpcNSigma             [pidMode][0] ,h30_pt_tpcNSigma             [pidMode][1], h30_pt_tpcNSigma             [pidMode][3]
      ,h31_tpcInnerParam_tpcNSigma  [pidMode][0] ,h31_tpcInnerParam_tpcNSigma  [pidMode][1], h31_tpcInnerParam_tpcNSigma  [pidMode][3]
      // ,h32_tofExpMom_tpcNSigma      [pidMode][0] ,h32_tofExpMom_tpcNSigma      [pidMode][1], h32_tofExpMom_tpcNSigma      [pidMode][3]
    );
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h32,
      // h29_p_tpcNSigma              [pidMode][0] ,h29_p_tpcNSigma              [pidMode][1], h29_p_tpcNSigma              [pidMode][3]
      // ,h30_pt_tpcNSigma            [pidMode] [0] ,h30_pt_tpcNSigma            [pidMode] [1], h30_pt_tpcNSigma            [pidMode] [3]
      // ,h31_tpcInnerParam_tpcNSigma [pidMode] [0] ,h31_tpcInnerParam_tpcNSigma [pidMode] [1], h31_tpcInnerParam_tpcNSigma [pidMode] [3]
      h32_tofExpMom_tpcNSigma      [pidMode][0] ,h32_tofExpMom_tpcNSigma      [pidMode][1], h32_tofExpMom_tpcNSigma      [pidMode][3]
    );
     }
    //
    SetXYRange(h33_p_tofNSigma              [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h34_pt_tofNSigma             [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h35_tpcInnerParam_tofNSigma  [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h36_tofExpMom_tofNSigma      [pidMode][0], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h33_p_tofNSigma              [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h34_pt_tofNSigma             [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h35_tpcInnerParam_tofNSigma  [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h36_tofExpMom_tofNSigma      [pidMode][1], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h33_p_tofNSigma              [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h34_pt_tofNSigma             [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h35_tpcInnerParam_tofNSigma  [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);
    SetXYRange(h36_tofExpMom_tofNSigma      [pidMode][3], 1, pLow, pUp, 0, pLow, pUp);

    if(DrawSwitch){
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h33,
      h33_p_tofNSigma              [pidMode][0] ,h33_p_tofNSigma              [pidMode][1], h33_p_tofNSigma              [pidMode][3]
      // ,h34_pt_tofNSigma             [pidMode][0] ,h34_pt_tofNSigma             [pidMode][1], h34_pt_tofNSigma             [pidMode][3]
      ,h35_tpcInnerParam_tofNSigma  [pidMode][0] ,h35_tpcInnerParam_tofNSigma  [pidMode][1], h35_tpcInnerParam_tofNSigma  [pidMode][3]
      // ,h36_tofExpMom_tofNSigma      [pidMode][0] ,h36_tofExpMom_tofNSigma      [pidMode][1], h36_tofExpMom_tofNSigma      [pidMode][3]
    );
    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h36,
      // ,h33_p_tofNSigma              [pidMode][0] ,h33_p_tofNSigma              [pidMode][1], h33_p_tofNSigma              [pidMode][3]
      // ,h34_pt_tofNSigma             [pidMode][0] ,h34_pt_tofNSigma             [pidMode][1], h34_pt_tofNSigma             [pidMode][3]
      // ,h35_tpcInnerParam_tofNSigma  [pidMode][0] ,h35_tpcInnerParam_tofNSigma  [pidMode][1], h35_tpcInnerParam_tofNSigma  [pidMode][3]
      h36_tofExpMom_tofNSigma      [pidMode][0] ,h36_tofExpMom_tofNSigma      [pidMode][1], h36_tofExpMom_tofNSigma      [pidMode][3]
    );
    }
    // SetXYRange(h37_tpcNSigma_tofNSigma [0], 1, pLow, pUp, 0, pLow, pUp);
    // SetXYRange(h37_tpcNSigma_tofNSigma [1], 1, pLow, pUp, 0, pLow, pUp);
    // SetXYRange(h37_tpcNSigma_tofNSigma [3], 1, pLow, pUp, 0, pLow, pUp);

    DrawSix2DPlots(HIST(MainDir[kMainDir])+ps_h37, h37_tpcNSigma_tofNSigma [pidMode][0],h37_tpcNSigma_tofNSigma [pidMode][1], h37_tpcNSigma_tofNSigma [pidMode][3]);
    cout<<"INFO :: Print :: Exit  "<<PidDire[pidMode]<<" Analysis :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl<<endl;
  }
  cout<<"INFO :: Print :: Exit TrackAnalysis :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
}
//________________________________________________ Sparse Analysis Function ___________________________________________________________
template<typename T, typename G>
void SparseAnalysis(const T& hSparseList, const int& nClass, const std::vector<double>& classLow,const std::vector<double>& classUp,
  const int &nSmallClass, const std::vector<double>& smallClassLow, const std::vector<double>& smallClassUp, const std::vector<int>& nClassIDX_smallClass,
  const int &axisCl, const int& pairType, const int& axisA0, const int & axisA1, const int& axisB0, const int& axisB1,
  std::vector<double>& Rab, std::vector<double>& Raa, std::vector<double>& Rbb, std::vector<double>& NDy,
  G &grRab, G &grRaa, G &grRbb, G &grNDy,
  std::vector<double>& Rab_CBWC, std::vector<double>& Raa_CBWC, std::vector<double>& Rbb_CBWC, std::vector<double>& NDy_CBWC,
  G &grRab_CBWC, G &grRaa_CBWC, G &grRbb_CBWC, G &grNDy_CBWC, const std::string& pathString)
{
  cout<<endl<<"//____________________Entering Sparse Analysis___________________________"<<endl;
  cout<<"HistList.size() = "<<hSparseList.size()<<endl;
  cout<<"Printing Class Edges :: nClass = "<<nClass<<endl;
  for(int i=0 ; i < nClass ; i++){
    cout<<"i = "<<std::setw(3)<<i<<" :: "<<"["<<std::setw(5)<<classLow[i]<<","<<std::setw(5)<<classUp[i]<<"] "<<endl;
  }

  cout<<"Printing Small Class Edges :: nSmallClass = "<<nSmallClass<<endl;
  for(int i=0 ; i < nSmallClass ; i++){
    cout<<"i = "<<std::setw(3)<<i<<" :: "<<"["<<std::setw(5)<<smallClassLow[i]<<","<<std::setw(5)<<smallClassUp[i]<<"] :: nClassIDX = "<<nClassIDX_smallClass[i]<<endl;
  }

  int BinCountCheck= 200000*10;
  const int nDim = hSparseList[0]->GetNdimensions();
  int THnBinValue[nDim];
  double Xvar[nDim];

  //Debugging Part //Get all 1D hist definitions so that you can match and debug what you have filled
  vector<TH1D*> h1D(nDim, nullptr);
  vector<vector<TH1D*>> h1D_nClass(nDim, vector<TH1D*>(nClass, nullptr));

  for(int iAxis = 0 ; iAxis < nDim ; iAxis++){
    h1D[iAxis] = get1DBlankHistFromSparse(hSparseList[0],iAxis);
    for (int iClass = 0; iClass < nClass; iClass++) {
      h1D_nClass[iAxis][iClass] = GetClonedHist(h1D[iAxis], Form("nClass_%d",iClass), Form(":: centFT0C[%2.0f,%2.0f]",classLow[iClass], classUp[iClass]));
    }
  }
  
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

  // 2 represents square in the following
  //Error Analysis Part
  vector<vector<double>> nEntries_nSubSample(nSubSample, vector<double>(nClass));
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

  //_______________MBWC part______________________________________________________________________________
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

  //_______________________ Entries Per Subsample____________________________________________________
  //Find Entries Per SubSample
  int64_t totalSubSampleEntries = 0 ; 
  int64_t EntriesPerSubSample = FindEntriesPerSubSample(hSparseList, nSubSample, totalSubSampleEntries);
  int64_t SubSampleEntryCounter[nSubSample]; int iSubSample = -1;
  for (int i = 0 ; i < nSubSample; i++){ SubSampleEntryCounter[i] = 0;}

  TRandom3 randomGenerator(seed);

  //Now looping over the bins
  auto Start1 = chrono::high_resolution_clock::now();
  auto Start2 = chrono::high_resolution_clock::now();
  
  int classNumber = -1;
  int smallClassNumber = -1;
  long int countFillCheck = 0;

  const int nHist = hSparseList.size();
  cout<<"nHist = "<<nHist<<endl;
  for(int iHist = 0 ; iHist < nHist ; iHist++){
    cout<<"iHist = "<<iHist<<endl;
    auto hSparse = hSparseList[iHist];
    int64_t nBinsSparse = hSparse->GetNbins();
    int64_t iBinEntries = 0;
    cout<<"iHist = "<<iHist<<" :: nBinsSparse :: "<<nBinsSparse<<endl;
    for(int iBin = 0 ; iBin < nBinsSparse ; iBin++){
      if(iBin % BinCountCheck == 0){
        cout<<endl;
        PrintTime(Start2, Form("    %d :: %s :: BinReading :: BinTime     :: iBin = %d :: ",iHist,hSparse->GetName(),iBin));
        PrintTime(Start1, Form("    %d :: %s :: BinReading :: ElapsedTime :: iBin = %d :: ",iHist,hSparse->GetName(),iBin));
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
        //The Variable is integer
        if(classLow[iClass] <= static_cast<int>(Xvar[axisCl]) && static_cast<int>(Xvar[axisCl]) <= classUp[iClass]){
          classNumber = iClass;
          break;
        }
      }//classloop block

      if(classNumber == -1) {
        cout<<"ERROR :: classNumber = -1 :: "<<Xvar[axisCl]<<endl;
      }

      smallClassNumber = -1;
      for(int iSmallClass = 0 ; iSmallClass < nSmallClass; iSmallClass++){
        if(smallClassLow[iSmallClass] <= static_cast<int>(Xvar[axisCl]) && static_cast<int>(Xvar[axisCl]) <= smallClassUp[iSmallClass]){
          smallClassNumber = iSmallClass;
          break;
        }
      }//classloop block

      if(smallClassNumber == -1) {
        cout<<"ERROR :: smallClassNumber = -1 :: "<<Xvar[axisCl]<<endl;
      }

      if( nClassIDX_smallClass[smallClassNumber] != classNumber){
        cout<<"ERROR :: nClassIDX_smallClass[smallClassNumber] != classNumber :: "<<endl;
      }

      Sum_Na[classNumber]   += iBinEntries*Na;
      Sum_Na2[classNumber]  += iBinEntries*Na*Na;
      Sum_Nb[classNumber]   += iBinEntries*Nb;
      Sum_Nb2[classNumber]  += iBinEntries*Nb*Nb;
      Sum_NaNb[classNumber] += iBinEntries*Na*Nb;
      nEntries[classNumber] += iBinEntries;
  
      Sum_NaCorr[classNumber] += iBinEntries*(Na*(Na-1));
      Sum_NbCorr[classNumber] += iBinEntries*(Nb*(Nb-1));

      //____________Small Class Analysis For CBWC__________________________________
      Sum_Na_nSmallClass[smallClassNumber]    += iBinEntries*Na;
      Sum_Na2_nSmallClass[smallClassNumber]   += iBinEntries*Na*Na;
      Sum_Nb_nSmallClass[smallClassNumber]    += iBinEntries*Nb;
      Sum_Nb2_nSmallClass[smallClassNumber]   += iBinEntries*Nb*Nb;
      Sum_NaNb_nSmallClass[smallClassNumber]  += iBinEntries*Na*Nb;
      nEntries_nSmallClass[smallClassNumber]  += iBinEntries;
  
      Sum_NaCorr_nSmallClass[smallClassNumber] += iBinEntries*(Na*(Na-1));
      Sum_NbCorr_nSmallClass[smallClassNumber] += iBinEntries*(Nb*(Nb-1));

      //____________Subsample Analysis__________________________________
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
      } //Bin Entries Loop ends
      //___________________Debug Histogram______________
      //Histogram filling consumes a lot of time 
      for(int iAxis = 0 ; iAxis < nDim ; iAxis++){
        h1D[iAxis]                     ->Fill(Xvar[iAxis], iBinEntries);
        h1D_nClass[iAxis][classNumber] ->Fill(Xvar[iAxis], iBinEntries);
      }
    } //Bin loop ends
    // delete hSparse; //don't delete, in a list the pointer gets deleted and code will crash
  } //Histogram Loop ends

  //debugging steps -> make sure to check to avoid unpredicted errors
  checkClassificationHist(h1D_nClass, axisCl, nClass);
  checkSubSampleEntries(nEntries_nSubSample, EntriesPerSubSample, totalSubSampleEntries);

  vector<vector<double>> Raa_nSubSample(nSubSample, vector<double>(nClass));
  vector<vector<double>> Rbb_nSubSample(nSubSample, vector<double>(nClass));
  vector<vector<double>> Rab_nSubSample(nSubSample, vector<double>(nClass));
  vector<vector<double>> NDy_nSubSample(nSubSample, vector<double>(nClass));

  //Calculation of Raa, Rbb, Rab & NDy
  int64_t totalEnt_nClass = 0;
  int64_t totalEnt_nSubsample = 0;
  for (int iClass=0; iClass<nClass; iClass++){
    totalEnt_nClass += nEntries[iClass];
    // cout<<"iClass = "<<iClass<<" :: "<<nEntries[iClass]<<endl;
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
      totalEnt_nSubsample += nEntries_nSubSample[iSubSample][iClass];
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
    //   <<iClass<<" :: Raa["<<iClass<<"] = "<<Raa[iClass]<<" :: CorrValues "<<Raa_Corr[iClass]<<" :: diff = "<<Raa[iClass]-Raa_Corr[iClass]<<endl
    //   <<iClass<<" :: Rbb["<<iClass<<"] = "<<Rbb[iClass]<<" :: CorrValues "<<Rbb_Corr[iClass]<<" :: diff = "<<Rbb[iClass]-Rbb_Corr[iClass]<<endl
    //   <<iClass<<" :: Rab["<<iClass<<"] = "<<Rab[iClass]<<" :: CorrValues "<<Rab_Corr[iClass]<<" :: diff = "<<Rab[iClass]-Rab_Corr[iClass]<<endl
    //   <<iClass<<" :: NDy["<<iClass<<"] = "<<NDy[iClass]<<endl
    // ;

    //It is a peculiar case with double, you divide but the division is non termnating and it fails in the precesion, the values will mismatch but the difference will be very small
    if( Sum_NaCorr[iClass]  - ( Sum_Na2[iClass] - Sum_Na[iClass] ) >= 1e-8) { cout<<"ERROR in sum calculation  :: "<<iClass<<" :: "<<Sum_NaCorr[iClass] <<" :: "<<Sum_Na2[iClass] <<" :: "<<Sum_Na[iClass] <<endl;}
    if( mean_NaCorr[iClass] - ( mean_Na2[iClass]- mean_Na[iClass]) >= 1e-8) { cout<<"ERROR in mean calculation :: "<<iClass<<" :: "<<mean_NaCorr[iClass]<<" :: "<<mean_Na2[iClass]<<" :: "<<mean_Na[iClass]<<endl;}
    if(Raa[iClass] - Raa_Corr[iClass] >= 1e-8) { cout<<"ERROR :: iClass = "<<iClass<<" :: "<<Raa[iClass]<<" != "<<Raa_Corr[iClass]<<endl;}
    if(Rbb[iClass] - Rbb_Corr[iClass] >= 1e-8) { cout<<"ERROR :: iClass = "<<iClass<<" :: "<<Rbb[iClass]<<" != "<<Rbb_Corr[iClass]<<endl;}
    if(Rab[iClass] - Rab_Corr[iClass] >= 1e-8) { cout<<"ERROR :: iClass = "<<iClass<<" :: "<<Rab[iClass]<<" != "<<Rab_Corr[iClass]<<endl;}
  }
  if( totalEnt_nClass     != totalSubSampleEntries) {cout<<"ERROR :: ERROR in counting :: totalEnt_nClass     != totalSubSampleEntries"<<endl;}
  if( totalEnt_nSubsample != totalSubSampleEntries) {cout<<"ERROR :: ERROR in counting :: totalEnt_nSubsample != totalSubSampleEntries"<<endl;}

  vector<double> Raa_nSmallClass(nSmallClass);
  vector<double> Rbb_nSmallClass(nSmallClass);
  vector<double> Rab_nSmallClass(nSmallClass);
  vector<double> NDy_nSmallClass(nSmallClass);

  //CBWC values
  //Calculation of Raa, Rbb, Rab & NDy
  for (int iSmallClass=0; iSmallClass<nSmallClass; iSmallClass++){
    // cout<<"iSmallClass = "<<iSmallClass<<" :: "<<nEntries_nSmallClass[iSmallClass]<<endl;
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

  vector<double> sumForCBWC_Raa_nClass(nClass);
  vector<double> sumForCBWC_Rbb_nClass(nClass);
  vector<double> sumForCBWC_Rab_nClass(nClass);
  vector<double> sumForCBWC_NDy_nClass(nClass);

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
            // cout<<"iSmallClass = "<<iSmallClass <<" ERROR NO BIN "<<endl;
          }
      }
    }//smallClass loop is over
    Raa_CBWC[iClass] = sumForCBWC_Raa_nClass[iClass]/countSum;
    Rbb_CBWC[iClass] = sumForCBWC_Rbb_nClass[iClass]/countSum;
    Rab_CBWC[iClass] = sumForCBWC_Rab_nClass[iClass]/countSum;
    NDy_CBWC[iClass] = sumForCBWC_NDy_nClass[iClass]/countSum;
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

  SetXYRange(h1D[0],1,-1.0,200, 0, 0.0,0.0);
  SetXYRange(h1D[1],1,-1.5,150.5, 0, 0.0,0.0);
  SetXYRange(h1D[2],1,-1.5, 20.5, 0, 0.0,0.0);
  SetXYRange(h1D[3],1,-1.5, 10.5, 0, 0.0,0.0);
  SetXYRange(h1D[4],1,-1.5, 10.5, 0, 0.0,0.0);
  SetXYRange(h1D[5],1,-1.5,100.5, 0, 0.0,0.0);
  SetXYRange(h1D[6],1,-1.5,100.5, 0, 0.0,0.0);
  SetXYRange(h1D[7],1,-1.5, 40.5, 0, 0.0,0.0);
  SetXYRange(h1D[8],1,-1.5, 40.5, 0, 0.0,0.0);

  for (classNumber=0; classNumber<nClass; classNumber++){
    double x0Low = h1D_nClass[0][classNumber]->GetBinLowEdge(getFirstFilledBin(h1D_nClass[0][classNumber])) -3.0*h1D_nClass[0][classNumber]->GetBinWidth(getFirstFilledBin(h1D_nClass[0][classNumber]));;  //
    double x0Up  = h1D_nClass[0][classNumber]->GetBinLowEdge(getLastFilledBin (h1D_nClass[0][classNumber])) +3.0*h1D_nClass[0][classNumber]->GetBinWidth(getLastFilledBin (h1D_nClass[0][classNumber]));;  //
    SetXYRange(h1D_nClass[0][classNumber],1,x0Low,x0Up, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[1][classNumber],1,-1.5,150.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[2][classNumber],1,-1.5, 20.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[3][classNumber],1,-1.5, 10.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[4][classNumber],1,-1.5, 10.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[5][classNumber],1,-1.5,100.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[6][classNumber],1,-1.5,100.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[7][classNumber],1,-1.5, 40.5, 0, 0.0,0.0);
    SetXYRange(h1D_nClass[8][classNumber],1,-1.5, 40.5, 0, 0.0,0.0);
  }

  // if(DrawHistograms == 1){
    for(int iAxis = 0 ; iAxis < nDim ; iAxis++){
      // setObjStyle(h1D[iAxis] , getMultiBit({hT,xT,yT}), {HIST(hSparse->GetName())+h1D[iAxis]->GetXaxis()->GetTitle(), hist->GetXaxis()->GetTitle(), "Counts"});
      // CanvasSaver(h1D[iAxis] , getMultiBit({yL, hist}));
        if(nClass > 0){ DrawSix1DLogPlots(pathString, h1D_nClass[iAxis][0], h1D_nClass[iAxis][1], h1D_nClass[iAxis][2], h1D_nClass[iAxis][3], h1D_nClass[iAxis][4]);}
        if(nClass > 5){ DrawSix1DLogPlots(pathString, h1D_nClass[iAxis][5], h1D_nClass[iAxis][6], h1D_nClass[iAxis][7], h1D_nClass[iAxis][8], h1D_nClass[iAxis][9]);}
    }
  // }

    double x[nClass] ;
    x[0] = 10;
    x[1] = 30;
    x[2] = 50;
    x[3] = 70;
    x[4] = 90;

    x[0] = 90;
    x[1] = 70;
    x[2] = 50;
    x[3] = 30;
    x[4] = 10;

    // for(int ii = 0 ; ii< nClass; ii++){
    //   cout<<"x["<<ii<<"] = "<<x[ii]<<endl;
    // }

    Double_t ex[nClass];
    ex[0] = 10; 
    ex[1] = 10;
    ex[2] = 10;
    ex[3] = 10;
    ex[4] = 10;

    vector<double> Raa_SubSampling_Mean(nClass); vector<double> Raa_SubSampling_Sigma(nClass);
    vector<double> Rbb_SubSampling_Mean(nClass); vector<double> Rbb_SubSampling_Sigma(nClass);
    vector<double> Rab_SubSampling_Mean(nClass); vector<double> Rab_SubSampling_Sigma(nClass);
    vector<double> NDy_SubSampling_Mean(nClass); vector<double> NDy_SubSampling_Sigma(nClass);

    GetMeanAndErrorFromSubSampling(Raa_nSubSample, Raa_SubSampling_Mean, Raa_SubSampling_Sigma);
    GetMeanAndErrorFromSubSampling(Rbb_nSubSample, Rbb_SubSampling_Mean, Rbb_SubSampling_Sigma);
    GetMeanAndErrorFromSubSampling(Rab_nSubSample, Rab_SubSampling_Mean, Rab_SubSampling_Sigma);
    GetMeanAndErrorFromSubSampling(NDy_nSubSample, NDy_SubSampling_Mean, NDy_SubSampling_Sigma);

    // for(int iClass = 0 ; iClass < nClass ; iClass++){ cout<<"iClassS = "<<iClass<<" :: "<<NDy_SubSampling_Sigma[iClass]<<endl;}
    // for(int iClass = 0 ; iClass < nClass ; iClass++){ cout<<"iClassM = "<<iClass<<" :: "<<NDy_SubSampling_Mean[iClass]<<endl;}

    //Get Statistical Error from the data//

    grRab = new TGraphErrors(nClass,x,&Rab[0],ex, Rab_SubSampling_Sigma.data());grRab->SetMarkerStyle(kOpenSquare    );grRab->SetMarkerColor(kBlack);grRab->SetLineColor(kBlack); grRab->SetLineStyle(1);grRab->SetLineWidth(1);grRab->SetMarkerSize(1.3);
    grRaa = new TGraphErrors(nClass,x,&Raa[0],ex, Raa_SubSampling_Sigma.data());grRaa->SetMarkerStyle(kOpenTriangleUp);grRaa->SetMarkerColor(kBlue );grRaa->SetLineColor(kBlue ); grRaa->SetLineStyle(2);grRaa->SetLineWidth(1);grRaa->SetMarkerSize(1.3);
    grRbb = new TGraphErrors(nClass,x,&Rbb[0],ex, Rbb_SubSampling_Sigma.data());grRbb->SetMarkerStyle(kOpenCircle    );grRbb->SetMarkerColor(kRed  );grRbb->SetLineColor(kRed  ); grRbb->SetLineStyle(5);grRbb->SetLineWidth(1);grRbb->SetMarkerSize(1.3);
    grNDy = new TGraphErrors(nClass,x,&NDy[0],ex, NDy_SubSampling_Sigma.data());grNDy->SetMarkerStyle(kOpenSquare    );grNDy->SetMarkerColor(kBlack);grNDy->SetLineColor(kBlack); grNDy->SetLineStyle(1);grNDy->SetLineWidth(1);grNDy->SetMarkerSize(1.3);

    grRab_CBWC = new TGraphErrors(nClass,x,&Rab_CBWC[0],ex, Rab_SubSampling_Sigma.data());grRab_CBWC->SetMarkerStyle(kOpenSquare    );grRab_CBWC->SetMarkerColor(kBlack);grRab_CBWC->SetLineColor(kBlack); grRab_CBWC->SetLineStyle(1);grRab_CBWC->SetLineWidth(1);grRab_CBWC->SetMarkerSize(1.3);
    grRaa_CBWC = new TGraphErrors(nClass,x,&Raa_CBWC[0],ex, Raa_SubSampling_Sigma.data());grRaa_CBWC->SetMarkerStyle(kOpenTriangleUp);grRaa_CBWC->SetMarkerColor(kBlue );grRaa_CBWC->SetLineColor(kBlue ); grRaa_CBWC->SetLineStyle(2);grRaa_CBWC->SetLineWidth(1);grRaa_CBWC->SetMarkerSize(1.3);
    grRbb_CBWC = new TGraphErrors(nClass,x,&Rbb_CBWC[0],ex, Rbb_SubSampling_Sigma.data());grRbb_CBWC->SetMarkerStyle(kOpenCircle    );grRbb_CBWC->SetMarkerColor(kRed  );grRbb_CBWC->SetLineColor(kRed  ); grRbb_CBWC->SetLineStyle(5);grRbb_CBWC->SetLineWidth(1);grRbb_CBWC->SetMarkerSize(1.3);
    grNDy_CBWC = new TGraphErrors(nClass,x,&NDy_CBWC[0],ex, NDy_SubSampling_Sigma.data());grNDy_CBWC->SetMarkerStyle(kOpenSquare    );grNDy_CBWC->SetMarkerColor(kBlack);grNDy_CBWC->SetLineColor(kBlack); grNDy_CBWC->SetLineStyle(1);grNDy_CBWC->SetLineWidth(1);grNDy_CBWC->SetMarkerSize(1.3);
/*
*/
  }

template<typename I>
void executeSparseAnalysisPart(const I &inFiles,  const int& nClass, std::vector<double> classLow, std::vector<double> classUp ){
  cout<<"INFO :: Print :: Enter Sparse Analysis :: gCanvasNo = "<<gCanvasNo<<" :: gCounterNo = "<<gCounterNo<<endl;
  std::vector<double>  LegLeftTop     = {0.11, 0.77, 0.47, 0.89};
  std::vector<double>  LegLeftBottom  = {0.11, 0.13, 0.47, 0.25};
  std::vector<double>  LegRightTop    = {0.53, 0.77, 0.89, 0.89};
  std::vector<double>  LegRightBottom = {0.53, 0.13, 0.89, 0.25};
  std::vector<double>  LegMidTop      = {0.29, 0.66, 0.65, 0.78};

  vector<THnSparseD*> Sparse_Full_K0sPiKa(inFiles.size(), nullptr);
  loadSparseHistograms(Sparse_Full_K0sPiKa, inFiles, HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa", 1);

  PrintAllAxisOfSparse(Sparse_Full_K0sPiKa[0]);

  get1DdistributionOfAllAxis(Sparse_Full_K0sPiKa, HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/");
 
  //_____________Obtaining Quantiles for Processing__________________________________
  TH1D* histAxis = get1DMergedAxis(Sparse_Full_K0sPiKa, 0);
  histAxis->SetName("MultV0M");
  histAxis->SetTitle("MultV0M");
  histAxis->GetXaxis()->SetTitle("MultV0M");
  // TCanvas *c = new TCanvas();
  // c->SetLogy();
  // histAxis->GetXaxis()->SetRangeUser(-1, 200);
  // histAxis->Draw();

  const int nQuantilePoints =  nClass+1;
  vector<double> nQuantileArray = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
  vector<double> quantileArray(nQuantilePoints);
  vector<int> iBinLow(nClass);
  vector<int> iBinUp(nClass);

  getQuantileBinProperEdges(histAxis, nQuantilePoints, quantileArray, nQuantileArray,
    classLow, classUp, iBinLow, iBinUp);

  //treat each bin separately
  //Find the number of small bins available.
  cout<<"HistName = "<<histAxis->GetName()<<endl;
  cout<<"nBins    = "<<histAxis->GetNbinsX()<<endl;
  cout<<"xAxisLow = "<<histAxis->GetBinLowEdge(1)<<endl;
  cout<<"xAxisUp  = "<<histAxis->GetBinLowEdge(histAxis->GetNbinsX())+histAxis->GetBinWidth(histAxis->GetNbinsX())<<endl;
  
  //To Reduce the memory size find the first and the last filled bin 
  int firstFilledBin = getFirstFilledBin(histAxis);
  int lastFilledBin  = getLastFilledBin(histAxis); 

  cout<<"firstFilledBin = "<<firstFilledBin<<endl;
  cout<<"lastFilledBin  = "<<lastFilledBin<<endl;
  cout<<"lowEdgeOfLowestBin  = "<<histAxis->GetBinLowEdge(firstFilledBin)<<endl;
  cout<<"lowEdgeOfHighestBin = "<<histAxis->GetBinLowEdge(lastFilledBin)<<endl;
  const int nSmallClass = histAxis->GetBinLowEdge(lastFilledBin) - histAxis->GetBinLowEdge(firstFilledBin) + 1;//
  cout<<"nSmallClass = "<<nSmallClass<<endl;

  vector<double> smallClassLow(nSmallClass);
  vector<double> smallClassUp(nSmallClass);
  vector<int> nClassIDX_smallClass(nSmallClass);
  vector<int> iBinLow_smallClass(nSmallClass);
  vector<int> iBinUp_smallClass(nSmallClass);

  getSmallBinProperEdges(histAxis, nSmallClass, smallClassLow, smallClassUp, iBinLow_smallClass, iBinUp_smallClass, nClassIDX_smallClass, nClass, classLow, classUp, firstFilledBin, lastFilledBin);

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
  // Axis 0 :: centFT0C(percentile)
  // Axis 1 :: nTrack
  // Axis 2 :: nK0s
  // Axis 3 :: nRejectedPiPlus
  // Axis 4 :: nRejectedPiMinus
  // Axis 5 :: nPiPlus
  // Axis 6 :: nPiMinus
  // Axis 7 :: nKaPlus
  // Axis 8 :: nKaMinus
  
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
                    nSmallClass, smallClassLow, smallClassUp, nClassIDX_smallClass,
                    axisCl, pairType, axisA0, axisA1, axisB0, axisB1,
                      Rab_Kp_Km,  Raa_Kp_Km,  Rbb_Kp_Km,  NDy_Kp_Km, 
                    grRab_Kp_Km,grRaa_Kp_Km,grRbb_Kp_Km,grNDy_Kp_Km,
                      Rab_Kp_Km_CBWC,  Raa_Kp_Km_CBWC,  Rbb_Kp_Km_CBWC,  NDy_Kp_Km_CBWC,
                    grRab_Kp_Km_CBWC,grRaa_Kp_Km_CBWC,grRbb_Kp_Km_CBWC,grNDy_Kp_Km_CBWC,
                    HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/"
                  );

    grRab_Kp_Km->SetLineStyle(0);
    grRaa_Kp_Km->SetLineStyle(0);
    grRbb_Kp_Km->SetLineStyle(0);
    vector<TGraph*> graphList        = {grRab_Kp_Km, grRaa_Kp_Km,  grRbb_Kp_Km};
    vector<string>  graphLegTitles   = {"R_{ab}", "R_{aa}, a = K^{#plus}", "R_{bb}, b = K^{#minus}"};
    vector<double>  graphLegPosition = LegLeftTop;
    std::string MgTitle = "R_{aa},R_{ab},R_{bb} Values :: [K^{#plus}, K^{#minus}]";
    TMultiGraph* mgRvl_Kp_Km = GetMultigraph("mgRvl_Kp_Km", graphList,MgTitle.c_str(), "centFT0C (percentile)", "Value");//,graphLegTitles,graphLegPosition);
    TLegend* leg = GetLegendFromVectors(graphList, graphLegTitles, graphLegPosition);
    DrawMultigraphWithLegend(HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", mgRvl_Kp_Km, leg);

    setObjStyle(grNDy_Kp_Km, getMultiBit({hT,xT,yT}), {"#nu_{dyn}[K^{#plus},K^{#minus}]", "centFT0C (percentile)", "#nu_{dyn}[K^{#plus},K^{#minus}]"});
    CanvasSaver(grNDy_Kp_Km, HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", getMultiBit({ap}));

    grRab_Kp_Km_CBWC->SetLineStyle(0);
    grRaa_Kp_Km_CBWC->SetLineStyle(0);
    grRbb_Kp_Km_CBWC->SetLineStyle(0);
    vector<TGraph*> graphList_CBWC        = {grRab_Kp_Km_CBWC, grRaa_Kp_Km_CBWC,  grRbb_Kp_Km_CBWC};
    vector<string>  graphLegTitles_CBWC   = {"R_{ab} (CBWC)", "R_{aa} (CBWC), a = K^{#plus}", "R_{bb}(CBWC), b = K^{#minus}"};
    vector<double>  graphLegPosition_CBWC = LegLeftTop;
    std::string MgTitle_CBWC = "R_{aa},R_{ab},R_{bb} Values (CBWC) :: [K^{#plus}, K^{#minus}]";
    TMultiGraph* mgRvl_Kp_Km_CBWC = GetMultigraph("mgRvl_Kp_Km__CBWC", graphList_CBWC,MgTitle_CBWC.c_str(), "centFT0C (percentile)", "Value");//,graphLegTitles,graphLegPosition);
    TLegend* leg_CBWC = GetLegendFromVectors(graphList_CBWC, graphLegTitles_CBWC, graphLegPosition_CBWC);
    DrawMultigraphWithLegend(HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", mgRvl_Kp_Km_CBWC, leg_CBWC);

    setObjStyle(grNDy_Kp_Km_CBWC, getMultiBit({hT,xT,yT}), {"#nu_{dyn}[K^{#plus},K^{#minus}]", "centFT0C (percentile)", "#nu_{dyn}[K^{#plus},K^{#minus}] (CBWC)"});
    CanvasSaver(grNDy_Kp_Km_CBWC, HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", getMultiBit({ap}));
  //End = [K+, K-] Analysis

  //Begin = [K0s, Kaa] Analysis
  axisCl = 0;
  pairType = 1;
  if(pairType == 0) { axisA0 = axisKaPlus; axisB0 = axisKaMinus;  } //Two different Axis
  if(pairType == 1) { axisA0 = axisKaPlus; axisA1 = axisKaMinus; axisB0 = axisK0s; } // Sum of two different Axis and Third axis
  if(pairType == 2) { axisA0 = axisKaPlus; axisA1 = axisKaMinus; axisB0 = axisPiPlus; axisB1 = axisPiMinus; } //Sum two axis on each variable

  std::vector<double> Raa_Ka_K0s(nClass);
  std::vector<double> Rbb_Ka_K0s(nClass);
  std::vector<double> Rab_Ka_K0s(nClass);
  std::vector<double> NDy_Ka_K0s(nClass);
  TGraphErrors* grRab_Ka_K0s;
  TGraphErrors* grRaa_Ka_K0s;
  TGraphErrors* grRbb_Ka_K0s;
  TGraphErrors* grNDy_Ka_K0s;

  std::vector<double> Raa_Ka_K0s_CBWC(nClass);
  std::vector<double> Rbb_Ka_K0s_CBWC(nClass);
  std::vector<double> Rab_Ka_K0s_CBWC(nClass);
  std::vector<double> NDy_Ka_K0s_CBWC(nClass);
  TGraphErrors* grRab_Ka_K0s_CBWC;
  TGraphErrors* grRaa_Ka_K0s_CBWC;
  TGraphErrors* grRbb_Ka_K0s_CBWC;
  TGraphErrors* grNDy_Ka_K0s_CBWC;

  SparseAnalysis(Sparse_Full_K0sPiKa, nClass, classLow, classUp,
                  nSmallClass, smallClassLow, smallClassUp, nClassIDX_smallClass,
                  axisCl, pairType, axisA0, axisA1, axisB0, axisB1,
                    Rab_Ka_K0s,  Raa_Ka_K0s,  Rbb_Ka_K0s,  NDy_Ka_K0s, 
                  grRab_Ka_K0s,grRaa_Ka_K0s,grRbb_Ka_K0s,grNDy_Ka_K0s,
                    Rab_Ka_K0s_CBWC,  Raa_Ka_K0s_CBWC,  Rbb_Ka_K0s_CBWC,  NDy_Ka_K0s_CBWC,
                  grRab_Ka_K0s_CBWC,grRaa_Ka_K0s_CBWC,grRbb_Ka_K0s_CBWC,grNDy_Ka_K0s_CBWC,
                  HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/"                
                );

  grRab_Ka_K0s->SetLineStyle(0);
  grRaa_Ka_K0s->SetLineStyle(0);
  grRbb_Ka_K0s->SetLineStyle(0);
  graphList        = {grRab_Ka_K0s, grRaa_Ka_K0s,  grRbb_Ka_K0s};
  graphLegTitles   = {"R_{ab}", "R_{aa}, a = K^{#plus} + K^{#minus}", "R_{bb}, b = K^{0}_{s}"};
  graphLegPosition = LegLeftTop;
  MgTitle = "R_{aa},R_{ab},R_{bb} Values :: [K^{#pm}, K^{0}_{s}]";
  TMultiGraph* mgRvl_Ka_K0s = GetMultigraph("mgRvl_Ka_K0s", graphList, MgTitle.c_str(), "centFT0C (percentile)", "Value");//,graphLegTitles,graphLegPosition);
  mgRvl_Ka_K0s->Draw("alp");
  leg = GetLegendFromVectors(graphList, graphLegTitles, graphLegPosition);
  DrawMultigraphWithLegend(HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", mgRvl_Ka_K0s, leg);

  setObjStyle(grNDy_Ka_K0s, getMultiBit({hT,xT,yT}), {"#nu_{dyn}[K^{#pm},K^{0}_{s}]", "centFT0C (percentile)", "#nu_{dyn}[K^{#pm},K^{0}_{s}]"});
  CanvasSaver(grNDy_Ka_K0s, HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", getMultiBit({ap}));

  grRab_Ka_K0s_CBWC->SetLineStyle(0);
  grRaa_Ka_K0s_CBWC->SetLineStyle(0);
  grRbb_Ka_K0s_CBWC->SetLineStyle(0);
  graphList_CBWC        = {grRab_Ka_K0s_CBWC, grRaa_Ka_K0s_CBWC,  grRbb_Ka_K0s_CBWC};
  graphLegTitles_CBWC   = {"R_{ab} (CBWC)", "R_{aa} (CBWC), a = K^{#plus} + K^{#minus}", "R_{bb} (CBWC), b = K^{0}_{s}"};
  graphLegPosition_CBWC = LegLeftTop;
  MgTitle_CBWC = "R_{aa}, R_{ab}, R_{bb} Values (CBWC) :: [K^{#pm}, K^{0}_{s}]";
  TMultiGraph* mgRvl_Ka_K0s_CBWC = GetMultigraph("mgRvl_Ka_K0s_CBWC", graphList_CBWC,MgTitle_CBWC.c_str(), "centFT0C (percentile)", "Value");//,graphLegTitles,graphLegPosition);
  leg_CBWC = GetLegendFromVectors(graphList_CBWC, graphLegTitles_CBWC, graphLegPosition_CBWC);
  DrawMultigraphWithLegend(HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", mgRvl_Ka_K0s_CBWC, leg_CBWC);

  setObjStyle(grNDy_Ka_K0s_CBWC, getMultiBit({hT,xT,yT}), {"#nu_{dyn}[K^{#pm},K^{0}_{s}(CBWC)]", "centFT0C (percentile)", "#nu_{dyn}[K^{#pm},K^{0}_{s}(CBWC)]"});
  CanvasSaver(grNDy_Ka_K0s_CBWC, HIST(MainDir[kMainDir])+"recoAnalysis/Sparse_Full_K0sPiKa/NuDyn/", getMultiBit({ap}));

  cout<<"Writing The results in a File"<<endl;
  TFile *outFile = new TFile("StoredResults.root","RECREATE");
  outFile->cd();
  grRab_Ka_K0s->SetName("grRab_Ka_K0s");
  grRaa_Ka_K0s->SetName("grRaa_Ka_K0s");
  grRbb_Ka_K0s->SetName("grRbb_Ka_K0s");
  grNDy_Ka_K0s->SetName("grNDy_Ka_K0s");

  grRab_Ka_K0s->Write();
  grRaa_Ka_K0s->Write();
  grRbb_Ka_K0s->Write();
  grNDy_Ka_K0s->Write();

  grRab_Kp_Km->SetName("grRab_Kp_Km");
  grRaa_Kp_Km->SetName("grRaa_Kp_Km");
  grRbb_Kp_Km->SetName("grRbb_Kp_Km");
  grNDy_Kp_Km->SetName("grNDy_Kp_Km");

  grRab_Kp_Km->Write();
  grRaa_Kp_Km->Write();
  grRbb_Kp_Km->Write();
  grNDy_Kp_Km->Write();

  grRab_Ka_K0s_CBWC->SetName("grRab_Ka_K0s_CBWC");
  grRaa_Ka_K0s_CBWC->SetName("grRaa_Ka_K0s_CBWC");
  grRbb_Ka_K0s_CBWC->SetName("grRbb_Ka_K0s_CBWC");
  grNDy_Ka_K0s_CBWC->SetName("grNDy_Ka_K0s_CBWC");

  grRab_Ka_K0s_CBWC->Write();
  grRaa_Ka_K0s_CBWC->Write();
  grRbb_Ka_K0s_CBWC->Write();
  grNDy_Ka_K0s_CBWC->Write();

  grRab_Kp_Km->SetName("grRab_Kp_Km_CBWC");
  grRaa_Kp_Km->SetName("grRaa_Kp_Km_CBWC");
  grRbb_Kp_Km->SetName("grRbb_Kp_Km_CBWC");
  grNDy_Kp_Km->SetName("grNDy_Kp_Km_CBWC");

  grRab_Kp_Km->Write();
  grRaa_Kp_Km->Write();
  grRbb_Kp_Km->Write();
  grNDy_Kp_Km->Write();

  outFile->Close();
  delete outFile;
  cout<<"Results Stored"<<endl;
/*
// THnSparseD* Sparse_Full_K0sPrDe   = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_Full_K0sPrDe"  ); Sparse_Full_K0sPrDe  ->Print(); PrintAllAxisOfSparse(Sparse_Full_K0sPrDe  );
// THnSparseD* Sparse_Full_K0sKaEl   = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_Full_K0sKaEl"  ); Sparse_Full_K0sKaEl  ->Print(); PrintAllAxisOfSparse(Sparse_Full_K0sKaEl  );
// THnSparseD* Sparse_Full_PiKaPr    = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_Full_PiKaPr"   ); Sparse_Full_PiKaPr   ->Print(); PrintAllAxisOfSparse(Sparse_Full_PiKaPr   );
// THnSparseD* Sparse_Full_PiElDe    = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_Full_PiElDe"   ); Sparse_Full_PiElDe   ->Print(); PrintAllAxisOfSparse(Sparse_Full_PiElDe   );
// THnSparseD* Sparse_Full_KaPrDe    = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_Full_KaPrDe"   ); Sparse_Full_KaPrDe   ->Print(); PrintAllAxisOfSparse(Sparse_Full_KaPrDe   );
// THnSparseD* Sparse_Full_PrElDe    = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_Full_PrElDe"   ); Sparse_Full_PrElDe   ->Print(); PrintAllAxisOfSparse(Sparse_Full_PrElDe   );
// THnSparseD* Sparse_newDynm_K0s_Ka = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_newDynm_K0s_Ka"); Sparse_newDynm_K0s_Ka->Print(); PrintAllAxisOfSparse(Sparse_newDynm_K0s_Ka);
// THnSparseD* Sparse_newDynm_Kp_Km  = (THnSparseD*)inFile->Get("kaon-isospin-fluctuations/recoAnalysis/Sparse_newDynm_Kp_Km" ); Sparse_newDynm_Kp_Km ->Print(); PrintAllAxisOfSparse(Sparse_newDynm_Kp_Km );
*/
}

//________________________________________________ Main Function ___________________________________________________________
void NuDynMultiFileRead(){  
  SetStyle();

  cout<<endl<<"INFO :: extension = "<<ext<<endl;
  fs::path path = Form("SavePlots/%s/",ext.c_str());//"path/to/your/folder";  // Change this to the desired path
  createFolderWithParents(path);
  cout<<endl;

  const int nFiles = inFileList.size();
  cout<<"Number of Files = "<<nFiles<<endl;

  std::vector<TFile*> inFiles(inFileList.size(), nullptr); //use vectors, easy to manipulate using functions;
  loadTFiles(inFiles, inFileList);
  cout<<endl;

  cout<<"INFO :: Main Directory Is :: kMainDir = "<<kMainDir<<" :: MainDir["<<kMainDir<<"] = "<<MainDir[kMainDir]<<endl<<endl;

  std::vector<double> classLow(nClass);
  std::vector<double> classUp(nClass);
  int classNumber = 0;
  for(int i = 0; i < nClass; i++) { classLow[i] = i * 100.0/double(nClass) ; classUp[i] = (i+1) * 100.0/double(nClass) ;}
  classLow[0] = -1.0; classUp[nClass-1] = 101.0;

  for(int i = 0; i < nClass; i++) { cout<<i<<" :: "<<classLow[i]<<" :: "<<classUp[i]<<endl;}

  double x[nClass] = {10, 30, 50, 70, 90};

  if(PrintEvent){
    executeEventInfoPart(inFiles);
  }
  cout<<"INFO :: Saved :: AfterEventInfo :: gCanvasNo = 20 :: gCounterNo = 20"<<endl;
  cout<<endl;
  gCanvasNo = 20; gCounterNo = 20;

  if( PrintGenIdentifiedK0s      ) {fillGenTrackQA<genAnalysisDir, kK0s>(inFiles);}
  if( PrintGenIdentifiedPion     ) {fillGenTrackQA<genAnalysisDir, kPi >(inFiles);}
  if( PrintGenIdentifiedKaon     ) {fillGenTrackQA<genAnalysisDir, kKa >(inFiles);}
  if( PrintGenIdentifiedProton   ) {fillGenTrackQA<genAnalysisDir, kPr >(inFiles);}
  if( PrintGenIdentifiedElectron ) {fillGenTrackQA<genAnalysisDir, kEl >(inFiles);}
  if( PrintGenIdentifiedDeuteron ) {fillGenTrackQA<genAnalysisDir, kDe >(inFiles);}

  //V0 information
  if(PrintV0s){
    executeV0loop(inFiles);
  }
  cout<<endl;
  cout<<"INFO :: Saved :: v0TableFull             :: gCanvasNo = 191 :: gCounterNo = 191"<<endl;
  cout<<"INFO :: Saved :: v0TablePostK0sCheck     :: gCanvasNo = 363 :: gCounterNo = 363"<<endl;
  cout<<"INFO :: Saved :: v0TablePostMassCut      :: gCanvasNo = 535 :: gCounterNo = 535"<<endl;
  cout<<"INFO :: Saved :: v0TablePostSelectionCut :: gCanvasNo = 707 :: gCounterNo = 707"<<endl;
  cout<<"INFO :: Saved :: True V0 Tag Count Hist  :: gCanvasNo = 708 :: gCounterNo = 708"<<endl;
  cout<<endl;
  gCanvasNo = 708; gCounterNo = 708;
  //V0 information

  //K0s Information
  if(PrintK0s){
    executeV0InCollisionloop(inFiles);
  }
  cout<<endl;
  cout<<"INFO :: Saved :: recoK0sPreSel  :: gCanvasNo = 880  ; gCounterNo = 880 ;"<<endl;
  cout<<"INFO :: Saved :: recoK0sPostSel :: gCanvasNo = 1052 ; gCounterNo = 1052;"<<endl;
  cout<<endl;
  gCanvasNo = 1052 ; gCounterNo = 1052;

  //K0s Information
  if(PrintK0sMass){
    //Centerality vs Mass
    TH2F* hK0s_5_01_centFTOC_mK0s = loadMergedTH2FHistogram(inFiles, HIST(MainDir[kMainDir])+"recoK0s/PostSel/mK0s_vs_cent"); Set2DLabelsAxis(hK0s_5_01_centFTOC_mK0s, 1, "K0s Selected :: Mass vs centFT0C", 0, "", 0, "");
    // CanvasCounter++; DrawObject2D(CanvasCounter, c[CanvasCounter],hK0s_5_01_centFTOC_mK0s);

    TH1D* hK0s_nClass_mK0s[nClass];
    string nameString = "hK0s_nClass_mK0s";
    classNumber = 0;

    // void GetProjectionHist()
    int nTotalCount = 0; 
    for(classNumber = 0 ; classNumber < nClass; classNumber++){
      // TH2F hClone = 
      hK0s_5_01_centFTOC_mK0s->GetXaxis()->SetRangeUser(classLow[classNumber], classUp[classNumber]);
      hK0s_nClass_mK0s[classNumber] = hK0s_5_01_centFTOC_mK0s->ProjectionY();
      hK0s_nClass_mK0s[classNumber]->SetName(Form("%s_%d",nameString.c_str(),classNumber));
      hK0s_nClass_mK0s[classNumber]->SetTitle(Form("K0s Mass :: centFT0C[%2.0f,%2.0f]",classLow[classNumber], classUp[classNumber]));
      // CanvasCounter++; c[CanvasCounter] = new TCanvas();
      // hK0s_nClass_mK0s[classNumber]->Draw();
      nTotalCount += hK0s_nClass_mK0s[classNumber]->GetEntries();
    }

    cout<<"nTotalCount = "<<nTotalCount<<" :: Entries = "<<hK0s_5_01_centFTOC_mK0s->GetEntries()<<endl;
    if (nClass > 0) {DrawSix2DPlots(hK0s_nClass_mK0s[0], hK0s_nClass_mK0s[1], hK0s_nClass_mK0s[2], hK0s_nClass_mK0s[3], hK0s_nClass_mK0s[4]);}
    if constexpr (nClass > 5) {DrawSix2DPlots(hK0s_nClass_mK0s[5], hK0s_nClass_mK0s[6], hK0s_nClass_mK0s[7], hK0s_nClass_mK0s[8], hK0s_nClass_mK0s[9]);}
  }

  gCanvasNo = 1053 ; gCounterNo = 1053;  

  if(PrintFullTracks || PrintSelectedTracks){
    executeTrackQAPart(inFiles);
  }
  cout<<endl;
  cout<<"INFO :: Saved :: recoTrackPreSel  :: gCanvasNo = 1124 :: gCounterNo = 1124"<<endl;
  cout<<"INFO :: Saved :: recoTrackPostSel :: gCanvasNo = 1195 :: gCounterNo = 1195"<<endl;
  cout<<endl;
  gCanvasNo = 1195 ; gCounterNo = 1195;

  auto ps_IdTag  = HIST(MainDir[kMainDir])+"recoAnalysis/SelectedTrack_IdentificationTag" ; TH1* SelectedTrack_IdentificationTag = loadMergedHistogram(inFiles, ps_IdTag) ; Set2DLabelsAxis(SelectedTrack_IdentificationTag, 1, "Selected Track IdentificationTag", 0, "", 0, "");
  auto ps_RejTag = HIST(MainDir[kMainDir])+"recoAnalysis/RejectedTrack_RejectionTag"      ; TH1* RejectedTrack_RejectionTag      = loadMergedHistogram(inFiles, ps_RejTag); Set2DLabelsAxis(RejectedTrack_RejectionTag     , 1, "Rejected Track Information", 0, "", 0, "");
  if(PrintFullTracks || PrintSelectedTracks){
    CanvasSaver(SelectedTrack_IdentificationTag, getMultiBit({zL}));
    CanvasSaver(RejectedTrack_RejectionTag, getMultiBit({zL}));
  }
  cout<<"INFO :: Saved :: SelectedTracInfo    :: gCanvasNo = 1197 :: gCounterNo = 1197"<<endl;
  gCanvasNo = 1197 ; gCounterNo = 1197;

  // Identification Plots
  if(PrintTrackAnalysis){
    executeTrackAnalysisPart(inFiles);
  }
  cout<<endl;
  cout<<"INFO :: Saved :: Enter Pi/ Analysis :: gCanvasNo = 1377 :: gCounterNo = 1377"<<endl;
  cout<<"INFO :: Saved :: Exit  Pi/ Analysis :: gCanvasNo = 1406 :: gCounterNo = 1406"<<endl;
  cout<<"INFO :: Saved :: Enter Ka/ Analysis :: gCanvasNo = 1406 :: gCounterNo = 1406"<<endl;
  cout<<"INFO :: Saved :: Exit  Ka/ Analysis :: gCanvasNo = 1435 :: gCounterNo = 1435"<<endl;
  cout<<"INFO :: Saved :: Enter Pr/ Analysis :: gCanvasNo = 1435 :: gCounterNo = 1435"<<endl;
  cout<<"INFO :: Saved :: Exit  Pr/ Analysis :: gCanvasNo = 1464 :: gCounterNo = 1464"<<endl;
  cout<<"INFO :: Saved :: Enter El/ Analysis :: gCanvasNo = 1464 :: gCounterNo = 1464"<<endl;
  cout<<"INFO :: Saved :: Exit  El/ Analysis :: gCanvasNo = 1493 :: gCounterNo = 1493"<<endl;
  cout<<"INFO :: Saved :: Enter De/ Analysis :: gCanvasNo = 1493 :: gCounterNo = 1493"<<endl;
  cout<<"INFO :: Saved :: Exit  De/ Analysis :: gCanvasNo = 1522 :: gCounterNo = 1522"<<endl;
  cout<<"INFO :: Saved :: Exit TrackAnalysis :: gCanvasNo = 1522 :: gCounterNo = 1522"<<endl;
  cout<<endl;
  gCanvasNo = 1522 ; gCounterNo = 1522;

  if(PrintSparseAnalysis){
    executeSparseAnalysisPart(inFiles, nClass, classLow, classUp);
  }

}
