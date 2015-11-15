#ifndef CAMAX_LIGHTSCHEDULER_HPP
#define CAMAX_LIGHTSCHEDULER_HPP

#include "ITimeService.hpp"
#include "ILightController.hpp"
#include <vector>

using namespace std;

namespace Camax
{
  typedef struct ScheduledLightEvent
  {
    int id;
    TimeStatus day;
    int minuteOfDay;
    LightStatus lightStatus;
    
    ScheduledLightEvent(int _id, TimeStatus _day, int _minuteOfDay, LightStatus _lightStatus) :
      id(_id), day(_day), minuteOfDay(_minuteOfDay), lightStatus(_lightStatus)  {}
  } ScheduledLightEvent;
  
  class LightScheduler
  {
  public:
    void ScheduleTurnOn(int id, TimeStatus day, int minute);
    void ScheduleTurnOff(int id, TimeStatus day, int minute);
    void RemoveSchedule();
    void WakeUp();
    
  private:
    vector<ScheduledLightEvent> scheduledLightEvents;
  };
}

#endif // CAMAX_LIGHTSCHEDULER_HPP
