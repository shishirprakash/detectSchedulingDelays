#include <malloc.h>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char ** argv)
{
	long testIntervalInMicroseconds=1000; //1ms
	long thresholdForLogging=1000; //1ms
	struct timeval now;
	struct timespec sleepTime;
	sleepTime.tv_sec=0;
	sleepTime.tv_nsec=testIntervalInMicroseconds*1000l;
	unsigned long sleepStartTime, sleepEndTime, sleepDuration, excessSleepTime;
	while(1) {
		gettimeofday(&now, NULL);
		sleepStartTime = now.tv_sec * 1000000L + now.tv_usec;
		nanosleep(&sleepTime, NULL);
		gettimeofday(&now, NULL);
		sleepEndTime = now.tv_sec * 1000000L + now.tv_usec;
		sleepDuration = sleepEndTime - sleepStartTime;
		excessSleepTime = sleepDuration - testIntervalInMicroseconds;
		if(excessSleepTime < thresholdForLogging)
			continue;
		printf("microseconds slept: %ld target: %ld diff: %ld\n",
				sleepDuration,
				testIntervalInMicroseconds,
				excessSleepTime
		      );
	}
	return 0;
}
