#ifndef PRIORITIZED_QUEUE_AND_STACK_VARYING_MAXIMUM_H_
#define PRIORITIZED_QUEUE_AND_STACK_VARYING_MAXIMUM_H_

#include <vector>
#include "PrioritizedQueue.h"

template<typename ValueType>
void FindMaximumsInSlidingWindow(const std::vector<ValueType>& values,
    const std::vector<char>& commands,
    std::vector<ValueType>& maximums)
{
    ProiritiziedQueue<ValueType> prioritiziedQueue;

    size_t rightCursor = 0;
    prioritiziedQueue.Push(values[rightCursor]);

    for (size_t commandIndex = 0; commandIndex < commands.size(); ++commandIndex)
    {
        if (commands[commandIndex] == 'R')
        {
            ++rightCursor;
            prioritiziedQueue.Push(values[rightCursor]);
        }
        if (commands[commandIndex] == 'L')
        {
            prioritiziedQueue.Pop();
        }
        maximums.push_back(prioritiziedQueue.PriorityValue());
    }
}


#endif