#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
{
    int orientacion; //horzontal o vertical
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

            case 1: 
                
                if(unidad[aux].orientacion==0) //horizontal
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

                break;


            case 2: 

                if(unidad[aux].orientacion==0) //horizontal
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

                break;



            case 3:

                if(unidad[aux].orientacion==0) //horizontal
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

                break;


            case 4: 
                
                if(unidad[aux].orientacion==0) //horizontal
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

                break;

            

            case 5: 

                if(unidad[aux].orientacion==0) //horizontal
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

                break;
            
        }
    }
}

void limite(int barco,int* posicion,int borde)
{
    switch(barco)
    {
        case 1: if(*posicion>borde-2*borde/10){ //barrera para que no desaparezca la img
                *posicion=borde-2*borde/10;
                }
                break;

        case 2: if(*posicion>borde-3*borde/10){ 
                *posicion=borde-3*borde/10;
                }
                break;

        case 3: if(*posicion>borde-3*borde/10){
                *posicion=borde-3*borde/10;
                }
                break;

        case 4: if(*posicion>borde-4*borde/10){
                *posicion=borde-4*borde/10;
                }
                break;

        case 5: if(*posicion>borde-5*borde/10){
                *posicion=borde-5*borde/10;
                }
                break;
    }
}



void caja(SDL_Rect * pos,int indice, int rotacion){

    switch(indice){

        case 1:  //barco de 2

            if(rotacion==1){ //horizontal
                pos->w=160;
                pos->h=60;
            }

            
            else{

                pos->w=80;
                pos->h=120;

            }

            printf("caja barco 2 creada\n");
            break;

        case 2:  //barco de 3

            if(rotacion==1){
                pos->w=240;
                pos->h=60;
            }

            
            else{

                pos->w=80;
                pos->h=180;

            }

            printf("caja barco 3 creada\n");
            break;


        case 3:  //barco de 3

            if(rotacion==1){
                pos->w=240;
                pos->h=60;
            }

            
            else{

                pos->w=80;
                pos->h=180;

            }

            printf("caja barco 3 creada\n");
            break;

        case 4:  //barco de 4

            if(rotacion==1){
                pos->w=320;
                pos->h=60;
            }

            
            else{

                pos->w=80;
                pos->h=240;

            }


            printf("caja barco 4 creada\n");
            break;


        case 5:  //barco de 5

            if(rotacion==1){
                pos->w=400;
                pos->h=60;
            }

            
            else{

                pos->w=80;
                pos->h=300;

            }

            printf("caja barco 5 creada\n");
            break;
    }
}



int colision(SDL_Rect * actual,int indice,SDL_Rect * arreglo){


    int i;
    int a=0;

    for(i=0;i<5;i++){
        
        if(i==indice-1){
            printf("i igual a indice, continuando\n");
            continue;
        }


        if(((arreglo+i)->w)!=0){ //confirmar que no sea una caja nula

            printf("i=%d\n",i);
            printf("barco.actual.w=%d\n",actual->w);
            printf("barco.actual.h=%d\n",actual->h);
            printf("barco.arreglo+i.w=%d\n",(arreglo+i)->w);
            printf("barco.arreglo+i.h=%d\n",(arreglo+i)->h);

            a=SDL_HasIntersection(actual,(arreglo+i));

            
            if(a==1){
                printf("no se puede colocar ahi\n");
                break;
            }
        }
    }


    return a;

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
    SDL_Rect estatic[5];
    estatic[0].w=0;
    estatic[0].h=0;
    estatic[1].w=0;
    estatic[1].h=0;
    estatic[2].w=0;
    estatic[2].h=0;
    estatic[3].w=0;
    estatic[3].h=0;
    estatic[4].w=0;
    estatic[4].h=0;
    SDL_Rect posBarco; 
    posBarco.x=0;
    posBarco.y=0;

    SDL_Rect *puntero=&estatic[0];
    SDL_Event evento;
   

    int i,cnt=0,indice=1; //indice: 1.lancha(2), 2.submarino(3), 3.crucero(3), 4.acorazado(5), 5.portaaviones(5)
    int ARRi[5]={0};
    int aux=1,aux2=1,rot=1,borde=1;
    int interseccion;

    barco flota[5]; //los cinco barcos

    flota[0].orientacion=1; // 1:horizontal, 2:vertical
    flota[1].orientacion=1;
    flota[2].orientacion=1;
    flota[3].orientacion=1;
    flota[4].orientacion=1;

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

    
    grn1V= IMG_Load("./Data/verdes/destructor_v.png");
    grn2V= IMG_Load("./Data/verdes/submarino_v.png");
    grn3V= IMG_Load("./Data/verdes/crucero_v.png");
    grn4V= IMG_Load("./Data/verdes/acorazado_v.png"); 
    grn5V= IMG_Load("./Data/verdes/portaaviones_v.png");
    


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

                    case SDL_SCANCODE_A:



                        estatic[cnt]=posBarco;
                        caja(&estatic[cnt],indice,rot);
                        interseccion=colision(&estatic[cnt],indice,puntero);

                        if(interseccion==1){
                            printf("se intersectan las cajas\n");
                            break;
                        }

                        ARRi[cnt]=indice;
                        flota[indice-1].existencia=0;
                        flota[indice-1].orientacion=rot;
                        

                        

                        indice++;
                        cnt++;
                        printf("cnt=%d\n",cnt);
                        break;
                        

                    case SDL_SCANCODE_S:

                        cnt--;
                        indice--;

                        if(cnt<0){
                            cnt=0;
                        }

                        if(indice<1){
                            indice=1;
                        }

                        ARRi[cnt]=0;
                        flota[indice-1].existencia=1;
                        flota[indice-1].orientacion=1;
                        estatic[cnt].w=0;
                        estatic[cnt].h=0;

                        printf("quitando caja.. ancho=%d alto=%d\n",estatic[cnt].w,estatic[cnt].h);


                       

                        printf("cnt=%d\n",cnt);
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
                    case 1: 
                            
                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(red1H,NULL,detras,&estatic[i]);
                            }
                            else{
                                SDL_BlitSurface(red1V,NULL,detras,&estatic[i]);
                            }
                            break;
                    case 2: 
                            
                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(red2H,NULL,detras,&estatic[i]);
                            }
                            else{
                                SDL_BlitSurface(red2V,NULL,detras,&estatic[i]);
                            }
                            break;
                    case 3: 

                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(red3H,NULL,detras,&estatic[i]);
                            }
                            else{
                                SDL_BlitSurface(red3V,NULL,detras,&estatic[i]);
                            }
                            break;

                    case 4: 
                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(red4H,NULL,detras,&estatic[i]);
                            }
                            else{
                                SDL_BlitSurface(red4V,NULL,detras,&estatic[i]);
                            }
                            break;
                    
                    case 5: 

                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(red5H,NULL,detras,&estatic[i]);
                            }
                            else{
                                SDL_BlitSurface(red5V,NULL,detras,&estatic[i]);
                            }
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