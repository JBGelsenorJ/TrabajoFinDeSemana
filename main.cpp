#include"SDL/include/SDL.h"
#include<stdio.h>
#pragma comment(lib, "SDL/Libx86/SDL2.lib")
#pragma comment(lib, "SDL/Libx86/SDL2main.lib")
int main(int argc, char* argv[]) {
	SDL_Window *window;                    // puntero ventana
	SDL_Renderer* renderer;				// puntero para renderizar
	SDL_Init(SDL_INIT_VIDEO);              // inicializar

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"An SDL2 window",                  // nombre pentaña
		SDL_WINDOWPOS_UNDEFINED,           // posicion x incial
		SDL_WINDOWPOS_UNDEFINED,           // pos y inicial
		512,                               // anchura
		512,                               // altura
		0);

	while (1) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			/* handle your event here */
		}
		renderer = SDL_CreateRenderer(window, -1, 0); //para que los dibujos afecten a dicha ventana
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // elegimos color
		SDL_RenderClear(renderer);// limpia la pantalla con el color elegido
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // color de dibujo
		SDL_Rect rectangle; //Creamos rectangulo
		rectangle.x = 10; //Posicion en x
		rectangle.y = 100; // posicion en y
		rectangle.w = 200; //ancho
		rectangle.h = 200; //alto
		SDL_RenderFillRect(renderer, &rectangle);
		SDL_RenderPresent(renderer); 		//Hasta aqui renderiza en cada bucle
	}

	

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}