#pragma once
#ifndef Plansza_h
#define Plansza_h

class Plansza
{
private:
	int Mapa[25][6];	//	0-Plasza	1-Plasza	2-Plasza	3-GraczID1	4-GraczID2	5-GraczID3
public:
	Plansza();
	int get(int indeks, int MapaID);
	int set(int indeks, int MapaID, int dane);	//0-operacja powiod�a si�	1-operacja nie powiod�a si�
	void rysuj(int rzad, int MapaID);
	void rysuj();
	int bicie(int pionek1, int pionek2);	//0-zbity	1-nie mo�e bi�	2-B��dne dane
	int koordy(char a, char b);
};

#endif // !Plansza.h

