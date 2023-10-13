
#include "navigationssystem.h"
#include "test.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Navigationssystem w;
    w.show();

    Test test;
    QTest::qExec(&test);
    return a.exec();
}
