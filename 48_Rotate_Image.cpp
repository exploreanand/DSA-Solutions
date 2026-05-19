#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // Transpose the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Reverse the matrix
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};
int main()
{
  Solution obj;
  vector<vector<int>> matrix(4, vector<int>(4, 0));
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[0][3] = 4;
  matrix[1][0] = 5;
  matrix[1][1] = 6;
  matrix[1][2] = 7;
  matrix[1][3] = 8;
  matrix[2][0] = 9;
  matrix[2][1] = 10;
  matrix[2][2] = 11;
  matrix[2][3] = 12;
  matrix[3][0] = 13;
  matrix[3][1] = 14;
  matrix[3][2] = 15;
  matrix[3][3] = 16;
  obj.rotate(matrix);

  for (int i = 0; i < matrix.size(); i++)
  {
    cout << "[";
    for (int j = 0; j < matrix[0].size(); j++)
    {
      cout << matrix[i][j];
      cout << ",";
    }
    cout << "]";
  }
  cout << endl;

  return 0;
}