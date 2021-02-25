#pragma once
#include "ObjetGenerique.h"
#include "Ray.h"
#include "Vecteur4D.h"
class Sphere: public ObjetGenerique
{
public:
	Sphere() //constructeur
	;

    explicit Sphere(const Vecteur4D& position)
	    : ObjetGenerique(position)
    {
    	
    }

	

    virtual ~Sphere(); //destructeur
    bool intersect(Ray ray, Hit& hit) override;
public:
    float radius = 1;
    int counter = 0;
};

