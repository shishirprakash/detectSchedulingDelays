# detectSchedulingDelays
 tests for delays in waking up/scheduling a process.


a simpler C program that solely tests for delays in waking up/scheduling a process. The previous code was designed to test for some more complex CPU starvation scenarios, but I think what we have here is probably very simple and this simpler C code should get right to the problem and be easily readable by anyone.



To compile:

gcc -o detectSchedulingDelays detectSchedulingDelays.c



The program is very simple. All it does is take a timestamp, sleep for a fixed period of time, take another timestamp when it wakes up and compares the difference in the two timestamps with the amount of time it requested the system to sleep for. If the amount of time it was asleep is greater than the amount of time it requested to sleep by more than a certain amount then it will print a message like this:



microseconds slept: 103002 target: 1000 diff: 102002


In this example output, the program is stating it slept for 103002 microseconds, or 103ms, after it asked the system to put it to sleep for just 1000 microseconds, or 1 ms, and thus the program was asleep for 102002 microseconds, or 102ms, longer than it had requested to be asleep. This is an indication that the thread was runnable but it was not getting scheduled to run on a CPU for a long time.



You can customize the amount of time the program requests to sleep as well as the threshold at which it will log a message if it slept too long. At the top of the source file, you can change the values for these two lines:



long testIntervalInMicroseconds=1000; //1ms

long thresholdForLogging=1000; //1ms


These are the default values I put in the program, these values are such that the program will ask to go to sleep for 1ms, and if it ends up being asleep for more than 2ms (i.e. 1ms target + 1ms threshold) then it will log a message.



As I said, this is a much simpler program than the previous one I provided and should make the issue we are seeing very clear for anyone that's new coming in to this.



To run the test program, after running gcc to compile the source, you would just do:



./detectSchedulingDelays



The program does not require any arguments.

