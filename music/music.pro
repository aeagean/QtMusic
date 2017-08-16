TEMPLATE = app

QT += core
QT += qml quick multimedia
CONFIG += c++11

SOURCES += main.cpp \
    Service/FileBrowser/FileBrowserService.cpp \
    Model/MediaPlayControl/MusicPlayControl.cpp \
    Model/FileBrowser/FileBrowserModel.cpp \
    Model/FileBrowser/FileBrowserListModel.cpp \
    Infrastructure/domain/BaseListModel.cpp \
    Infrastructure/domain/BaseItemModel.cpp \
    Infrastructure/Repertory/MusicRepertory.cpp \
    Service/Music/MusicListService.cpp \
    Domain/MusicBase.cpp \
    Service/Music/MusicSearchService.cpp \
    Model/MusicSearch/MusicSearchList.cpp \
    Model/MusicSearch/MusicSearch.cpp \
    Model/MusicInfo/MusicPlayListModel.cpp \
    Model/MusicInfo/MusicPlayModel.cpp \
    Infrastructure/domain/DomainObject.cpp

RESOURCES += qml.qrc \
    resource.qrc

INCLUDEPATH +=  Model/MediaPlayControl \
                Model/FileBrowser \
                Model/MusicInfo
INCLUDEPATH +=  Service/FileBrowser \
                Service/Music
INCLUDEPATH +=  Infrastructure/domain \
                Infrastructure/Repertory \
                Domain

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    MediaPlayControl/MusicPlayControl.h \
    Service/FileBrowser/FileBrowserService.h \
    Model/MediaPlayControl/MusicPlayControl.h \
    Model/FileBrowser/FileBrowserModel.h \
    Model/FileBrowser/FileBrowserListModel.h \
    Infrastructure/domain/ObjectListModelImpl.h \
    Infrastructure/domain/ObjectListModel.h \
    Infrastructure/domain/BaseListModel.h \
    Infrastructure/domain/BaseItemModel.h \
    Infrastructure/Repertory/MusicRepertory.h \
    Service/Music/MusicListService.h \
    Domain/MusicBase.h \
    Service/Music/MusicSearchService.h \
    Model/MusicSearch/MusicSearchList.h \
    Model/MusicSearch/MusicSearch.h \
    Model/MusicInfo/MusicPlayListModel.h \
    Model/MusicInfo/MusicPlayModel.h \
    Utils/JsonListConvertorImpl.h \
    Infrastructure/domain/DomainObject.h \
    Infrastructure/domain/JsonListConvertor.h \
    Infrastructure/domain/JsonListConvertorImpl.h
