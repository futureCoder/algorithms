#include "stdafx.h"
#include "file_1.h"
#include "BaseClass.h"
//#include "FriendClassTest.h"

class A
{
public:
    A() {
        cout << "Construct A" << endl;
    }
    ~A()
    {
        cout << "De construct A" << endl;
    }
    A(const A& val)
    {
        cout << "Copy Construct A" << endl;
    }
protected:
private:
};

class B
{
public:
    B() {
        cout << "Construct B" << endl;
    }
    ~B()
    {
        cout << "De construct B" << endl;
    }
protected:
private:
};

class C
{
public:
    C(A vala, B valb){
        a = vala;
        b = valb;
    }
private :
    A a;
    B b;

};

enum eBattleCardIDParamDef
{
    eCUR_CARD_ID_OFFSET = (16 * 0),
    eBattleCard_ID_1_OFFSET = (16 * 1),
    eBattleCard_ID_2_OFFSET = (16 * 2),
    eBattleCard_ID_3_OFFSET = (16 * 3),
    eMASK = 0xffff,
};

unsigned short GetValue(unsigned long long val, unsigned long long mask, int offset)
{
    mask <<= offset;
    val = (val & mask) >> offset;
    return (unsigned short)val;
}

int main()
{
    unsigned long long val = 0;
    while (cin >> val)
    {
        cout << GetValue(val, eMASK, eCUR_CARD_ID_OFFSET) << endl;
        cout << GetValue(val, eMASK, eBattleCard_ID_1_OFFSET) << endl;
        cout << GetValue(val, eMASK, eBattleCard_ID_2_OFFSET) << endl;
        cout << GetValue(val, eMASK, eBattleCard_ID_3_OFFSET) << endl;
    }
   /* A a;
    B b;
    C c(a, b);*/
}