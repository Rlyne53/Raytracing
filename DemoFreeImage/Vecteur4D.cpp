#include "Vecteur4D.h"

#include <cmath>


Vecteur4D::Vecteur4D(float x, float y, float z, float k)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->k = k;
}

Vecteur4D::Vecteur4D(const RGBQUAD& couleur) : Vecteur4D(couleur.rgbRed, couleur.rgbGreen, couleur.rgbBlue, 1)
{

}

Vecteur4D Vecteur4D::somme(Vecteur4D autre) const
{
	Vecteur4D res(autre.x + x, autre.y + y, autre.z + z, autre.k + k);
	return res;
}

float Vecteur4D::produit(const Vecteur4D& autre) const
{
	return x * autre.x + y * autre.y + z * autre.z+ k * autre.k;
}

Vecteur4D Vecteur4D::soustraction(const Vecteur4D& autre) const
{
	Vecteur4D res(x-autre.x , y-autre.y , z-autre.z, k-autre.k );
	return res;
}

Vecteur4D Vecteur4D::produit_vectoriel(const Vecteur4D& autre) const
{
	return Vecteur4D::un();
}

Vecteur4D Vecteur4D::un()
{
	return Vecteur4D(1, 1, 1, 1);
}



Vecteur4D Vecteur4D::multiplicationScalaire(float nombre_flottant) const
{
	return Vecteur4D(nombre_flottant * x, nombre_flottant * y, nombre_flottant * z, nombre_flottant* k);
}

float Vecteur4D::norm() const
{
	return sqrt(produit(*this));
}

bool Vecteur4D::isNull() const
{
	return norm() < 0.00000000001f ;
}

Vecteur4D Vecteur4D::normalise() const
{
	if (!isNull())
	{
		float n = norm();
		return 1 / n * (*this);
	}
}


Vecteur4D operator+(const Vecteur4D& x, const Vecteur4D& y)
{
	return x.somme(y);
}

Vecteur4D operator-(const Vecteur4D& x, const Vecteur4D& y)
{
	return x.soustraction(y);
}

Vecteur4D operator-(const Vecteur4D& x)
{
	return Vecteur4D().soustraction(x);
}

float operator*(const Vecteur4D& x, const Vecteur4D& y)
{
	return x.produit(y);
}

Vecteur4D operator*(const float& t, const Vecteur4D& y)
{
	return y.multiplicationScalaire(t);
}

Vecteur4D operator*(const Vecteur4D& x, const float& t)
{
	return x.multiplicationScalaire(t);
}
