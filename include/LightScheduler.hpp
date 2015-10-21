#ifndef CAMAX_LIGHTSCHEDULER_HPP
#define CAMAX_LIGHTSCHEDULER_HPP

#include "ITimeService.hpp"

namespace Camax
{
  class LightScheduler
  {
    public:
      void ScheduleTurnOn(int id, enum TimeStatus day, int minute);
      void RemoveSchedule();
      void WakeUp();
  };
}

#endif // CAMAX_LIGHTSCHEDULER_HPP
