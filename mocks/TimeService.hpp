#ifndef CAMAX_TIMESERVICE_HPP
#define CAMAX_TIMESERVICE_HPP

#include "ITimeService.hpp"

namespace Camax
{
  class TimeService : public ITimeService
  {
    public:
      TimeService();
      Time& getTime();
      void getPeriodicAlarm();
      // The actual mock starts from hereon forward
      void setMinute(int minute);
      void setDay(int day);

    private:
      Time time;
      void validateMinute(int minute);
      void validateDay(int day);
  };
}

#endif // CAMAX_TIMESERVICE_HPP
