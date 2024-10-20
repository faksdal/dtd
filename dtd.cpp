/*
 * dtd.cpp
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 *      
 * dtd is a command line utility to convert between deg/min/sec and decimal degrees, and vice versa
 *  - expanded to include celcuis-fahrenheit conversion
 *  - restructuring into c++ classes
 */


#include <math.h>
#include <stdio.h>
#include <getopt.h>
#include "source/degtodec.h"


void printUsage(void);




int main(int argc, char *argv[])
{
	int		c, optionIndex, deg, min, sec;
	float	float_sec;
	float	input = 0L, output;
	char	*shortOptions = (char*)"";
	
	struct option longOptions[] = {
		{"degtodec", required_argument, NULL, 1},
		{"dectodeg", required_argument, NULL, 2},
		{"ctof", required_argument, NULL, 3},
		{"ftoc", required_argument, NULL, 4},
		{"atob", required_argument, NULL, 5},
		{0, 0, 0, 0}
	};
	
	printf("\ndtd, a command line converting utility by Jon Leithe!\n\n");
	if(argc < 2){
		printf("To few arguments\n");
		printUsage();
		return (2);
	}
	
	
	
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 1:		{
						dtd d(optarg, degToDec);
						printf("%d°%d'%d'' =  %f°\n", d.getDeg(), d.getMin(), d.getSec(), d.getDecDegrees());
						break;
						}
			case 2:		input = atof(optarg);
						deg = atoi(optarg);
						while(*optarg++ != '.');
						*optarg--;
						min = round(output = atof(optarg) * 60.0);
						//while(*optarg++ != '.');
						//*optarg--;
						printf("\n\n Output: %f", output);
						output -= min;
						printf("\n\n Output: %f\n", output);
						float_sec = (output*60);
						printf("%f° = %d°%d'%f''\n\n", input, deg, min, float_sec);
						break;
			case 3:		input = atof(optarg);
						output = ((input * 9/5) + 32);
						printf("%f°C = %f°F\n\n", input, output);
						break;
			case 4:		input = atof(optarg);
						output = ((input - 32) * 5/9);
						printf("%f°F = %f°C\n\n", input, output);
						break;
			case 5:		//invoceatob()
						break;
			default:	printf("No option set!\n");
						printUsage();
						break;
		}
	}
	

	return 0;
}



void printUsage(void)
{
	printf("Usage: dtd --degtodec <deg>.<min>.<sec>\n");
	printf("       dtd --dectodeg <decimaldegrees>\n");
	printf("       dtd --ctof <degrees Celcius>\n");
	printf("       dtd --ftoc <degrees Fahrenheit>\n");
}
