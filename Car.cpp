/*** Car.cpp ***/ 

#include "Car.h"
#include "Option.h"
#include <string.h>
#include <iostream>

using namespace std;
using namespace carconfig;

/******** Constructeur par defaut ********/

Car::Car() : name("Projet_208GTI_MrDugenou"), model("208 GTi 1.6", 200, Engine::Petrol, 34100.0f) //default model
{
    
}
/*Car::Car() {
	cout << ">>> Car = constructeur par defaut" << endl;
	name = "Projet Ford GT"; //
	Model m; //model par defaut
	setModel(m); // assignation de ce modele a la voiture a l'aide du setter
}*/

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

void Car::setModel(Model m)
{
	model.setName(m.getName());
    model.setPower(m.getPower());
    model.setEngine(m.getEngine());
    model.setBasePrice(m.getBasePrice()); //On recopie le model passé en paramètre
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

/* ========================================================
   addOption
   Ajoute une option à la voiture si elle n'existe pas déjà
   ======================================================== */
void Car::addOption(const Option &option)
{
    for(int i=0; i<5; i++)
    {
        
        if(options[i] == nullptr)
        {
            options[i] = new Option(option);
            return;
        }
    }
}

/* ========================================================
   removeOption
   Supprime une option du vector via son code
   ======================================================== */
void Car::removeOption(const string &code)
{
    bool found = false;

    for (int i = 0; i < (int)options.size(); i++)
    {
        if (options[i]->getCode() == code)
        {
            // On supprime l'élément trouvé
            options.erase(options.begin() + i);
            cout << "Option " << code << " supprimée." << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "[INFO] Option " << code << " introuvable." << endl;
    }
}


/* ========================================================
   getPrice
   Calcule le prix total (modèle + options)
   ======================================================== */
float Car::getPrice() const
{
    float total = model.getBasePrice(); // Prix de base du modèle

    // On additionne le prix de chaque option
    for (int i = 0; i < (int)options.size(); i++)
    {
        total += options[i]->getPrice();
    }

    return total;
}

/* ========================================================
   display
   Affiche le modèle, les options et le prix total
   ======================================================== */
void Car::display() const
{
    cout << "=== VOITURE ===" << endl;
    cout << "Nom : " << name << endl;

    cout << "--- Modele ---" << endl;
    model.display();

    cout << "--- Options ---" << endl;
    if (options.empty())
    {
        cout << "Aucune option." << endl;
    }
    else
    {
        for (int i = 0; i < (int)options.size(); i++)
        {
            options[i]->display();
        }
    }

    cout << "Prix total : " << getPrice() << " €" << endl;
}