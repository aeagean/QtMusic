TEMPLATE = app

QT += qml quick
QT += multimedia
CONFIG += c++11

SOURCES += main.cpp \
    FileListViewModel.cpp \
    MediaPlayControl/MusicPlayControl.cpp

RESOURCES += qml.qrc
INCLUDEPATH += MediaPlayControl
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    FileListViewModel.h \
    MediaPlayControl/MusicPlayControl.h
