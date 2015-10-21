#ifndef CAMAX_LIGHTSCHEDULER_HPP
#define CAMAX_LIGHTSCHEDULER_HPP

#include "ITimeService.hpp"
#include <vector>

using namespace std;

namespace Camax
{
  typedef struct ScheduledLightEvent
  {
    int id;
    enum TimeStatus day;
    int minuteOfDay;

    ScheduledLightEvent(int _id, enum TimeStatus _day, int _minuteOfDay) :
      id(_id), day(_day), minuteOfDay(_minuteOfDay) {}
  } ScheduledLightEvent;

  vector<ScheduledLightEvent> scheduledLightEvents;

  class LightScheduler
  {
    public:
      void ScheduleTurnOn(int id, enum TimeStatus day, int minute);
      void RemoveSchedule();
      void WakeUp();
  };
}

#endif // CAMAX_LIGHTSCHEDULER_HPP
