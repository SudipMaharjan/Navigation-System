#ifndef SHOWROUTE_H
#define SHOWROUTE_H

#include <QWidget>
#include <ort.h>
#include <graph.h>

namespace Ui {
class ShowRoute;
}

class ShowRoute : public QWidget
{
    Q_OBJECT

public:
    explicit ShowRoute(vector<Ort*> route, QWidget *parent = nullptr);
    ~ShowRoute();

private:
    Ui::ShowRoute *ui;
};

#endif // SHOWROUTE_H
