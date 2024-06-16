// Uzebox Kickstart


#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdlib.h>
#include <uzebox.h>

#include "data/kick13.inc"

int main()
{
    SetSpritesTileTable(tileset);
    SetTileTable(tileset);
    ClearVram();
    while (1)
    {
        DrawMap2(0,0,kick13);
    }
}
