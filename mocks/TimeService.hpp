#ifndef CAMAX_TIMESERVICE_HPP
#define CAMAX_TIMESERVICE_HPP

#include "ITimeService.hpp"

namespace Camax
{
  class TimeService : public ITimeService
  {
    public:
      TimeService(int minute = 0, int day = 0);
      Time& getTime();
      void getPeriodicAlarm();
      // The actual mock starts from hereon forward
      void setMinute(int minute);
      void setDay(int day);

    private:
      Time time;
  };
}

#endif // CAMAX_TIMESERVICE_HPP
