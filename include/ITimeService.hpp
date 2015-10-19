#ifndef CAMAX_ITIMESERVICE_HPP
#define CAMAX_ITIMESERVICE_HPP

namespace Camax
{
  class ITimeService
  {
    virtual int getTime() = 0;
    virtual void getPeriodicAlarm() = 0;
  };
}

#endif // CAMAX_ITIMESERVICE_HPP
