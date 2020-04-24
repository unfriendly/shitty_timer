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
[*] RDTSC Compare Total Diff: 8408
[*] RDTSC Locky Tricky AVG Diff: 17
[*] RDTSC VMExit AVG Diff: 2118
[*] CPU MHz: 2593
[*] Starting Timer
[*] Timer Delay in miliseconds: 10
==============================================
Counting To: 10
Locky Tricky Timer Diff AVG: 28512892
Locky Tricky Timer AVG Diff In Seconds: 0.010996
VMExit Timer Diff AVG: 28506302
VMExit Timer AVG Diff In Seconds: 0.010994
==============================================
Timing Deviation in Ticks: -6590
Timing Deviation in Seconds: -0.000003
==============================================
Timing Deviation in Ticks: 6590
Timing Deviation in Seconds: 0.000003
==============================================
Counting up at MHz: 1000
Counting up Host: 0
Counting up Guest: 0.000000
Host Clock: 102175939946000
Guest Clock: 102175939945948.560000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2962941456 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 1
Counting up Guest: 0.385619
Host Clock: 102175945685052
Guest Clock: 102175939945955.120000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2968680508 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 2
Counting up Guest: 0.771238
Host Clock: 102175949236568
Guest Clock: 102175939945961.690000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2972232024 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 3
Counting up Guest: 1.156858
Host Clock: 102175953000788
Guest Clock: 102175939945968.250000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2975996244 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 4
Counting up Guest: 1.542477
Host Clock: 102175956508328
Guest Clock: 102175939945974.810000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2979503784 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 5
Counting up Guest: 1.928096
Host Clock: 102175960654515
Guest Clock: 102175939945981.370000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2983649971 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 6
Counting up Guest: 2.313715
Host Clock: 102175969137614
Guest Clock: 102175939945987.940000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2992133070 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 7
Counting up Guest: 2.699334
Host Clock: 102175974839167
Guest Clock: 102175939945994.500000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=2997834623 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 8
Counting up Guest: 3.084954
Host Clock: 102175979410346
Guest Clock: 102175939946001.060000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=3002405802 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
Counting up Host: 9
Counting up Guest: 3.470573
Host Clock: 102175983189912
Guest Clock: 102175939946007.620000
Time Scale: 0.385619
Time Multiplier: 6.555526
Host Freq: 2593.231848
Guest Freq: 1000.000000
Host CPU Registers: EAX=3006185368 | EDX=23789
Leaf Check EAX=1 and EDX=2: Leaf=8589934593
Leaf Check EAX=1 and EDX=2: Math Check=4294967298.000000
------------------------
```
