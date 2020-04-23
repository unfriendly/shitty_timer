![C/C++ CI](https://github.com/RawTechnique/shitty_timer/workflows/C/C++%20CI/badge.svg) 

# shitty_timer
External clock thingy to bypass timing checks
(Cross platform POC only ATM)

# build_command
gcc -coverage -O0 ./Timer.c -o Timer

# how_to_use
./Timer | number_of_tests | delay_in_ms | guest_mhz

./Timer 100 10 1000

# example_output
```
PS C:\Timer> ./Timer 100 10 1000
==============================================
[*] RDTSC Compare Total Diff: 5424
[*] RDTSC Locky Tricky AVG Diff: 16
[*] RDTSC VMExit AVG Diff: 1635
[*] CPU MHz: 2593
[*] Starting Timer
[*] Timer Delay in miliseconds: 10
==============================================
Counting To: 100
Locky Tricky Timer Diff AVG: 28575945
Locky Tricky Timer AVG Diff In Seconds: 0.011020
VMExit Timer Diff AVG: 28472147
VMExit Timer AVG Diff In Seconds: 0.010980
==============================================
Timing Deviation in Ticks: -103798
Timing Deviation in Seconds: -0.000040
==============================================
Timing Deviation in Ticks: 103798
Timing Deviation in Seconds: 0.000040
==============================================
Counting up at MHz: 1000
Counting up Host: 0
Counting up Guest: 0.000000
Host Clock: 27880660822542
Guest Clock: 0
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 0
Counting up Guest: 0.000000
Host Clock: 27880662486764
Guest Clock: 27880660822542
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 1
Counting up Guest: 0.385520
Host Clock: 27880664303456
Guest Clock: 27880660822583
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 2
Counting up Guest: 0.771041
Host Clock: 27880665976484
Guest Clock: 27880660822624
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 3
Counting up Guest: 1.156561
Host Clock: 27880667513382
Guest Clock: 27880660822665
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 4
Counting up Guest: 1.542082
Host Clock: 27880669029332
Guest Clock: 27880660822706
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 5
Counting up Guest: 1.927602
Host Clock: 27880670584910
Guest Clock: 27880660822747
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 6
Counting up Guest: 2.313123
Host Clock: 27880672226134
Guest Clock: 27880660822788
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 7
Counting up Guest: 2.698643
Host Clock: 27880673742114
Guest Clock: 27880660822829
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 8
Counting up Guest: 3.084164
Host Clock: 27880675269526
Guest Clock: 27880660822870
Time Scale: 0.385520
CPU Freq: 2593.896030
Counting up Host: 9
Counting up Guest: 3.469684
Host Clock: 27880676786152
Guest Clock: 27880660822911
Time Scale: 0.385520
CPU Freq: 2593.896030
```
