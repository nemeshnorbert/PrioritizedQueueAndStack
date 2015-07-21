#ifndef PRIORITIZED_QUEUE_AND_STACK_IO_TOOLS_H_
#define PRIORITIZED_QUEUE_AND_STACK_IO_TOOLS_H_

#include <iostream>
#include <vector>
#include <string>

template<typename ValueType>
void ReadVector(std::istream& input_stream, std::vector<ValueType>& values)
{
    size_t valuesCount;
    input_stream >> valuesCount;
    for (size_t index = 0; index < valuesCount; ++index)
    {
        ValueType value;
        input_stream >> value;
        values.push_back(value);
    }
}

template<typename ValueType>
void PrintVector(std::ostream& outputStream,
    const std::vector<ValueType>& values,
    bool printSize = false)
{
    if (printSize)
    {
        outputStream << values.size() << '\n';
    }
    for (size_t index = 0; index < values.size(); ++index)
    {
        outputStream << values[index] << ' ';
    }
    outputStream << '\n';
}


#endif