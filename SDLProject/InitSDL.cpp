#include "InitSDL.h"

InitSDL::InitSDL()
{
  _screenTitle = "Default Title";
  _screenHeight = new int(1080);
  _screenWidth = new int(1920);
  _flag = new Uint32(1);
}

InitSDL::InitSDL(char *screenTitle, int *screenWidth, int *screenHeight, Uint32 *flag)
{
  _screenTitle = screenTitle;
  _screenWidth = screenWidth;
  _screenHeight = screenHeight;
  _flag = flag;
}

InitSDL::~InitSDL()
{
  SDL_DestroyWindow(_window);
  SDL_Quit();
}

void InitSDL::init()
{
  initWindow(_screenTitle, _screenWidth, _screenHeight, _flag);
}

void InitSDL::init(char *screenTitle, int *screenWidth, int *screenHeight, Uint32 *flag)
{
  initWindow(screenTitle, screenWidth, screenHeight, flag);
}

void InitSDL::initWindow(char * screenTitle, int * screenWidth, int * screenHeight, Uint32 * flag)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		_window = SDL_CreateWindow(
			screenTitle,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			*screenWidth,
			*screenHeight,
			*flag);

		if (_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
	}
}