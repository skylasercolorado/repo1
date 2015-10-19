#ifndef CAMAX_ILIGHTCONTROLLER_HPP
#define CAMAX_ILIGHTCONTROLLER_HPP

namespace Camax
{
  class ILightController
  {
    virtual void turnOn(int id) = 0;
    virtual void turnOff(int id) = 0;
  };
}

#endif // CAMAX_ILIGHTCONTROLLER_HPP
