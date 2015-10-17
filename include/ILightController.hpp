#ifndef CAMAX_ILIGHTCONTROLLER_HPP
#define CAMAX_ILIGHTCONTROLLER_HPP

namespace Camax
{
  class ILightController
  {
    virtual void On(int id) = 0;
    virtual void Off(int id) = 0;
  };
}

#endif // CAMAX_ILIGHTCONTROLLER_HPP
