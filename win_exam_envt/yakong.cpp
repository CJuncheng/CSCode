#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
using namespace std;

string getWeekday(int year, int month, int day) {
    tm timeStruct = { 0 };
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;

    time_t timeValue = mktime(&timeStruct);
    if (timeValue == -1) 
        return "illegal";

    char* weekday = std::ctime(&timeValue);
    string weekdayStr(weekday);
    weekdayStr.pop_back(); 
    return weekdayStr;
}

int main() {
    
    string str;
    while (std::cin >> str) {
        std::vector<std::string> times;
        string time;
        std::stringstream ss(str);
        while (std::getline(ss, time, '-')) {
            times.push_back(time);
        }

        int year = stoi(times[0]), month = stoi(times[1]), day = stoi(times[2]);

        std::string weekday = getWeekday(year, month, day);
        weekday = weekday.substr(0, 3);
        if(weekday == "illegal"){
            std::cout << "illegal" << std::endl;
            continue;;
        }

        if(weekday == "Mon")
            std::cout << "Monday" << std::endl;
        else if(weekday == "Tue")
            std::cout << "Tuesday" << std::endl;
        else if(weekday == "Wed")
            std::cout << "Wednesday" << std::endl;
        else if(weekday == "Thu")
            std::cout << "Thursday" << std::endl;
        else if(weekday == "Fri")
            std::cout << "Friday" << std::endl;
        else if(weekday == "Sat")
            std::cout << "Saturday" << std::endl;
        else if(weekday == "Sun")
            std::cout << "Sunday" << std::endl;
    }

    return 0;
}