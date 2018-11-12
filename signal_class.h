#ifndef SIGNAL_CLASS_H
#define SIGNAL_CLASS_H
#include "QtCore"
#include "QObject"
#include "QDebug"

class QCSignalClass:public QObject
{
    Q_OBJECT
public:
    QCSignalClass()
    {}
signals:
    void signal_fun_no_param();
    void signal_fun_with_param(int);
    void signal_fun_with_param(int ,int );

public slots:
    void receive_no_param()
    {
        qDebug()<<"the slots received the no param function"<<endl;
    }
    void receive_with_param(int num)
    {
        qDebug()<<num<<endl;
    }
    void receive_with_param(int num_one,int num_two )
    {
        qDebug()<<num_one<<" "<<num_two<<endl;
    }
private slots:
    void receive_self_signal()
    {
        qDebug()<<"private slots received own signal"<<endl;
    }
};








#endif // SIGNAL_CLASS_H
