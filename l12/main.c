#include <unistd.h>
#include <stdbool.h>
#include "temp_sensor.h"

#define START_DATE "2021-01-01"

extern char *optarg;
extern int optind, opterr, optopt;

int main(int argc, char *argv[]) 
{	
	int rez = 0;
	int number_of_days = 0;
	const char *filename = NULL;

	while ( (rez = getopt(argc,argv,"n:f:v")) != -1) {
		switch (rez) {
			case 'n': 
				number_of_days = atoi(optarg); 
				break;
			case 'f':
				filename = optarg;
				break;
			case 'v':
				verbose = true;
				break;
		}
	}

	struct measurements *meas = malloc(sizeof(struct measurements) * number_of_days);
    
    generate_measurements(meas, START_DATE, number_of_days);

    save_measurements(meas, filename, number_of_days);

    free(meas);

	return 0;
}