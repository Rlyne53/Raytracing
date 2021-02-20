#include "Vecteur3D.h"

Vecteur3D::Vecteur3D()
{
	_x = 0;
	_y = 0;
	_z = 0;
}
Vecteur3D::~Vecteur3D()
{


}
Vecteur3D::Vecteur3D(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
}

//Constructeur de recopie
Vecteur3D::Vecteur3D(const Vecteur3D& v)
{
	_x = v._x;
	_y = v._y;
	_z = v._z;


}

//La somme de deux vecteurs
Vecteur3D Vecteur3D::somme(const Vecteur3D& v) {
	Vecteur3D s;
	s._x = _x + v._x;
	s._y = _y + v._y;
	s._z = _z + v._z;
	return s;

}

Vecteur3D Vecteur3D::soustraction(const Vecteur3D& v) {
	Vecteur3D s;
	s._x = _x - v._x;
	s._y = _y - v._y;
	s._z = _z - v._z;
	return s;

}

Vecteur3D Vecteur3D::sub(float f)
{
	return Vecteur3D(_x - f, _y - f, _z - f);
}


//Le produit scalaire de deux vecteurs
float Vecteur3D::produit(const Vecteur3D& v)
{
	return _x * v._x + _y * v._y + _z * v._z;
}

Vecteur3D Vecteur3D::cross(Vecteur3D v)
{
	Vecteur3D vCross;
	vCross._x = ((_y * v._z) - (_z * v._y));
	vCross._y = ((_z * v._x) - (_x * v._z));
	vCross._z = ((_x * v._y) - (_y * v._x));
	return vCross;
}

//tester si deux vecteurs ont les memes composantes
bool Vecteur3D::egal(const Vecteur3D& v) {
	return (_x == v._x && _y == v._y && _z == v._z);
}

//Retourner la norme du vecteur
float Vecteur3D::norme(const Vecteur3D& v) {
	return sqrt(v._x * v._x + v._y * v._y + v._z * v._z);
}

Vecteur3D Vecteur3D::normalise(Vecteur3D& v)
{
	float n = norme(v);
	if (norme(v) != 0)
	{
		v._x /= n;
		v._y /= n;
		v._z /= n;
	}
	return v;
}

Vecteur3D Vecteur3D::mult(float f)
{
	return Vecteur3D(_x * f, _y * f, _z * f);
}
//L'affichage d'un vecteur
void Vecteur3D::afficher()
{
	std::cout << "(" << _x << "," << _y << "," << _z << ")" << std:: endl;
}

/*Vecteur3D operator+(Vecteur3D vect1, Vecteur3D vect2)
{

}

Vecteur3D operator-(Vecteur3D vect1, Vecteur3D vect2)
{

}
Vecteur3D operator-(Vecteur3D vect1)
{

}
float operator*(Vecteur3D vect1, Vecteur3D vect2)
{

}*/