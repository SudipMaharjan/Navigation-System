#include "ort.h"
#include <math.h>
#include <cmath>
#include<iomanip>

static int nextID = 1;

double Ort::getLongitude() const
{
    return longitude;
}

double Ort::getLatitude() const
{
    return latitude;
}

bool Ort::isVisited(){
    return visited;
}

string Ort::getName() const
{
    return name;
}

double Ort::getID() const
{
    return ID;
}

Ort::~Ort(){

}

void Ort::binaryExport(ofstream &outfile)
{
    BbaseWriter(outfile, 0);
}

void Ort::txtExport(ofstream &outfile)
{
    TbaseWriter(outfile, 0);
}


void Ort::BbaseWriter(ofstream &outfile,int i)
{
    if(outfile.is_open()){
        outfile.write((char*) &i, sizeof(i));

        unsigned int nameSize = name.length()+1;
        outfile.write((char*)(&nameSize),sizeof(nameSize));
        outfile.write(name.c_str(),nameSize);

        outfile.write((char*) &latitude, sizeof(latitude));
        outfile.write((char*) &longitude, sizeof(longitude));
        outfile.write((char*) &ID, sizeof(ID));
    }
}

void Ort::TbaseWriter(ofstream &outfile, int i)
{
    if(!outfile.is_open()){
        return;
    }
    outfile<< i<<';';
    outfile<<getName()<<';';
    outfile<<getLatitude()<<';';
    outfile<<getLongitude()<<';';
}

Ort::Ort(string name, double latitude, double longitude) : name(name), latitude(latitude), longitude (longitude), ID(nextID++){
}

QString Ort::printQString(){
    return "0";
}

QString Ort::printInformation(){
    return "0";
}

double deg2rad(double degree) {
    return degree/180 * M_PI;
}

double Ort::getDistance(Ort &ort2){
    double R = 6371; // Radius of the earth in km
    double diffY = deg2rad(getLatitude() - ort2.getLatitude());
    double diffX = deg2rad(getLongitude() - ort2.getLongitude());
    double a =
        sin(diffY/2) * sin(diffY/2) +
        cos(deg2rad(getLatitude())) * cos(deg2rad(ort2.getLatitude())) *
            sin(diffX/2) * sin(diffX/2)
        ;
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c; // Distance in km
    return distance;
}

void Ort::setDistances(Ort* ort,double dist){
    distances[ort] = dist;
}
