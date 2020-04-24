![C/C++ CI](https://github.com/RawTechnique/shitty_timer/workflows/C/C++%20CI/badge.svg) 
[![codecov](https://codecov.io/gh/RawTechnique/shitty_timer/branch/master/graph/badge.svg)](https://codecov.io/gh/RawTechnique/shitty_timer)

# shitty_timer
External clock thingy to bypass timing checks
(Cross platform POC only ATM)

Right now its 99.99987% accurate for 10 calls, at 10ms, and counting at 1000MHz, which means by the time 1 second passes it would be 99.99857% accurate (each second is minus 0.0013% accuracy), so it drifts a lot)

# build_command
```
gcc -coverage -O0 ./Timer.c -o Timer
```

# how_to_use
./Timer | number_of_tests | delay_in_ms | guest_mhz
```
./Timer 10 10 1000
```

# example_output
```
PS C:\Timer> ./Timer 10 10 1000
==============================================
[*] RDTSC Compare Total Diff: 7466
[*] RDTSC Locky Tricky AVG Diff: 16
[*] RDTSC VMExit AVG Diff: 1635
[*] Host CPU MHz: 2594
[*] Starting Timer
[*] Timer Delay in miliseconds: 10
==============================================
Counting To: 10
Locky Tricky Timer Diff AVG: 28513285
Locky Tricky Timer AVG Diff In Seconds: 0.010992
VMExit Timer Diff AVG: 28510335
VMExit Timer AVG Diff In Seconds: 0.010991
==============================================
Timing Deviation in Ticks: -2950
Timing Deviation in Seconds: -0.000001
==============================================
Timing Deviation in Ticks: 2950
Timing Deviation in Seconds: 0.000001
==============================================
Counting up at Guest MHz: 1000
Counting up Host: 0
Counting up Guest: 0.000000
Host Clock: 103034220953184
Guest Clock: 103034220953138.170000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2250489440 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 1
Counting up Guest: 0.385682
Host Clock: 103034226713160
Guest Clock: 103034220953144.340000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2256249416 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 2
Counting up Guest: 0.771363
Host Clock: 103034230226274
Guest Clock: 103034220953150.520000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2259762530 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 3
Counting up Guest: 1.157045
Host Clock: 103034234683608
Guest Clock: 103034220953156.690000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2264219864 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 4
Counting up Guest: 1.542727
Host Clock: 103034238287260
Guest Clock: 103034220953162.860000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2267823516 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 5
Counting up Guest: 1.928409
Host Clock: 103034241989142
Guest Clock: 103034220953169.030000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2271525398 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 6
Counting up Guest: 2.314090
Host Clock: 103034251401040
Guest Clock: 103034220953175.200000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2280937296 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 7
Counting up Guest: 2.699772
Host Clock: 103034256091142
Guest Clock: 103034220953181.370000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2285627398 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 8
Counting up Guest: 3.085454
Host Clock: 103034260802568
Guest Clock: 103034220953187.550000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2290338824 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 9
Counting up Guest: 3.471136
Host Clock: 103034264501857
Guest Clock: 103034220953193.720000
Time Scale: 0.385682
Time Multiplier: 6.170908
Host Freq: 2592.811378
Guest Freq: 1000.000000
Host CPU Registers: EAX=2294038113 | EDX=23989
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
```
