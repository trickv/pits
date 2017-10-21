#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>   	// Standard input/output definitions
#include <string.h>  	// String function definitions
#include <unistd.h>  	// UNIX standard function definitions
#include <fcntl.h>   	// File control definitions
#include <errno.h>   	// Error number definitions
#include <termios.h> 	// POSIX terminal control definitions
#include <stdint.h>
#include <stdlib.h>
#include <dirent.h>
#include <math.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <sys/statvfs.h>
#include <inttypes.h>

#include "gps.h"
#include "DS18B20.h"
#include "adc.h"
#include "adc_i2c.h"
//#include "misc.h"
#include "snapper.h"
#include "led.h"
#include "bmp085.h"
#include "bme280.h"
#include "aprs.h"
#include "lora.h"
#include "pipe.h"
#include "prediction.h"
#include "log.h"
#ifdef EXTRAS_PRESENT
#	include "ex_tracker.h"
#endif	
//#include "gps.c"


int main(void)
{
    pthread_t GPSThread;
	struct TGPS GPS;
	memset(&GPS, 0, sizeof(struct TGPS));

	if (pthread_create(&GPSThread, NULL, GPSLoop, &GPS))
	{
		fprintf(stderr, "Error creating GPS thread\n");
		return 1;
	}
}
