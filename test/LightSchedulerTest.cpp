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
  //! -# Set values in spy (fake) instance
  timeServiceFake.setMinute(42);
  timeServiceFake.setDay(Saturday);

  //! -# Get the values from the real instance and verify they match those set by the spy (fake) instance.
  EXPECT_EQ(42, timeServiceReal.getTime().minuteOfDay);
  EXPECT_EQ(Saturday, timeServiceReal.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, ControllerSetStaticAccessTurnOn)
{
  //! -# Set values in the real instance.
  lightControllerReal.turnOn(3);

  //! -# Read the values through the spy (fake) instance and verify they match those set by the real instance.
  EXPECT_EQ(3, lightControllerFake.getLastId());
  EXPECT_EQ(LightStateOn, lightControllerFake.getLastState());
}

TEST_F(LightSchedulerTest, ControllerSetStaticAccessTurnOff)
{
  //! -# Set values in the real instance.
  lightControllerReal.turnOff(3);

  //! -# Read the values through the spy (fake) instance and verify they match those set by the real instance.
  EXPECT_EQ(3, lightControllerFake.getLastId());
  EXPECT_EQ(LightStateOff, lightControllerFake.getLastState());
}
