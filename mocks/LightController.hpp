#ifndef CAMAX_LIGHTCONTROLLER_HPP
#define CAMAX_LIGHTCONTROLLER_HPP

#include "ILightController.hpp"

namespace Camax
{
  enum
  {
    LightIdUnknown,
    LightStateUnknown
  };

  class LightController : ILightController
  {
    void On(int id);
    void Off(int id);
  };
}

#endif // CAMAX_LIGHTCONTROLLER_HPP
