//
// Galaxian for Arduboy
//

#include "MicroGamer.h"
#include "game.h"

MicroGamer mArduboy;
MicroGamerTones sound(mArduboy.audio.enabled);
Game mGame;

void setup()
{
  mArduboy.begin();
  mArduboy.initRandomSeed();
  mArduboy.setFrameRate(60);

#ifdef CAPTURE_SCREEN
  Serial.begin(115200);
#endif
}

void loop()
{
  if (!(mArduboy.nextFrame())) {
    return;
  }

  mArduboy.clear();
  mGame.check_input();
  mGame.do_state();
  mGame.draw();
  mArduboy.display();
}

