#include <stdio.h>
#include <stdlib.h>

//codigo mio

void puntos(char matriz[10][10]){  //rellenar matriz con puntos
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			matriz[i][j]='.';
		}
	}
}




int main () {

	char tablero1[10][10];  //declaracion tablero 1
	char tablero2[10][10]; //declaracion tablero 2
	char fila1,fila2;        // Estos char llevaran la parte A,B,C,etc... de la coordenada
	int columna1,columna2;	//y esta parte el 1,2,3,etc... para formar algo tipo A10;
	


	puntos(tablero1);      //llenar tableros con puntos
	puntos(tablero2);     // lo mismo

	system("clear");
	printf("Guerra naval alfa 0.0.1\n\n");
	printf("Jugador 1, ingrese las coordenadas inicial y final de barco correspondiente\n");
	printf("Si la entrada no es valida el programa pedira las coordenadas nuevamente\n");
	/*de aqui para adelante surge la problematica de cual es la manera mas eficiente de 
	  escanear el ingreso de los barcos.... yo habia pensado en un ingreso de la forma:
	  A10(espacio)B9, donde si se fijan el caracter mayusculo lo leo con un char y el numero con
	  un int....segun dice la guia los casos de prueba no deben tener validacion de entrada
	  asi que eso es un alivio... por ahora.... la cosa es que hay que validar cada par de 
	  coordenadas inicio final de cada barco y ya se me agoto el cerebro por hoy, se 
	  aceptan sugerencias*/
	printf("ingrese las coordenadas del PortaAviones:");
	scanf("%c%d",&fila1,&columna1);
	getchar();
	scanf("%c%d",&fila2,&columna2);
	printf("cordenada 1: %c%d\n",fila1,columna1);
	printf("cordenada 2: %c%d\n",fila2,columna2);
	



	return 0;

}