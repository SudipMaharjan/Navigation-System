
#include "test.h"
#include "ort.h"

Test::Test()
{

}

void Test::testDistanceKielMuenchen() {
    Ort* kiel = new Ort("Kiel", 10.1228, 54.3233);
    Ort* muenchen= new Ort("Muenchen", 11.5820, 48.1351);

    double actualDistance = 693.14;
    double calculatedDistance = kiel->getDistance(*muenchen);
    double tolerance = actualDistance * 0.05;


    QVERIFY(fabs(calculatedDistance - actualDistance) <= tolerance);
}

void Test::testDistancePassauBerlin() {
    Ort* passau = new Ort("Passau", 13.4319, 48.5667);
    Ort* berlin = new Ort("Berlin", 13.4050, 52.5200);

    double actualDistance = 439.11;
    double calculatedDistance = passau->getDistance(*berlin);
    double tolerance = actualDistance * 0.05;

    QVERIFY(fabs(calculatedDistance - actualDistance) <= tolerance);
}

void Test::testDistanceHamburgFrankfurt() {
    Ort* hamburg = new Ort("Hamburg", 9.9872, 53.5488);
    Ort* frankfurt = new Ort("Frankfurt", 8.6821, 50.1109);

    double actualDistance = 404.96;
    double calculatedDistance = hamburg->getDistance(*frankfurt);
    double tolerance = actualDistance * 0.05;

    QVERIFY(fabs(calculatedDistance - actualDistance) <= tolerance);
}
