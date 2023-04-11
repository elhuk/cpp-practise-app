#include <gtest/gtest.h>

class Math{

  public:

    template<typename T>
    T add (T numX, T numY){
      return numX + numY;
    }
};

class TestFixture : public testing::Test{

  public:

    Math math;
};


TEST_F(TestFixture, add_function_should_add_two_integer_numbers) {
  EXPECT_EQ(math.add(2, 4), 6);
}

TEST_F(TestFixture, add_function_should_add_two_real_numbers) {
  EXPECT_EQ(math.add(2.5, 2.5), 5.0);
}