#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

int stringToInt(istringstream& iss) {
    int result;
    if(!(iss >> result))
        throw std::domain_error("Invalid input");
    // char remain;
    // if(iss >> remain)
    //     throw std::domain_error("More than a single invalid int");
    return result;
}

void printEndTime(const string& input) {
    istringstream iss(input);

    //read from the stream in order
    int startHour, startMinute, durationHour, durationMinute;
    string pmToken, hoursToken, minuteToken;
    char colon,remain;
    iss >> startHour >> colon >> startMinute >> pmToken >> durationHour >>hoursToken >> durationMinute >> minuteToken;

    if(iss >> remain)
        throw std::domain_error("More than a single invalid int");

    //deal with PM
    if (pmToken == "PM" && startHour != 12) {
        startHour += 12;
    }

    if (pmToken == "AM" && startHour == 12) {
        startHour = 0;
    }

    //Calculate the final time and deal with the carry
    int finalMinute = startMinute + durationMinute;
    int finalHour = startHour + durationHour + finalMinute / 60;
    finalMinute %= 60;
    finalHour %= 24;

    //output the time to the console
    cout << setw(2) << setfill('0') << finalHour << ':' << setw(2)  << finalMinute <<'\n';

}

int main() {
    printEndTime("1:40 AM 1 hours 30 minutes");
    return 0;
}