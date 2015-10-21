#ifndef CAMAX_TIMESERVICE_HPP
#define CAMAX_TIMESERVICE_HPP

#include "ITimeService.hpp"

namespace Camax
{
  class TimeService : public ITimeService
  {
    public:
      //TimeService();
      Time& getTime();
      void getPeriodicAlarm();
      // The actual mock starts from hereon forward
      static void setMinute(int minute);
      static void setDay(int day);
      static void validateMinute(int minute);
      static void validateDay(int day);

    private:
      static Time time;
  };
}

#endif // CAMAX_TIMESERVICE_HPP
