// PrioritizedQueueAndStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TestingTools.h"

// Given an array of integers we are about to find maximum in a window sliding over this 
// array. Each move of window is given by two commands: 'R' and 'L'. Command 'R' means 
// that the right edge is extended to the right by one step. Command 'L' moves the left 
// edge the window by one step.

int main()
{
    Test<int>({ 1, 4, 2, 3, 5, 8, 6, 7, 9, 10 },
         { 'R', 'R', 'L', 'R', 'R', 'R', 'L', 'L', 'L', 'R', 'L', 'L' },
         { 4, 4, 4, 4, 5, 8, 8, 8, 8, 8, 8, 6 });
    //Run<int>();
    return 0;
}
