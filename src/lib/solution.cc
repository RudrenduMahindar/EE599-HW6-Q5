#include "solution.h"
#include <stack>
#include <iostream>
#include <queue>

bool helper_BFS(int start,int end,int num_vertices,vector<vector<int>>& adj_vec)
{
  if(start==end)
    return true;
  vector<bool> visited_node(num_vertices,false); 
  queue<int> q;
  visited_node[start]=true;
  q.push(start);
  while(!q.empty())
  {
    start=q.front();
    q.pop();
    for(auto it=adj_vec[start].begin();it!=adj_vec[start].end();it++)
    {
      if(*it==end)
        return true;
      if(!visited_node[*it])
      {
        visited_node[*it]=true;
        q.push(*it);
      }  
    }
  }
  return false;
}
bool is_in_range(int i,int j,int max_limit,vector<vector<int>>& maze)
{
  if((i<0 || i>=max_limit) || (j<0 || j>=max_limit) || (maze[i][j]==0))
    return false;
  return true;  
}
bool Graph::check_path(pair<int,int> start, pair<int,int> end, vector<vector<int>>& maze)
{
  int source,dest;
  int n=maze.size();
  int num_vertices=(n*n)+2;
  vector<vector<int>> adj_vec(num_vertices);
  //Graph g(num_vertices);
  maze[start.first][start.second]=2; //start from 2
  maze[end.first][end.second]=3; //end at 3
  int vertex_num=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(maze[i][j]!=0)
      {
        if(is_in_range(i,j+1,n,maze))
          adj_vec[vertex_num].push_back(vertex_num+1);
        if(is_in_range(i,j-1,n,maze))
          adj_vec[vertex_num].push_back(vertex_num-1);
        if(j < n-1 && is_in_range(i+1,j,n,maze)) 
          adj_vec[vertex_num].push_back(vertex_num+n); 
        if(i > 0 && is_in_range(i-1,j,n,maze)) 
          adj_vec[vertex_num].push_back(vertex_num-n);     
      }   
      if(maze[i][j]==2)
        source=vertex_num;
      if(maze[i][j]==3)
        dest=vertex_num;
      
      vertex_num++ ;   
    }
  }
return helper_BFS(source,dest,num_vertices,adj_vec);  
}


/*vector<int> Graph::DFS(int root,vector<bool>& visited_nodes)
{
  vector<int> visit_dfs;
  stack<int> s;
  s.push(root);
  while(!s.empty())
  {
    int i=s.top();
    //cout<<"top ="<<i<<" ";
    s.pop();
    if(visited_nodes[i])
      continue;
    visited_nodes[i]=true;
    visit_dfs.push_back(i);
    auto it=v_.find(i);
    //set<int> neighbours;
    //neighbours=it->second;
    for(auto it1=(it->second).rbegin();it1!=(it->second).rend();it1++)
    {
      if(!visited_nodes[*it1])
      {  
        //cout<<"visit ="<< *it1 <<" ";
        s.push(*it1);
      }
    }
  }
  return visit_dfs;
}*/

