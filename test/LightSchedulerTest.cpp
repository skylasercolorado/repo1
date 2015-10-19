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

    LightController lightController;
    TimeService timeService;
};

TEST_F(LightSchedulerTest, NoChangeToLightsDuringInitialization)
{
  EXPECT_EQ(LightIdUnknown, lightController.getLastId());
  EXPECT_EQ(LightStateUnknown, lightController.getLastState());
}

TEST_F(LightSchedulerTest, Create)
{
  EXPECT_EQ(TimeUnknown, timeService.getTime().minuteOfDay);
  EXPECT_EQ(TimeUnknown, timeService.getTime().dayOfWeek);
}
