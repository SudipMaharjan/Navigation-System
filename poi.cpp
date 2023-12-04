#include "poi.h"

PoI::PoI(string name, double latitude, double longitude, string bemerkung, category cat) : Ort(name, latitude,longitude)
{
    this->bemerkung = bemerkung;
    kategorie = cat;
}

QString PoI::printQString() {

    QString attribut =QString("%1").arg(QString::number(getID()), -20);
    attribut += QString("%1").arg("PoI", -20);;
    attribut += QString("%1").arg(QString::fromStdString(getName()), -20);
    attribut += QString("%1").arg(QString::number(getLatitude()), -20);
    attribut += QString("%1").arg(QString::number(getLongitude()), -20);
    attribut += QString::fromStdString(bemerkung) + ", ";
    attribut += categoryToQString(kategorie);
    return attribut;
}

QString PoI::printInformation() {

    QString att ="ID: " + QString::number(getID()) + "\nTyp: " + "PoI\n";
    att += "name: " + QString::fromStdString(getName()) + "\n";
    att += "latitude: " + QString::number(getLatitude()) + "\n";
    att += "longitude: " + QString::number(getLongitude())+ "\n";
    att += "bemerkung: " + QString::fromStdString(bemerkung) + "\n";
    att += "kategorie: " + categoryToQString(kategorie) + "\n";

    return att;
}

PoI::~PoI() {

}
string PoI::getBemerkung()const{
    return bemerkung;
}
category PoI::getKategorie()const{
    return kategorie;
}
void PoI::binaryExport(ofstream &outfile)
{
    if(!outfile.is_open())
        return;
    BbaseWriter(outfile, 2);
    int Bsize = bemerkung.size();
    outfile.write((char*) &Bsize, sizeof(Bsize));
    outfile.write((char*) bemerkung.c_str(), Bsize);
    int categoryType = kategorie;
    outfile.write((char*) &categoryType, sizeof(int));
}

void PoI::txtExport(ofstream &outfile)
{
    if(!outfile.is_open())
        return;
    TbaseWriter(outfile, 2);
    outfile<<getBemerkung()<<';';
    outfile <<getKategorie()<<endl;
}
QString categoryToQString(category kategorie){
    QString cat;
    if(kategorie ==TANKSTELLE)
        cat = "TANKSTELLE";
    else if(kategorie ==RESTAURANT)
        cat = "RESTAURANT";
    else if(kategorie ==SEHENSWUERDIGKEIT)
        cat = "SEHENSWUERDIGKEIT";
    else if(kategorie ==COMMON_PLACE)
        cat = "COMMON_PLACE";
    else
        cat = "UNKNOWN";

    return cat;
}

QString PoI::getTyp() {return "PoI";}

QString PoI::getParameters() const{
    QString parameter = QString::fromStdString(bemerkung);
    parameter += categoryToQString(kategorie);
    return parameter;
}
