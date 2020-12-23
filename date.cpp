#include "date.h"
using namespace std;

Date::Date(){
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int todayd=now->tm_mday;
    int todaym=now->tm_mon+1;
    int todayy=now->tm_year+1900;
    this->day=todayd;
    this->month=todaym;
    this->year=todayy;
}

bool Date::operator==(Date d1){
    if ((day == d1.day) && (month == d1.month) && (year == d1.year)){
        return true;
    }
    return false;
}

Date::Date(int day,int month,int year){
    this->day=day;
    this->month=month;
    this->year=year;
}

void Date::showDate(){
    cout<<day<<"/"<<month<<"/"<<year;
}

string Date::getDateStr() const{
    string d,m,y,date,block="/";
    if(day<10){
        d='0'+to_string(day);
    }
    else{
        d=to_string(day);
    }
    if(month<10){
        m='0'+to_string(month);
    }else{
        m = to_string(month);
    }
    y = to_string(year);
    date += d + block + m + block + y;
    return date;
}

Date Date::getDate(string date) const{
    int day,month,year;
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6));
    Date dt1 = { day,month,year };
    return dt1;
}

bool Date::isleapYear(){
    bool result=false;
    if (year% 4 == 0 && year % 100 != 0) {
        result=true;
    }
    if (year% 400 == 0 && year% 100 == 0) {
        result=true;
    }
    return result;
}

int Date::nly()
{
    int year = year;
    int nly = 0;

    if (month <= 2) { //See if current year of the date needs to be accounted for in the leap years counter
        year--;
    }

    for (int i = 1800; i <= year; i++) { //leap years are multiples of 4 but not of 100 or multiples of 400 and 100
        if (isleapYear()) {
            nly++;
        }
    }

    return nly;

}

int Date::timePeriod( Date dt2)
{
    long int n1 = (year-1800) * 365 + day;

    for (int i = 0; i < month - 1; i++) {
        n1 += mdays[i];
    }

    n1 += nly(); //Add one day for each leap year (since leap years have 366 and not 365 days)


    long int n2 = (dt2.year - 1800) * 365 + dt2.day;
    for (int i = 0; i < dt2.month - 1; i++){
        n2+=mdays[i];
    }
    n2 += dt2.nly();
    return (n2 - n1);
}

Date Date::extendTime() {
    int rest, extrad = 10;
    //days plus months
    int n1 = day ;
    for (int i = 0; i < month - 1; i++) {
        n1 += mdays[i];
    }
    if (isleapYear() && month > 2) { //check if the fact that it's a leap year or not affect calculations
        n1 += 1;
    }
    if (isleapYear()) {
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
        year += 1;
        int days;
        if (isleapYear()) {
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
    if (isleapYear()) {
        mdays[1] = 29;
    }
    int i;
    for (i = 0; i < 12; i++) {
        if (n1 <= mdays[i]) {
            break;
        }
        n1 -= mdays[i];
    }
    day = n1;
    month = i+1;
    Date result={day,month,year};
    return result;
}

Date Date::delayDate() {
    int rest, extrad = 11;
    //days plus months
    int n1 = day ;
    for (int i = 0; i < month - 1; i++) {
        n1 += mdays[i];
    }
    if (isleapYear() && month > 2) { //check if the fact that it's a leap year or not affect calculations
        n1 += 1;
    }
    if (isleapYear()) {
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
        year += 1;
        int days;
        if (isleapYear()) {
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
    if (isleapYear()) {
        mdays[1] = 29;
    }
    int i;
    for (i = 0; i < 12; i++) {
        if (n1 <= mdays[i]) {
            break;
        }
        n1 -= mdays[i];
    }
    day = n1;
    month = i+1;
    Date result={day,month,year};
    return result;
}