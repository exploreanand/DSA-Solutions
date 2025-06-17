#include <iostream>
#include <vector>
using namespace std;
class Solution {
    vector<vector<int>> result;
    int f = 0;
    int l = 0;
    int i = 0;
    int j = 0;
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
        {
            return result;
        }
        
        if (numRows == 1)
        {
            vector<int> row = {1};
            result.insert(result.begin(), row);
            return result;
        }
        
        if (numRows == 2)
        {
            vector<int> row = {1};
            result.insert(result.begin(), row);
            vector<int> row2 = {1, 1};
            result.insert(result.end(), row2);
            return result;
        }

        if (numRows > 2)
        {
            vector<int> row = {1};
            result.insert(result.begin(), row);
            vector<int> row2 = {1, 1};
            result.insert(result.end(), row2);

            void pascal(int numRows){
                vector<int> row = {1};
                result.insert(result.begin(), row);
                for (int i = 0; i < count; i++)
                {
                    /* code */
                }
                
            }
        }
        
        return result;
    }
};
int main()
{
    Solution obj;
    vector<vector<int>> result = obj.generate(2);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
