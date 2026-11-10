#pragma once

#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;


class Timer {
private:
    std::string block_name;
    time_point<steady_clock> start_time; // steady_clock never jumps, unlike the wall clock
public:
    Timer(): block_name("block"), 
            start_time(steady_clock::now()) {}
    Timer(const std::string& name): block_name(name), 
            start_time(steady_clock::now()) {}
    ~Timer() {
        auto end_time = steady_clock::now();
        auto duration = end_time - start_time;
    
        cout << "Time consumption of the " << block_name << ": ";
        cout << duration_cast<milliseconds>(duration).count() << "ms\n";
    }
};