#include<bits/stdc++.h>
using namespace std;
class Solution 
{
  public:
  int dfs(vector<vector<int>>& grid,int r,int c)
  {
      int row = grid.size();
      int col = grid[0].size();
      if(r<0 || c<0 || r>=row || c>=col || grid[r][c]==0)
      {
          return 0;
      }
      
      grid[r][c] = 0;
      
      return 1 + dfs(grid,r+1,c) + dfs(grid,r-1,c) + dfs(grid,r,c+1) + dfs(grid,r,c-1);
  }
  int findMaxArea(vector<vector<int>>& grid)
  {
      int maxArea = 0;
      int row = grid.size();
      int col = grid[0].size();
      for(int i=0;i<row;i++)
      {
          for(int j=0;j<col;j++)
          {
              if(grid[i][j]==1)
              {
                  maxArea = max(maxArea, dfs(grid,i,j));
              }
          }
      }
      return maxArea;
  }
};
int main()
{
    vector<vector<int>>grid = {
        {1,0,0,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,1}
    };
    Solution sol;
    int maxarea = sol.findMaxArea(grid);
    cout<<maxarea;
}
