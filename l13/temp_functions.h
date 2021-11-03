#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdbool.h>
#include <time.h>

#define MAX_YEARS 10

struct measurements {
    struct tm date;
    int temp;
};

/* structures to hold aggregated statistics. Averages are
   calculated from sum and count at the end of processing */

struct month_stat {
	int meas_sum; 
	int meas_count;
	int min;
	int max;
};

struct year_stat {
	int year;
	int meas_sum; 
	int meas_count;
	int min;
	int max;
	struct month_stat month[12];
};

bool known_year(struct year_stat *yearst, int year);
void add_year(struct year_stat *yearst, int year);
void add_stat_item(struct year_stat *yearst, struct measurements meas);
const char *month_name(int mnum);
void print_month_stat(int m, struct year_stat yearst);
void print_year_stat(struct year_stat yearst);
void print_help(void);


#endif