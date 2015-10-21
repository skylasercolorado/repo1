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
      cout << "day: " << it->day << "\n";
      cout << "minuteOfDay: " << it->minuteOfDay << "\n";
      cout << "timeService.getTime().dayOfWeek: " << timeService.getTime().dayOfWeek << "\n";
      cout << "timeService.getTime().minuteOfDay: " << timeService.getTime().minuteOfDay << "\n";
      if((it->day == timeService.getTime().dayOfWeek ||
	  it->day == Everyday) &&
	 it->minuteOfDay == timeService.getTime().minuteOfDay)
	{
	  cout << "id: " << it->id << "\n";
	  lightController.turnOn(it->id);
	}
    }
}

