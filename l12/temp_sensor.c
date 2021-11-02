#include "temp_sensor.h"

bool verbose = false;

void generate_measurements(struct measurements *meas, char *start_date, int days) 
{
	char buff[11] = { 0 };
	struct tm t = { 0 };

	strptime(start_date, "%F", &t);

	srand(time(NULL));

    for (int i = 0; i < days; i++) {
    	mktime(&t);
    	meas[i].date = t;
    	meas[i].temp = rand() % 100 - 50;
	    strftime(buff, sizeof buff, "%F", &t);
	    t.tm_mday += 1;	
    }
}

int save_measurements(struct measurements *meas, const char *file, int count) 
{
	FILE *f;

    

	f = fopen(file, "w");
	if (!f) {
        return -1;
    }

    for (int i = 0; i < count; i++) {
    	fprintf(f, "%d;%d;%d;%d\n", meas[i].date.tm_mday, meas[i].date.tm_mon+1, meas[i].date.tm_year+1900, meas[i].temp);
        DBG("wrote measurement", meas[i]);
    }

    fclose(f);

    return 0;

}

