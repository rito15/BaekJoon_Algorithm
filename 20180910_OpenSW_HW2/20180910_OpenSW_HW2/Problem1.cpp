#include <iostream>
#include <string>

using namespace std;

typedef struct date
{
    int year;
    int month;
    int day;
} date;

// 0월 ~ 12월의 일수 (0월은 마이너스 계산 위해 31로 설정)
int days[] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void parse_date(date& dateStruct, string dateTime)
{
    string tmp;

    for (int i = 0; i < 10; i++)	// parsing
    {
        tmp += dateTime[i];

        if (i == 4 || i == 7)
            tmp = "";
        else if (i == 3)
        {
            dateStruct.year = stoi(tmp);
            tmp = "";
        }
        else if (i == 6)
        {
            dateStruct.month = stoi(tmp);
            tmp = "";
        }
        else if (i == 9)
        {
            dateStruct.day = stoi(tmp);
            tmp = "";
        }
    }
}

void print_date(date &date_)
{
    cout << date_.year;
    cout << "/";

    if (date_.month < 10) cout << '0';
    cout << date_.month;
    cout << "/";

    if (date_.day < 10) cout << '0';
    cout << date_.day;
    cout << endl;
}

bool isLeapYear(int year)
{
    if (year % 4 == 0)
        return true;
    else
        return false;
}

void calculate_date(date& now, date& target, int& gap)
{
    target = now;

    while (gap != 0)
    {
        if (gap > 0)
        {
            if (gap > days[target.month])	// calculation body
            {
                if (isLeapYear(target.year) && target.month == 2)
                {
                    target.day += 29;
                    gap -= 29;
                }
                else
                {
                    target.day += days[target.month];
                    gap -= days[target.month];
                }
            }
            else // gap <= days[month]
            {
                target.day += gap;
                gap = 0;
            }

            if (target.day > days[target.month])	// month up
            {
                if (isLeapYear(target.year) && target.month == 2)
                {
                    if (target.day > 29)
                    {
                        target.day -= 29;
                        target.month++;
                    }
                }
                else
                {
                    target.day -= days[target.month];
                    target.month++;
                }
            }

            if (target.month > 12)		// year up
            {
                target.month -= 12;
                target.year++;
            }
        }
        else // gap < 0   ================================================
        {
            if (gap < 0 - days[target.month - 1])	// calculation body
            {
                if (isLeapYear(target.year) && target.month == 3)
                {
                    target.day -= 29;
                    gap += 29;
                }
                else
                {
                    target.day -= days[target.month - 1];
                    gap += days[target.month - 1];
                }
            }
            else // gap >= days[month - 1]
            {
                target.day += gap;
                gap = 0;
            }

            if (target.day < 0)	// month down
            {
                if (isLeapYear(target.year) && target.month == 3)
                {
                    if (target.day + 29 > 0)
                    {
                        target.day += 29;
                        target.month--;
                    }
                }
                else
                {
                    target.day += days[target.month - 1];
                    target.month--;
                }
            }

            if (target.month < 1)		// year down
            {
                target.month += 12;
                target.year--;
            }
        }
    }
}

int main()
{
    date now;			// now
    date target;		// 
    string dateTime;	// input date string
    int gap;			// target - now (days)

    cout << "Input Now Date : ";
    cin >> dateTime;
    parse_date(now, dateTime);		// string -> date

    cout << "Input gap      : ";
    cin >> gap;

    calculate_date(now, target, gap);

    cout << "Target Date    : ";
    print_date(target);

    return 0;
}