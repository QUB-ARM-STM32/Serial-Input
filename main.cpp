#include "mbed.h"

// define the buffered serial to use
static BufferedSerial pc(USBTX, USBRX);

// define the pin outs
DigitalOut greenLED(LED1);

// buffer for our character
char* buffer = new char[1];

// main() runs in its own thread in the OS
int main()
{

    while (true) {
        pc.read(buffer, 1);


        if (*buffer == '1'){
            greenLED = 1;
            printf("\r\nGREEN LED ON\r\n");
        }
        else if (*buffer == '0'){
            greenLED = 0;
            printf("\r\nGREEN LED OFF\r\n");
        }
        else{
            printf("\r\nYou entered %c\r\n", *buffer);
        }


    }
}

