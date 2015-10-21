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
      LightController::reset();
    }

    virtual void TearDown()
    {

    }

    LightController lightControllerStub;
    TimeService timeServiceStub;

    LightController lightControllerReal;
    TimeService timeServiceReal;

    LightScheduler lightScheduler;
};

TEST_F(LightSchedulerTest, NoChangeToLightsDuringInitialization)
{
  EXPECT_EQ(LightIdUnknown, lightControllerStub.getLastId());
  EXPECT_EQ(LightStateUnknown, lightControllerStub.getLastState());
}

TEST_F(LightSchedulerTest, Create)
{
  EXPECT_EQ(TimeUnknown, timeServiceStub.getTime().minuteOfDay);
  EXPECT_EQ(TimeUnknown, timeServiceStub.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, Set)
{
  timeServiceStub.setMinute(42);
  timeServiceStub.setDay(Saturday);

  EXPECT_EQ(42, timeServiceStub.getTime().minuteOfDay);
  EXPECT_EQ(Saturday, timeServiceStub.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, TimeSetStaticAccess)
{
  //! -# Set values in spy (Stub) instance
  timeServiceStub.setMinute(42);
  timeServiceStub.setDay(Saturday);

  //! -# Get the values from the real instance and verify they match those set by the spy (Stub) instance.
  EXPECT_EQ(42, timeServiceReal.getTime().minuteOfDay);
  EXPECT_EQ(Saturday, timeServiceReal.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, ControllerSetStaticAccessTurnOn)
{
  //! -# Set values in the real instance.
  lightControllerReal.turnOn(3);

  //! -# Read the values through the spy (Stub) instance and verify they match those set by the real instance.
  EXPECT_EQ(3, lightControllerStub.getLastId());
  EXPECT_EQ(LightStateOn, lightControllerStub.getLastState());
}

TEST_F(LightSchedulerTest, ControllerSetStaticAccessTurnOff)
{
  //! -# Set values in the real instance.
  lightControllerReal.turnOff(3);

  //! -# Read the values through the spy (Stub) instance and verify they match those set by the real instance.
  EXPECT_EQ(3, LightController::getLastId());
  EXPECT_EQ(LightStateOff, LightController::getLastState());
  //! - Notes: I don't even need Stub objects. I can just use the the static object-less functions.
}

TEST_F(LightSchedulerTest, TimeSetStaticAccessWithoutStub)
{
  //! -# Set values in spy (Stub) instance
  //! - Yeah, I don't need Stub objects.
  TimeService::setMinute(42);
  TimeService::setDay(Saturday);

  //! -# Get the values from the real instance and verify they match those set by the spy (Stub) instance.
  EXPECT_EQ(42, timeServiceReal.getTime().minuteOfDay);
  EXPECT_EQ(Saturday, timeServiceReal.getTime().dayOfWeek);
}

TEST_F(LightSchedulerTest, ScheduleOnEverydayNotTimeYet)
{
  //! -# Set values in spy (Stub) instance
  //! - Yeah, I don't need Stub objects.
  lightScheduler.ScheduleTurnOn(3, Everyday, 1200);
  TimeService::setDay(Monday);
  TimeService::setMinute(1199);
  lightScheduler.WakeUp();

  //! -# Get the values from the real instance and verify they match those set by the spy (Stub) instance.
  EXPECT_EQ(LightIdUnknown, lightControllerStub.getLastId());
  EXPECT_EQ(LightStateUnknown, lightControllerStub.getLastState());
}

TEST_F(LightSchedulerTest, ScheduleOnEverydayItsTime)
{
  //! -# Set values in spy (Stub) instance
  //! - Yeah, I don't need Stub objects.
  lightScheduler.ScheduleTurnOn(3, Monday, 1200);
  TimeService::setDay(Monday);
  TimeService::setMinute(1200);
  lightScheduler.WakeUp();

  //! -# Get the values from the real instance and verify they match those set by the spy (Stub) instance.
  EXPECT_EQ(3, lightControllerStub.getLastId());
  EXPECT_EQ(LightStateOn, lightControllerStub.getLastState());
}


