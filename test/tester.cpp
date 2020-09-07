#include <cassert>
#include <random>
#include <deque>
#include <iostream>
#include "priority_queue.h"

enum class ActionType
{
    Push, Pop
};

template <typename ValueType>
struct Action
{
    ActionType type;
    ValueType value;
};

template <typename ValueType>
std::vector<Action<ValueType>> GetRandomActions(
        const ValueType& min, const ValueType& max, size_t count)
{
    static std::mt19937_64 engine;
    std::uniform_int_distribution<int> typeGenerator(0, 1);
    std::uniform_int_distribution<ValueType> valueGenerator(min, max);

    std::vector<Action<ValueType>> actions;
    for (size_t index = 0; index < count; ++index)
    {
        Action<ValueType> action;
        action.value = valueGenerator(engine);
        action.type = typeGenerator(engine) == 0 ? ActionType::Push : ActionType::Pop;
        actions.push_back(action);

    }
    return actions;
}

template <typename ValueType>
void PrintAction(std::ostream& out, const Action<ValueType>& action)
{
    if (action.type == ActionType::Push)
    {
        out << "Push " << action.value << '\n';
    }
    else if (action.type == ActionType::Pop)
    {
        out << "Pop\n";
    }
    else
    {
        // Unknown action for the queue
        assert(false);
    }
}

template <typename ValueType>
void PrintActions(std::ostream& out, const std::vector<Action<ValueType>>& actions)
{
    for (size_t index = 0; index < actions.size(); ++index)
    {
        PrintAction(out, actions[index]);
    }
}

template <typename ValueType>
bool RunTest(std::ostream& out, const std::vector<Action<ValueType>>& actions)
{
    PriorityQueue<ValueType> queue;
    std::deque<ValueType> deque;
    for (size_t index = 0; index < actions.size(); ++index)
    {
        if (queue.Size() != deque.size())
        {
            out << "Wrong queue size for action #" << index << " for sequence of actions:\n";
            PrintActions(out, actions);
            return false;
        }
        const Action<ValueType>& action = actions[index];
        if (action.type == ActionType::Push)
        {
            queue.Push(action.value);
            deque.push_front(action.value);
        }
        else if (action.type == ActionType::Pop)
        {
            if (!queue.Empty())
            {
                queue.Pop();
                deque.pop_back();
            }
        }
        else
        {
            // Unknown action for the queue
            assert(false);
        }
        if (!queue.Empty())
        {
            if (deque.empty())
            {
                out << "Queue must be empty after action #" << index << " for sequence of actions:\n";
                PrintActions(out, actions);
                return false;
            }
            else
            {
                ValueType true_max = *std::max_element(deque.begin(), deque.end());
                ValueType max = queue.PriorityValue();
                if (true_max != max)
                {
                    out
                        << "Wrong max "
                        << max
                        << " (true value" << true_max << ") "
                        << "for action # " << index
                        << " for sequence of actions:\n";
                    PrintActions(out, actions);
                    return false;
                }
            }
        }
    }
    out << "Test passed\n";
    return true;
}


int main()
{
    for (int attempt = 0; attempt < 10; ++attempt)
    {
        if(!RunTest(std::cout, GetRandomActions<int>(-100, 100, 10000)))
        {
            return 1;
        }
    }
    return 0;
}
