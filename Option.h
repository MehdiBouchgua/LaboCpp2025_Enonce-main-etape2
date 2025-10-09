/*** Option.h ***/
#ifndef OPTION_H//
#define OPTION_H

#include <iostream>
#include <string>
using namespace std; // permet d'utiliser cout direment et non stdcout
/*#include "cstream"*/

namespace carconfig {

class Option {

private:
	string code;
	string label;
	float price;

public:
	Option();
	Option(const string &c,const string& l, float p);
	Option(const Option& o);
	~Option();

	//SETTER
	void setCode(const string& c);
	void setLabel(const string& l);
	void setPrice(const float p);

	//GETTERS
	string getCode()const;
	string getLabel()const;
	float getPrice()const;



	void display() const;


};

}

#endif