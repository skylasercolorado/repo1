#include "TimeService.hpp"
#include <stdexcept>

using namespace Camax;
using namespace std;

void TimeService::validateMinute(int minute)
{
  const int hoursInDay = 24;
  const int minutesInHour = 60;

  if (minute < 0 || minute > ((hoursInDay * minutesInHour) - 1))
    throw range_error ("minutes must be between 0 and 1439");
}

void TimeService::validateDay(int day)
{
  const int daysInWeek = 7;

  if (day < 1 || day > (daysInWeek))
    throw range_error ("days must be between 1 and 7");
}

TimeService::TimeService()
{
  time.minuteOfDay = TimeUnknown;
  time.dayOfWeek = TimeUnknown;
}

Time& TimeService::getTime()
{
  return time;
}

void TimeService::getPeriodicAlarm()
{

}

void TimeService::setMinute(int minute)
{
  validateMinute(minute);
  time.minuteOfDay = minute;
}

void TimeService::setDay(int day)
{
  validateDay(day);
  time.dayOfWeek = day;
}
