#include <gb/gb.h>
#include <stdio.h>
#include "backgroundtiles.c"
#include "coronabackground.c"
#include "GameCharacter.c"
#include "CharacterSprites.c"

struct GameCharacter toiletpaper;


UBYTE spritesize = 8;

void moveit(struct GameCharacter* character, UINT8 x, UINT8 y){
    move_sprite(character->spriteids[0], x, y);
    move_sprite(character->spriteids[1], x + spritesize, y);
    move_sprite(character->spriteids[2], x, y + spritesize);
    move_sprite(character->spriteids[3], x + spritesize, y + spritesize);
}

void setuptoilet(){
    toiletpaper.x = 80;
    toiletpaper.y = 130;
    toiletpaper.width = 16;
    toiletpaper.height = 16;

    set_sprite_tile(0,0);
    toiletpaper.spriteids[0] = 0;
    set_sprite_tile(2,2);
    toiletpaper.spriteids[1] = 2;
    set_sprite_tile(1,1);
    toiletpaper.spriteids[2] = 1;
    set_sprite_tile(3,3);
    toiletpaper.spriteids[3] = 3;

    moveit(&toiletpaper, toiletpaper.x, toiletpaper.y);

}






void main(){

    set_sprite_data(0, 8, CharacterSprites);
   
    setuptoilet();


    
    
    set_bkg_data(0, 7, backgroundtiles);
    set_bkg_tiles(0, 0, 40, 18, backgroundmap);


    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    while(1){
        scroll_bkg(1,0);
        delay(100);

        if(joypad() & J_LEFT){
            toiletpaper.x -= 2;
            moveit(&toiletpaper, toiletpaper.x, toiletpaper.y);
            NR52_REG = 0x80;
        }
        if(joypad() & J_RIGHT){
            toiletpaper.x += 2;
            moveit(&toiletpaper, toiletpaper.x, toiletpaper.y);
            NR52_REG = 0x80;
        }
        if(joypad() & J_UP){
            toiletpaper.y -= 2;
            moveit(&toiletpaper, toiletpaper.x, toiletpaper.y);
            NR52_REG = 0x80;
        }
        if(joypad() & J_DOWN){
            toiletpaper.y += 2;
            moveit(&toiletpaper, toiletpaper.x, toiletpaper.y);
            NR52_REG = 0x80;
        }

        
    }
}