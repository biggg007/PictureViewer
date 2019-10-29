#ifndef IMAGEFILEMSG_H
#define IMAGEFILEMSG_H

#include <QObject>
#include <qfileinfo.h>
#include <QFileDialog>

class ImageFileMsg : public QObject
{
    Q_OBJECT

//   Q_PROPERTY(QString selpath READ get_image_name WRITE set_image_file_path)

public:
    explicit ImageFileMsg(QObject *parent = nullptr);

    Q_INVOKABLE void set_image_file_path(const QString &selpath);
    Q_INVOKABLE QString get_next_image_path();
    Q_INVOKABLE QString get_previous_image_path();
    Q_INVOKABLE QString get_image_name();
    int     get_image_count(){return m_image_count;}
    int     get_image_cur_index(){return m_current_image_index;}
    void    image_file_list();

signals:

public slots:

private:
    QString m_dir_path;
    QString filename;
    int     m_current_image_index;
    int     m_image_count;

    QFileInfoList m_image_infolist;

};

#endif // IMAGEFILEMSG_H
