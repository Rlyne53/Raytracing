#pragma once
#include "math.h"
#include <iostream>

#include "Vecteur.h"
#include "Vecteur4D.h"


class Vecteur3D : Vecteur
{
public:
	Vecteur3D(); //constructeur
	Vecteur3D(float x, float y, float z); //constructeur d'initialisation
	virtual ~Vecteur3D(); //destructeur

	//fonction statique qui renvoit un vecteur (1,1,1)
	static Vecteur3D un() {
		return Vecteur3D(1, 1, 1);
	}
	
	//fonction statique qui renvoit un vecteur nul
	static Vecteur3D zero() {
		return Vecteur3D();
	}

public:
	float x;
	float y;
	float z; //déclaration des composantes 3D x,y,z

	//Constructeur de recopie
	Vecteur3D(const Vecteur3D& v);

	//L'affichage d'un vecteur
	void afficher();

	Vecteur somme(Vecteur4D autre) const override;
	float produit(const Vecteur& autre) const override;
	Vecteur soustraction(const Vecteur& autre) const override;
	Vecteur produit_vectoriel(const Vecteur& autre) const override;
	
	Vecteur multiplicationScalaire(float nombre_flottant) const override;
	//La somme de deux vecteurs
	Vecteur3D somme(const Vecteur3D& v) const;

	Vecteur3D soustraction(const Vecteur3D& v);

	//Le produit scalaire de deux vecteurs
	float produit(const Vecteur3D& v);

	//tester si deux vecteurs ont les memes composantes
	bool egal(const Vecteur3D& v);

	//Retourner la norme du vecteur
	float norme(const Vecteur3D& v);

	//Produit vectoriel
	Vecteur3D cross(Vecteur3D v);

	//Normalisation du vecteur
	Vecteur3D normalise(Vecteur3D& v);

	//multiplication d'un vecteur par un scalaire 
	Vecteur3D mult(float f);

	Vecteur3D sub(float f);

};
