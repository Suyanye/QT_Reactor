#include "readevent.h"

#include <QString>

ReadEvent::ReadEvent()
{

}

void ReadEvent::eventHandler(QTcpSocket *socket)
{
    QString message;

    QDataStream in(socket);
    // 设置数据流版本，这里要和服务器端相同
    in.setVersion(QDataStream::Qt_5_9);

    in >> message;
    // 显示接收到的数据
    qDebug() << message;

    emit signalSendData(socket);
}
