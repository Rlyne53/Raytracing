#pragma once
#include <FreeImage.h>

#include "Vecteur4D.h"

struct Couleur
{
	Couleur(Vecteur4D vecteur = Vecteur4D());
	Couleur(RGBQUAD rgb);
	Couleur(int r = 0, int g = 0, int b = 0, int a = 1);
	int rouge = 255;
	int vert = 255;
	int bleu = 255;
	float alpha = 1;
public:
	RGBQUAD formatQuad();
	Vecteur4D formatVecteur();
};

