#include <Arduboy.h>
#include "warsprites.h"

Arduboy arduboy;

const unsigned char *staticSprites[6] = {warsprite_trees, warsprite_dirt, warsprite_mountain, warsprite_hill, warsprite_house, warsprite_bighouse};
const unsigned char *animatedSprites[10] = {warsprite_grass1, warsprite_infantry1, warsprite_tank1, warsprite_car1, warsprite_plane1,
                                            warsprite_grass2, warsprite_infantry2, warsprite_tank2, warsprite_car2, warsprite_plane2};
bool flip = true;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(30);
}

void loop() {
  if (!(arduboy.nextFrame()))
    return;
  if (!(arduboy.everyXFrames(15)))
    return;
    
  arduboy.clear();
  
  // static sprites
  byte posx = 0;
  for(byte i = 0; i < 6; i++){
    posx = 2 + 10*i;
    arduboy.drawBitmap(posx, 2, staticSprites[i], 8, 8, 1);
  }

  // animated sprites
  for(byte i = 0; i < 5; i++){
    posx = 2 + 10*i;
    arduboy.drawBitmap(posx, 12, animatedSprites[flip?i:i+5], 8, 8, 1);
  }

  flip = !flip;
  arduboy.display();
}
