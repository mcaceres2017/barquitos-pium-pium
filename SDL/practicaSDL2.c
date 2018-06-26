#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


//a la hora de compilar se pone gcc nombre.c -lSDL2 -lSDL2_image //


int main () {


    SDL_Window *pantalla=NULL; // esta sera la ventana.... el cuadrado con nombre
    SDL_Surface *img1=NULL;   // superficie que contendra la imagen que queremos
    SDL_Surface *img2=NULL;
    SDL_Surface *img3=NULL;
    SDL_Surface *img4=NULL;
    SDL_Surface *img5=NULL;
    SDL_Surface *fusion=NULL;
    SDL_Surface *arreglo=NULL;
    SDL_Texture *imgTexture=NULL;  // a partir de la imagen crearemos una textura
    SDL_Renderer *render=NULL;    // y esto es para renderizar la pantalla y cargarle las imagenes
    SDL_Rect posImg; //esto es para ir moviendo la imagen... WIP
    posImg.x=400;
    posImg.y=400;
    posImg.h=100;
    posImg.w=100;

    SDL_Rect estatic[10];

    int i,cnt=0,indice=1;
    int ARRi[10]={0};



    SDL_Event evento; 

    int aux=1,aux2=1; //auxiliar para el ciclo que detecta si presionamos la equis para cerrar ventana


    if(SDL_Init(SDL_INIT_VIDEO) < 0) { // activacion y comprobacion de que el video inicio correctamente
                                       // el subsistema de video tambien activa el subsistema de eventos

        fprintf(stderr,"No se pudo iniciar SDL video: %s\n", SDL_GetError());
        exit(1);
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



    img1= IMG_Load("./patito.png"); //cargamos la imagen.. el comando es de SDL.Image
    img2= IMG_Load("./SuperSanic.png");
    img3= IMG_Load("./Wario.png");
    img4= IMG_Load("./Waligui.png");
    img5= IMG_Load("./uganda.png");

    render= SDL_CreateRenderer(pantalla, -1, 0);   // renderizamos la pantalla...
    //este comando recibe (SDL_Window * pantalla, el numero del driver que hara el render...el menos uno es para que
    // agarre el primer dispositivo disponible, y el cero nuevamente son banderas... el cero es para ninguna


    while(aux==1){  //ciclo para que no se cierre altiro

        while(SDL_PollEvent(&evento)){ // con el SDL poll con el que consultamos una lista de eventos que se van almacenando
                    
            fusion=SDL_CreateRGBSurface(0,800,600,32,0,0,0,0);

            if(evento.type==SDL_QUIT) // si presionamos la equis para cerrar la ventana
            {
                aux=0; //para terminar el ciclo
                break;
            }


            if(evento.type==SDL_KEYDOWN){ //si se presiono una tecla
                switch(evento.key.keysym.scancode) { //esto para acceder a una tabla de codigos qlos que tiene SDL para 
                                                    // reconocer cada tecla 

                    case SDL_SCANCODE_UP: //los scancodes son como codigos internaciones... independiente del teclado  
                        posImg.y-=50;     //reconocera la tecla....
                        if(posImg.y<0){  //barrera para que no desaparezca la img
                            posImg.y=0;
                        }
                        printf("posimg.y=%d\n",posImg.y); //indicador
                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_DOWN: 
                        posImg.y+=50;
                        if(posImg.y>500){ //barrera para que no desaparezca la img
                            posImg.y=500;
                        }
                        printf("posimg.y=%d\n",posImg.y); //indicador
                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_RIGHT: 
                        posImg.x+=50;
                        if(posImg.x>700){ //barrera para que no desaparezca la img
                            posImg.x=700;
                        }
                        printf("posimg.x=%d\n",posImg.x); //indicador
                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_LEFT: 
                        posImg.x-=50;
                        if(posImg.x<0){ //barrera para que no desaparezca la img
                            posImg.x=0;
                        }
                        printf("posimg.x=%d\n",posImg.x); //indicador
                        SDL_RenderClear(render);
                        break; 
                    
                    case SDL_SCANCODE_A:
                        ARRi[cnt]=indice;

                        cnt++;
                        if(cnt>10){
                            cnt=10;
                        }

                        if(cnt<10){
                            estatic[cnt-1]=posImg;
                        }

                        if(cnt==10 && aux2==1){
                            estatic[cnt-1]=posImg;
                            aux2=0;
                        }
                        printf("cnt=%d\n",cnt);
                        break;

                    case SDL_SCANCODE_S:
                        cnt--;
                        ARRi[cnt]=0;
                        aux2=1;
                        if(cnt<0){
                            cnt=0;
                        }
                        printf("cnt=%d\n",cnt);
                        break;

                    case SDL_SCANCODE_Q:
                        indice--;

                        if(indice<1)
                        {
                            indice=5;
                        }
                        break;

                    case SDL_SCANCODE_W:
                        indice++;

                        if(indice>5)
                        {
                            indice=1;
                        }
                        break;               
                }
            }

            switch(indice)
            {
                case 1: arreglo=img1;
                        break;
                case 2: arreglo=img2;
                        break;
                case 3: arreglo=img3;
                        break;
                case 4: arreglo=img4;
                        break;
                case 5: arreglo=img5;
                        break;
            }


            SDL_BlitScaled(arreglo,NULL,fusion,&posImg);


            for(i=0;i<cnt;i++){

                switch(ARRi[i])
                {
                    case 1: SDL_BlitScaled(img1,NULL,fusion,&estatic[i]);
                            break;
                    case 2: SDL_BlitScaled(img2,NULL,fusion,&estatic[i]);
                            break;
                    case 3: SDL_BlitScaled(img3,NULL,fusion,&estatic[i]);
                            break;
                    case 4: SDL_BlitScaled(img4,NULL,fusion,&estatic[i]);
                            break;
                    case 5: SDL_BlitScaled(img5,NULL,fusion,&estatic[i]);
                            break;
                } 
            }

            imgTexture= SDL_CreateTextureFromSurface(render,fusion); 
            SDL_FreeSurface(fusion);
            SDL_RenderCopy(render, imgTexture, NULL, NULL);
            SDL_RenderPresent(render);

        }

    }

    //al salir destruimos todo y cerramos los subsistemas con SDL_Quit
    SDL_FreeSurface(fusion);
    SDL_FreeSurface(img1);
    SDL_FreeSurface(img2);
    SDL_FreeSurface(img3);
    SDL_FreeSurface(img4);
    SDL_FreeSurface(img5);
    SDL_FreeSurface(arreglo);
    SDL_DestroyTexture(imgTexture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(pantalla);
    SDL_Quit();
    return 0;


}