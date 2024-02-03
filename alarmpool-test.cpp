#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// int64_t alarm_callback(alarm_id_t id, void *user_data) {
//     // Put your timeout handler code in here
//     return 0;
// }

repeating_timer_t rpt1000;
repeating_timer_t rpt1011;
repeating_timer_t rpt1017;
repeating_timer_t rpt1029;
repeating_timer_t rpt1063;

bool callback_a(repeating_timer_t *rt)
{
    puts("a");
    return true;
}
bool callback_b(repeating_timer_t *rt)
{
    puts("b");
    return true;
}
bool callback_c(repeating_timer_t *rt)
{
    puts("c");
    return true;
}
bool callback_d(repeating_timer_t *rt)
{
    puts("d");
    return true;
}
bool callback_e(repeating_timer_t *rt)
{
    puts("e");
    return true;
}

int main()
{
    stdio_init_all();

    // // Timer example code - This example fires off the callback after 2000ms
    // add_alarm_in_ms(2000, alarm_callback, NULL, false);

    sleep_ms(1000);
    puts("Hello, world!");
    sleep_ms(1000);

    // auto ap = alarm_pool_create_with_unused_hardware_alarm(4); // this will block the timer E below
    auto ap = alarm_pool_create_with_unused_hardware_alarm(8);
    alarm_pool_add_repeating_timer_ms(ap, -1000, callback_a, nullptr, &rpt1000); // A
    alarm_pool_add_repeating_timer_ms(ap, -1011, callback_b, nullptr, &rpt1011); // B
    alarm_pool_add_repeating_timer_ms(ap, -1017, callback_c, nullptr, &rpt1017); // C
    alarm_pool_add_repeating_timer_ms(ap, -1029, callback_d, nullptr, &rpt1029); // D
    alarm_pool_add_repeating_timer_ms(ap, -1063, callback_e, nullptr, &rpt1063); // E

    while (true) {

    }

    return 0;
}
