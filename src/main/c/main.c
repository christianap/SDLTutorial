#include <stdio.h>
#include <SDL2/SDL.h>

#define bool int
#define true 1
#define false 0

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;

bool init() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else {
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return(success);
}

bool loadMedia() {
	bool success = true;

	gHelloWorld = SDL_LoadBMP("resources/images/image.bmp");
	if (gHelloWorld == NULL) {
		printf("Unable to load image %s! SDL_Error: %s\n", "resources/images/image.bmp", SDL_GetError());
		success = false;
	}

	return(success);
}

void close() {
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}

int main(int argc, char* args[]) {
	if (!init()) {
		printf("Failed to initialize.\n");
	} else {
		if (!loadMedia()) {
			printf("Failed to load media.\n");
			return(0);
		} else {
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(2000);
		}
	}
	close();
	return(0);
}