/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 */
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(0 == board.size())
            return ;
        const int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i)
        {
            BFS(board, i, 0);
            BFS(board, i, n - 1);
        }
        for(int j = 1; j < n; ++j)
        {
            BFS(board, 0, j);
            BFS(board, m - 1, j);
        }
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if('O' == board[i][j])
                    board[i][j] = 'X';
                if('*' == board[i][j])
                    board[i][j] = 'O';
            }

        }
    }

    void BFS(vector<vector<char>>& board, int i, int j)
    {
        typedef pair<int, int> state_t;
        queue<state_t> q;
        const int m = board.size(), n = board[0].size();
        auto state_is_valid = [&](const state_t &t) -> bool{
            const int x = t.first, y = t.second;
            if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != 'O')
                return false;
            return true;
        };
    	auto state_expand = [&](const state_t &t) {
    		vector<state_t> result;
    		const int x = t.first, y = t.second;
    		state_t ex[4] = {{x - 1, y}, {x + 1, y}, {x, y-1}, {x, y + 1}};
    		for(int i = 0; i < 4; ++i) {
    			if(state_is_valid(ex[i])) {
    				board[ex[i].first][ex[i].second] = '*';
    				result.push_back(ex[i]);
    			}
    		}
    		return result;
    	};
    	state_t start = {i, j};
    	if(state_is_valid(start)) {
    		board[start.first][start.second] = '*';
    		q.push(start);
    	}
    	while(!q.empty()) {
    		auto cur = q.front();
    		q.pop();
    		auto ex = state_expand(cur);
    		for(auto i : ex)
    			q.push(i);
    	}
    }
};