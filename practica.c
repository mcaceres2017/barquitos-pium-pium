
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void iniciarPantalla(SDL_Surface *pantalla)
{
	pantalla=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

	if(pantalla==NULL)
	{
		fprintf(stderr,"error al iniciar la pantalla %s\n",SDL_GetError());
		exit(1);
	}
}

void recargarPantalla(SDL_Surface *pantalla, SDL_Surface *imagen, int mat[10][10])
{
	int i,j;

	SDL_Rect destino;

	destino.h=imagen->h;
	destino.w=imagen->w;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(mat[i][j]==1)
			{
				destino.x=i*100;
				destino.y=j*100;
				SDL_BlitSurface(imagen,NULL,pantalla,&destino);
			}
		}
	}

	SDL_Flip(pantalla);
}

int main()
{	
	int matriz[10][10],i,j; //matriz de la posicion de imagenes
	int contador,aux;

	for(i=0;i<10;i++) // la rellenamos de ceros
	{
		for(j=0;j<10;j++)
		{
			matriz[i][j]=0;
		}
	}
	
    SDL_Surface *pantalla, *imagen, *negro;

    SDL_Event evento; 

    // Variable auxiliar dónde almacenaremos la posición dónde colocaremos
    // la imagen dentro de la superficie principal

    SDL_Rect destino;


    // Iniciamos el subsistema de video de SDL

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr,"No se pudo iniciar SDL: %s\n", SDL_GetError());
    exit(1);
    }

    atexit(SDL_Quit);


    // Comprobamos que sea compatible el modo de video

    if(SDL_VideoModeOK(1000, 1000, 32, SDL_SWSURFACE) == 0) {
   
   fprintf(stderr, "Modo no soportado: %s\n", SDL_GetError());
   exit(1);
   
    }
    
    // Establecemos el modo de video y asignamos la superficie
    // principal a la variable pantalla

    pantalla = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE);

    if(pantalla == NULL) {
    fprintf(stderr, "No se puede inicializar el modo gráfico: %s",\
       SDL_GetError());
    }


	imagen=SDL_LoadBMP("/home/carlos/Escritorio/ajuste_sdl.bmp");

	if(imagen == NULL)
	{
		fprintf(stderr,"error al hacer load %s\n",SDL_GetError());
		exit(1);
	}

	if(SDL_SaveBMP(imagen,"./ajuste_sdl.bmp")<0)
	{
		fprintf(stderr,"error al hacer save %s\n",SDL_GetError());
		exit(1);
	}

	imagen->h=100; // tamaño de imagen
	imagen->w=100;

	destino.x=0; // le ponemos los valores a destino
	destino.y=0;
	destino.h=imagen->h;
	destino.w=imagen->w;


	if(SDL_BlitSurface(imagen,NULL,pantalla,&destino)<0) // hacemos el primer bliting
	{
		fprintf(stderr,"error al hacer bliting %s\n",SDL_GetError());
		exit(1);
	}

	SDL_Flip(pantalla);

	if(pantalla==NULL)
	{
		fprintf(stderr,"error al cargar %s\n",SDL_GetError());
		exit(1);
	}

	aux=0;
	contador=0;

	for(;;)
	{
		while(SDL_PollEvent(&evento))
		{
			if(evento.type==SDL_QUIT) // para salir
			{
				SDL_FreeSurface(imagen);
				return 0;
			}

			if(evento.type==SDL_KEYDOWN) // si presionamos una tecla
			{
				SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY ,SDL_DEFAULT_REPEAT_INTERVAL); // para detectar que la tecla de mantiene pulsada

				switch(evento.key.keysym.sym)
				{
					case SDLK_UP: destino.y-=100; //si es arriba
								if(destino.y<0)
								{
									destino.y=0;
								}

								break;

					case SDLK_DOWN: destino.y+=100; // si es abajo
								if(destino.y>900)
								{
									destino.y=900;
								}

								break;


					case SDLK_RIGHT: destino.x+=100; // si es derecha
								if(destino.x>900)
								{
									destino.x=900;
								}

								break;


					case SDLK_LEFT: destino.x-=100; // si es izquierda
								if(destino.x<0)
								{
									destino.x=0;
								}

								break;
					case SDLK_a: if(aux==0) // si es a
								{
 									matriz[destino.x/100][destino.y/100]=1; // marcamos la posicion
 									contador++;
								}

								else
								{
									if(matriz[destino.x/100][destino.y/100]==1)
									{
										contador--;
									}

									matriz[destino.x/100][destino.y/100]=0;
								}

								if(contador==10) // cambiamos de poner a quitar
								{
									aux=1;
								}
				}

				pantalla = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE); // volvemos todo negro
				SDL_Flip(pantalla);

				recargarPantalla(pantalla,imagen,matriz); // reponemos las imagenes segun la matriz de sus posiciones

				SDL_BlitSurface(imagen,NULL,pantalla,&destino); // blit a la imagen desplazada
				SDL_Flip(pantalla);

				if(contador==0 && aux==1)
				{
					return 0;
				}
			}
		}

		/*SDL_Delay(100);

		pantalla = SDL_SetVideoMode(1000, 1000, 32, SDL_HWSURFACE);
		SDL_Flip(pantalla);

		SDL_Delay(100);

		if(SDL_BlitSurface(imagen,NULL,pantalla,&destino)<0)
			{
				fprintf(stderr,"error al hacer bliting %s\n",SDL_GetError());
				exit(1);
			}

			SDL_Flip(pantalla);*/
	}

	return 0;
}