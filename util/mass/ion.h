#ifndef UTIL_MASS_ION_H
#define UTIL_MASS_ION_H

#include<string>
#include "peptide.h"

namespace util {
namespace mass {

enum class IonType { a, b, c, x, y, z};

class IonMass
{
public:
    static double Compute(std::string seq, IonType ion)
    {
        double mass = PeptideMass::Compute(seq); //with an addtional h2o
        switch (ion)
        {
            case IonType::a:
                mass = mass - kOxygen * 2 - kHydrogen - kCarbon;
                break;
            case IonType::b:
                mass = mass - kOxygen - kHydrogen;
                break;
            case IonType::c:
                mass = mass - kOxygen + kHydrogen * 2 + kNitrogen;
                break;
            case IonType::x:
                mass += kCarbon + kOxygen - kHydrogen;
                break;
            case IonType::y:
                mass += kHydrogen;
                break;
            case IonType::z:
                mass = mass - kNitrogen - kHydrogen * 2;
                break;
        }
        return mass;
    }

protected:
    static const double kCarbon = 12.0;
    static const double kNitrogen = 14.003074;
    static const double kOxygen = 15.99491463;
    static const double kHydrogen = 1.007825;
};

} // namespace mass
} // namespace util

#endif