#ifndef UTIL_CALC_CALC_H
#define UTIL_CALC_CALC_H

#include <vector>
#include <numeric>

namespace util {
namespace calc {

class Calc
{
public:
    Calc() = default;
    double DotProduct(const std::vector<double>&, 
        const std::vector<double>&) const;
};


} // namespace io
} // namespace calc


#endif