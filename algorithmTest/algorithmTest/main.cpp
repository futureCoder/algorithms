#include "leetcode.h"
#include "algorithmsBasic.hpp"
#include "ThreadPool.h"
namespace Solution 
{
	int main()
	{
		MyLinkedList* obj = new MyLinkedList();
		cout << obj->get(0) << endl;
		obj->addAtIndex(1, 2);
		cout << obj->get(0) << endl;
		cout << obj->get(1) << endl;
		obj->addAtIndex(0, 1);
		cout << obj->get(0) << endl;
		cout << obj->get(1) << endl;
		return 0;
	}
}

int main() {
	Solution::main();
}