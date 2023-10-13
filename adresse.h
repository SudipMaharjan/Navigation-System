#ifndef ADRESSE_H
#define ADRESSE_H

#include "ort.h"

class Adresse : public Ort
{
private:
    string strasse;
    int hausnummer;
    int postleitzahl;
    string stadt;

public:
    Adresse(string name, double latitude, double longitude, string str, int hnummer, int plz, string std);
    ~Adresse();
    QString printQString() override;
    QString printInformation() override;
    void binaryExport(ofstream &outfile) override;
    void txtExport(ofstream &outfile) override;
    string getStrasse() const;
    int getHausnummer() const;
    int getPostleitzahl() const;
    string getStadt() const;
};

#endif // ADRESSE_H
