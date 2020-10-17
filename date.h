#ifndef AEDAPROJECT1_DATE_H
#define AEDAPROJECT1_DATE_H

#include <ctime>


struct Date
{
    int day, month, year;
};

time_t t = time(0);
struct tm *now = localtime(&t);
int todayd=now->tm_mday;
int todaym=now->tm_mon+1;
int todayy=now->tm_year+1900;

Date dttoday={todayd,todaym,todayy};

const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31 };


int countLeapYears(Date d)
{
    int year = d.year;
    int nly = 0;

    if (d.month <= 2) {
        year--;
    }

    for (int i = 1800; i <= year; i++) {
        if (i% 4 == 0 && i % 100 != 0) {
            nly++;
        }
        if (i% 400 == 0 && i% 100 == 0) {
            nly++;
        }
    }

    return nly;

}

int getDifference(Date dt1, Date dt2)
{
    long int n1 = (dt1.year-1800) * 365 + dt1.day;

    for (int i = 0; i < dt1.month - 1; i++) {
        n1 += monthDays[i];
    }

    n1 += countLeapYears(dt1);


    long int n2 = (dt2.year - 1800) * 365 + dt2.day;
    for (int i = 0; i < dt2.month - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    return (n2 - n1);
}

#endif //AEDAPROJECT1_DATE_H
