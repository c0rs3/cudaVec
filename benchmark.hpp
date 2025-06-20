#ifndef _BENCHMARK_
#define _BENCHMARK_
#include <iostream>
#include <chrono>
#define _BENCHMARK_BEGIN namespace benchmark {
#define _BENCHMARK_END }

_BENCHMARK_BEGIN
// After each scope can be used to store/get the duration of that scope
static std::chrono::duration<float> last_duration;

template<typename Ty_>
class Timer {
private:
public:
	std::chrono::duration<Ty_> duration;
    std::chrono::steady_clock::time_point start; 
    
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer(){
        std::chrono::steady_clock::time_point end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        last_duration = duration;
        std::clog << "Duration(ms): " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms" << endl;
        std::clog << "Duration(ns): " << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count() << "ns" << std::endl;
    }
};

_BENCHMARK_END

#endif