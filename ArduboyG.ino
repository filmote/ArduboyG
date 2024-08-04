#define ABG_IMPLEMENTATION
#define ABG_SYNC_PARK_ROW
#define SPRITESU_IMPLEMENTATION

#define SPRITESU_OVERWRITE
#define SPRITESU_PLUSMASK
#define SPRITESU_FX

#include <ArduboyFX.h>  
#include "src/ArduboyG.h"
#include "src/SpritesU.hpp"

#include "fxdata/fxdata.h"

ArduboyGBase_Config<ABG_Mode::L4_Triplane> arduboy;

void update() {
    
}

void loop() {

    FX::enableOLED();
    arduboy.waitForNextPlane(BLACK);
    FX::disableOLED();

    if (arduboy.needsUpdate()) update();

    uint16_t currentPlane = arduboy.currentPlane();

    SpritesU::drawOverwriteFX(0, 0, BG, currentPlane);    

}

void setup() {      

    arduboy.boot();
    arduboy.startGray();

    FX::begin(FX_DATA_PAGE, FX_SAVE_PAGE);

}
