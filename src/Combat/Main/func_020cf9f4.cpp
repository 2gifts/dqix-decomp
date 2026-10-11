// JPN: main:020d14c0
struct CalendarDate { int year, month, day, weekday; };
#if defined(jpn)
extern volatile int data_020f2408[];
#define monthStarts data_020f2408
#else
extern volatile int data_020f229c[];
#define monthStarts data_020f229c
#endif
#pragma optimize_for_size off
extern "C" void func_020cf9f4(CalendarDate* out, int days) {
 if(days<0) days=0;
 if(days>36524) days=36524;
 out->weekday=(days+6)%7;
 unsigned year=0;
 do {
  int prior;
  int span;
  if(!(year&3)) span=366; else span=365;
  prior=days;
  days-=span;
  if(days<0) { days=prior; break; }
  ++year;
 } while(year<99);
 out->year=year;
 if(days>365) days=365;
 if(!(year&3)) {
  if(days<60) {
   int month;
   if(days<31) month=1; else { days-=31; month=2; }
   out->month=month; out->day=days+1; return;
  }
  --days;
 }
 int month=11;
 do {
  if(days>=monthStarts[month]) {
   out->month=month+1; out->day=days-monthStarts[month]+1; return;
  }
 } while(--month>=0);
}

#pragma optimize_for_size reset
