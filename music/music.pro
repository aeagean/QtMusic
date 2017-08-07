TEMPLATE = app

QT += core
QT += qml quick multimedia
CONFIG += c++11

SOURCES += main.cpp \
    Service/FileBrowser/FileBrowserService.cpp \
    Model/MediaPlayControl/MusicPlayControl.cpp \
    Model/FileBrowser/FileBrowserModel.cpp

RESOURCES += qml.qrc \
    resource.qrc
INCLUDEPATH += Model/MediaPlayControl \
    Model/FileBrowser \
    Service/FileBrowser/
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    MediaPlayControl/MusicPlayControl.h \
    Service/FileBrowser/FileBrowserService.h \
    Model/MediaPlayControl/MusicPlayControl.h \
    Model/FileBrowser/FileBrowserModel.h
