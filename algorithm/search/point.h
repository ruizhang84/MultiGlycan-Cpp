#ifndef ALGORITHM_SEARCH_POINT_H
#define ALGORITHM_SEARCH_POINT_H

#include <vector>

namespace algorithm {
namespace search {

template <class T>
class Point
{
public:
    Point() = default;
    Point(double value, std::vector<T> content):
        value_(value), content_(content){}
    
    double Value() const { return value_; }
    void set_value(double value) { value_ = value; }
    std::vector<T> Content() { return content_; }
    void set_content(std::vector<T> content) { content_ = content; }
    bool operator<(const Point& other)
    {
        return value_ < other.value_;
    }

protected:
    double value_;
    std::vector<T> content_;
};

} // namespace algorithm
} // namespace search 

#endif
