#pragma once
#include <string>
#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

class ThreadCounter{
public:
    explicit ThreadCounter(int n);

    int count = 0;
    int need_threads;
};

ThreadCounter::ThreadCounter(int n): need_threads(n) {
}
