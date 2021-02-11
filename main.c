#include <avr/io.h>
#include <util/delay.h>

#define LED 1

#define MIN_COUNTER 1
#define MAX_COUNTER 5

#define DELAY_100 100
#define DELAY_200 200
#define DELAY_300 300
#define DELAY_400 400
#define DELAY_500 500

void delay(short counter);
int main(void)
{
    // Set port B output 0 as output
    DDRB = _BV(LED);

    short counter = MIN_COUNTER;
    while (1)
    {
        // Toggle port b output 0
        PORTB ^= _BV(LED);
        delay(counter);

        PORTB ^= _BV(LED);
        delay(counter);

        // How do handle this without an `if`?
        if (++counter > MAX_COUNTER) counter = MIN_COUNTER;
    }
    return 0;
}

void delay(short counter)
{
        // Busy wait
        //_delay_ms(DELAY_MS);

        switch (counter)
        {
          case 1: _delay_ms(DELAY_100); break;
          case 2: _delay_ms(DELAY_200); break;
          case 3: _delay_ms(DELAY_300); break;
          case 4: _delay_ms(DELAY_400); break;
          case 5: _delay_ms(DELAY_500); break;
          default: break;
        }
}
