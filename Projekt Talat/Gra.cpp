#include "Gra.h"
#include "Includy.h"
#include "Plansza.h"

int Gra::ruch(Plansza &A, int k1, int k2, int GraczID)
{

	if (GraczID != A.get(k1, 4))
	{
		printf("Pionek nie nalezy do gracza!");
		return 1;
	}

	if (k1 != k2)
	{

	}


	return 0;
}

void Gra::pobierz_komende(Plansza &A, int GraczID)
{
	int a = 1;
	int i = 0;
	int indeks1, indeks2;
	do
	{
		A.rysuj();

		while ((string[i++] = getchar()) != '\n' || i == 5)
			;
		system("cls");
		string[i - 1] = '\0';

		if (((indeks1 = A.koordy(string[0], string[1])) < 0 && (indeks2 = A.koordy(string[3], string[4])) < 0) || string[2] != ' ')
			printf("Zla komenda!\nWpisz help aby uzyskac pomoc.\n");
		else
			if (!ruch(A, indeks1, indeks2, GraczID))
				a = 0;

	} while (a != 0);
}