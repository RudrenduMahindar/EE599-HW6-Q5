#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
TEST(PathTest, ReturnTrue) {
  vector<vector<int>> vertices = {{1,1,0,0,0}, 
    {1,0,1,1,1},
    {1,1,0,0,1},
    {1,1,0,0,1},
    {1,1,1,1,1}};
  Graph g;
  pair<int,int> start={0,0};
  pair<int,int> end={4,4};
  bool actual=g.check_path(start,end,vertices);
  bool expected=true;
  EXPECT_EQ(expected, actual);
}
TEST(PathTest, ReturnFalse) {
  vector<vector<int>> vertices = {{1,1,0,0,0},
  {1,1,1,1,1},
  {0,1,0,0,1},
  {1,0,0,0,0},
  {1,1,1,1,1}};
  Graph g;
  pair<int,int> start={1,2};
  pair<int,int> end={4,4};
  bool actual=g.check_path(start,end,vertices);
  bool expected=false;
  EXPECT_EQ(expected, actual);
}

