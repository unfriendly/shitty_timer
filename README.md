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
./Timer 10 10 1000
```

# example_output
```
PS C:\Users\suici\Downloads\RDTSC Timer> ./Timer 10 10 1000
==============================================
[*] RDTSC Compare Total Diff: 4770
[*] RDTSC Locky Tricky AVG Diff: 16
[*] RDTSC VMExit AVG Diff: 1636
[*] CPU MHz: 2592
[*] Starting Timer
[*] Timer Delay in miliseconds: 10
==============================================
Counting To: 10
Locky Tricky Timer Diff AVG: 28581869
Locky Tricky Timer AVG Diff In Seconds: 0.011027
VMExit Timer Diff AVG: 28467147
VMExit Timer AVG Diff In Seconds: 0.010983
==============================================
Timing Deviation in Ticks: -114722
Timing Deviation in Seconds: -0.000044
==============================================
Timing Deviation in Ticks: 114722
Timing Deviation in Seconds: 0.000044
==============================================
Counting up at MHz: 1000
Counting up Host: 0
Counting up Guest: 0.000000
Host Clock: 35271942816142
Guest Clock: 35271942816094.172000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 1
Counting up Guest: 0.385562
Host Clock: 35271947571000
Guest Clock: 35271942816100.344000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 2
Counting up Guest: 0.771123
Host Clock: 35271949960538
Guest Clock: 35271942816106.516000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 3
Counting up Guest: 1.156685
Host Clock: 35271952480974
Guest Clock: 35271942816112.687000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 4
Counting up Guest: 1.542246
Host Clock: 35271955239424
Guest Clock: 35271942816118.859000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 5
Counting up Guest: 1.927808
Host Clock: 35271957697540
Guest Clock: 35271942816125.031000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 6
Counting up Guest: 2.313370
Host Clock: 35271960114432
Guest Clock: 35271942816131.203000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 7
Counting up Guest: 2.698931
Host Clock: 35271962495804
Guest Clock: 35271942816137.375000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 8
Counting up Guest: 3.084493
Host Clock: 35271964901774
Guest Clock: 35271942816143.547000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
Counting up Host: 9
Counting up Guest: 3.470054
Host Clock: 35271967446120
Guest Clock: 35271942816149.719000
Time Scale: 0.385562
Time Multiplier: 6.168986
Host Freq: 2593.619282
Guest Freq: 1000.000000
------------------------
```
