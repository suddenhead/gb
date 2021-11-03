APPNAME=tempstats

SRCS+= main.c
SRCS+= temp_functions.c

all:
	gcc $(SRCS) -o $(APPNAME)
	gcc generate_sample.c -o generate_sample

clean:
	rm -f $(APPNAME) generate_sample