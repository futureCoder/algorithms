class Solution {
public:
    int myAtoi(string str) {
        int len = str.size(), index = 0, flag = 1;
        if(len == 0) return 0;
        while(str[index] == ' ') ++index;
        if(str[index] == '+')
        	++index;
        else if(str[index] == '-')
        {
        	flag = -1;
        	++index;
        }
        int ret = 0;
        while(index < len)
        {
        	if(str[index] < '0' || str[index] > '9') break;
        	if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[index]- '0' > INT_MAX % 10)) return flag == 1 ? INT_MAX : INT_MIN;
        	ret = ret * 10 + str[index++] - '0';
        }
        return ret * flag;
    }
};