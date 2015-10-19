#ifndef CAMAX_LIGHTCONTROLLER_HPP
#define CAMAX_LIGHTCONTROLLER_HPP

#include "ILightController.hpp"

namespace Camax
{
  enum LightStatus
  {
    LightIdUnknown = -1,
    LightStateUnknown = -2
  };

  class LightController : public ILightController
  {
    void On(int id);
    void Off(int id);
  };
}

#endif // CAMAX_LIGHTCONTROLLER_HPP
