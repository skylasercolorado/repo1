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
