#pragma once
#include "Vecteur3D.h"

class Transform
{
public:
    Transform(Vecteur4D position = Vecteur4D(), Vecteur4D rotation = Vecteur4D(), Vecteur4D scale = Vecteur4D::un()); //constructeur d'initialisation
    virtual ~Transform(); //destructeur
public:
    Vecteur4D position;
    Vecteur4D rotation;
    Vecteur4D scale;
};


