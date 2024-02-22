/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class WeekDays
{
private:
    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int CurrentDay;

public:
    WeekDays()
    {
        CurrentDay = 0;
    }

    WeekDays(int day)
    {
        CurrentDay = day % 7;
    }

    string getCurrentDay()
    {
        return Days[CurrentDay];
    }

    string getNextDay()
    {
        return Days[(CurrentDay + 1) % 7];
    }

    string getPreviousDay()
    {
        return Days[(CurrentDay + 6) % 7];
    }

    string getNthDayFromToday(int n)
    {
        return Days[(CurrentDay + n) % 7];
    }
};

int main()
{
    WeekDays week;

    cout << "Current Day: " << week.getCurrentDay() << endl;
    cout << "Next Day: " << week.getNextDay() << endl;
    cout << "Previous Day: " << week.getPreviousDay() << endl;

    int n;
    cout << endl
         << "Enter value of n to find nth day from today: " << endl;
    cin >> n;
    cout << "Day after next " << n << " days: " << week.getNthDayFromToday(n) << endl;

    return 0;
}
