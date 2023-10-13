
#include "route.h"

Route::Route()
{

}

Route::Route(Ort *a, Ort *b)
    :from{a},to{b}
{
    distance = a->getDistance(*b);
    Routet = false;
}

Route::~Route()
{
    delete from;
    from = nullptr;

    delete to;
    to = nullptr;
}

Ort* Route::getFrom()const{
    return from;
}

Ort* Route::getTo() const{
    return to;
}

double Route::getDistance()const{
    return distance;
}

bool Route::isRoutet(){
    return Routet;
}
void Route::setRoutet(){
    Routet = true;
}
