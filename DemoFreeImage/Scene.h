#pragma once
#include "ObjetGenerique.h"
#include <vector>

class Scene
{
private:
	Scene();

public:
	static Scene& Instance();
	void listeDesObjets();
	void ajoutObjet(ObjetGenerique* objet);
	
private:
	std::vector<ObjetGenerique*> _objets = std::vector<ObjetGenerique*>(0);
	//static Scene* scene;
		
};