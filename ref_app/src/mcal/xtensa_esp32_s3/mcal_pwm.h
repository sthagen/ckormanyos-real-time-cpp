///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2025.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_PWM_2025_02_22_H
  #define MCAL_PWM_2025_02_22_H

  #include <mcal_pwm/mcal_pwm_base.h>

  namespace mcal
  {
    namespace pwm
    {
      typedef void config_type;

      inline void init(const config_type*) { }

      mcal::pwm::pwm_base& pwm0() noexcept;
    }
  }

#endif // MCAL_PWM_2025_02_22_H
