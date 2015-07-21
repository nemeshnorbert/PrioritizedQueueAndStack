#ifndef PRIORITIZED_QUEUE_AND_STACK_TESTING_TOOLS_H_
#define PRIORITIZED_QUEUE_AND_STACK_TESTING_TOOLS_H_

#include "IOTools.h"
#include "VaryingMaximum.h"

template <typename ValueType>
bool Test(const std::vector<ValueType> values,
    const std::vector<char>& commands,
    const std::vector<ValueType>& answers)
{
    std::vector<ValueType> maximums;
    FindMaximumsInSlidingWindow(values, commands, maximums);
    std::ostream& stream = std::cerr;
    if (maximums != answers)
    {

        stream << "Wrong answer\nfor values: ";
        PrintVector(stream, values);
        stream << "and commands: ";
        PrintVector(stream, commands);
        stream << "\nThe correct answer is: ";
        PrintVector(stream, answers);
        return false;
    }
    else
    {
        stream << "Test passed!\n";
    }

    return true;
}

template <typename ValueType>
void Run()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<ValueType> numbers;
    ReadVector(std::cin, numbers);

    std::vector<char> commands;
    ReadVector(std::cin, commands);

    std::vector<ValueType> maximums;
    FindMaximumsInSlidingWindow(numbers, commands, maximums);

    PrintVector(std::cout, maximums);
}

#endif