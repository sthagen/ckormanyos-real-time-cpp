﻿Real-Time-C++ - Benchmarks
==================

<p align="center">
    <a href="https://github.com/ckormanyos/real-time-cpp/actions">
        <img src="https://github.com/ckormanyos/real-time-cpp/actions/workflows/real-time-cpp-benchmarks.yml/badge.svg" alt="Build Benchmarks"></a>
    <a href="https://github.com/ckormanyos/real-time-cpp/blob/master/LICENSE_1_0.txt">
        <img src="https://img.shields.io/badge/license-BSL%201.0-blue.svg" alt="Boost Software License 1.0"></a>
    <a href="https://godbolt.org/z/6cexnsW9Y" alt="godbolt">
        <img src="https://img.shields.io/badge/try%20it%20on-godbolt-green" /></a>
</p>


## Implementation details

  - The benchmarks provide code that exercises microcontroller performance.
  - Various efficiency aspects are emphasized such as integral and floating-point calculations, looping, branching, etc.
  - Each benchmark is implemented as a single callable function to be called from a scheduled task in the multitasking scheduler configuration.
  - Every benchmark file can also be compiled separately as a standalone C++14, 17, 20, 23 and beyond project.
  - A benchmark digital I/O pin is toggled hi/lo at begin/end of the benchmark run providing for oscilloscope real-time measurement.
  - The benchmarks provide scalable, portable means for identifying the performance class of the microcontroller.

## Executing the benchmarks

Executing the benchmarks is straightforward. Select the desired benchmark and
activate its corresponding flag in
[app_benchmark.h](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark.h).
In particular, `#define` the flag `APP_BENCHMARK_TYPE` to be one of the pre-defined benchmark types.
This is typically done by simply un-commenting one of the easily-found relevant lines around
[line 34 here](https://github.com/ckormanyos/real-time-cpp/blob/da091570f30347ab729dcafb46a2e3708ba0ab22/ref_app/src/app/benchmark/app_benchmark.h#L34).
Compile the reference application and run on the target.
The benchmark timing will be reflected on microcontroller's corresponding
benchmark port pin (the definition of which can be found in its target-specific MCAL).

Individual benchmarks can also be run standalone on any C++ platform.
In the following [short link](https://godbolt.org/z/6cexnsW9Y)
to [godbolt](https://godbolt.org), for instance, we have adapted the
`APP_BENCHMARK_TYPE_TRAPEZOID_INTEGRAL` benchmark for standalone use.
The `main()` subroutine in the benchmark source files is activated
with the compiler definition `APP_BENCHMARK_STANDALONE_MAIN`.

## Individual benchmarks

  - ![app_benchmark_none.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_none.cpp) via `#define APP_BENCHMARK_TYPE_NONE` is an empty benchmark with merely a Boolean function call returning `true`.
  - ![app_benchmark_complex.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_complex.cpp) via `#define APP_BENCHMARK_TYPE_COMPLEX` computes a floating-point complex-valued trigonometric sine function using the [`extended_complex::complex`](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/math/extended_complex/extended_complex.h) template class.
  - ![app_benchmark_crc.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_crc.cpp) via `#define APP_BENCHMARK_TYPE_CRC` calculates a $32$-bit, byte-oriented CRC result described in Sect. 6.1 of the book.
  - ![app_benchmark_fast_math.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_fast_math.cpp) via `#define APP_BENCHMARK_TYPE_FAST_MATH` calculates reduced, time-optimized floating-point elementary transcendental functions.
  - ![app_benchmark_filter.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_filter.cpp) via `#define APP_BENCHMARK_TYPE_FILTER` calculates an integral FIR filter sampling result.
  - ![app_benchmark_fixed_point.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_fixed_point.cpp) via `#define APP_BENCHMARK_TYPE_FIXED_POINT` calculates the first derivative of an elementary function using the self-written [`fixed_point`](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/math/fixed_point/fixed_point.h) template class in Chap. 13 of the book.
  - ![app_benchmark_float.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_float.cpp) via `#define APP_BENCHMARK_TYPE_FLOAT` implements the floating-point examples detailed in Sect. 12.4 of the book.
  - ![app_benchmark_wide_integer.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_wide_integer.cpp) via `#define APP_BENCHMARK_TYPE_WIDE_INTEGER` performs $256$-bit unsigned big integer calculations using the [`uintwide_t`](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/math/wide_integer/uintwide_t.h) class.
  - ![app_benchmark_pi_spigot.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_pi_spigot.cpp) via `#define APP_BENCHMARK_TYPE_PI_SPIGOT` performs a pi calculation using a template-based _spigot_ algorithm with calculation steps divided among the slices of the idle task.
  - ![app_benchmark_pi_spigot_single.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_pi_spigot_single.cpp) via `#define APP_BENCHMARK_TYPE_PI_SPIGOT_SINGLE` does the same pi calculation as above implemented as a single function call.
  - ![app_benchmark_hash.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_hash.cpp) via `#define APP_BENCHMARK_TYPE_HASH` computes a $160$-bit hash checksum of a $3$-byte character-based message.
  - ![app_benchmark_wide_decimal.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_wide_decimal.cpp) via `#define APP_BENCHMARK_TYPE_WIDE_DECIMAL` computes a $100$ decimal digit square root using the [`decwide_t`](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/math/wide_decimal/decwide_t.h) template class.
  - ![app_benchmark_trapezoid_integral.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_trapezoid_integral.cpp) via `#define APP_BENCHMARK_TYPE_TRAPEZOID_INTEGRAL` computes the numerical floating-point result of a Bessel function using a recursive trapezoid integration routine.
  - ![app_benchmark_pi_agm.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_pi_agm.cpp) via `#define APP_BENCHMARK_TYPE_PI_AGM` computes $53$ decimal digits of pi (or optionally $101$ decimal digits of pi) using a Gauss AGM method with the [`decwide_t`](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/math/wide_decimal/decwide_t.h) template class having a so-called _limb type_ of `std::uint16_t`.
  - ![app_benchmark_boost_math_cbrt_tgamma.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_boost_math_cbrt_tgamma.cpp) via `#define APP_BENCHMARK_TYPE_BOOST_MATH_CBRT_TGAMMA` uses [Boost.Math](https://www.boost.org/doc/libs/1_81_0/libs/math/doc/html/index.html) to compute the cube root of various Gamma functions values.
  - ![app_benchmark_boost_math_cyl_bessel_j.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_boost_math_cyl_bessel_j.cpp) via `#define APP_BENCHMARK_TYPE_BOOST_MATH_CYL_BESSEL_J` also uses [Boost.Math](https://www.boost.org/doc/libs/1_81_0/libs/math/doc/html/index.html) to calculate cylindrical Bessel functions of small, non-integer order.
  - ![app_benchmark_cnl_scaled_integer.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_cnl_scaled_integer.cpp) via `#define APP_BENCHMARK_TYPE_CNL_SCALED_INTEGER` brings a small subset of the [CNL Library](https://github.com/johnmcfarlane/cnl) _onto the metal_ by exercising various elementary quadratic calculations with the fixed-point representations of [`cnl::scaled_integer`](https://github.com/johnmcfarlane/cnl/tree/main/include/cnl/_impl/scaled_integer).
  - ![app_benchmark_soft_double_h2f1.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_soft_double_h2f1.cpp) via `#define APP_BENCHMARK_TYPE_SOFT_DOUBLE_H2F1` calculates an ${\approx}~{15}$ decimal digit hypergeometric function value using a classic iterative rational approximation scheme. This calculation is also included as an example in the [soft_double](https://github.com/ckormanyos/soft_double) project.
  - ![app_benchmark_boost_multiprecision_cbrt.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_boost_multiprecision_cbrt.cpp) via `#define APP_BENCHMARK_TYPE_BOOST_MULTIPRECISION_CBRT` uses [Boost.Multiprecision](https://www.boost.org/doc/libs/1_81_0/libs/multiprecision/doc/html/index.html) in combination with [Boost.Math](https://www.boost.org/doc/libs/1_81_0/libs/math/doc/html/index.html) to compute $101$ decimal digits of a cube root function.
  - ![app_benchmark_hash_sha256.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_hash_sha256.cpp) via `#define APP_BENCHMARK_TYPE_HASH_SHA256` computes a $256$-bit hash checksum of a short $3$-byte character-based message.
  - ![app_benchmark_ecc_generic_ecc.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_ecc_generic_ecc.cpp) via `#define APP_BENCHMARK_TYPE_ECC_GENERIC_ECC` provides an intuitive view on elliptic-curve algebra, depicting a well-known $256$-bit cryptographic key-gen/sign/verify method. This benchmark is actually too lengthy to run on most of our embedded targets (other than BBB or RPI-zero) and adaptions of OS/watchdog are required in order to run this benchmark on the metal.
  - ![app_benchmark_non_std_decimal.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_non_std_decimal.cpp) via `#define APP_BENCHMARK_TYPE_NON_STD_DECIMAL` carries out a $64$-bit decimal-floating-point calculation of the exponential function using the contemporary [cpplliance/decimal](https://github.com/cppalliance/decimal) library. This benchmark does not, at the moment, run on the AVR target, but requires a larger microcontroller such as one of the $32$-bit ARM(R) devices.

## Performance classes

Most of the benchmarks run on each supported target system.
Experience with runs on the individual target systems reveal
a wide range of microcontroller _performance_ _classes_.

Consider, for instance,
[app_benchmark_pi_agm.cpp](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/app/benchmark/app_benchmark_pi_agm.cpp)
which exercises the benchmark of type `APP_BENCHMARK_TYPE_PI_AGM`.
This benchmark computes ${\sim}50{\ldots}100$ decimal digits of the mathematical constant
$\pi$ using a Gauss AGM method with help
from the [`decwide_t`](https://github.com/ckormanyos/real-time-cpp/blob/master/ref_app/src/math/wide_decimal/decwide_t.h)
template class.

A typical range of performance classes is shown in the following table.
The benchmark used is a ${\sim}100$ decimal digit AGM $\pi$ calculation.

| Target             |  runtime $[ms]$ |  relative  |
|--------------------|-----------------|------------|
| `am335x`           |  1.5            |    1.0     |
| `stm32f446`        |  5.1            |    3.4     |
| `rpi_pico2_rp2350` |  6.3            |    4.2     |
| `wch_ch32v307`     |  8.0            |    5.3     |
| `xtensa_esp32_s3`  |  9.1            |    6.1     |
| `rpi_pico_rp2040`  |  19             |    13      |
| `avr`              |  420            |    280     |

There are strikingly differing performance classes
for the $8$-bit MICROCHIP(R) AVR controller of the ARDUINO
and the $32$-bit ARM(R) 8 controller
of the BeagleBone Black Edition, Rev. C.
The $\pi$ calculation requires approximately
$420~\text{ms}$ and $1.5~\text{ms}$,
respectively, on these two microcontroller systems.

The $32$-bit ARM(R) Cortex(R) M4F controller on
the `stm32f446` board performs the calculation in
the middle of the two extremes, with a result
of $5.1~\text{ms}$.

The $32$-bit RISC-V controller (having a novel _open-source_ core)
on the `wch_ch32v307` board boasts a quite respectable
time of $8.0~\text{ms}$.

Running on only one core (core0) of the $32$-bit
controller of the `xtensa_esp32_s3` board results in
a runtime of $9.1~\text{ms}$ for the calculation.

Using only one core (core1) on the $32$-bit ARM(R) Cortex(R) M0+
controller of the `rpi_pico_rp2040` board results in a calculation
time of $19~\text{ms}$. The next generation `rpi_pico2_rp2350`
with dual ARM(R) Cortex(R) M33 cores definitively improves on this
(still using only core1) with a time of $6.3~\text{ms}$.
This is slightly more than $3~\text{ms}$ times faster
than its predecessor.
