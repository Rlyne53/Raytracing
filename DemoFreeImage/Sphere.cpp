#include "Sphere.h"
#include "SecondOrderEquation.h"

Sphere::Sphere()
{
	ObjetGenerique::type = "Sphere";
    transform.position = Vecteur4D(0, 0, 3, 0);
    materiaux.couleur = Couleur(255, 0, 0);
}

Sphere::~Sphere()
{

}

bool Sphere::intersect(Ray ray, Hit& hit) {
	
    Vecteur4D u = ray.direction;
    Vecteur4D o = ray.origine;
    double a = u.norm() * u.norm();
    double b = 2 * u * o;
    double c = o.norm() * o.norm() - radius * radius;
    double delta = b * b - 4 * a * c;
    double t1;
    double t2;
	if (delta<=0)
	{
        return false;
	}
    t1 = (-b - sqrt(delta)) / (2 * a);
    t2 = (-b + sqrt(delta)) / (2 * a);

	if (ray.t_min < t1 && t1 <ray.t_max)
	{
		
	}
    hit.hitPoint = ray.pointDuRayon(t1);
    hit.materiaux = materiaux;
    return true;
    
}