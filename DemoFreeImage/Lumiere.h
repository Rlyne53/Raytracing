#pragma once
#include "ObjetGenerique.h"

class Lumiere: public ObjetGenerique
{
public:
	Lumiere();
	bool intersect(Ray ray, Hit& hit) override;

	explicit Lumiere(const Vecteur4D& position)
		: ObjetGenerique(position)
	{
	}
};