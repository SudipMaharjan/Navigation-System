
#include "test.h"
#include "poi.h"
#include "ort.h"
#include "QtTest/qtestcase.h"

void Test::testSaarbruekenCottbus(){
    PoI saarbrueken = PoI("Saarbrueken",49.2382, 6.9975, "Stadt", UNKNOWN);
    PoI Cottbus = PoI("Cottbus",51.756744,14.335731,"Stadt",UNKNOWN);
    double distance = saarbrueken.getDistance(Cottbus);
    QCOMPARE(distance,589.395897108);
}
void Test::testKielMuenchen(){
    PoI kiel = PoI("Kiel",54.3233, 10.1228, "Stadt", UNKNOWN);
    PoI muenchen = PoI("Muenchen",48.1351,11.5820,"Stadt",UNKNOWN);
    double distance = kiel.getDistance(muenchen);
    QCOMPARE(distance,695.51658043);
}
void Test::testBerlinMainz(){
    PoI berlin = PoI("Berlin",52.5200, 13.4050, "Stadt", UNKNOWN);
    PoI mainz = PoI("Mainz",49.9929,8.2473,"Stadt",UNKNOWN);
    double distance = berlin.getDistance(mainz);
    QCOMPARE(distance,455.649030796);
}
void Test::testStuttgartHamburg(){
    PoI stuttgart = PoI("stuttgart",48.7758, 9.1829, "Stadt", UNKNOWN);
    PoI hamburg = PoI("hamburg",53.5488,9.9872,"Stadt",UNKNOWN);
    double distance = stuttgart.getDistance(hamburg);
    QCOMPARE(distance,533.678970746);
}
