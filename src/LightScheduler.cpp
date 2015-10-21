#include "LightScheduler.hpp"
#include "TimeService.hpp"
#include "LightController.hpp"

#include <vector>
#include <iostream>

using namespace Camax;
using namespace std;

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
  TimeService timeService;
  LightController lightController;

  for(vector<ScheduledLightEvent>::iterator it = scheduledLightEvents.begin();
      it != scheduledLightEvents.end(); it++)
    {
      if((it->day == timeService.getTime().dayOfWeek ||
	  it->day == Everyday) &&
	 it->minuteOfDay == timeService.getTime().minuteOfDay)
	{
	  lightController.turnOn(it->id);
	}
    }
}

