/*** Car.h ***/ 

#include "Car.h"
#include <string.h>

/******** Constructeur ********/

Car::Car()
{
	cout << ">>> Car = constructeur par defaut" << endl;
	name = nullptr;
	setName("nom");
	setModel("model");
}

Car::Car(const name& n,const model& m)
{
	cout << ">>> Car : constructeur d'initialisation <<<" << endl;
	name = nullptr;
	setName(n);
	setModel(m);
}
