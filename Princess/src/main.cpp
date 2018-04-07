#define SDL_MAIN_HANDLED

#include <iostream>

#include "LTimer.h"
#include <chrono>
#include <time.h>
#include "Tile.h"
#include "AStar.h"


int GAME_SCALE = 3;

int main()
{
	SDL_Window* gameWindow = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 816, 624, SDL_WINDOW_SHOWN);
	//SDL_Renderer* gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Event *e = new SDL_Event();



	unsigned int lastTime = 0;
	float deltaTime = 0;
	unsigned int currentTime = 0;
	srand(time(NULL));

	bool debug = false;

	srand(time(NULL));

	const int SCREEN_FPS = 60;

	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


	//The frames per second timer
	LTimer fpsTimer;

	//The frames per second cap timer
	LTimer capTimer;

	//Start counting frames per second
	int countedFrames = 0;

	fpsTimer.start();


	// Setup renderer
	// sets renderer for window
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
	//renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);


	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);
	//SDL_RenderClear(renderer);


	// Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
	SDL_Rect r;
	r.x = 0;
	r.y = 0;
	r.w = 50;
	r.h = 50;

	std::vector<Tile*> tileVector;

	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			tileVector.push_back(new Tile(i * 8, j * 8, 8, 8));
		}
	}








	while (7 == 7)
	{
	//	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);


		SDL_RenderClear(renderer);
	//	SDL_RenderClear(renderer);


		for (int i = 0; i < tileVector.size(); i++)
		{

			//	SDL_SetRenderDrawColor(renderer, i % 255 , i % 255, i % 255, 200); //yellow
			tileVector.at(i)->render(renderer, i);
		}


		//Calculate and correct fps
		int avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}


		while (SDL_PollEvent(e)) 
		{
			switch (e->type) 
			{
				/* Look for a keypress */
			case SDL_KEYDOWN:
				/* Check the SDLKey values and move change the coords */
				switch (e->key.keysym.sym) 
				{
				case SDLK_LEFT:
					r.x -= 8;
					break;
				case SDLK_RIGHT:
					r.x += 8;
					break;
				case SDLK_UP:
					r.y -= 8;
					break;
				case SDLK_DOWN:
					r.y += 8;
					break;
				default:
					break;
				}
			}
		}
	

		//Set text to be rendered
		if (avgFPS > 1)
		{
			//			cout << "FPS (With Cap) " << avgFPS << endl;;
		}
		//update ren
		++countedFrames;

		//If frame finished early
		int frameTicks = capTimer.getTicks();

		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);

			currentTime = SDL_GetTicks();
			if (currentTime > lastTime)
			{
				deltaTime = ((float)(currentTime - lastTime)) / 1000;

			//	input->handleInput();
	
				//update something
				lastTime = currentTime;
			}

			//SDL_RenderClear(renderer);

			///////////DRAW BEG
			// Set render color to blue ( rect will be rendered in this color )


			SDL_SetRenderDrawColor(renderer, 255, 200, 0, 200); //yellow

			// Render rect
			SDL_RenderFillRect(renderer, &r);




			///////////DRAW END
//
		//	SDL_RenderCopy(renderer)

			SDL_RenderPresent(renderer);

			cout << "test tick" << endl;
		}
	}

	SDL_RenderPresent(renderer);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gameWindow);

	IMG_Quit();
	SDL_Quit();

	return 0;
}



