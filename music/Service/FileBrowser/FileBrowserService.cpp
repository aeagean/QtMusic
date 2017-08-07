#include "FileBrowserService.h"

FileBrowserService * FileBrowserService::_instance = NULL;

FileBrowserService *FileBrowserService::instance()
{
    if (_instance == NULL) {
        _instance = new FileBrowserService();
    }
    return _instance;
}

FileBrowserService::FileBrowserService()
{

}
