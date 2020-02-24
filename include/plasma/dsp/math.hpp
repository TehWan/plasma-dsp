#pragma once

#include <complex>
#include <cmath>

using namespace std;

namespace dsp {

class math {
public:
    math(void) = delete;
    ~math(void) = delete;

    static constexpr double pi = acos(-1.);

    // normalized sinc: sin(\pi x) / (\pi x)
    static double sinc(double x);
};

} // namespace