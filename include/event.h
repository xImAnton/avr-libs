#ifndef __event_h_included__
#define __event_h_included__

/*
    Run the following code only, if the timer was called interval-times.
    Otherwise return and do other stuff in the loop.
    Disable interrupts to prevent the timer_var getting changed during
    checking or setting
*/
#define RUN_TIMED(interval, timer_var) \
    cli(); \
    if (timer_var < interval) { \
        sei(); \
        return; \
    } \
    time -= interval; \
    sei()

typedef uint8_t event_t;

volatile event_t evt_bfr[256] = {0};
volatile uint8_t evt_read_ptr = 0;
volatile uint8_t evt_write_ptr = 0;

#define push_event(evt) evt_bfr[evt_write_ptr++] = evt
#define EVENTS_TO_POLL evt_read_ptr != evt_write_ptr
#define poll_event() evt_bfr[evt_read_ptr++]

#endif // not __event_h_included__
