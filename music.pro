TEMPLATE = app

QT += core
QT += qml quick multimedia
CONFIG += c++11

SOURCES += main.cpp \
    Service/FileBrowser/FileBrowserService.cpp \
    Model/MediaPlayControl/MusicPlayControl.cpp \
    Model/FileBrowser/FileBrowserModel.cpp \
    Model/FileBrowser/FileBrowserListModel.cpp \
    infrastructure/domain/BaseListModel.cpp \
    infrastructure/domain/BaseItemModel.cpp \
    infrastructure/Repertory/MusicRepertory.cpp \
    Service/Music/MusicListService.cpp \
    Domain/MusicBase.cpp \
    Service/Music/MusicSearchService.cpp \
    Model/MusicSearch/MusicSearchList.cpp \
    Model/MusicSearch/MusicSearch.cpp \
    Model/MusicInfo/MusicPlayListModel.cpp \
    Model/MusicInfo/MusicPlayModel.cpp \
    infrastructure/domain/DomainObject.cpp \
    Model/MusicInfo/MusicLyricsListModel.cpp \
    Model/MusicInfo/MusicLyricsModel.cpp \
    infrastructure/utils/LyricsParse.cpp

RESOURCES += qml.qrc \
    resource.qrc

INCLUDEPATH +=  Model/MediaPlayControl \
                Model/FileBrowser \
                Model/MusicInfo
INCLUDEPATH +=  Service/FileBrowser \
                Service/Music
INCLUDEPATH +=  infrastructure/domain \
                infrastructure/Repertory \
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
    infrastructure/domain/ObjectListModelImpl.h \
    infrastructure/domain/ObjectListModel.h \
    infrastructure/domain/BaseListModel.h \
    infrastructure/domain/BaseItemModel.h \
    infrastructure/Repertory/MusicRepertory.h \
    Service/Music/MusicListService.h \
    Domain/MusicBase.h \
    Service/Music/MusicSearchService.h \
    Model/MusicSearch/MusicSearchList.h \
    Model/MusicSearch/MusicSearch.h \
    Model/MusicInfo/MusicPlayListModel.h \
    Model/MusicInfo/MusicPlayModel.h \
    Utils/JsonListConvertorImpl.h \
    infrastructure/domain/DomainObject.h \
    infrastructure/domain/JsonListConvertor.h \
    infrastructure/domain/JsonListConvertorImpl.h \
    Model/MusicInfo/MusicLyricsListModel.h \
    Model/MusicInfo/MusicLyricsModel.h \
    infrastructure/utils/LyricsParse.h
