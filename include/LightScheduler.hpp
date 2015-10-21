#ifndef CAMAX_LIGHTSCHEDULER_HPP
#define CAMAX_LIGHTSCHEDULER_HPP

#include "ITimeService.hpp"
#include <vector>

using namespace std;

namespace Camax
{
  typedef struct
  {
    int id;
    enum TimeStatus day;
    int minuteOfDay;
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
