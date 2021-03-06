
#include <16F84A.h>
#device ADC  = 8  // 8bits el ADC
#fuses HS         // HS por que utilizaremos un crystal de  20MHz
#use delay (clock=20M)
#define LCD_RS    PIN_D2
#define LCD_E     PIN_D3
#define LCD_DB4   PIN_D4
#define LCD_DB5   PIN_D5
#define LCD_DB6   PIN_D6
#define LCD_DB7   PIN_D7
#include <lcd1.c>

int8 valor,valor1;

char Leer_ADC(CHAR canal)
{
   CHAR dato;
   SET_ADC_CHANNEL (canal) ;
   delay_us (20) ;
   dato = READ_ADC () ;
   delay_us (10) ;
   RETURN dato;
}

void main()
{
   SETUP_ADC (ADC_CLOCK_INTERNAL);
   SETUP_ADC_PORTS (ALL_ANALOG) ;
   lcd_init () ;
   
   WHILE (TRUE)
   {
      valor = Leer_ADC (0);
      valor1 = Leer_ADC (1);
      lcd_gotoxy (1, 1) ;
      printf (lcd_putc, "AN0 = % 03u - AN1 = % 03u", valor, valor1);
      
   }

}

