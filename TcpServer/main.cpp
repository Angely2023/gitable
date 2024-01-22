#include "widget.h"
#include "tcpserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Widget w;
//    w.show();

    TcpServer t;
    t.show();


    return a.exec();
}
