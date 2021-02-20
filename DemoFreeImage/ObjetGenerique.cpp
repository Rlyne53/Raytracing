#include "ObjetGenerique.h"

ObjetGenerique::ObjetGenerique(Transform transform)
{
	this->transform = transform;
}


ObjetGenerique::~ObjetGenerique()
{

}

std::ostream& operator<<(std::ostream& os, ObjetGenerique objet)
{
	{
		os << objet.type;
		return os;
	}
}
