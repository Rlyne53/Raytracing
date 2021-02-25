#pragma once
#include "Vecteur4D.h"

class Vecteur
{
public:
	Vecteur();
	virtual Vecteur somme(Vecteur4D autre) const;
	virtual float produit(const Vecteur& autre) const;
	virtual Vecteur soustraction(const Vecteur& autre) const;
	virtual Vecteur produit_vectoriel(const Vecteur& autre) const;
	virtual Vecteur un();
	virtual Vecteur zero();
	virtual Vecteur multiplicationScalaire(float nombre_flottant) const;
public:
	float x;
	float y;
};


template <typename T>
T operator*(float floatNumber, const T& vecteur);
template <typename T>
T operator+(const T& vecteur1, const T& vecteur2);
template <typename T>
T operator-(const T& vecteur1, const T& vecteur2);
template <typename T>
T operator-(const T& vecteur);
template <typename T>
float operator*(const T& vecteur1, const T& vecteur2);