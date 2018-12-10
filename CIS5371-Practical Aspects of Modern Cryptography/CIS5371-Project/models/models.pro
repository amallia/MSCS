TARGET = model
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers DESobjects ElGamalobjects
DEPENDPATH  += ../helpers DESobjects ElGamalobjects
LIBS += -L../lib -lhelper
LIBS += -L/home/chris/Dropbox/MSCS/'CIS5371-Practical Aspects of Modern Cryptography'/CIS5371-DES/Release -l des
LIBS += -L/home/chris/Dropbox/MSCS/'CIS5371-Practical Aspects of Modern Cryptography'/CIS5371-ElGamel/Release -l ElGamal
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
