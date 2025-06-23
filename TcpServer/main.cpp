#include "tcpserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    opeDB::getInstance().init();
    Tcpserver w;
    w.show();
    return a.exec();
}
