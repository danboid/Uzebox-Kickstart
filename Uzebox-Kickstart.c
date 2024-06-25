// Uzebox Kickstart

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdlib.h>
#include <uzebox.h>

#include "data/drive_click.inc"
#include "data/kick13.inc"


#define PCM_PATCH 0
#define PCM_CHANNEL 4
#define PLAY_SPEED 23

int disk_timer = 0;

const struct PatchStruct patches[] PROGMEM = {
  {2,drive_click_wav,NULL,sizeof(drive_click_wav)-2,sizeof(drive_click_wav)-1},
};

int main()
{
  SetSpritesTileTable(tileset);
  InitMusicPlayer(patches);
  SetTileTable(tileset);
  ClearVram();
  while(1) {
    DrawMap2(0,0,kick13);
    disk_timer++;
    if(disk_timer >= 300) {
      TriggerNote(PCM_CHANNEL,PCM_PATCH,PLAY_SPEED,255);
      disk_timer = 0;
    }
  }
}
