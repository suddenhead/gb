#include <stdio.h>
#include "temp_functions.h"



bool known_year(struct year_stat *yearst, int year) 
{
	for (int i = 0; i < MAX_YEARS; i++) {
		if (yearst[i].year == year) {
			return true;
		}
	}
	return false;
}

void add_year(struct year_stat *yearst, int year) 
{
	for (int i = 0; i < MAX_YEARS; i++) {
		if (yearst[i].year == 0) {
			yearst[i].year = year;
			break;
		}

	}
}

void add_stat_item(struct year_stat *yearst, struct measurements meas)
{
	for (int i = 0; i < MAX_YEARS; i++) {
		if (yearst[i].year == meas.date.tm_year+1900) {

			yearst[i].month[meas.date.tm_mon].meas_sum += meas.temp;
			yearst[i].month[meas.date.tm_mon].meas_count++;
			if (meas.temp < yearst[i].month[meas.date.tm_mon].min) {
				yearst[i].month[meas.date.tm_mon].min = meas.temp;
			} 
			if (meas.temp > yearst[i].month[meas.date.tm_mon].max) {
				yearst[i].month[meas.date.tm_mon].max = meas.temp;
			}

			yearst[i].meas_sum += meas.temp;
			yearst[i].meas_count++;
			if (meas.temp < yearst[i].min) {
				yearst[i].min = meas.temp;
			} 
			if (meas.temp > yearst[i].max) {
				yearst[i].max = meas.temp;
			}
			
			break;
		}
	}
}

const char *month_name(int mnum)
{
	switch (mnum) {
		case 0: return "Jan"; break;
		case 1: return "Feb"; break;
		case 2: return "Mar"; break;
		case 3: return "Apr"; break;
		case 4: return "May"; break;
		case 5: return "Jun"; break;
		case 6: return "Jul"; break;
		case 7: return "Aug"; break;
		case 8: return "Sep"; break;
		case 9: return "Oct"; break;
		case 10: return "Nov"; break;
		case 11: return "Dec"; break;
		default: return "undef"; break;
	}
}

void print_month_stat(int m, struct year_stat yearst)
{
	printf("%s\t%d\t%d\t%.2f\n", month_name(m), 
										yearst.month[m].min, 
										yearst.month[m].max,
										((float)yearst.month[m].meas_sum/(float)yearst.month[m].meas_count));
}

void print_year_stat(struct year_stat yearst)
{
	printf("Year\t%d\t%d\t%.2f\n", yearst.min, yearst.max, ((float)yearst.meas_sum/(float)yearst.meas_count));
	printf("===============================\n\n");
}

void print_help(void) {
	printf("Usage: tempstats [-h] [-m month] -f path\n\n");
	printf("-h\t this help\n");
	printf("-m\t display only this month (1-12)\n");
	printf("-f\t file to parse\n");

}