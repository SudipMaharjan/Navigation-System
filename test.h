#ifndef TEST_H
#define TEST_H

#include <QtTest/QTest>

class Test : public QObject
{
    Q_OBJECT
public:
    Test();

private slots:
    void testDistanceKielMuenchen();
    void testDistancePassauBerlin();
    void testDistanceHamburgFrankfurt();
};

#endif // TEST_H
