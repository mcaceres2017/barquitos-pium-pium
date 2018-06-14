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

void danyar(char *blanco,barcosVivos* objetivo,identificador* id,int* vidas)
{
	if(*blanco==id->nombre1)
	{
		objetivo->barcoA--;

		if(objetivo->barcoA==0) // si todos los barcos A fueron destruidos
		{
			*vidas--;
		}
	}
	else if (*blanco==id->nombre2)
	{
		objetivo->barcoB--;

		if(objetivo->barcoB==0)  // si todos los barcos B fueron destruidos
		{
			*vidas--;
		}
	}
	else if (*blanco==id->nombre3)
	{
		objetivo->barcoC--;

		if(objetivo->barcoC==0)  // si todos los barcos C fueron destruidos
		{
			*vidas--;
		}
	}
	else if (*blanco==id->nombre4)
	{
		objetivo->barcoD--;

		if(objetivo->barcoD==0)  // si todos los barcos D fueron destruidos
		{
			*vidas--;
		}
	}
	else if (*blanco==id->nombre5)
	{
		objetivo->barcoE--;

		if(objetivo->barcoE==0)  // si todos los barcos E fueron destruidos
		{
			*vidas--;
		}
	}
	/*ver a la wea que achunto
	restar barcos barcosVivos
	si barco qlo cero, restar uno a vidas.*/

}

void asignarNombres(char* tablero, identificador* barco) //revisado y seguro
{
	int i,j,k,aux,a,b,aux2,aux3=0;
	int contador=0;
	char nombres[5];

	a=0;

	while(a<5)
	{

		j=0;
		aux=0;

		for(i=0;i<100;i++)
		{
			aux2=0;
			if(*(tablero+i)!='.')
			{
				j=*(tablero+i);

				for(b=0;b<a;b++)
				{
					if(j==nombres[b])
					{
						aux2=1;
						break;
					}
				}

				if(aux2==1)
				{
					continue;
				}

				if(aux==0)
				{
					contador++;
					aux=1;
				}

				if(*(tablero+i+1)==j)
				{
					contador++;
				}
			}
		}

		nombres[a]=j;


		switch(contador)
		{
			case 5: barco->nombre1=j;
					break;
			case 4: barco->nombre2=j;
					break;
			case 3: if(aux3==0)
					{
						barco->nombre3=j;
						aux3=1;	
					}

					else
					{
						barco->nombre4=j;
					}

					break;
			case 2: barco->nombre5=j;
					break;
		}
		a++;

		k=0;
		contador=0;
		j=0;
		aux=0;

		for(i=0;i<=99;i=i+10)
		{
			aux2=0;

			if(*(tablero+i)!='.')
			{
				j=*(tablero+i);

				for(b=0;b<a;b++)
				{
					if(j==nombres[b])
					{
						aux2=1;
						break;
					}
				}
			
				if(aux2==1)
				{
					continue;
				}

				if(aux==0)
				{
					contador++;
					aux=1;
				}

				if(*(tablero+i+1)==j)
				{
					contador++;
				}
			}

			if(i>=90)
			{
				k++;
				i=k;
			}
		}

		nombres[a]=j;

		switch(contador)
		{	
			case 5: barco->nombre1=j;
					break;
			case 4: barco->nombre2=j;
					break;
			case 3: if(aux3==0)
					{
						barco->nombre3=j;
						aux3=1;	
					}

					else
					{
						barco->nombre4=j;
					}

					break;
			case 2: barco->nombre5=j;
					break;
		}
		a++;
	}
}

void punteria(char *blanco,barcosVivos* objetivo,identificador* id,int *p,int* vidas) //revisado
{
	if(*blanco>='A' && *blanco<='Z')
	{
		danyar(blanco,objetivo,id,vidas); // funcion para dañar

		*blanco='+';
		printf("acertaste dispara de nuevo\n");
	}

	else if(*blanco=='-' || *blanco=='+')
	{
		printf("dispare invalide, apunte nuevemente:\n");
	}

	else
	{
		*blanco='-';

		if(*p==1)
		{
			*p=2;
		}

		if(*p==2)
		{
			*p=1;
		}
	}
}

void RellenarMatriz(char *matriz)  //comprobado
{
	int i;
	for(i=0;i<100;i++)
	{
		*(matriz+i)='.';
	}
}

char obtenerBlanco(int n, char cordenadas[n], char *matriz) //revisado
{	
	int i,k;
	int j=0;
	char blanco;

	i=cordenadas[0]-'A'; //traspaso de letra a entero

	for(k=1;k<n-1;k++) // traspaso de numero caracter a numero entero
	{
		j=j*10+(cordenadas[k]-'0');
	}

	j--; //restar uno porque la matriz empieza en cero

	blanco=*(matriz+(i*10+j)); //blanco copia el caracter apuntado

	return blanco; 
}

void ingresarMatriz(char *matriz)//puntero tomado por la funcion //funciona
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
	char tablero_de_barcos2[10][10]; //declaracion de los tableros de posicion de barcos
	char disparo[3];
	
	char tablero_de_juego1[10][10];
	char tablero_de_juego2[10][10]; //declaracion  de los tableros visibles para los jugadores

	int i,j,c,aux,contador,p=1;
	char *pt1=&tablero_de_barcos1[0][0];
	char *pt2=&tablero_de_barcos2[0][0];
	char *pt3=&tablero_de_juego1[0][0];
	char *pt4=&tablero_de_juego2[0][0];
	int *turno=&p;
	char *pos;

	RellenarMatriz(pt3);
	RellenarMatriz(pt4);

	barcosVivos flota1={5,4,3,3,2}; //barcos del jugador 1
	barcosVivos flota2={5,4,3,3,2}; //barcos del jugador 2

	identificador j1;
	identificador j2;

	printf("jugador 1 ingrese la posicion de sus barcos\n");

	
	ingresarMatriz(pt1);
	asignarNombres(pt1,&j1);

	printf("jugador 2 ingrese la posicion de sus barcos\n");

	ingresarMatriz(pt2);
	asignarNombres(pt2,&j2);

	int barcos_de_jugador_1=5;
	int barcos_de_jugador_2=5;
	char cordenada_apuntada;

	while(barcos_de_jugador_1>0 && barcos_de_jugador_2>0) // condicion del ternimo de juego
	{
		
		if (p==1)
		{
			printf("jugador 1, dispare.\n");
		}	
		
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

				if(contador==1 && (c<'1' || c>'9')) // si es la segunda cordenada y la entrada no es un numero
				{
					aux=1;
				}

				if (contador==2 && c!='0')
				{
					c=0;
					disparo[contador]=c;
					aux=1;
				}

				contador++;

			}
			if (aux==1)
			{
				printf("Dispare correctamente.\n");
			}

		}while(aux==1);

		cordenada_apuntada=obtenerBlanco(contador,disparo,pt1);
		pos=&cordenada_apuntada;

		if(p==1) // si es el turno del J1
		{
			punteria(pos,&flota2,&j2,turno,&barcos_de_jugador_2);
			continue;
		}

		if(p==2) // si es el turno del J2
		{
			punteria(pos,&flota1,&j1,turno,&barcos_de_jugador_1);
			continue;
		}
	}

	printf("el juego termino\n");

	if(barcos_de_jugador_1!=0)
	{
		printf("gana el jugador uno\n");
	}

	else
	{
		printf("gana el jugador dos\n");
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
/*funcion dañar recibe pos y un puntero a las estructuras identificador de j1 y j2*/