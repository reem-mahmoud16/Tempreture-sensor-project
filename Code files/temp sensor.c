/*
 * temp_sensor.c
 *
 * Created: 9/17/2022 8:04:35 PM
 *  Author: HP.SXH08
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "LCD_config.h"
#include "ADC_driver.h"
#include "std_macros.h"

int main(void)
{
	LCD_vInit();
	ADC_vinit();
	unsigned char temp;
	LCD_vSend_string("temp now: ");
    while(1)
    {
		temp = ADC_u16Read() * 0.25;
		LCD_movecursor(1,11);
		LCD_vSend_char((temp/10)+48);
		LCD_vSend_char((temp%10)+48);
		LCD_vSend_char(0XDF);
		LCD_vSend_string("C");
    }
}