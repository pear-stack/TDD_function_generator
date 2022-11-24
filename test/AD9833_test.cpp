#include "gtest/gtest.h"

extern "C" {
#include "AD9833_driver.h"
}

TEST(t1, test1) {
  ASSERT_EQ(AD9833_ok(1, 1), 2);
}
TEST(t1, test2){
  ASSERT_EQ(AD9833_ok(1,2), 3); 
}
//55str
