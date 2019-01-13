#include "reactorclient.h"
#include "ui_reactorclient.h"

ReactorClient::ReactorClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReactorClient)
{
    ui->setupUi(this);

    m_connectServer = new ConnectServer();
}

ReactorClient::~ReactorClient()
{
    delete ui;
}
