#pragma once
#include <map>
#include "FacturableParUnite.h"
#include "FacturableFraisFixe.h"

class Facture {
private:
	map<int, ElementFacturable*> map_elements;

public:
	Facture() {};
	~Facture();

	void ajouterNuit(double _prix, int _quantite);
	void ajouterRepas(double _prix, int _quantite);
	void ajouterSpa(double _prix);
	void ajouterGym(double _prix);
	void afficherFacture();

	void VerifierDuplique(int _rang);

	void retirerNuit();
	void retirerRepas();
	void retirerSpa();
	void retirerGym();
};