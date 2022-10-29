/*
 * dtd.cpp
 *
 *  Created on: 28 Oct 2022
 *      Author: jole
 */

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>



int main(int argc, char *argv[])
{
	int		c, optionIndex, deg, min, sec;
	float	decdeg = 0L, f;
	char	*shortOptions = (char*)"";
	
	struct option longOptions[] = {
		{"degtodec", required_argument, NULL, 1},
		{"dectodeg", required_argument, NULL, 2},
		{0, 0, 0, 0}
	};
	
	printf("\ndtd, a command line converting utility from Jon Leithe!\n\n");
	if(argc < 2){
		printf("\nUsage: dtd --degtodec <deg>.<min>.<sec>\n");
		printf("Usage: dtd --dectodeg <decimaldegrees>\n\n");
		return (2);
	}
	
	
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 1:		deg = atoi(optarg);
						while(*optarg++ != '.');
						min = atoi(optarg);
						while(*optarg++ != '.');
						sec = atoi(optarg);
						decdeg = deg + min/60.0 + sec/3600.0;
						printf("%d°%d'%d'' = %f°\n", deg, min, sec, decdeg);
						break;
			case 2:		decdeg = atof(optarg);
						deg = atoi(optarg);
						while(*optarg++ != '.');
						*optarg--;
						min = round(f = atof(optarg) * 60.0);
						//while(*optarg++ != '.');
						//*optarg--;
						f -= min;
						sec = round(f * 60);
						printf("%f° = %d°%d'%d''\n", decdeg, deg, min, sec);
						break;
			default:	printf("No option set!\n");
						printf("Usage: dtd --degtodec <deg>.<min>.<sec>\n");
						printf("Usage: dtd --dectodeg <decimaldegrees>\n");
						break;
		}
	}
	

	return 0;
}
