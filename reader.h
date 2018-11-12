#ifndef READER_H
#define READER_H
#include "QObject"
#include "QDebug"

class QCReader:public QObject
{
public:
    Reader()
    {

    }
    void receiveNewspaper(const QString& name)
    {
        qDebug()<<"Receives Newspaper:"<<name;
    }
};
#endif // READER_H
