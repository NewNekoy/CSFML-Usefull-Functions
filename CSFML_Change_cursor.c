/*
** Draw_Cursor is a simple functions who set you're mouse to another texture choose by you.
**
** Prototype : Draw_Cursor(sfRenderWindow *window, sfSprite *sCursor)
** Only 'Draw_Cursor and createMyWindow' is make with Coding Style no errors !
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

void Draw_Cursor(sfRenderWindow *window, sfSprite *sCursor)
{
  sfVector2f cursorPos;
  cursorPos.x = sfMouse_getPosition(window).x;
  cursorPos.y = sfMouse_getPosition(window).y;
  sfSprite_setPosition(sCursor, cursor_Pos);
  sfRenderWindow_drawSprite(window, sCursor, NULL);
}

int main(void)
{
  sfRenderWindow *window = createMyWindow(1920, 1080);
  sfEvent event;
  
  sfTexture *cursor_Texture = sfTexture_createFromFile("asset/cursor.png", NULL);
  sfSprite *cursor_Sprite = sfSprite_create();
  sfSprite_setTexture(cursor_Sprite, cursor_Texture, sfTrue);
  sfRenderWindow_setMouseCursorVisible(window, sfFalse);
  while (sfRenderWindow_isOpen(window))
  {
    while (sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed) {
        sfTexture_destroy(cursor_Texture);
        sfSprite_destroy(cursor_Sprite);
        sfRenderWindow_close(window);
        return 0;
      }
    }
  }
  Draw_Cursor(window, cursor_Sprite);
  sfRenderWindow_display(window);
  return 0;
}
