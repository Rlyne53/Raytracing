#include "Vecteur.h"
Vecteur operator*(float nombreFlottant, const Vecteur& vecteur)
{
	return vecteur.multiplicationScalaire(nombreFlottant);
}

Vecteur operator+(const Vecteur& vecteur1, const Vecteur& vecteur2)
{
	Vecteur res = vecteur1.somme(vecteur2);
	return res;
}

Vecteur operator-(const Vecteur& vecteur1, const Vecteur& vecteur2)
{
	Vecteur res = vecteur1.soustraction(vecteur2);
	return res;
}

Vecteur operator-(const Vecteur& vecteur)
{
	Vecteur res = vecteur.multiplicationScalaire(-1);
	return res;
}

float operator*(const Vecteur& vecteur1, const Vecteur& vecteur2)
{
	return vecteur1.produit(vecteur2);
}