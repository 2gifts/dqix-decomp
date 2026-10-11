#include <globaldefs.h>
struct CalendarDate { int year,month,day; };
#pragma optimize_for_size off
// USA: 020cfc00; JPN: 020d16cc
extern "C" ARM int func_020cfc00(const CalendarDate* date) {
 int year=date->year+2000;
 int month=date->month-2;
 int day=date->day;
 if(month<1) { --year; month+=12; }
 int century=year/100;
 int within=year%100;
 return (day+(26*month-2)/10+within+within/4+century/4+5*century)%7;
}

#pragma optimize_for_size reset
