#ifndef HIRS_H
#define HIRS_H
#include <QVarLengthArray>
#include <QObject>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_magnifier.h>
#include <qwt_scale_engine.h>
#include <qwt_plot_panner.h>

class HIRS;
#include "ui_mainwindow.h"
#include "mainwindow.h"

#define HIRS_BYTES_PER_FRAME 36
#define HIRS_WORDS_PER_FRAME 22

class HIRS
{
public:
   HIRS(MainWindow *aParent);
   void addHIRSFrame(uchar *HIRSBytes, float *frameTime, uchar *frameChunkQuality);
   void processHIRS();
   void clearAll();

/*private slots:
   void HIRSPlotsZoomed();*/

private:
   MainWindow *Parent;
   void plotHIRSMirrorScanPos();
   void plotHIRSElements();
   void plotHIRSElement(int identToPlot);

   QVarLengthArray <int16_t> HIRSstream[HIRS_BYTES_PER_FRAME];
   //QVarLengthArray <uint> frameIDList;
   QVarLengthArray <uchar> frameQualityList; //we do need this because we need to know if we can trust the contrast/brightness calc for individual pixels
   QVarLengthArray <float> HIRSTime[HIRS_BYTES_PER_FRAME];
};

#endif // HIRS_H
