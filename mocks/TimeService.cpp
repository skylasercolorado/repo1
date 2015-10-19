#include "TimeService.hpp"

using namespace Camax;

TimeService::TimeService(int minute, int day)
{
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
  time.minuteOfDay = minute;
}

void TimeService::setDay(int day)
{
  time.dayOfWeek = day;
}
