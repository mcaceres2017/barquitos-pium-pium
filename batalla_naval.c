#include <stdio.h>
#include <stdlib.h>

void ingresarMatriz(char *matriz)
{
	int i,c;

	for(i=0;i<100;)
	{
		c=fgetc(stdin);

		if(c!='\n')
		{
			*(matriz+i)=c;
			i++;
		}
	}
}

int main()
{
	char tablero_de_barcos1[10][10];
	char tablero_de_barcos2[10][10]; //declaracion de los tableros de posiocion de barcos

	int tablero_de_juego1[10][10]={0};
	int tablero_de_juego2[10][10]={0}; //declaracion  de los tableros visibles para los jugadores

	int i,j,c,aux;
	char *pt;

	struct barcos	// estructura de los barcos
	{

		int barcoA; //barco de 5
		int barcoB;	//barco de 4
		int barcoC;	//barco de 3
		int barcoD; //barco de 3
		int barcoE; //barco de 2
	};

	struct barcos jugador1={5,4,3,3,2}; //barcos del jugador 1
	struct barcos jugador2={5,4,3,3,2}; //barcos del jugador 2

	printf("jugador 1 ingrese la posiocion de sus barcos\n");

	pt=&tablero_de_barcos1[0][0];

	ingresarMatriz(pt);

	printf("jugador 2 ingrese la posiocion de sus barcos\n");

	pt=&tablero_de_barcos2[0][0];

	ingresarMatriz(pt);

	/*for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%c",tablero_de_barcos1[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%c",tablero_de_barcos2[i][j]);
		}

		printf("\n");
	}

	printf("\n");*/

	return 0;
}