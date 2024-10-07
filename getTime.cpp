#include <iostream>
#include <ctime>

using namespace std;

int getTimezone(string timezone, int godTime);
int getYear(int godTime);
bool becausePointersAreDumbI(int godTime);
int becausePointersAreDumbII(int godTime);
string getMonth(int godTime, bool isLeapYear);
int getDay(int godTime, bool isLeapYear);
int becausePointersAreDumbIII(int godTime);
int getTime(int godTime);

int main() {
    int godTime = time(NULL);
    string timezone;
    cout << "Please enter your American standard time zone (in all caps): ";
    cin >> timezone;

    godTime = getTimezone(timezone, godTime);

    int currYear = getYear(godTime);
    bool isLeapYear = becausePointersAreDumbI(godTime);
    godTime = becausePointersAreDumbII(godTime);

    string currMonth = getMonth(godTime, isLeapYear);
    int currDay = getDay(godTime, isLeapYear);
    godTime = becausePointersAreDumbIII(godTime);

    int hr = 3600, min = 60, sec = 1;
    int currHr = 0, currMin = 0, currSec = 0;
    while (hr <= godTime) {
        godTime -= hr;
        currHr++;
    }

    while (min <= godTime) {
        godTime -= min;
        currMin++;
    }

    while (sec <= godTime) {
        godTime -= sec;
        currSec++;
    }

    cout << "The time is ";
    if (currHr < 10) cout << "0" << currHr << ":";
    else cout << currHr << ":";
    if (currMin < 10) cout << "0" << currMin << ":";
    else cout << currMin << ":";
    if (currSec < 10) cout << "0" << currSec;
    else cout << currSec;
    cout << " on " << currMonth << " " << currDay << ", " << currYear << endl;

    return 0;
}

int getTimezone(string timezone, int godTime) {
    while(cin) {
        //Says that if a time zone is 5 hours behind GMT, then it subtracts
        //5 hours from godTime to fit it to that time zone
        if (timezone == "EST") {
            godTime -= (4 * 3600);
        } else if (timezone == "CST") {
            godTime -= (5 * 3600);
        } else if (timezone == "MST") {
            godTime -= (6 * 3600);
        } else if (timezone == "PST") {
            godTime -= (7 * 3600);
        } else if (timezone == "AKST" || timezone == "YST") {
            godTime -= (8 * 3600);
        } else if (timezone == "AHST") {
            godTime -= (9 * 3600);
        } else {
            cout << "Please input a correct time zone: ";
            cin >> timezone;
            continue;
        }
        break;
    }

    return godTime;
}

int getYear(int godTime) {
    int currYear = 1970, year = 31536000, leapYear = 31622400;
    while (year <= godTime) {
        if ((currYear % 4 == 0 && currYear % 100 != 0) || currYear % 400 == 0) {
            godTime -= leapYear;
            currYear++;
        } else {
            godTime -= year;
            currYear++;
        }
    }

    return currYear;
}

bool becausePointersAreDumbI(int godTime) {
    int currYear = 1970, year = 31536000, leapYear = 31622400;
    while (year <= godTime) {
        if ((currYear % 4 == 0 && currYear % 100 != 0) || currYear % 400 == 0) {
            godTime -= leapYear;
            currYear++;
        } else {
            godTime -= year;
            currYear++;
        }
    }

    if ((currYear % 4 == 0 && currYear % 100 != 0) || currYear % 400 == 0) return true;
    else return false;
}

int becausePointersAreDumbII(int godTime) {
    int currYear = 1970, year = 31536000, leapYear = 31622400;
    while (year <= godTime) {
        if ((currYear % 4 == 0 && currYear % 100 != 0) || currYear % 400 == 0) {
            godTime -= leapYear;
            currYear++;
        } else {
            godTime -= year;
            currYear++;
        }
    }

    return godTime;
}

string getMonth(int godTime, bool isLeapYear) {
    int day = 86400, currDay = 1;

    while (day <= godTime) {
        godTime -= day;
        currDay++;
    }

    if (isLeapYear) {
        if (currDay < 32) return "January";
        else if (currDay < 61) return "February";
        else if (currDay < 92) return "March";
        else if (currDay < 122) return "April";
        else if (currDay < 153) return "May";
        else if (currDay < 183) return "June";
        else if (currDay < 214) return "July";
        else if (currDay < 245) return "August";
        else if (currDay < 275) return "September";
        else if (currDay < 306) return "October";
        else if (currDay < 336) return "November";
        else return "December";
    } else {
        if (currDay < 32) return "January";
        else if (currDay < 60) return "February";
        else if (currDay < 91) return "March";
        else if (currDay < 121) return "April";
        else if (currDay < 152) return "May";
        else if (currDay < 182) return "June";
        else if (currDay < 213) return "July";
        else if (currDay < 244) return "August";
        else if (currDay < 274) return "September";
        else if (currDay < 305) return "October";
        else if (currDay < 335) return "November";
        else return "December";
    }
}

int getDay(int godTime, bool isLeapYear) {
    int day = 86400, currDay = 1;

    while (day <= godTime) {
        godTime -= day;
        currDay++;
    }

    if (isLeapYear) {
        if (currDay < 32) return currDay;
        else if (currDay < 61) return currDay - 31;
        else if (currDay < 92) return currDay - 60;
        else if (currDay < 122) return currDay - 91;
        else if (currDay < 153) return currDay - 121;
        else if (currDay < 183) return currDay - 152;
        else if (currDay < 214) return currDay - 182;
        else if (currDay < 245) return currDay - 213;
        else if (currDay < 275) return currDay - 244;
        else if (currDay < 306) return currDay - 274;
        else if (currDay < 336) return currDay - 305;
        else return currDay - 335;
    } else {
        if (currDay < 32) return currDay;
        else if (currDay < 60) return currDay - 31;
        else if (currDay < 91) return currDay - 59;
        else if (currDay < 121) return currDay - 90;
        else if (currDay < 152) return currDay - 120;
        else if (currDay < 182) return currDay - 151;
        else if (currDay < 213) return currDay - 181;
        else if (currDay < 244) return currDay - 212;
        else if (currDay < 274) return currDay - 243;
        else if (currDay < 305) return currDay - 273;
        else if (currDay < 335) return currDay - 304;
        else return currDay - 334;
    }
}

int becausePointersAreDumbIII(int godTime) {
    int day = 86400;

    while (day <= godTime) {
        godTime -= day;
    }

    return godTime;
}
