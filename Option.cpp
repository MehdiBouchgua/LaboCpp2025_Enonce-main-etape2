/**** Option.cpp ***/

#include "Option.h"
#include <iostream>

using namespace std;

namespace carconfig {

// CONSTRUCTEUR PAR DEFAUT
Option::Option() : code(""), label(""), price(0.0f) 
{
	//Initialisation avec des valeurs neutre donc rien a faire ici
}

// CONSTRUCTEUR INITIALISATION
Option::Option(const string &c, const string &l, float p) : code(c), label(l), price(p)
{
	cout << ">>> Constructeur d'initialisation de Option" << endl;// Valeur assigné avant l'exec
}

//Constructeur de copie
Option::Option(const Option &o) : code(o.code), label(o.label), price(o.price)
{

}

//DESTRUCTEUR

Option::~Option()
{
	// String et float se détruisent tout seul
}



// SETTERS (modifie attribut private)


// Change le code de l'option
void Option::setCode(const string &c)
{
	code = c;
}
//Change le libellé 
void Option::setLabel(const string &l)
{
	label = l;
}

//change le prix
void Option::setPrice(float p)
{
	price = p;
}

//GETTERS  (permet la lecture Private)

//renvoi le code
string Option::getCode() const
{
	return code;
}

//Renvoi Libellé...
string Option::getLabel() const
{
	return label;
}

float Option::getPrice() const // ne s'applique pas au float mais a l'objet (THIS) par lequel la methode est appelé
{
	return price;
}

//Méthode d'affichage
void Option::display() const
{
	cout << "Code : " << code << " | Label : " << label << " | Prix : " << price << "€" << endl;
}

}