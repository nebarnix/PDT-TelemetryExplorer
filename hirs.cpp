#include "hirs.h"
/*
virtual void YourPlotMagnifier::rescale(double factor)
{
    QwtPlotMagnifier::rescale(factor);

    emit Magnified();
}*/

/*viod HIRS::HIRSPlotsZoomed()
   {
   Parent->ui->HIRSRawPlot->setAxisAutoScale( QwtPlot::yLeft );
   Parent->ui->HIRSElemPlot->setAxisAutoScale( QwtPlot::yLeft );
   Parent->ui->HIRSScanPosPlot->setAxisAutoScale( QwtPlot::yLeft );
   }*/

HIRS::HIRS(MainWindow *aParent)
   {
   Parent = aParent;

   (void )new QwtPlotPanner( Parent->ui->HIRSScanPosPlot->canvas() );
   QwtPlotMagnifier *zoom_x2 = new QwtPlotMagnifier( Parent->ui->HIRSScanPosPlot->canvas()  );
   QwtPlotMagnifier *zoom_y2 = new QwtPlotMagnifier( Parent->ui->HIRSScanPosPlot->canvas()  );
   zoom_x2->setWheelModifiers(Qt::ControlModifier);
   zoom_x2->setAxisEnabled(Qt::XAxis, true);
   zoom_x2->setAxisEnabled(Qt::YAxis,false);

   zoom_y2->setAxisEnabled(Qt::XAxis,false);
   zoom_y2->setAxisEnabled(Qt::YAxis,true);

   (void )new QwtPlotPanner( Parent->ui->HIRSElemPlot->canvas() );
   QwtPlotMagnifier *zoom_x3 = new QwtPlotMagnifier( Parent->ui->HIRSElemPlot->canvas()  );
   QwtPlotMagnifier *zoom_y3 = new QwtPlotMagnifier( Parent->ui->HIRSElemPlot->canvas()  );
   zoom_x3->setWheelModifiers(Qt::ControlModifier);
   zoom_x3->setAxisEnabled(Qt::XAxis, true);
   zoom_x3->setAxisEnabled(Qt::YAxis,false);

   zoom_y3->setAxisEnabled(Qt::XAxis,false);
   zoom_y3->setAxisEnabled(Qt::YAxis,true);

   (void )new QwtPlotPanner( Parent->ui->HIRSRawPlot->canvas() );
   QwtPlotMagnifier *zoom_x = new QwtPlotMagnifier( Parent->ui->HIRSRawPlot->canvas()  );
   QwtPlotMagnifier *zoom_y = new QwtPlotMagnifier( Parent->ui->HIRSRawPlot->canvas()  );
   zoom_x->setWheelModifiers(Qt::ControlModifier);
   zoom_x->setAxisEnabled(Qt::XAxis, true);
   zoom_x->setAxisEnabled(Qt::YAxis,false);

   zoom_y->setAxisEnabled(Qt::XAxis,false);
   zoom_y->setAxisEnabled(Qt::YAxis,true);
   }

void HIRS::processHIRS()
   {
   plotHIRSMirrorScanPos();
   plotHIRSElements();
   for(int i=2; i < HIRS_WORDS_PER_FRAME; i++)
      plotHIRSElement(i);
   }

void HIRS::plotHIRSElements()
   {
   QwtPlotCurve *curve1 = new QwtPlotCurve("Element Number");
   QwtSymbol *marker = new QwtSymbol;
   double *xPoints1, *yPoints1;

   QwtPlotCurve *curve2 = new QwtPlotCurve("Period Monitor");
   QwtSymbol *marker2 = new QwtSymbol;
   double *xPoints2, *yPoints2;

   xPoints1 = new double[HIRSstream[1].length()];
   yPoints1 = new double[HIRSstream[1].length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < HIRSstream[1].length(); point++)
      {
      yPoints1[point] = (HIRSstream[1][point] >> 1) & 63;
      xPoints1[point] = HIRSTime[1][point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[1], &yPoints1[1], HIRSstream[1].length());
   curve1->setPen( QColor( "blue" ) );

   marker->setStyle(QwtSymbol::Ellipse);
   marker->setSize(4);
   marker->setColor(QColor( "purple" ));
   marker->setPen(QColor( "cyan" ));
   curve1->setStyle( QwtPlotCurve::NoCurve );
   curve1->setSymbol(marker);

   curve1->attach(Parent->ui->HIRSElemPlot);

   xPoints2 = new double[HIRSstream[1].length()];
   yPoints2 = new double[HIRSstream[1].length()];

   for(int point=0; point < HIRSstream[1].length(); point++)
      {
      yPoints2[point] = HIRSstream[1][point] >> 7;
      xPoints2[point] = HIRSTime[1][point];
      }

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], HIRSstream[1].length());
   curve2->setPen( QColor( "orange" ) );

   marker2->setStyle(QwtSymbol::Ellipse);
   marker2->setSize(4);
   marker2->setColor(QColor( "purple" ));
   marker2->setPen(QColor( "orange" ));
   curve2->setStyle( QwtPlotCurve::NoCurve );
   curve2->setSymbol(marker2);

   curve2->attach(Parent->ui->HIRSElemPlot);

   Parent->ui->HIRSElemPlot->autoFillBackground();

   // finally, refresh the plot
   Parent->ui->HIRSElemPlot->axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating,true);
   Parent->ui->HIRSElemPlot->axisScaleEngine(QwtPlot::yLeft)->setAttribute(QwtScaleEngine::Floating,true);
   Parent->ui->HIRSElemPlot->replot();
   Parent->ui->HIRSElemPlot->show();
   }

void HIRS::plotHIRSMirrorScanPos()
   {
   QwtPlotCurve *curve1 = new QwtPlotCurve("all HIRS");
   QwtSymbol *marker = new QwtSymbol;
   double *xPoints1, *yPoints1;

   QwtPlotCurve *curve2 = new QwtPlotCurve("Cal Level Indicator");
   QwtSymbol *marker2 = new QwtSymbol;
   double *xPoints2, *yPoints2;

   xPoints1 = new double[HIRSstream[0].length()];
   yPoints1 = new double[HIRSstream[0].length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < HIRSstream[0].length(); point++)
      {
      yPoints1[point] = HIRSstream[0][point] >> 5; //bitshift(uint16(HIRSwords(:,1)),-5)
      xPoints1[point] = HIRSTime[0][point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], HIRSstream[0].length());
   curve1->setPen( QColor( "blue" ) );

   marker->setStyle(QwtSymbol::Ellipse);
   marker->setSize(4);
   marker->setColor(QColor( "purple" ));
   marker->setPen(QColor( "cyan" ));
   curve1->setStyle( QwtPlotCurve::NoCurve );
   curve1->setSymbol(marker);

   curve1->attach(Parent->ui->HIRSScanPosPlot);

   xPoints2 = new double[HIRSstream[0].length()];
   yPoints2 = new double[HIRSstream[0].length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < HIRSstream[0].length(); point++)
      {
      yPoints2[point] = HIRSstream[0][point] & 0x1F;
      xPoints2[point] = HIRSTime[0][point];
      }

   curve2->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve2->setRawSamples(&xPoints2[0], &yPoints2[0], HIRSstream[0].length());
   curve2->setPen( QColor( "orange" ) );

   marker2->setStyle(QwtSymbol::Ellipse);
   marker2->setSize(4);
   marker2->setColor(QColor( "purple" ));
   marker2->setPen(QColor( "orange" ));
   curve2->setStyle( QwtPlotCurve::NoCurve );
   curve2->setSymbol(marker2);

   curve2->attach(Parent->ui->HIRSScanPosPlot);

   Parent->ui->HIRSScanPosPlot->autoFillBackground();

   // finally, refresh the plot
   Parent->ui->HIRSScanPosPlot->axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating,true);;
   Parent->ui->HIRSScanPosPlot->axisScaleEngine(QwtPlot::yLeft)->setAttribute(QwtScaleEngine::Floating,true);;
   Parent->ui->HIRSScanPosPlot->replot();
   Parent->ui->HIRSScanPosPlot->show();
   }

void HIRS::plotHIRSElement(int identToPlot)
   {
   QwtPlotCurve *curve1 = new QwtPlotCurve("Raw Filter Data");

   double *xPoints1, *yPoints1;


   xPoints1 = new double[HIRSstream[identToPlot].length()];
   yPoints1 = new double[HIRSstream[identToPlot].length()];

   //for(int frame=0, igood=0, ibad=0; frame < numFrames; frame++)
   for(int point=0; point < HIRSstream[identToPlot].length(); point++)
      {
      yPoints1[point] = HIRSstream[identToPlot][point];
      xPoints1[point] = HIRSTime[identToPlot][point];
      }

   curve1->setRenderHint(QwtPlotItem::RenderAntialiased, true);
   curve1->setRawSamples(&xPoints1[0], &yPoints1[0], HIRSstream[identToPlot].length());

   curve1->setPen( QColor( "red" ).darker(identToPlot*10+50) );

   curve1->attach(Parent->ui->HIRSRawPlot);

   Parent->ui->HIRSRawPlot->autoFillBackground();

   // finally, refresh the plot
   Parent->ui->HIRSRawPlot->axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating,true);;
   Parent->ui->HIRSRawPlot->axisScaleEngine(QwtPlot::yLeft)->setAttribute(QwtScaleEngine::Floating,true);;
   Parent->ui->HIRSRawPlot->replot();
   Parent->ui->HIRSRawPlot->show();
   }

void HIRS::clearAll()
   {
   for(int i=0; i < HIRS_WORDS_PER_FRAME; i++)
      {
      HIRSstream[i].clear();
      HIRSTime[i].clear();
      }
   //frameQualityList.clear; //we do need this because we need to know if we can trust the contrast/brightness calc for individual pixels
   }

void HIRS::addHIRSFrame(uchar *HIRSBytes, float *frameTime, uchar *frameChunkQuality)
   {
   //When we get passed a frame, we need to dissect it into the HIRS_BYTES_PER_FRAME parts, we need
   //to assign a quality based on 5 chunks to each part (giving each byte a quality based on the
   //larger chunk will just make our life easier later becacuse we will soon lose sight of where
   //each byte came from as this is an independant subcommutated stream. The same goes for time,
   //we need to interpolate through to assign each byte a time.

   //Assume MSB first, LSBs second like this (i<<8 + (i+1))
   QString windowContents, hexStr;
   uint32_t HIRSword;
   uchar offset = 0;
   //uchar k=0;
   //i=> the HIRS word number (0-22)
   //j=> The HIRS byte number used to index the uchar array

   hexStr.sprintf("%04.2f\t",frameTime[0]);
   windowContents.append(hexStr);

   for(int i=0; i < HIRS_WORDS_PER_FRAME; i++)
      {
      HIRSword = 0;
      //k=0;
      for(int j=((i*13)/8); j <= (((i+1)*13)/8); j++)
         {         
         HIRSword = HIRSword << 8;
         HIRSword |= HIRSBytes[j];
         //HIRSword |= uint32_t(HIRSBytes[j]) << (8*k);
         //k++;
         }
      offset = 8 - ((13*(i+1)) % 8); //mod tells us how many bits into the last byte we ARE using, and we want to shift out the bits that we AREN'T using, so we substract it from 8
      HIRSword = HIRSword >> offset; //shift out the bits not used (they're the MSB of the next word)
      HIRSword &= 0x1FFF; //finally mask out only the 13 wanted bits to remove LSB's of the previous word

      if( i>1 && (HIRSword >> 12 == 0)) //sign bit is 0, means negative number
         HIRSstream[i].append(-(HIRSword & 0xFFF));
      else if( i>1 && (HIRSword >> 12 == 1)) //sign bit is 1, means positive number
         HIRSstream[i].append((HIRSword & 0xFFF));
      else //unsigned element
         HIRSstream[i].append(HIRSword);

      HIRSTime[i].append(frameTime[(i*13)/8]); //use time of whichever byte the first bit was in

      hexStr.sprintf("%04X:%04X\t",HIRSword,HIRSstream[i].last()&0x1FFF);
      windowContents.append(hexStr);
      }
   Parent->ui->HIRSRawHex->appendPlainText(windowContents);
   //frameIDList.append(frameID);
   //frameQualityList.append(frameGood);
   //frameTimeList.append(frameTime);
   //22 words with 2 left over status bits (23 words)
   }




