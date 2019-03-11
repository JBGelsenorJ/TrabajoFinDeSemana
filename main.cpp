#include"SDL_Image/Include/SDL_image.h"
#include "SDL/include/SDL.h"

#include<stdio.h>

#pragma comment(lib, "SDL/Libx86/SDL2.lib")
#pragma comment(lib, "SDL/Libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Image/Libx86/SDL2_image.lib")
int main(int argc, char* argv[]) {
	SDL_Window *window;                    // pointer window
	SDL_Renderer* renderer;				// pointer for rendering
	SDL_Init(SDL_INIT_VIDEO);              // inicialize
	IMG_Init(IMG_INIT_PNG);

	SDL_Surface* Loading_Surf;
	SDL_Surface* Loading_Surf1;
	SDL_Surface* Loading_Surf2;
	SDL_Texture *background;

	SDL_Texture *starship;
	
	
	SDL_Texture *laser;
	//laser = IMG_Load("Assets/images/bullet.png");
	
	// Creacion de una ventana
	window = SDL_CreateWindow(
		"Amazing work",                  // window's name
		SDL_WINDOWPOS_UNDEFINED,           // initial pos x 
		SDL_WINDOWPOS_UNDEFINED,           // initial pos y 
		1024,                               // width
		512,                               // height
		0);
	int numx = 0;
	int numy = 0;
	int ban = 0;
	int rec1x = 0;
	bool running = true;
	while (running) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type==SDL_QUIT)
			{
				running = false;
			}
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					numx -= 30;
					break;
				case SDLK_RIGHT:
					numx += 30;
					break;
				case SDLK_UP:
					numy -= 30;
					break;
				case SDLK_DOWN:
					numy += 30;
					break;
				case SDLK_SPACE:
					ban = 1;
					rec1x = 0;
					break;
				case SDLK_ESCAPE:
					running = false;
					break;
				default:
					break;
				}
			}
		}
		renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_PRESENTVSYNC); //with this we make possible that the draws affects this window

		Loading_Surf = IMG_Load("Assets/images/background.png");
		background = SDL_CreateTextureFromSurface(renderer, Loading_Surf);
		SDL_FreeSurface(Loading_Surf);
		SDL_RenderCopy(renderer, background, NULL, NULL);

		Loading_Surf1 = IMG_Load("Assets/images/starship.png");
		starship = SDL_CreateTextureFromSurface(renderer, Loading_Surf1);
		SDL_FreeSurface(Loading_Surf1);
		SDL_RenderCopy(renderer, starship, NULL, NULL);
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
		//SDL_Rect rectangle; //Creating a rectangle
		/*rectangle.x = numx; //Position in x
		rectangle.y = numy; // position in y
		rectangle.w = 200; //width
		rectangle.h = 100; //height
		SDL_RenderFillRect(renderer, &rectangle); */


		if (ban == 1)
		{
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); 
		SDL_Rect rectangle1; 
		rectangle1.x = numx + 220 +rec1x; 
		rectangle1.y = numy + 50; 
		rectangle1.w = 100; 
		rectangle1.h = 30; 
		SDL_RenderFillRect(renderer, &rectangle1);
			for (int i = 0; i < 200; i++)
			{
				rec1x++;
			}

		}
		SDL_RenderPresent(renderer); 		//until here the code renders on every loop
		SDL_Delay(100);
		SDL_DestroyRenderer(renderer);


	}	

	// Clean up
	SDL_Quit();
	IMG_Quit();
	return 0;
}
