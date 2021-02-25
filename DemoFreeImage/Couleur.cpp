#include "Couleur.h"

Couleur::Couleur(Vecteur4D vecteur)
{
	rouge = vecteur.x;
	vert = vecteur.y;
	bleu = vecteur.z;
	alpha = vecteur.k;
}

Couleur::Couleur(RGBQUAD rgb)
{
	rouge = rgb.rgbRed;
	vert = rgb.rgbGreen;
	bleu = rgb.rgbBlue;
}

Couleur::Couleur(int r, int g, int b, int a) : rouge(r),vert(g),bleu(b),alpha(a)
{
}

RGBQUAD Couleur::formatQuad()
{
	RGBQUAD quadruplet = RGBQUAD();
	quadruplet.rgbGreen = vert * alpha;
	quadruplet.rgbRed = rouge * alpha;
	quadruplet.rgbBlue = bleu*alpha;
	return quadruplet;
}

Vecteur4D Couleur::formatVecteur()
{
	Vecteur4D vecteur = Vecteur4D(rouge,vert,bleu,alpha);
	return vecteur;
}
