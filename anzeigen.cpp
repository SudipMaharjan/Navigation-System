#include "anzeigen.h"
#include "ui_anzeigen.h"

Anzeigen::Anzeigen(QVector<Ort *> liste, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Anzeigen)
{
    ui->setupUi(this);
    QString outputText = "Navi-Daten\n";
    outputText += "--------------------------------------------------------------------------------------------------------\n";
    outputText += QString("%1").arg("ID", -20)+ QString("%1").arg("Typ", -20) + QString("%1").arg("Name", -20) + QString("%1").arg("Latitude", -20) + QString("%1").arg("Longitude", -20) + QString("%1").arg("Parameters") + "\n";
    ui->listWidget->addItem(outputText);

    for (int i=0; i < liste.size(); i++){
        ui->listWidget->addItem(liste.at(i)->printQString());
    }
}

Anzeigen::~Anzeigen()
{
    delete ui;
}
