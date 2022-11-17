/// By Henry
#include "lib/include.h"

char *reading_string(char delimiter, int *ptr){
    char letter;
    static char array[50];
    int counter = 0;
    letter = readChar();  
    while (letter != delimiter){
        array[counter] = letter;
        letter = readChar();
        counter ++;
    }
    *ptr = strlen(array);
    return &array[0];
}

char *inverting_name(char *name, int length){
    static char inverted_name[50];
    int counter = 0;
    int idx = 0; 
    for (int i = length; i > 0; i--){
        inverted_name[counter] = *(name + (i -1));
        inverted_name[counter + 1] = idx + '0';
        idx ++; 
        counter = counter + 2;
    }
    return &inverted_name[0];
}

int main(void)
{
    uint16_t valor = 0;
    char c='5'; 
    //char b='a';
    // Pointers 
    // Sending Name to python
    char name[] = "Henry"; 
    char *p;  
    p = &name[0]; // First address of the array 
 
    Configurar_PLL(_20MHZ);  //Confiuracion de velocidad de reloj
    Configurar_UART0();//Yo FCLK 20MHZ Baudrate 9600

    //Experimento 1
    //  Configurar_UART1(); //Jorge,Alberto,Navarro,Saul,Fabela -fclk 25MHZ Baud-rate 57600
    //  Configurar_UART7(); //Angel,Fernanda,Sonia,Aleidis,Monse -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART4(); //Argelia,Roxana,Yesica,Vanesa,Christian,Abiu -fclk 10MHZ Baud-rate 4800
    //  Configurar_UART2(); //Brizet,Monse,Luis,Majo,Alonso -fclk 40MHZ Baud-rate 115200
    //  Configurar_UART3(); //Jesus,Yesica,Carlos,Dulce,Rodolfo,Leonardo -fclk 80MHZ Baud-rate 19200
    //  Configurar_UART2(); //Andrea,Avila,Pamela,Paulina -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART5(); //Hector,Cecilia,Carolina,Jozzafat -fclk 40MHZ Baud-rate 28800
    Configurar_GPIO();
    //UART_2_CONFIG(); 
    //printChar(c);
    //printChar(b);
    //printString(p);
    int length_of_array; 
    length_of_array = 0; 
    char *initial_name = reading_string(',', &length_of_array);
    //printString(initial_name);
    char *inverted_name = inverting_name(initial_name, length_of_array);
    printString(inverted_name);
    
    while(1)
    {
         c = readChar();
         switch(c)
         {
             case 'r':
                 //GPIODATA port F 662
                 printChar('a');
                 GPIOF->DATA = (1<<1);
                 break;
             case 'b':
                 //GPIODATA port F 662
                 printChar('b');
                 GPIOF->DATA = (1<<2);
                 break;
             case 'g':
                 //GPIODATA port F 662
                 printChar('c');
                 GPIOF->DATA = (1<<3);
                 break;
             case 'y':
                 //GPIODATA port F 662
                 printChar('d');
                 GPIOF->DATA = (1<<3) | (1<<2);
                 break;
             default:
                 printChar((char)valor);
                 GPIOF->DATA = (0<<1) | (0<<2) | (0<<3);
                 break;
         }
    }
}
