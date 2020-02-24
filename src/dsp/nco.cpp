#include "plasma/dsp/nco.hpp"
#include "plasma/dsp/math.hpp"
#include <cmath>

namespace dsp {

nco::nco(void)
    : theta_(0)
    , d_theta_(0)
{
}

double nco::get_frequency(void) const
{
    return d_theta_ / math::two_pi;
}

void nco::set_frequency(double frequency)
{
    d_theta_ = abs(math::two_pi * frequency);
}

void nco::adjust_frequency(double df)
{
    d_theta_ = abs(d_theta_ + df);
}

double nco::get_phase(void) const
{
    return theta_ / math::two_pi;
}

void nco::set_phase(double phase)
{
    theta_ = fmod(phase, math::two_pi);
}

void nco::adjust_phase(double dp)
{
    theta_ = fmod(theta_ + dp, math::two_pi);
}

void nco::step(void)
{
    theta_ = fmod(theta_ + d_theta_, math::two_pi);
}

void nco::reset(void)
{
    theta_ = 0;
}

double nco::mix_up(double x)
{
    return real(x * exp(complex<double>(0, theta_)));
}

double nco::mix_down(double x)
{
    return real(x * exp(complex<double>(0, -theta_)));
}

complex<double> nco::mix_up_complex(complex<double> x)
{
    return x * exp(complex<double>(0, theta_));
}

complex<double> nco::mix_down_complex(complex<double> x)
{
    return x * exp(complex<double>(0, -theta_));
}

} // namespace
