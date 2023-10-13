#include "information.h"
#include "ui_information.h"

Information::Information(Navigationssystem* navi, Ort* ort, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    QString info = ort->printInformation();
    info += "\n\nDamit verbundene Orte\n";
    info += navi->getGraph()->printConnectedOrt(ort);
    ui->label->setText(info);
}

Information::~Information()
{
    delete ui;
}
