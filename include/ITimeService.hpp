#ifndef CAMAX_ITIMESERVICE_HPP
#define CAMAX_ITIMESERVICE_HPP

namespace Camax
{
  struct Time
   {
     int minuteOfDay;
     int dayOfWeek;
   };

  class ITimeService
  {
    virtual Time& getTime() = 0;
    virtual void getPeriodicAlarm() = 0;
  };
}

#endif // CAMAX_ITIMESERVICE_HPP
