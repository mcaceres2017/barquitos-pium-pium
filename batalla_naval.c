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

typedef struct //esto asocia una letra "x" a cada barco
{
	char nombre1; //barco de 5
	char nombre2; //barco de 4
	char nombre3; //barco de 3
	char nombre4; //barco de 3
	char nombre5; //barco de 2
}identificador;

void danyar(char *blanco,barcosVivos* objetivo,identificador* id,int* vidas)
{
	if(*blanco==id->nombre1) // si se le apunto al barco de 5
	{
		objetivo->barcoA--; //restale uno a las "partes" de ese barco
		printf("Has disparado al Portaaviones enemigo\n");

		if(objetivo->barcoA==0) // si todos los barcos A fueron destruidos
		{
			*vidas--; //bajale uno al contador de barcos.
			printf("Destruiste el Portaaviones enemigo\n");
		}
	}
	else if (*blanco==id->nombre2) //si se le apunto al barco de 4
	{
		objetivo->barcoB--; //restale uno a las "partes" de ese barco
		printf("Has disparado al Acorazado enemigo\n");

		if(objetivo->barcoB==0)  // si todos los barcos B fueron destruidos
		{
			*vidas--;
			printf("Destruiste el Acorazado enemigo\n");
		}
	}
	else if (*blanco==id->nombre3) // barco de 3
	{
		objetivo->barcoC--;
		printf("Has disparado al Crucero enemigo\n");

		if(objetivo->barcoC==0)  // si todos los barcos C fueron destruidos
		{
			*vidas--;
			printf("Destruiste el Crucero enemigo\n");
		}
	}
	else if (*blanco==id->nombre4) // barco de 3
	{
		objetivo->barcoD--;
		printf("Has disparado al submarino enemigo\n");

		if(objetivo->barcoD==0)  // si todos los barcos D fueron destruidos
		{
			*vidas--;
			printf("Destruiste el submarino enemigo\n");
		}
	}
	else if (*blanco==id->nombre5) // barco de 2
	{
		objetivo->barcoE--;
		printf("Has disparado al destructor enemigo\n");

		if(objetivo->barcoE==0)  // si todos los barcos E fueron destruidos
		{
			*vidas--;
			printf("Destruiste el destructor enemigo\n");
		}
	}

}

void asignarNombres(char* tablero, identificador* barco) //revisado y seguro
{
	int i,j,k,aux,a,b,aux2,aux3=0;
	int contador=0,contador_aux=0;
	char nombres[5];

	a=0;

	while(a<5)
	{

		j=0;
		aux=0;
		contador=0;

		for(i=0;i<100;i++) //este for revisa las filas de la matriz
		{
			aux2=0;
			if(*(tablero+i)!='.') //si se pilla con una letra
			{
				j=*(tablero+i);   // jota copia el ASCII de esa letra

				for(b=0;b<a;b++) //se revisa si esa letra ya fue asignada a un barco
				{
					if(j==nombres[b])
					{
						aux2=1;
						break;
					}
				}

				if(aux2==1) // si es asi... se sigue al siguiente ciclo
				{
					continue;
				}

				if(aux==0)   //este if
				{
					contador++;
					aux=1;
				}

				if(*(tablero+i+1)==j) // y este if son para contar el largo del barco
				{
					contador++;
				}
				
				if(*(tablero+i+1)!=j) //si se pilla con un caracter distinto
				{
					contador_aux=contador; // se va  a guardar el tamaño del barco anterior
					aux=0;
					contador=0;
				}
				
				if(contador_aux>=2 && contador_aux<=5) // si el tamaño del barco anterior esta
				{                                      // dentro del rango, se rompe el ciclo para
					contador=contador_aux;             // guardar dicho barco.
					break;
				}
			}
		}

		if(contador>=2 && contador<=5) //si el contador esta dentro del rango del tamaño de los barcos
		{		
			nombres[a]=j; //se copia el "nombre" al comparador
			printf("se copio %c al comparador\n",j); //bandera para revisar el programa


			switch(contador)  // se asigna ese nombre al barco correspondiente segun el largo
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

		k=0;
		contador=0;
		contador_aux=0;
		j=0;
		aux=0;

		for(i=0;i<=99;i=i+10)  //esto revisa la matriz por columnas
		{
			aux2=0;

			if(*(tablero+i)!='.') //y el mismo proceso
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

				if(*(tablero+i+10)==j)
				{
					contador++;
				}

				if(*(tablero+i+10)!=j) //si se pilla con un caracter distinto
				{                      // ojo, aqui es el siguiente caracter en la columna, no en la fila
					contador_aux=contador; // se va  a guardar el tamaño del barco anterior
					aux=0;
					contador=0;
				}
				
				if(contador_aux>=2 && contador_aux<=5) // si el tamaño del barco anterior esta
				{                                      // dentro del rango, se rompe el ciclo para
					contador=contador_aux;             // guardar dicho barco.
					break;
				}
			}

			if(i>=90 && i<99) // cuando se llega a la ultima posicion de la columna
			{
				k++; //k aumenta
				i=k;  // para que i recorra la siguiente columna
			}
		}

		if(contador>=2 && contador<=5) //si el contador esta dentro del rango
		{

			nombres[a]=j; // se copia el "nombre" al comparador
			printf("se copio %c al comparador\n",j);

			switch(contador) // y se asigna la letra al barco correspondiente
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
}

void punteria(char *blanco,char *pantalla,barcosVivos* objetivo,identificador* id,int *p,int* vidas) //revisado
{
	if(*blanco>='A' && *blanco<='Z') //si se esta dentro de rango
	{
		danyar(blanco,objetivo,id,vidas); // se llama a danyar 
		printf("blanco apuntaba a=%c pantalla apuntaba a=%c\n",*blanco,*pantalla);
		*blanco='+'; // y se sobreescribe esa letra con un + que significa acertado
		*pantalla='+'; //en la matriz que se muestra por pantalla igual se vuelve mas
		printf("blanco apunta a=%c pantalla apunta a=%c\n",*blanco,*pantalla);
		printf("acertaste dispara de nuevo\n");
	}

	else if(*blanco=='-' || *blanco=='+') // si se apunto a un lugar al cual ya se habia apuntado
	{
		printf("disparo invalido, apunte nuevamente:\n");
	}

	else //este else es para cuando se apunta al agua
	{
		printf("blanco apuntaba a=%c pantalla apuntaba a=%c\n",*blanco,*pantalla);
		*blanco='-'; //se copia un menos de tiro fallido
		*pantalla='-'; //se copia un menos a la matriz que se muestra
		printf("blanco apunta a=%c pantalla apunta a=%c\n",*blanco,*pantalla);
		printf("disparo al agua\n");

		if(*p==1) // y se cambia de jugador
		{
			*p=2;
		}

		else if(*p==2)
		{
			*p=1;
		}
	}
}

void RellenarMatriz(char *matriz)  //comprobado
{
	int i;
	for(i=0;i<100;i++) //rellena la matriz de puntos
	{
		*(matriz+i)='.';
	}
}

char * obtenerBlanco(int n, char cordenadas[n], char *matriz) //revisado
{	
	int i=0,k;
	int j=0;
	char *blanco;

	i=cordenadas[0]-'A'; //traspaso de letra a entero

	for(k=1;k<n;k++) // traspaso de numero caracter a numero entero
	{
		j=j*10+(cordenadas[k]-'0');
	}

	j--; //restar uno porque la matriz empieza en cero

	blanco=&(*(matriz+(i*10+j))); //blanco copia la direccion de memoria del caracter apuntado
	printf("blanco apunta hacia la posicion %d\n",0+(i*10+j));
	return blanco; //y se retorna un puntero, ojo.
}

void ingresarMatriz(char *matriz)//puntero tomado por la funcion //funciona
{
	int i,c;

	for(i=0;i<100;)
	{
		c=fgetc(stdin);//lee un caracter

		if(c!='\n')//si el caracter no es salto de linea
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
	char disparo[3]; // vector que guarda la coordenada apuntada
	
	char tablero_de_juego1[10][10];
	char tablero_de_juego2[10][10]; //declaracion  de los tableros visibles para los jugadores

	int i,j,c,aux,contador,p=1;
	char *pt1=&tablero_de_barcos1[0][0];
	char *pt2=&tablero_de_barcos2[0][0];
	char *pt3=&tablero_de_juego1[0][0];
	char *pt4=&tablero_de_juego2[0][0];
	int *turno=&p;

	RellenarMatriz(pt3);
	RellenarMatriz(pt4);

	barcosVivos flota1={5,4,3,3,2}; //barcos del jugador 1
	barcosVivos flota2={5,4,3,3,2}; //barcos del jugador 2

	identificador j1;  //nombres de los barcos p1
	identificador j2;  //nombres de los barcos p2

	printf("jugador 1 ingrese la posicion de sus barcos\n");

	
	ingresarMatriz(pt1); //se le pide al jugador ingresar la matriz
	asignarNombres(pt1,&j1);   //y se asignas los nombres a cada barco

	printf("jugador 2 ingrese la posicion de sus barcos\n");

	ingresarMatriz(pt2);
	asignarNombres(pt2,&j2);

	int barcos_de_jugador_1=5; 
	int barcos_de_jugador_2=5; //contadores para barcos restantes
	char *ca; //cordenada apuntada.. guarda la direccion de memoria del lugar al que se apunto de la matriz de barcos
	char *cp; // cordenada pantalla guarda la direccion de memoria del lugar al que se apunto de la matriz de juegos

	printf("Mostrando matriz jugador 1\n"); //para revisar

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%c",tablero_de_barcos1[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	printf("Mostrando matriz jugador 2\n"); //para revisar

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%c",tablero_de_barcos2[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	while(barcos_de_jugador_1>0 && barcos_de_jugador_2>0) // condicion del ternimo de juego
	{

		if(p==1) //imprime la matriz que se muestra por pantalla
		{
			printf("\n\n\n\n"); //estos son solo para separar entre disparo y disparo
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					printf("%c",tablero_de_juego2[i][j]);
				}

				printf("\n");
			}
		}

		if(p==2) //imprime la matriz que se muestra por pantalla
		{
			printf("\n\n\n\n"); //estos son solo para separar entre disparo y disparo
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{
					printf("%c",tablero_de_juego1[i][j]);
				}

				printf("\n");
			}
		}

		
		if (p==1)
		{
			printf("jugador 1, dispare.\n");
		}	

		if (p==2)
		{
			printf("jugador 2, dispare.\n");
		}

		printf("Disparo:");
		
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
				printf("aux=%d\n",aux);

			}
			if (aux==1)
			{
				printf("Dispare correctamente.\n");
			}

		}while(aux==1);

		
		if(p==1) //se obtiene la direccion de memoria del lugar al que se apunto, tanto para la matriz que
		{        //se muestra como para la matriz de barcos enemiga
			ca=obtenerBlanco(contador,disparo,pt2);
			cp=obtenerBlanco(contador,disparo,pt4);
		}

		if(p==2)
		{
			ca=obtenerBlanco(contador,disparo,pt1);
			cp=obtenerBlanco(contador,disparo,pt3);
		}
		
		printf("cordenada apuntada=%c cordenada pantalla=%c\n",*ca,*cp);

		if(p==1) // si es el turno del J1
		{
			punteria(ca,cp,&flota2,&j2,turno,&barcos_de_jugador_2);
			continue; //si el j1 fallo, esto evita que se meta al if del p2 inmediatamente despues
		} 

		if(p==2) // si es el turno del J2
		{
			punteria(ca,cp,&flota1,&j1,turno,&barcos_de_jugador_1);
		}		
	}

	printf("el juego termino\n");

	if(barcos_de_jugador_2==0)
	{
		printf("gana el jugador uno\n");
	}

	if(barcos_de_jugador_1==0)
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


/*AAAAABBBB.         
CCCDDDEE..
..........
..........
..........
..........
..........
..........
..........
..........*/

