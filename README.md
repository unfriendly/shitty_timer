![C/C++ CI](https://github.com/RawTechnique/shitty_timer/workflows/C/C++%20CI/badge.svg) 

# shitty_timer
External clock thingy to bypass timing checks
(Cross platform POC only ATM)

# build_command
```
gcc -coverage -O0 ./Timer.c -o Timer
```

# how_to_use
./Timer | number_of_tests | delay_in_ms | guest_mhz
```
./Timer 100 10 1000
```

# example_output
```
PS C:\Timer> ./Timer 100 10 1000
==============================================
[*] RDTSC Compare Total Diff: 4514
[*] RDTSC Locky Tricky AVG Diff: 17
[*] RDTSC VMExit AVG Diff: 1633
[*] CPU MHz: 2592
[*] Starting Timer
[*] Timer Delay in miliseconds: 10
==============================================
Counting To: 100
Locky Tricky Timer Diff AVG: 28484187
Locky Tricky Timer AVG Diff In Seconds: 0.010989
VMExit Timer Diff AVG: 28548910
VMExit Timer AVG Diff In Seconds: 0.011014
==============================================
Timing Deviation in Ticks: 64723
Timing Deviation in Seconds: 0.000025
==============================================
Timing Deviation in Ticks: -64723
Timing Deviation in Seconds: -0.000025
==============================================
Counting up at MHz: 1000
Counting up Host: 0
Counting up Guest: 0.000000
Host Clock: 33824189444860
Guest Clock: 33824189444804.555000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 1
Counting up Guest: 0.385575
Host Clock: 33824194098629
Guest Clock: 33824189444811.109000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 2
Counting up Guest: 0.771150
Host Clock: 33824196750428
Guest Clock: 33824189444817.664000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 3
Counting up Guest: 1.156725
Host Clock: 33824199144724
Guest Clock: 33824189444824.219000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 4
Counting up Guest: 1.542300
Host Clock: 33824201528918
Guest Clock: 33824189444830.773000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 5
Counting up Guest: 1.927875
Host Clock: 33824204060548
Guest Clock: 33824189444837.328000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 6
Counting up Guest: 2.313451
Host Clock: 33824207406848
Guest Clock: 33824189444843.883000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 7
Counting up Guest: 2.699026
Host Clock: 33824209668410
Guest Clock: 33824189444850.437000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 8
Counting up Guest: 3.084601
Host Clock: 33824211853692
Guest Clock: 33824189444856.992000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
Counting up Host: 9
Counting up Guest: 3.470176
Host Clock: 33824219110559
Guest Clock: 33824189444863.547000
Time Scale: 0.385575
Time Multiplier: 6.554777
Host Freq: 2593.528502
Guest Freq: 1000.000000
```
