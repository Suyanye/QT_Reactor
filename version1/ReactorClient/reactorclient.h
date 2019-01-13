#ifndef REACTORCLIENT_H
#define REACTORCLIENT_H

#include <QWidget>
#include "connectserver.h"

namespace Ui {
class ReactorClient;
}

class ReactorClient : public QWidget
{
    Q_OBJECT

public:
    explicit ReactorClient(QWidget *parent = 0);
    ~ReactorClient();

private:
    Ui::ReactorClient *ui;

    ConnectServer *m_connectServer;
};

#endif // REACTORCLIENT_H
