/*
 * DateCheck.c
 *
 *  Created on: 15 Oct 2019
 *      Author: Arizo
 */


#include "DateCheck.h"

void input(unsigned char date[])
{
	int x = 0;
	unsigned char temp;

	printf("\nEnter a date according to YYYY:MM:DD   : ");

	while(((temp=getchar())!= '\n') && (x<=DATE_LENGTH))
	{
		if (isdigit(temp) || temp == ':')
		{
			date[x++] = temp;
		}
	}
}

Date splitInput(unsigned char date[]) {
	Date result;
	int counter = 0;
	char temp[DATE_LENGTH] = {0};

	while(counter < DATE_LENGTH && date[counter] != '\0')
	{
		if(date[counter] != ':') temp[strlen(temp)] = date[counter];
		else break;
		counter++;
	}
	result.year = atoi(temp);

	counter++;
	memset(temp, 0, DATE_LENGTH);
	while(counter < DATE_LENGTH && date[counter] != '\0')
	{
		if(date[counter] != ':') temp[strlen(temp)] = date[counter];
		else break;
		counter++;
	}
	result.month = atoi(temp);

	counter++;
	memset(temp, 0, DATE_LENGTH);
	while(counter < DATE_LENGTH && date[counter] != '\0')
	{
		if(date[counter] != ':') temp[strlen(temp)] = date[counter];
		else break;
		counter++;
	}
	result.day = atoi(temp);

	return result;
}

_Bool checkdate(Date enteredDate, _Bool *leapyear)
{
	_Bool result = true;
	*leapyear = false;

	if(enteredDate.year < 0 || enteredDate.year > 9999) result = false;
	else if(enteredDate.month < DATEMIN || enteredDate.month > MONTHMAX) result = false;
	else if (enteredDate.day < DATEMIN || enteredDate.day > DAYMAX) result = false;
	else if((enteredDate.month == APR || enteredDate.month == JUN || enteredDate.month == SEP || enteredDate.month == NOV) && enteredDate.day > DAYMAX2) result = false;
	else if(enteredDate.month == FEB)
	{
		if((enteredDate.year % 400 == 0) || (enteredDate.year % 4 == 0 && enteredDate.year % 100 != 0))
		{
			*leapyear = true;
		}
		if(enteredDate.day > FEBDAYMAXLEAP) result = false;
		else if((enteredDate.day == FEBDAYMAXLEAP) && !(*leapyear)) result = false;
	}

	return result;
}
