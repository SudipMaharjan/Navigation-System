
#ifndef GRAPH_H
#define GRAPH_H

#include "ort.h"
#include "route.h"
#include <QVector>
#include<queue>


class Graph
{
private:
    QVector<Ort*>allOrt;
    QVector<Route*>allRoute;

public:
    Graph();
    ~Graph();
    void addOrt(Ort*);
    void addRoute(Route*);
    QVector<Ort*>& getAllOrt();
    QVector<Route*>&getAllRoute();
    QString printConnectedOrt(Ort*)const;
    bool isConnected(Ort*, Ort*) const;
    vector<Ort*>getNachbarOrte(std::queue<Route*>,Ort*);
    void removeRoute(std::queue<Route*>,Ort*,Ort*);
};

#endif // GRAPH_H
