#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


//a la hora de compilar se pone gcc nombre.c -lSDL2 -lSDL2_image //


int main () {


    SDL_Window *pantalla=NULL; // esta sera la ventana.... el cuadrado con nombre
    SDL_Surface *img=NULL;     // superficie que contendra la imagen que queremos
    SDL_Texture *imgTexture=NULL;  // a partir de la imagen crearemos una textura
    SDL_Renderer *render=NULL;    // y esto es para renderizar la pantalla y cargarle las imagenes
    SDL_Rect posImg; //esto es para ir moviendo la imagen... WIP
    posImg.x=0;
    posImg.y=300;
    posImg.h=60;
    posImg.w=80;
    SDL_Rect copia;

   	copia.h=60;
   	copia.w=80;

    SDL_Rect estatic[10];

    int i,j,cnt=0;

    int posiciones[10][10]={0};



    SDL_Event evento; //esto es para que detecte el cierre de ventana

    int aux=1; //auxiliar para el ciclo que detecta si presionamos la equis para cerrar ventana


    if(SDL_Init(SDL_INIT_VIDEO) < 0) { // activacion y comprobacion de que el video inicio correctamente
                                       // el subsistema de video tambien activa el subsistema de eventos

        fprintf(stderr,"No se pudo iniciar SDL video: %s\n", SDL_GetError());
        exit(1);
    }




    if(SDL_WasInit(SDL_INIT_VIDEO)) {   //comprobacion de que el video esta activo
        printf("video activo\n");
    } 


    pantalla = SDL_CreateWindow ("probando sdl2",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  600,
                                  SDL_WINDOW_RESIZABLE);


    //creacion de la pantalla con el formato (nombre,posicion x,posicion y, ancho, alto, banderas)
    //las banderas son caleta... puse esa para ver si se puede ajustar la pantalla


    if(pantalla == NULL) {   //comprobamos que la ventana se crea correctamente  
        fprintf(stderr, "No se pudo crear la ventana: %s", SDL_GetError());
    }



    img= IMG_Load("/home/carlos/Escritorio/proyecto/patito.jpg"); //cargamos la imagen.. el comando es de SDL.Image

    render= SDL_CreateRenderer(pantalla, -1, 1);   // renderizamos la pantalla...
    //este comando recibe (SDL_Window * pantalla, el numero del driver que hara el render...el menos uno es para que
    // agarre el primer dispositivo disponible, y el cero nuevamente son banderas... el cero es para ninguna


    imgTexture= SDL_CreateTextureFromSurface(render,img); 
    //a partir de la imagen que tenemos guardada en la surface, creamos una textura

    SDL_FreeSurface(img); //una vez convertimos la imagen a textura destruimos la superficie....no la necesitamos


    SDL_RenderClear(render); // limpiamos la pantalla renderizada...
    SDL_RenderCopy(render, imgTexture, NULL, &posImg); // copiamos la textura hacia la pantalla
    SDL_RenderPresent(render);  //y se lo "mostramos" al usuario

    

    while(aux==1){  //ciclo para que no se cierre altiro

        while(SDL_PollEvent(&evento)){ //hay tres metodos para "capturar" eventos
                                // son el SDL poll con el que consultamos una lista de eventos que se van almacenando
                                // SDL Wait event creo.... con el que esperamos al primer evento que sea activado...
                                //y el otro no me acuerdo.. pero era para estar atento solo a eventos particulares
                                // con los que queramos trabajar
            
            if(evento.type==SDL_QUIT) // si presionamos la equis para cerrar la ventana
            {
                aux=0; //para terminar el ciclo
                break;
            }

            i=1;

            if(evento.type==SDL_KEYDOWN){ //si se presiono una tecla
                switch(evento.key.keysym.sym) { //esto para acceder a una tabla de codigos qlos que tiene SDL para 
                                            // reconocer cada tecla 

                    case SDLK_UP:   
                        posImg.y-=60;
                        printf("ariiba\n");
                        if(posImg.y<0)
                        {
                        	posImg.y=0;
                        }
                        SDL_RenderClear(render);
                        SDL_RenderCopy(render, imgTexture, NULL, &posImg); 
                        break;

                    case SDLK_DOWN: 
                        posImg.y+=60;
                        printf("abajo\n");
                        if(posImg.y>540)
                        {
                        	posImg.y=540;
                        }
                        SDL_RenderClear(render);
                        SDL_RenderCopy(render, imgTexture, NULL, &posImg); 
                        break;

                    case SDLK_RIGHT: 
                    	printf("derecha\n");
                        posImg.x+=80;
                        if(posImg.x>720)
                        {
                        	posImg.x=720;
                        }
                        SDL_RenderClear(render);
                        SDL_RenderCopy(render, imgTexture, NULL, &posImg); 
                        break;

                    case SDLK_LEFT: 
                        posImg.x-=80;
                        printf("izquirda\n");
                        if(posImg.x<0)
                        {
                        	posImg.x=0;
                        }
                        SDL_RenderClear(render);
                        SDL_RenderCopy(render, imgTexture, NULL, &posImg); 
                        break; 
                    
                    case SDLK_a:
                    	if(posiciones[posImg.x/80][posImg.y/60]==0)
                    	{
                    		posiciones[posImg.x/80][posImg.y/60]=1;
                    	}

                        /*cnt++;
                        if(cnt>10){
                            cnt=10;
                        } 
                        printf("cnt=%d\n",cnt);*/
                        break;

                    case SDLK_s:

                    	if(posiciones[posImg.x/60][posImg.y/80]==1)
                    	{
                    		posiciones[posImg.x/60][posImg.y/80]=0;
                    	}

                        /*cnt--;
                        if(cnt<0){
                            cnt=0;
                        }
                        printf("cnt=%d\n",cnt);*/
                        break;
                }

                for(i=0;i<10;i++)
                {
                	for(j=0;j<10;j++)
                	{
                		if(posiciones[i][j]==1)
                		{
                			copia.x=i*60;
                			copia.y=j*80;

                			SDL_RenderCopy(render,imgTexture,NULL,&copia);
                		}
                	}
                }

                SDL_RenderPresent(render);

            }

            /*if(cnt>0){     
                estatic[cnt-1]=posImg;
                printf("estatic[%d].x=%d\n",cnt-1,estatic[cnt-1].x);
            }*/

            /*for(i=0;i<cnt;i++){
                SDL_RenderCopy(render, imgTexture, NULL, &estatic[i]); 
            }

            SDL_RenderPresent(render);*/

        }

    }

    //al salir destruimos todo y cerramos los subsistemas con SDL_Quit
    SDL_DestroyTexture(imgTexture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(pantalla);
    SDL_Quit();
    return 0;


}