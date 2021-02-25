#pragma once
#include "ObjetGenerique.h"
#include <vector>

#include "Camera.h"
#include "Lumiere.h"
#define MAX_DIST 2


class Scene
{
private:
	Scene();

public:
	void raytrace();
	static Scene& Instance();
	void listeDesObjets();
	void ajoutObjet(ObjetGenerique* objet);
	void ajoutObjet(Camera* cam);
	void ajoutObjet(Lumiere* lumiere);
	
private:
	std::vector<ObjetGenerique*> _objets = std::vector<ObjetGenerique*>(0);
	std::vector<Camera*> _cameras;
	std::vector<Lumiere*> _lumieres;
public:
	//static Scene* scene;
		
};
