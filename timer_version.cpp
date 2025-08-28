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

int main() {
    Timer timer;
    std::cout << "Hello, World!" << std::endl;
    return 0; 
}