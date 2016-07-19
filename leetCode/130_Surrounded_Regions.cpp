class Solution {
public:
    void solve(vector<vector<char>>& board) {
    	if(board.empty()) return;
        const int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
        	BFS(board, i, 0);
        	BFS(board, i, n - 1);
        }
        for(int j = 1; j < n - 1; ++j) {
        	BFS(board, 0, j);
        	BFS(board, m - 1, j);
        }
        for(int i = 0; i < m; ++i)
        	for(int j = 0; j < n; ++j)
        		if(board[i][j] == '*')
        			board[i][j] = 'O';
        		else 
        			board[i][j] = 'X';
    }	

    void BFS(vector<vector<char>>& board, int i, int j) {
    	typedef pair<int, int> state_t;
    	queue<state_t> q;
    	const int m = board.size(), n = board[0].size();

    	auto state_is_valid = [&](const state_t &t) {
    		const int x = t.first, y = t.second;
    		if(x < 0 || y < 0 || x >= m || y >=n || board[x][y] != 'O')
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