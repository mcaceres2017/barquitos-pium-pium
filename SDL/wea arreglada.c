#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

typedef struct
{
    int orientacion; //horzontal o vertical
    int disponible; // 0.no esta disponible 1. esta disponible Ej: no puedes poner 2 destructores
} barco;




void menuPrincipal(SDL_Renderer *render, TTF_Font* fuente){




    /*falta crear que al elegir SALIR o INICIAR PARTIDA pase algo*/
    SDL_Color colorLetra={255,255,255};
    SDL_Surface* fondo= IMG_Load("./Data/menu.png");; //rgb 0 255 240
    SDL_Surface* puntero= IMG_Load("./Data/puntero.png");
    SDL_Surface* vacio;
    SDL_Surface* msn1= TTF_RenderText_Blended_Wrapped(fuente,"Iniciar partida",colorLetra,650);
    SDL_Surface* msn2= TTF_RenderText_Blended_Wrapped(fuente,"Salir",colorLetra,650);
    SDL_Texture* textura;
    SDL_Event evento;
    SDL_Rect posPuntero={185,360,0,0};
    SDL_Rect posMSN1={245,360,0,0};
    SDL_Rect posMSN2={245,420,0,0};

    int aux=1;

    while (aux==1){
        while(SDL_PollEvent(&evento)){


            vacio=SDL_CreateRGBSurface(0,800,600,32,0,0,0,0);
            SDL_BlitSurface(fondo,NULL,vacio,NULL);
            SDL_BlitSurface(msn1,NULL,vacio,&posMSN1);
            SDL_BlitSurface(msn2,NULL,vacio,&posMSN2);

            if(evento.type==SDL_QUIT) 
            { 
                exit(0);
            }

            if(evento.type==SDL_KEYDOWN){ 
                switch(evento.key.keysym.scancode) { 

                    case SDL_SCANCODE_UP:

                        posPuntero.y-=60;

                        if(posPuntero.y<360){

                            posPuntero.y=420;
                        }
                        break;


                    case SDL_SCANCODE_DOWN:

                        posPuntero.y+=60;

                        if(posPuntero.y>420){

                            posPuntero.y=360;
                        }
                        break;
                }
            } 

            SDL_BlitSurface(puntero,NULL,vacio,&posPuntero);
            textura= SDL_CreateTextureFromSurface(render,vacio);
            SDL_FreeSurface(vacio);
            SDL_RenderCopy(render, textura, NULL, NULL);
            SDL_DestroyTexture(textura);
            SDL_RenderPresent(render);
        }
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


int disparoValido(char* mat, int* vidasEnemigo, int* hundidos, SDL_Rect disparo){

    int x=0;
    int y=0;
    x=(disparo.x/80);
    y=(disparo.y/60);
    int retorno=0; // 0.tiro invalido 1.tiro correcto 2.tiro al agua

    if(mat[(y*10)+x]=='O' || mat[(y*10)+x]=='X'){
        printf("tiro invalido, de nuevo\n");
    }

    if(mat[(y*10)+x]=='A'){
        vidasEnemigo[0]-=1;
        printf("A restantes %d\n",vidasEnemigo[0]);
        mat[(y*10)+x]='O';
        retorno=1;

        if(vidasEnemigo[0]==0){
            *hundidos+=1;
        }
    }

    if(mat[(y*10)+x]=='B'){
        vidasEnemigo[1]-=1;
        printf("B restantes %d\n",vidasEnemigo[1]);
        mat[(y*10)+x]='O';
        retorno=1;

        if(vidasEnemigo[1]==0){
            *hundidos+=1;
        }
    }

    if(mat[(y*10)+x]=='C'){
        vidasEnemigo[2]-=1;
        printf("C restantes %d\n",vidasEnemigo[2]);
        mat[(y*10)+x]='O';
        retorno=1;

        if(vidasEnemigo[2]==0){
            *hundidos+=1;
        }
    }

    if(mat[(y*10)+x]=='D'){
        vidasEnemigo[3]-=1;
        printf("D restantes %d\n",vidasEnemigo[3]);
        mat[(y*10)+x]='O';
        retorno=1;

        if(vidasEnemigo[3]==0){
            *hundidos+=1;
        }
    }


    if(mat[(y*10)+x]=='E'){
        vidasEnemigo[4]-=1;
        printf("E restantes %d\n",vidasEnemigo[4]);
        mat[(y*10)+x]='O';
        retorno=1;


        if(vidasEnemigo[4]==0){
            *hundidos+=1;
        }
    }

    if(mat[(y*10)+x]=='.'){
        mat[(y*10)+x]='X';
        retorno=2;
    }

    

    return retorno;


}


void juego(char* mat1, char* mat2, SDL_Renderer* render){




    //SE justifica el uso de variables auxiliares si solo seran dos jugadores?

    int jugador=1; //se parte como el J1
    int vivosJ1[5]={5,4,3,3,2}; //las "vidas", representando el tamaño del barco
    int vivosJ2[5]={5,4,3,3,2};
    int vivosEnemigo[5];// auxiliar para copiar las "vidas" del J1 o del J2
    int J1hundidos=0; //barcos que ha hundido el J1
    int J2hundidos=0; //barcos que ha hundido el J2
    int jugadorHundidos; //auxiliar para los barcos que ha hundido el J1 o el J2
    int cnt1=0,cnt2=0;
    int i,validez,posx=0,posy=0;
    char* matObjetivo=NULL;  //auxiliar para la matriz enemiga
    SDL_Surface* detras;
    SDL_Surface* fondoJuego;
    SDL_Surface* correcto;
    SDL_Surface* fallido;
    SDL_Surface* marcador;
    SDL_Texture* textura;
    SDL_Event evento;

    SDL_Rect posActual; //para mover el marcador, cursor o como le llamen
    posActual.x=0;
    posActual.y=0;

    SDL_Rect disparosJ1[100]; //estos son para ir guardando la posicion de los disparos para mostrar
    SDL_Rect disparosJ2[100]; //las equis o circulos... en el peor de las casos el wn puede haberle
                              //disparado a todas las jodidas casillas.

    fondoJuego= IMG_Load("./Data/juego/fondo_juego.png");
    correcto= IMG_Load("./Data/juego/correcto.png");
    fallido= IMG_Load("./Data/juego/error.png");
    marcador= IMG_Load("./Data/juego/marcador.png");

    while(J1hundidos<5 && J2hundidos<5)
    {
        validez=0;

        if(jugador==1)
        {
            matObjetivo=mat2;
            jugadorHundidos=J1hundidos;

            for(i=0;i<5;i++)
            {
                vivosEnemigo[i]=vivosJ2[i];
            }

        }

        else
        {
            matObjetivo=mat1;
            jugadorHundidos=J2hundidos;

            for(i=0;i<5;i++)
            {
                vivosEnemigo[i]=vivosJ1[i];
            }
        }

        while(SDL_PollEvent(&evento))
        {
            detras=SDL_CreateRGBSurface(0,800,600,32,0,0,0,0);
            SDL_BlitSurface(fondoJuego,NULL,detras,NULL);

            if(evento.type==SDL_QUIT) 
            { 
                exit(0);
            }

            if(evento.type==SDL_KEYDOWN){ 
                switch(evento.key.keysym.scancode) { 

                    case SDL_SCANCODE_UP:  
                        
                        posActual.y-=60;   

                        if(posActual.y<0){  
                            posActual.y=0;
                        }

                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_DOWN: 

                        posActual.y+=60;

                        if(posActual.y>540){  
                            posActual.y=540;
                        }


                        SDL_RenderClear(render);
                        break;

                    case SDL_SCANCODE_RIGHT: 

                        posActual.x+=80;

                        if(posActual.x>720){
                            posActual.x=720;
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

                        validez=disparoValido(matObjetivo,&vivosEnemigo[0],&jugadorHundidos,posActual);
                        printf("validez=%d\n",validez);
                        if(validez==1 || validez==2){

                            if(jugador==1)
                            {
                                disparosJ1[cnt1]=posActual;
                                cnt1++;
                            }

                            else
                            {
                                disparosJ2[cnt2]=posActual;
                                cnt2++;
                            }
                        }

                        else{
                            printf("apunta bien\n");
                        }
                        break;
                }//fin de switch
            }//fin de if


            if(jugador==1){

                for(i=0;i<cnt1;i++){

                    posx=(disparosJ1[i].x/80);
                    posy=(disparosJ1[i].y/60);
                    if(matObjetivo[(posy*10)+posx]=='O'){
                        SDL_BlitSurface(correcto,NULL,detras,&disparosJ1[i]);
                    }

                    if(matObjetivo[posy*10+posx]=='X'){
                        SDL_BlitSurface(fallido,NULL,detras,&disparosJ1[i]);
                    }
                
                }  
            }

            else{

                for(i=0;i<cnt2;i++){

                    posx=(disparosJ2[i].x/80);
                    posy=(disparosJ2[i].y/60);
                    if(matObjetivo[(posy*10)+posx]=='O'){
                        SDL_BlitSurface(correcto,NULL,detras,&disparosJ2[i]);
                    }

                    if(matObjetivo[posy*10+posx]=='X'){
                        SDL_BlitSurface(fallido,NULL,detras,&disparosJ2[i]);
                    }
                
                }

            }
            
            SDL_BlitSurface(marcador,NULL,detras,&posActual);
            textura= SDL_CreateTextureFromSurface(render,detras); 
            SDL_FreeSurface(detras);
            SDL_RenderCopy(render, textura, NULL, NULL);
            SDL_DestroyTexture(textura);
            SDL_RenderPresent(render);

            if(jugador==1)
            {
                J1hundidos=jugadorHundidos;
                for(i=0;i<5;i++)
                {
                    vivosJ2[i]=vivosEnemigo[i];
                }
            }

            if(jugador==2)
            {
                J2hundidos=jugadorHundidos;
                for(i=0;i<5;i++)
                {
                    vivosJ1[i]=vivosEnemigo[i];
                }
            }

        }//fin while eventos


        if(validez==2)
        {   
            
            //Falta agregar Delay
            if(jugador==1)
            {
                jugador=2;
                printf("cambio a 2\n");
            }

            else
            {
                jugador=1;
                printf("cambio a 1\n");
            }
        }

    }//fin while "vidas"
} //fin funcion


int main () {


    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();


    barco flota[5];
    SDL_Rect cajas[5];
    TTF_Font* fuente= TTF_OpenFont("./Data/fuente/pokemon.ttf",30);
    SDL_Window   *pantalla=NULL;
    SDL_Renderer *render=NULL; 
    SDL_Surface  *redH[5]={NULL}; 
    SDL_Surface  *redV[5]={NULL};
    SDL_Surface  *grnH[5]={NULL}; 
    SDL_Surface  *grnV[5]={NULL};


    char mat1[10][10];
    char mat2[10][10];
    int i;


    pantalla = SDL_CreateWindow ("barquitos 2000 remastered",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  800,
                                  600,
                                  SDL_WINDOW_RESIZABLE);



    render= SDL_CreateRenderer(pantalla, -1, 0);

    menuPrincipal(render,fuente);

    //EL PROGRAMA SE QUEDA ATORADO EN MENUPRINCIPAL PORQUE NO LE PUSE QUE HAGA ALGO



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



    for(i=0;i<5;i++){ //iniciamos cajas en tamaño cero y barcos en horizontal y disponibilidad 1
        cajas[i].w=0;
        cajas[i].h=0;
        flota[i].orientacion=1;
        flota[i].disponible=1;
    }

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
        
    juego(&mat1[0][0],&mat2[0][0],render);


    printf("fin del juego\n");


    
    TTF_CloseFont(fuente);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(pantalla);
    TTF_Quit();
    SDL_Quit();
    return 0;
}