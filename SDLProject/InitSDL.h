#ifndef InitSDL_H
#define InitSDL_H

#include <SDL.h>
#include <stdio.h>
#include <memory>

class InitSDL
{
public:
  InitSDL();
  InitSDL(char *screenTitle, int *screenWidth, int *screenHeight, Uint32 *flag);
  ~InitSDL();

  void init();
  void init(char *screenTitle, int *screenWidth, int *screenHeight, Uint32 *flag);

  /** 
   * Inline Functions 
   */
  SDL_Window *getWindow() { return _window; }

private:
	SDL_Window *_window;
  int *_screenWidth, *_screenHeight;
  char *_screenTitle;
  Uint32 *_flag;

  void initWindow(char *screenTitle, int *screenWidth, int *screenHeight, Uint32 *flag);
};

#endif
