#include "Scene.h"
#include <iostream>

Scene::Scene()
{
}

Scene& Scene::Instance()
{
	/*if (scene == nullptr) {
		scene = new Scene();
	}

	return *scene;*/
	return *(new Scene());
}

void Scene::listeDesObjets()
{
	for (ObjetGenerique* objet : _objets) {
		std::cout << *objet << std::endl;
	}
}

void Scene::ajoutObjet(ObjetGenerique* objet)
{
	_objets.push_back(objet);
}
