#include "Lumiere.h"

Lumiere::Lumiere()
{
	materiaux.couleur = Couleur(255, 255, 0, 0);
}

bool Lumiere::intersect(Ray ray, Hit& hit)
{
	return false;
}
