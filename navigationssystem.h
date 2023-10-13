
#ifndef NAVIGATIONSSYSTEM_H
#define NAVIGATIONSSYSTEM_H

#include <QMainWindow>
#include "graph.h"
#include "ort.h"
#include "poi.h"
#include <vector>
#include<QInputDialog>
#include<QLabel>
#include<QMessageBox>
#include<QTextEdit>
#include "qdynamicbutton.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Navigationssystem; }
QT_END_NAMESPACE

class Navigationssystem : public QMainWindow

{
    Q_OBJECT

public:
    Navigationssystem(QWidget *parent = nullptr);
    ~Navigationssystem();
    QString entfernungBerechnen(int id1, int id2);
    int getIndex(int id);
    void auffuellen();
    void binaryExport();
    void txtExport();
    void binaryImport();
    void txtImport();
    Graph* getGraph();
    vector<Ort *> getOrtfromCheckedDynamicButton();
    QDynamicButton* createDynamicButton(string name, double latitude, double longitude);
    vector<Ort *> dijkstra(Ort* source,  Ort* destination);
    //void dijkstra(Ort* source,  Ort* destination);
    Ort* getNeareast(std::map<Ort *, double> &, std::map<Ort *, bool> &);



private slots:
    void on_pushButton_OrtAnlegen_clicked();
    void on_pushButton_AlleOrte_clicked();
    void on_pushButton_Entfernung_clicked();
    void on_pushButton_Exportieren_clicked();
    void on_pushButton_Importieren_clicked();
    void on_pushButton_Information_clicked();
    void on_pushButton_OrtEntfernen_clicked();
    void on_pushButton_Routing_clicked();
    void on_pushButton_Laden_clicked();

private:
    Ui::Navigationssystem *ui;
    void ortAnlegen();
    void adresseAnlegen();
    void PoIAnlegen();
    QVector<Ort*> erasedOrte;
    QVector<QDynamicButton*>dynamicButtons;
    QVector<QDynamicButton*>erasedDynamicButtons;
    QVector<Route*>erasedRoute;
    Graph graph;
};

category stringToCategory(string&);

#endif // NAVIGATIONSSYSTEM_H


