#include "Plansza.h"
#include "Includy.h"

int Plansza::get(int indeks, int MapaID)
{
	return Mapa[indeks][MapaID];
}

int Plansza::set(int indeks, int MapaID, int dane)
{
	if (MapaID <= 6 && MapaID > 0 && dane >= 0 && dane < 10 && indeks >= 0 && indeks < 25)
	{
		Mapa[indeks][MapaID] = dane;
		return 0;
	}
	else
		return 1;
		
}

Plansza::Plansza()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Mapa[i][j] = 0;
		}
	}
}

void Plansza::rysuj(int rzad, int MapaID)
{
	int pom = 5 * rzad;
	int GraczID = 3 + MapaID;
	if (rzad == 0)
		printf(" A    B    C    D    E  ");
	else
		for (int i = pom - 5; i < pom; i++)
		{
			int pom = 0;
			if (i % 5 == 0)
				printf("%d", rzad);
			pom = Mapa[i][MapaID];

			if (pom > 0)
			{
				if (pom == 1) printf("[MT%d]", Mapa[i][GraczID]);
				else if (pom == 2) printf("[MK%d]", Mapa[i][GraczID]);
				else if (pom == 3) printf("[MS%d]", Mapa[i][GraczID]);
				else if (pom == 4) printf("[ST%d]", Mapa[i][GraczID]);
				else if (pom == 5) printf("[SK%d]", Mapa[i][GraczID]);
				else if (pom == 6) printf("[SS%d]", Mapa[i][GraczID]);
				else if (pom == 7) printf("[DT%d]", Mapa[i][GraczID]);
				else if (pom == 8) printf("[DK%d]", Mapa[i][GraczID]);
				else if (pom == 9) printf("[DS%d]", Mapa[i][GraczID]);
			}
			else
				printf("[   ]");
		}
}

void Plansza::rysuj()
{
	
	printf("A: A    B    C    D    E    ");
	printf("B: A    B    C    D    E    ");
	printf("C: A    B    C    D    E\n");
	
	for (int i = 1; i < 6; i++)
	{
		for (int l = 0; l < 3; l++)
		{
			int GraczID = (l + 1) * 2;
			for (int j = 0; j < 5; j++)
			{
				int pom = 0;
				if (j % 5 == 0)
					printf("%d", i);

				pom = Mapa[i][l];

				if (pom > 0)
				{
					if (pom == 1) printf("[MT%d]", GraczID);
					else if (pom == 2) printf("[MK%d]", GraczID);
					else if (pom == 3) printf("[MS%d]", GraczID);
					else if (pom == 4) printf("[ST%d]", GraczID);
					else if (pom == 5) printf("[SK%d]", GraczID);
					else if (pom == 6) printf("[SS%d]", GraczID);
					else if (pom == 7) printf("[DT%d]", GraczID);
					else if (pom == 8) printf("[DK%d]", GraczID);
					else if (pom == 9) printf("[DS%d]", GraczID);
				}
				else
					printf("[   ]");
			}
			printf("  ");
		}
		printf("\n");
	}
}

int Plansza::bicie(int pionek1, int pionek2)
{
	switch (pionek1)
	{
	case 1:
		if (pionek2 == 9)
			return 0;
		else
			return 1;
	case 2:
		if (pionek2 == 1)
			return 0;
		else
			return 1;
	case 3:
		if (pionek2 == 2 || pionek2 == 1)
			return 0;
		else
			return 1;
	case 4:
		if (pionek2 == 1)
			return 0;
		else
			return 1;
	case 5:
		if (pionek2 == 4 || pionek2 == 2 || pionek2 == 1)
			return 0;
		else
			return 1;
	case 6:
		if (pionek2 == 1 || pionek2 == 2 || pionek2 == 3 || pionek2 == 4 || pionek2 == 5)
			return 0;
		else
			return 1;
	case 7:
		if (pionek2 == 4)
			return 0;
		else
			return 1;
	case 8:
		if (pionek2 == 4 || pionek2 == 5 || pionek2 == 7)
			return 0;
		else
			return 1;
	case 9:
		if (pionek2 == 4 || pionek2 == 5 || pionek2 == 6 || pionek2 == 7 || pionek2 == 8)
			return 0;
		else
			return 1;
	default:
		return 2;
	}
}

int Plansza::koordy(char a, char b)
{
	int pom = b - 48;
	if (pom < 1 || pom > 9)
		return -1;

	pom *= 5;

	if (a == 'A' || a == 'a')
		pom -= 5;
	else if (a == 'B' || a == 'b')
		pom -= 4;
	else if (a == 'C' || a == 'c')
		pom -= 3;
	else if (a == 'D' || a == 'd')
		pom -= 2;
	else if (a == 'E' || a == 'e')
		pom -= 1;
	else
		return -1;

	return pom;
}