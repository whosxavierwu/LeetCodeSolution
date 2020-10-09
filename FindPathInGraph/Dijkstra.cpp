#include <vector>
#include <set>
using namespace std;

void dijkstra(vector<vector<int>>& a, int p){
    int n = a.size();
    vector<int> d(n);  // shortest path from p to i
    vector<bool> visited(n, false);
    visited[p] = true;
    int visited_cnt = 1;
    for (int i = 0; i < n; ++i){
        d[i] = a[p][i];
    }
    while (visited_cnt < n){
        int min_dist = INT_MAX;
        int closest_point = 0; 
        for (int i = 0; i < n; ++i){
            if (!visited[i] && d[i] < min_dist){
                min_dist = d[i];
                closest_point = i;
            }
        }
        for (int i = 0; i < n; ++i){
            if (!visited[i]){
                d[i] = min(d[i], d[closest_point] + a[closest_point][i]);
            }
        }
        visited[closest_point] = true;
        visited_cnt++;
    }
}