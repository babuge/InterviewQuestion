QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

include($${ProConfig}/AppConfig.pri)
include($${AppDir}/UiFrame/UiFrame.pri)

SOURCES += main.cpp

# gtest
#if(win32){
#    if(mingw){
#        $$headersCopyFunc($${OUTLIB},"", $${ProjectRootDir}/3rdparty/GTest-1.8.x/lib/mingw/libgtest.dll)
#        LIBS += -L$${OUTLIB}/ -lgtest
#    } else {
#        $$headersCopyFunc($${OUTLIB},"", $${ProjectRootDir}/3rdparty/GTest-1.8.x/lib/win/libgtest.dll)
#        LIBS += $${OUTLIB}/libgtest.dll
#    }
#} esle {
#    $$headersCopyFunc($${OUTLIB},"", $${ProjectRootDir}/3rdparty/GTest-1.8.x/lib/linux/libgtest.so)
#    LIBS += -L$${OUTLIB}/ -lgtest
#}

INCLUDEPATH += $${ThridParty}/GTest-1.8.x/include
INCLUDEPATH += $${CommonDir}/TestModule

DEPENDPATH += $${OUTLIB}

$$headersCopyFunc($${CommonDir}, App, $${AppDir}/UiFrame/TestListView/CommonTest.h)
