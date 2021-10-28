#include <stdio.h>
#include "dirutils.h"


int main (int argc, char **argv)
{
	if (argc < 2) {
        printf("Enter path\n");
        return 0;
    }

    list_dir(argv[1]);
    return 0;
}