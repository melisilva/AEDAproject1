#ifndef AEDAPROJECT1_DATE_H
#define AEDAPROJECT1_DATE_H
#include<ctime>
#include <string>
#include <iostream>
using namespace std;

class Date {
private:
    int mdays[12] = { 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };
    int day,month,year;
public:
    Date();
    Date(int day,int month,int year);
    void showDate();
    string getDateStr();
    Date getDate(string date);
    bool isleapYear();
    int nly();
    int timePeriod(Date dt2);
    string extendTime();


};


#endif //AEDAPROJECT1_DATE_H
