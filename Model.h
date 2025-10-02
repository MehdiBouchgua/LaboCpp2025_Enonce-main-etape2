/* Model.h */
#ifndef MODEL_H //
#define MODEL_H

#include <iostream>
using namespace std; // permet d'utiliser cout direment et non stdcout
/*#include "cstream"*/

enum Engine {Petrol,Diesel,Electric,Hybrid};

class Model {

private:
    char* name;
    int power;
    Engine engine;
    float basePrice;

public: //en dehors de la classe ça doit etre déclaré en Public
    Model();
    Model(const char* n, int p, Engine e, float bp); //Init
    Model(const Model &m); // Copie
    ~Model(); //Destructeur
//Set
    void setName(const char*n);
    void setPower(int p);
    void setEngine(Engine e);
    void setBasePrice(float bp);

 //Get
    const char* getName() const;
    int 		getPower() const;
    Engine 		getEngine() const;
    float 		getBasePrice() const;

    void display() const;
};

#endif