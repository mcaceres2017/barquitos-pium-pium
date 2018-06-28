#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


int main () {

	SDL_Surface *fondo=NULL; //superficie en negro 
	SDL_Surface *boton=NULL; //superficie para boton
	SDL_Surface *presionado=NULL;  //superficie para cuando el mouse esta sobre el boton
	SDL_Texture *textura=NULL;  //textura
	SDL_Window  *pantalla=NULL;   //pantalla
	SDL_Renderer * render=NULL;   //renderizado de la pantalla
	SDL_Rect posBot;         //rectangulo para el boton
	posBot.x=300;            //posicion inicial x del boton... esquina superior izquierda
	posBot.y=200;			//posicion inicial y del boton... esquina superior izquierda
	posBot.h=200;			//alto del boton
	posBot.w=200;			//ancho del boton

	SDL_Event evento;    //evento
 


	SDL_Init(SDL_INIT_VIDEO);    //iniciamos video






	pantalla= SDL_CreateWindow ("barquitos 2000 remastered",   //creamos pantalla
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  600,
                                  SDL_WINDOW_RESIZABLE);


	render=SDL_CreateRenderer(pantalla, -1, 0);   //creamos el render

	boton= IMG_Load("./1.png");    //cargamos imagen 1
	presionado= IMG_Load("./2.png");  //cargamos imagen 2



	int x,y;   //variables para monitorear la posicion del mouse





	while(1){  //ciclo infinito

		while(SDL_PollEvent(&evento)){  //ciclo para la piscina de eventos

			SDL_RenderClear(render);
			fondo=SDL_CreateRGBSurface(0,800,600,32,0,0,0,0);  //creamos una superficie negra

			SDL_GetMouseState(&x,&y);  //monitoreamos el mouse... esto te devuelve la posicion x e y actuales del mouse


			if(x>=300 && x<=500 && y>=200 && y<=400){   //si el mouse esta sobre del "rectangulo" del boton...
														// se muestra la imagen 2

				SDL_BlitScaled(presionado,NULL,fondo,&posBot);


				if(evento.type==SDL_MOUSEBUTTONDOWN){ //si se presiona la "imagen 2" se cierra el programa
					
					if(evento.button.button == SDL_BUTTON_LEFT){  //evento.button.button revisa si es que se ha presionado
																 // un boton... puede ser
																  //SDL_BUTTON_LEFT =click izquierdo
																 //SDL_BUTTON_RIGHT= click derecho
																  //SDL_BUTTON_MIDDLE= click de la rueda
						SDL_FreeSurface(fondo);
						SDL_Quit();
						return 0;
					}
				}

			}

			else{  //si el mouse no esta sobre el "rectangulo" del boton... muestra la imagen uno

				SDL_BlitScaled(boton,NULL,fondo,&posBot);
			}


			if(evento.type==SDL_QUIT){  //si es que apretamos la equis de la ventana

				SDL_FreeSurface(fondo);
				SDL_Quit();
				return 0;

			}

			textura=SDL_CreateTextureFromSurface(render,fondo);  // creamos la textura
			SDL_FreeSurface(fondo);  //liberamos fondo porque a cada rato tenemos que saber cual imagen mostrar.. si la uno o la dos
			SDL_RenderCopy(render, textura, NULL, NULL); //copiamos la textura al render (la pantalla)
			SDL_DestroyTexture(textura);
			SDL_RenderPresent(render);   // y mostramos el render

		}  //cierre del while de la piscina de eventos

	}	//cierre del while infinito

}  //cierre del main