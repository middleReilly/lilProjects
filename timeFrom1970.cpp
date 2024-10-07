#include <iostream>
#include <ctime>

using namespace std;

int main() {

    int sec, min, hr, day, year;
    int timeAmount;
    
    timeAmount = time(NULL);

    sec = 1;
    min = 60 * sec;
    hr = 60 * min;
    day = 24 * hr;
    year = 365 * day;

    int yearCount = 0;
    while (year <= timeAmount) {
        timeAmount -= year;
        yearCount++;
    }

    int dayCount = 0;
    while (day <= timeAmount) {
        timeAmount -= day;
        dayCount++;
    }

    int hrCount = 0;
    while (hr <= timeAmount) {
        timeAmount -= hr;
        hrCount++;
    }

    int minCount = 0;
    while (min <= timeAmount) {
        timeAmount -= min;
        minCount++;
    }

    int secCount = 0;
    while (sec <= timeAmount) {
        timeAmount -= sec;
        secCount++;
    }

    cout << "It has been " << yearCount << " years, " << dayCount << " days, ";
    cout << hrCount << " hours, " << minCount << " minutes, and " << secCount << " seconds ";
    cout << "since 00:00:00 GMT, Jan 1, 1970.\n";

    cout << clock()/CLOCKS_PER_SEC;
    return 0;
}
