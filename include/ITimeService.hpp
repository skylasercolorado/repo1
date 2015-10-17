#ifndef CAMAX_ITIMESERVICE_HPP
#define CAMAX_ITIMESERVICE_HPP

namespace Camax
{
  class ITimeService
  {
    virtual int GetTime() = 0;
    virtual void SetPeriodicAlarm() = 0;
  };
}

#endif // CAMAX_ITIMESERVICE_HPP
