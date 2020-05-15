#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m,p;
int q[1000000];
int32_t main()
{
    freopen("REC.INP","r",stdin);
    freopen("REC.OUT","w",stdout);
    scanf("%lld%lld%lld", &n, &m, &p);
    int ans=0;
    if (p%2!=0) p++;
    p/=2;
    for (int i=1;i<=999999;i++) q[i]=q[i-1]+i;
    int x,y,u,v;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {

            if (i+p-1>n) {
                x=n;
                y=j+p-(n-i);
            } else {
                x=i+p-1;
                y=j+1;
            }
            if (x>n || y>m) break;
           // if (y>m || (y-j)+(x-i)<p) break;
            if (j+p-1>m) {
                v=m;
                u=i+p-(m-j);

            } else {
                u=i+1;
                v=j+p-1;
            }
            if (u>n || v>m) break;
            //if (u>n || (u-i)+(v-j)<p) break;
            //int r=0;
          //  if (n-x-1>0) r=q[n-x-1];
            ans+=(q[n-u+1]-q[n-x]+(m-v)*(n-u+1));

        }
    }
    cout<<ans;
    return 0;
}