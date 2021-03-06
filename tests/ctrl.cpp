#include "gtest/gtest.h"
#include "controller.h"

class ctrlTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	ctrlTest() {
		// You can do set-up work for each test here.
	  p.StartSale(); // we have access to p, declared in the fixture
	}

	virtual ~ctrlTest() {
		// You can do clean-up work that doesn't throw exceptions here.
	  p.EndSale(100000.0000);
  }

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).

	}

	// Objects declared here can be used by all tests in the test case for Project1.
	Controller p;
};

TEST_F(ctrlTest, StartSale) {
  EXPECT_TRUE(p.OnScannedItem("0000000001"));
}

TEST_F(ctrlTest, DiscountReq) {
  EXPECT_TRUE(p.OnReqDiscount("1234567890"));
  EXPECT_FALSE(p.OnReqDiscount("1234567891"));
}
