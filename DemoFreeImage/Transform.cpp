#include "Transform.h"

Transform::Transform(Vecteur4D position, Vecteur4D rotation, Vecteur4D scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}
Transform::~Transform()
{

}