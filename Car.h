/*** Car.h ***/ 
#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include "Model.h"

using namespace std; // permet d'utiliser cout direment et non stdcout

namespace carconfig {


class Car {

private:
	string name; //nom du projet voiture
	Model model; //Modele de base

public:
	Car();
	Car(const string &n,const Model &m); // init
	Car(const Car &c); // copie
	~Car(); //Destructeur

	//SETTERS
	void setName(const string &n);
	void setModel(const Model &m);

	//GETTERS
	string getName() const;
	Model getModel() const;

	void display() const;


};

} //Fin namespace carconfig

#endif