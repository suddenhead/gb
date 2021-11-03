#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"

#define START_DATE "2021-01-01"
#define NUM_YEARS 3
#define TRASH_CHANCE 0 

int randRange(int lower, int upper)
{
	return (rand() % (upper - lower + 1)) + lower;
}

int rolldice(int percentage) {
	return (rand() % 100) < percentage ? true : false;
}


int main(void)
{
	FILE *f;
	char buff[11] = { 0 };
	struct tm t = { 0 };
	struct measurements meas;

	strptime(START_DATE, "%F", &t);

	srand(time(0));

	f = fopen("sample.csv", "w");
	for (int i = 0; i < NUM_YEARS*365*24*60; i++) {
		if (rolldice(TRASH_CHANCE)) {
			fprintf(f, "trash\n");
			t.tm_min += 1;	
			continue;
		}
    	mktime(&t);
    	meas.date = t;

    	// mins and maxs for Moscow (from Wikipedia)
    	switch (meas.date.tm_mon) {
    		case 0: meas.temp = randRange(-42, 9); break;
    		case 1: meas.temp = randRange(-38, 8); break;
    		case 2: meas.temp = randRange(-32, 20); break;
    		case 3: meas.temp = randRange(-21, 30); break;
    		case 4: meas.temp = randRange(-8, 33); break;
    		case 5: meas.temp = randRange(2, 35); break;
    		case 6: meas.temp = randRange(1, 38); break;
    		case 7: meas.temp = randRange(-1, 33); break;
    		case 8: meas.temp = randRange(-8, 32); break;
    		case 9: meas.temp = randRange(-20, 24); break;
    		case 10: meas.temp = randRange(-32, 16); break;
    		case 11: meas.temp = randRange(-38, 10); break;
    		default: meas.temp = randRange(-99, 99); break;
    	}
	    strftime(buff, sizeof buff, "%F", &t);
	    fprintf(f, "%d;%02d;%02d;%02d;%02d;%d\n", meas.date.tm_year+1900,
	    							meas.date.tm_mon+1, 
	    							meas.date.tm_mday,
	    							meas.date.tm_hour,
	    							meas.date.tm_min,
	    							meas.temp);
	    t.tm_min += 1;	
	    
    }
    fclose(f);

    return 0;
}