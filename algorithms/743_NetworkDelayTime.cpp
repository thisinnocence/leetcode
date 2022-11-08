#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int networkDelayTime(vector<vector<int>> &times, int n, int K)
    {
        // 最大值经典数字
        const int INF = 0x3f3f3f3f;

        // 有向图, 构建邻接矩阵
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
        for (auto &v: times) {
            graph[v[0]][v[1]] = v[2];
        }

        // 点编号1~n, 为了使下标和点的编号对应, 设置n+1大小的vector
        vector<int> distance(n + 1, INF); // 距离起始点的最短距离，全部初始化为INF
        vector<bool> visited(n + 1, false); // 是否已经得到最优解

        distance[K] = 0; // 起始点
        for (int i = 0; i < n - 1; i++) { // 每次松弛1个点, 共n个点循环n次
            // 在还未确定最短路的点中，寻找到起始点距离最小的点
            int t = -1;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && (t == -1 || distance[t] > distance[j])) {
                    t = j;
                }
            }
            visited[t] = true; // t号点的最短路已经确定

            for (int j = 1; j <= n; j++) { // 用t更新其他点的距离
                distance[j] = min(distance[j], distance[t] + graph[t][j]);
            }
        }

        // 路径即为K到所有其他点最短路里的最大的距离
        int ans = *max_element(distance.begin() + 1, distance.end());
        return ans == INF ? -1 : ans;
    }
};

