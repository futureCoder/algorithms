#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int desk[50005];

struct Pep
{
	int num;
	int price;
	bool operator< (const Pep &b) const {
		if(price != b.price)
			return price > b.price;
		return num < b.num;
	}
	void get() {
		scanf("%d%d", &num, &price);
	}
}pep[50005];

int main() {
	int n, m;
	while(~scanf("%d%d",&n, &m)) {
		for(int i = 0; i < n; ++i) 
			scanf("%d", &desk[i]);
		for(int i = 0; i < m; ++i)
			pep[i].get();
		multiset<int> dsize;
		sort(pep, pep + m);
		long long ans = 0;
		for(int i = 0; i < m; ++i) {
			auto it = dsize.lower_bound(pep[i].num);
			if(it == dsize.end())
				continue;
			while(it != dsize.begin() && *it > pep[i].num)
				--it;
			while(it != dsize.end() && *it < pep[i].num)
				++it;
			if(it == dsize.end())
				--it;
			if(it != dsize.end()) {
				ans += pep[i].price;
				dsize.erase(it);
			}
		}
		printf("%lld\n", and);
		return 0;
	}
}