/*
 * degtodec.cpp
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 *	source code for convert deg/min/sec to decimaldegrees      
 *      
 */

#include <stdio.h>
#include <stdlib.h>
#include "source/degtodec.h"


dtd::dtd(char *input, mode m)
{
	float	retVal;
	
	switch(m){
		case degToDec:	deg = atoi(input);
						while(*input++ != '-');
						min = atoi(input);
						while(*input++ != '-');
						//printf("Input: %s\n", input);
						sec = atof(input);
						//printf("Sec: %f\n", sec);
						decDegrees = deg + min/60.0 + sec/3600.0;
						break;
		case decToDeg:	break;
		default:		break;
	}
}
