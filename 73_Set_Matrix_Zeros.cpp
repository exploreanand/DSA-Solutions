#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> rc;
    for (int i = 0; i < m; i++)
    {
      int j = 0;
      do {
        if (matrix[i][j] == 0)
        {
          rc.emplace_back(i,j);
        }
        j++;
      }
      while (j < n);
    }
    for (auto &p: rc){
      int row = p.first;
      int col = p.second;
      for (int i = 0; i < n; i++)
      {
        matrix[row][i] = 0;
      }
      for (int i = 0; i < m; i++)
      {
        matrix[i][col] = 0;
      }
    }
  }
};
int main()
{
  Solution obj;
  vector<vector<int>> matrix(3, vector<int>(3, 0));
  matrix[0][0] = 1;
  matrix[0][1] = 1;
  matrix[0][2] = 1;
  matrix[1][0] = 1;
  matrix[1][1] = 0;
  matrix[1][2] = 1;
  matrix[2][0] = 1;
  matrix[2][1] = 1;
  matrix[2][2] = 1;
  obj.setZeroes(matrix);

  for (int i = 0; i < matrix.size(); i++)
  {
    cout<<"[";
    for (int j = 0; j < matrix[0].size(); j++)
    {
      cout<<matrix[i][j];
    }
    cout<<"]";

  }
  cout<<endl;

  return 0;
}