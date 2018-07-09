#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

using namespace std;

int main()
{
    // Iniciamos el subsistema de video

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
	
	cerr << "No se pudo iniciar SDL: " << SDL_GetError() << endl;
	exit(1);
    }

    atexit(SDL_Quit);

    // Comprobamos que sea compatible el modo de video
    
    if(SDL_VideoModeOK(640, 480, 24, SDL_HWSURFACE|SDL_DOUBLEBUF) == 0) {
	
        cerr << "Modo no soportado: " << SDL_GetError() << endl;
        exit(1);
	
    }

    // Antes de establecer el modo de video
    // Establecemos el nombre de la ventana

    SDL_WM_SetCaption("Prueba. SDL_mixer", NULL);

    // Establecemos el modo

    SDL_Surface *pantalla;
    
    pantalla = SDL_SetVideoMode(640, 480, 24, SDL_HWSURFACE|SDL_DOUBLEBUF);
    
    if(pantalla == NULL) {
	
	cerr << "No se pudo establecer el modo de video: "
	     << SDL_GetError();
	
	exit(1);
    }

    // Inicializamos la librería SDL_Mixer

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,\
		     MIX_DEFAULT_CHANNELS, 4096) < 0) {
	
	cerr << "Subsistema de Audio no disponible" << endl;
	exit(1);
    }

    // Al salir cierra el subsistema de audio

    atexit(Mix_CloseAudio);

    // Cargamos un fichero para la BSO

    Mix_Music *bso;

    bso = Mix_LoadMUS("./Data/musica para probar weas/Riviera The Promised Land Soundtrack 24 Triumph.wav");

    if(bso == NULL) {

	cerr << "No se puede cargar el fichero bso.mp3" << endl;
	exit(1);
    }

    // Variables auxiliares

    SDL_Event evento;
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,\
	 		SDL_DEFAULT_REPEAT_INTERVAL);

    int volumen = 100;

     cout << "Pulse ESC para salir" << endl;
    cout << "Pulse Q para subir el volumen" << endl;
    cout << "Pulse A para bajar el volumen" << endl;
    cout << "Pulse I para reproduccir la música" << endl;
    cout << "Pulse P para pausar la reproducción" << endl;
    cout << "Pulse R para reproduccir la música después del pause" << endl;
    cout << "Pulse W para poner la música al inicio" << endl;
    cout << "Pusel H para mostrar ayuda" << endl;

    // Bucle infinito 
    
    for( ; ; ) {

	// RECUERDA: -1 en SDL_Mixer en las llamadas a función
	// simboliza infinito

        while(SDL_PollEvent(&evento)) {

            if(evento.type == SDL_KEYDOWN) {

                if(evento.key.keysym.sym == SDLK_ESCAPE) {

		    // Cerramos el sistema de audio
		    // al terminar de trabajar con él
		    
		    Mix_FreeMusic(bso);
		    
		    cout << "Gracias" << endl;
	 

		    return 0;
		}

                // Manejo del Volumen

                if(evento.key.keysym.sym == SDLK_q) {

                    volumen += 2;

                    if(volumen < 128)
                        Mix_VolumeMusic(volumen);
                    else
                        volumen = 128;

                    cout << "Volumen actual: " << volumen << endl;

                }

                if(evento.key.keysym.sym == SDLK_a) {

                    volumen -= 2;

                    if(volumen > -1) 
                        Mix_VolumeMusic(volumen);
                    else
                        volumen = 0;

                    cout << "Volumen actual: " << volumen << endl;

                }

		// Control de la reproducción 
		
		if(evento.key.keysym.sym == SDLK_i) {

		    Mix_PlayMusic(bso, -1);

		    cout << "Música iniciada" << endl;
		    
		}

		if(evento.key.keysym.sym == SDLK_p) {
		    
		    if(Mix_PlayingMusic() == 1) {
		    
			Mix_PauseMusic();
			
			cout << "Música en pausa" << endl;

		    } else {

			cout << "La música no está en reproducción" << endl;

		    }

		}

		if(evento.key.keysym.sym == SDLK_r) {
		    
	 	    if(Mix_PausedMusic() == 1) {

			Mix_ResumeMusic();
 			
			cout << "Música en reproducción" << endl;
		    } else {
		    
			cout << "La música ya está en reproducción" << endl;

		    }
		}

		if(evento.key.keysym.sym == SDLK_w) {
		    
		    Mix_RewindMusic();
		    
		    cout << "Música al principio" << endl;

	 	}

 		if(evento.key.keysym.sym == SDLK_h) {

 		    cout << "\n   == AYUDA == " << endl;
 		    cout << "Pulse ESC para salir" << endl;
	 	    cout << "Pulse Q para subir el volumen" << endl;
  		    cout << "Pulse A para bajar el volumen" << endl;
 		    cout << "Pulse I para reproduccir la música" << endl;
 		    cout << "Pulse P para pausar la reproducción" << endl;
	 	    cout << "Pulse R para reproduccir la música después del pause" << endl;
 		    cout << "Pulse W para poner la música al inicio" << endl;
		    cout << "Pusel H para mostrar ayuda" << endl;

		}

	     }
	}
	
     }

}