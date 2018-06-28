#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
{
    int orientacion; //horzontal o vertical
    int id; //1.submarino 2.destructor etc
    int existencia; // 0.no esta disponible 1. esta disponible Ej: no puedes poner 2 destructores
} barco;


void EscanearMatriz(SDL_Rect *matriz,int *indices, barco *unidad) //pondremos (estatic,ARRI,flota)
{
    int i,j,aux,filas,columnas;
    char tableroDeJuego[10][10];

    for(i=0;i<10;i++) // rellenamos la matriz de puntos
    {
        for(j=0;j<10;j++)
        {
            tableroDeJuego[i][j]='.';
        }
    }

    for(i=0;i<10;i++)
    {
        aux=indices[i];
        filas=matriz[i].x;
        columnas=matriz[i].y;

        switch(aux)
        {
            case 1: if(unidad[aux].orientacion==0) //horizontal
            {
                for(j=0;j<5;j++)
                {
                    tableroDeJuego[filas/80+j*80][columnas/60]='A';
                }
            }

            else //vertical
            {
                for(j=0;j<5;j++)
                {
                    tableroDeJuego[filas/80][columnas/60 +j*60]='A';
                }
            }

            case 2: if(unidad[aux].orientacion==0) //horizontal
            {
                for(j=0;j<4;j++)
                {
                    tableroDeJuego[filas/80+j*80][columnas/60]='B';
                }
            }

            else //vertical
            {
                for(j=0;j<4;j++)
                {
                    tableroDeJuego[filas/80][columnas/60 +j*60]='B';
                }
            }

            case 3: if(unidad[aux].orientacion==0) //horizontal
            {
                for(j=0;j<3;j++)
                {
                    tableroDeJuego[filas/80+j*80][columnas/60]='C';
                }
            }

            else //vertical
            {
                for(j=0;j<3;j++)
                {
                    tableroDeJuego[filas/80][columnas/60 +j*60]='C';
                }
            }

            case 4: if(unidad[aux].orientacion==0) //horizontal
            {
                for(j=0;j<3;j++)
                {
                    tableroDeJuego[filas/80+j*80][columnas/60]='D';
                }
            }

            else //vertical
            {
                for(j=0;j<3;j++)
                {
                    tableroDeJuego[filas/80][columnas/60 +j*60]='D';
                }
            }

            case 5: if(unidad[aux].orientacion==0) //horizontal
            {
                for(j=0;j<2;j++)
                {
                    tableroDeJuego[filas/80+j*80][columnas/60]='E';
                }
            }

            else //vertical
            {
                for(j=0;j<2;j++)
                {
                    tableroDeJuego[filas/80][columnas/60 +j*60]='E';
                }
            }
        }
    }
}

void limite(int barco,int* posicion,int borde)
{
    switch(barco)
    {
        case 1: if(*posicion>borde-4*borde/10){ //barrera para que no desaparezca la img
                *posicion=borde-4*borde/10;
                }
                break;

        case 2: if(*posicion>borde-2*borde/10){ 
                *posicion=borde-2*borde/10;
                }
                break;

        case 3: if(*posicion>borde-3*borde/10){
                *posicion=borde-3*borde/10;
                }
                break;

        case 4: if(*posicion>borde-5*borde/10){
                *posicion=borde-5*borde/10;
                }
                break;

        case 5: if(*posicion>borde-3*borde/10){
                *posicion=borde-3*borde/10;
                }
                break;
    }
}


//a la hora de compilar se pone gcc nombre.c -lSDL2 -lSDL2_image //


int main () {


    SDL_Window *pantalla=NULL;
    SDL_Surface *fondo=NULL;


    SDL_Surface *red1H=NULL;  //barco de 2 destructor
    SDL_Surface *red2H=NULL;  //barco de 3 submarino
    SDL_Surface *red3H=NULL;  //barco de 3 crucero
    SDL_Surface *red4H=NULL;  //barco de 4 acorazado
    SDL_Surface *red5H=NULL;  //barco de 5 portaaviones

    SDL_Surface *red1V=NULL;  
    SDL_Surface *red2V=NULL;
    SDL_Surface *red3V=NULL;
    SDL_Surface *red4V=NULL;
    SDL_Surface *red5V=NULL;


    SDL_Surface *grn1H=NULL;
    SDL_Surface *grn2H=NULL;
    SDL_Surface *grn3H=NULL;
    SDL_Surface *grn4H=NULL;
    SDL_Surface *grn5H=NULL;


    SDL_Surface *grn1V=NULL;
    SDL_Surface *grn2V=NULL;
    SDL_Surface *grn3V=NULL;
    SDL_Surface *grn4V=NULL;
    SDL_Surface *grn5V=NULL;


    SDL_Surface *detras=NULL;
    SDL_Surface *arreglo=NULL;
    SDL_Texture *imgTexture=NULL; 
    SDL_Renderer *render=NULL;  
    SDL_Rect estatic[10];
    SDL_Rect posBarco; 
    posBarco.x=0;
    posBarco.y=0;
    SDL_Event evento;
   

    int i,cnt=0,indice=1,k; //indice: 1.acorazado(4), 2.lancha(2), 3.submarino(3), 4.porta aviones(5), 5.acorazado(3)
    int ARRi[10]={0};
    int aux=1,aux2=1,rot=1,borde=1;

    barco flota[5]; //los cinco barcos

    flota[0].orientacion=0; // 0:horizontal, 1:vertical
    flota[1].orientacion=0;
    flota[2].orientacion=0;
    flota[3].orientacion=0;
    flota[4].orientacion=0;

    flota[0].existencia=1;
    flota[1].existencia=1;
    flota[2].existencia=1;
    flota[3].existencia=1;
    flota[4].existencia=1;


    fondo= IMG_Load("./Data/fondo.png");


    red1H= IMG_Load("./Data/rojos/destructor_h.png");
    red2H= IMG_Load("./Data/rojos/submarino_h.png");
    red3H= IMG_Load("./Data/rojos/crucero_h.png");
    red4H= IMG_Load("./Data/rojos/acorazado_h.png"); 
    red5H= IMG_Load("./Data/rojos/portaaviones_h.png");

  
    red1V= IMG_Load("./Data/rojos/destructor_v.png");
    red2V= IMG_Load("./Data/rojos/submarino_v.png");
    red3V= IMG_Load("./Data/rojos/crucero_v.png");
    red4V= IMG_Load("./Data/rojos/acorazado_v.png"); 
    red5V= IMG_Load("./Data/rojos/portaaviones_v.png");
    
    
    grn1H= IMG_Load("./Data/verdes/destructor_h.png");
    grn2H= IMG_Load("./Data/verdes/submarino_h.png");
    grn3H= IMG_Load("./Data/verdes/crucero_h.png");
    grn4H= IMG_Load("./Data/verdes/acorazado_h.png"); 
    grn5H= IMG_Load("./Data/verdes/portaaviones_h.png");

    
    grn1H= IMG_Load("./Data/verdes/destructor_v.png");
    grn2H= IMG_Load("./Data/verdes/submarino_v.png");
    grn3H= IMG_Load("./Data/verdes/crucero_v.png");
    grn4H= IMG_Load("./Data/verdes/acorazado_v.png"); 
    grn5H= IMG_Load("./Data/verdes/portaaviones_v.png");
    


    if(SDL_Init(SDL_INIT_VIDEO) < 0) { // activacion y comprobacion de video
                                       // el subsistema de video tambien activa el subsistema de eventos

        fprintf(stderr,"No se pudo iniciar SDL video: %s\n", SDL_GetError());
        exit(1);
    }


    pantalla = SDL_CreateWindow ("barquitos 2000 remastered",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  600,
                                  SDL_WINDOW_RESIZABLE);



    if(pantalla == NULL) {   //comprobamos que la ventana se crea correctamente  
        fprintf(stderr, "No se pudo crear la ventana: %s", SDL_GetError());
    }



    render= SDL_CreateRenderer(pantalla, -1, 0);  

    while(aux==1){  //ciclo para que no se cierre altiro

        while(SDL_PollEvent(&evento)){ // con el SDL poll con el que consultamos una lista de eventos que se van almacenando
                    
            detras=SDL_CreateRGBSurface(0,800,600,32,0,0,0,0);
            SDL_BlitSurface(fondo,NULL,detras,NULL);


            if(evento.type==SDL_QUIT) 
            {
                aux=0; 
                break;
            }


            if(evento.type==SDL_KEYDOWN){ //si se presiono una tecla
                switch(evento.key.keysym.scancode) { //esto para acceder a una tabla de codigos qlos que tiene SDL para 
                                                    // reconocer cada tecla 

                    case SDL_SCANCODE_UP:  
                        
                        posBarco.y-=60;   


                        if(posBarco.y<0){  //barrera para que no desaparezca la img
                            posBarco.y=0;
                        }

                        printf("posBarco.y=%d\n",posBarco.y);
                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_DOWN: 

                        posBarco.y+=60;

                        if(rot==1)//si esta horizontal
                        {
                            if(posBarco.y>540){ //barrera para que no desaparezca la img
                                posBarco.y=540;
                            }
                        }

                        else //si esta vertical
                        {
                            limite(indice,&posBarco.y,600);
                        }

                        printf("posBarco.y=%d\n",posBarco.y);
                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_RIGHT: 

                        posBarco.x+=80;

                        if(rot==2)//si esta vertical
                        {
                            if(posBarco.x>720){ //barrera para que no desaparezca la img
                                posBarco.x=720;
                            }
                        }

                        else // si esta horizontal
                        {
                            limite(indice,&posBarco.x,800);
                        }

                        printf("posBarco.x=%d\n",posBarco.x);
                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_LEFT: 

                        posBarco.x-=80;


                        if(posBarco.x<0){ //barrera para que no desaparezca la img
                            posBarco.x=0;
                        }

                        printf("posBarco.x=%d\n",posBarco.x);
                        SDL_RenderClear(render);
                        break; 

                        /*if(flota[indice].existencia==0) // si no esta disponible
                        {
                            continue;
                        }

                        else
                        {
                            flota[indice].existencia=0; // luego haremos el proceso inverso
                        }*/

                        ARRi[cnt]=indice;
                        flota[indice-1].existencia=0;

                        indice--;

                        if(indice<1)
                        {
                            indice=5;
                        }

                        while(flota[indice-1].existencia==0)
                        {
                            indice--;

                            if(indice<1)
                            {
                                indice=5;
                            }
                        }

                        cnt++;

                        if(cnt>5){
                            cnt=5;
                        }

                        if(cnt<5){
                            estatic[cnt-1]=posBarco;
                        }

                        if(cnt==5 && aux2==1){
                            estatic[cnt-1]=posBarco;
                            aux2=0;
                        }

                        printf("cnt=%d\n",cnt);
                        break;



                    case SDL_SCANCODE_A:

                        ARRi[cnt]=indice;

                        cnt++;

                        if(cnt>10){
                            cnt=10;
                        }

                        if(cnt<10){
                            estatic[cnt-1]=posBarco;
                        }

                        if(cnt==10 && aux2==1){
                            estatic[cnt-1]=posBarco;
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

                    case SDL_SCANCODE_Q: //hay que ver luego una forma de que no se muestren los que ya estan puestos

                        indice--;

                        if(indice<1)
                        {
                            indice=5;
                        }

                        while(flota[indice-1].existencia==0)
                        {
                            indice--;

                            if(indice<1)
                            {
                                indice=5;
                            }
                        }

                        if(rot==1)
                        {
                            limite(indice,&posBarco.x,800);
                        }

                        else
                        {
                            limite(indice,&posBarco.y,600);
                        }

                        printf("%d\n",indice);

                        break;

                    case SDL_SCANCODE_W:
                        
                        indice++;

                        if(indice>5)
                        {
                            indice=1;
                        }

                        while(flota[indice-1].existencia==0)
                        {
                            indice++;

                            if(indice>5)
                            {
                                indice=1;
                            }
                        }

                        if(rot==1)
                        {
                            limite(indice,&posBarco.x,800);
                        }

                        else
                        {
                            limite(indice,&posBarco.y,600);
                        }

                        printf("%d\n",indice);

                        break;   


                    case SDL_SCANCODE_R: //tecla para rotar

                        if(rot==1){
                            rot=2;
                            printf("rot=%d\n",rot);
                        }
                        else{
                            rot=1;
                            printf("rot=%d\n",rot);
                        }

                        if(rot==1)
                        {
                            limite(indice,&posBarco.x,800);
                        }

                        else
                        {
                            limite(indice,&posBarco.y,600);
                        }

                        break;           
                }
            }

            switch(indice)
            {
                case 1: if(rot==1){
                            SDL_BlitSurface(red1H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(red1V,NULL,detras,&posBarco);
                        }

                        break;

                case 2: if(rot==1){
                            SDL_BlitSurface(red2H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(red2V,NULL,detras,&posBarco);
                        }
                        break;

                case 3: if(rot==1){
                            SDL_BlitSurface(red3H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(red3V,NULL,detras,&posBarco);
                        }
                        break;

                case 4: if(rot==1){
                            SDL_BlitSurface(red4H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(red4V,NULL,detras,&posBarco);
                        }
                        break;
                        
                case 5: if(rot==1){
                            SDL_BlitSurface(red5H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(red5V,NULL,detras,&posBarco);
                        }
                        break;
            }



            for(i=0;i<cnt;i++){

                switch(ARRi[i])
                {
                    case 1: SDL_BlitSurface(red1H,NULL,detras,&estatic[i]);
                            break;
                    case 2: SDL_BlitSurface(red2H,NULL,detras,&estatic[i]);
                            break;
                    case 3: SDL_BlitSurface(red3H,NULL,detras,&estatic[i]);
                            break;
                    case 4: SDL_BlitSurface(red4H,NULL,detras,&estatic[i]);
                            break;
                    case 5: SDL_BlitSurface(red5H,NULL,detras,&estatic[i]);
                            break;
                } 
            }



            imgTexture= SDL_CreateTextureFromSurface(render,detras); 
            SDL_FreeSurface(detras);
            SDL_RenderCopy(render, imgTexture, NULL, NULL);
            SDL_DestroyTexture(imgTexture);
            SDL_RenderPresent(render);

        }

    }

    //al salir destruimos todo y cerramos los subsistemas con SDL_Quit
    SDL_FreeSurface(detras);

    SDL_FreeSurface(red1H);
    SDL_FreeSurface(red2H);
    SDL_FreeSurface(red3H);
    SDL_FreeSurface(red4H);
    SDL_FreeSurface(red5H);

    SDL_FreeSurface(red1V);
    SDL_FreeSurface(red2V);
    SDL_FreeSurface(red3V);
    SDL_FreeSurface(red4V);
    SDL_FreeSurface(red5V);


    SDL_FreeSurface(grn1H);
    SDL_FreeSurface(grn2H);
    SDL_FreeSurface(grn3H);
    SDL_FreeSurface(grn4H);
    SDL_FreeSurface(grn5H);

    SDL_FreeSurface(grn1V);
    SDL_FreeSurface(grn2V);
    SDL_FreeSurface(grn3V);
    SDL_FreeSurface(grn4V);
    SDL_FreeSurface(grn5V);

    SDL_FreeSurface(arreglo);

    SDL_DestroyTexture(imgTexture);

    SDL_DestroyRenderer(render);

    SDL_DestroyWindow(pantalla);

    SDL_Quit();
    return 0;
}