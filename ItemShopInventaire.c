#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Object 
{
	char name[11];//ne pas ecrire plus de 10 char
	int price;
	
};
typedef struct Object object;

void sortInv(object tInventaire[])
{
	for (int i = 2; i > 0; i--)
	{
		
		for (int j = 0; j < i; j++)
		{
			
			if (strcmp(tInventaire[j].name, tInventaire[j+1].name) > 0)
			{
				
				object copie;
				copie = tInventaire[j+1];
				tInventaire[j+1] = tInventaire[j];
				tInventaire[j] = copie;

			}
		}
	}
}

void sortSeller (object tSeller[])
{
	for (int i = 3; i > 0; i--)
	{
		
		for (int j = 0; j < i; j++)
		{
			
			if (tSeller[j].price > tSeller[j+1].price)
			{
				
				object copie;
				copie = tSeller[j+1];
				tSeller[j+1] = tSeller[j];
				tSeller[j] = copie;

			}
		}
	}
}

void view(object tableau[], int size)
{
	for (int i = 0; i<size; i++)
	{
		printf("%s : %d\n",tableau[i].name, tableau[i].price);
	}
	printf("\n");
}

int main ()
{
	object poire = {"poire", 50};
	object pomme = {"pomme", 2};
	object banane = {"banane", 100};

	object tInventaire[3] = {poire, pomme, banane};
	

	object kiwi = {"kiwi", 80};
	object clementine = {"clementine", 25};
	object orange = {"orange", 75};
	object tomate = {"tomate", 150};

	object tSeller[4] = {kiwi, clementine, orange, tomate};

	sortInv(tInventaire);
	view(tInventaire, 3);

	sortSeller(tSeller);
	view(tSeller, 4);
	
	return 0;
}