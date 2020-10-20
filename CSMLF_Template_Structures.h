#ifndef STRUCT_TEMP_H_
#define STRUCT_TEMP_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

typedef struct Template_s {
  sfTexture *background;
  sfSprite *spt_background;
  int life;
  int score;
  sfVector2f cursor_position;
} Template_t;

#endif
