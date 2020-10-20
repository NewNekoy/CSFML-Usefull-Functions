/*
** Simple functions for creating window in SFML
**
** Prototype : createMyWindow(unsigned int width, unsigned int height) Just set 1920 & 1080 for default window size
** Only 'createMyWindow' is make with Coding Style no errors !
** main function have some coding style errors, use structures for you're texture and sprite.
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode mode;

    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(mode, "Name of Window", sfClose, NULL);
    if (!window)
        return 0;
    return (window);
}

int main(void)
{
  sfRenderWindow *window = createMyWindow(1920, 1080);
  sfEvent event;

  while (sfRenderWindow_isOpen(window))
  {
    while (sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return 0;
      }
  }
  sfRenderWindow_display(window);
  return 0;
}
