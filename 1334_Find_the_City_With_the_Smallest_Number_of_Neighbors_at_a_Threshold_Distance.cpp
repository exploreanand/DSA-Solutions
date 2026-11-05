#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Because we have to find distance from every city to every other city.
        vector<vector<int>> d_matrix(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++){
            d_matrix[i][i] = 0;
        }

        for(auto& it : edges){
            int u = it[0], v = it[1], w = it[2];
            d_matrix[u][v] = w;
            d_matrix[v][u] = w;
        }

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    d_matrix[i][j] = min(d_matrix[i][j], (d_matrix[i][via] + d_matrix[via][j]));
                }
            }
        }

        pair<int, int> min_city = {-1, INT_MAX};  // Initialised as -1 for none and INT_MAX for infinite neighbours
        
        // Now the final matrix is ready
        for(int i = 0; i < n; i++){
            int city = i;
            int neighbours = 0;
            for(int j = 0; j < n; j++){
                if(i != j && d_matrix[i][j] <= distanceThreshold){
                    neighbours++;
                }
            }
            if(neighbours <= min_city.second){
                min_city.second = neighbours;
                min_city.first = city;
            }
        }

        return min_city.first;
    }
};

int main()
{

    return 0;
}