#include "writeevent.h"

WriteEvent::WriteEvent()
{

}

void WriteEvent::eventHandler(QTcpSocket *socket)
{
    // 用于暂存要发送的数据
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    // 设置数据流的版本，客户端和服务器端使用的版本要相同
    out.setVersion(QDataStream::Qt_5_9);

    out << tr("不知道 …… 知道 ……");

    socket->write(block);

    //发送完数据后断开连接
    socket->disconnectFromHost();

    // 发送数据成功后，显示提示
    qDebug() << "发送数据成功!!!";
}
