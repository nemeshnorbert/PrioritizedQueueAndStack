#ifndef PRIORITIZED_QUEUE_AND_STACK_PRIORITIZED_QUEUE_H_
#define PRIORITIZED_QUEUE_AND_STACK_PRIORITIZED_QUEUE_H_

#include "PrioritizedStack.h"

template <typename ValueType, typename ComparerType = std::less<ValueType>>
class ProiritiziedQueue
{
public:
    ProiritiziedQueue() : leftStack_(), rightStack_()
    {}

    ProiritiziedQueue(const ProiritiziedQueue<ValueType, ComparerType>& right)
        : leftStack_(right.leftStack_), rightStack_(right.rightStack_)
    {}

    void Push(const ValueType& value)
    {
        leftStack_.Push(value);
    }

    void Pop()
    {
        if (rightStack_.Empty())
        {
            do
            {
                rightStack_.Push(leftStack_.Top());
                leftStack_.Pop();
            } while (!leftStack_.Empty());
        }
        rightStack_.Pop();
    }

    bool Empty() const
    {
        return leftStack_.Empty() && rightStack_.Empty();
    }

    size_t Size() const
    {
        return leftStack_.Size() + rightStack_.Size();
    }

    ValueType PriorityValue() const
    {
        if (!leftStack_.Empty() && !rightStack_.Empty())
        {
            return std::max(leftStack_.PriorityValue(),
                rightStack_.PriorityValue(),
                ComparerType());
        }
        if (!leftStack_.Empty() && rightStack_.Empty())
        {
            return leftStack_.PriorityValue();
        }
        return rightStack_.PriorityValue();
    }

    void Swap(ProiritiziedQueue<ValueType, ComparerType>& right)
    {
        leftStack_.Swap(right.leftStack_);
        rightStack_.Swap(right.rightStack_);
    }

private:
    ProiritiziedStack<ValueType, ComparerType> leftStack_;
    ProiritiziedStack<ValueType, ComparerType> rightStack_;
};

#endif