#include "showroute.h"
#include "ui_showroute.h"

ShowRoute::ShowRoute(vector<Ort*> route,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowRoute)
{
    ui->setupUi(this);
    QString text;
    double totalDistance = 0.0;
    for(unsigned int i{};i<route.size()-1;i++){
        text += QString::fromStdString(route[i]->getName()) + "->";
        totalDistance += route[i]->getDistance(*route[route.size()-1]);
    }
    text += QString::fromStdString(route[route.size()-1]->getName());
    ui->listWidget->addItem(text);
    ui->listWidget->addItem("\nTotal Distance:\t" + QString::number(totalDistance) + "km");
}

ShowRoute::~ShowRoute()
{
    delete ui;
}
