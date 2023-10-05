#include "msp430g2553.h"
#include "clock.h"

#define TIMERA0_COUNT   32767
#define TIMERA1_COUNT   255

static struct clock clk = { 0, 0, 0, 0, 0 };

unsigned short active_display = BIT3;

int main(void)
{
    // disable watchdog timer
    WDTCTL = WDTPW | WDTHOLD;

    // setup Timer A as real-time clock
    BCSCTL1 |= DIVA_0;
    BCSCTL3 |= XCAP_3 | LFXT1S_0;

    // enable timer A0 interrupt
    CCTL0 = CCIE;
    CCR0 = TIMERA0_COUNT;
    TACTL = TASSEL_1 | MC_1;

    // enable timer A1 interrupt
    TACCTL1 = CCIE;
    TACCR1 = TIMERA1_COUNT;

    // configure P1.3-P1.6 as output
    // these control the BCD driver and are active high
    P1DIR |= BIT3 + BIT4 + BIT5 + BIT6;

    // configure P2.0-P2.3 as output
    // these control the digit select and are active low
    P2DIR |= BIT0 + BIT1 + BIT2 + BIT3;

    _bis_SR_register(LPM0_bits + GIE);
}

void __interrupt_vec(TIMER0_A0_VECTOR) timer_a0_isr(void)
{
    increment_time(&clk);
}

void __interrupt_vec(TIMER0_A1_VECTOR) timer_a1_isr(void)
{
    // clear interrupt flag
    TACCTL1 &= ~CCIFG;

    switch (active_display)
    {
    case BIT3:
        P1OUT = clk.hour_tens;
        P2OUT = BIT1 + BIT2 + BIT3;
        P2OUT &= ~BIT0;
        break;

    case BIT2:
        P1OUT = clk.hour_ones;
        P2OUT = BIT0 + BIT2 + BIT3;
        P2OUT &= ~BIT1;
        break;

    case BIT1:
        P1OUT = clk.minute_tens;
        P2OUT = BIT0 + BIT1 + BIT3;
        P2OUT &= ~BIT2;
        break;

    case BIT0:
        P1OUT = clk.minute_ones;
        P2OUT = BIT0 + BIT1 + BIT2;
        P2OUT &= ~BIT3;
        break;

    default:
        break;
    }

    if (!(active_display >>= 1))
        active_display = BIT3;
}