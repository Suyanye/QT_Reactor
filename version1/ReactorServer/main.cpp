#include "reactorserver.h"
#include <QApplication>

#include "serversocket.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ReactorServer w;
    w.show();

    return a.exec();
}
