class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size();
        bool ret = false;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) 
                if(board[i][j] == word[0]) {
                    ret |= BFS(board, word, i, j, 0);
                    if(ret)
                        return ret;
                }
                else
                    continue;
        return ret;
    }
    bool BFS(vector<vector<char>>& board, const string &word, const int &i, const int &j, const int &word_idx) {
        if(word_idx >= word.size() - 1)
            return true;

        const int m = board.size(), n = board[0].size();
        typedef pair<int, int> state_t;
        queue<state_t> q;
        bool ret = false;

        auto state_is_valid = [&](const state_t &t) {
            const int x = t.first, y = t.second;
            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[word_idx + 1])
                return false;
            return true;
        };
        auto state_expand = [&](const state_t &t) {
            const int x = t.first, y = t.second;
            vector<state_t> vec;
            state_t ex[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
            for(int i = 0; i < 4; ++i) {
                if(state_is_valid(ex[i])) {
                    vec.push_back(ex[i]);
                }
            }
            return vec;
        };

        state_t cur = {i, j};
        auto ex = state_expand(cur);
        for(auto i : ex)
            q.push(i);

        auto tmp = board[i][j];
        board[i][j] = 0;

        while(!q.empty()) {
            auto k = q.front();
            q.pop();
            ret |= BFS(board, word, k.first, k.second, word_idx + 1);
        }
        board[i][j] = tmp;
        return ret;
    }
};