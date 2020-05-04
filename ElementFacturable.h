#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class ElementFacturable {
protected:	//Est-ce qu'il fallait quand m�me avoir les attributs en tant que priv�s et avoir des accesseurs � la place?
	const double TAXE_BASE = 1.08;
	string nom;
	double prix;

public:
	ElementFacturable(string _nom, double _prix);
	virtual ~ElementFacturable() {};
	virtual void afficherElement() const;

	virtual double calculerTotal() const { return this->prix; }; 
	virtual double calculerTotalPlusTaxe() const { return (calculerTotal() * TAXE_BASE); };
};