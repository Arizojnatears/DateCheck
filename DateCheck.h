/*
 * DateCheck.h
 *
 *  Created on: 15 Oct 2019
 *      Author: Arizo
 */

#ifndef DATECHECK_H_
#define DATECHECK_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define DATE_LENGTH 10
#define MONTHMAX 12
#define DATEMIN 1
#define DAYMAX 31
#define DAYMAX2 30
#define FEBDAYMAXLEAP 29
#define JAN 1
#define	FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OKT 10
#define NOV 11
#define DEC 12

//A struct to store the different parts of the input
typedef struct {
	int year;
	int month;
	int day;
} Date;

void input(unsigned char date[]);
Date splitInput(unsigned char date[]);
_Bool checkdate(Date enteredDate, _Bool *leapyear);

#endif /* DATECHECK_H_ */
