#include <avr/io.h>
#include <util/delay.h>
#include <avr/iom328p.h> 

    /*
    PD7 - red light output port
    PD5 - Green light output port
    PC0 - Analog in for temrature sensor
    */
void init_ports(){
    // Set pin 7 and 5 output pins
    DDRD |= 0xA0; 
    // Set pin 0 on PORTC to 0
    DDRC &= ~0x01;    
}

void test_lights(){
    int i = 0;
    while(1){
        if(i == 0){
            // Turn red light on, green light off
            PORTD |= (1 << 7);
            PORTD &= ~(1 << 5);
            i = 1;
        }else{
            // Turn red light off, green light on
            PORTD &= ~(1 << 7);
            PORTD |= (1 << 5);
            i = 0;
        }
        _delay_ms(1000);
    }
}

int main(int argc, char const *argv[])
{
    init_ports();
    test_lights();

    return 0;
}
