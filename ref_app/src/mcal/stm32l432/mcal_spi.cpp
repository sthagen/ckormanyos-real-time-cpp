///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2012 - 2024.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal_spi.h>

#include <mcal_spi/mcal_spi_software_dummy.h>

auto mcal::spi::init(const mcal::spi::config_type*) -> void
{
}

auto mcal::spi::spi0() -> util::communication_base&
{
  static mcal::spi::spi_software_dummy com;

  return com;
}
