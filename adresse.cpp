
#include "adresse.h"

Adresse::Adresse(string name, double latitude, double longitude, string str, int hnummer, int plz, string std) : Ort(name,latitude, longitude){
    strasse = str;
    hausnummer = hnummer;
    postleitzahl = plz;
    stadt = std;
}
Adresse::~Adresse(){

}

QString Adresse::printQString() {
    QString attribut =QString("%1").arg(QString::number(getID()), -20);
    attribut += QString("%1").arg("Adr", -20);;
    attribut += QString("%1").arg(QString::fromStdString(getName()), -20);
    attribut += QString("%1").arg(QString::number(getLatitude()), -20);
    attribut += QString("%1").arg(QString::number(getLongitude()), -20);
    attribut += QString::fromStdString(strasse) +  " ";
    attribut += QString::number(hausnummer) + ", ";
    attribut += QString::number(postleitzahl) + " ";
    attribut += QString::fromStdString(stadt);

    return attribut;
}
QString Adresse::printInformation(){
    QString att = "ID: " + QString::number(getID()) +"\nTyp: " + "Adr\n";
    att += "name: " + QString::fromStdString(getName()) + "\n";
    att += "latitude: " + QString::number(getLatitude()) + "\n";
    att += "longitude: " + QString::number(getLongitude()) + "\n";
    att += "strasse: " + QString::fromStdString(strasse) + "\n";
    att += "hausnummer: " + QString::number(hausnummer) + "\n";
    att += "postleitzahl: " + QString::number(postleitzahl) + "\n";
    att += "stadt: " + QString::fromStdString(stadt) + "\n";

    return att;
}

void Adresse::binaryExport(ofstream &outfile)
{
    if(!outfile.is_open())
        qDebug("falsch");
    BbaseWriter(outfile,1);
    int stringsize = strasse.size()+1;
    outfile.write((char*) &stringsize, sizeof(stringsize));
    outfile.write((char*) strasse.c_str(), stringsize);

    outfile.write((char*) &hausnummer, sizeof(hausnummer));
    outfile.write((char*) &postleitzahl, sizeof(postleitzahl));
    stringsize = stadt.size()+1;
    outfile.write((char*) &stringsize, sizeof(stringsize));
    outfile.write((char*) stadt.c_str(), stringsize);
}

void Adresse::txtExport(ofstream &outfile)
{
    if(!outfile.is_open())
        return;
    TbaseWriter(outfile,1);
    outfile << getStrasse()<<';';
    outfile << getHausnummer()<<';';
    outfile << getPostleitzahl()<<';';
    outfile <<  getStadt()<<endl;
}

string Adresse::getStrasse() const{return strasse;}

int Adresse::getHausnummer() const {return hausnummer;}

int Adresse::getPostleitzahl() const{return postleitzahl;}

string Adresse::getStadt() const{return stadt;}

QString Adresse::getTyp(){return "Adr";}

QString Adresse::getParameters() const{
    QString parameter = QString::fromStdString(strasse);
    parameter += QString::number(hausnummer);
    parameter += QString::number(postleitzahl);
    parameter += QString::fromStdString(stadt);
    return parameter;
}

