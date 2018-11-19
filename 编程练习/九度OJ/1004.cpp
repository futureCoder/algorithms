#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,k,n,temp;
    while(~scanf("%d",&n))
    {
        vector<int> v;
        for(k=0; k<2; ++k)
        {
            if(k==1) scanf("%d",&n);
            for(j=0; j<n; ++j)
            {
                scanf("%d",&temp);
                v.push_back(temp);
            }
        }
        sort(v.begin(),v.end());
        printf("%d\n",v[(v.size()-1)/2]);
    }
}
