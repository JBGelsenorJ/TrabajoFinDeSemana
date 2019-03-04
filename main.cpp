#include"SDL/include/SDL.h"
#include<stdio.h>
#pragma comment(lib, "SDL/Libx86/SDL2.lib")
#pragma comment(lib, "SDL/Libx86/SDL2main.lib")
int main(int argc, char* argv[]) {
	SDL_Window *window;                    // puntero ventana
	SDL_Renderer* renderer;				// puntero para renderizar
	SDL_Init(SDL_INIT_VIDEO);              // inicializar

	// Creacion de una ventana
	window = SDL_CreateWindow(
		"Trabajo finde javier belda",                  // nombre pentaña
		SDL_WINDOWPOS_UNDEFINED,           // posicion x incial
		SDL_WINDOWPOS_UNDEFINED,           // pos y inicial
		512,                               // anchura
		512,                               // altura
		0);
	int numx = 0;
	int numy = 0;
	int ban = 0;
	while (1) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				/* Look for a keypress */
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					numx -= 10;
					break;
				case SDLK_RIGHT:
					numx += 10;
					break;
				case SDLK_UP:
					numy -= 10;
					break;
				case SDLK_DOWN:
					numy += 10;
					break;
				case SDLK_SPACE:
					ban = 1;
					break;
				default:
					break;
				}
			}
		}
		renderer = SDL_CreateRenderer(window, -1, 0); //para que los dibujos afecten a dicha ventana
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // elegimos color
		SDL_RenderClear(renderer);// limpia la pantalla con el color elegido
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // color de dibujo
		SDL_Rect rectangle; //Creamos rectangulo
		rectangle.x = numx; //Posicion en x
		rectangle.y = numy; // posicion en y
		rectangle.w = 200; //ancho
		rectangle.h = 100; //alto
		SDL_RenderFillRect(renderer, &rectangle);
		if (ban == 1)
		{
			/*renderer = SDL_CreateRenderer(window, -1, 0); //para que los dibujos afecten a dicha ventana
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // color de dibujo
			SDL_Rect rectangle1; //Creamos rectangulo
			rectangle1.x = 256; //Posicion en x
			rectangle1.y = -256; // posicion en y
			rectangle1.w = 50; //ancho 
			rectangle1.h = 50; //alto */
		}
		SDL_RenderPresent(renderer); 		//Hasta aqui renderiza en cada bucle
		SDL_Delay(1000);
		SDL_DestroyRenderer(renderer);
	}	

	

	// Destruye la ventana (en teoria)
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}
