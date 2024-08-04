#define ABG_IMPLEMENTATION
#define ABG_TIMER1
#define ABG_SYNC_PARK_ROW
#define SPRITESU_IMPLEMENTATION

#include <ArduboyFX.h>  
#include "src/ArduboyG.h"
#include "fxdata/fxdata.h"

#define SPRITESU_OVERWRITE
#define SPRITESU_PLUSMASK
#define SPRITESU_RECT
#define SPRITESU_FX

#include "src/SpritesU.hpp"

extern ArduboyGBase_Config<ABG_Mode::L4_Triplane> a;
decltype(a) a;




void update() {
    
    // uint8_t b = a.buttonsState();
    // Check for buttons/ move players etc.
    
}

void loop() {

    FX::enableOLED();
    a.waitForNextPlane(BLACK);
    FX::disableOLED();

    if (a.needsUpdate()) update();

    uint16_t currentPlane = a.currentPlane();

    SpritesU::drawOverwriteFX(0, 0, Images::BG, currentPlane);    

}

void setup() {      

    a.boot();
    abg_detail::send_cmds_prog<0xDB, 0x20>();
    a.startGray();

    FX::begin(FX_DATA_PAGE, FX_SAVE_PAGE);

}
