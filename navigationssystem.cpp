#include "navigationssystem.h"
#include "anzeigen.h"
#include "anzeigen.h"
#include "ui_navigationssystem.h"
#include "adresse.h"
#include "poi.h"
#include <iostream>
#include "information.h"
#include <fstream>
#include <limits>
#include <queue>
#include <set>
#include<sstream>
#include<iomanip>
#include<cfloat>
#include "ImagePixel.h"
#include "showroute.h"


Navigationssystem::Navigationssystem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Navigationssystem)
{
    ui->setupUi(this);
    connect(ui->pushButtonAlleOrte,&QPushButton::clicked,this,&Navigationssystem::AlleOrte);
    connect(ui->pushButtonOrtAnlegen,&QPushButton::clicked,this,&Navigationssystem::OrtAnlegen);
    connect(ui->pushButtonOrtEntfernen,&QPushButton::clicked,this,&Navigationssystem::OrtEntfernen);
    connect(ui->pushButtonInformation,&QPushButton::clicked,this,&Navigationssystem::information);
    connect(ui->pushButtonExportieren,&QPushButton::clicked,this,&Navigationssystem::Exportieren);
    connect(ui->pushButtonImportieren,&QPushButton::clicked,this,&Navigationssystem::Importieren);
    connect(ui->pushButtonEntfernung,&QPushButton::clicked,this,&Navigationssystem::Entfernung);
    connect(ui->pushButtonRouting,&QPushButton::clicked,this,&Navigationssystem::Routing);
    connect(ui->pushButtonLaden,&QPushButton::clicked,this,&Navigationssystem::auffuellen);
}

Navigationssystem::~Navigationssystem()
{
    delete ui;
    for (auto &a : dynamicButtons){
        delete a;
        a = nullptr;
    }
    for (auto &b : erasedOrte){
        delete b;
        b = nullptr;
    }
    for (auto &c : erasedDynamicButtons){
        delete c;
        c = nullptr;
    }
    for(auto &d : erasedRoute){
        delete d;
        d = nullptr;
    }
}

Graph *Navigationssystem::getGraph(){
    return &graph;
}

void Navigationssystem::auffuellen(){
    if(graph.getAllOrt().size()==0){
        PoI* stuttgart = new PoI("Stuttgart", 48.7758, 9.1829, "Hauptstadt Baden-Württemberg", COMMON_PLACE);
        graph.addOrt(stuttgart);
        dynamicButtons.push_back(createDynamicButton("Stuttgart", 48.7758, 9.1829));

        PoI* muenchen = new PoI("Muenchen", 48.1351, 11.5820, "Hauptstadt Bayern",COMMON_PLACE);
        graph.addOrt(muenchen);
        dynamicButtons.push_back(createDynamicButton("Muenchen", 48.1351, 11.5820));

        PoI* berlin = new PoI("Berlin", 52.5200, 13.4050, "Hauptstadt Stadtstaat",COMMON_PLACE);
        graph.addOrt(berlin);
        dynamicButtons.push_back(createDynamicButton("Berlin", 52.5200, 13.4050));

        PoI* postdam = new PoI("Potsdam", 52.3906, 13.0645, "Hauptstadt Brandenburg",COMMON_PLACE);
        graph.addOrt(postdam);
        dynamicButtons.push_back(createDynamicButton("Potsdam", 52.3906, 13.0645));

        PoI* bremen = new PoI("Bremen", 53.0793, 8.8017, "Hauptstadt Stadtstaat",COMMON_PLACE);
        graph.addOrt(bremen);
        dynamicButtons.push_back(createDynamicButton("Bremen", 53.0793, 8.8017));

        PoI* hamburg = new PoI("Hamburg", 53.5488, 9.9872, "Hauptstadt Stadtstaat",COMMON_PLACE);
        graph.addOrt(hamburg);
        dynamicButtons.push_back(createDynamicButton("Hamburg", 53.5488, 9.9872));

        PoI* wiesbaden = new PoI("Wiesbaden", 50.0782, 8.2398, "Hauptstadt Hessen",COMMON_PLACE);
        graph.addOrt(wiesbaden);
        dynamicButtons.push_back(createDynamicButton("Wiesbaden", 50.0782, 8.2398));

        PoI* schwerin =new PoI("Schwerin", 53.6355, 11.4012, "Hauptstadt Mecklenburg-Vorpommern",COMMON_PLACE);
        graph.addOrt(schwerin);
        dynamicButtons.push_back(createDynamicButton("Schwerin", 53.6355, 11.4012));

        PoI* hannover = new PoI("Hannover", 52.3759, 9.7320, "Hauptstadt Niedersachsen",COMMON_PLACE);
        graph.addOrt(hannover);
        dynamicButtons.push_back(createDynamicButton("Hannover", 52.3759, 9.7320));

        PoI* duesseldorf = new PoI("Duesseldorf", 51.2277, 6.7735, "Hauptstadt Nordrhein-Westfalen",COMMON_PLACE);
        graph.addOrt(duesseldorf);
        dynamicButtons.push_back(createDynamicButton("Duesseldorf", 51.2277, 6.7735));

        PoI* mainz = new PoI("Mainz", 49.9929, 8.2473, "Hauptstadt Rheinland-Pfalz",COMMON_PLACE);
        graph.addOrt(mainz);
        dynamicButtons.push_back(createDynamicButton("Mainz", 49.9929, 8.2473));

        PoI* saarbruecken = new PoI("Saarbruecken", 49.2382, 6.9975, "Hauptstadt Saarland",COMMON_PLACE);
        graph.addOrt(saarbruecken);
        dynamicButtons.push_back(createDynamicButton("Saarbruecken", 49.2382, 6.9975));

        PoI* dresden = new PoI("Dresden", 51.0504, 13.7373, "Hauptstadt Sachsen",COMMON_PLACE);
        graph.addOrt(dresden);
        dynamicButtons.push_back(createDynamicButton("Dresden", 51.0504, 13.7373));

        PoI* magdeburg = new PoI("Magdeburg", 52.1205, 11.6276, "Hauptstadt Sachsen-Anhalt",COMMON_PLACE);
        graph.addOrt(magdeburg);
        dynamicButtons.push_back(createDynamicButton("Magdeburg", 52.1205, 11.6276));

        PoI* kiel = new PoI("Kiel", 54.3233, 10.1228, "Hauptstadt Schleswig-Holstein",COMMON_PLACE);
        graph.addOrt(kiel);
        dynamicButtons.push_back(createDynamicButton("Kiel", 54.3233, 10.1228));

        PoI* erfurt = new PoI("Erfurt", 50.9848, 11.0299, "Hauptstadt Thüringen",COMMON_PLACE);
        graph.addOrt(erfurt);
        dynamicButtons.push_back(createDynamicButton("Erfurt", 50.9848, 11.0299));

        PoI* chiemsee = new PoI("Chiemsee", 47.8709, 12.4537,"Großer See in Bayern",SEHENSWUERDIGKEIT);
        graph.addOrt(chiemsee);
        dynamicButtons.push_back(createDynamicButton("Chiemsee", 47.8709, 12.4537));

        PoI* bgh = new PoI("BGH", 49.0071, 8.3966, "Bundesgerichtshof",UNKNOWN);
        graph.addOrt(bgh);
        dynamicButtons.push_back(createDynamicButton("BGH", 49.0071, 8.3966));

        graph.addRoute(new Route(kiel,hamburg));
        graph.addRoute(new Route(kiel,schwerin));
        graph.addRoute(new Route(schwerin,berlin));
        graph.addRoute(new Route(berlin,postdam));
        graph.addRoute(new Route(berlin,dresden));
        graph.addRoute(new Route(magdeburg,postdam));
        graph.addRoute(new Route(magdeburg,hannover));
        graph.addRoute(new Route(hannover,bremen));
        graph.addRoute(new Route(bremen,hamburg));
        graph.addRoute(new Route(hamburg,schwerin));
        graph.addRoute(new Route(bremen,duesseldorf));
        graph.addRoute(new Route(duesseldorf,erfurt));
        graph.addRoute(new Route(dresden,erfurt));
        graph.addRoute(new Route(duesseldorf,wiesbaden));
        graph.addRoute(new Route(wiesbaden,mainz));
        graph.addRoute(new Route(mainz,saarbruecken));
        graph.addRoute(new Route(saarbruecken,stuttgart));
        graph.addRoute(new Route(stuttgart,muenchen));
        graph.addRoute(new Route(bgh,saarbruecken));
        graph.addRoute(new Route(bgh,stuttgart));
        graph.addRoute(new Route(muenchen,chiemsee));
        graph.addRoute(new Route(chiemsee,dresden));
        graph.addRoute(new Route(magdeburg,erfurt));
        graph.addRoute(new Route(hamburg,hannover));
        graph.addRoute(new Route(hannover,schwerin));
        graph.addRoute(new Route(mainz,stuttgart));
        graph.addRoute(new Route(muenchen,erfurt));
    }
    else{
        QMessageBox::information(this,"Graph nicht leer","Graph nicht leer");
    }
}

void Navigationssystem::adresseAnlegen(){
    QString qname = QInputDialog::getText(this,"name","name");
    QString qlatitude = QInputDialog::getText(this,"latitude","latitude");
    QString qlongitude = QInputDialog::getText(this,"longitude","longitude");

    QString qstrasse = QInputDialog::getText(this,"strasse","strasse");
    QString qhausnummer = QInputDialog::getText(this,"hausnummer","hausnummer");
    QString qpostleitzahl = QInputDialog::getText(this,"postleitzahl","postleitzahl");
    QString qstadt = QInputDialog::getText(this,"stadt","stadt");

    string name = qname.toStdString();
    double latitude = qlatitude.toDouble();
    double longitude = qlongitude.toDouble();
    string strasse = qstrasse.toStdString();
    int hausnummer = qhausnummer.toInt();
    int postleitzahl = qpostleitzahl.toInt();
    string stadt = qstadt.toStdString();

    Adresse* adresse = new Adresse(name,latitude,longitude,strasse,hausnummer,postleitzahl,stadt);
    graph.addOrt(adresse);
    dynamicButtons.push_back(createDynamicButton(name,latitude,longitude));

    double nachbarDistance = DBL_MAX;
    double temp{};
    Ort* tempOrt = nullptr;
    for(auto &a:graph.getAllOrt()){
        temp = adresse->getDistance(*a);
        if(temp<nachbarDistance && adresse != a){
            nachbarDistance = temp;
            tempOrt = a;
        }
    }
    graph.addRoute(new Route(adresse,tempOrt));
    QMessageBox::information(this,"Message","Adresse angelegt");
}

void Navigationssystem::PoIAnlegen(){
    QString qname = QInputDialog::getText(this,"name","name");
    QString qlatitude = QInputDialog::getText(this,"latitude","latitude");
    QString qlongitude = QInputDialog::getText(this,"longitude","longitude");

    QString qbemerkung = QInputDialog::getText(this,"bemerkung","bemerkung");
    QString qkategorie = QInputDialog::getText(this,"kategorie","kategorie");

    string name = qname.toStdString();
    double latitude = qlatitude.toDouble();
    double longitude = qlongitude.toDouble();
    string bemerkung = qbemerkung.toStdString();
    string Skategorie = qkategorie.toStdString();
    category kategorie = stringToCategory(Skategorie);

    PoI* poi = new PoI(name,latitude,longitude,bemerkung,kategorie);
    graph.addOrt(poi);
    dynamicButtons.push_back(createDynamicButton(name,latitude,longitude));

    double nachbarDistance=DBL_MAX;
    double temp{};
    Ort* tempOrt = nullptr;
    for(auto &a:graph.getAllOrt()){
        temp = poi->getDistance(*a);
        if(temp<nachbarDistance && poi != a){
            nachbarDistance = temp;
            tempOrt = a;
        }
    }
    graph.addRoute(new Route(poi,tempOrt));
    QMessageBox::information(this,"Message","Poi angelegt");
}

void Navigationssystem::txtExport()
{
    string outfilename = "outfile.txt";
    ofstream outfile(outfilename, ios::out);
    for(auto &i : graph.getAllOrt())
        i->txtExport(outfile);
}

void Navigationssystem::txtImport()
{
    if(graph.getAllOrt().size()==0){
        string infilename = "outfile.txt";
        ifstream quelle;

        quelle.open(infilename, ios::out);
        string data;
        if (quelle.is_open())
        {
            while (quelle.peek()!= EOF) {
                getline(quelle, data);
                stringstream strm(data);
                string name,stringType,stringLat,stringLon,strasse,stringHausnummer,stringPostleitzahl,stadt,bemerkung,stringKategorie;

                getline(strm,stringType,';');
                if(stringType == "1"){
                    getline(strm,name,';');
                    getline(strm,stringLat,';');
                    getline(strm,stringLon,';');
                    getline(strm,strasse,';');
                    getline(strm,stringHausnummer,';');
                    getline(strm,stringPostleitzahl,';');
                    getline(strm,stadt,';');

                    double latitude = stod(stringLat);
                    double longitude = stod(stringLon);
                    double hausnummer = stod(stringHausnummer);
                    int postleitzahl = stoi(stringPostleitzahl);

                    Adresse* adresse = new Adresse(name,latitude,longitude,strasse,hausnummer,postleitzahl,stadt);
                    graph.addOrt(adresse);
                    dynamicButtons.push_back(createDynamicButton(name,latitude,longitude));
                }
                else if(stringType == "2"){
                    getline(strm,name,';');
                    getline(strm,stringLat,';');
                    getline(strm,stringLon,';');
                    getline(strm,bemerkung,';');
                    getline(strm,stringKategorie,';');

                    double latitude = stod(stringLat);
                    double longitude = stod(stringLon);
                    category kategorie = stringToCategory(stringKategorie);

                    PoI* poi = new PoI(name,latitude,longitude,bemerkung,kategorie);
                    graph.addOrt(poi);
                    dynamicButtons.push_back(createDynamicButton(name,latitude,longitude));
                }
                else{
                    cout<<"Invalid Typ"<<endl;
                }
            }
        }
    }
    else{
        QMessageBox::information(this,"Graph nicht leer", "Graph nicht leer");
    }
}


int Navigationssystem::getIndex(int id){
    for(int i=0;i<graph.getAllOrt().size(); i++){
        if(graph.getAllOrt()[i]->getID() == id ){
            return i;
        }
    }
    return -1;
}

QString Navigationssystem::entfernungBerechnen(int id1, int id2){

    int index1 = getIndex(id1);
    int index2 = getIndex(id2);
    if(index1 == -1 || index2 == -1){
        QMessageBox::information(this,"Warning","ID not found");
        return "0";
    }
    return "Entfernung = " + QString::number( graph.getAllOrt()[index1]->getDistance(*graph.getAllOrt()[index2])) + " km";
}

category stringToCategory(string& str) {
    if (str == "0") {
        return TANKSTELLE;
    } else if (str == "1") {
        return RESTAURANT;
    } else if (str == "2") {
        return SEHENSWUERDIGKEIT;
    }else if (str == "3") {
        return COMMON_PLACE;
    }else if (str == "4") {
        return UNKNOWN;
    }else{
        cout<<"Invalid kategorie"<<endl;
        return UNKNOWN;
    }
}

void Navigationssystem::OrtAnlegen()
{
    QMessageBox::StandardButton reply1, reply2;
    reply1 = QMessageBox::question(nullptr, "Choose Option", "Do you want to add an address?",QMessageBox::Yes | QMessageBox::No);

    if (reply1 == QMessageBox::Yes) {
        adresseAnlegen();
    }
    else if (reply1 == QMessageBox::No) {
        reply2 = QMessageBox::question(nullptr, "Choose Option", "Do you want to add an PoI?",QMessageBox::Yes | QMessageBox::No);
        if (reply2 == QMessageBox::Yes) {
            PoIAnlegen();
        }
        else{
            QMessageBox::information(this,"Message","Nothing selected");
        }
    }
}

void Navigationssystem::AlleOrte()
{
    Anzeigen* liste = new Anzeigen(this->graph.getAllOrt());
    liste->show();
}

void Navigationssystem::Exportieren()
{
    txtExport();
    QMessageBox::information(this,"Message","Data in outfile.txt exported");
}

void Navigationssystem::Importieren()
{
    txtImport();
    QMessageBox::information(this,"Message","Data from outfile.txt imported");
}


void Navigationssystem::OrtEntfernen(){
    QString Bname;
    for(int i{};i<dynamicButtons.size();i++){
        if(dynamicButtons[i]->isChecked()){
            dynamicButtons[i]->setChecked(false);
            dynamicButtons[i]->hide();
            Bname = dynamicButtons[i]->text();
            erasedDynamicButtons.push_back(dynamicButtons[i]);
            dynamicButtons.erase(dynamicButtons.begin()+i);
        }
    }
    for(int j{};j<graph.getAllOrt().size();j++){
        if(Bname==QString::fromStdString(graph.getAllOrt()[j]->getName())){
            erasedOrte.push_back(graph.getAllOrt()[j]);
            graph.getAllOrt().erase(graph.getAllOrt().begin()+j);
            break;
        }
    }
    for(int j{};j<graph.getAllRoute().size();j++){
        if(Bname==QString::fromStdString(graph.getAllRoute()[j]->getFrom()->getName()) || Bname==QString::fromStdString(graph.getAllRoute()[j]->getTo()->getName())){
            erasedRoute.push_back(graph.getAllRoute()[j]);
            graph.getAllRoute().erase(graph.getAllRoute().begin()+j);
            break;
        }
    }
}

void Navigationssystem::Entfernung(){
    if(getOrtfromCheckedDynamicButton().size()==2){
        int id1 = getOrtfromCheckedDynamicButton()[0]->getID();
        int id2 = getOrtfromCheckedDynamicButton()[1]->getID();
        QMessageBox::information(this,"Entfernung",entfernungBerechnen(id1,id2));
    }
    else{
        QMessageBox::information(this,"Warning","zwei Orte Auswaehlen");
    }
}

void Navigationssystem::information()
{
    if(dynamicButtons.size())
        for(auto &a:dynamicButtons){
            if(a->isChecked()){
                for(auto &b:graph.getAllOrt()){
                    if(a->text() == QString::fromStdString(b->getName())){
                        Information* info = new Information(this,b);
                        info->show();
                    }
                }
            }
        }
    else{
        QMessageBox::information(this,"Information","no buttons");
    }
}

vector<Ort *> Navigationssystem::getOrtfromCheckedDynamicButton(){
    vector<Ort*>checkedOrt;
    for(auto &a:dynamicButtons){
        if(a->isChecked()){
            for(auto &b:graph.getAllOrt()){
                if(a->text() == QString::fromStdString(b->getName())){
                    checkedOrt.push_back(b);
                }
            }
        }
    }
    return checkedOrt;
}

QDynamicButton* Navigationssystem::createDynamicButton(std::string name,double latitude, double longitude){
    ReferencePoint bremen (210,135, 8.8017,53.0793);
    ReferencePoint berlin(450, 172, 13.4050, 52.5200);
    ScaledMap karte = ScaledMap(501, 491, bremen, berlin, 0, 0);

    int x = karte.longitudeToX(longitude);
    int y = karte.latitudeToY(latitude);

    QDynamicButton* button = new QDynamicButton(this);  // Create a dynamic button object
    button->setAutoExclusive(false);
    button->setText(QString::fromStdString(name));
    button->move(x,y);
    button->show();

    return button;
}
vector<Ort*> Navigationssystem::dijkstra(Ort* source, Ort* destination) {
    std::map<Ort*, double> distances;
    std::map<Ort*, Ort*> previous;
    std::map<Ort*,bool> visited;
    std::queue<Ort*> qOrt;
    std::queue<Route*>qRoutes;

    for (auto a : graph.getAllOrt()) {
        distances[a] = DBL_MAX;
        visited[a] = false;
        previous[a] = a;
    }

    distances[source] = 0.0;
    previous[source] = nullptr;
    for(unsigned int i{};i<graph.getAllOrt().size()-1;i++){
        Ort* minOrt = getNeareast(distances,visited);
        visited[minOrt] = true;

        Ort* nachbarOrt= nullptr;
        for(auto a : graph.getAllRoute()){
            if(a->getFrom()==minOrt){
                nachbarOrt = a->getTo();
            }
            else if(a->getTo()==minOrt ){
                nachbarOrt = a->getFrom();
            }
            if(!visited[nachbarOrt] && nachbarOrt!=nullptr){
                int dist = distances[minOrt] + minOrt->getDistance(*nachbarOrt);
                if(dist < distances[nachbarOrt]){
                    distances[nachbarOrt] = dist;
                    previous[nachbarOrt] = minOrt;
                }
            }
        }   
    }
    vector<Ort*> path;
    Ort* current = destination;
    while (current != nullptr) {
        path.push_back(current);
        current = previous[current];
    }
    if(path.size() && path[0]== destination){
        reverse(path.begin(), path.end());
    }
    return path;
}

void Navigationssystem::Routing()
{
    vector<Ort*>route{};
    if(getOrtfromCheckedDynamicButton().size()==2){
        route = dijkstra(getOrtfromCheckedDynamicButton()[0],getOrtfromCheckedDynamicButton()[1]);
        ShowRoute* showRoute = new ShowRoute(route);
        showRoute->show();
    }
}


void Navigationssystem::Laden()
{
    auffuellen();
}

bool compare(Ort* ort1,  Ort* ort2, std::map<Ort*, double> distances)  {
    return (distances[ort1] < distances[ort2]);
}

Ort* Navigationssystem::getNeareast(std::map<Ort*,double>&distances,std::map<Ort*,bool>&visited){
    Ort* nearest = nullptr;
    double min = DBL_MAX;
    for(auto &a: graph.getAllOrt()){
        if(!visited[a] && distances[a] < min){
            min = distances[a];
            nearest = a;
        }
    }
    return nearest;
}
