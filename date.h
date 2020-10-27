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
    string getDateStr() const;
    Date getDate(string date) const;
    bool isleapYear();
    int nly();
    int timePeriod(Date dt2);
    Date extendTime();
    Date delayDate();
    bool operator==(Date d1);

};


#endif //AEDAPROJECT1_DATE_H
