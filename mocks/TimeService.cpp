#include "TimeService.hpp"
#include <stdexcept>

using namespace Camax;
using namespace std;

TimeService::TimeService(int minute, int day)
{
  //TODO: Validate ranges
  const int hoursInDay = 24;
  const int minutesInHour = 60;
  if(minute < 0 || minute > ((hoursInDay * minutesInHour) - 1))
      throw range_error("minutes must be between 0 and 1439");

  const int daysInWeek = 7;
  if(day < 1 || day > (daysInWeek))
        throw range_error("days must be between 1 and 7");


  time.minuteOfDay = minute;
  time.dayOfWeek = day;
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
  //TODO: Validate ranges
  time.minuteOfDay = minute;
}

void TimeService::setDay(int day)
{
  //TODO: Validate ranges
  time.dayOfWeek = day;
}
