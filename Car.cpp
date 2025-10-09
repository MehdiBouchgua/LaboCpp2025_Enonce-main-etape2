/*** Car.cpp ***/ 

#include "Car.h"
#include "Option.h"
#include <string.h>
#include <iostream>

using namespace std;
using namespace carconfig;

/******** Constructeur par defaut ********/

Car::Car() {
	cout << ">>> Car = constructeur par defaut" << endl;
	name = "Projet_sans_nom"; //
	Model m; //model par defaut
	setModel(m); // assignation de ce modele a la voiture a l'aide du setter
}

// Constructeur d'initialisation

Car::Car(const string &n,const Model &m) {
	cout << ">>> Car : constructeur d'initialisation <<<" << endl;
	setName(n);
	setModel(m);
}

// Constructeur de copie


Car::Car(const Car &c) {
	cout << ">>> Car : Constructeur de copie <<<" << endl;
	//passage en ref de l'objet c const pour eviter une copie inutile
	name = c.name;
	model = c.model; //La copie automatique est safe car string

}

// Destructeur

Car::~Car()
{
	cout << ">>> Car : destructeur <<<" << endl;
	// Rien a désallouer car pas de pointeur ni de mémoire dynamique -> destructeur de "Model" appelé auto
}


// SETTERS

void Car::setName(const string &n)
{
	name = n; //affectation directe de la valeur passé en parametre a l'attribut privé "string name"
}

void Car::setModel(const Model &m)
{
	model = m; //On recopie le model passé en paramètre
}


//GETTERS

string Car::getName() const
{
	return name; // on retourne une copie du nom et pas de modif de l'objet car const
}

Model Car::getModel() const
{
	return model; // Test2a.cpp getModel().display() donc retour par valeur
}

// Ajout d'une option à la voiture
void Car::addOption(Option *opt)
{
    if (opt)
    {
        options.push_back(opt);
    }
}

// Suppression d'une option par son code
void Car::removeOption(const string &code) {
    for (auto it = options.begin(); it != options.end(); ++it)
    {
        if ((*it)->getCode() == code)
        {
            options.erase(it);
            break;
        }
    }
}

// Calcule le prix total
float Car::getPrice() const
{
    float total = model.getBasePrice();  // récupère le prix du modèle
    for (const auto &opt : options)
        total += opt.getPrice();         // ajoute le prix de chaque option
    return total;
}

// Affiche les informations complètes de la voiture
void Car::display() const
{
    cout << "Voiture : " << name << endl;
    cout << "Modèle  : " << model.getName() << " (" << model.getBasePrice() << " €)" << endl;
    cout << "Options :" << endl;


    for (auto opt : options)
    {
        opt->display();
    }
    cout << "Prix total : " << getPrice() << " €" << endl;
}