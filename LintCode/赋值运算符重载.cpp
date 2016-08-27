class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        if(pData) {
            m_pData = new char[strlen(pData) + 1] ;
            strcpy(m_pData, pData);
        }
        else {
            this->m_pData = NULL;
        }
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if(this != &object) {
            Solution tmp(object.m_pData);
            char *chtmp = this->m_pData;
            this->m_pData = tmp.m_pData;
            tmp.m_pData = chtmp;
        }
        return *this;
    }
};