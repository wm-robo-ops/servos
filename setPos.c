#include <pigpiod_if2.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>

int main (int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "usage: setPos pan_deg tilt_deg\n");
		exit(1);
	}
	
	//Servos on pins 4 and 7
	int pan_servo = 4, tilt_servo = 7;

	long int pan, tilt;
	char *extra;
	if ((pan = strtol(argv[1], &extra, 10)) == 0)
	{
		if (extra == argv[0])
		{
			fprintf(stderr, "could not convert first arg to int\n");
			exit(1);
		}

		if ((pan == LONG_MIN || pan == LONG_MAX) && errno == ERANGE)
		{
			fprintf(stderr, "first arg value out of range\n");
			exit(1);
		}
	}

	if ((tilt = strtol(argv[2], &extra, 10)) == 0)
	{
		if (extra == argv[0])
		{
			fprintf(stderr, "could not convert second arg to int\n");
			exit(1);
		}

		if ((tilt == LONG_MIN || pan == LONG_MAX) && errno == ERANGE)
		{
			fprintf(stderr, "second arg value out of range\n");
			exit(1);
		}
	}

	int pi;
	if ((pi = pigpio_start(NULL, NULL)) <  0)
	{
		fprintf(stderr, "Could not initialize gpio's\n");
		exit(1);
	} 
	
	else
	{
		long int pan_ang = (2000*pan)/180 + 500;
		long int tilt_ang = (2000*tilt)/180 + 500;
		set_servo_pulsewidth(pi, pan_servo, pan_ang);
		set_servo_pulsewidth(pi, tilt_servo, tilt_ang);
		pigpio_stop(pi);
		return 0;
	}
}
