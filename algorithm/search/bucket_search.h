#ifndef ALGORITHM_BUCKET_SEARCH_H
#define ALGORITHM_BUCKET_SEARCH_H

#include <algorithm> 
#include "search.h"
#include <iostream>

namespace algorithm {
namespace search {


template <class T>
class BucketSearch : public SearchBase<T>
{
typedef std::vector<std::vector<std::shared_ptr<Point<T>>>> Bucket;
public:
    struct PointComparer
    {
        bool operator()(std::shared_ptr<Point<T>> const& lhs, std::shared_ptr<Point<T>>  const& rhs) const
        {
            return *lhs < *rhs;
        }
    };

    BucketSearch(double tol, ToleranceBy by):
        SearchBase<T>(tol, by) { };

    void Init()
    {
        if (! this->data_.empty())
        {
            auto min_element = std::min_element(this->data_.begin(), this->data_.end(), PointComparer());
            auto max_element = std::max_element(this->data_.begin(), this->data_.end(), PointComparer());
            min_ = (*min_element)->Value();
            max_ = (*max_element)->Value();

            // bucket size 
            int bucket_size = (int) ((max_ - min_) / this->tolerance_ + 1);
            bins_.reserve(bucket_size);
            bins_.assign(bucket_size, std::vector<std::shared_ptr<Point<T>>>());

            // fill the bucket
            for(auto& it : this->data_){
                int index = Index(it->Value());
                bins_[index].push_back(it);
            }      
        }
    }

    std::vector<T> Query(const double target) override
    {
        std::vector<T> result;
        int index = Index(target);
        for (int i = index - 1; i <= index + 1; i++){
            for(const auto& it : bins_[i])
            {
                if (this->Match(it.get(), target))
                {
                    result.push_back(it->Content());
                }
            }
        }
        return result;
    }

    bool Search(const double target) override
    {
        std::vector<T> result;
        int index = Index(target);
        for (int i = index - 1; i <= index + 1; i++){
            for(const auto& it : bins_[i])
            {
                if (this->Match(it.get(), target))
                {
                    return true;
                }
            }
        }
        return false;
    }


protected:
    int Index(double target) 
        { return (target - min_) / this->tolerance_; }

    double min_;
    double max_;
    Bucket bins_;
};

} // namespace algorithm
} // namespace search 

#endif
