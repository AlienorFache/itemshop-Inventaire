#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Object 
{
	char name[10];//ne pas ecrire plus de 9 char
	int price;
	
};
typedef struct Object object;

void sort(object tInventaire[])
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

	for (int i = 0; i<3; i++)
	{
		printf("%s : %d\n",tInventaire[i].name, tInventaire[i].price);
	}

}

int main ()
{
	object poire = {"poire", 50};
	object pomme = {"pomme", 2};
	object banane = {"banane", 100};
	

	object tInventaire[3] = {poire, pomme, banane};
	
	sort(tInventaire);
	
	return 0;
}