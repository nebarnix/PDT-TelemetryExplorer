#ifndef SEM_H
#define SEM_H
#include <QVarLengthArray>
#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>

class SEM;
#include "ui_mainwindow.h"
#include "mainwindow.h"

class SEM
{
public:
   SEM(MainWindow *aParent);
   void addSEMFrame(uchar SEMByte1, uchar SEMByte2, uint frameID, float frameTime, bool frameGood);
   void processSEM();
   void clearAll();

private:
   MainWindow *Parent;
   void decomMEPED();
   void decomTED();
   void filterMEPED();
   void filterTED();
   void plotMEPED();
   void plotMEPEDE0();
   void plotMEPEDE90();
   void plotMEPEDP0();
   void plotMEPEDP90();
   void plotMEPEDPOmni(); //omniP sounds better =P
   void plotTED();
   void plotTEDLow(); //0.05-1 keV Partial Energy Flux
   void plotTEDHigh(); //2-10 keV Partial Energy Flux
   void plotTEDMaxDifEnergyFlux(); //Maximum Differential Energy Flux
   void plotTEDEnergyMaxDifEnergyFlux(); //Energy of Maximum Differential Energy Flux
   void plotTEDFourPtEnergySpectrum0E(); //Four Point Energy/Flux Spectrum
   void plotTEDFourPtEnergySpectrum3E(); //Four Point Energy/Flux Spectrum
   void plotTEDFourPtEnergySpectrum0P(); //Four Point Energy/Flux Spectrum
   void plotTEDFourPtEnergySpectrum3P(); //Four Point Energy/Flux Spectrum
   void plotTEDBackgnd(); //Background Electron and Proton Levels

   void zeroJumpyPts(QVarLengthArray <uchar> &data, uint filterThreshold);

   QVarLengthArray <uchar> SEMdata1, SEMdata2;
   QVarLengthArray <uint> frameIDList;
   QVarLengthArray <uchar> frameQualityList;
   QVarLengthArray <float> frameTimeList;

   //IDEA! it would be cool to query ephemris data and overlay the data onto a map to show where auroras are

   //MEPED Variables
   QVarLengthArray <uchar> MEPED_0P1, MEPED_0P2, MEPED_0P3, MEPED_0P4, MEPED_0P5, MEPED_0P6;
   QVarLengthArray <uchar> MEPED_9P1, MEPED_9P2, MEPED_9P3, MEPED_9P4, MEPED_9P5, MEPED_9P6;
   QVarLengthArray <uchar> MEPED_0E1, MEPED_0E2, MEPED_0E3, MEPED_9E1, MEPED_9E2, MEPED_9E3;
   QVarLengthArray <uchar> MEPED_P6, MEPED_P7, MEPED_P8, MEPED_P9;

   //TED Variables
   QVarLengthArray <uchar> TED_0EFL, TED_0PFL, TED_3EFL, TED_3PFL;
   QVarLengthArray <uchar> TED_0EFH, TED_0PFH, TED_3EFH, TED_3PFH;
   QVarLengthArray <uchar> TED_0DEM, TED_0DPM, TED_3DEM, TED_3DPM;
   QVarLengthArray <uchar> TED_0EM, TED_0PM, TED_3EM, TED_3PM;
   QVarLengthArray <uchar> TED_0DE1, TED_0DE2, TED_0DE3, TED_0DE4, TED_3DE1, TED_3DE2, TED_3DE3, TED_3DE4, TED_0DP1, TED_0DP2, TED_0DP3, TED_0DP4, TED_3DP1, TED_3DP2, TED_3DP3, TED_3DP4;
   QVarLengthArray <uchar> TED_0EBKH, TED_0EBKL, TED_0PBKH, TED_0PBKL, TED_3PBKH, TED_3PBKL;

   //MEPED Time Variables
   QVarLengthArray <float> MEPED_0P1Time, MEPED_0P2Time, MEPED_0P3Time, MEPED_0P4Time, MEPED_0P5Time, MEPED_0P6Time;
   QVarLengthArray <float> MEPED_9P1Time, MEPED_9P2Time, MEPED_9P3Time, MEPED_9P4Time, MEPED_9P5Time, MEPED_9P6Time;
   QVarLengthArray <float> MEPED_0E1Time, MEPED_0E2Time, MEPED_0E3Time, MEPED_9E1Time, MEPED_9E2Time, MEPED_9E3Time;
   QVarLengthArray <float> MEPED_P6Time, MEPED_P7Time, MEPED_P8Time, MEPED_P9Time;


   //TED Time Variables
   QVarLengthArray <float> TED_0EFLTime, TED_0PFLTime, TED_3EFLTime, TED_3PFLTime;
   QVarLengthArray <float> TED_0EFHTime, TED_0PFHTime, TED_3EFHTime, TED_3PFHTime;
   QVarLengthArray <float> TED_0DEMTime, TED_0DPMTime, TED_3DEMTime, TED_3DPMTime;
   QVarLengthArray <float> TED_0EMTime, TED_0PMTime, TED_3EMTime, TED_3PMTime;
   QVarLengthArray <float> TED_0DE1Time, TED_0DE2Time, TED_0DE3Time, TED_0DE4Time, TED_3DE1Time, TED_3DE2Time, TED_3DE3Time, TED_3DE4Time, TED_0DP1Time, TED_0DP2Time, TED_0DP3Time, TED_0DP4Time, TED_3DP1Time, TED_3DP2Time, TED_3DP3Time, TED_3DP4Time;
   QVarLengthArray <float> TED_0EBKHTime, TED_0EBKLTime, TED_0PBKHTime, TED_0PBKLTime, TED_3PBKHTime, TED_3PBKLTime;
};

#endif // SEM_H
