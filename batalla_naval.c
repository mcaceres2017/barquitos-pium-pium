#include <stdio.h>
#include <stdlib.h>

typedef struct // vidas
	{

		int barcoA; //barco de 5
		int barcoB;	//barco de 4
		int barcoC;	//barco de 3
		int barcoD; //barco de 3
		int barcoE; //barco de 2
	}barcosVivos;

void RellenarMatriz(char *matriz)
{
	int i;
	for(i=0;i<100;i++)
	{
		*(matriz+i)='.';
	}
}

char obtenerBlanco(int n, char cordenadas[n], char *matriz)
{	
	int j,k;
	int i=0;
	char blanco;

	j=cordenadas[0]-'A';

	for(k=1;k<n;k++)
	{
		i=i*10+(cordenadas[k]-'0');
	}

	i--;

	blanco=*(matriz+(i*10+j));
	*(matriz+(i*10+j))='.';

	return blanco;

}

void ingresarMatriz(char *matriz)//puntero tomado por la funcion
{
	int i,c;

	for(i=0;i<100;)
	{
		c=fgetc(stdin);//lee un caracter

		if(c!='\n' )//si el caracter no es salto de linea
		{
			*(matriz+i)=c; // aquello apuntado por el puntero es igual al caracter ingresado
			i++; //i sirve para desplazar a donde apunta el puntero en la matriz
		}
	}
}

int main()
{
	char tablero_de_barcos1[10][10];
	char tablero_de_barcos2[10][10]; //declaracion de los tableros de posiocion de barcos
	char disparo[3];
	
	int tablero_de_juego1[10][10];
	int tablero_de_juego2[10][10]; //declaracion  de los tableros visibles para los jugadores

	int i,j,c,aux,contador,p;
	char *pt1=&tablero_de_barcos1[0];
	char *pt2=&tablero_de_barcos2[0];
	char *pt3=&tablero_de_juego1[0];
	char *pt4=&tablero_de_juego2[0];

	RellenarMatriz(pt3);
	RellenarMatriz(pt4);

	barcosVivos flota1={5,4,3,3,2}; //barcos del jugador 1
	barcosVivos flota2={5,4,3,3,2}; //barcos del jugador 2

	printf("jugador 1 ingrese la posiocion de sus barcos\n");

	
	ingresarMatriz(pt1);

	printf("jugador 2 ingrese la posiocion de sus barcos\n");

	ingresarMatriz(pt2);

	int barcos_de_jugador_1=5;
	int barcos_de_jugador_2=5;
	char cordenada_apuntada;

	while(barcos_de_jugador_1>0 && barcos_de_jugador_2>0) // condicion del ternimo de juego
	{
		if (p==1)
		{
			
		do
		{
			printf("jugador 1, dispare\n");

			aux=0; // auxiliar para las entradas invalidas
			contador=0; // contador para medir el largo de la entrada

			while((c=fgetc(stdin))!='\n')// lee hasta el salto de linea
			{
				if(contador<3) // si esta dentro del rango
				{
					disparo[contador]=c;
				}

				else
				{
					aux=1;
				}

				if(contador==0 && (c<'A' || c>'j')) // si es la primera cordenada y la entrada no es una letra
				{
					aux=1;
				}

				if(contador==1 && (c<'0' || c>'9')) // si es la segunda cordenada y la entrada no es un numero
				{
					aux=1;
				}

				else if (contador==1 && c=='1')
				{
					contador++;
					disparo[contador]=c;
				}
				if (contador==2 && c!='0')
				{
					c=NULL;
					disparo[contador]=c;
				}
			}

		}while(aux==1);

		cordenada_apuntada=obtenerBlanco(contador,disparo,pt1);
		if (cordenada_apuntada='A')
		{
			
		}
		else if (cordenada_apuntada=='B')
		{
			
		}
		else if (cordenada_apuntada=='C')
		{
			
		}
		else if (cordenada_apuntada=='D')
		{
			
		}
		else if (cordenada_apuntada=='E')
		{
			
		}
		else 
		{

		}
		p++;

	}

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