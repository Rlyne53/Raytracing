#include "Transform.h"

Transform::Transform(Vecteur3D position, Vecteur3D rotation, Vecteur3D scale)
{
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
}
Transform::~Transform()
{

}