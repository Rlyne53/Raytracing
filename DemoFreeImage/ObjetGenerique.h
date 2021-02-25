#pragma once
#include "Transform.h"
#include <iostream>
#include "Hit.h"
#include "Materiaux.h"
#include "Ray.h"



class ObjetGenerique
{
public:
	ObjetGenerique(Transform transform = Transform());
	virtual ~ObjetGenerique();
	virtual bool intersect(Ray ray, Hit& hit) = 0;
	ObjetGenerique(Vecteur4D position) //constructeur
	{
		transform = Transform(position);
	}

public:
	std::string type;
	Transform transform;
	Materiaux materiaux;
};


std::ostream& operator<<(std::ostream& os, ObjetGenerique* objet);
