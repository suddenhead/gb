#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>


#include "temp_functions.h"

extern char *optarg;
extern int optind, opterr, optopt;

int main(int argc, char *argv[])
{
  	FILE *f;
  	struct tm t = { 0 };
  	struct measurements meas;
  	struct year_stat yearst[MAX_YEARS] = { 0 };
  	int rez = 0;
  	const char *filename = NULL;
  	int month_number = -1;

  	while ( (rez = getopt(argc,argv,"m:f:h")) != -1) {
		switch (rez) {
			case 'm': 
				month_number = atoi(optarg)-1;
				break;
			case 'f':
				filename = optarg;
				break;
			case 'h':
				print_help();
				return 0;
				break;
		}
	}

	if (!filename) {
		print_help();
		return 0;
	}

  	f = fopen(filename, "r");
  	if (!f) {
    	return -1;
	}

	int line = 1;
	char datestring[17];
	int temp;		
		
	int scans;
	while ((scans = fscanf(f, "%16s;%d", datestring, &temp)) != EOF) {
		if (scans != 2) {
			printf("(%d) Error parsing line %d: %s %d\n", scans, line, datestring, temp);
			continue;
		}

		strptime(datestring, "%Y;%m;%d;%H;%M", &t);
		meas.date = t;
		meas.temp = temp;

		/* check if current year already exists in statistics array
		   otherwise create it */
		if (!known_year(yearst, meas.date.tm_year+1900)) {
			add_year(yearst, meas.date.tm_year+1900);
		}

		// process current measurement
		add_stat_item(yearst, meas);

		line++;		
	}


	for (int i = 0; i < MAX_YEARS; i++) {
		if (yearst[i].year == 0) {
			break;
		}
		printf("===========YEAR %d===========\n", yearst[i].year);
		printf("\tMin\tMax\tAverage\n");
		for (int k = 0; k < 12; k++) {
			if (month_number == -1 || month_number == k) {
				print_month_stat(k, yearst[i]);
			}
		}
		printf("\n");
		print_year_stat(yearst[i]);
	}


	fclose(f);

	return 0;

}