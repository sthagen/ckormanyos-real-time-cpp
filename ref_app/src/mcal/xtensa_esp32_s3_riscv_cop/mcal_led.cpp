///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2025.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_led.h>
#include <mcal_led/mcal_led_port.h>

mcal::led::led_base& mcal::led::led0()
{
  using led0_port_type = mcal::port::port_pin<UINT32_C(17)>;

  using led0_led_type = mcal::led::led_port<led0_port_type>;

  static led0_led_type the_led_00;

  return the_led_00;
}
