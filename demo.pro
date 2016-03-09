TEMPLATE = lib
QT -= gui
CONFIG += console warn_on plugin
CONFIG -= app_bundle

SDKPATH = $$PWD/SDK
QMAKE_CXXFLAGS += -DXPLM200=1
QMAKE_CXXFLAGS += -DXPLM210=1

INCLUDEPATH += $$SDKPATH/CHeaders/XPLM $$SDKPATH/CHeaders/Widgets
DEFINES += APL=0 IBM=1 LIN=0
LIBS += -L$$SDKPATH/Libraries/Win -lXPLM_64 -lXPWidgets_64

SOURCES += main.cpp
TARGET = testplugin
