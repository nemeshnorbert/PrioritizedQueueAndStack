#ifndef PRIORITIZED_QUEUE_AND_STACK_PRIORITIZED_STACK_H_
#define PRIORITIZED_QUEUE_AND_STACK_PRIORITIZED_STACK_H_

#include <vector>
#include <algorithm>
#include <functional>

template <typename ValueType, typename ComparerType = std::less<ValueType>>
class ProiritiziedStack
{
public:
    ProiritiziedStack() : data_(), prefixPriorityId_(), comparer_()
    {}

    ProiritiziedStack(const ProiritiziedStack<ValueType, ComparerType>& right)
        : data_(right.data_),
        prefixPriorityId_(right.prefix_priority_id_),
        comparer_(right.comparer_)
    {}

    void Push(const ValueType& value)
    {
        data_.push_back(value);
        if (!prefixPriorityId_.empty())
        {
            prefixPriorityId_.push_back(
                comparer_(value, data_[prefixPriorityId_.back()]) ?
                prefixPriorityId_.back() :
                data_.size() - 1);
        }
        else
        {
            prefixPriorityId_.push_back(data_.size() - 1);
        }
    }

    void Pop()
    {
        data_.pop_back();
        prefixPriorityId_.pop_back();
    }

    bool Empty() const
    {
        return data_.empty();
    }

    size_t Size() const
    {
        return data_.size();
    }

    const ValueType& Top() const
    {
        return data_.back();
    }

    ValueType PriorityValue() const
    {
        return data_[prefixPriorityId_.back()];
    }

    void Swap(ProiritiziedStack<ValueType, ComparerType>& right)
    {
        data_.swap(right.data_);
        prefixPriorityId_.swap(right.prefix_priority_id_);
        std::swap(comparer_, right.comparer_);
    }

private:
    std::vector<ValueType> data_;
    std::vector<size_t> prefixPriorityId_;
    ComparerType comparer_;
};

#endif