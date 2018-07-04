#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
{
    int orientacion; //horzontal o vertical
    int existencia; // 0.no esta disponible 1. esta disponible Ej: no puedes poner 2 destructores
} barco;


void CrearMatriz(char * matriz, SDL_Rect * cajas,barco * puntero) //pondremos (estatic,ARRI,flota)
{
    int i,j,k;
    SDL_Rect scan1; //escaner filas
    scan1.x=0;
    scan1.y=0;
    scan1.w=80;
    scan1.h=60;
    SDL_Rect scan2;  //escaner columnas
    scan2.x=0;
    scan2.y=0;
    scan2.w=80;
    scan2.h=60;

    int aux[5]={0}; //auxiliar para encontrar barcos



    //revisando la matriz horizontalmente
    //scan es del tamaño de UN cuadrado....que nos sirve para encontrar la posicion de los barcos

    for(i=0;i<10;i++) //ciclo filas
    {
        scan1.x=0;
        scan1.y=i*60;

        scan2.y=0;
        scan2.x=i*80;

        for(j=0;j<10;j++)  //ciclo columnas
        {
            scan1.x=j*80;
            scan2.y=j*60;

            for(k=0;k<5;k++)  //ciclo interseccion
            {
                if(SDL_HasIntersection(&scan1,(cajas+k))==1) //WIP
                {
                    switch(k){

                        case 0:  //barco de 2

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
                                printf("save barco 1 h\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(i*10)+j]='E';
                                matriz[(i*10)+j+1]='E';
                                aux[k]=1;
                            }

                            break;


                        case 1: //barco de 3

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
                                printf("save barco 2 h\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(i*10)+j]='D';
                                matriz[(i*10)+j+1]='D';
                                matriz[(i*10)+j+2]='D';
                                aux[k]=1;
                            }

                            break;

                        case 2: //barco de 3

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
                                printf("save barco 3 h\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(i*10)+j]='C';
                                matriz[(i*10)+j+1]='C';
                                matriz[(i*10)+j+2]='C';
                                aux[k]=1;
                            }

                            break;

                        case 3: //barco de 4

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
                                printf("save barco 4 h\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(i*10)+j]='B';
                                matriz[(i*10)+j+1]='B';
                                matriz[(i*10)+j+2]='B';
                                matriz[(i*10)+j+3]='B';
                                aux[k]=1;
                            }

                            break;

                        case 4: //barco de 5

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
                                printf("save barco 5 h\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(i*10)+j]='A';
                                matriz[(i*10)+j+1]='A';
                                matriz[(i*10)+j+2]='A';
                                matriz[(i*10)+j+3]='A';
                                matriz[(i*10)+j+4]='A';
                                aux[k]=1;
                            }

                            break;
                    } //fin del switch
                } //fin del if


                if(SDL_HasIntersection(&scan2,(cajas+k))==1){

                    switch(k){

                        case 0:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
                                printf("save barco 1 v\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(j*10)+i]='E';
                                matriz[(j*10)+10+i]='E';
                                aux[k]=1;
                            }

                            break;

                        case 1:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
                                printf("save barco 2 v\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(j*10)+i]='D';
                                matriz[(j*10)+10+i]='D';
                                matriz[(j*10)+20+i]='D';
                                aux[k]=1;
                            }

                            break;

                        case 2:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
                                printf("save barco 3 v\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(j*10)+i]='C';
                                matriz[(j*10)+10+i]='C';
                                matriz[(j*10)+20+i]='C';
                                aux[k]=1;
                            }

                            break;

                        case 3:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
                                printf("save barco 4 v\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(j*10)+i]='B';
                                matriz[(j*10)+10+i]='B';
                                matriz[(j*10)+20+i]='B';
                                matriz[(j*10)+30+i]='B';
                                aux[k]=1;
                            }

                            break;

                        case 4:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
                                printf("save barco 5 v\n");
                                printf("i=%d j=%d\n",i,j);
                                matriz[(j*10)+i]='A';
                                matriz[(j*10)+10+i]='A';
                                matriz[(j*10)+20+i]='A';
                                matriz[(j*10)+30+i]='A';
                                matriz[(j*10)+40+i]='A';
                                aux[k]=1;
                            }

                            break;
                    } //fin del switch vertical
                } //fin del if vertical
            } //fin de k
        } //fin de j
    } //fin de i
} //fin funcion

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
            printf("barco.arreglo+%d.w=%d\n",i,(arreglo+i)->w);
            printf("barco.arreglo+%d.h=%d\n",i,(arreglo+i)->h);

            a=SDL_HasIntersection(actual,(arreglo+i));

            
            if(a==1){
                printf("no se puede colocar ahi\n");
                printf("choca con barco %d\n",i+1);
                break;
            }
        }
    }


    return a;

}

void PonerBarcos(char *matriz, SDL_Window *pantalla,SDL_Surface *barco1H,SDL_Surface *barco2H,SDL_Surface *barco3H,SDL_Surface *barco4H,SDL_Surface *barco5H,SDL_Surface *barco1V,SDL_Surface *barco2V,SDL_Surface *barco3V,SDL_Surface *barco4V,SDL_Surface *barco5V)
{
     SDL_Surface *detras=NULL;
    SDL_Surface *fondo=NULL;
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
   

    int i,j,cnt=0,indice=1; //indice: 1.lancha(2), 2.submarino(3), 3.crucero(3), 4.acorazado(5), 5.portaaviones(5)
    int ARRi[5]={0};
    int aux=1,rot=1,borde=1;
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

                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_LEFT: 

                        posBarco.x-=80;


                        if(posBarco.x<0){ //barrera para que no desaparezca la img
                            posBarco.x=0;
                        }

                        SDL_RenderClear(render);
                        break; 

                    case SDL_SCANCODE_A:

                        estatic[cnt].x=posBarco.x;
                        estatic[cnt].y=posBarco.y;
                        printf("creando caja\n");
                        caja(&estatic[cnt],indice,rot);
                        printf("caja %d creada w=%d h=%d\n",indice,estatic[0].w,estatic[0].h);
                        interseccion=colision(&estatic[cnt],indice,puntero);

                        if(interseccion==1){
                            printf("se intersectan las cajas\n");
                            interseccion=0;
                            break;
                        }

                        ARRi[cnt]=indice;
                        flota[indice-1].existencia=0;
                        flota[indice-1].orientacion=rot;
                        printf("confirmacion antes de salir de A\n");
                        printf("caja %d w=%d h=%d\n",indice,estatic[0].w,estatic[0].h);
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
                        estatic[cnt].x=0;
                        estatic[cnt].y=0;
                        estatic[cnt].w=0;
                        estatic[cnt].h=0;

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

            for(i=0;i<cnt;i++){


                switch(ARRi[i])
                {
                    case 1: 
                            
                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(barco1H,NULL,detras,&estatic[i]);
                                estatic[i].w=160;
                                estatic[i].h=60;
                                /*BlitSurface ajusta la caja 2 a las dimensiones originales de la imagen
                                y BlitScaled ajusta la imagen a las dimensiones de la caja 2.... eso si
                                teniendo cuidado de que a la imagen le sobre la menor cantida de 
                                espacio transparente posible..... como ocupamos el blitsurface y al 
                                terminar este blit las medidas W y H de la caja 2 cambiaban... tuvimos
                                que poner esos "reajustes" como parche curita por mientras...el resto
                                de las cosas funciona bien..... ahora como ya tenemos el escaneado de la
                                matriz faltaria crear el segundo while con otra piscina de eventos para
                                lo que serian los disparos hasta que alguien gane*/
                            }
                            else{
                                SDL_BlitSurface(barco1V,NULL,detras,&estatic[i]);
                                estatic[i].w=80;
                                estatic[i].h=120;
                            }

                            break;
                    case 2: 
                            
                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(barco2H,NULL,detras,&estatic[i]);
                                estatic[i].w=240;
                                estatic[i].h=60;
                            }
                            else{
                                SDL_BlitSurface(barco2V,NULL,detras,&estatic[i]);
                                estatic[i].w=80;
                                estatic[i].h=180;
                            }
                            break;
                    case 3: 

                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(barco3H,NULL,detras,&estatic[i]);
                                estatic[i].w=240;
                                estatic[i].h=60;
                            }
                            else{
                                SDL_BlitSurface(barco3V,NULL,detras,&estatic[i]);
                                estatic[i].w=80;
                                estatic[i].h=180;
                            }
                            break;

                    case 4: 
                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(barco4H,NULL,detras,&estatic[i]);
                                estatic[i].w=320;
                                estatic[i].h=60;
                            }
                            else{
                                SDL_BlitSurface(barco4V,NULL,detras,&estatic[i]);
                                estatic[i].w=80;
                                estatic[i].h=240;
                            }
                            break;
                    
                    case 5: 

                            if(flota[i].orientacion==1){
                                SDL_BlitSurface(barco5H,NULL,detras,&estatic[i]);
                                estatic[i].w=400;
                                estatic[i].h=60;
                            }
                            else{
                                SDL_BlitSurface(barco5V,NULL,detras,&estatic[i]);
                                estatic[i].w=80;
                                estatic[i].h=300;
                            }
                            break;
                } 
            }


            switch(indice)
            {
                case 1: if(rot==1){
                            SDL_BlitSurface(barco1H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(barco1V,NULL,detras,&posBarco);
                        }

                        break;

                case 2: if(rot==1){
                            SDL_BlitSurface(barco2H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(barco2V,NULL,detras,&posBarco);
                        }
                        break;

                case 3: if(rot==1){
                            SDL_BlitSurface(barco3H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(barco3V,NULL,detras,&posBarco);
                        }
                        break;

                case 4: if(rot==1){
                            SDL_BlitSurface(barco4H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(barco4V,NULL,detras,&posBarco);
                        }
                        break;
                        
                case 5: if(rot==1){
                            SDL_BlitSurface(barco5H,NULL,detras,&posBarco);
                        }
                        if(rot==2){
                            SDL_BlitSurface(barco5V,NULL,detras,&posBarco);
                        }
                        break;
            }



            imgTexture= SDL_CreateTextureFromSurface(render,detras); 
            SDL_FreeSurface(detras);
            SDL_RenderCopy(render, imgTexture, NULL, NULL);
            SDL_DestroyTexture(imgTexture);
            SDL_RenderPresent(render);

            if(cnt==5){

                aux=0;
                break;
            }  //posiblemente con esta liberacion tire una violacion

        }
    }



    CrearMatriz(matriz,puntero,&flota[0]);

    //al salir destruimos todo y cerramos los subsistemas con SDL_Quit
    SDL_FreeSurface(detras);

    SDL_FreeSurface(barco1H);
    SDL_FreeSurface(barco2H);
    SDL_FreeSurface(barco3H);
    SDL_FreeSurface(barco4H);
    SDL_FreeSurface(barco5H);

    SDL_FreeSurface(barco1V);
    SDL_FreeSurface(barco2V);
    SDL_FreeSurface(barco3V);
    SDL_FreeSurface(barco4V);
    SDL_FreeSurface(barco5V);

    SDL_FreeSurface(arreglo);

    SDL_DestroyTexture(imgTexture);

    SDL_DestroyRenderer(render);

}

//a la hora de compilar se pone gcc nombre.c -lSDL2 -lSDL2_image //


int main () {


    SDL_Window *pantalla=NULL;


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

    char mat1[10][10];
    char *ptMat1=&mat1[0][0];
    int i,j;


    for(i=0;i<10;i++) // rellenamos la matriz de puntos
    {
        for(j=0;j<10;j++)
        {
            mat1[i][j]='.';
        }
    }

    char mat2[10][10];
    char *ptMat2=&mat2[0][0];


    for(i=0;i<10;i++) // rellenamos la matriz de puntos
    {
        for(j=0;j<10;j++)
        {
            mat2[i][j]='.';
        }
    }

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

    PonerBarcos(ptMat1,pantalla,red1H,red2H,red3H,red4H,red5H,red1V,red2V,red3V,red4V,red5V);

    for(i=0;i<10;i++) // rellenamos la matriz de puntos
    {
        for(j=0;j<10;j++)
        {
            printf("%c",mat1[i][j]);
        }

        printf("\n");
    }

    PonerBarcos(ptMat2,pantalla,grn1H,grn2H,grn3H,grn4H,grn5H,grn1V,grn2V,grn3V,grn4V,grn5V);

    for(i=0;i<10;i++) // rellenamos la matriz de puntos
    {
        for(j=0;j<10;j++)
        {
            printf("%c",mat2[i][j]);
        }

        printf("\n");
    }

    SDL_DestroyWindow(pantalla);

    SDL_Quit();
    return 0;
}