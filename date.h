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
    /** 
        * Default construtctor for class Date.
    */
    Date();

    /** 
        * Overloaded constructor for class Date.
        * @param day: integer number that specifies the day in a range from 1 to 31.
        * @param month: integer number that specifies the month in a range from 1 to 12.
        * @param year: integer number that specifies the year.
    */
    Date(int day,int month,int year);

    /**
     * Void function that outputs the Date in DD/MM/YYYY format.
    */
    void showDate();

    /**
     * Function that returns a string version of the respective Date class object, for use in other classes.
     * @return: a string representing the Date in DD/MM/YYYY format.
     */ 
    string getDateStr() const;

    /**
     * Function that returns the Date object specified by a string in DD/MM/YYYY format.
     * @param date: a string in DD/MM/YYYY format that specifies a date.
     * @return: a Date class object.
    */
    Date getDate(string date) const;

    /**
     * Function to distinguish if a Date's year is a leap year or not.
     * @return: true if it's a leap year, false otherwise.
    */
    bool isleapYear();

    /**
     * Function that returns the number of leap years between 1800 and the year specified by the object's year attribute.
     * @return: number of leap years between 1800 and the object's specified year (integer).
    */
    int nly();

    /**
     * Function that returns the time period (in days) between the Date from which the member is called and the argument's Date.
     * @param dt2: a Date object.
     * @return: the timer period referred in days (integer).
    */
    int timePeriod(Date dt2);

    /**
     * Function that adds exactly 10 days to the Date from which the member is called and returns the resulting date.
     * @return: the Date object with the 10 days added to it (Date).
     */
    Date extendTime();

    /**
     * Function that returns the "delay date" associated with a date (date + 11 days), for calculations regarding delays.
     * @return: the Date object representing the delay date.
     */ 
    Date delayDate();

    /**
     * Operator to compare two dates and see if they're the same.
     * @param d1: the Date with which the current Date will be compared to.
     * @return: true if both dates have the same day, month and year, false otherwise.
    */
    bool operator==(Date d1);

};


#endif //AEDAPROJECT1_DATE_H
