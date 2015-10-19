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
      void setMinute(int minute);
      void setDay(int day);
      static void updateTimeImage(Time time)
      {
	timeImage.dayOfWeek = time.dayOfWeek;
	timeImage.minuteOfDay = time.minuteOfDay;
      }

    private:
      Time time;
      static Time timeImage;
      void validateMinute(int minute);
      void validateDay(int day);

  };
}

#endif // CAMAX_TIMESERVICE_HPP
