#pragma once
#ifndef Gra_h
#define Gra_h
#include "Plansza.h"

class Gra
{
	char string[6];
private:
	int ruch(Plansza &A, int k1, int k2, int GraczID);
public:
	void pobierz_komende(Plansza &A, int GraczID);
};
/*
class AI : public Gra
{
public:
	void generuj_ruch();
};*/

#endif // !Gra_h
