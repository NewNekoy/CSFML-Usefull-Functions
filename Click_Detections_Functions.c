/*
** Click functions is a simple functions who return 'true or false' statement if user click into the Sprite.
**
** Prototype : isClick(sfSprite yourSprite, sfTexture yourTexture, sfEvent event)
** Only 'isClick & createMyWindow' is make with Coding Style no errors !
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
    window = sfRenderWindow_create(mode, "My_Hunter", sfClose, NULL);
    if (!window)
        return 0;
    return (window);
}

bool isClick(sfSprite *s, sfTexture *t, sfEvent e)
{
  sfVector2u tSize = sfTexture_getSize(t);
  sfVector2f sPos = sfSprite_getPosition(s);
  
  if (event.type = sfEvtMouseButtonPressed) {
    if (event.mouseButton.x >= sPos.x && event.mouseButton.x <= (sPos + tSize.x)
    && event.mouseButton.y >= sPos.y && event.mouseButton.y <= (sPos + tSize.y))
      return true;
  }
  return false;
}

int main(void)
{
  sfRenderWindow *window = createMyWindow(1920, 1080);
  sfEvent event;
  
  sfTexture *myTexture = sfTexture_createFromFile("asset/texture.jpg", NULL);
  sfSprite *mySprite = sfSprite_create();
  sfSprite_setTexture(mySprite, myTexture, sfTrue);
  
  while (sfRenderWindow_isOpen(window))
  {
    while (sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed) {
        sfDestroy_Texture(myTexture);
        sfDestroy_Sprite(mySprite);
        sfRenderWindow_close(window);
        return 0;
      }
      if (isClick(mySprite, myTexture) == true)
        // Do what you want if user click !
    }
  }
  sfRenderWindow_drawSprite(window, mySprite, NULL);
  sfRenderWindow_display(window);
  return 0;
}
