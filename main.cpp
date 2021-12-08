#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "V:L:hv";

	const struct option long_options[] = {
		{"Value",	required_argument,	NULL,'V'},
		{"List",	required_argument,	NULL,'L'},
		{"help",	no_argument,		NULL,'h'},
		{"version",	no_argument,		NULL,'v'},
		{NULL,		0,					NULL, 0}
	};

	int parse, option_index = -1;

	/* array for checking only unique items */
	bool counter[4] = {false, false, false, false};

	while ((parse=getopt_long(argc, argv, 
							short_options, 
							long_options, 
							&option_index))!=-1){
		switch(parse){
			/* -V or --Value with required argument */
			case 'V': {
				if (!counter[0]){
					
					printf("Value = %s\n",optarg);
					counter[0] = true;
				}
				break;
			}
			/* -L or --List with required list of arguments */
			case 'L': {
				if (!counter[1]){
					
					printf("List = %s\n",optarg);
					counter[1] = true;
				}
				break;
			}
			/* -h or --help */
			case 'h': {
				if (!counter[2]){
					
					printf("Help. Allowed commands:\n\t-V / --Value\n\t-L / --List\n\t-h / --help\n\t-v / --version\n");
					counter[2] = true;
				}
				break;
			}
			/* -v or --version */
			case 'v': {
				if (!counter[3]){
					
					printf("Current program version is 1.0 .\n");
					counter[3] = true;
				}
				break;
			}
			/* other unknown options */
			case '?': default: {
				printf("Unknown option! Try again.\n");
				break;
			}
		}
		option_index = -1;
	}
	return 0;
}
