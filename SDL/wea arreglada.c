#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
{
    int orientacion; //horzontal o vertical
    int disponible; // 0.no esta disponible 1. esta disponible Ej: no puedes poner 2 destructores
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
                                matriz[(i*10)+j]='E';
                                matriz[(i*10)+j+1]='E';
                                aux[k]=1;
                            }

                            break;


                        case 1: //barco de 3

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
                                matriz[(i*10)+j]='D';
                                matriz[(i*10)+j+1]='D';
                                matriz[(i*10)+j+2]='D';
                                aux[k]=1;
                            }

                            break;

                        case 2: //barco de 3

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
                                matriz[(i*10)+j]='C';
                                matriz[(i*10)+j+1]='C';
                                matriz[(i*10)+j+2]='C';
                                aux[k]=1;
                            }

                            break;

                        case 3: //barco de 4

                            if(aux[k]==0 && (puntero+k)->orientacion==1)
                            {
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
                                matriz[(j*10)+i]='E';
                                matriz[(j*10)+10+i]='E';
                                aux[k]=1;
                            }

                            break;

                        case 1:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
                                matriz[(j*10)+i]='D';
                                matriz[(j*10)+10+i]='D';
                                matriz[(j*10)+20+i]='D';
                                aux[k]=1;
                            }

                            break;

                        case 2:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
                                matriz[(j*10)+i]='C';
                                matriz[(j*10)+10+i]='C';
                                matriz[(j*10)+20+i]='C';
                                aux[k]=1;
                            }

                            break;

                        case 3:

                            if(aux[k]==0 && (puntero+k)->orientacion==2)
                            {
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
        case 1: if(*posicion>borde-2*borde/10){
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

            if(rotacion==1){ 

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



int colision(SDL_Rect* actual, int indice, SDL_Rect* cajas){


    int i;
    int a=0;

    for(i=0;i<5;i++){
        
        if(i==indice-1){
            continue;
        }

        if(((cajas+i)->w)!=0){ //confirmar que no sea una caja nula

            a=SDL_HasIntersection(actual,(cajas+i));
            
            if(a==1){
                break;
            }
        }
    }

    return a;
}



void ponerBarcos(SDL_Surface** H, SDL_Surface** V, SDL_Renderer* render, 
                 SDL_Rect* cajas, barco* flota){


    SDL_Surface* detras;
    SDL_Surface  *fondo=NULL;
    fondo  = IMG_Load("./Data/fondo.png");
    SDL_Event evento;
    SDL_Texture *textura=NULL;
    SDL_Rect posActual;
    posActual.x=0;
    posActual.y=0;

    int aux=1,indice=1,rot=1;
    int interseccion,i,j;


    while(aux==1){  

        while(SDL_PollEvent(&evento)){
            

            detras=SDL_CreateRGBSurface(0,800,600,32,0,0,0,0);
            SDL_BlitSurface(fondo,NULL,detras,NULL);


            if(evento.type==SDL_QUIT) 
            { 
                exit(0);
            }


            if(evento.type==SDL_KEYDOWN){ 
                switch(evento.key.keysym.scancode) { 

                    case SDL_SCANCODE_UP:  
                        
                        posActual.y-=60;   

                        if(posActual.y<0){  //barrera para que no desaparezca la img
                            posActual.y=0;
                        }

                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_DOWN: 

                        posActual.y+=60;

                        if(rot==1)//si esta horizontal
                        {
                            if(posActual.y>540){ //barrera para que no desaparezca la img
                                posActual.y=540;
                            }
                        }

                        else //si esta vertical
                        {
                            limite(indice,&posActual.y,600);
                        }

                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_RIGHT: 

                        posActual.x+=80;

                        if(rot==2)
                        {
                            if(posActual.x>720){ //barrera para que no desaparezca la img
                                posActual.x=720;
                            }
                        }

                        else // si esta horizontal
                        {
                            limite(indice,&posActual.x,800);
                        }

                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_LEFT: 

                        posActual.x-=80;


                        if(posActual.x<0){
                            posActual.x=0;
                        }

                        SDL_RenderClear(render);
                        break; 

                    case SDL_SCANCODE_A:

                        cajas[indice-1]=posActual;
                        caja(&cajas[indice-1],indice,rot);
                        interseccion=colision(&cajas[indice-1],indice,&cajas[0]);

                        if(interseccion==1){
                            interseccion=0;
                            break;
                        }

                        flota[indice-1].disponible=0;
                        flota[indice-1].orientacion=rot;
                        indice++;
                        //para que aparezca el siguiente barco dentro de los limites de la pantalla
                        if(rot==1){
                            limite(indice,&posActual.x,800);
                        }
                        else{
                            limite(indice,&posActual.y,600);
                        }
                        break;
                        

                    case SDL_SCANCODE_S:

                        indice--;

                        if(indice<1){
                            indice=1;
                        }

                        flota[indice-1].disponible=1;
                        flota[indice-1].orientacion=1;
                        cajas[indice-1].x=0;
                        cajas[indice-1].y=0;
                        cajas[indice-1].w=0;
                        cajas[indice-1].h=0;
                        break;


                    case SDL_SCANCODE_R: //tecla para rotar

                        if(rot==1){
                            rot=2;
                        }
                        else{
                            rot=1;
                        }

                        if(rot==1)
                        {
                            limite(indice,&posActual.x,800);
                        }

                        else
                        {
                            limite(indice,&posActual.y,600);
                        }

                        break;         
                } 
            }

            for(i=0;i<indice-1;i++){

                switch(i)
                {
                    case 0: 
                            
                            if(flota[i].orientacion==1){
                                SDL_BlitScaled(H[i],NULL,detras,&cajas[i]);
                            }
                            else{
                                SDL_BlitScaled(V[i],NULL,detras,&cajas[i]);
                            }

                            break;
                    case 1: 
                            
                            if(flota[i].orientacion==1){
                                SDL_BlitScaled(H[i],NULL,detras,&cajas[i]);
                            }
                            else{
                                SDL_BlitScaled(V[i],NULL,detras,&cajas[i]);
                            }
                            break;
                    case 2: 

                            if(flota[i].orientacion==1){
                                SDL_BlitScaled(H[i],NULL,detras,&cajas[i]);
                            }
                            else{
                                SDL_BlitScaled(V[i],NULL,detras,&cajas[i]);
                            }
                            break;

                    case 3: 
                            if(flota[i].orientacion==1){
                                SDL_BlitScaled(H[i],NULL,detras,&cajas[i]);
                            }
                            else{
                                SDL_BlitScaled(V[i],NULL,detras,&cajas[i]);
                            }
                            break;
                    
                    case 4: 

                            if(flota[i].orientacion==1){
                                SDL_BlitScaled(H[i],NULL,detras,&cajas[i]);
                            }
                            else{
                                SDL_BlitScaled(V[i],NULL,detras,&cajas[i]);
                            }
                            break;
                } 
            }


            switch(indice)
            {
                case 1: if(rot==1){
                            SDL_BlitSurface(H[0],NULL,detras,&posActual);
                        }
                        if(rot==2){
                            SDL_BlitSurface(V[0],NULL,detras,&posActual);
                        }

                        break;

                case 2: if(rot==1){
                            SDL_BlitSurface(H[1],NULL,detras,&posActual);
                        }
                        if(rot==2){
                            SDL_BlitSurface(V[1],NULL,detras,&posActual);
                        }
                        break;

                case 3: if(rot==1){
                            SDL_BlitSurface(H[2],NULL,detras,&posActual);
                        }
                        if(rot==2){
                            SDL_BlitSurface(V[2],NULL,detras,&posActual);
                        }
                        break;

                case 4: if(rot==1){
                            SDL_BlitSurface(H[3],NULL,detras,&posActual);
                        }
                        if(rot==2){
                            SDL_BlitSurface(V[3],NULL,detras,&posActual);
                        }
                        break;
                        
                case 5: if(rot==1){
                            SDL_BlitSurface(H[4],NULL,detras,&posActual);
                        }
                        if(rot==2){
                            SDL_BlitSurface(V[4],NULL,detras,&posActual);
                        }
                        break;
            }


            textura= SDL_CreateTextureFromSurface(render,detras); 
            SDL_FreeSurface(detras);
            SDL_RenderCopy(render, textura, NULL, NULL);
            SDL_DestroyTexture(textura);
            SDL_RenderPresent(render);

            if(indice==6){

                aux=0;
                SDL_FreeSurface(fondo);
                break;
            }  

        }
    }


}


int main () {


    SDL_Window   *pantalla=NULL;
    SDL_Surface  *redH[5]={NULL}; 
    SDL_Surface  *redV[5]={NULL};
    SDL_Surface  *grnH[5]={NULL}; 
    SDL_Surface  *grnV[5]={NULL};  
    SDL_Renderer *render=NULL;  
    SDL_Rect cajas[5];
    barco flota[5];
    char mat1[10][10];
    char mat2[10][10];

    int i,j;

    //carga de imagenes

    redH[0]= IMG_Load("./Data/rojos/destructor_h.png");    //barco de 2 destructor
    redH[1]= IMG_Load("./Data/rojos/submarino_h.png");     //barco de 3 submarino
    redH[2]= IMG_Load("./Data/rojos/crucero_h.png");       //barco de 3 crucero
    redH[3]= IMG_Load("./Data/rojos/acorazado_h.png");     //barco de 4 acorazado
    redH[4]= IMG_Load("./Data/rojos/portaaviones_h.png");  //barco de 5 portaaviones
    redV[0]= IMG_Load("./Data/rojos/destructor_v.png");
    redV[1]= IMG_Load("./Data/rojos/submarino_v.png");
    redV[2]= IMG_Load("./Data/rojos/crucero_v.png");
    redV[3]= IMG_Load("./Data/rojos/acorazado_v.png"); 
    redV[4]= IMG_Load("./Data/rojos/portaaviones_v.png");
    grnH[0]= IMG_Load("./Data/verdes/destructor_h.png");
    grnH[1]= IMG_Load("./Data/verdes/submarino_h.png");
    grnH[2]= IMG_Load("./Data/verdes/crucero_h.png");
    grnH[3]= IMG_Load("./Data/verdes/acorazado_h.png"); 
    grnH[4]= IMG_Load("./Data/verdes/portaaviones_h.png");
    grnV[0]= IMG_Load("./Data/verdes/destructor_v.png");
    grnV[1]= IMG_Load("./Data/verdes/submarino_v.png");
    grnV[2]= IMG_Load("./Data/verdes/crucero_v.png");
    grnV[3]= IMG_Load("./Data/verdes/acorazado_v.png"); 
    grnV[4]= IMG_Load("./Data/verdes/portaaviones_v.png");
    

    SDL_Init(SDL_INIT_VIDEO);

    for(i=0;i<10;i++) // rellenamos las matrices de puntos
    {
        for(j=0;j<10;j++)
        {
            mat1[i][j]='.';
            mat2[i][j]='.';
        }
    }

    for(i=0;i<5;i++){ //iniciamos cajas en tamaño cero y barcos en horizontal y disponibilidad 1
        cajas[i].w=0;
        cajas[i].h=0;
        flota[i].orientacion=1;
        flota[i].disponible=1;
    }


    pantalla = SDL_CreateWindow ("barquitos 2000 remastered",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  600,
                                  SDL_WINDOW_RESIZABLE);


    render= SDL_CreateRenderer(pantalla, -1, 0);


    //esta wea recibe lo justo y necesario para funcionar... no
    //cree las cajas y la flota dentro de esta funcion porque tambien las necesita
    //crear matriz para trabajar. si no se hubieran borrado al terminar ponerBarcos.
    ponerBarcos(&redH[0],&redV[0],render,&cajas[0],&flota[0]);

    //luego de crear la matriz del jugador 1 liberamos las imagenes rojas
    SDL_FreeSurface(redH[0]);
    SDL_FreeSurface(redH[1]);
    SDL_FreeSurface(redH[2]);
    SDL_FreeSurface(redH[3]);
    SDL_FreeSurface(redH[4]);

    SDL_FreeSurface(redV[0]);
    SDL_FreeSurface(redV[1]);
    SDL_FreeSurface(redV[2]);
    SDL_FreeSurface(redV[3]);
    SDL_FreeSurface(redV[4]);


    CrearMatriz(&mat1[0][0],&cajas[0],&flota[0]);

    for(i=0;i<10;i++) // comprobacion de la matriz
    {
        for(j=0;j<10;j++)
        {
            printf("%c",mat1[i][j]);
        }
        printf("\n");
    }


    //reseteamos cajas y flotas para poner los barcos verdes...ahora la matriz guarda la informacion
    for(i=0;i<5;i++){ 
        cajas[i].w=0;
        cajas[i].h=0;
        flota[i].orientacion=1;
        flota[i].disponible=1;
    }


    ponerBarcos(&grnH[0],&grnV[0],render,&cajas[0],&flota[0]);


    //liberamos las imagenes verdes... si ya no las vamos a ocupar
    SDL_FreeSurface(grnH[0]);
    SDL_FreeSurface(grnH[1]);
    SDL_FreeSurface(grnH[2]);
    SDL_FreeSurface(grnH[3]);
    SDL_FreeSurface(grnH[4]);

    SDL_FreeSurface(grnV[0]);
    SDL_FreeSurface(grnV[1]);
    SDL_FreeSurface(grnV[2]);
    SDL_FreeSurface(grnV[3]);
    SDL_FreeSurface(grnV[4]);

    CrearMatriz(&mat2[0][0],&cajas[0],&flota[0]);


    for(i=0;i<10;i++) // comprobacion de la matriz 2
    {
        for(j=0;j<10;j++)
        {
            printf("%c",mat2[i][j]);
        }
        printf("\n");
    }

    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(pantalla);
    SDL_Quit();
    return 0;
}