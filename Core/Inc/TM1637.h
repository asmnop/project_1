/*
 * TM1637.h
 *
 *  Created on: Apr 25, 2024
 *      Author: mm
 */

#ifndef INC_TM1637_H_
#define INC_TM1637_H_


//	SETTING:
#define NUMBER_OF_DISPLAYS	4		//	Amount of displays to service,

//	DATA COMMAND SETTING:
#define NORMAL_AUTO_WRITE	0x40	//	Normal mode,	automatic address adding,	write data to display register,
#define TEST_AUTO_WRITE		0x48	//	Test mode,		automatic address adding,	write data to display register,
#define NORMAL_FIX_WRITE	0x44	//	Normal mode,	fix address,				write data to display register,
#define TEST_FIX_WRITE		0x4B	//	Test mode,		fix address,				write data to display register,

#define NORMAL_AUTO_READ	0x42	//	Normal mode,	automatic address adding,	read key scan data,
#define TEST_AUTO_READ		0x4A	//	Test mode,		automatic address adding,	read key scan data,
#define NORMAL_FIX_READ		0x46	//	Normal mode,	fix address,				read key scan data,
#define TEST_FIX_READ		0x4D	//	Test mode,		fix address,				read key scan data,


//	DISPLAY CONTROL:
#define	DISP_ON_1		0x88	//	Display on, brightness level: 1,
#define	DISP_ON_2		0x89	//	Display on, brightness level: 2,
#define	DISP_ON_3		0x8A	//	Display on, brightness level: 3,
#define	DISP_ON_4		0x8B	//	Display on, brightness level: 4,
#define	DISP_ON_5		0x8C	//	Display on, brightness level: 5,
#define	DISP_ON_6		0x8D	//	Display on, brightness level: 6,
#define	DISP_ON_7		0x8E	//	Display on, brightness level: 7,
#define	DISP_ON_8		0x8F	//	Display on, brightness level: 8,
#define	DISP_OFF		0x80	//	Display off,
#define	DISP_ON			0x88	//	Different name, Display on, brightness level: 1,


//	ADDRESS SETTING COMMAND:
#define	DISP_ADDR_1		0xC0	//	C0H,	data to first display,
#define	DISP_ADDR_2		0xC1	//	C1H,	data to second display,
#define	DISP_ADDR_3		0xC2	//	C2H,	data to third display,
#define	DISP_ADDR_4		0xC3	//	C3H,	data to forth display,
#define	DISP_ADDR_5		0xC4	//	C4H,	data to fifth display,
#define	DISP_ADDR_6		0xC5	//	C5H,	data to sixth display,
#define	START_ADDR		0xC0	//	C0H,	data to second display, different name,


void TM1637_init(void);


#endif /* INC_TM1637_H_ */
