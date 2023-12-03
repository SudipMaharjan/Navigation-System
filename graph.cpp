
#include "graph.h"

Graph::Graph()
{

}

Graph::~Graph(){
    for(auto &a:allOrt){
        delete a;
        a=nullptr;
    }
    for(auto &b:allRoute){
        delete b;
        b=nullptr;
    }
}

void Graph::addOrt(Ort* a){
    allOrt.push_back(a);
}

void Graph::addRoute(Route* r){
    allRoute.push_back(r);
}

QVector<Ort*>& Graph::getAllOrt()  {
    return allOrt;
}
QVector<Route*>& Graph::getAllRoute(){
    return allRoute;
}

QString Graph::printConnectedOrt(Ort* o)const{
    QString info;
    for(int i{};i<allRoute.size();i++){
        if(o== allRoute[i]->getFrom()) {
            info +=QString::fromStdString(allRoute[i]->getTo()->getName());
            info += "\t entfernung = ";
            info +=QString::number( o->getDistance(*allRoute[i]->getTo()));
            info += "km\n";
        }
        if(o==allRoute[i]->getTo()){
            info += QString::fromStdString(allRoute[i]->getFrom()->getName());
            info += "\t entfernung = ";
            info += QString::number(o->getDistance(*allRoute[i]->getFrom()));
            info += "km\n";
        }
    }

    return info;
}

bool Graph::isConnected(Ort* a, Ort* b) const{
    bool t = false;
    for(int i{};i<allRoute.size();i++){
        if(allRoute[i]->getFrom() == a && allRoute[i]->getTo() == b){
            t = true;
        }
        else if(allRoute[i]->getFrom() == b && allRoute[i]->getTo() == a){
            t = true;
        }
    }
    return t;
}

vector<Ort*> Graph::getNachbarOrte(std::queue<Route*>q, Ort* ort){
    unsigned int i{};
    vector<Ort*>nachbarOrte;
    vector<Route*>qRoute;
    while(!q.empty()){
        qRoute.push_back(q.front());
        q.pop();
    }

    while(true){
        if(qRoute[i]->isRoutet() == false){
            if(i<qRoute.size()){
                if(ort == qRoute[i]->getFrom()){
                    nachbarOrte.push_back(allRoute[i]->getTo());
                }
                if(ort == qRoute[i]->getTo()){
                    nachbarOrte.push_back(allRoute[i]->getFrom());
                }
                ++i;
            }
            else if(i==qRoute.size()){
                break;
            }
        }
    }
    return nachbarOrte;
}

