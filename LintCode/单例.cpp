class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        return ptr;
    }
private:
	static Solution *ptr;
};

static Solution::ptr = new Solution();