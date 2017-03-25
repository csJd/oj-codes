#include<cstdio>
using namespace std;

bool solve(int &w)
{
    int wl, dl, wr, dr;
    bool mobl = true, mobr = true;
    scanf("%d %d %d %d", &wl, &dl, &wr, &dr);
    if(!wl) mobl = solve(wl);
    if(!wr) mobr = solve(wr);
    w = wl + wr;
    return mobl && mobr && (wl * dl == wr * dr);
}

int main()
{
    int cas, w;
    scanf("%d", &cas);
    while(cas--)
    {
        printf(solve(w) ? "YES\n" : "NO\n");
        if(cas) printf("\n");
    }
    return 0;
}
