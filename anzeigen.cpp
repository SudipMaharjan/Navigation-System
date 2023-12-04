#include "anzeigen.h"
#include "ui_anzeigen.h"
#include <QStandardItem>

Anzeigen::Anzeigen(QVector<Ort *> liste, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Anzeigen)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(liste.size(), 5);
    model->setHorizontalHeaderLabels({"ID","Type","Name","Latitude","Longitude","Parameters"});

    int row = 0;
    for (const auto& item : liste) {
        model->setData(model->index(row, 0), QString::number(item->getID()));
        model->setData(model->index(row, 1), item->getTyp());
        model->setData(model->index(row, 2), QString::fromStdString(item->getName()));
        model->setData(model->index(row, 3), QString::number(item->getLatitude()));
        model->setData(model->index(row, 4), QString::number(item->getLongitude()));
        model->setData(model->index(row, 5), item->getParameters());
        ++row;
    }

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
}

Anzeigen::~Anzeigen()
{
    delete ui;
}
