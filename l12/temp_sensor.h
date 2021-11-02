#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


extern bool verbose;

struct measurements {
    struct tm date;
    int temp;
};

#if defined DEBUG
#define DBG(msg, m) if (verbose) { printf("%s: day %d month %d year %d temp %d\n", msg, m.date.tm_mday, m.date.tm_mon + 1, m.date.tm_year + 1900, m.temp); }
#else
#define DBG(msg, m) 
#endif


void generate_measurements(struct measurements *meas, char *start_date, int days);

int save_measurements(struct measurements *meas, const char *file, int count);


#endif