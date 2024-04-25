/*
 * TM1637.c
 *
 *  Created on: Apr 25, 2024
 *      Author: mm
 */


#include "main.h"
#include "TM1637.h"


//	INFORMATIONS:
//	-communications protocol is made by two-wire bus interface,
//	-it is not I2C protocol because we don't have slave address,
//	DATA FRAME:
//	-when CLK is in a high level and DIO changes from high to low START command is made,
//	-start means that sending transmission is begin,
//	-when CLK is in a high level and DIO changes form low to high STOP command is made,
//	-state change on DIO take place when CLK is low,
//	-read data take place when CLK is high, in that time DIO should not change,

//	ACTIONS:
//	-create functions to send start command, stop command, sending data, sending command,

//	DATA FRAME:
//	-default state: DIO - H, CLK - H,
//	-sending START - DIO - L, CLK - L,
//	-when CLK is low we have to set the DIO line to wanted state,
//	-after setting DIO we make CLK - H and CLK - L,
//	-we make it eight times for every bit,
//	-TM1637 sends acknowledge, we have to check state on DIO,
//	-we make a input mode on DIO line, read state,
//	-then we make CLK - H, then we also can read DIO state,
//	-after that we change mode of work DIO as output with low state, and CLK - L,
//	-sending STOP - CLK - H, DIO - H,
//	-we can skip reading acknowledge by make a CLK - H, CLK - L,

void TM1637_init(void);
void TM1637_START(void);
void TM1637_STOP(void);
void TM1637_write_data(const uint8_t data);
void TM1637_cmd(const uint8_t data);
void TM1637_write_display(const char sign_arr[]);


void TM1637_init(void)
{
	TM1637_write_display("@@@@");	//	Show some data on display,
	HAL_Delay(500);
	TM1637_cmd(NORMAL_AUTO_WRITE);	//	Selected working mode,
	TM1637_cmd(DISP_ON_8);			//	Selected display brightness,
	TM1637_write_display("????");	//	Show some data on display,
}

void TM1637_START(void)
{
	//	-sending start command,
	//	-we assume that state on two lines CLK and DIO is known, and it's a high state,

	//	Data line is going from high to low, CLK is on high state,
	HAL_GPIO_WritePin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);

	//	CLK line is going from high to low, DIO is on low state,
	HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
}

void TM1637_STOP(void)
{
	//	-sending stop command,
	//	-we assume that state on CLK line is low and we don't know how is the state on DIO,

	//	Setting low state on DIO pin,
	HAL_GPIO_WritePin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);

	//	CLK line is going from low to high, DIO is on low state,
	HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_SET);
	HAL_Delay(10);

	//	Data line is going from low to high, CLK is on high state,
	HAL_GPIO_WritePin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin, GPIO_PIN_SET);
	HAL_Delay(10);
}

void TM1637_write_data(const uint8_t data)
{
	//	-sending one data frame,
	//	-after that we can send another data or stop command,
	//	-at the output we have: CLK - L, DIO - unknown,

	//	Sending eight bits of data:
	for(uint8_t i=0; i<8; i++)
	{
		if( (data >> i) & 0x01)
		{
			HAL_GPIO_WritePin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin, GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin, GPIO_PIN_RESET);
		}
		HAL_Delay(1);

		HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_SET);
		HAL_Delay(1);

		HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
	}

	//	Receive acknowledge bit or skip that:
	//	Now we make a skip:
	HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_SET);
	HAL_Delay(10);

	HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
}

void TM1637_cmd(const uint8_t data)
{
	TM1637_START();
	TM1637_write_data(data);
	TM1637_STOP();
}

void TM1637_write_display(const char sign_arr[])
{
	//	-sending data to show on display,

	TM1637_START();

	TM1637_write_data(DISP_ADDR_1);
	for(uint8_t i=0; i<NUMBER_OF_DISPLAYS; i++)
	{
		TM1637_write_data(sign_arr[i]);
	}

	TM1637_STOP();
}





