#include "CSFML_Template_Structures.h"

Template_t *create_structure(sfRenderWindow *window)
{
  Template_t *structure = malloc(sizeof(*structure));
  structure->background = sfTexture_createFromFile("asset/background.jpg", NULL);
  structure->spt_background = sfSprite_create();
  sfSprite_setTexture(structure->spt_background, structure->background; sfTrue);
  structure->score = 0;
  return structure;
}

void free_structure(Template_t *structure, sfRenderWindow *window)
{
  sfTexture_destroy(structure->background);
  sfSprite_destroy(structure->spt_background);
}

void draw_structure(sfRenderWindow *window, Template_t *structure)
{
  sfRenderWindow_drawSprite(window, structure->spt_background, NULL);
}

int menu(sfRenderWindow *window)
{
  sfEvent event;
  Template_t *structure = create_structure(window);
  structure->heal = 3;
  while (sfRenderWindow_isOpen(window))
  {
    while (sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed)
      {
        free_structure(structure, window);
        return -1;
      }
    }
    draw_structure(window, structure);
    sfRenderWindow_display(window);
  }
}
