// Shitty Timer I'm working on
//
#include "Timer.h"

/* */
static inline unsigned long long
rdtsc_diff(void) {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    unsigned long long ret, ret2;
    unsigned eax, edx;
    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    ret = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);
    ret2 = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);

    /* Uncomment for debugging

    printf("- RDTSC1 Locky: %I64d\n", ret);

    printf("- RDTSC2 Locky: %I64d\n", ret2);

    printf("- RDTSC Locky Diff: %I64d\n", ret - ret2);

  */
    return (ret2 - ret);
}

/* */
static inline unsigned long long
rdtsc_diff_vmexit(void) {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    unsigned long long ret, ret2;
    unsigned int eax, edx;
    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
    __asm__ __volatile__("cpuid": /* no output */: "a"(0x00));
    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    ret = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);

    /* vm exit forced here. it uses: eax = 0; cpuid; */
    ret2 = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);

    /* Uncomment for debugging

    printf("- RDTSC1 VMExit: %I64d\n", ret);

    printf("- RDTSC2 VMExit: %I64d\n", ret2);

    printf("- RDTSC VMExit Diff: %I64d\n", ret - ret2);

  */
    return (ret2 - ret);
}

/* */
static inline unsigned long long
rdtsc_cpu_freq(void) {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    unsigned low_end, high_end;
    unsigned long long freq;
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    __asm__("rdtsc\r\n": "=d"(high_end), "=a"(low_end));
    freq = high_end;
    freq = (freq << 32) | low_end;
    return (freq);
}

/* */
static inline unsigned long long
rdtsc_current(void) {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    unsigned long long ret;
    unsigned eax, edx;
    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    ret = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);
    return (ret);
}

/* */
static inline unsigned long long
rdtsc_current_vmexit(void) {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    unsigned long long ret;
    unsigned eax, edx;
    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
    /* vm exit forced here. it uses: eax = 0; cpuid; */
    __asm__ __volatile__("cpuid": /* no output */: "a"(0x00));
    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    ret = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);
    return (ret);
}

/* */
int
main(int argc, char * argv[]) {
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    unsigned long long diff_compare;
    /* local start variable definition */
    int start_test;
    int tests_2run;
    unsigned long long rdtsc_1;
    unsigned long long vmexit_1;
    unsigned long long rdtsc_2;
    unsigned long long vmexit_2;
    unsigned long long avg_rdtsc;
    unsigned long long avg_vmexit;
    unsigned long long freq_start, freq_end;
    int cpu_freq;
    char * o;
    char * p;
    char * q;
    int num_1;
    int num_2;
    int num_3;
    long conv_1;
    long conv_2;
    long conv_3;
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

    diff_compare = rdtsc_diff_vmexit() - rdtsc_diff();
    start_test = 0;
    tests_2run = 10;
    rdtsc_1 = 0;
    vmexit_1 = 0;
    rdtsc_2 = 0;
    vmexit_2 = 0;
    avg_rdtsc = 0;
    avg_vmexit = 0;
    cpu_freq = 0;

    errno = 0;
    conv_1 = strtol(argv[1], & o, 10);
    conv_2 = strtol(argv[2], & p, 10);
    conv_3 = strtol(argv[3], & q, 10);

    /* Check for errors */
    if (errno != 0 || * o != '\0' || conv_1 > INT_MAX) {} else {
        num_1 = conv_1;
    }

    /* Check for errors */
    if (errno != 0 || * p != '\0' || conv_2 > INT_MAX) {} else {
        num_2 = conv_2;
    }

    /* Check for errors */
    if (errno != 0 || * q != '\0' || conv_3 > INT_MAX) {} else {
        num_3 = conv_3;
    }

    if (argc <= 2) {

        /* argc should be 2 for correct execution */
        printf("10 Test Default - 10 Second Delay - Please use (./rdtsc.exe tests_ammount sleep_value_ms) to configure options\n");
        while (start_test < tests_2run) {
            /*~~~~~~~~~~~~~~~~~~~~~~~*/
            unsigned long long rdtsc;
            unsigned long long vmexit;
            /*~~~~~~~~~~~~~~~~~~~~~~~*/

            rdtsc = rdtsc_diff();
            vmexit = rdtsc_diff_vmexit();

            rdtsc_1 = rdtsc;
            rdtsc_2 = rdtsc;
            vmexit_1 = vmexit;
            vmexit_2 = vmexit;
            if (avg_rdtsc == 0) {
                /*~~~~~~~~~~~~~~~~~~~~~~~~*/
                unsigned long long rdtsc_3;
                /*~~~~~~~~~~~~~~~~~~~~~~~~*/

                rdtsc_3 = rdtsc;
                avg_rdtsc = rdtsc_3;
                avg_rdtsc = (rdtsc_1 + rdtsc_2 + rdtsc_3) / 3;
            }

            avg_rdtsc = (avg_rdtsc + rdtsc_1 + rdtsc_2) / 3;
            if (avg_vmexit == 0) {
                /*~~~~~~~~~~~~~~~~~~~~~~~~~*/
                unsigned long long vmexit_3;
                /*~~~~~~~~~~~~~~~~~~~~~~~~~*/

                vmexit_3 = vmexit;

                avg_vmexit = vmexit_3;
                avg_vmexit = (vmexit_1 + vmexit_2 + vmexit_3) / 3;
            }

            avg_vmexit = (vmexit_1 + vmexit_2 + avg_vmexit) / 3;

            /* Uncomment for debugging

              printf("On Test: %d ^\n", start_test + 1);

              printf("--------------\n");

      */
            start_test++;
        }
    } else {
        while (start_test < num_1) {
            /*~~~~~~~~~~~~~~~~~~~~~~~*/
            unsigned long long rdtsc;
            unsigned long long vmexit;
            /*~~~~~~~~~~~~~~~~~~~~~~~*/

            rdtsc = rdtsc_diff();
            vmexit = rdtsc_diff_vmexit();

            rdtsc_1 = rdtsc;
            rdtsc_2 = rdtsc;
            vmexit_1 = vmexit;
            vmexit_2 = vmexit;
            if (avg_rdtsc == 0) {
                /*~~~~~~~~~~~~~~~~~~~~~~~~*/
                unsigned long long rdtsc_3;
                /*~~~~~~~~~~~~~~~~~~~~~~~~*/

                rdtsc_3 = rdtsc;
                avg_rdtsc = rdtsc_3;
                avg_rdtsc = (rdtsc_1 + rdtsc_2 + rdtsc_3) / 3;
            }

            avg_rdtsc = (avg_rdtsc + rdtsc_1 + rdtsc_2) / 3;
            if (avg_vmexit == 0) {
                /*~~~~~~~~~~~~~~~~~~~~~~~~~*/
                unsigned long long vmexit_3;
                /*~~~~~~~~~~~~~~~~~~~~~~~~~*/

                vmexit_3 = vmexit;

                avg_vmexit = vmexit_3;
                avg_vmexit = (vmexit_1 + vmexit_2 + vmexit_3) / 3;
            }

            avg_vmexit = (vmexit_1 + vmexit_2 + avg_vmexit) / 3;

            /* Uncomment for debugging

              printf("On Test: %d ^\n", start_test + 1);

              printf("--------------\n");

      */
            start_test++;
        }
    }

    /*Get CPU Frequency*/
    freq_start = rdtsc_cpu_freq();
    sleep(1);
    freq_end = rdtsc_cpu_freq();
    cpu_freq = (freq_end - freq_start) / 1000000;
    printf("==============================================\n");
    printf("[*] RDTSC Compare Total Diff: %I64d\n", diff_compare);
    printf("[*] RDTSC Locky Tricky AVG Diff: %I64d\n", avg_rdtsc);
    printf("[*] RDTSC VMExit AVG Diff: %I64d\n", avg_vmexit);
    printf("[*] Host CPU MHz: %u\n", cpu_freq);
    printf("[*] Starting Timer\n");
    printf("[*] Timer Delay in miliseconds: %d\n", num_2);
    printf("==============================================\n");
    if (cpu_freq == 0) {

        /* Do Nothing Here */
    } else {
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        int start_timer;
        unsigned long long count_1_time;
        unsigned long long count_2_time;
        unsigned long long count_time_diff;
        unsigned long long count_time_avg;
        double diff_seconds_avg;
        unsigned long long count_time_avg_vmexit;
        double diff_seconds_avg_vmexit;
        unsigned long long timing_deviation_ticks;
        double timing_deviation_seconds;
        double time_scale;
        double num_3_d;
        double freq_start_d;
        double freq_end_d;
        double cpu_freq_d;
        double ticks_counter;
        int ticks_host;
        double guest_clock;
        double time_multiplier;
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        start_timer = 0;
        count_1_time = 0;
        count_2_time = 0;
        count_time_diff = 0;
        count_time_avg = 0;
        diff_seconds_avg = 0;
        count_time_avg_vmexit = 0;
        diff_seconds_avg_vmexit = 0;
        timing_deviation_ticks = 0;
        timing_deviation_seconds = 0;

        if (argc <= 3) {
            while (start_timer < 10) {
                /*~~~~~~~~~~~~~~~~~~~~~*/
                double double_time_diff;
                double double_cpu_freq;
                double double_ticks;
                double diff_seconds;
                /*~~~~~~~~~~~~~~~~~~~~~*/

                count_1_time = rdtsc_current();
                Sleep(10000);
                count_2_time = rdtsc_current();
                count_time_diff = count_2_time - count_1_time;
                if (count_time_avg == 0) {
                    count_time_avg = (count_time_diff + (count_2_time - count_1_time)) / 2;
                } else {
                    count_time_avg = (count_time_diff + count_time_avg) / 2;
                }

                double_time_diff = count_time_diff;
                double_cpu_freq = cpu_freq;
                double_ticks = 1000000;
                diff_seconds = (double_time_diff / double_cpu_freq) / double_ticks;

                /* Uncomment for debugging

                printf("RDTSC Counting Diff: %I64d (%I64d-%I64d)\n", count_time_diff,count_2_time,count_1_time);

                printf("Counting Diff In Seconds: %lf\n", diff_seconds);

        */
                if (diff_seconds_avg == 0) {
                    diff_seconds_avg = diff_seconds;
                } else {
                    diff_seconds_avg = (diff_seconds + diff_seconds_avg) / 2;
                }

                start_timer++;
            }
        } else {
            while (start_timer < num_1) {
                /*~~~~~~~~~~~~~~~~~~~~~*/
                double double_time_diff;
                double double_cpu_freq;
                double double_ticks;
                double diff_seconds;
                /*~~~~~~~~~~~~~~~~~~~~~*/

                count_1_time = rdtsc_current();
                Sleep(num_2);
                count_2_time = rdtsc_current();
                count_time_diff = count_2_time - count_1_time;
                if (count_time_avg == 0) {
                    count_time_avg = (count_time_diff + (count_2_time - count_1_time)) / 2;
                } else {
                    count_time_avg = (count_time_diff + count_time_avg) / 2;
                }

                double_time_diff = count_time_diff;
                double_cpu_freq = cpu_freq;
                double_ticks = 1000000;
                diff_seconds = (double_time_diff / double_cpu_freq) / double_ticks;

                /* Uncomment for debugging

                printf("RDTSC Counting Diff: %I64d (%I64d-%I64d)\n", count_time_diff,count_2_time,count_1_time);

                printf("Counting Diff In Seconds: %lf\n", diff_seconds);

        */
                if (diff_seconds_avg == 0) {
                    diff_seconds_avg = diff_seconds;
                } else {
                    diff_seconds_avg = (diff_seconds + diff_seconds_avg) / 2;
                }

                start_timer++;
            }
        }

        /* Reset values for VMExit Timer */
        start_timer = 0;
        count_1_time = 0;
        count_2_time = 0;
        count_time_diff = 0;
        if (argc <= 3) {
            while (start_timer < 10) {
                /*~~~~~~~~~~~~~~~~~~~~~*/
                double double_time_diff;
                double double_cpu_freq;
                double double_ticks;
                double diff_seconds;
                /*~~~~~~~~~~~~~~~~~~~~~*/

                count_1_time = rdtsc_current_vmexit();
                Sleep(10000);
                count_2_time = rdtsc_current_vmexit();
                count_time_diff = count_2_time - count_1_time;
                if (count_time_avg_vmexit == 0) {
                    count_time_avg_vmexit = (count_time_diff + (count_2_time - count_1_time)) / 2;
                } else {
                    count_time_avg_vmexit = (count_time_diff + count_time_avg_vmexit) / 2;
                }

                double_time_diff = count_time_diff;
                double_cpu_freq = cpu_freq;
                double_ticks = 1000000;
                diff_seconds = (double_time_diff / double_cpu_freq) / double_ticks;

                /* Uncomment for debugging

                printf("RDTSC Counting Diff: %I64d (%I64d-%I64d)\n", count_time_diff,count_2_time,count_1_time);

                printf("Counting Diff In Seconds: %lf\n", diff_seconds);

        */
                if (diff_seconds_avg_vmexit == 0) {
                    diff_seconds_avg_vmexit = diff_seconds;
                } else {
                    diff_seconds_avg_vmexit = (diff_seconds + diff_seconds_avg_vmexit) / 2;
                }

                start_timer++;
            }
        } else {
            while (start_timer < num_1) {
                /*~~~~~~~~~~~~~~~~~~~~~*/
                double double_time_diff;
                double double_cpu_freq;
                double double_ticks;
                double diff_seconds;
                /*~~~~~~~~~~~~~~~~~~~~~*/

                count_1_time = rdtsc_current_vmexit();
                Sleep(num_2);
                count_2_time = rdtsc_current_vmexit();
                count_time_diff = count_2_time - count_1_time;
                if (count_time_avg_vmexit == 0) {
                    count_time_avg_vmexit = (count_time_diff + (count_2_time - count_1_time)) / 2;
                } else {
                    count_time_avg_vmexit = (count_time_diff + count_time_avg_vmexit) / 2;
                }

                double_time_diff = count_time_diff;
                double_cpu_freq = cpu_freq;
                double_ticks = 1000000;
                diff_seconds = (double_time_diff / double_cpu_freq) / double_ticks;

                /* Uncomment for debugging

                	printf("VM Exit RDTSC Counting Diff: %I64d (%I64d-%I64d)\n", count_time_diff,count_2_time,count_1_time);

                	printf("Counting Diff In Seconds: %lf\n", diff_seconds);

        */
                if (diff_seconds_avg_vmexit == 0) {
                    diff_seconds_avg_vmexit = diff_seconds;
                } else {
                    diff_seconds_avg_vmexit = (diff_seconds + diff_seconds_avg_vmexit) / 2;
                }

                start_timer++;
            }
        }

        timing_deviation_ticks = count_time_avg_vmexit - count_time_avg;
        timing_deviation_seconds = diff_seconds_avg_vmexit - diff_seconds_avg;
        printf("Counting To: %d\n", start_timer);
        printf("Locky Tricky Timer Diff AVG: %I64d\n", count_time_avg);
        printf("Locky Tricky Timer AVG Diff In Seconds: %lf\n", diff_seconds_avg);
        printf("VMExit Timer Diff AVG: %I64d\n", count_time_avg_vmexit);
        printf("VMExit Timer AVG Diff In Seconds: %lf\n", diff_seconds_avg_vmexit);
        printf("==============================================\n");
        printf("Timing Deviation in Ticks: %I64d\n", timing_deviation_ticks);
        printf("Timing Deviation in Seconds: %lf\n", timing_deviation_seconds);
        printf("==============================================\n");
        timing_deviation_ticks = count_time_avg - count_time_avg_vmexit;
        timing_deviation_seconds = diff_seconds_avg - diff_seconds_avg_vmexit;
        printf("Timing Deviation in Ticks: %I64d\n", timing_deviation_ticks);
        printf("Timing Deviation in Seconds: %lf\n", timing_deviation_seconds);
        printf("==============================================\n");
        printf("Counting up at Guest MHz: %d\n", num_3);
        time_scale = 0;
        num_3_d = num_3;
        freq_start_d = 0;
        freq_end_d = 0;
        cpu_freq_d = 0;

        freq_start_d = rdtsc_cpu_freq();
        sleep(1);
        freq_end_d = rdtsc_cpu_freq();
        cpu_freq_d = (freq_end_d - freq_start_d) / 1000000;
        time_scale = num_3_d / cpu_freq_d;
        ticks_counter = 0;
        ticks_host = 0;
        guest_clock = 0;
        time_multiplier = 0;

        time_multiplier = (avg_rdtsc * time_scale);
        if (argc <= 3) {

            /* for (;;) { */
            while (ticks_host < 10) {
                if (guest_clock == 0) {
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                    unsigned long long host_clock;
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

                    host_clock = rdtsc_current();
                    guest_clock = host_clock;
                } else {
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                    unsigned long long host_clock;
                    unsigned long long leaf_check;
                    double math_check;
                    unsigned eax, edx, lax, ldx;
                    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
                    unsigned long long eaxd, edxd;
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

                    lax = 1;
                    ldx = 2;
                    host_clock = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);
                    leaf_check = ((unsigned long long) lax) | (((unsigned long long) ldx) << 32);
                    guest_clock = (guest_clock + time_multiplier);
                    eaxd = ((unsigned long long) eax);
                    edxd = ((unsigned long long) edx);
                    math_check = (((unsigned long long) lax) << 32) | ((unsigned long long) ldx);
                    printf("Counting up Host: %d\n", ticks_host);
                    printf("Counting up Guest: %lf\n", ticks_counter);
                    printf("Host Clock: %I64d\n", host_clock);
                    printf("Guest Clock: %lf\n", guest_clock);
                    printf("Time Scale: %lf\n", time_scale);
                    printf("Time Multiplier: %lf\n", time_multiplier);
                    printf("Host Freq: %lf\n", cpu_freq_d);
                    printf("Guest Freq: %lf\n", num_3_d);
                    printf("Host CPU Registers: EAX=%I64d", eaxd);
                    printf(" | EDX=%I64d\n", edxd);
                    printf("Leaf Check EAX=1 and EDX=2: Leaf=%I64d\n", leaf_check);
                    printf("Leaf Check EAX=1 and EDX=2: Math Check=%lf\n", math_check);
                    printf("------------------------\n");
                    ticks_counter = ticks_counter + time_scale;
                    ticks_host++;
                }
            }
        } else {

            /* for (;;) { */
            while (ticks_host < num_1) {
                if (guest_clock == 0) {
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                    unsigned long long host_clock;
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

                    host_clock = rdtsc_current();

                    guest_clock = host_clock;
                } else {

                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                    unsigned long long host_clock;
                    unsigned long long leaf_check;
                    double math_check, math_check_no_shift;
                    unsigned eax, edx, lax, ldx;
                    __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
                    unsigned long long eaxd, edxd, edxdm, edxdmf, ldxd, ldxdm, ldxdmf, eaxd_change, edxd_change, eaxd_avg, edxd_avg;
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

                    eaxd_change = 0;
                    edxd_change = 0;
                    eaxd_avg = 0;
                    edxd_avg = 0;

                    lax = 1;
                    ldx = 2;
                    host_clock = ((unsigned long long) eax) | (((unsigned long long) edx) << 32);
                    leaf_check = ((unsigned long long) lax) | (((unsigned long long) ldx) << 32);
                    guest_clock = (guest_clock + time_multiplier);
                    eaxd = ((unsigned long long) eax);
                    edxd = ((unsigned long long) edx);
                    edxdm = ((unsigned long long) edx) << 32;
                    edxdmf = 32 << ((unsigned long long) edx);
                    math_check = (32 << ((unsigned long long) lax)) | ((unsigned long long) ldx);
                    math_check_no_shift = (((unsigned long long) lax)) | ((unsigned long long) ldx);
                    ldxd = ((unsigned long long) ldx);
                    ldxdm = ((unsigned long long) ldx) << 32;
                    ldxdmf = 32 << ((unsigned long long) ldx);
                    printf("Counting up Host: %d\n", ticks_host);
                    printf("Counting up Guest: %lf\n", ticks_counter);
                    printf("Host Clock: %I64d\n", host_clock);
                    printf("Guest Clock: %lf\n", guest_clock);
                    printf("Time Scale: %lf\n", time_scale);
                    printf("Time Multiplier: %lf\n", time_multiplier);
                    printf("Host Freq: %lf\n", cpu_freq_d);
                    printf("Guest Freq: %lf\n", num_3_d);
                    printf(" \n");
                    printf("Host CPU Leaf Check: EAX=%I64d", eaxd);
                    printf(" | EDX=%I64d\n", edxd);
                    printf("Host Leaf EDX Math: %I64d\n", edxdm);
                    printf("Host Leaf EDX Math Flip: %I64d\n", edxdmf);
                    printf(" \n");
                    printf("VM Leaf Check: EAX=1 | EDX=2: Leaf=%I64d\n", leaf_check);
                    printf("VM Leaf EDX Math Check: %lf\n", math_check);
                    printf("VM Leaf EDX No Shift Math Check: %lf\n", math_check_no_shift);
                    printf("VM Leaf EDX Math: %I64d\n", ldxdm);
                    printf("VM Leaf EDX Math Flip: %I64d\n", ldxdmf);
                    printf("------------------------\n");
                    ticks_counter = ticks_counter + time_scale;
                    ticks_host++;
                }
            }

            /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
            int find_leaf_avg;
            double eaxd_change, edxd_change, eaxd_avg, edxd_avg;
            /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

            eaxd_change = 0;
            edxd_change = 0;
            eaxd_avg = 0;
            edxd_avg = 0;

            while (find_leaf_avg < num_1) {
                /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                unsigned eax, edx, eax_old, edx_old;
                __asm__ __volatile__("rdtsc": "=a"(eax_old), "=d"(edx_old));
                Sleep(num_2);
                __asm__ __volatile__("rdtsc": "=a"(eax), "=d"(edx));
                double eaxd, edxd, eaxd_old, edxd_old;
                /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

                eaxd = ((unsigned long long) eax);
                edxd = ((unsigned long long) edx);
                eaxd_old = ((unsigned long long) eax_old);
                edxd_old = ((unsigned long long) edx_old);

                printf("EAXD: EAXD=%lf\n", eaxd);
                printf("EDXD: EDXD=%lf\n", edxd);
                printf("EAXD OLD: EAXD=%lf\n", eaxd_old);
                printf("EDXD OLD: EDXD=%lf\n", edxd_old);

                eaxd_change = eaxd - eaxd_old;
                if (eaxd_avg == 0) {
                    eaxd_avg = eaxd_change;
                }
                else {
                    eaxd_avg = (eaxd_avg + eaxd_change)/2;
                }

                edxd_change = edxd - edxd_old;
                if (edxd_avg == 0) {
                    edxd_avg = edxd_change;
                }
                else {
                    edxd_avg = (edxd_avg + edxd_change)/2;
                }

                find_leaf_avg++;
            }
            printf("EAX AVG: EAX=%lf\n", eaxd_avg);
            printf("EDX AVG: EDX=%lf\n", edxd_avg);
        }
    }

    return (0);
}
