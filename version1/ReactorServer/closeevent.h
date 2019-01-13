#ifndef CLOSEEVENT_H
#define CLOSEEVENT_H

#include <QObject>
#include <QTcpSocket>

#include "abstractevent.h"

class CloseEvent : public QObject, public AbstractEvent
{
public:
    CloseEvent();

public slots:
    void eventHandler(QTcpSocket *socket);
};

#endif // CLOSEEVENT_H
