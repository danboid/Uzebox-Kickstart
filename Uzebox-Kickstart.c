// Uzebox Kickstart


#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdlib.h>
#include <uzebox.h>
#include <unistd.h>

#include "data/kick13.inc"
#include "data/drive_click.inc"

#define PCM_PATCH 1
#define PCM_CHANNEL 3
#define PLAY_SPEED 23

int frames = 0;

const struct PatchStruct patches[] PROGMEM = {
  {2,drive_click_wav,NULL,0,sizeof(drive_click_wav)-1},
};

int main()
{
    SetSpritesTileTable(tileset);
    SetTileTable(tileset);
    ClearVram();
    while (1)
    {
        DrawMap2(0,0,kick13);
        frames++;
        if (frames >= 180) {
                TriggerNote(PCM_CHANNEL,PCM_PATCH,PLAY_SPEED,128);
            }
        
    }
}
