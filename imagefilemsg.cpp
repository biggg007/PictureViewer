#include <qimage.h>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QStringList>
#include "imagefilemsg.h"

ImageFileMsg::ImageFileMsg(QObject *parent) : QObject(parent)
{

}

QString ImageFileMsg::get_next_image_path()
{
    if(m_current_image_index >= m_image_count - 1)
        m_current_image_index = 0;
    else
        m_current_image_index ++;

//    qDebug()<<"The next image path:"<<m_current_image_index;
    return get_image_name();
}

QString ImageFileMsg::get_previous_image_path()
{          
    if(m_current_image_index <= 0)
        m_current_image_index = m_image_count - 1;
    else
        m_current_image_index --;

    return get_image_name();
}

QString ImageFileMsg::get_image_name()
{
    qDebug()<<"ImageFileMsg::get_image_name() "<<m_image_infolist.at(m_current_image_index).fileName();
    return m_image_infolist.at(m_current_image_index).fileName();
}

void ImageFileMsg::image_file_list()
{
    m_image_infolist.clear();

    QDir dir(m_dir_path,"Images (*.png *.bmp *.jpg *.gif)");

    m_image_infolist = dir.entryInfoList( );
    m_image_count = m_image_infolist.count();
    m_current_image_index = 0;
}

void ImageFileMsg::set_image_file_path(const QString &path)
{
    if(nullptr != path)
        m_dir_path = path;
    else{
         qDebug()<<"Wrong path!";
         return;
    }

    qDebug()<<"Set dir path:"<<m_dir_path;

    image_file_list();
}
