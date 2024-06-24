// Uzebox Kickstart

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdlib.h>
#include <uzebox.h>

#include "data/drive_click.inc"
#include "data/kick13.inc"


#define PCM_PATCH 1
#define PCM_CHANNEL 4
#define PLAY_SPEED 23

int played = 0;

int btnPrev = 0;     // Previous button
int btnHeld = 0;     // buttons that are held right now
int btnPressed = 0;  // buttons that were pressed this frame
int btnReleased = 0; // buttons that were released this frame

const struct PatchStruct patches[] PROGMEM = {
  {2,drive_click_wav,NULL,sizeof(drive_click_wav)-2,sizeof(drive_click_wav)-1},
};

void processControls(void)
{
    btnHeld = ReadJoypad(0); //read in our player one joypad input
    btnPressed = btnHeld & (btnHeld ^ btnPrev);
    btnReleased = btnPrev & (btnHeld ^ btnPrev);

	if(btnHeld & BTN_B){
        TriggerNote(PCM_CHANNEL,PCM_PATCH,PLAY_SPEED,255);
    }
    btnPrev = btnHeld;
}

int main()
{
    SetSpritesTileTable(tileset);
    InitMusicPlayer(patches);
    SetTileTable(tileset);
    ClearVram();
    while(1) {
      WaitVsync(1);
      DrawMap2(0,0,kick13);
      processControls();
    }
}
