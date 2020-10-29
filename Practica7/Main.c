#include <xc.h>
#include <htc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//::::::::    PIC18F45K50 CONFIGURATION BIT SETtINGS    ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::----:----+
// CONFIG1L                                                                                                                                  |
#pragma config PLLSEL = PLL4X   // PLL Selection (4x clock multiplier)                                                                       |
#pragma config CFGPLLEN = OFF   // PLL Enable Configuration bit (PLL Disabled (firmware controlled))                                         |
#pragma config CPUDIV = NOCLKDIV// CPU System Clock Postscaler (CPU uses system clock (no divide))                                           |
#pragma config LS48MHZ = SYS24X4// Low Speed USB mode with 48 MHz system clock (System clock at 24 MHz, USB clock divider is set to 4)

// CONFIG1H
#pragma config FOSC = INTOSCIO  // Oscillator Selection (Internal oscillator)
#pragma config PCLKEN = ON      // Primary Oscillator Shutdown (Primary oscillator enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config nPWRTEN = OFF    // Power-up Timer Enable (Power up timer disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable (BOR enabled in hardware (SBOREN is ignored))
#pragma config BORV = 190       // Brown-out Reset Voltage (BOR set to 1.9V nominal)
#pragma config nLPBOR = OFF     // Low-Power Brown-out Reset (Low-Power Brown-out Reset disabled)

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bits (WDT disabled in hardware (SWDTEN ignored))
#pragma config WDTPS = 32768    // Watchdog Timer Postscaler (1:32768)

// CONFIG3H
#pragma config CCP2MX = RC1     // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
#pragma config T3CMX = RC0      // Timer3 Clock Input MUX bit (T3CKI function is on RC0)
#pragma config SDOMX = RB3      // SDO Output MUX bit (SDO function is on RB3)
#pragma config MCLRE = ON       // Master Clear Reset Pin Enable (MCLR pin enabled; RE3 input disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port Enable (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled)

// CONFIG5L
#pragma config CP0 = OFF        // Block 0 Code Protect (Block 0 is not code-protected)
#pragma config CP1 = OFF        // Block 1 Code Protect (Block 1 is not code-protected)
#pragma config CP2 = OFF        // Block 2 Code Protect (Block 2 is not code-protected)
#pragma config CP3 = OFF        // Block 3 Code Protect (Block 3 is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protect (Boot block is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protect (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Block 0 Write Protect (Block 0 (0800-1FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Block 1 Write Protect (Block 1 (2000-3FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Block 2 Write Protect (Block 2 (04000-5FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Block 3 Write Protect (Block 3 (06000-7FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Registers Write Protect (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protect (Boot block (0000-7FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protect (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Block 0 Table Read Protect (Block 0 is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Block 1 Table Read Protect (Block 1 is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Block 2 Table Read Protect (Block 2 is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Block 3 Table Read Protect (Block 3 is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protect (Boot block is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
//                                                                                                                                           |
//                                                                                                                            |
//........    PIC18F45K50 configuration bit settings 

#define _XTAL_FREQ 1000000
#define LedInt1 PORTAbits.RA0
#define LedInt2 PORTAbits.RA1
#define S1 PORTDbits.RD0
#define S2 PORTDbits.RD1
#define S3 PORTDbits.RD2
#define S4 PORTDbits.RD3


void portInit(void);


void portInit(void) {
    //Configurando todos los puertos utilizados como digitales
    ANSELB = 0;
    ANSELD = 0;
    ANSELA = 0;
    //Configuracion de Salidas
    TRISA = 0;//indicadores para el estado de la columna
    TRISB = 0;//LEDs para representacion de la tecla presionada
    //Configuracion de entradas
    TRISD = 0b00001111; 
    
    
    
}

void main(void) {
    portInit();//Inicializando los puertos
    //Declarando variables
    char int0 = 0, ren, reg = 0;
    char val;
    //inicializando un arreglo de dos dimensiones que contenga la matriz 4x4 del teclado
    int Keys[4][4] = {{1,4,7,0xF},{2,5,8,0,},{3,6,9,0xE},{0xA,0xB,0xC,0xD}};
    //Ciclo infinito
    while(1){
        if(S1 == 0 && PORTD < 16){//si se detecta un 0 en alguna de las entradas
                                  //mientras que PORTD = 0b0000XXXX,encontrando la columna
            LATD = 16; // se prende el bit 4 de LATD
            
            for(int i = 0;i<4;i++){//se utiliza un para recorrer ese bit
                //los bits en el corrimiento estan asociados a las salidas
                //conectadas a los renglones, entonces si al energizar un
                //renglon la entrada asociada a la columna "S1" cambia 1
                //significa que en esa posicion se esta presionando un boton
        
                if(S1 == 1 && PORTD>=16){
                    ren = i;//se almacena el renglon
                    //se indica la columna acutal con 2 leds
                    LedInt1 = 0;
                    LedInt2 = 0;
                    val = Keys[0][ren];//se obtiene el valor a representar de la matriz
                    
                    LATB = LATB<<4;//Se corre cuatro bist el valor actual de PORTB
                    LATB = LATB | val;//se hace un OR con el valor de la matriz,
                    //para incluirlo en los 4 bits menos significativos, puesto que
                    //todos las teclas son numeros d 4 bits

                    LATD = 0; //se apagan todas las salidas respectivas a los renglones
                    //regresando S1 a 0
                    while(S1==0){// se espera a que la entrada asociada a la columna vuleva 
                        //a ser 1, significando que se ha dejado de presionar el boton
                        LedInt2 = LedInt2^255;//parapadeo de un led
                    }
                    LedInt2 = 0;   
                }
                LATD = LATD<<1;//corrimiento de un Bit
            }
            
        }
        if(S2 == 0 && PORTD < 16){
            LATD = 16;
            for(int i = 0;i<4;i++){
                if(S2 == 1 && PORTD>=16){
                    ren = i;
                    LedInt1 = 0;
                    LedInt2 = 1;
                    val = Keys[1][ren];
                    if(reg == 0){
                        LATB = LATB<<4;
                        LATB = LATB | val;   
                    }
                    if(reg == 1){
                        LATB = LATB<<4;
                        LATB = LATB | val;
                    }
                    reg = 1;
                    //cbit = 255 - pow(2,col + 3);
                    //LATD = LATD & cbit;
                    LATD = 0;
                    while(S2==0){
                        LedInt2 = LedInt2^255;
                    }
                    LedInt2 = 1;
                   
                   
                    
                }
                LATD = LATD<<1;
            }
        
        }
        if(S3 == 0 && PORTD < 16){
            LATD = 16;
            for(int i = 0;i<4;i++){
                if(S3 == 1 && PORTD>=16){
                    ren = i;
                    LedInt1 = 1;
                    LedInt2 = 0;
                    val = Keys[2][ren];
                    if(reg == 0){
                        LATB = LATB<<4;
                        LATB = LATB | val;   
                    }
                    if(reg == 1){
                        LATB = LATB<<4;
                        LATB = LATB | val;
                    }
                    reg = 1;
                    LATD = 0;
                    while(S3==0){
                        LedInt2 = LedInt2^255;
                    }
                    LedInt2 = 0;
                }
                LATD = LATD<<1;
            }
        
        }
        if(S4 == 0 && PORTD < 16){
            LATD = 16;
            for(int i = 0;i<4;i++){
                if(S4 == 1 && PORTD>=16){
                    ren = i;
                    LedInt1 = 1;
                    LedInt2 = 1;
                    val = Keys[3][ren];
                    if(reg == 0){
                        LATB = LATB<<4;
                        LATB = LATB | val;   
                    }
                    if(reg == 1){
                        LATB = LATB<<4;
                        LATB = LATB | val;
                    }
                    reg = 1;
                    //cbit = 255 - pow(2,col + 3);
                    //LATD = LATD & cbit;
                    LATD = 0;
                    while(S4==0){
                        LedInt2 = LedInt2^255;
                    }
                    LedInt2 = 1;
                }
                LATD = LATD<<1;
            }
        
        }
    return;
    }
}

