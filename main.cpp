#include "widget.h"
#include "work.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Form Work;
    w.show();
    
    return a.exec();
}
