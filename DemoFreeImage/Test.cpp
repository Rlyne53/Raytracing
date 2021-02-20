#include <iostream>
#include "Scene.h"
#include "Camera.h"
#include "Sphere.h"

int main(int argc, char** argv)
{
	Scene scene = Scene::Instance();
	scene.ajoutObjet(new Camera());
	scene.ajoutObjet(new Sphere());

	scene.listeDesObjets();

	//test fonctions vecteur
	Vecteur3D v1(1, 2, 3);
	std::cout << "Vecteur V1";
	v1.afficher();
	Vecteur3D v2(3, 2, 1);
	std::cout << "Vecteur V2";
	v2.afficher();
	std::cout << std::endl;
	std::cout << "La somme des vecteurs v1 et v2 est : ";
	(v1.somme(v2)).afficher();
	std::cout << "Le produit scalaire des vecteurs v1 et v2 est : " << v1.produit(v2) << std::endl;
	std::cout << std::endl;
	std::cout << "Copier le vecteur V1 dans V3:" << std::endl;
	Vecteur3D v3(v1);
	std::cout << "Vecteur V3";
	v3.afficher();
	if (v1.egal(v3))
		std::cout << "Les vecteurs v1 et v3 coincident " << std::endl;
	else
		std::cout << "Les vecteurs v1 et v3 ne coincident pas " << std::endl;

	std::cout << "Le produit scalaire des vecteurs v1 et v2 est : " << v1.norme(v1) << std::endl;
	std::cout <<  "Norme" << std::endl;
	v1.normalise(v2).afficher();
	std::cout << std::endl;
	std::cout << "Produit vectoriel" << std::endl;
	v1.cross(v1).afficher();
	
	return EXIT_SUCCESS;
}