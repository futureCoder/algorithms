class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        int num1 = 0, num2 = 1, tmp;
        if (2 > n)
            return num1;
        if (2 == n)
            return num2;
        for (int i = 3; i <= n; ++i) {
            tmp = num2;
            num2 += num1;
            num1 = tmp;
        }
        return num2;
    }
};