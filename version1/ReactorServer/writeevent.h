#ifndef WRITEEVENT_H
#define WRITEEVENT_H

#include <QObject>
#include <QTcpSocket>

#include "abstractevent.h"

class WriteEvent :public QObject, public AbstractEvent
{
    Q_OBJECT

public:
    WriteEvent();

public slots:
    void eventHandler(QTcpSocket *socket);
};

#endif // WRITEEVENT_H
