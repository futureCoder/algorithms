class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int ret = 0;
        for(int i = 0; i < m; ++i)
        	for(int j = 0; j < n; ++j) {
        		if(1 == grid[i][j]) {
        			++ret;
        			BFS(grid, i, j);
        		}
        	}
    	return ret;
    }
    int BFS(vector<vector<char>>& grid, int i, int j) {
    	typedef std::pair<int, int> state_t;
    	std::queue<state_t> q;

    	const int m = grid.size(), n = grid[0].size();
    	auto is_state_valid = [&](const state_t &t) {
    		const int x = t.first, y = t.second;
    		if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
    			return false;
    		return true;
    	};
    	auto state_expand = [&](const state_t &t) {
    		const int x = t.first, y = t.second;
    		state_t ex[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
    		for(int i = 0; i < 4; ++i)
    			if(is_state_valid(ex[i]))
    				q.push(ex[i]);
    	}
    	grid[i][j] = 2;
    	state_expand({i, j});
    	while(!q.empty()) {
    		auto cur = q.front();
    		q.pop();
    		BFS(grid, q.first, q.second);
    	}
    }
};