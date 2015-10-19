#ifndef CAMAX_LIGHTCONTROLLER_HPP
#define CAMAX_LIGHTCONTROLLER_HPP

#include "ILightController.hpp"

namespace Camax
{
  enum LightStatus
  {
    LightIdUnknown 	= -1,
    LightStateUnknown 	= -2,
    LightStateOn 	= 1,
    LightStateOff 	= 2
  };

  class LightController : public ILightController
  {
    public:
      //LightController() : lastId(LightIdUnknown), lastState(LightStateUnknown) {}
      void turnOn(int id);
      void turnOff(int id);
      // The actual mock starts from hereon forward
      static int getLastId();
      static int getLastState();

    private:
      static int lastId;
      static int lastState;
  };
}

#endif // CAMAX_LIGHTCONTROLLER_HPP
