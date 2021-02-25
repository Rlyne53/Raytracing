#include "Ray.h"

Ray::Ray(Vecteur4D origine, Vecteur4D direction)
{
	this->origine = origine;
	this->direction = direction.normalise();
}



Vecteur4D Ray::pointDuRayon(float t)
{
	return origine + (t * direction);
}
