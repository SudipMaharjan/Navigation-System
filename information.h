#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include "ort.h"
#include "navigationssystem.h"

namespace Ui {
class Information;
}

class Information : public QWidget
{
    Q_OBJECT

public:
    explicit Information(Navigationssystem* navi, Ort* ort,QWidget *parent = nullptr);
    ~Information();

private:
    Ui::Information *ui;
};

#endif // INFORMATION_H
