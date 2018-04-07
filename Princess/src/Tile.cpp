#include "Tile.h"

Tile::Tile()
{
	r.x = 0;
	r.y = 0;
	r.w = 8;
	r.y = 8;
}

Tile::Tile(int x, int y, int width, int height)
{
	r.x = x;
	r.y = y;
	r.w = width;
	r.h = height;
}

Tile::Tile(int size)
{
	r.w = size;
	r.h = size;
}

void Tile::render(SDL_Renderer* r, int i)
{
	SDL_RenderClear(r);
	SDL_SetRenderDrawColor(r, 55, 55, 55, 200); //yellow

	//SDL_RenderPresent(r);
	
}