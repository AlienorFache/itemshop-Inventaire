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

void view(object tableau[], int size, int money)
{
	printf("Vous avez : %dAg\n",money);
	for (int i = 0; i<size; i++)
	{
		if (tableau[i].price == 0)
		{
			printf("%d _ Vide\n", i);
		}
		else
		{
			printf("%d _ %s : %d\n",i ,tableau[i].name, tableau[i].price);
		}
		
		
	}
	printf("\n");
}

void buy (object tInventaire[], object tSeller[], int *money)
{
	printf("%dAg\n", *money);

	int number;
	int ok = 0;
	while ( ok != 1)
	{
		printf("Quel objet voulez vous acheter ?\n");
		scanf("%d", &number);
		if (number >= 0 && number <= 7)
		{
			ok = 1;
		}
	}

	//trouve un emplacement vide dans l'inventaire
	int i = 0;
	while (tInventaire[i].price != 0 && i <= 7)
	{
		i++;
	}

	if (i > 7)
	{
		printf("Votre inventaire est plein. Vous ne pouvez rien acheter.\n");
	}

	if (i <= 7)
	{
		tInventaire[i] = tSeller[number];
		*money -= tSeller[number].price;
		strcpy(tSeller[number].name, "\0");
		tSeller[number].price = 0;

		printf("Vous avez achetez %s.\n", tInventaire[i].name);
		printf("%dAg\n", *money);
		printf("%s\n", tSeller[number].name);

	}

}

int main ()
{
	int money = 1000;

	object poire = {"poire", 50};
	object pomme = {"pomme", 2};
	object banane = {"banane", 100};

	object tInventaire[8] = {poire, pomme, banane};
	

	object kiwi = {"kiwi", 80};
	object clementine = {"clementine", 25};
	object orange = {"orange", 75};
	object tomate = {"tomate", 150};

	object tSeller[8] = {kiwi, clementine, orange, tomate};

	sortInv(tInventaire);
	view(tInventaire, 8, money);

	sortSeller(tSeller);
	view(tSeller, 8, money);
	
	buy(tInventaire, tSeller, &money);

	return 0;
}