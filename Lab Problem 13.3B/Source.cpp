
#include <iostream>
#include <string>

using namespace std;

int dayOfWeek(int month, int day, int year);
int getModifiedMonth(int month, int year);
int getModifiedYear(int month, int year);

int main() {
    string input;
    int month, day, year;

    while (true) {
        cout << "Enter a date or Q to quit: ";
        getline(cin, input);

        if (input == "Q" || input == "q") {
            break;
        }

        sscanf_s(input.c_str(), "%d %d %d", &month, &day, &year);

        if (month >= 1 && month <= 12 && day >= 1 && day <= 31 && year >= 1582) {
            int weekday = dayOfWeek(month, day, year);
            const char* weekdays[] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
            cout << weekdays[weekday] << ", ";
            switch (month) {
            case 1: cout << "January"; break;
            case 2: cout << "February"; break;
            case 3: cout << "March"; break;
            case 4: cout << "April"; break;
            case 5: cout << "May"; break;
            case 6: cout << "June"; break;
            case 7: cout << "July"; break;
            case 8: cout << "August"; break;
            case 9: cout << "September"; break;
            case 10: cout << "October"; break;
            case 11: cout << "November"; break;
            case 12: cout << "December"; break;
            }
            cout << " " << day << ", " << year << endl;
        }
        else {
            cout << "Invalid date." << endl;
        }
    }

    return 0;
}

/**
dayOfWeek - Computes the weekday of a given date.
@param year the year
@param month the month (1 = January ... 12 = December)
@param day the day of the month
@return the weekday (0 = Saturday ... 6 = Friday)
*/
int dayOfWeek(int month, int day, int year) {
    int modifiedMonth = getModifiedMonth(month, year);
    int modifiedYear = getModifiedYear(month, year);

    int K = modifiedYear % 100;
    int J = modifiedYear / 100;
    int h = (day + (13 * (modifiedMonth + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    if (h < 0) {
        h += 7;
    }

    return h;
}

int getModifiedMonth(int month, int year) {
    if (month == 1 || month == 2) {
        return month + 12;
    }
    else {
        return month;
    }
}

int getModifiedYear(int month, int year) {
    if (month == 1 || month == 2) {
        return year - 1;
    }
    else {
        return year;
    }
}