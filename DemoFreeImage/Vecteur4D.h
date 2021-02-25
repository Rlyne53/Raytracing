#pragma once
#include <FreeImage.h>

class Vecteur4D 
{
public:
	Vecteur4D(float x = 0,float y = 0, float z = 0, float k = 0);
	Vecteur4D(const RGBQUAD& couleur);

	Vecteur4D somme(Vecteur4D autre) const ;
	float produit(const Vecteur4D& autre) const ;
	Vecteur4D soustraction(const Vecteur4D& autre) const ;
	Vecteur4D produit_vectoriel(const Vecteur4D& autre) const ;
	static Vecteur4D un() ;
	Vecteur4D multiplicationScalaire(float nombre_flottant) const ;
	float norm() const;
	bool isNull() const;
	Vecteur4D normalise() const;


public:
	float x;
	float y;
	float z;
	float k;
};


Vecteur4D operator+(const Vecteur4D& x, const Vecteur4D& y);
Vecteur4D operator-(const Vecteur4D& x, const Vecteur4D& y);
Vecteur4D operator-(const Vecteur4D& x);
float operator*(const Vecteur4D& x, const Vecteur4D& y);
Vecteur4D operator*(const float& t, const Vecteur4D& y);
Vecteur4D operator*(const Vecteur4D& x, const float& t);