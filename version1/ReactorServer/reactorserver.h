#ifndef REACTORSERVER_H
#define REACTORSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

#include "serversocket.h"
#include "connectevent.h"
#include "readevent.h"
#include "writeevent.h"
#include "closeevent.h"

namespace Ui {
class ReactorServer;
}

class ReactorServer : public QWidget
{
    Q_OBJECT

public:
    explicit ReactorServer(QWidget *parent = 0);
    ~ReactorServer();

public slots:
    void slotNewConnection();

    void slotReadyRead();

    void slotSendData();

    void slotCloseSocket();

    void slotGetSocket(QTcpSocket *socket);

signals:
    void signalNewConnection(QTcpServer *socket);

    void signalReadyRead(QTcpSocket *socket);

private:
    Ui::ReactorServer *ui;

    QTcpServer *m_serverSocket;

    QList<QTcpSocket *> m_clientSocketList;

    ReadEvent *m_readEvent;

    WriteEvent *m_writeEvent;

    ConnectEvent *m_connectEvent;

    CloseEvent *m_closeEvent;

};

#endif // REACTORSERVER_H
