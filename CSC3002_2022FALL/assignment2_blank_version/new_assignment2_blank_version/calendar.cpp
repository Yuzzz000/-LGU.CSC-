/* Q1:
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 */

#include <string>
#include <iostream>
#include "csc300222fall/assignment2/lib.h"
#include "csc300222fall/assignment2/calendar.h"

using namespace std;

Month stringToMonth(string s)
{
   if (s == "JANUARY") {
      return JANUARY;
   }
   if (s == "FEBRUARY") {
      return FEBRUARY;
   }
   if (s == "MARCH") {
      return MARCH;
   }
   if (s == "APRIL") {
      return APRIL;
   }
   if (s == "MAY") {
      return MAY;
   }
   if (s == "JUNE") {
      return JUNE;
   }
   if (s == "JULY") {
      return JULY;
   }
   if (s == "AUGUST") {
      return AUGUST;
   }
   if (s == "SEPTEMBER") {
      return SEPTEMBER;
   }
   if (s == "OCTOBER") {
      return OCTOBER;
   }
   if (s == "NOVEMBER") {
      return NOVEMBER;
   }
   if (s == "DECEMBER") {
      return DECEMBER;
   }
}

/* TODO PART:
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
string monthToString(Month month)
{
   // TODO
   string strM = "???";
   if (month == JANUARY){
      strM = "JANUARY";
   }
   if (month == FEBRUARY){
      strM = "FEBRUARY";
   }
   if (month == MARCH){
      strM = "MARCH";
   }
   if (month == APRIL){
      strM = "APRIL";
   }
   if (month == MAY){
      strM = "MAY";
   }
   if (month == JUNE){
      strM = "JUNE";
   }
   if (month == JULY){
      strM = "JULY";
   }
   if (month == AUGUST){
      strM = "AUGUST";
   }
   if (month == SEPTEMBER){
      strM = "SEPTEMBER";
   }
   if (month == OCTOBER){
      strM = "OCTOBER";
   }
   if (month == NOVEMBER){
      strM = "NOVEMBER";
   }
   if (month == DECEMBER){
      strM = "DECEMBER";
   }
   return strM;
}

Month operator++(Month &month, int)
{
   // TODO
   Month month1;
   month1 = static_cast<Month>((static_cast<int>(month) + 1) % 7);
   return month1;
}


/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Date class.  The default
 * constructor creates a Date with a zero internal value that must
 * be assigned a new value before it is used.  The others initialize
 * the date from the arguments by calling the private initDate method.
 */

Date::Date()
{
   initDate(1, JANUARY, 1900);
}

Date::Date(int day, Month month, int year)
{
   initDate(day, month, year);
}

Date::Date(Month month, int day, int year)
{
   initDate(day, month, year);
}

/*
 * TODO function
 * Implementation notes: getDay, getMonth
 * --------------------------------------
 * In this implementation of the Date class, the day and the month are
 * not stored explicitly but must instead be computed from the dayInYear
 * field.
 */

int Date::getDay()
{
   // TODO
   int gDay = 0;
   while ((isLeapYear(year) == false && dayInYear > 365) || dayInYear> 366){
      if(isLeapYear(year)){dayInYear = dayInYear - 366;}
      else{dayInYear = dayInYear - 365;}
      year = year + 1;
   }
   while (dayInYear <= 0){
      year = year - 1;
      if(isLeapYear(year)){dayInYear = dayInYear + 366;}
      else{dayInYear = dayInYear + 365;}
   }
   if (dayInYear <= 31){gDay = dayInYear;}
   if (isLeapYear(year)){
      if(dayInYear > 31 && dayInYear <= 60){gDay = dayInYear - 31;}  //2
      if(dayInYear > 60 && dayInYear <= 91){gDay = dayInYear - 60;}  //3
      if(dayInYear > 91 && dayInYear <= 121){gDay = dayInYear - 91;} //4
      if(dayInYear > 121 && dayInYear <= 152){gDay = dayInYear - 121;}  //5
      if(dayInYear > 152 && dayInYear <= 182){gDay = dayInYear - 152;}  //6
      if(dayInYear > 182 && dayInYear <= 213){gDay = dayInYear - 182;} //7
      if(dayInYear > 213 && dayInYear <= 244){gDay = dayInYear - 213;}  //8
      if(dayInYear > 244 && dayInYear <= 274){gDay = dayInYear - 244;}  //9
      if(dayInYear > 274 && dayInYear <= 305){gDay = dayInYear - 274;}  //10
      if(dayInYear > 305 && dayInYear <= 335){gDay = dayInYear - 305;}  //11
      if(dayInYear > 335 && dayInYear <= 366){gDay = dayInYear - 335;}  //12
   }
   else{
      if(dayInYear > 31 && dayInYear <= 59){gDay = dayInYear - 31;}  //2
      if(dayInYear > 59 && dayInYear <= 90){gDay = dayInYear - 59;}  //3
      if(dayInYear > 90 && dayInYear <= 120){gDay = dayInYear - 90;} //4
      if(dayInYear > 120 && dayInYear <= 151){gDay = dayInYear - 120;}  //5
      if(dayInYear > 151 && dayInYear <= 181){gDay = dayInYear - 151;}  //6
      if(dayInYear > 181 && dayInYear <= 212){gDay = dayInYear - 181;} //7
      if(dayInYear > 212 && dayInYear <= 243){gDay = dayInYear - 212;}  //8
      if(dayInYear > 243 && dayInYear <= 273){gDay = dayInYear - 243;}  //9
      if(dayInYear > 273 && dayInYear <= 304){gDay = dayInYear - 273;}  //10
      if(dayInYear > 304 && dayInYear <= 334){gDay = dayInYear - 304;}  //11
      if(dayInYear > 334 && dayInYear <= 365){gDay = dayInYear - 334;}  //12
   }
   return gDay;
}

/*
 * TODO function
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

Month Date::getMonth()
{
   // TODO
   Month gMonth;
   while ((isLeapYear(year) == false && dayInYear > 365) || dayInYear> 366){
      if(isLeapYear(year)){dayInYear = dayInYear - 366;}
      else{dayInYear = dayInYear - 365;}
      year = year + 1;
   }
   while (dayInYear <= 0){
      year = year - 1;
      if(isLeapYear(year)){dayInYear = dayInYear + 366;}
      else{dayInYear = dayInYear + 365;}
   }
   if (dayInYear <= 31){gMonth = JANUARY;}
   if (isLeapYear(year)){
      if(dayInYear > 31 && dayInYear <= 60){gMonth = FEBRUARY;}  //2
      if(dayInYear > 60 && dayInYear <= 91){gMonth = MARCH;}  //3
      if(dayInYear > 91 && dayInYear <= 121){gMonth = APRIL;} //4
      if(dayInYear > 121 && dayInYear <= 152){gMonth = MAY;}  //5
      if(dayInYear > 152 && dayInYear <= 182){gMonth = JUNE;}  //6
      if(dayInYear > 182 && dayInYear <= 213){gMonth = JULY;} //7
      if(dayInYear > 213 && dayInYear <= 244){gMonth = AUGUST;}  //8
      if(dayInYear > 244 && dayInYear <= 274){gMonth = SEPTEMBER;}  //9
      if(dayInYear > 274 && dayInYear <= 305){gMonth = OCTOBER;}  //10
      if(dayInYear > 305 && dayInYear <= 335){gMonth = NOVEMBER;}  //11
      if(dayInYear > 335 && dayInYear <= 366){gMonth = DECEMBER;}  //12
   }
   else{
      if(dayInYear > 31 && dayInYear <= 59){gMonth = FEBRUARY;}  //2
      if(dayInYear > 59 && dayInYear <= 90){gMonth = MARCH;}  //3
      if(dayInYear > 90 && dayInYear <= 120){gMonth = APRIL;} //4
      if(dayInYear > 120 && dayInYear <= 151){gMonth = MAY;}  //5
      if(dayInYear > 151 && dayInYear <= 181){gMonth = JUNE;}  //6
      if(dayInYear > 181 && dayInYear <= 212){gMonth = JULY;} //7
      if(dayInYear > 212 && dayInYear <= 243){gMonth = AUGUST;}  //8
      if(dayInYear > 243 && dayInYear <= 273){gMonth = SEPTEMBER;}  //9
      if(dayInYear > 273 && dayInYear <= 304){gMonth = OCTOBER;}  //10
      if(dayInYear > 304 && dayInYear <= 334){gMonth = NOVEMBER;}  //11
      if(dayInYear > 334 && dayInYear <= 365){gMonth = DECEMBER;}  //12
   }
   return gMonth;

}

int Date::getYear()
{
   // TODO
   return year;
}

/*
 * TODO function
 * Implementation notes: toString
 * ------------------------------
 * The toString method uses the getters to perform the translation into
 * day/month/year values.
 */

string Date::toString()
{
   // TODO
   string toS;
   
   day = getDay();
   month = getMonth();
   year = getYear();
   string m = capitalize(monthToString(month));
   toS = to_string(day) + "-" + m + "-" + to_string(year);
   return toS;
}

string Date::capitalize(string str)
{
   // TODO
   string capS;
   capS = str[0];
   for (int i = 1; i < 3; i++){
      str[i] = tolower(str[i]);
      capS = capS + str[i];
   }
   return capS;
}

void Date::initDate(int day, Month month, int yyyy)
{
   // TODO
   this->day = day;
   this->month = month;
   this->year = yyyy;
   if (month == JANUARY){dayInYear = day;}
   if(month == FEBRUARY){dayInYear = day + 31;}
   if(isLeapYear(year)){
      if (month == MARCH){dayInYear = day + 60;}
      if (month == APRIL){dayInYear = day + 91;}
      if (month == MAY){dayInYear = day + 121;}
      if (month == JUNE){dayInYear = day + 152;}
      if (month == JULY){dayInYear = day + 182;}
      if (month == AUGUST){dayInYear = day + 213;}
      if (month == SEPTEMBER){dayInYear = day + 244;}
      if (month == OCTOBER){dayInYear = day + 274;}
      if (month == NOVEMBER){dayInYear = day + 305;}
      if (month == DECEMBER){dayInYear = day + 335;}
   }
   else{
      if (month == MARCH){dayInYear = day + 50;}
      if (month == APRIL){dayInYear = day + 90;}
      if (month == MAY){dayInYear = day + 120;}
      if (month == JUNE){dayInYear = day + 151;}
      if (month == JULY){dayInYear = day + 181;}
      if (month == AUGUST){dayInYear = day + 212;}
      if (month == SEPTEMBER){dayInYear = day + 243;}
      if (month == OCTOBER){dayInYear = day + 273;}
      if (month == NOVEMBER){dayInYear = day + 304;}
      if (month == DECEMBER){dayInYear = day + 334;}
   }
}

int getDayInYear(Date date){
   int dayInYear;
   Month month = date.getMonth();
   int day = date.getDay();
   int year = date.getYear();
   if (month == JANUARY){dayInYear = day;}
   if(month == FEBRUARY){dayInYear = day + 31;}
   if(isLeapYear(year)){
      if (month == MARCH){dayInYear = day + 60;}
      if (month == APRIL){dayInYear = day + 91;}
      if (month == MAY){dayInYear = day + 121;}
      if (month == JUNE){dayInYear = day + 152;}
      if (month == JULY){dayInYear = day + 182;}
      if (month == AUGUST){dayInYear = day + 213;}
      if (month == SEPTEMBER){dayInYear = day + 244;}
      if (month == OCTOBER){dayInYear = day + 274;}
      if (month == NOVEMBER){dayInYear = day + 305;}
      if (month == DECEMBER){dayInYear = day + 335;}
   }
   else{
      if (month == MARCH){dayInYear = day + 50;}
      if (month == APRIL){dayInYear = day + 90;}
      if (month == MAY){dayInYear = day + 120;}
      if (month == JUNE){dayInYear = day + 151;}
      if (month == JULY){dayInYear = day + 181;}
      if (month == AUGUST){dayInYear = day + 212;}
      if (month == SEPTEMBER){dayInYear = day + 243;}
      if (month == OCTOBER){dayInYear = day + 273;}
      if (month == NOVEMBER){dayInYear = day + 304;}
      if (month == DECEMBER){dayInYear = day + 334;}
   }
   return dayInYear;

}



Date operator+(Date date, int delta)
{
   // TODO
   /*
   int dayInYear;
   Month month = date.getMonth();
   int day = date.getDay();
   int year = date.getYear();
   if (month == JANUARY){dayInYear = day;}
   if(month == FEBRUARY){dayInYear = day + 31;}
   if(isLeapYear(year)){
      if (month == MARCH){dayInYear = day + 60;}
      if (month == APRIL){dayInYear = day + 91;}
      if (month == MAY){dayInYear = day + 121;}
      if (month == JUNE){dayInYear = day + 152;}
      if (month == JULY){dayInYear = day + 182;}
      if (month == AUGUST){dayInYear = day + 213;}
      if (month == SEPTEMBER){dayInYear = day + 244;}
      if (month == OCTOBER){dayInYear = day + 274;}
      if (month == NOVEMBER){dayInYear = day + 305;}
      if (month == DECEMBER){dayInYear = day + 335;}
   }
   else{
      if (month == MARCH){dayInYear = day + 50;}
      if (month == APRIL){dayInYear = day + 90;}
      if (month == MAY){dayInYear = day + 120;}
      if (month == JUNE){dayInYear = day + 151;}
      if (month == JULY){dayInYear = day + 181;}
      if (month == AUGUST){dayInYear = day + 212;}
      if (month == SEPTEMBER){dayInYear = day + 243;}
      if (month == OCTOBER){dayInYear = day + 273;}
      if (month == NOVEMBER){dayInYear = day + 304;}
      if (month == DECEMBER){dayInYear = day + 334;}
   }
   dayInYear = dayInYear + delta;
   Date newDate;
   newDate.dayInYear = dayInYear;
   return newDate;
   */


  Date newDate1;
  date.dayInYear = date.dayInYear + delta;
  date.month = date.getMonth();
  date.day = date.getDay();
  return date;
  

  
}
Date operator-(Date date, int delta)
{
   // TODO
   return date + -1*delta;
}

int operator-(Date d1, Date d2)
{
   // TODO
   Date da;
   Date db;
   int sep = 0;
   if (d1 > d2){da = d1; db = d2;}
   if (d1 < d2){da = d2; db = d1;}
   if (d1 == d2){return sep;}
   int dayInYearA;
   Month monthA = da.getMonth();
   int dayA = da.getDay();
   int yearA = da.getYear();
   int dayInYearB;
   Month monthB = db.getMonth();
   int dayB = db.getDay();
   int yearB = db.getYear();
/*
   if (monthA == JANUARY){dayInYearA = dayA;}
   if(monthA == FEBRUARY){dayInYearA = dayA + 31;}
   if(isLeapYear(yearA)){
      if (monthA == MARCH){dayInYearA = dayA + 60;}
      if (monthA == APRIL){dayInYearA = dayA + 91;}
      if (monthA == MAY){dayInYearA = dayA + 121;}
      if (monthA == JUNE){dayInYearA = dayA + 152;}
      if (monthA == JULY){dayInYearA = dayA + 182;}
      if (monthA == AUGUST){dayInYearA = dayA + 213;}
      if (monthA == SEPTEMBER){dayInYearA = dayA + 244;}
      if (monthA == OCTOBER){dayInYearA = dayA + 274;}
      if (monthA == NOVEMBER){dayInYearA = dayA + 305;}
      if (monthA == DECEMBER){dayInYearA = dayA + 335;}
   }
   else{
      if (monthA == MARCH){dayInYearA = dayA + 50;}
      if (monthA == APRIL){dayInYearA = dayA + 90;}
      if (monthA == MAY){dayInYearA = dayA + 120;}
      if (monthA == JUNE){dayInYearA = dayA + 151;}
      if (monthA == JULY){dayInYearA = dayA + 181;}
      if (monthA == AUGUST){dayInYearA = dayA + 212;}
      if (monthA == SEPTEMBER){dayInYearA = dayA + 243;}
      if (monthA == OCTOBER){dayInYearA = dayA + 273;}
      if (monthA == NOVEMBER){dayInYearA = dayA + 304;}
      if (monthA == DECEMBER){dayInYearA = dayA + 335;}
   }
   if (monthB == JANUARY){dayInYearB = dayB;}
   if(monthB == FEBRUARY){dayInYearB = dayB + 31;}
   if(isLeapYear(yearB)){
      if (monthB == MARCH){dayInYearB = dayB + 60;}
      if (monthB == APRIL){dayInYearB = dayB + 91;}
      if (monthB == MAY){dayInYearB = dayB + 121;}
      if (monthB == JUNE){dayInYearB = dayB + 152;}
      if (monthB == JULY){dayInYearB = dayB + 182;}
      if (monthB == AUGUST){dayInYearB = dayB + 213;}
      if (monthB == SEPTEMBER){dayInYearB = dayB + 244;}
      if (monthB == OCTOBER){dayInYearB = dayB + 274;}
      if (monthB == NOVEMBER){dayInYearB = dayB + 305;}
      if (monthB == DECEMBER){dayInYearB = dayB + 335;}
   }
   else{
      if (monthB == MARCH){dayInYearB = dayB + 50;}
      if (monthB == APRIL){dayInYearB = dayB + 90;}
      if (monthB == MAY){dayInYearB = dayB + 120;}
      if (monthB == JUNE){dayInYearB = dayB + 151;}
      if (monthB == JULY){dayInYearB = dayB + 181;}
      if (monthB == AUGUST){dayInYearB = dayB + 212;}
      if (monthB == SEPTEMBER){dayInYearB = dayB + 243;}
      if (monthB == OCTOBER){dayInYearB = dayB + 273;}
      if (monthB == NOVEMBER){dayInYearB = dayB + 304;}
      if (monthB == DECEMBER){dayInYearB = dayB + 335;}
   }
   if (yearA == yearB){sep = dayInYearA - dayInYearB;}

   for (int i = yearB; i <= yearA; i++){

   }
   */
   dayInYearA = getDayInYear(da);
   dayInYearB = getDayInYear(db);
   if (yearA == yearB){sep = dayInYearA - dayInYearB;}
   else{
      if(isLeapYear(yearB)){sep = 366-dayInYearB;}
      else{ sep = 365 - dayInYearB;}
      for (int i = yearB +1 ; i <= yearA; i++){
         if (isLeapYear(i)){sep += 366;}
         else{sep += 365;}
      }
      if(isLeapYear(yearA)){sep = sep - (366-dayInYearA);}
      else{sep = sep - (365-dayInYearA);}
   }
   return sep;
   

}

Date &operator+=(Date &date, int delta)
{
   // TODO
   Date nDate;
   nDate = date + delta;
   date = nDate;
   return date;
}

Date &operator-=(Date &date, int delta)
{
   // TODO
   Date nDate;
   nDate = date - delta;
   date = nDate;
   return date;
}

Date operator++(Date &date)
{
   // TODO
   Date date1;
   date1 = date + 1;
   date = date1;
   return date;


}

Date operator++(Date &date, int)
{
   // TODO
   Date date1;
   Date date2;
   date1 = date;
   date2 = date + 1;
   date = date2;
   return date1;
   
}

Date operator--(Date &date)
{
   // TODO
   Date date1;
   date1 = date - 1;
   date = date1;
   return date;
}

Date operator--(Date &date, int)
{
   // TODO
   Date date1;
   Date date2;
   date1 = date;
   date2 = date - 1;
   date = date2;
   return date1;
   
}

bool operator==(Date d1, Date d2)
{
   // TODO
   if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() == d2.getDay()){
      return true;
   }
   else{
      return false;
   }
}

bool operator!=(Date d1, Date d2)
{
   // TODO
   if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() == d2.getDay()){
      return false;
   }
   else{
      return true;
   }
}

bool operator<(Date d1, Date d2)
{
   // TODO
   if(d1.getYear() < d2.getYear()){
      return true;
   }
   if (d1.getYear() == d2.getYear()){
      if (d1.getMonth() < d2.getMonth()){
         return true;
      }
      if (d1.getMonth() == d2.getMonth()){
         if (d1.getDay() < d2.getDay()){
            return true;
         }
      }  
      }
   return false;
}

bool operator<=(Date d1, Date d2)
{
   // TODO
   if (d1.getYear() > d2.getYear()){
      return false;
   }
   else{
      if (d1.getYear() == d2.getYear() && d1.getMonth() > d2.getMonth()){
         return false;
      }
      else{
         if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() > d2.getDay()){
            return false;
         }
      }
   }
   return true;

}

bool operator>(Date d1, Date d2)
{
   // TODO
   if(d1.getYear() > d2.getYear()){
      return true;
   }
   if (d1.getYear() == d2.getYear()){
      if (d1.getMonth() > d2.getMonth()){
         return true;
      }
      if (d1.getMonth() == d2.getMonth()){
         if (d1.getDay() > d2.getDay()){
            return true;
         }
      }  
      }
   return false;
}

bool operator>=(Date d1, Date d2)
{
   // TODO
   if (d1.getYear() < d2.getYear()){
      return false;
   }
   else{
      if (d1.getYear() == d2.getYear() && d1.getMonth() < d2.getMonth()){
         return false;
      }
      else{
         if (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() < d2.getDay()){
            return false;
         }
      }
   }
   return true;
}

std::ostream &operator<<(std::ostream &os, Date date){
   // TODO
   return os << date.toString();
}

/*
 * TODO function
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function is a reasonably literal translation of the old rhyme:
 *
 *    Thirty days has September
 *    April, June, and November
 *    All the rest have 31
 *    Excepting February alone
 *    Which has 28 in fine
 *    And each leap year 29
 */

int daysInMonth(Month month, int year)
{
   // TODO
   int n;
   if (month == JANUARY || month == MARCH || month == MAY || month == JULY || month == AUGUST || month == OCTOBER || month == DECEMBER){
      n = 31;
   }
   if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER){
      n = 30;
   }
   if (month == FEBRUARY){
      if (isLeapYear(year)){n = 29;}
      else{ n = 28;}
   }
   return n;
}

/* TODO PART:
 * Implementation notes: isLeapYear
 * --------------------------------
 * This function simply encodes the rule for determining leap years:
 * a leap year is any year divisible by 4, except for years ending in 00,
 * in which case the year must be divisible by 400.
 */

bool isLeapYear(int year)
{
   // TODO
   if (year % 100 == 0){
      if (year % 400 == 0){
         return true;
      }
      else{
         return false;
      }
   }
   else{
      if (year % 4 == 0){
         return true;
      }
      else return false;
   }
}

/* DO NOT modify this main() part */
int main()
{
   int id;
   cin >> id;
   int day, year;
   string mon;
   cin >> day >> mon >> year;

   if (id == 1)
   {
      for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1))
      {
         cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << endl;
      }
   }
   else if (id == 2)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding.toString() << endl;
   }
   else if (id == 3)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cin >> mon >> day >> year;
      Date kennedyAssassination(stringToMonth(mon), day, year);
      cin >> mon >> day >> year;
      Date newYearsEve(stringToMonth(mon), day, year);
      cin >> day >> mon >> year;
      Date inaugurationDay(day, stringToMonth(mon), year);
      cin >> day >> mon >> year;
      Date electionDay(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding << endl;
      cout << "kennedyAssassination = " << kennedyAssassination << endl;
      cout << boolalpha;
      cout << "moonLanding < kennedyAssassination = "
           << (moonLanding < kennedyAssassination) << endl;
      cout << "moonLanding > kennedyAssassination = "
           << (moonLanding > kennedyAssassination) << endl;
      cout << "moonLanding == kennedyAssassination = "
           << (moonLanding == kennedyAssassination) << endl;
      cout << "moonLanding == moonLanding = "
           << (moonLanding == moonLanding) << endl;
      cout << "inaugurationDay - electionDay = "
           << (inaugurationDay - electionDay) << endl;
      Date day = newYearsEve;
      cout << "New Year's Eve = " << day++ << endl;
      cout << "New Year's Day = " << day << endl;
      for (Date d = electionDay; d <= inaugurationDay; d++)
      {
         cout << d << endl;
      }
      
   }
}
