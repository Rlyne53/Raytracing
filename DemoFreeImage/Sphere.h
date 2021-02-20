#pragma once
#include "ObjetGenerique.h"
class Sphere: public ObjetGenerique
{
public:
    Sphere() //constructeur
    {
        ObjetGenerique::type = "Sphere";
    }
    virtual ~Sphere(); //destructeur
};

