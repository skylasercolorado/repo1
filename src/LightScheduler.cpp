#include "LightScheduler.hpp"
#include "TimeService.hpp"
#include "LightController.hpp"

using namespace Camax;

void LightScheduler::ScheduleTurnOn(int id, enum TimeStatus day, int minute)
{
  TimeService::validateDay(day);
  TimeService::validateMinute(minute);

  ScheduledLightEvent event = {id, day, minute};
  scheduledLightEvents.push_back(event);
}

void LightScheduler::RemoveSchedule()
{

}

void LightScheduler::WakeUp()
{

}

