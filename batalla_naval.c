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

typedef struct 
{
	char nombre1;
	char nombre2;
	char nombre3;
	char nombre4;
	char nombre5;
}identificador;

void punteria(char blanco)
{
	if(blanco)
}

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
	int i,k;
	int j=0;
	char blanco;

	i=cordenadas[0]-'A'; //traspaso de letra a entero

	for(k=1;k<n;k++) // traspaso de numero caracter a numero entero
	{
		j=j*10+(cordenadas[k]-'0');
	}

	j--; //restar uno porque la matriz empieza en cero

	blanco=*(matriz+(i*10+j)); //blanco copia el caracter apuntado

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
	
	char tablero_de_juego1[10][10];
	char tablero_de_juego2[10][10]; //declaracion  de los tableros visibles para los jugadores

	int i,j,c,aux,contador,p;
	char *pt1=&tablero_de_barcos1[0][0];
	char *pt2=&tablero_de_barcos2[0][0];
	char *pt3=&tablero_de_juego1[0][0];
	char *pt4=&tablero_de_juego2[0][0];

	RellenarMatriz(pt3);
	RellenarMatriz(pt4);

	barcosVivos flota1={5,4,3,3,2}; //barcos del jugador 1
	barcosVivos flota2={5,4,3,3,2}; //barcos del jugador 2

	printf("jugador 1 ingrese la posicion de sus barcos\n");

	
	ingresarMatriz(pt1);

	printf("jugador 2 ingrese la posicion de sus barcos\n");

	ingresarMatriz(pt2);

	int barcos_de_jugador_1=5;
	int barcos_de_jugador_2=5;
	char cordenada_apuntada;

	while(barcos_de_jugador_1>0 && barcos_de_jugador_2>0) // condicion del ternimo de juego
	{
		/*if (p==1)
		{*/
		
		printf("jugador 1, dispare.\n");	
		do
		{

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

				if(contador==0 && (c<'A' || c>'J')) // si es la primera cordenada y la entrada no es una letra
				{
					aux=1;
				}
				
				if(contador==0 && (c>='A' || c<='J'))
				{
					contador++;
				}

				if(contador==1 && (c<'1' || c>'9')) // si es la segunda cordenada y la entrada no es un numero
				{
					aux=1;
				}


				if (contador==1 && c=='1')
				{
					contador++;
				}

				if (contador==2 && c!='0')
				{
					c=0;
					disparo[contador]=c;
					aux=1;
				}

			}
			if (aux==1)
			{
				printf("Dispare correctamente.\n");
			}

		}while(aux==1);

		cordenada_apuntada=obtenerBlanco(contador,disparo,pt1);
		if (cordenada_apuntada=='A')
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
			if(p==1)
			{
				p=2;
			}
			if(p==2)
			{
				p=1;
			}
		}


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

/*poner mensajes para p1 y p2... cambiar un par de weas con if's*/