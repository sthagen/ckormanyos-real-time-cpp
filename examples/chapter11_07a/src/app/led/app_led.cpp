///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2026.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <app/led/app_led.h>
#include <mcal_cpu.h>
#include <mcal_led.h>
#include <mcal_wdg.h>
#include <os/os_task.h>
#include <util/utility/util_time.h>

namespace local
{
  bool result_pi_calc_is_ok { true };
} // namespace local

extern auto pi_main() -> int;

extern "C"
void app_led_task_background(void*)
{
  // This background task runs perpetually without pause, break or yield
  // This task has lowest priority and will be interrupted by any other
  // task having higher priority, such as the LED 1/2 Hz toggle task
  // (i.e., app_led_timer_toggle_led0).

  for(;;)
  {
    // Perform the next pi calculation in a blocking call.
    const int next_pi_result { pi_main() };

    local::result_pi_calc_is_ok = ((next_pi_result == int { INT8_C(0) }) && local::result_pi_calc_is_ok);

    if(!local::result_pi_calc_is_ok)
    {
      // If the pi calculation is wrong, stop the continuous calculation loop.
      for(;;)
      {
        mcal::cpu::nop();

        mcal::wdg::secure::trigger();
      }
    }
  }
}

extern "C"
void app_led_task_toggle_led0(void*)
{
  // When using FreeRTOS, this task has higher priority than
  // the background task. Due to its higher task-priority,
  // this task is, in fact, intended to preemptively interrupt
  // the lower-priority background task.

  // If using the simulated host (such as _MSC_VER or GCC on x86_64),
  // FreeRTOS is not used, but rather the C++ <thread> and <chrono>
  // libraries are used for simulated task scheduling. The <thread>
  // library does not use adjustable priorities in this case, but the
  // thread scheduler supports preemptive scheduling and emulates
  // the desired timing quite well.

  using app_led_timer_type = util::timer<std::uint32_t>;
  using app_led_tick_type  = typename app_led_timer_type::tick_type;

  constexpr app_led_tick_type
    app_led_1s_interval
    {
      app_led_timer_type::seconds(app_led_tick_type { UINT8_C(1) })
    };

  app_led_timer_type app_led_timer_toggle_led0 { app_led_1s_interval };

  auto& local_led0 { mcal::led::led0() };

  local_led0.toggle();

  for(;;)
  {
    // This application task is programmed to cyclically yield for 125ms.

    OS_TASK_WAIT_YIELD(TickType_t { UINT8_C(125) });

    mcal::wdg::secure::trigger();

    if(local::result_pi_calc_is_ok)
    {
      // Toggle led0 every 1s.
      if(app_led_timer_toggle_led0.timeout())
      {
        local_led0.toggle();

        app_led_timer_toggle_led0.start_interval(app_led_1s_interval);
      }
    }
    else
    {
      // If the pi calculation is wrong, turn on the LED and stop toggling.
      if(!local_led0.state_is_on())
      {
        local_led0.toggle();
      }

      for(;;)
      {
        mcal::cpu::nop();

        mcal::wdg::secure::trigger();
      }
    }
  }
}
