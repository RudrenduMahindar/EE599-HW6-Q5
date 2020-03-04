#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Graph {
public:
  //Graph(int num_vertices):v_(num_vertices){}
  //int v_;
  bool check_path(pair<int,int> start, pair<int,int> end, vector<vector<int>>& maze);
};

#endif