#pragma once
#include "Vecteur3D.h"

class Ray
{
public:
	Ray(Vecteur4D origine, Vecteur4D direction);
	
	Vecteur4D pointDuRayon(float t);
public:
	Vecteur4D origine;
	Vecteur4D direction;
	float t_min = 0.1;
	float t_max = 1000;
};

