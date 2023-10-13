#ifndef ANZEIGEN_H
#define ANZEIGEN_H

#include <QWidget>
#include "ort.h"

namespace Ui {
class Anzeigen;
}

class Anzeigen : public QWidget
{
    Q_OBJECT

public:
    explicit Anzeigen(QVector<Ort *> liste, QWidget *parent = nullptr);
    ~Anzeigen();

private:
    Ui::Anzeigen *ui;
};

#endif // ANZEIGEN_H
