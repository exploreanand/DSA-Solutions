#include <iostream>
#include <vector>

using namespace std;

class DSU
{
    vector<int> parents;
    vector<int> size;

public:
    DSU(int a)
    {
        size.resize(a, 1);
        parents.resize(a);
        for (int i = 0; i < a; i++)
        {
            parents[i] = i;
        }
    }

    int findParents(int u)
    {
        if (parents[u] == u)
            return u;
        return parents[u] = findParents(parents[u]);
    }

    void uniteSize(int u, int v)
    {
        int root_u = findParents(u);
        int root_v = findParents(v);
        if (root_u == root_v)
            return;
        if (size[root_u] < size[root_v])
        {
            parents[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else
        {
            parents[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A)
    {
        vector<vector<bool>> isVis(n, vector<bool>(m, false));
        int count = 0;
        vector<int> ans;
        DSU obj(n * m);

        for (const auto& [row, col] : A)
        {
            if (isVis[row][col] == false)
            {
                isVis[row][col] = true;
                count++;

                vector<int> n_row = {0, 1, 0, -1};
                vector<int> n_col = {1, 0, -1, 0};

                for (int i = 0; i < 4; i++)
                {

                    int n_r = row + n_row[i];
                    int n_c = col + n_col[i];

                    if (n_r >= 0 && n_c >= 0 && n_r < n && n_c < m && isVis[n_r][n_c])
                    {
                        int u = row * m + col;
                        int v = n_r * m + n_c;
                        if (obj.findParents(u) == obj.findParents(v))
                        {
                            continue;
                        }
                        obj.uniteSize(u, v);
                        count--;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

int main()
{

    return 0;
}