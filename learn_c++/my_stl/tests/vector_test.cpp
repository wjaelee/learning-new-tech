#include "vector.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace mystd {
namespace {

TEST(VectorTest, VectorLength) {
  vector<int> v(10);
  EXPECT_EQ(v.length(), 0);
}

TEST(VectorTest, VectorCapacity) {
  vector<int> v(10);
  EXPECT_EQ(v.capacity(), 10);
}

TEST(VectorTest, VectorCapacityEmpty) {
  vector<int> v;
  EXPECT_EQ(v.capacity(), 1);
}

TEST(VectorTest, VectorReserve) {
  vector<int> v;
  v.reserve(20);
  EXPECT_EQ(v.capacity(), 20);
}

TEST(VectorTest, VectorAt) {
  vector<int> v;
  v.push_back(10);
  v.push_back(15);
  EXPECT_EQ(v[0], 10);
  EXPECT_EQ(v[1], 15);
}

} // namespace
} // namespace mystd
