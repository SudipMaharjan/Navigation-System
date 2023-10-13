
#ifndef POI_H
#define POI_H

#include "ort.h"
enum category{
    TANKSTELLE=0,
    RESTAURANT,
    SEHENSWUERDIGKEIT,
    COMMON_PLACE,
    UNKNOWN,
};
class PoI : public Ort
{
private:
    string bemerkung;
    category kategorie;

public:
    PoI(string name, double latitude, double longitude, string bemerkung, category cat);
    ~PoI() override;
    QString printQString() override;
    QString printInformation() override;
    string getBemerkung()const;
    category getKategorie()const;
    void binaryExport(ofstream &outfile) override;
    void txtExport(ofstream &outfile) override;
};

QString categoryToQString(category);

#endif // POI_H
