#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <thread>

using std::string, std::cout, std::cin, std::endl;
using std::getline, std::setw, std::setfill, std::flush;
using std::this_thread::sleep_for, std::chrono::milliseconds;

int main() {
    int hours = 0, minutes = 0, seconds = 0;
    string message;

    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;
    cin.ignore();  // Clear newline from input buffer

    cout << "Enter message to display when time is up: ";
    getline(cin, message);

    if (hours < 0) hours = 0;
    if (minutes < 0) minutes = 0;
    if (seconds < 0) seconds = 0;

    int total_seconds = hours * 3600 + minutes * 60 + seconds;

    if (total_seconds == 0) {
        cout << "Timer set to 0 seconds. Exiting.\n";
        return 0;
    }

    cout << "\nTimer started for " << hours << "h " << minutes << "m "
              << seconds << "s.\n";

    while (total_seconds > 0) {
        int h = total_seconds / 3600;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;

        cout << "\r" << setw(2) << setfill('0') << h << ":"
                  << setw(2) << setfill('0') << m << ":"
                  << setw(2) << setfill('0') << s << " remaining "
                  << flush;

        sleep_for(std::chrono::seconds(1));
        --total_seconds;
    }

    cout << "\r00:00:00 remaining " << endl;

    // Display custom message
    cout << message << endl;

    // Ring the bell 3 times
    for (int i = 0; i < 3; ++i) {
        cout << "\a";
        sleep_for(milliseconds(500));
    }
    cout << "Time's up!" << endl;

    return 0;
}
