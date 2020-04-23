![C/C++ CI](https://github.com/RawTechnique/shitty_timer/workflows/C/C++%20CI/badge.svg) 

# shitty_timer
External clock thingy to bypass timing checks
(Cross platform POC only ATM)

# build_command
gcc -coverage -O0 ./Timer.c -o Timer

# how_to_use

./Timer number_of_tests delay_in_ms guest_mhz

./Timer 100 10 1000
