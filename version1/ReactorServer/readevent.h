#ifndef READEVENT_H
#define READEVENT_H

#include <QObject>
#include <QTcpSocket>

#include "abstractevent.h"

class ReadEvent : public QObject, public AbstractEvent
{
    Q_OBJECT

public:
    ReadEvent();

public slots:
    void eventHandler(QTcpSocket *socket);

signals:

    void signalSendData(QTcpSocket *socket);
};

#endif // READEVENT_H
