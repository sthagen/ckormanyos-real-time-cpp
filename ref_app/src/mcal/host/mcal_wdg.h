///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_WDG_2010_04_10_H
  #define MCAL_WDG_2010_04_10_H

  // Forward declaration of the util::timer template class.
  namespace util
  {
    template<typename unsigned_tick_type>
    class timer;
  } // namespace util

  namespace sys
  {
    namespace idle
    {
      void task_func();
    } // namespace idle
  } // namespace sys

  namespace mcal
  {
    namespace wdg
    {
      using config_type = void;

      auto init(const config_type*) -> void;

      class secure final
      {
        static auto trigger() -> void;

        friend auto ::sys::idle::task_func() -> void;

        template<typename unsigned_tick_type>
        friend class util::timer;
      };
    } // namespace wdg
  } // namespace mcal

#endif // MCAL_WDG_2010_04_10_H
