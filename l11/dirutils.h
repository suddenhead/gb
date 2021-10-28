#ifndef DIRUTILS_H
#define DIRUTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>

void list_dir(const char *dir_name);

#endif