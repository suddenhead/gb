#include "temp_sensor.h"

#define START_DATE "2021-01-01"
#define NUMBER_OF_DAYS 60

int main(void) 
{	
    struct measurements meas[NUMBER_OF_DAYS];

    generate_measurements(meas, START_DATE, NUMBER_OF_DAYS);

    save_measurements(meas, "m.csv", NUMBER_OF_DAYS);

	return 0;
}