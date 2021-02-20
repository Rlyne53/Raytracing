#pragma once
#include "ObjetGenerique.h"

class Camera : public ObjetGenerique
{
public:
	Camera() //constructeur
	{
		ObjetGenerique::type = "Camera";
	}
	virtual ~Camera(); //déstructeur
private:
	//ChampDeVision _cdv;

};


struct ChampDeVision //composante du champ de vision
{
	float _n;
	float _f;
	float _l;
	float _r;
};
