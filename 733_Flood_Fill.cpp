#include <iostream>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& image,int sr, int sc, int color, int m,int n){
        int initial = image[sr][sc];
        if (initial == color) return;
        image[sr][sc] = color;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            pair<int, int> l = {temp.first, temp.second - 1};
            pair<int, int> r = {temp.first, temp.second + 1};
            pair<int, int> t = {temp.first - 1, temp.second};
            pair<int, int> d = {temp.first + 1, temp.second};

            if(l.second >= 0 && image[l.first][l.second] == initial){
                image[l.first][l.second] = color;
                q.push(l);
            }
            if(r.second < n && image[r.first][r.second] == initial){
                image[r.first][r.second] = color;
                q.push(r);
            }
            if(t.first >= 0 && image[t.first][t.second] == initial){
                image[t.first][t.second] = color;
                q.push(t);
            }
            if(d.first < m && image[d.first][d.second] == initial){
                image[d.first][d.second] = color;
                q.push(d);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.empty() || image[0].empty()) return image;
        int m = image.size();
        int n = image[0].size();
        bfs(image, sr, sc, color, m, n);
        return image;
    }
};

int main()
{

    return 0;
}