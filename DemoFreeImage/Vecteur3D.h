#pragma once
#include "math.h"
#include <iostream>



class Vecteur3D
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
	float _x;
	float _y;
	float _z; //déclaration des composantes 3D x,y,z

	//Constructeur de recopie
	Vecteur3D(const Vecteur3D& v);

	//L'affichage d'un vecteur
	void afficher();

	//La somme de deux vecteurs
	Vecteur3D somme(const Vecteur3D& v);

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


Vecteur3D operator+(Vecteur3D vect1, Vecteur3D vect2);
Vecteur3D operator-(Vecteur3D vect1, Vecteur3D vect2);
Vecteur3D operator-(Vecteur3D vect1);
float operator*(Vecteur3D vect1, Vecteur3D vect2);
	