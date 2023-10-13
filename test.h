
#ifndef TEST_H
#define TEST_H


#include <QObject>
#include <QtTest/QTest>


class Test:public QObject
{
    Q_OBJECT
private slots:
    void testSaarbruekenCottbus();
    void testKielMuenchen();
    void testBerlinMainz();
    void testStuttgartHamburg();
};

#endif // TEST_H
