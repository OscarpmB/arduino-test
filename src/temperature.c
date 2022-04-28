#include <avr/io.h>
#include <util/delay.h>
// #include <avr/iom328p.h> // finds all imports so vscode doesnot complain

// void init_leds(){
//     DDRB = DDRB | (1 << DDB5);
//     DDRD = DDRD | (1 << DDB7); 
// }

/*
    TODO
    fix why code wont run with functions decleard above main
*/

int main(int argc, char const *argv[]){
    // init_ports();
    // test_lights();
    DDRB = DDRB | (1 << DDB5);
    DDRD = DDRD | (1 << DDB7); 
    // init_leds();
    while(1){
        DDRD = DDRD | (1 << DDB5); 
        PORTD = PORTD | (1 << PORT5);
        _delay_ms(1000);
        PORTD = PORTD & ~(1 << PORT5);
        _delay_ms(1000);
    }

    return 0;
}


