#include "sem.h"

SEM::SEM(MainWindow *aParent)
   {
   Parent = aParent;
   }

void SEM::processSEM()
   {
   decomMEPED();
   decomTED();
   filterMEPED();
   filterTED();
   plotMEPED();
   plotTED();
   }

void SEM::clearAll()
   {
   SEMdata1.clear(); SEMdata2.clear();
   frameIDList.clear();
   frameQualityList.clear();
   frameTimeList.clear();

   //MEPED Variables
   MEPED_0P1.clear(); MEPED_0P2.clear(); MEPED_0P3.clear(); MEPED_0P4.clear(); MEPED_0P5.clear(); MEPED_0P6.clear();
   MEPED_9P1.clear(); MEPED_9P2.clear(); MEPED_9P3.clear(); MEPED_9P4.clear(); MEPED_9P5.clear(); MEPED_9P6.clear();
   MEPED_0E1.clear(); MEPED_0E2.clear(); MEPED_0E3.clear(); MEPED_9E1.clear(); MEPED_9E2.clear(); MEPED_9E3.clear();
   MEPED_P6.clear(); MEPED_P7.clear(); MEPED_P8.clear(); MEPED_P9.clear();

   //TED Variables
   TED_0EFL.clear(); TED_0PFL.clear(); TED_3EFL.clear(); TED_3PFL.clear();
   TED_0EFH.clear(); TED_0PFH.clear(); TED_3EFH.clear(); TED_3PFH.clear();
   TED_0DEM.clear(); TED_0DPM.clear(); TED_3DEM.clear(); TED_3DPM.clear();
   TED_0EM.clear(); TED_0PM.clear(); TED_3EM.clear(); TED_3PM.clear();
   TED_0DE1.clear(); TED_0DE2.clear(); TED_0DE3.clear(); TED_0DE4.clear(); TED_3DE1.clear(); TED_3DE2.clear(); TED_3DE3.clear(); TED_3DE4.clear(); TED_0DP1.clear(); TED_0DP2.clear(); TED_0DP3.clear(); TED_0DP4.clear(); TED_3DP1.clear(); TED_3DP2.clear(); TED_3DP3.clear(); TED_3DP4.clear();
   TED_0EBKH.clear(); TED_0EBKL.clear(); TED_0PBKH.clear(); TED_0PBKL.clear(); TED_3PBKH.clear(); TED_3PBKL.clear();

   //MEPED Time Variables
   MEPED_0P1Time.clear(); MEPED_0P2Time.clear(); MEPED_0P3Time.clear(); MEPED_0P4Time.clear(); MEPED_0P5Time.clear(); MEPED_0P6Time.clear();
   MEPED_9P1Time.clear(); MEPED_9P2Time.clear(); MEPED_9P3Time.clear(); MEPED_9P4Time.clear(); MEPED_9P5Time.clear(); MEPED_9P6Time.clear();
   MEPED_0E1Time.clear(); MEPED_0E2Time.clear(); MEPED_0E3Time.clear(); MEPED_9E1Time.clear(); MEPED_9E2Time.clear(); MEPED_9E3Time.clear();
   MEPED_P6Time.clear(); MEPED_P7Time.clear(); MEPED_P8Time.clear(); MEPED_P9Time.clear();


   //TED Time Variables
   TED_0EFLTime.clear(); TED_0PFLTime.clear(); TED_3EFLTime.clear(); TED_3PFLTime.clear();
   TED_0EFHTime.clear(); TED_0PFHTime.clear(); TED_3EFHTime.clear(); TED_3PFHTime.clear();
   TED_0DEMTime.clear(); TED_0DPMTime.clear(); TED_3DEMTime.clear(); TED_3DPMTime.clear();
   TED_0EMTime.clear(); TED_0PMTime.clear(); TED_3EMTime.clear(); TED_3PMTime.clear();
   TED_0DE1Time.clear(); TED_0DE2Time.clear(); TED_0DE3Time.clear(); TED_0DE4Time.clear(); TED_3DE1Time.clear(); TED_3DE2Time.clear(); TED_3DE3Time.clear(); TED_3DE4Time.clear(); TED_0DP1Time.clear(); TED_0DP2Time.clear(); TED_0DP3Time.clear(); TED_0DP4Time.clear(); TED_3DP1Time.clear(); TED_3DP2Time.clear(); TED_3DP3Time.clear(); TED_3DP4Time.clear();
   TED_0EBKHTime.clear(); TED_0EBKLTime.clear(); TED_0PBKHTime.clear(); TED_0PBKLTime.clear(); TED_3PBKHTime.clear(); TED_3PBKLTime.clear();

   //clear plots
   Parent->ui->MEPED0EPlot->detachItems();
   Parent->ui->MEPED0PPlot->detachItems();
   Parent->ui->MEPED90EPlot->detachItems();
   Parent->ui->MEPED90PPlot->detachItems();
   Parent->ui->MEPEDOmniPPlot->detachItems();

   Parent->ui->TEDBackPlot->detachItems();
   Parent->ui->TEDEMaxDEPlot->detachItems();
   Parent->ui->TEDFluxSpecPlotE1->detachItems();
   Parent->ui->TEDFluxSpecPlotE2->detachItems();
   Parent->ui->TEDFluxSpecPlotP1->detachItems();
   Parent->ui->TEDFluxSpecPlotP2->detachItems();
   Parent->ui->TEDHighPlot->detachItems();
   Parent->ui->TEDLowPlot->detachItems();
   Parent->ui->TEDMaxDEPlot->detachItems();
   }

void SEM::addSEMFrame(uchar SEMByte1, uchar SEMByte2, uint frameID, float frameTime, bool frameGood)
   {
   SEMdata1.append(SEMByte1);
   SEMdata2.append(SEMByte2);
   frameIDList.append(frameID);
   frameQualityList.append(frameGood);
   frameTimeList.append(frameTime);
   }

void SEM::decomMEPED()
   {
   //MEPED Digital A data consists of six directional proton measurements
   //and three directional electron measurements for each of two directions
   //of incidence (0 and 90 degrees) and four omni-directional proton
   //measurements. All but the two highest energy omni-directional proton
   //measurements are read out every two seconds. The two highest energy
   //omnidirectional proton measurements are read out every four seconds.
   //The MEPED Digital A data and readout rates are summarized in Table 4.3.4.2-2.

   for(uint frame=0; frame < frameIDList.length(); frame++)
      {
      if((frameIDList[frame] % 20) == 0)
         {
         MEPED_0P1.append(SEMdata2[frame]);
         MEPED_0P1Time.append(frameTimeList[frame]);
         }

      else if(((frameIDList[frame]-1) % 20) == 0)
         {
         MEPED_0P2.append(SEMdata1[frame]);
         MEPED_0P3.append(SEMdata2[frame]);
         MEPED_0P2Time.append(frameTimeList[frame]);
         MEPED_0P3Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-2) % 20) == 0)
         {
         MEPED_0P4.append(SEMdata1[frame]);
         MEPED_0P5.append(SEMdata2[frame]);
         MEPED_0P4Time.append(frameTimeList[frame]);
         MEPED_0P5Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-3) % 20) == 0)
         {
         MEPED_0P6.append(SEMdata1[frame]);
         MEPED_0E1.append(SEMdata2[frame]);
         MEPED_0P6Time.append(frameTimeList[frame]);
         MEPED_0E1Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-4) % 20) == 0)
         {
         MEPED_0E2.append(SEMdata1[frame]);
         MEPED_0E3.append(SEMdata2[frame]);
         MEPED_0E2Time.append(frameTimeList[frame]);
         MEPED_0E3Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-5) % 20) == 0)
         {
         MEPED_9P1.append(SEMdata1[frame]);
         MEPED_9P2.append(SEMdata2[frame]);
         MEPED_9P1Time.append(frameTimeList[frame]);
         MEPED_9P2Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-6) % 20) == 0)
         {
         MEPED_9P3.append(SEMdata1[frame]);
         MEPED_9P4.append(SEMdata2[frame]);
         MEPED_9P3Time.append(frameTimeList[frame]);
         MEPED_9P4Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-7) % 20) == 0)
         {
         MEPED_9P5.append(SEMdata1[frame]);
         MEPED_9P6.append(SEMdata2[frame]);
         MEPED_9P5Time.append(frameTimeList[frame]);
         MEPED_9P6Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-8) % 20) == 0)
         {
         MEPED_9E1.append(SEMdata1[frame]);
         MEPED_9E2.append(SEMdata2[frame]);
         MEPED_9E1Time.append(frameTimeList[frame]);
         MEPED_9E2Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-9) % 20) == 0)
         {
         MEPED_9E3.append(SEMdata1[frame]);
         MEPED_P6.append(SEMdata2[frame]);
         MEPED_9E3Time.append(frameTimeList[frame]);
         MEPED_P6Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-10) % 20) == 0)
         {
         MEPED_P7.append(SEMdata1[frame]);
         MEPED_P7Time.append(frameTimeList[frame]);
         }

      if(((frameIDList[frame]-10) % 40) == 0)
         {
         MEPED_P8.append(SEMdata2[frame]);
         MEPED_P8Time.append(frameTimeList[frame]);
         }

      if(((frameIDList[frame]-30) % 40) == 0)
         {
         MEPED_P9.append(SEMdata2[frame]);
         MEPED_P9Time.append(frameTimeList[frame]);
         }
      }
   }

void SEM::zeroJumpyPts(QVarLengthArray <uchar> &data, uint filterThreshold)
   {
   QVarLengthArray <int> indcsToRemove;
   //Nulling filter to zero out data points that jump out of family by a distance of filterThreshold
   for(int idx=1; idx < (data.length()-1); idx++)
      {
      if(abs(data[idx-1] - data[idx]) > filterThreshold && abs(data[idx+1] - data[idx]) > filterThreshold)
         indcsToRemove.append(idx);//data[idx] = 0; //zero out bad data values
      }

   for(int idx=indcsToRemove.length()-1; idx >= 0; idx--)
      data.remove(indcsToRemove[idx]); //we must work backwards else the indices will change on us
   }

void SEM::filterMEPED()
   {
   uint filterThreshold = 20;
   zeroJumpyPts(MEPED_0E1,filterThreshold);
   zeroJumpyPts(MEPED_0E2,filterThreshold);
   zeroJumpyPts(MEPED_0E3,filterThreshold);
   zeroJumpyPts(MEPED_9E1,filterThreshold);
   zeroJumpyPts(MEPED_9E2,filterThreshold);
   zeroJumpyPts(MEPED_9E3,filterThreshold);
   zeroJumpyPts(MEPED_0P1,filterThreshold);
   zeroJumpyPts(MEPED_0P2,filterThreshold);
   zeroJumpyPts(MEPED_0P3,filterThreshold);
   zeroJumpyPts(MEPED_0P4,filterThreshold);
   zeroJumpyPts(MEPED_0P5,filterThreshold);
   zeroJumpyPts(MEPED_0P6,filterThreshold);
   zeroJumpyPts(MEPED_9P1,filterThreshold);
   zeroJumpyPts(MEPED_9P2,filterThreshold);
   zeroJumpyPts(MEPED_9P3,filterThreshold);
   zeroJumpyPts(MEPED_9P4,filterThreshold);
   zeroJumpyPts(MEPED_9P5,filterThreshold);
   zeroJumpyPts(MEPED_9P6,filterThreshold);
   zeroJumpyPts(MEPED_P6,filterThreshold);
   zeroJumpyPts(MEPED_P7,filterThreshold);
   zeroJumpyPts(MEPED_P8,filterThreshold);
   zeroJumpyPts(MEPED_P9,filterThreshold);
   }

void SEM::filterTED()
   {
   uint filterThreshold = 20;
   //This will need to take into account change vs time, or we might crap out on long data loss intervals
   //since points are typically 2 seconds apart, and we have used 20, that means we were implicitly filter out points that changed more than 10 counts per second
   zeroJumpyPts(TED_0EFL,filterThreshold);
   zeroJumpyPts(TED_0PFL,filterThreshold);
   zeroJumpyPts(TED_3EFL,filterThreshold);
   zeroJumpyPts(TED_3PFL,filterThreshold);
   zeroJumpyPts(TED_0EFH,filterThreshold);
   zeroJumpyPts(TED_0PFH,filterThreshold);
   zeroJumpyPts(TED_3EFH,filterThreshold);
   zeroJumpyPts(TED_3PFH,filterThreshold);
   zeroJumpyPts(TED_0DEM,filterThreshold);
   zeroJumpyPts(TED_0DPM,filterThreshold);
   zeroJumpyPts(TED_3DEM,filterThreshold);
   zeroJumpyPts(TED_3DPM,filterThreshold);
   zeroJumpyPts(TED_0EM,filterThreshold);
   zeroJumpyPts(TED_0PM,filterThreshold);
   zeroJumpyPts(TED_3EM,filterThreshold);
   zeroJumpyPts(TED_3PM,filterThreshold);
   zeroJumpyPts(TED_0DE1,filterThreshold);
   zeroJumpyPts(TED_0DE2,filterThreshold);
   zeroJumpyPts(TED_0DE3,filterThreshold);
   zeroJumpyPts(TED_0DE4,filterThreshold);
   zeroJumpyPts(TED_3DE1,filterThreshold);
   zeroJumpyPts(TED_3DE2,filterThreshold);
   zeroJumpyPts(TED_3DE3,filterThreshold);
   zeroJumpyPts(TED_3DE4,filterThreshold);
   zeroJumpyPts(TED_0DP1,filterThreshold);
   zeroJumpyPts(TED_0DP2,filterThreshold);
   zeroJumpyPts(TED_0DP3,filterThreshold);
   zeroJumpyPts(TED_0DP4,filterThreshold);
   zeroJumpyPts(TED_3DP1,filterThreshold);
   zeroJumpyPts(TED_3DP2,filterThreshold);
   zeroJumpyPts(TED_3DP3,filterThreshold);
   zeroJumpyPts(TED_3DP4,filterThreshold);
   zeroJumpyPts(TED_0EBKH,filterThreshold);
   zeroJumpyPts(TED_0EBKL,filterThreshold);
   zeroJumpyPts(TED_0PBKH,filterThreshold);
   zeroJumpyPts(TED_0PBKL,filterThreshold);
   zeroJumpyPts(TED_3PBKH,filterThreshold);
   zeroJumpyPts(TED_3PBKL,filterThreshold);
   }

void SEM::decomTED()
   {
   //Random thought while flying to Amsterdam from Kyiv and over Berlin...
   //what if we had a more generic solution based on a telemetry definition file???
   //It would be more like writing a decom from scratch but would work for ANY data stream
   //And it would be much easier to add functionality.
   //Open Decom???! Anyone?!

   //TED Digital A data consists of a 0.05 to 1 keV partial energy
   //flux measurement, a 1 to 20 keV partial energy flux measurement,
   //maximum differential energy fluxes, four-point differential energy
   //spectra and background measurements for electrons and protons,
   //each at two angles of incidence (0 and 30 degrees).

   for(uint frame=0; frame < frameIDList.length(); frame++)
      {
      if(((frameIDList[frame]-13) % 20) == 0)
         {
         TED_0EFL.append(SEMdata1[frame]);
         TED_0EFLTime.append(frameTimeList[frame]);
         TED_3EFL.append(SEMdata2[frame]);
         TED_3EFLTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-14) % 20) == 0)
         {
         TED_0PFL.append(SEMdata1[frame]);
         TED_0PFLTime.append(frameTimeList[frame]);
         TED_3PFL.append(SEMdata2[frame]);
         TED_3PFLTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-15) % 20) == 0)
         {
         TED_0EFH.append(SEMdata1[frame]);
         TED_0EFHTime.append(frameTimeList[frame]);
         TED_3EFH.append(SEMdata2[frame]);
         TED_3EFHTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-16) % 20) == 0)
         {
         TED_0PFH.append(SEMdata1[frame]);
         TED_0PFHTime.append(frameTimeList[frame]);
         TED_3PFH.append(SEMdata2[frame]);
         TED_3PFHTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-17) % 20) == 0)
         {
         TED_0EM.append((SEMdata1[frame] & (128+64+32+16)) >> 4);
         TED_0EMTime.append(frameTimeList[frame]);
         TED_0PM.append(SEMdata1[frame] & (1+2+4+8));
         TED_0PMTime.append(frameTimeList[frame]);
         TED_0DEM.append(SEMdata2[frame]);
         TED_0DEMTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-18) % 20) == 0)
         {
         TED_0DPM.append(SEMdata1[frame]);
         TED_0DPMTime.append(frameTimeList[frame]);
         TED_3EM.append((SEMdata2[frame] & (128+64+32+16)) >> 4);
         TED_3EMTime.append(frameTimeList[frame]);
         TED_3PM.append(SEMdata2[frame] & (1+2+4+8));
         TED_3PMTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-19) % 20) == 0)
         {
         TED_3DEM.append(SEMdata1[frame]);
         TED_3DEMTime.append(frameTimeList[frame]);
         TED_3DPM.append(SEMdata2[frame]);
         TED_3DPMTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-11) % 80) == 0)
         {
         TED_0DE1.append(SEMdata1[frame]);
         TED_0DE1Time.append(frameTimeList[frame]);
         TED_0DE2.append(SEMdata2[frame]);
         TED_0DE2Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-31) % 80) == 0)
         {
         TED_3DE1.append(SEMdata1[frame]);
         TED_3DE1Time.append(frameTimeList[frame]);
         TED_3DE2.append(SEMdata2[frame]);
         TED_3DE2Time.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 51 || frameIDList[frame] == 131 || frameIDList[frame] == 211)
         {
         TED_0DP1.append(SEMdata1[frame]);
         TED_0DP1Time.append(frameTimeList[frame]);
         TED_0DP2.append(SEMdata2[frame]);
         TED_0DP2Time.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 71 || frameIDList[frame] == 151 || frameIDList[frame] == 231)
         {
         TED_3DP1.append(SEMdata1[frame]);
         TED_3DP1Time.append(frameTimeList[frame]);
         TED_3DP2.append(SEMdata2[frame]);
         TED_3DP2Time.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 291)
         {
         TED_0EBKL.append(SEMdata1[frame]);
         TED_0EBKLTime.append(frameTimeList[frame]);
         TED_0EBKH.append(SEMdata2[frame]);
         TED_0EBKHTime.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 311)
         {
         TED_3PBKL.append(SEMdata2[frame]);
         TED_3PBKLTime.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-12) % 80) == 0)
         {
         TED_0DE3.append(SEMdata1[frame]);
         TED_0DE3Time.append(frameTimeList[frame]);
         TED_0DE4.append(SEMdata2[frame]);
         TED_0DE4Time.append(frameTimeList[frame]);
         }
      else if(((frameIDList[frame]-32) % 80) == 0)
         {
         TED_3DE3.append(SEMdata1[frame]);
         TED_3DE3Time.append(frameTimeList[frame]);
         TED_3DE4.append(SEMdata2[frame]);
         TED_3DE4Time.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 52 || frameIDList[frame] == 132 || frameIDList[frame] == 212)
         {
         TED_0DP3.append(SEMdata1[frame]);
         TED_0DP3Time.append(frameTimeList[frame]);
         TED_0DP4.append(SEMdata2[frame]);
         TED_0DP4Time.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 72 || frameIDList[frame] == 152 || frameIDList[frame] == 232)
         {
         TED_3DP3.append(SEMdata1[frame]);
         TED_3DP3Time.append(frameTimeList[frame]);
         TED_3DP4.append(SEMdata2[frame]);
         TED_3DP4Time.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 292)
         {
         TED_0PBKL.append(SEMdata1[frame]);
         TED_0PBKLTime.append(frameTimeList[frame]);
         TED_0PBKH.append(SEMdata2[frame]);
         TED_0PBKHTime.append(frameTimeList[frame]);
         }
      else if(frameIDList[frame] == 312)
         {
         TED_3PBKH.append(SEMdata2[frame]);
         TED_3PBKHTime.append(frameTimeList[frame]);
         }
      }
   }

void SEM::plotMEPED()
   {
   plotMEPEDE0();  //0 degree electron counts
   plotMEPEDE90(); //90 degree electron counts
   plotMEPEDP0();  //0 degree proton counts
   plotMEPEDP90(); //90 degree proton counts
   plotMEPEDPOmni(); //omniP sounds better =P
   }

void SEM::plotTED()
   {
   plotTEDLow(); //0.05-1 keV Partial Energy Flux
   plotTEDHigh(); //2-10 keV Partial Energy Flux

   plotTEDMaxDifEnergyFlux(); //Maximum Differential Energy Flux
   plotTEDEnergyMaxDifEnergyFlux(); //Energy of Maximum Differential Energy Flux

   plotTEDBackgnd(); //Background Electron and Proton Levels

   plotTEDFourPtEnergySpectrum0E(); //Four Point Energy/Flux Spectrum
   plotTEDFourPtEnergySpectrum3E(); //Four Point Energy/Flux Spectrum
   plotTEDFourPtEnergySpectrum0P(); //Four Point Energy/Flux Spectrum
   plotTEDFourPtEnergySpectrum3P(); //Four Point Energy/Flux Spectrum
   }

void SEM::plotMEPEDE0()
   {
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   //Idea! Quality info could be shaded grey bars on the background for line plots


   QwtPlotCurve *curve1 = new QwtPlotCurve("Good >= 30KeV");
   //QwtPlotCurve *curve1Bad = new QwtPlotCurve("Bad >= 30KeV");

   QwtPlotCurve *curve2 = new QwtPlotCurve("Good >= 100KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad >= 100KeV");

   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  >= 300KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   //double *xPointsGood, *xPointsBad;
   //double *yPointsGood, *yPointsBad;
   //unsigned int numPointsGood=numGoodFrames;
   //unsigned int numPointsBad=abs(numFrames-numGoodFrames);

   xPoints1 = new double[MEPED_0E1.length()];
   yPoints1 = new double[MEPED_0E1.length()];

   xPoints2 = new double[MEPED_0E2.length()];
   yPoints2 = new double[MEPED_0E2.length()];

   xPoints3 = new double[MEPED_0E3.length()];
   yPoints3 = new double[MEPED_0E3.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < MEPED_0E1.length(); point++)
      {
      yPoints1[point] = MEPED_0E1[point];
      xPoints1[point] = MEPED_0E1Time[point];
      }

   for(int point=0; point < MEPED_0E2.length(); point++)
      {
      yPoints2[point] = MEPED_0E2[point];
      xPoints2[point] = MEPED_0E2Time[point];
      }

   for(int point=0; point < MEPED_0E3.length(); point++)
      {
      yPoints3[point] = MEPED_0E3[point];
      xPoints3[point] = MEPED_0E3Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], MEPED_0E1.length());
   curve1->setPen( QColor( "green" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], MEPED_0E2.length());
   curve2->setPen( QColor( "orange" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], MEPED_0E3.length());
   curve3->setPen( QColor( "red" ) );

   curve1->attach(Parent->ui->MEPED0EPlot);
   curve2->attach(Parent->ui->MEPED0EPlot);
   curve3->attach(Parent->ui->MEPED0EPlot);

   Parent->ui->MEPED0EPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->MEPED0EPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->MEPED0EPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->MEPED0EPlot->replot();
   Parent->ui->MEPED0EPlot->show();
   }

void SEM::plotMEPEDE90() {
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps


   QwtPlotCurve *curve1 = new QwtPlotCurve("Good >= 30KeV");
   //QwtPlotCurve *curve1Bad = new QwtPlotCurve("Bad >= 30KeV");

   QwtPlotCurve *curve2 = new QwtPlotCurve("Good >= 100KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad >= 100KeV");

   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  >= 300KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   //double *xPointsGood, *xPointsBad;
   //double *yPointsGood, *yPointsBad;
   //unsigned int numPointsGood=numGoodFrames;
   //unsigned int numPointsBad=abs(numFrames-numGoodFrames);

   xPoints1 = new double[MEPED_9E1.length()];
   yPoints1 = new double[MEPED_9E1.length()];

   xPoints2 = new double[MEPED_9E2.length()];
   yPoints2 = new double[MEPED_9E2.length()];

   xPoints3 = new double[MEPED_9E3.length()];
   yPoints3 = new double[MEPED_9E3.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < MEPED_9E1.length(); point++)
      {
      yPoints1[point] = MEPED_9E1[point];
      xPoints1[point] = MEPED_9E1Time[point];
      }

   for(int point=0; point < MEPED_9E2.length(); point++)
      {
      yPoints2[point] = MEPED_9E2[point];
      xPoints2[point] = MEPED_9E2Time[point];
      }

   for(int point=0; point < MEPED_9E3.length(); point++)
      {
      yPoints3[point] = MEPED_9E3[point];
      xPoints3[point] = MEPED_9E3Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], MEPED_9E1.length());
   curve1->setPen( QColor( "green" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], MEPED_9E2.length());
   curve2->setPen( QColor( "orange" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], MEPED_9E3.length());
   curve3->setPen( QColor( "red" ) );

   curve1->attach(Parent->ui->MEPED90EPlot);
   curve2->attach(Parent->ui->MEPED90EPlot);
   curve3->attach(Parent->ui->MEPED90EPlot);

   Parent->ui->MEPED90EPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->MEPED90EPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->MEPED90EPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->MEPED90EPlot->replot();
   Parent->ui->MEPED90EPlot->show();
   }

void SEM::plotMEPEDP0()
   {
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps


   QwtPlotCurve *curve1 = new QwtPlotCurve("Good = 30-80KeV");
   //QwtPlotCurve *curve1Bad = new QwtPlotCurve("Bad >= 30KeV");

   QwtPlotCurve *curve2 = new QwtPlotCurve("Good = 80-250KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad >= 100KeV");

   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  = 250-800KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   QwtPlotCurve *curve4 = new QwtPlotCurve("Good = 800-2.5k KeV");
   //QwtPlotCurve *curve1Bad = new QwtPlotCurve("Bad >= 30KeV");

   QwtPlotCurve *curve5 = new QwtPlotCurve("Good = 2.5-7 MeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad >= 100KeV");

   QwtPlotCurve *curve6 = new QwtPlotCurve("Good  > 7M KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;
   double *xPoints5, *yPoints5;
   double *xPoints6, *yPoints6;
   //double *xPointsGood, *xPointsBad;
   //double *yPointsGood, *yPointsBad;
   //unsigned int numPointsGood=numGoodFrames;
   //unsigned int numPointsBad=abs(numFrames-numGoodFrames);

   xPoints1 = new double[MEPED_0P1.length()];
   yPoints1 = new double[MEPED_0P1.length()];

   xPoints2 = new double[MEPED_0P2.length()];
   yPoints2 = new double[MEPED_0P2.length()];

   xPoints3 = new double[MEPED_0P3.length()];
   yPoints3 = new double[MEPED_0P3.length()];

   xPoints4 = new double[MEPED_0P4.length()];
   yPoints4 = new double[MEPED_0P4.length()];

   xPoints5 = new double[MEPED_0P5.length()];
   yPoints5 = new double[MEPED_0P5.length()];

   xPoints6 = new double[MEPED_0P6.length()];
   yPoints6 = new double[MEPED_0P6.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < MEPED_0P1.length(); point++)
      {
      yPoints1[point] = MEPED_0P1[point];
      xPoints1[point] = MEPED_0P1Time[point];
      }

   for(int point=0; point < MEPED_0P2.length(); point++)
      {
      yPoints2[point] = MEPED_0P2[point];
      xPoints2[point] = MEPED_0P2Time[point];
      }

   for(int point=0; point < MEPED_0P3.length(); point++)
      {
      yPoints3[point] = MEPED_0P3[point];
      xPoints3[point] = MEPED_0P3Time[point];
      }

   for(int point=0; point < MEPED_0P4.length(); point++)
      {
      yPoints4[point] = MEPED_0P4[point];
      xPoints4[point] = MEPED_0P4Time[point];
      }

   for(int point=0; point < MEPED_0P5.length(); point++)
      {
      yPoints5[point] = MEPED_0P5[point];
      xPoints5[point] = MEPED_0P5Time[point];
      }

   for(int point=0; point < MEPED_0P6.length(); point++)
      {
      yPoints6[point] = MEPED_0P6[point];
      xPoints6[point] = MEPED_0P6Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], MEPED_0P1.length());
   curve1->setPen( QColor( "green" ) ); //green

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], MEPED_0P2.length());
   curve2->setPen( QColor( "yellow-green" ) ); //yellow green

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], MEPED_0P3.length());
   curve3->setPen( QColor( "yellow" ) ); //yellow

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], MEPED_0P4.length());
   curve4->setPen( QColor( "orange" ) ); //orange

   curve5->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve5->setRawSamples(&xPoints5[0], &yPoints5[0], MEPED_0P5.length());
   curve5->setPen( QColor( "red" ) ); //red

   curve6->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve6->setRawSamples(&xPoints6[0], &yPoints6[0], MEPED_0P6.length());
   curve6->setPen( QColor( "purple" ) ); //purple

   curve1->attach(Parent->ui->MEPED0PPlot);
   curve2->attach(Parent->ui->MEPED0PPlot);
   curve3->attach(Parent->ui->MEPED0PPlot);
   curve4->attach(Parent->ui->MEPED0PPlot);
   curve5->attach(Parent->ui->MEPED0PPlot);
   curve6->attach(Parent->ui->MEPED0PPlot);

   Parent->ui->MEPED0PPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->MEPED0PPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->MEPED0PPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->MEPED0PPlot->replot();
   Parent->ui->MEPED0PPlot->show();
   }

void SEM::plotMEPEDP90()
   {
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps


   QwtPlotCurve *curve1 = new QwtPlotCurve("Good = 30-80KeV");
   //QwtPlotCurve *curve1Bad = new QwtPlotCurve("Bad >= 30KeV");

   QwtPlotCurve *curve2 = new QwtPlotCurve("Good = 80-250KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad >= 100KeV");

   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  = 250-800KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   QwtPlotCurve *curve4 = new QwtPlotCurve("Good = 800-2.5k KeV");
   //QwtPlotCurve *curve1Bad = new QwtPlotCurve("Bad >= 30KeV");

   QwtPlotCurve *curve5 = new QwtPlotCurve("Good = 2.5-7 MeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad >= 100KeV");

   QwtPlotCurve *curve6 = new QwtPlotCurve("Good  > 7M KeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;
   double *xPoints5, *yPoints5;
   double *xPoints6, *yPoints6;
   //double *xPointsGood, *xPointsBad;
   //double *yPointsGood, *yPointsBad;
   //unsigned int numPointsGood=numGoodFrames;
   //unsigned int numPointsBad=abs(numFrames-numGoodFrames);

   xPoints1 = new double[MEPED_9P1.length()];
   yPoints1 = new double[MEPED_9P1.length()];

   xPoints2 = new double[MEPED_9P2.length()];
   yPoints2 = new double[MEPED_9P2.length()];

   xPoints3 = new double[MEPED_9P3.length()];
   yPoints3 = new double[MEPED_9P3.length()];

   xPoints4 = new double[MEPED_9P4.length()];
   yPoints4 = new double[MEPED_9P4.length()];

   xPoints5 = new double[MEPED_9P5.length()];
   yPoints5 = new double[MEPED_9P5.length()];

   xPoints6 = new double[MEPED_9P6.length()];
   yPoints6 = new double[MEPED_9P6.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < MEPED_9P1.length(); point++)
      {
      yPoints1[point] = MEPED_9P1[point];
      xPoints1[point] = MEPED_9P1Time[point];
      }

   for(int point=0; point < MEPED_9P2.length(); point++)
      {
      yPoints2[point] = MEPED_9P2[point];
      xPoints2[point] = MEPED_9P2Time[point];
      }

   for(int point=0; point < MEPED_9P3.length(); point++)
      {
      yPoints3[point] = MEPED_9P3[point];
      xPoints3[point] = MEPED_9P3Time[point];
      }

   for(int point=0; point < MEPED_9P4.length(); point++)
      {
      yPoints4[point] = MEPED_9P4[point];
      xPoints4[point] = MEPED_9P4Time[point];
      }

   for(int point=0; point < MEPED_9P5.length(); point++)
      {
      yPoints5[point] = MEPED_9P5[point];
      xPoints5[point] = MEPED_9P5Time[point];
      }

   for(int point=0; point < MEPED_9P6.length(); point++)
      {
      yPoints6[point] = MEPED_9P6[point];
      xPoints6[point] = MEPED_9P6Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], MEPED_9P1.length());
   curve1->setPen( QColor( "green" ) ); //green

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], MEPED_9P2.length());
   curve2->setPen( QColor( "yellow-green" ) ); //yellow green

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], MEPED_9P3.length());
   curve3->setPen( QColor( "yellow" ) ); //yellow

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], MEPED_9P4.length());
   curve4->setPen( QColor( "orange" ) ); //orange

   curve5->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve5->setRawSamples(&xPoints5[0], &yPoints5[0], MEPED_9P5.length());
   curve5->setPen( QColor( "red" ) ); //red

   curve6->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve6->setRawSamples(&xPoints6[0], &yPoints6[0], MEPED_9P6.length());
   curve6->setPen( QColor( "purple" ) ); //purple

   curve1->attach(Parent->ui->MEPED90PPlot);
   curve2->attach(Parent->ui->MEPED90PPlot);
   curve3->attach(Parent->ui->MEPED90PPlot);
   curve4->attach(Parent->ui->MEPED90PPlot);
   curve5->attach(Parent->ui->MEPED90PPlot);
   curve6->attach(Parent->ui->MEPED90PPlot);

   Parent->ui->MEPED90PPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->MEPED90PPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->MEPED90PPlot->canvas() );
   magnifier->setMouseButton( Qt::RightButton );

   // finally, refresh the plot
   Parent->ui->MEPED90PPlot->replot();
   Parent->ui->MEPED90PPlot->show();
   }

void SEM::plotMEPEDPOmni()
   {
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good >= 16 MeV");
   //QwtPlotCurve *curve1Bad = new QwtPlotCurve("Bad >= 30KeV");

   QwtPlotCurve *curve2 = new QwtPlotCurve("Good >= 35 MeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad >= 100KeV");

   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  >= 70 MeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   QwtPlotCurve *curve4 = new QwtPlotCurve("Good  >= 140 MeV");
   //QwtPlotCurve *curve2Bad = new QwtPlotCurve("Bad  >= 300KeV");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;
   //double *xPointsGood, *xPointsBad;
   //double *yPointsGood, *yPointsBad;
   //unsigned int numPointsGood=numGoodFrames;
   //unsigned int numPointsBad=abs(numFrames-numGoodFrames);

   xPoints1 = new double[MEPED_P6.length()];
   yPoints1 = new double[MEPED_P6.length()];

   xPoints2 = new double[MEPED_P7.length()];
   yPoints2 = new double[MEPED_P7.length()];

   xPoints3 = new double[MEPED_P8.length()];
   yPoints3 = new double[MEPED_P8.length()];

   xPoints4 = new double[MEPED_P9.length()];
   yPoints4 = new double[MEPED_P9.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < MEPED_P6.length(); point++)
      {
      yPoints1[point] = MEPED_P6[point];
      xPoints1[point] = MEPED_P6Time[point];
      }

   for(int point=0; point < MEPED_P7.length(); point++)
      {
      yPoints2[point] = MEPED_P7[point];
      xPoints2[point] = MEPED_P7Time[point];
      }

   for(int point=0; point < MEPED_P8.length(); point++)
      {
      yPoints3[point] = MEPED_P8[point];
      xPoints3[point] = MEPED_P8Time[point];
      }

   for(int point=0; point < MEPED_P9.length(); point++)
      {
      yPoints4[point] = MEPED_P9[point];
      xPoints4[point] = MEPED_P9Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], MEPED_P6.length());
   curve1->setPen( QColor( "green" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], MEPED_P7.length());
   curve2->setPen( QColor( "orange" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], MEPED_P8.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], MEPED_P9.length());
   curve4->setPen( QColor( "purple" ) );

   curve1->attach(Parent->ui->MEPEDOmniPPlot);
   curve2->attach(Parent->ui->MEPEDOmniPPlot);
   curve3->attach(Parent->ui->MEPEDOmniPPlot);
   curve4->attach(Parent->ui->MEPEDOmniPPlot);

   Parent->ui->MEPEDOmniPPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->MEPEDOmniPPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->MEPEDOmniPPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->MEPEDOmniPPlot->replot();
   Parent->ui->MEPEDOmniPPlot->show();
   }

//0.05-1 keV Partial Energy Flux
void SEM::plotTEDLow()
   {
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good 0 Degree Electrons");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good 0 Degree Protons");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  30 Degree Electrons");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good  30 Degree Protons");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_0EFL.length()];
   yPoints1 = new double[TED_0EFL.length()];

   xPoints2 = new double[TED_0PFL.length()];
   yPoints2 = new double[TED_0PFL.length()];

   xPoints3 = new double[TED_3EFL.length()];
   yPoints3 = new double[TED_3EFL.length()];

   xPoints4 = new double[TED_3PFL.length()];
   yPoints4 = new double[TED_3PFL.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_0EFL.length(); point++)
      {
      yPoints1[point] = TED_0EFL[point];
      xPoints1[point] = TED_0EFLTime[point];
      }

   for(int point=0; point < TED_0PFL.length(); point++)
      {
      yPoints2[point] = TED_0PFL[point];
      xPoints2[point] = TED_0PFLTime[point];
      }

   for(int point=0; point < TED_3EFL.length(); point++)
      {
      yPoints3[point] = TED_3EFL[point];
      xPoints3[point] = TED_3EFLTime[point];
      }

   for(int point=0; point < TED_3PFL.length(); point++)
      {
      yPoints4[point] = TED_3PFL[point];
      xPoints4[point] = TED_3PFLTime[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_0EFL.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_0PFL.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_3EFL.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_3PFL.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDLowPlot);
   curve2->attach(Parent->ui->TEDLowPlot);
   curve3->attach(Parent->ui->TEDLowPlot);
   curve4->attach(Parent->ui->TEDLowPlot);

   Parent->ui->TEDLowPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDLowPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDLowPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDLowPlot->replot();
   Parent->ui->TEDLowPlot->show();
   }

//2-10 keV Partial Energy Flux
void SEM::plotTEDHigh()
   {

   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good 0 Degree Electrons");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good 0 Degree Protons");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  30 Degree Electrons");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good  30 Degree Protons");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_0EFH.length()];
   yPoints1 = new double[TED_0EFH.length()];

   xPoints2 = new double[TED_0PFH.length()];
   yPoints2 = new double[TED_0PFH.length()];

   xPoints3 = new double[TED_3EFH.length()];
   yPoints3 = new double[TED_3EFH.length()];

   xPoints4 = new double[TED_3PFH.length()];
   yPoints4 = new double[TED_3PFH.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_0EFH.length(); point++)
      {
      yPoints1[point] = TED_0EFH[point];
      xPoints1[point] = TED_0EFHTime[point];
      }

   for(int point=0; point < TED_0PFH.length(); point++)
      {
      yPoints2[point] = TED_0PFH[point];
      xPoints2[point] = TED_0PFHTime[point];
      }

   for(int point=0; point < TED_3EFH.length(); point++)
      {
      yPoints3[point] = TED_3EFH[point];
      xPoints3[point] = TED_3EFHTime[point];
      }

   for(int point=0; point < TED_3PFH.length(); point++)
      {
      yPoints4[point] = TED_3PFH[point];
      xPoints4[point] = TED_3PFHTime[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_0EFH.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_0PFH.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_3EFH.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_3PFH.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDHighPlot);
   curve2->attach(Parent->ui->TEDHighPlot);
   curve3->attach(Parent->ui->TEDHighPlot);
   curve4->attach(Parent->ui->TEDHighPlot);

   Parent->ui->TEDHighPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDHighPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDHighPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDHighPlot->replot();
   Parent->ui->TEDHighPlot->show();
   }

//Maximum Differential Energy Flux
void SEM::plotTEDMaxDifEnergyFlux()
   {
   //TED_0DEM, TED_0DPM, TED_3DEM, TED_3DPM
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good 0 Degree Electrons");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good 0 Degree Protons");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  30 Degree Electrons");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good  30 Degree Protons");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_0DEM.length()];
   yPoints1 = new double[TED_0DEM.length()];

   xPoints2 = new double[TED_0DPM.length()];
   yPoints2 = new double[TED_0DPM.length()];

   xPoints3 = new double[TED_3DEM.length()];
   yPoints3 = new double[TED_3DEM.length()];

   xPoints4 = new double[TED_3DPM.length()];
   yPoints4 = new double[TED_3DPM.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_0DEM.length(); point++)
      {
      yPoints1[point] = TED_0DEM[point];
      xPoints1[point] = TED_0DEMTime[point];
      }

   for(int point=0; point < TED_0DPM.length(); point++)
      {
      yPoints2[point] = TED_0DPM[point];
      xPoints2[point] = TED_0DPMTime[point];
      }

   for(int point=0; point < TED_3DEM.length(); point++)
      {
      yPoints3[point] = TED_3DEM[point];
      xPoints3[point] = TED_3DEMTime[point];
      }

   for(int point=0; point < TED_3DPM.length(); point++)
      {
      yPoints4[point] = TED_3DPM[point];
      xPoints4[point] = TED_3DPMTime[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_0DEM.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_0DPM.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_3DEM.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_3DPM.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDMaxDEPlot);
   curve2->attach(Parent->ui->TEDMaxDEPlot);
   curve3->attach(Parent->ui->TEDMaxDEPlot);
   curve4->attach(Parent->ui->TEDMaxDEPlot);

   Parent->ui->TEDMaxDEPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDMaxDEPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDMaxDEPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDMaxDEPlot->replot();
   Parent->ui->TEDMaxDEPlot->show();
   }

//Energy of Maximum Differential Energy Flux
void SEM::plotTEDEnergyMaxDifEnergyFlux()
   {
   //TED_0EM, TED_0PM, TED_3EM, TED_3PM
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good 0 Degree Electrons");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good 0 Degree Protons");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good  30 Degree Electrons");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good  30 Degree Protons");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_0EM.length()];
   yPoints1 = new double[TED_0EM.length()];

   xPoints2 = new double[TED_0PM.length()];
   yPoints2 = new double[TED_0PM.length()];

   xPoints3 = new double[TED_3EM.length()];
   yPoints3 = new double[TED_3EM.length()];

   xPoints4 = new double[TED_3PM.length()];
   yPoints4 = new double[TED_3PM.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_0EM.length(); point++)
      {
      yPoints1[point] = TED_0EM[point];
      xPoints1[point] = TED_0EMTime[point];
      }

   for(int point=0; point < TED_0PM.length(); point++)
      {
      yPoints2[point] = TED_0PM[point];
      xPoints2[point] = TED_0PMTime[point];
      }

   for(int point=0; point < TED_3EM.length(); point++)
      {
      yPoints3[point] = TED_3EM[point];
      xPoints3[point] = TED_3EMTime[point];
      }

   for(int point=0; point < TED_3PM.length(); point++)
      {
      yPoints4[point] = TED_3PM[point];
      xPoints4[point] = TED_3PMTime[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_0EM.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_0PM.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_3EM.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_3PM.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDEMaxDEPlot);
   curve2->attach(Parent->ui->TEDEMaxDEPlot);
   curve3->attach(Parent->ui->TEDEMaxDEPlot);
   curve4->attach(Parent->ui->TEDEMaxDEPlot);

   Parent->ui->TEDEMaxDEPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDEMaxDEPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDEMaxDEPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDEMaxDEPlot->replot();
   Parent->ui->TEDEMaxDEPlot->show();
   }

//Four Point Energy/Flux Spectrum
void SEM::plotTEDFourPtEnergySpectrum0E()
   {
   //plot(1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4,1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4);
   //(TED_0DE1)(TED_0DE2)(TED_0DE3)(TED_0DE4) TEDFluxSpecPlotE1


   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good Bkgnd Electrons Low");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good Bkgnd Electrons High");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good Bkgnd Protons Low");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good Bkgnd Protons High");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_0DE1.length()];
   yPoints1 = new double[TED_0DE1.length()];

   xPoints2 = new double[TED_0DE2.length()];
   yPoints2 = new double[TED_0DE2.length()];

   xPoints3 = new double[TED_0DE3.length()];
   yPoints3 = new double[TED_0DE3.length()];

   xPoints4 = new double[TED_0DE4.length()];
   yPoints4 = new double[TED_0DE4.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_0DE1.length(); point++)
      {
      yPoints1[point] = TED_0DE1[point];
      xPoints1[point] = TED_0DE1Time[point];
      }

   for(int point=0; point < TED_0DE2.length(); point++)
      {
      yPoints2[point] = TED_0DE2[point];
      xPoints2[point] = TED_0DE2Time[point];
      }

   for(int point=0; point < TED_0DE3.length(); point++)
      {
      yPoints3[point] = TED_0DE3[point];
      xPoints3[point] = TED_0DE3Time[point];
      }

   for(int point=0; point < TED_0DE4.length(); point++)
      {
      yPoints4[point] = TED_0DE4[point];
      xPoints4[point] = TED_0DE4Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_0DE1.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_0DE2.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_0DE3.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_0DE4.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDFluxSpecPlotE1);
   curve2->attach(Parent->ui->TEDFluxSpecPlotE1);
   curve3->attach(Parent->ui->TEDFluxSpecPlotE1);
   curve4->attach(Parent->ui->TEDFluxSpecPlotE1);

   Parent->ui->TEDFluxSpecPlotE1->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDFluxSpecPlotE1->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDFluxSpecPlotE1->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDFluxSpecPlotE1->replot();
   Parent->ui->TEDFluxSpecPlotE1->show();
   }

//Four Point Energy/Flux Spectrum
void SEM::plotTEDFourPtEnergySpectrum3E()
   {
   //plot(1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4,1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4);
   //(TED_3DE1)(TED_3DE2)(TED_3DE3)(TED_3DE4) TEDFluxSpecPlotE2


   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good Bkgnd Electrons Low");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good Bkgnd Electrons High");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good Bkgnd Protons Low");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good Bkgnd Protons High");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_3DE1.length()];
   yPoints1 = new double[TED_3DE1.length()];

   xPoints2 = new double[TED_3DE2.length()];
   yPoints2 = new double[TED_3DE2.length()];

   xPoints3 = new double[TED_3DE3.length()];
   yPoints3 = new double[TED_3DE3.length()];

   xPoints4 = new double[TED_3DE4.length()];
   yPoints4 = new double[TED_3DE4.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_3DE1.length(); point++)
      {
      yPoints1[point] = TED_3DE1[point];
      xPoints1[point] = TED_3DE1Time[point];
      }

   for(int point=0; point < TED_3DE2.length(); point++)
      {
      yPoints2[point] = TED_3DE2[point];
      xPoints2[point] = TED_3DE2Time[point];
      }

   for(int point=0; point < TED_3DE3.length(); point++)
      {
      yPoints3[point] = TED_3DE3[point];
      xPoints3[point] = TED_3DE3Time[point];
      }

   for(int point=0; point < TED_3DE4.length(); point++)
      {
      yPoints4[point] = TED_3DE4[point];
      xPoints4[point] = TED_3DE4Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_3DE1.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_3DE2.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_3DE3.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_3DE4.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDFluxSpecPlotE2);
   curve2->attach(Parent->ui->TEDFluxSpecPlotE2);
   curve3->attach(Parent->ui->TEDFluxSpecPlotE2);
   curve4->attach(Parent->ui->TEDFluxSpecPlotE2);

   Parent->ui->TEDFluxSpecPlotE2->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDFluxSpecPlotE2->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDFluxSpecPlotE2->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDFluxSpecPlotE2->replot();
   Parent->ui->TEDFluxSpecPlotE2->show();
   }

//Four Point Energy/Flux Spectrum
void SEM::plotTEDFourPtEnergySpectrum0P()
   {
   //plot(1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4,1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4);
   //(TED_0DP1)(TED_0DP2)(TED_0DP3)(TED_0DP4) TEDFluxSpecPlotP1


   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good Bkgnd Electrons Low");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good Bkgnd Electrons High");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good Bkgnd Protons Low");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good Bkgnd Protons High");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_0DP1.length()];
   yPoints1 = new double[TED_0DP1.length()];

   xPoints2 = new double[TED_0DP2.length()];
   yPoints2 = new double[TED_0DP2.length()];

   xPoints3 = new double[TED_0DP3.length()];
   yPoints3 = new double[TED_0DP3.length()];

   xPoints4 = new double[TED_0DP4.length()];
   yPoints4 = new double[TED_0DP4.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_0DP1.length(); point++)
      {
      yPoints1[point] = TED_0DP1[point];
      xPoints1[point] = TED_0DP1Time[point];
      }

   for(int point=0; point < TED_0DP2.length(); point++)
      {
      yPoints2[point] = TED_0DP2[point];
      xPoints2[point] = TED_0DP2Time[point];
      }

   for(int point=0; point < TED_0DP3.length(); point++)
      {
      yPoints3[point] = TED_0DP3[point];
      xPoints3[point] = TED_0DP3Time[point];
      }

   for(int point=0; point < TED_0DP4.length(); point++)
      {
      yPoints4[point] = TED_0DP4[point];
      xPoints4[point] = TED_0DP4Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_0DP1.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_0DP2.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_0DP3.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_0DP4.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDFluxSpecPlotP1);
   curve2->attach(Parent->ui->TEDFluxSpecPlotP1);
   curve3->attach(Parent->ui->TEDFluxSpecPlotP1);
   curve4->attach(Parent->ui->TEDFluxSpecPlotP1);

   Parent->ui->TEDFluxSpecPlotP1->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDFluxSpecPlotP1->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDFluxSpecPlotP1->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDFluxSpecPlotP1->replot();
   Parent->ui->TEDFluxSpecPlotP1->show();
   }

//Four Point Energy/Flux Spectrum
void SEM::plotTEDFourPtEnergySpectrum3P()
   {
   //plot(1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4,1:numel(TED_0DP1),TED_0DP1,1:numel(TED_0DP2),TED_0DP2,1:numel(TED_0DP3),TED_0DP3,1:numel(TED_0DP4),TED_0DP4,1:numel(TED_3DP1),TED_3DP1,1:numel(TED_3DP2),TED_3DP2,1:numel(TED_3DP3),TED_3DP3,1:numel(TED_3DP4),TED_3DP4);
   //(TED_3DP1)(TED_3DP2)(TED_3DP3)(TED_3DP4) TEDFluxSpecPlotP2


   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good Bkgnd Electrons Low");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good Bkgnd Electrons High");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good Bkgnd Protons Low");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good Bkgnd Protons High");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_3DP1.length()];
   yPoints1 = new double[TED_3DP1.length()];

   xPoints2 = new double[TED_3DP2.length()];
   yPoints2 = new double[TED_3DP2.length()];

   xPoints3 = new double[TED_3DP3.length()];
   yPoints3 = new double[TED_3DP3.length()];

   xPoints4 = new double[TED_3DP4.length()];
   yPoints4 = new double[TED_3DP4.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_3DP1.length(); point++)
      {
      yPoints1[point] = TED_3DP1[point];
      xPoints1[point] = TED_3DP1Time[point];
      }

   for(int point=0; point < TED_3DP2.length(); point++)
      {
      yPoints2[point] = TED_3DP2[point];
      xPoints2[point] = TED_3DP2Time[point];
      }

   for(int point=0; point < TED_3DP3.length(); point++)
      {
      yPoints3[point] = TED_3DP3[point];
      xPoints3[point] = TED_3DP3Time[point];
      }

   for(int point=0; point < TED_3DP4.length(); point++)
      {
      yPoints4[point] = TED_3DP4[point];
      xPoints4[point] = TED_3DP4Time[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_3DP1.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_3DP2.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_3DP3.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_3DP4.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDFluxSpecPlotP2);
   curve2->attach(Parent->ui->TEDFluxSpecPlotP2);
   curve3->attach(Parent->ui->TEDFluxSpecPlotP2);
   curve4->attach(Parent->ui->TEDFluxSpecPlotP2);

   Parent->ui->TEDFluxSpecPlotP2->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDFluxSpecPlotP2->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDFluxSpecPlotP2->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDFluxSpecPlotP2->replot();
   Parent->ui->TEDFluxSpecPlotP2->show();
   }

//Background Electron and Proton Levels
void SEM::plotTEDBackgnd()
   {
   //TED_0EBKL,TED_0EBKH,TED_0PBKL,TED_0PBKH
   // add curves
   //TODO add quality information. This needs to be carried all of the way through the previous decom steps

   QwtPlotCurve *curve1 = new QwtPlotCurve("Good Bkgnd Electrons Low");
   QwtPlotCurve *curve2 = new QwtPlotCurve("Good Bkgnd Electrons High");
   QwtPlotCurve *curve3 = new QwtPlotCurve("Good Bkgnd Protons Low");
   QwtPlotCurve *curve4 = new QwtPlotCurve("Good Bkgnd Protons High");

   double *xPoints1, *yPoints1;
   double *xPoints2, *yPoints2;
   double *xPoints3, *yPoints3;
   double *xPoints4, *yPoints4;

   xPoints1 = new double[TED_0EBKL.length()];
   yPoints1 = new double[TED_0EBKL.length()];

   xPoints2 = new double[TED_0EBKH.length()];
   yPoints2 = new double[TED_0EBKH.length()];

   xPoints3 = new double[TED_0PBKL.length()];
   yPoints3 = new double[TED_0PBKL.length()];

   xPoints4 = new double[TED_0PBKH.length()];
   yPoints4 = new double[TED_0PBKH.length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < TED_0EBKL.length(); point++)
      {
      yPoints1[point] = TED_0EBKL[point];
      xPoints1[point] = TED_0EBKLTime[point];
      }

   for(int point=0; point < TED_0EBKH.length(); point++)
      {
      yPoints2[point] = TED_0EBKH[point];
      xPoints2[point] = TED_0EBKHTime[point];
      }

   for(int point=0; point < TED_0PBKL.length(); point++)
      {
      yPoints3[point] = TED_0PBKL[point];
      xPoints3[point] = TED_0PBKLTime[point];
      }

   for(int point=0; point < TED_0PBKH.length(); point++)
      {
      yPoints4[point] = TED_0PBKH[point];
      xPoints4[point] = TED_0PBKHTime[point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], TED_0EBKL.length());
   curve1->setPen( QColor( "orange" ) );

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], TED_0EBKH.length());
   curve2->setPen( QColor( "purple" ) );

   curve3->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve3->setRawSamples(&xPoints3[0], &yPoints3[0], TED_0PBKL.length());
   curve3->setPen( QColor( "red" ) );

   curve4->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve4->setRawSamples(&xPoints4[0], &yPoints4[0], TED_0PBKH.length());
   curve4->setPen( QColor( "magenta" ) );

   curve1->attach(Parent->ui->TEDBackPlot);
   curve2->attach(Parent->ui->TEDBackPlot);
   curve3->attach(Parent->ui->TEDBackPlot);
   curve4->attach(Parent->ui->TEDBackPlot);

   Parent->ui->TEDBackPlot->autoFillBackground();

   (void )new QwtPlotPanner( Parent->ui->TEDBackPlot->canvas() );
   QwtPlotMagnifier *magnifier = new QwtPlotMagnifier( Parent->ui->TEDBackPlot->canvas() );
   magnifier->setMouseButton( Qt::NoButton );

   // finally, refresh the plot
   Parent->ui->TEDBackPlot->replot();
   Parent->ui->TEDBackPlot->show();
   }


