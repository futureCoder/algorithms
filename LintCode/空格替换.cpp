class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        if(0 == length)
            return 0;
        int blank = 0;
        char *prev = string;
        while('\0' != *prev) {
            if(' ' == *prev++)
                ++blank;
        }
        length += 2 * blank;
        char *last = prev + 2 * blank;
        while(prev != last) {
            if(' ' == *prev) {
                *last-- = '0';
                *last-- = '2';
                *last-- = '%';
                --prev;
            }
            else {
                *last-- = *prev--;
            }
        }
        return length;
    }
};  