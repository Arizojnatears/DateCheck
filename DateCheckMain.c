/*
 * DateCheckMain.c
 *
 *  Created on: 15 Oct 2019
 *      Author: Arizo
 */

#include "DateCheck.h"

//String for date
unsigned char date[DATE_LENGTH + 1] = {0}, temp;
//A boolean used to set an input to OK, or not OK
_Bool errorCheck = false;
//A boolean used for if the entered year is a leap year
_Bool leapyear = false;


int main()
{
	setbuf(stdout, NULL);
//Used to ask for a new input if the input is not OK
	_Bool restart = true;
//While no OK input has been made..
	while(restart == true)
	{
//Call a function asking the user to make an input
	input(date);
//Call a function to split the input into three different parts
	Date temp = splitInput(date);
//Call a function to check if the input is OK, checking for leap year in the process
	errorCheck = checkdate(temp, &leapyear);
//If input is OK, print the input, if not OK print "INVALID DATE"
	printf("\n%s\n", errorCheck ? printf("%s", date) : "INVALID DATE");
	}

	return 0;
}
