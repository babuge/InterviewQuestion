QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

include($${ProConfig}/AppConfig.pri)
include($${AppDir}/UiFrame/UiFrame.pri)

SOURCES += main.cpp



$$headersCopyFunc($${CommonDir}, App, $${AppDir}/UiFrame/TestListView/CommonTest.h)
