#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T19:21:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TelemExplorer
TEMPLATE = app

include ( c:/qwt-6.1.3/features/qwt.prf )

SOURCES += main.cpp\
        mainwindow.cpp sem.cpp

HEADERS  += mainwindow.h sem.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../qwt-6.1.3/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../qwt-6.1.3/lib/ -lqwtd

INCLUDEPATH += $$PWD/../../../../../qwt-6.1.3/include
DEPENDPATH += $$PWD/../../../../../qwt-6.1.3/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../qwt-6.1.3/designer/plugins/designer/ -lqwt_designer_plugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../qwt-6.1.3/designer/plugins/designer/ -lqwt_designer_plugind
else:unix: LIBS += -L$$PWD/../../../../../qwt-6.1.3/designer/plugins/designer/ -lqwt_designer_plugin

INCLUDEPATH += $$PWD/../../../../../qwt-6.1.3/designer/plugins/designer
DEPENDPATH += $$PWD/../../../../../qwt-6.1.3/designer/plugins/designer
