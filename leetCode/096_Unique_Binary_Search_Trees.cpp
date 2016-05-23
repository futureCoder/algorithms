class Solution {
public:
    int numTrees(int n) {
        long long up = 1, down = 1, k = 2 * n;
        for(int i = 0; i < n; ++i)
        {
            down *= (n - i);
            up *= (k - i);
            if(up % down == 0)
            {
                up /= down;
                down = 1;
            }
        }
        return (int)(up / (n + 1));
    }
};