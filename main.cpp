#include <QCoreApplication>
#include "signal_class.h"
#include "newspaper.h"
#include "reader.h"

#include "QObject"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCSignalClass m_signal;
    QObject::connect(&m_signal,&QCSignalClass::signal_fun_no_param,&m_signal,&QCSignalClass::receive_no_param);
    emit m_signal.signal_fun_no_param();
    QObject::connect(&m_signal,&QCSignalClass::signal_fun_with_param,&m_signal,&QCSignalClass::receive_wit_param);
    emit m_signal.signal_fun_with_param(5);



    QCNewsPaper newspaper("Newpaper A");
    QCReader reader;
    QObject::connect(&newspaper,&QCNewsPaper::newPaper,&reader,&QCReader::receiveNewspaper);
    newspaper.send();

    QObject::connect(&newspaper,&QCNewsPaper::send_signal_no_param,&m_signal,&QCSignalClass::receive_no_param);
    emit newspaper.send_signal_no_param();


    return a.exec();
}
