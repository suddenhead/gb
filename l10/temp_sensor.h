#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct measurements {
    struct tm date;
    int temp;
};

void generate_measurements(struct measurements *meas, char *start_date, int days);

int save_measurements(struct measurements *meas, const char *file, int count);


#endif