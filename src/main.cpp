#include <iostream>
#include "priority_queue.h"

void Run()
{
    std::ostream& out = std::cout;
    std::istream& in = std::cin;
    out
        << "Given a sequence of actions for a queue we return the minimal value in the queue"
        << " after each action. Valid actions are:\n"
        << "\tpush <value>\n"
        << "\tpop.\n";
    using ValueType = int;
    PriorityQueue<ValueType> queue;
    out << "Enter actions count: ";
    size_t actionsCount = 0;
    in >> actionsCount;
    while (actionsCount > 0)
    {
        out << "Enter action: ";
        std::string action = "";
        in >> action;
        if (action == "push")
        {
            ValueType value;
            in >> value;
            queue.Push(value);
            out << "Max: " << queue.PriorityValue() << '\n';
            --actionsCount;
        }
        else if (action == "pop")
        {
            if (!queue.Empty())
            {
                queue.Pop();
            }
            if (!queue.Empty())
            {
                out << "Max: " << queue.PriorityValue() << '\n';
            }
            else
            {
                out << "Queue is empty\n";
            }
            --actionsCount;
        }
        else
        {
            out << "Unknown action. Valid actions are: push <value> and pop\n";
        }
    }
}

int main()
{
    Run();
    return 0;
}
