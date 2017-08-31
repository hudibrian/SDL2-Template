#include "InitSDL.h"
/**
 * Had to undefine main because SDL_main was causing
 * an issue with main being defined multiple times
*/
#undef main

std::unique_ptr<InitSDL> sdl(new InitSDL());

int main()
{
  SDL_Surface *screenSurface;

  sdl->init();

  SDL_Window *window = sdl->getWindow();

  if (window != NULL)
  {
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(10000);
  }
  else
  {
    SDL_Quit();
    exit(EXIT_FAILURE);
  }

  return 0;
}
