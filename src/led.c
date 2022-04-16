#include <avr/io.h>
#include <util/delay.h>
//#include <avr/iom328p.h> // finds all imports so vscode doesnot complain



int main(void)
{
    // Set Data Direction register D pin 6 to write
    // DDRD = DDRD | 0x40;
    DDRD |= (1 << 6);
    DDRB |= (1 << 5);

    while(1){
        // set Port D pin 6 to high  0000 0001 ->  0100 0000
        PORTD |= (1 << PORTD6);
        PORTB |= (1 << PORTB5);
        _delay_ms(4000);
        PORTD &= ~(1 << PORTD6);
        PORTB &= ~(1 << PORTB5);
        _delay_ms(4000);
    }
    return 0;
}
