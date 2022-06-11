//
//  main.cpp
//  Calendar_RndStuff
//
//  Created by Biro Laszlo on 11.06.22.
//

#include <iostream>
#include <vector>
#include <string>


int in_put()
{
    int in;
    std::cin >> in;
    return in;
}
void out_days()
{
    std::cout << "\tMon\tTue\tWed\tThu\tFri\tSat\tSun" << std::endl;
}
int out_day_num(int f_day, int days_in_month)
{
    int days = 1;
    int l_day = 1;
    for(int i = 1; days <= days_in_month; )
    {
        if (i >= f_day)
        {
            std::cout << "\t" << days;
            days++;
        }
        else
        {
            std::cout << "\t";
        }
            if (i % 7 == 0)
            {
                std::cout << "\n";
                l_day = 0;
            }
        i++;
        l_day++;
    }
    std::cout << std::endl;
    return l_day;
}
void out_calendar(int year, int f_day)
{
    std::string months[12] {"January", "February","March","April","May","June","July","August","September","October","November","December"};
    int days_in_month[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    std::cout << "Calendar for " << year << std::endl;
    for (int month = 1; month <= 12; month++)
    {
        std::cout << "--" << months[month-1] << " " << year << "--" << std::endl;
        out_days();
        if (year % 4 == 0)
            days_in_month[1] = 29;
        f_day = out_day_num(f_day, days_in_month[month-1]);
    }
}


int main()
{
    std::cout << "Enter a year: ";
    int year = in_put();
    std::cout << "Enter the first day of the year [1: Monday, ... 7:Sunday]: ";
    int f_day = in_put();
    out_calendar(year, f_day);
    
    return 0;
}
