#include <xc.h>
#include <htc.h>
#include <math.h>

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
#define waiting PORTAbits.RA0
#define waiting1 PORTAbits.RA1

void portInit(void);
void larsonDisplay(void);

void portInit(void) {

    ANSELB = 0;
    ANSELD = 0;
    ANSELA = 0;
    TRISB = 0;
    TRISD = 255; 
    TRISA = 0;
    
    
}
void larsonDisplay(void){
    LATB = 1;//se coloca un 1 en el primer bit y 0 en los demas
    __delay_ms(300);
    
    //con el for se recorre el primer bit 7 veces hacia la 
    //posicion mas significativa
    for(int i = 0; i < 8; i++){
        LATB = LATB << 1;//se utiliza LATB pues se lee y escribe en la misma variable
        __delay_ms(300);//se espera 300ms entre cada corrimiento
    }
    LATB = 0b1000000;//se coloca un 1 en el bit 7 y 0 en los demas,
    //dandole un valor de 64 al LATB
    __delay_ms(300);
    
    //en este caso se recorre el bit hacia la posicion menos significativa
    for(int i = 0; i<7 ; i++){
        LATB = LATB >> 1;
        __delay_ms(300);
    }
}
void main(void) {
    portInit();//inicializacion de los puertos
    char Led;
    //Ciclo infinito
    while(1){
        Led = rand() % 8;//se escoge un numero entre 0 y 7
        PORTB = pow(2,Led);//se obtiene el numero decimal asociada al bit escogido
        __delay_ms(500);//se llama un delay de 500ms
        
        //se pregunta si las salidas en PORTB son iguales al negado de las entradas
        //para ver si coincide el boton presionado con el LED activo
        if(PORTB == (PORTD^255)){
            larsonDisplay();//se llama la funcion para el Knigth rider
        }
        else{
             __delay_ms(250);//de no coincidir se espera otros 250ms
             
             //se vuelve a hacer la verificacion
             if(PORTB == (PORTD^255)){
                larsonDisplay();
            }
             else{
                 continue;//de no cumplirse se vulve al inicio del ciclo
             }
        }
        
    }
    return;
}