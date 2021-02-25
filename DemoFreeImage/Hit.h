#pragma once
#include "Materiaux.h"
#include "Ray.h"

struct Hit
{
	Ray* rayon;
	Vecteur4D hitPoint;
	Ray* rayon_secondaire;
	Materiaux materiaux;
};

