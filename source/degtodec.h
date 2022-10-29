/*
 * degtodec.h
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 *	source definitions for convert deg/min/sec to decimaldegrees      
 *      
 */

#ifndef __degtodec_h__
#define __degtodec_h__

//float degtodec(char *inputString);

enum	mode {degToDec, decToDeg};

class dtd {
	int		deg, min, sec;
	float	decDegrees;
	
	char	*inputString;
	
public:
	dtd(char *input, mode m);
	
	
	int getDeg(void){return deg;}
	int getMin(void){return min;}
	int getSec(void){return sec;}
	
	float getDecDegrees(void){return decDegrees;}
	
};

#endif