#include <iostream>
#include <thread>
#include <chrono>

class Timer{
    private:
    std::chrono::time_point<std::chrono::system_clock> start_;
    std::string name_;

    public:
        Timer(std::string name = "Timer" ):name_(std::move(name)) , start_{std::chrono::system_clock::now()}{
            
        }
        ~Timer() {
            auto end = std::chrono::system_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start_);
            std::cout<<name_ << " Recorded: " << duration.count() << " ns" << std::endl;
        }
};

void measureTimerOverhead() {
    Timer timer("Timer Overhead");
    
}

int main() {
    measureTimerOverhead(); //Timer Overhead Recorded: 1000 ns
}