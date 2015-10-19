#ifndef CAMAX_TIMESERVICE_HPP
#define CAMAX_TIMESERVICE_HPP

#include "ITimeService.hpp"

namespace Camax
{
  enum TimeStatus
  {
    TimeUnknown,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
  };

  class TimeService : public ITimeService
  {
    public:
      TimeService();
      Time& getTime();
      void getPeriodicAlarm();
      // The actual mock starts from hereon forward
      static void setMinute(int minute);
      static void setDay(int day);

    private:
      static Time time;
      static void validateMinute(int minute);
      static void validateDay(int day);
  };
}

#endif // CAMAX_TIMESERVICE_HPP
