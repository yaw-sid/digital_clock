#ifndef CLOCK_H
#define CLOCK_H

#define MAX_SECONDS     59
#define MAX_MINUTE_ONES 9
#define MAX_MINUTE_TENS 5
#define MAX_HOUR_ONES   9
#define MAX_HOUR_ONES_2 3
#define MAX_HOUR_TENS   2

struct clock
{
    short seconds;

    short minute_ones;
    short minute_tens;
    
    short hour_ones;
    short hour_tens;
};

void increment_time(struct clock *clk)
{
    if (!(clk->seconds = clk->seconds == MAX_SECONDS ? 0 : clk->seconds + 1)) {

        if (!(clk->minute_ones = clk->minute_ones == MAX_MINUTE_ONES ? 0 : clk->minute_ones + 1)) {

            if (!(clk->minute_tens = clk->minute_tens == MAX_MINUTE_TENS ? 0 : clk->minute_tens + 1)) {

                if (clk->hour_tens != 2) {
                    if (!(clk->hour_ones = clk->hour_ones == MAX_HOUR_ONES ? 0 : clk->hour_ones + 1)) {
                        ++clk->hour_tens;
                    }
                }
                else if (!(clk->hour_ones = clk->hour_ones == MAX_HOUR_ONES_2 ? 0 : clk->hour_ones + 1)) {
                    clk->hour_tens = clk->hour_tens == MAX_HOUR_TENS ? 0 : clk->hour_tens + 1;
                }
            }
        } 
    }
}

#endif