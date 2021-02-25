#include "Scene.h"

#include <FreeImage.h>
#include <iostream>
#include <string>

#include "Vecteur4D.h"
Scene::Scene()
{
}

void Scene::raytrace()
{
	int i, j, iObj, maxObj, l, maxLum;
	FIBITMAP* final_img = NULL;
	RGBQUAD colorObj;
	ObjetGenerique* intersecObj = NULL;// pointeur sur l'object intersecté par un rayon
	Hit interinfo, tmpInfo; // object stockant les informations d'une intersection

	// variable stockant l'intersection la plus proche, on donne de grande valeur pour
	Vecteur4D positionCamera;
	maxObj = _objets.size();
	maxLum = _lumieres.size();

	for (unsigned int k = 0; k < _cameras.size(); k++) {// pour chaque camera de la scène
		std::string nomImage = "Scene" + std::to_string(k);// nom de l'image
		positionCamera = _cameras[k]->transform.position;
		int dx = _cameras[k]->resolutionLargeur;
		int dy = _cameras[k]->resolutionLongueur;

		// on alloue l'image à rendre
		final_img = FreeImage_Allocate(dx, dy, 24);
		nomImage += ".bmp";
		// pour chaque pixel de l'image rendu par la camera
		for (i = 0; i < dy; i++) {// les lignes
			for (j = 0; j < dx; j++) {// les colonnes
				intersecObj = NULL;
				float distNearest = MAX_DIST;

				//calcul du rayon primaire
				interinfo.rayon = tmpInfo.rayon = &_cameras[k]->rayon(j, i);
				// on trouve les intersections avec les objets de la scène
				for (iObj = 0; iObj < maxObj; iObj++) {
					// intersection avec un objet
					if (_objets[iObj]->intersect(*tmpInfo.rayon,tmpInfo)) {
						// si la distance entre cette intersection et l'origine 
						// du rayon est + petite que la plus petite on met à jour les infos
						float dist = sqrt((tmpInfo.hitPoint - tmpInfo.rayon->origine) * (tmpInfo.hitPoint - tmpInfo.rayon->origine));
						if (dist < distNearest) {
							distNearest = dist;
							interinfo = tmpInfo;
							intersecObj = _objets[iObj];
						}
					}
				}
				// si intersection on calcul la couleur du pixel
				if (intersecObj) {
					// calcul du terme ambiant
					//RGBQUAD colorObj = RGBQUAD();
					RGBQUAD colorObj = interinfo.materiaux.couleur.formatQuad();
					//Vecteur4D color = Vecteur4D(colorObj) * interinfo.m_mat.getCoeff(0) * m_iambiant;
					Vecteur4D color = Vecteur4D(colorObj);
					//Vecteur4D color = Vecteur4D(166, 191, 173,1);
					// boucle sur chaque lumière
					for (l = 0; l < maxLum; l++) {
						//calcul du rayon secondaire
						Lumiere* lumiere = _lumieres[l];
	
						tmpInfo.rayon = interinfo.rayon_secondaire = &Ray(interinfo.hitPoint, _lumieres[l]->transform.position - interinfo.hitPoint);
						iObj = 0;
						bool isInter = false;
						while (!isInter && iObj < maxObj) {
							isInter = _objets[iObj]->intersect(*tmpInfo.rayon,tmpInfo);
							// si dist point intersection-obj > dist point intersection-lumière
							// l'objet ne cache pas la lumière
							if (isInter && (tmpInfo.hitPoint - interinfo.hitPoint).norm() > (tmpInfo.hitPoint - _lumieres[l]->transform.position).norm()) {
								isInter = false;
							}
							iObj++;
						}
						// si il n'y a pas eu d'intersection on ajoute la lumière
						if (!isInter) {
							//color = color + _lumieres[l]->getLumi(&colorObj, &interinfo);
							color = color + Couleur(colorObj).formatVecteur();
						}
					}
					// calcul de la couleur finale
					RGBQUAD final_color = Couleur(color).formatQuad();
					FreeImage_SetPixelColor(final_img, j, dy - i - 1, &final_color);
				}
			}
		}
		// sauvegarder l'image
		FreeImage_Save(FIF_BMP, final_img, nomImage.c_str());
		std::cout << "Fichier sauvearder sous le nom " << nomImage << std::endl;
		// déasllouer l'image
		FreeImage_Unload(final_img);
	}
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
		std::cout << objet << std::endl;
	}
}

void Scene::ajoutObjet(ObjetGenerique* objet)
{
	_objets.push_back(objet);
}

void Scene::ajoutObjet(Camera* cam)
{
	_cameras.push_back(cam);
}

void Scene::ajoutObjet(Lumiere* lumiere)
{
	_lumieres.push_back(lumiere);
}

