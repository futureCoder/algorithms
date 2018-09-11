/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 || j == 0)
                {
                    ret[i][j] = 1;
                    continue;
                }
                ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
            }
        }
        return ret[m - 1][n - 1];
    }
};