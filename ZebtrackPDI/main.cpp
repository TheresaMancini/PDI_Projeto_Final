#include "zebtrackpdi.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZebtrackPDI w;
    w.show();

    return a.exec();
}
