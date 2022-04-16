#include <avr/io.h>
#include <util/delay.h>
// #include <avr/iom328p.h> // finds all imports so vscode doesnot complain

void stupid_blink(double s){
    // Set Data Direction register D pin 6 to write
    // DDRD = DDRD | 0x40;
    DDRD |= (1 << 6);
    DDRB |= (1 << 5);

    while(0){
        // set Port D pin 6 to high  0000 0001 ->  0100 0000
        PORTD |= (1 << PORTD6);
        PORTB |= (1 << PORTB5);
        _delay_ms(4000);
        PORTD &= ~(1 << PORTD6);
        PORTB &= ~(1 << PORTB5);
        _delay_ms(4000);
    }
}


int main(void)
{
    DDRD |= (1 << 6); // PIN 6 as output 
    DDRD &= ~(1 << 5); // PIN 5 AS INPUT
    DDRD &= ~(1 << 4); // PIN 4 AS INPUT

    DDRB |= (1 << 5);

    while(1){
        int press = (PIND & (1 << 4));
        if( press != 1 ){
            PORTB |= (1 << PORTB5);
            _delay_ms(10000);
        }else{
            PORTB &= ~(1 << PORTB5);
        }
    }

    return 0;
}
