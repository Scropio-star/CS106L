#include <iostream>
#include <sstream>
using namespace std;

int stringToInt(const string& s) {
    istringstream iss(s);
    int result = 0;
    iss >> result;
    return result;
}

int main() {

    return 0;
}