#include "connectserver.h"

#include <QString>
#include <QDebug>
#include <QDataStream>


ConnectServer::ConnectServer()
{
    m_socket = new QTcpSocket(this);

    connect(m_socket, &QTcpSocket::readyRead,
            this, &ConnectServer::slotReadData);
    connect(m_socket, &QTcpSocket::disconnected,
            m_socket, &QTcpSocket::deleteLater);

    m_socket->abort();

    m_socket->connectToHost(tr("127.0.0.1"), 6666);

    connect(m_socket, &QTcpSocket::connected,
            this, &ConnectServer::slotSendData);
}

void ConnectServer::slotReadData()
{
    QString data;
    QDataStream in(m_socket);

    in.setVersion(QDataStream::Qt_5_9);

    in >> data;

    qDebug() << data;
}

void ConnectServer::slotSendData()
{

    QByteArray dataByte;

    QDataStream out(&dataByte, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_9);
    out << tr("你知不知道你是猪");

    out.device()->seek(0);

    m_socket->write(dataByte);
}
