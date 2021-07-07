#define _CRT_SECURE_NO_WARNINGS
#include "Plansza.h"
#include "Includy.h"
#include "Gra.h"

void help();
int koordy(char a, char b);
int pionek(char a, char b);
void rozstaw_gracz1(Plansza &A, int MapaID);
void gra2();
void gra1();
void info();

int main()
{
	int a = 1;
	
	do
	{
		printf("Talat:\n1-Gra 2 osobowa\n2-Gra 3 osobowa\n3-Jak grac\n4-Wyjscie\n>");
		while (scanf("%d", &a) != 1 || a < 1 || a > 4 || getchar() != '\n')
		{
			system("cls");
			printf("Talat:\n1-Gra 2 osobowa\n2-Gra 3 osobowa\n3-Jak grac\n4-Wyjscie\nPodaj prawidlowa opcje!\n>");
			while (getchar() != '\n')
				;
		}

		switch (a)
		{
		case 1:
			gra1();
			break;
		case 2:
			gra2();
			break;
		case 3:
			system("cls");
			info();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (a != 4);

	return 0;
}

void info()
{
	printf("Zasady gry:\n");
	printf("...\n");

	help();
}

void help()
{
	printf("help- Ten ekran\n");
	printf("A2 MT-Postaw Maly Trojkat na Pierwszej kolumnie,\n Drugim wierszu\n\n");

	printf("A2-Pierwsza kolumna  Drugi wiersz\n");
	printf("MT-Maly Trojkat\n");
	printf("MK-Maly Kwadrat\n");
	printf("MS-Maly Szescian\n");
	printf("ST-Sredni Trojkat\n");
	printf("SK-Sredni Kwadrat\n");
	printf("SS-Sredni Szescian\n");
	printf("DT-Duzy Trojkat\n");
	printf("DK-Duzy Kwadrat\n");
	printf("DS-Duzy Szescian\n");
	printf("00-Puste Pole\n");
	printf("MT1-Maly Trojkat nalezacy do gracza 1-wszego\n");
}

int pionek(char a, char b)
{
	if (a == 'D' || a == 'd')
		if (b == 'S' || b == 's')
			return 9;
		else if (b == 'K' || b == 'k')
			return 8;
		else if (b == 'T' || b == 't')
			return 7;
		else
			return -1;
	else if (a == 'S' || a == 's')
		if (b == 'S' || b == 's')
			return 6;
		else if (b == 'K' || b == 'k')
			return 5;
		else if (b == 'T' || b == 't')
			return 4;
		else
			return -1;
	else if (a == 'M' || a == 'm')
		if (b == 'S' || b == 's')
			return 3;
		else if (b == 'K' || b == 'k')
			return 2;
		else if (b == 'T' || b == 't')
			return 1;
		else
			return -1;
	else if (a == '0' && b == '0')
		return 0;
	else
		return -1;
}

void rozstaw_gracz1(Plansza &A, int MapaID)
{
	int a = 10, indeks = 0, pion = 0;
	int MapaID2;
	int GraczID1, GraczID2;
	char string[255];
	bool Pionki[10] = { false };

	if (MapaID == 3)
		MapaID2 = 1;
	else
		MapaID2 = MapaID + 1;
	system("cls");
	
	GraczID1 = 3 + MapaID;
	GraczID2 = 3 + MapaID2;

	do
	{
		int i = 0;
		printf("\n");
		for (int i = 0; i < 6; i++)
		{
			if (i == 0) 
				printf("A:");
			A.rysuj(i, MapaID);
			printf("  ");
			if (i == 0) 
				printf("B:");
			A.rysuj(i, MapaID2);
			printf("\n");
		}
		printf("\nRozstaw pionki na planszy A w 5-tym rzedzie\ni na planszy B w 1-wszym rzedzie:\n>");
		while ((string[i++] = getchar()) != '\n')
			;
		
		system("cls");

		string[i - 1] = '\0';

		if (string[0] == '\n')
			printf("Wpisz komende!\n");
		else if (strcmp(string, "help") == 0 || strcmp(string, "Help") == 0 || strcmp(string, "HELP") == 0)
		{
			printf("HELP:\n");
			help();
			printf("^HELP^\n");
		}
		else if (strcmp(string, "gotowe") == 0)
		{
			int pom = 0;
			for (int i = 1; i < 10; i++)
				if (Pionki[i] == false)
					pom++;
			if (pom != 0)
				printf("Ustaw wszystkie pionki na planszy!\n");
			else
				a = 0;
		}
		else if ((indeks = A.koordy(string[0], string[1])) < 0 || string[2] != ' ')
			printf("Zla komenda!\nWpisz help aby uzyskac pomoc.\n");
		else if ((pion = pionek(string[3], string[4])) < 0 || string[5] != '\0')
			printf("Zla komenda!\nWpisz help aby uzyskac pomoc.\n");
		else if (Pionki[pion] == true && pion == 0)
			printf("Pionek juz jest na planszy!\nWybierz inny!\n");
		else if (string[1] == '5')
		{
			int pionek_na_planszy = 0;
			if ((pionek_na_planszy = A.get(indeks, MapaID)) != 0)
			{
				Pionki[pionek_na_planszy] = false;
				if (A.set(indeks, MapaID, pion))
				{
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else if (A.set(indeks, GraczID1, MapaID))
				{
					A.set(indeks, MapaID, 0);
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else
				{
					if (pion != 0)
						Pionki[pion] = true;
				}
			}
			else
			{
				if (A.set(indeks, MapaID, pion))
				{
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else if (A.set(indeks, GraczID1, MapaID))
				{
					A.set(indeks, MapaID, 0);
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else
				{
					if (pion != 0)
						Pionki[pion] = true;
				}
			}
		}
		else if (string[1] == '1')
		{
			int pionek_na_planszy = 0;
			if ((pionek_na_planszy = A.get(indeks, MapaID2)) != 0)
			{
				Pionki[pionek_na_planszy] = false;
				if (A.set(indeks, MapaID2, pion))
				{
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else if (A.set(indeks, GraczID2, MapaID))
				{
					A.set(indeks, MapaID2, 0);
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else
				{
					if (pion != 0)
						Pionki[pion] = true;
				}
			}
			else
			{
				if (A.set(indeks, MapaID2, pion))
				{
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else if (A.set(indeks, GraczID2, MapaID))
				{
					A.set(indeks, MapaID2, 0);
					printf("\nNie udalo sie przypisac pionka do wybranego miejsca na planszy!\n");	//Error
				}
				else
				{
					if (pion != 0)
						Pionki[pion] = true;
				}
			}
		}
		else
			printf("Zle koordynaty!\n");
		
	} while (a != 0);
}

void gra1()
{
	int loop = 1;
	Plansza A;

	printf("Gracz 1\n");
	system("pause");
	rozstaw_gracz1(A, 1);
	system("cls");

	printf("Gracz 2\n");
	system("pause");
	rozstaw_gracz1(A, 2);
	system("cls");

	printf("Gracz 3\n");
	system("pause");
	rozstaw_gracz1(A, 3);
	system("cls");

	do
	{



	} while (loop == 0);
}

void gra2()
{
	Plansza A;

	A.rysuj();
	system("pause");
}