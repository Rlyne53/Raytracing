#pragma once
#include "ObjetGenerique.h"

class Camera : public ObjetGenerique
{
public:
	Camera() //constructeur
	;


	explicit Camera(const Vecteur4D& position)
		: ObjetGenerique(position)
	{
	}

	bool intersect(Ray ray, Hit& hit);
	virtual ~Camera(); //déstructeur

	Ray rayon(float i, float j);
public:
	int resolutionLargeur = 60;
	int resolutionLongueur= 60;

};


struct ChampDeVision //composante du champ de vision
{
	float _n;
	float _f;
	float _l;
	float _r;
};
