#include "LightController.hpp"

using namespace Camax;
using Camax::LightController;

void LightController::turnOn(int id)
{
  lastId = id;
  lastState = LightStateOn;
}

void LightController::turnOff(int id)
{
  lastId = id;
  lastState = LightStateOff;
}

int LightController::getLastId()
{
  return lastId;
}

int LightController::getLastState()
{
  return lastState;
}
