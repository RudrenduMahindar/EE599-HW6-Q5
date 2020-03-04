#include <iostream>
#include "src/lib/solution.h"

int main()
{
    vector<vector<int>> vertices = {{1,1,0,0,0}, 
    {1,0,1,1,1},
    {1,1,0,0,1},
    {1,1,0,0,1},
    {1,1,1,1,1}};

    //vector<vector<int>> vertices = {{1,1,0,0,0},{1,1,1,1,1},{0,1,0,0,1},{1,0,0,0,0},{1,1,1,1,1}};
    Graph g;
       
    pair<int,int> start={0,0};
    pair<int,int> end={4,4};
    bool path=g.check_path(start,end,vertices);
    if(path)
        cout<<"path exists"<<endl;
    else
        cout<<"path does not exist"<<endl; 
    return EXIT_SUCCESS;
}