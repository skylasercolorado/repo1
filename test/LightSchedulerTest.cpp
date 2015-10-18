#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "LightScheduler.hpp"
#include "LightController.hpp"
#include "ITimeService.hpp"

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
      LightController lightController;
    }

    virtual void TearDown()
    {

    }


  private:
};

TEST(LightSchedulerTest, NoChangeToLightsDuringInitialization)
{
  EXPECT_EQ(LightIdUnknown, lightController.GetLastId());
  EXPECT_EQ(LightStateUnknown, lightController.GetLastState());
}

//TEST(LightSchedulerTest, ScheduleOnEveryDayNotTimeYet)
//{
//
//  lightScheduler.ScheduleTurnOn(3, EveryDay, 1200);
//
//  TimeService ts;
//  ts.SetDay(Monday);
//  ts.SetMinute(1199);
//
//  ls.WakeUp();
//
//  LightController lcs;
//
//  EXPECT_EQ(LightIdUnknown, lcs.GetLastId());
//  EXPECT_EQ(LightStateUnknown, lcs.GetLastState());
//}
