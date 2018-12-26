/**********************************************************
Author: 微信公众号(你才小学生)
WeChat public platform: nicaixiaoxuesheng
Email:  2088201923@qq.com
**********************************************************/
#ifndef FILEBROWSERSERVICE_H
#define FILEBROWSERSERVICE_H

#include <QDir>
#include <QObject>

class FileBrowserService : public QObject
{
    Q_OBJECT
public:
    static FileBrowserService* instance();

    QStringList getCurrentPathNameList();
    QString getCurrentFullPathNameList();
    void cdNextPath(QString currentPathName);
    void cdPath(QString pathName);
    void cdPath(int indexPath); /*/home/user/music*/
                         /*index->  2    1     0   index == 1 ->/home/user*/

private:
    FileBrowserService();

private:
    static FileBrowserService* _instance;
    QDir m_dir;
};

#endif // FILEBROWSERSERVICE_H
