#include <QCoreApplication>
#include "signal_class.h"
#include "newspaper.h"
#include "reader.h"

#include "QObject"
int main(int argc, char *argv[])
{
    //类里面信号和槽函数的连接
    QCoreApplication a(argc, argv);
    QCSignalClass m_signal;

    //connect的第一种写法
    QObject::connect(&m_signal,SIGNAL(signal_fun_with_param(int)),&m_signal,SLOT(receive_with_param(int)));
    emit m_signal.signal_fun_with_param(5);


    //connect的第二种写法
    QObject::connect(&m_signal,&QCSignalClass::signal_fun_no_param,&m_signal,&QCSignalClass::receive_no_param);
    emit m_signal.signal_fun_no_param();

    //connect的第三种写法，主要针对重载函数，怎么说，其实没完善好，不建议使用第一或第二种
    QObject::connect(&m_signal,QOverload<int,int>::of(&QCSignalClass::signal_fun_with_param),&m_signal,QOverload<int,int>::of(&QCSignalClass::receive_with_param));
    emit m_signal.signal_fun_with_param(6,7);

    QCNewsPaper newspaper("Newpaper A");
    QCReader reader;
    QObject::connect(&newspaper,&QCNewsPaper::newPaper,&reader,&QCReader::receiveNewspaper);
    newspaper.send();

    //类与类之间的连接
    QObject::connect(&newspaper,&QCNewsPaper::send_signal_no_param,&m_signal,&QCSignalClass::receive_no_param);
    emit newspaper.send_signal_no_param();



    return a.exec();
}
