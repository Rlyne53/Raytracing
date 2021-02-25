#include "Vecteur3D.h"

Vecteur3D::Vecteur3D()
{
	x = 0;
	y = 0;
	z = 0;
}
Vecteur3D::~Vecteur3D()
{


}
Vecteur3D::Vecteur3D(float x, float y, float z)
{
	x = x;
	y = y;
	z = z;
}

//Constructeur de recopie
Vecteur3D::Vecteur3D(const Vecteur3D& v)
{
	x = v.x;
	y = v.y;
	z = v.z;


}

//La somme de deux vecteurs
Vecteur3D Vecteur3D::somme(const Vecteur3D& v) {
	Vecteur3D s;
	s.x = x + v.x;
	s.y = y + v.y;
	s.z = z + v.z;
	return s;

}

Vecteur3D Vecteur3D::soustraction(const Vecteur3D& v) {
	Vecteur3D s;
	s.x = x - v.x;
	s.y = y - v.y;
	s.z = z - v.z;
	return s;

}

Vecteur3D Vecteur3D::sub(float f)
{
	return Vecteur3D(x - f, y - f, z - f);
}


//Le produit scalaire de deux vecteurs
float Vecteur3D::produit(const Vecteur3D& v)
{
	return x * v.x + y * v.y + z * v.z;
}

Vecteur3D Vecteur3D::cross(Vecteur3D v)
{
	Vecteur3D vCross;
	vCross.x = ((y * v.z) - (z * v.y));
	vCross.y = ((z * v.x) - (x * v.z));
	vCross.z = ((x * v.y) - (y * v.x));
	return vCross;
}

//tester si deux vecteurs ont les memes composantes
bool Vecteur3D::egal(const Vecteur3D& v) {
	return (x == v.x && y == v.y && z == v.z);
}

//Retourner la norme du vecteur
float Vecteur3D::norme(const Vecteur3D& v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vecteur3D Vecteur3D::normalise(Vecteur3D& v)
{
	float n = norme(v);
	if (norme(v) != 0)
	{
		v.x /= n;
		v.y /= n;
		v.z /= n;
	}
	return v;
}

Vecteur3D Vecteur3D::mult(float f)
{
	return Vecteur3D(x * f, y * f, z * f);
}
//L'affichage d'un vecteur
void Vecteur3D::afficher()
{
	std::cout << "(" << x << "," << y << "," << z << ")" << std:: endl;
}
