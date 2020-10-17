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

const int mdays[12] = { 31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31 };


int nly(Date d)
{
    int year = d.year;
    int nly = 0;

    if (d.month <= 2) { //See if current year of the date needs to be accounted for in the leap years counter
        year--;
    }

    for (int i = 1800; i <= year; i++) { //leap years are multiples of 4 but not of 100 or multiples of 400 and 100
        if (i% 4 == 0 && i % 100 != 0) {
            nly++;
        }
        if (i% 400 == 0 && i% 100 == 0) {
            nly++;
        }
    }

    return nly;

}

int timePeriod(Date dt1, Date dt2)
{
    long int n1 = (dt1.year-1800) * 365 + dt1.day;

    for (int i = 0; i < dt1.month - 1; i++) {
        n1 += mdays[i];
    }

    n1 += nly(dt1); //Add one day for each leap year (since leap years have 366 and not 365 days)


    long int n2 = (dt2.year - 1800) * 365 + dt2.day;
    for (int i = 0; i < dt2.month - 1; i++){
        n2+=mdays[i];
    }
    n2 += nly(dt2);

    return (n2 - n1);
}

#endif //AEDAPROJECT1_DATE_H
