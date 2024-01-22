#include "widget.h"
#include "tcpclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Widget w;
//    w.show();

    TcpClient t;
    t.show();

    return a.exec();
}
