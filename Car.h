/*** Car.h ***/ 
#ifndef CAR_H
#define CAR_H

/*#include <iostream>*/
using namespace std; // permet d'utiliser cout direment et non stdcout
/*#include "cstream"*/

class Car {

private:
	string name;
	Model model;

public:
	Car();
	Car(const string &n, Model &m); // init
	Car(const Car &c) // copie
	~Car(); //Destructeur

	//SETTERS
	void setName(const char*n);
	void setModel(const char*c);

	//GETTERS
	string char getName() const;
	Model getModel() const;

	void display() const;


};

#endif