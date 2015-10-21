#include "LightScheduler.hpp"
#include "TimeService.hpp"
#include "LightController.hpp"

using namespace Camax;

void LightScheduler::ScheduleTurnOn(int id, enum TimeStatus day, int minute)
{
  TimeService::validateDay(day);
  TimeService::validateMinute(minute);

  scheduledLightEvents.push_back(ScheduledLightEvent(id, day, minute));
}

void LightScheduler::RemoveSchedule()
{

}

void LightScheduler::WakeUp()
{

}

