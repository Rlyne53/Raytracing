#include "Camera.h"

Camera::~Camera()
{

}

Ray Camera::rayon(float i, float j)
{
	Vecteur4D direction = Vecteur4D(i, j, 0)-transform.position;
	Ray ray = Ray(transform.position, direction  );
	
	return ray;
}

Camera::Camera()
{
	ObjetGenerique::type = "Camera";
	transform.position = Vecteur4D(0,0,-10,0);
}

bool Camera::intersect(Ray ray, Hit& hit) {
	return true;
}
