///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2017 - 2025.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// chapter12_05-001_complex.cpp

#include <complex>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

auto main() -> int;

auto main() -> int
{
  std::complex<float> x(1.23F, 3.45F); // (1.23 + 3.45 I)
  std::complex<float> y(0.77F, 0.22F); // (0.77 + 0.22 I)

  std::complex<float> z1;
  std::complex<float> z2;

  z1 = x / y;       // (2.6603774 + 3.7204117 I)
  z2 = std::sin(x); // (14.859343 + 5.2590045 I)

  std::stringstream strm { };

  strm << "z1: " << std::setprecision(std::numeric_limits<float>::digits10) << z1 << '\n';
  strm << "z2: " << std::setprecision(std::numeric_limits<float>::digits10) << z2 << '\n';

  std::cout << strm.str() << std::endl;
}
