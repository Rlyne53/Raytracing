#pragma once
#include "Transform.h"
#include <iostream>

class ObjetGenerique
{
public:
	ObjetGenerique(Transform transform = Transform());
	virtual ~ObjetGenerique();

protected:
	Transform transform;

public:
	std::string type;
};


std::ostream& operator<<(std::ostream& os, ObjetGenerique objet);
