#ifndef NEWSPAPER_H
#define NEWSPAPER_H
#include "QObject"
#include "qstring.h"
class QCNewsPaper:public QObject
{
    Q_OBJECT
public:
    QCNewsPaper(const QString& name):
        m_name(name)
    {

    }
    void send()
    {
        emit newPaper(m_name);
    }
signals:
    void send_signal_no_param();
    void newPaper(const QString& name);
private:
    QString m_name;
};
#endif // NEWSPAPER_H
