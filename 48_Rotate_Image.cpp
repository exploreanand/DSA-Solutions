#include <iostream>
#include <vector>
using namespace std;

// (0,0),(0,1),(0,2)
// (1,0)       (1,2)
// (2,0),(2,1),(2,2)

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    int i = 0;
    int j = 0;
    for (int c = 0; c < n / 2; c++)
    {
      i = c;
      j = c;
      for (int b = 0; b < n - 1 - 2*c; b++)
      {
        {
          int temp = matrix[i][j];
          int temp2;
          for (int a = 0; a < 4; a++)
          {
            int i2 = i;
            i = j;
            j = n - 1 - i2;

            temp2 = matrix[i][j];
            cout << temp2 << endl;
            matrix[i][j] = temp;
            cout << matrix[i][j] << endl;
            temp = temp2;
          }
        }
        i++;
      }
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