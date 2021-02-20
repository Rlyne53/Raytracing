#pragma once
#include "Vecteur3D.h"

class Transform
{
public:
    Transform(Vecteur3D position = Vecteur3D::zero(), Vecteur3D rotation = Vecteur3D::zero(), Vecteur3D scale = Vecteur3D::un()); //constructeur d'initialisation
    virtual ~Transform(); //destructeur
public:
    Vecteur3D position;
    Vecteur3D rotation;
    Vecteur3D scale;
};


