#ifndef ORT_H
#define ORT_H
#include <iostream>
#include <fstream>
#include<iomanip>
#include<QString>
#include<map>
using namespace std;


class Ort
{
private:
    string name;
    const double latitude;
    const double longitude;
    const int ID;
    bool visited = false;
    std::map<Ort*,double>distances;

protected:
    void BbaseWriter(ofstream &outfile, int i);
    void TbaseWriter(ofstream &outfile, int i);


public:
    Ort(string name, double latitude, double longitude);
    virtual ~Ort();
    virtual QString printQString();
    virtual QString printInformation();
    double getDistance(Ort& ort2);
    string getName()const;
    double getLongitude() const;
    double getLatitude() const;
    int getID() const;
    virtual void binaryExport(ofstream &outfile);
    virtual void txtExport(ofstream &outfile);
    bool isVisited();
    void setDistances(Ort*,double);
    virtual QString getTyp();
    virtual QString getParameters() const;
};

#endif // ORT_H
