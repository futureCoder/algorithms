class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        map<char, int> mymap;
        for(auto i : A)
            ++mymap[i];
        for(auto i : B) {
            if(mymap[i] == 0)
                return false;
            --mymap[i];
        }
        return true;
    }
};