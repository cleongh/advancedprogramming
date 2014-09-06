extern "C" {
#include <SDL.h>
}

int main(int argc, char const *argv[])
{

  /* initialize SDL */
  SDL_Init(SDL_INIT_VIDEO);

  /* set the title bar */
  SDL_WM_SetCaption("SDL Test", "SDL Test");

  /* create window */
  SDL_Surface* screen = SDL_SetVideoMode(640, 480, 0, 0);

  SDL_Event event;
  int gameover = 0;

  /* message pump */
  while (!gameover)
  {
    /* look for an event */
    if (SDL_PollEvent(&event)) {
      /* an event was found */
      switch (event.type) {
        /* close button clicked */
        case SDL_QUIT:
          gameover = 1;
          break;

        /* handle the keyboard */
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
            case SDLK_q:
              gameover = 1;
              break;
          }
          break;
      }
    }

    /* update the screen */
    SDL_UpdateRect(screen, 0, 0, 0, 0);
  }

  /* cleanup SDL */
  SDL_Quit();

  return 0;
}

