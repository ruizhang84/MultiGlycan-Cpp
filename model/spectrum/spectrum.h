#ifndef MODEL_SPECTRUM_SPECTRUM_H_
#define MODEL_SPECTRUM_SPECTRUM_H_

#include <vector>
#include "peak.h"

namespace model {
namespace spectrum {

enum class SpectrumType
{ MS, EThcD };

class Spectrum
{
public:
    Spectrum() = default;
    Spectrum(const Spectrum& other){
        peaks_ = std::move(other.peaks_);
        scan_num_ = other.scan_num_;
        type_ = other.type_;
    }

    Spectrum& operator=(const Spectrum& other){
        peaks_ = std::move(other.peaks_);
        scan_num_ = other.scan_num_;
        type_ = other.type_;
        return *this;
    }

    int Scan() { return scan_num_; }
    void set_scan(int num) { scan_num_ = num; }
    SpectrumType Type() { return type_; }
    void set_type(SpectrumType type) { type_ = type; }

    std::vector<Peak> Peaks() { return peaks_; }
    void set_peaks(std::vector<Peak>& peaks) 
        { peaks_ = std::move(peaks); }

protected:
    std::vector<Peak> peaks_;
    int scan_num_;
    SpectrumType type_;

};

}  //  namespace spectrum
}  //  namespace model

#endif