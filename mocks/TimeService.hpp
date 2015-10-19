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
//    friend void validateMinute(int minute);
//    friend void validateDay(int day);

    public:
      TimeService();
      Time& getTime();
      void getPeriodicAlarm();
      // The actual mock starts from hereon forward
      static void setMinute(int minute);
      static void setDay(int day);
      static void updateTimeImage(Time time)
      {
	timeImage.dayOfWeek = time.dayOfWeek;
	timeImage.minuteOfDay = time.minuteOfDay;
      }
      void updateTime(Time time)
      {
	this->time.dayOfWeek = time.dayOfWeek;
	this->time.minuteOfDay = time.minuteOfDay;
      }
      static Time timeImage;

    private:
      Time time;

      static void validateMinute(int minute);
      static void validateDay(int day);
  };

  //void validateMinute(int minute);
  //void validateDay(int day);
}

#endif // CAMAX_TIMESERVICE_HPP
