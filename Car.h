/*** Car.h ***/ 
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>
#include "Model.h"
#include "Option.h"

using namespace std; // permet d'utiliser cout direment et non stdcout

namespace carconfig {


class Car {

private:
	string name; //nom du projet voiture
	Model model; //Modele de base
	vector<const Option*> options;

public:
	Car();
	Car(const string &n,const Model &m); // init
	Car(const Car &c); // copie
	~Car(); //Destructeur

	//SETTERS
	void setName(const string &n);
	void setModel(Model m);

	//GETTERS
	string getName() const;
	Model getModel() const;

	// Gestion des options
	void addOption(const Option &option);               // Ajoute une option à la voiture
	void removeOption(const string &code);     // Supprime une option via son code
	float getPrice() const;              // Prix total du modèle + options
	void display() const;                      // Affiche les infos de la voiture



};

} //Fin namespace carconfig

#endif