#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "LightScheduler.hpp"
#include "LightController.hpp"
#include "TimeService.hpp"

using namespace Camax;
using namespace std;

class LightSchedulerTest : public ::testing::Test
{
  public:
    LightSchedulerTest()
      {

      }

    virtual void SetUp()
    {

    }

    virtual void TearDown()
    {

    }

    LightController lightControllerFake;
    TimeService timeServiceFake;

    LightController lightControllerReal;
    TimeService timeServiceReal;

};

TEST_F(LightSchedulerTest, NoChangeToLightsDuringInitialization)
{
  EXPECT_EQ(LightIdUnknown, lightControllerFake.getLastId());
  EXPECT_EQ(LightStateUnknown, lightControllerFake.getLastState());
}

TEST_F(LightSchedulerTest, Create)
{
  EXPECT_EQ(TimeUnknown, timeServiceFake.getTime().minuteOfDay);
  EXPECT_EQ(TimeUnknown, timeServiceFake.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, Set)
{
  timeServiceFake.setMinute(42);
  timeServiceFake.setDay(Saturday);

  EXPECT_EQ(42, timeServiceFake.getTime().minuteOfDay);
  EXPECT_EQ(Saturday, timeServiceFake.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, TimeSetStaticAccess)
{
  timeServiceFake.setMinute(42);
  timeServiceFake.setDay(Saturday);

  EXPECT_EQ(42, timeServiceReal.getTime().minuteOfDay);
  EXPECT_EQ(Saturday, timeServiceReal.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, ControllerSetStaticAccessTurnOn)
{
  lightControllerReal.turnOn(3);

  EXPECT_EQ(3, lightControllerFake.getLastId());
  EXPECT_EQ(LightStateOn, lightControllerFake.getLastState());
}

TEST_F(LightSchedulerTest, ControllerSetStaticAccessTurnOff)
{
  lightControllerReal.turnOff(3);

  EXPECT_EQ(3, lightControllerFake.getLastId());
  EXPECT_EQ(LightStateOff, lightControllerFake.getLastState());
}
