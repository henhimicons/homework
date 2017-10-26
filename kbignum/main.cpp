#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+19;
int a[maxn];
int solve(int l,int r,int k){
    int x = a[r-1];
    int index = l-1;
    int rr = 0;
    for (int i=l;i<r-1;i++){
        if (a[i]<=x){
            index++;
            rr++;
            swap(a[index],a[i]);
        }
    }
    swap(a[index+1],a[r]);
    index=index+1;
    if (rr==k) return x;
    else if (rr>k) solve(l,index,k);
    else solve(index,r,k-rr);
}
int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)==2){
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans = solve(0,n,k);
        printf("%d\n",ans);
    }
    return 0;
}
