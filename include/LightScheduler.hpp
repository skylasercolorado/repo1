#ifndef CAMAX_LIGHTSCHEDULER_HPP
#define CAMAX_LIGHTSCHEDULER_HPP

namespace Camax
{
  class LightScheduler
  {
    public:
      void ScheduleTurnOn();
      void RemoveSchedule();
      void WakeUp();
  };
}

#endif // CAMAX_LIGHTSCHEDULER_HPP
