
#ifndef ROUTE_H
#define ROUTE_H




#include "ort.h"
class Route
{
private:
    Ort* from;
    Ort* to;
    double distance;
    bool Routet;
public:
    Route();
    Route(Ort*,Ort*);
    Ort* getFrom()const;
    bool isRoutet();
    void setRoutet();
    Ort* getTo() const;
    double getDistance()const;
    ~Route();
};

#endif // ROUTE_H
