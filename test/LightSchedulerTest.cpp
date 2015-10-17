#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "LightScheduler.hpp"
#include "ILightController.hpp"
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

    }

    virtual void TearDown()
    {

    }


  private:
};


TEST(LightSchedulerTest, ScheduleOnEveryDayNotTimeYet)
{

}
