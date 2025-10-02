/*Model.cpp*/
#include "Model.h"
#include <string.h>


/* ---------- CONSTRUCTEUR--------------- */

Model::Model()
{
    cout << ">>> Model = constructeur par defaut" << endl;
    name = NULL;
    setName("nom");
    setPower(0);
    setEngine(Engine::Petrol);
    setBasePrice(0.0);
}

Model::Model(const char* n, int p, Engine e, float bp)
{
    cout << ">>> Model : constructeur d'initialisation <<<" << endl;
    name = NULL; // On remet le pointeur a NULL pour être sur de ne pas delete un mauvais element en mémoire
    setName(n);
    setPower(p);
    setEngine(e);
    setBasePrice(bp);
}

// -----------------CONSTRUCTEUR DE COPIE -------------

Model::Model(const Model &m)
{
    cout << ">>> Model = constructeur de copie" << endl;
    name = NULL;
    setName(m.getName()); //Récupere le nom de getname -> pointeur
    setPower(m.getPower());
    setEngine(m.getEngine());
    setBasePrice(m.getBasePrice());
}

// ---------------- DESTRUCTEUR---------------------

Model::~Model()
{
    cout << ">>> Model = Destructeur par defaut <<<" << endl;
    if (name) delete[] name; //suppression de "name" car tableau de caractere[]
}

// ------------------SETTER------------------------

void Model::setName(const char*n)
{
    if(n == NULL) return;
    if(name == n) return;
    if(name) delete [] name; // crochet car name est pointeur de char
    name = new char[strlen(n)+1]; // chaine +1 pour le \0
    strcpy(name,n);
}
void Model::setPower(int p)
{
    if( p < 0) return;
    power = p;
}
void Model::setEngine(Engine e)
{
    engine = e;
}
void Model::setBasePrice(float bp)
{
    if(bp < 0.0) return;
    basePrice = bp;
}

// ------------------GETTER------------------------

//Get
const char* Model::getName() const
{
    return name;
}
int         Model::getPower() const
{
    return power;
}
Engine      Model::getEngine() const
{
    return engine;
}
float       Model::getBasePrice() const
{
    return basePrice;
}

// -------------- METHODE D'INSTANCE --------------

void Model :: display() const
{
    cout << "Model: ";
    if (name)
        cout << name;
    else
        cout << "pas de nom";

    cout << "( " << power << " Ch, ";
    switch (engine)
    {
    case Engine::Petrol:cout << "essence, ";
        break;
    case Engine::Diesel: cout << "diesel, ";
        break;
    case Engine::Electric: cout << "electrique, ";
    }
    cout << basePrice << " euros)" << endl;
}
