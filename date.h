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

int mdays[12] = { 31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31 };

void showDate(){
    cout<<dttoday.day<<"/"<<dttoday.month<<"/"<<dttoday.year;
}

string getDateStr(struct Date dt1){
    string d,m,y,date,block="/";
    d = to_string(dt1.day);
    m = to_string(dt1.month);
    y = to_string(dt1.year);
    date += d + block + m + block + y;
    return date;
}

struct Date getDate(string date){
    int day,month,year;
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6));
    Date dt1 = { day,month,year };
    return dt1;
}

bool isleapYear(int year){
    bool result=false;
    if (year% 4 == 0 && year % 100 != 0) {
        result=true;
    }
    if (year% 400 == 0 && year% 100 == 0) {
        result=true;
    }
    return result;
}

int nly(Date d)
{
    int year = d.year;
    int nly = 0;

    if (d.month <= 2) { //See if current year of the date needs to be accounted for in the leap years counter
        year--;
    }

    for (int i = 1800; i <= year; i++) { //leap years are multiples of 4 but not of 100 or multiples of 400 and 100
        if (isleapYear(year)) {
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

string extendTime(Date dt1) {
    int rest, extrad = 10;
    //days plus months
    int n1 = dt1.day ;
    for (int i = 0; i < dt1.month - 1; i++) {
        n1 += mdays[i];
    }
    if (isleapYear(dt1.year) && dt1.month > 2) { //check if the fact that it's a leap year or not affect calculations
        n1 += 1;
    }
    if (isleapYear(dt1.year)) {
        rest = 366 - n1;
    }
    else {
        rest = 365 - n1;
    }
    if (extrad <= rest) { //year doesn't change
        n1 += extrad;
    }
    else {
        extrad -= rest;
        dt1.year += 1;
        int days;
        if (isleapYear(dt1.year)) {
            days = 366;
        }
        else {
            days = 365;
        }
        while (extrad >= days) {
            extrad -= days;
        }
        n1 = extrad;
    }
    if (isleapYear(dt1.year)) {
        mdays[1] = 29;
        cout << "leap" << endl;
    }
    int i;
    cout << n1 << endl;
    for (i = 0; i < 12; i++) {
        if (n1 <= mdays[i]) {
            break;
        }
        n1 -= mdays[i];
    }
    dt1.day = n1;
    dt1.month = i+1;
    return getDateStr(dt1);
}



#endif //AEDAPROJECT1_DATE_H
