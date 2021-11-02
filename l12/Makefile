APPNAME=main

SRCS+= main.c
SRCS+= temp_sensor.c

all:
	gcc $(SRCS) -o $(APPNAME)

debug:
	gcc $(SRCS) -o $(APPNAME) -DDEBUG

clean:
	rm -f $(APPNAME)
