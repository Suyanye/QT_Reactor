#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class ConnectServer : public QObject
{
    Q_OBJECT

public:
    ConnectServer();



public slots:

    void slotReadData();

    void slotSendData();

private:

    QTcpSocket *m_socket;
};

#endif // CONNECTSERVER_H
