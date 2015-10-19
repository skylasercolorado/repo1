#include "TimeService.hpp"

using namespace Camax;

TimeService::TimeService(int minute, int day)
{
  //TODO: Validate ranges
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
