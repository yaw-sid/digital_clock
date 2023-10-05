#include <stdio.h>
#include "clock.h"

int given_0_seconds_increment_time_sets_seconds_to_1(void)
{
    struct clock clk = { 0, 0, 0, 0, 0 };
    increment_time(&clk);
    return clk.seconds == 1;
}

int given_59_seconds_increment_time_sets_seconds_to_0(void)
{
    struct clock clk = { 59, 0, 0, 0, 0 };
    increment_time(&clk);
    return clk.seconds == 0;
}

int given_59_seconds_increment_time_increments_minutes_by_1(void)
{
    struct clock clk = { 59, 0, 0, 0, 0 };
    increment_time(&clk);
    return clk.minute_ones == 1;
}

int given_9_minutes_increment_time_sets_minutes_to_10(void)
{
    struct clock clk = { 59, 9, 0, 0, 0 };
    increment_time(&clk);
    return clk.minute_ones == 0 && clk.minute_tens == 1;
}

int given_59_minutes_increment_time_increments_hours_by_1(void)
{
    struct clock clk = { 59, 9, 5, 0, 0 };
    increment_time(&clk);
    return clk.hour_ones == 1;
}

int given_9_hours_increment_time_sets_hours_to_10(void)
{
    struct clock clk = { 59, 9, 5, 9, 0 };
    increment_time(&clk);
    return clk.hour_ones == 0 && clk.hour_tens == 1;
}

int given_23_hours_increment_time_resets_clock(void)
{
    struct clock clk = { 59, 9, 5, 3, 2 };
    increment_time(&clk);
    return clk.seconds == 0 && clk.minute_ones == 0 && clk.minute_tens == 0 &&
        clk.hour_ones == 0 && clk.hour_tens == 0;
}

int main(void)
{
    if (!given_0_seconds_increment_time_sets_seconds_to_1()) {
        printf("given_0_seconds_increment_time_sets_seconds_to_1 failed!\n");
        return 1;
    }
    if (!given_59_seconds_increment_time_sets_seconds_to_0()) {
        printf("given_59_seconds_increment_time_sets_seconds_to_0 failed!\n");
        return 1;
    }
    if (!given_59_seconds_increment_time_increments_minutes_by_1()) {
        printf("given_59_seconds_increment_time_increments_minutes_by_1 failed!\n");
        return 1;
    }
    if (!given_9_minutes_increment_time_sets_minutes_to_10()) {
        printf("given_9_minutes_increment_time_sets_minutes_to_10 failed!\n");
        return 1;
    }
    if (!given_59_minutes_increment_time_increments_hours_by_1()) {
        printf("given_59_minutes_increment_time_increments_hours_by_1 failed!\n");
        return 1;
    }
    if (!given_9_hours_increment_time_sets_hours_to_10()) {
        printf("given_9_hours_increment_time_sets_hours_to_10 failed!\n");
        return 1;
    }
    if (!given_23_hours_increment_time_resets_clock()) {
        printf("given_23_hours_increment_time_resets_clock failed!\n");
        return 1;
    }
    printf("all tests passed!\n");
    return 0;
}
