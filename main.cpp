#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>

int main() {
    int hours = 0, minutes = 0, seconds = 0;

    std::cout << "Enter hours: ";
    std::cin >> hours;
    std::cout << "Enter minutes: ";
    std::cin >> minutes;
    std::cout << "Enter seconds: ";
    std::cin >> seconds;

    if (hours < 0) hours = 0;
    if (minutes < 0) minutes = 0;
    if (seconds < 0) seconds = 0;

    int total_seconds = hours * 3600 + minutes * 60 + seconds;

    if (total_seconds == 0) {
        std::cout << "Timer set to 0 seconds. Exiting.\n";
        return 0;
    }

    std::cout << "\nTimer started for " << hours << "h " << minutes << "m "
              << seconds << "s.\n";

    while (total_seconds > 0) {
        int h = total_seconds / 3600;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;

        std::cout << "\r" << std::setw(2) << std::setfill('0') << h << ":"
                  << std::setw(2) << std::setfill('0') << m << ":"
                  << std::setw(2) << std::setfill('0') << s << " remaining "
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::seconds(1));
        --total_seconds;
    }

    std::cout << "\r00:00:00 remaining " << std::endl;

    // Ring the bell 3 times
    for (int i = 0; i < 3; ++i) {
        std::cout << "\a";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "Time's up!" << std::endl;

    return 0;
}
