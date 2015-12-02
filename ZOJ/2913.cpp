#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
using namespace std;

typedef set<int>::iterator it;
const int N = 10000;
int dis[N], tdis[N], link[N][12];
queue<int> q;
set<int> zone;

void bfs(int o)
{
    memset(tdis, 0, sizeof(tdis));
    tdis[o] = 1;
    q.push(o);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(tdis[cur] > dis[cur]) dis[cur] = tdis[cur];
        for(int i = 1; i <= link[cur][0]; ++i)
        {
            int j = link[cur][i];
            if(tdis[j] == 0)  q.push(j), tdis[j] = tdis[cur] + 1;
        }
    }
}

int main()
{
    int cas, nz, nr, id, mz, mr, ans, t;
    scanf("%d", &cas);
    while(cas--)
    {
        zone.clear();
        memset(dis, 0, sizeof(dis));
        scanf("%d%d", &nz, &nr);
        for(int i = 1; i <= nz; ++i)
        {
            scanf("%d %d", &id, &mz);
            link[id][0] = mz;
            zone.insert(id);
            for(int i = 1; i <= mz; ++i)
                scanf("%d", &link[id][i]);
        }

        for(int i = 1; i <= nr; ++i)
        {
            scanf("%d", &mr);
            for(int j = 1; j <= mr; ++j)
            {
                scanf("%d", &t);
                bfs(t);
            }
        }

        it i = zone.begin();
        ans = *i;
        for(++i; i != zone.end(); ++i)
            if(dis[*i] < dis[ans]) ans = *i;
        printf("%d %d\n", dis[ans], ans);
    }
    return 0;
}

//
//#include<cstdio>
//#include<cstring>
//#include<queue>
//#include<set>
//using namespace std;
//
//typedef set<int>::iterator it;
//const int N = 10005;
//int dis[N], tdis[N], link[N][12];
//queue<int> q;
//set<int> zone;
//
//void bfs(int o)
//{
//    memset(tdis, 0, sizeof(tdis));
//    tdis[o] = 1;
//    q.push(o);
//    while(!q.empty())
//    {
//        int cur = q.front();
//        q.pop();
//        for(int i = 1; i <= link[cur][0]; ++i)
//        {
//            int j = link[cur][i];
//            if(!tdis[j])
//            {
//                q.push(j);
//                tdis[j] = tdis[cur] + 1;
//                if(tdis[j]>dis[j]) dis[j]=tdis[j];
//            }
//        }
//    }
//}
//
//int main()
//{
//    int cas, nz, nr, id, mz, mr, ans, t;
//    scanf("%d", &cas);
//    while(cas--)
//    {
//        zone.clear();
//        memset(dis, 0, sizeof(dis));
//        scanf("%d%d", &nz, &nr);
//        for(int i = 1; i <= nz; ++i)
//        {
//            scanf("%d %d", &id, &mz);
//            link[id][0] = mz;
//            for(int i = 1; i <= mz; ++i)
//            {
//                scanf("%d", &link[id][i]);
//                zone.insert(link[id][i]);
//            }
//        }
//        for(int i = 1; i <= nr; ++i)
//        {
//            scanf("%d", &mr);
//            for(int j = 1; j <= mr; ++j)
//            {
//                scanf("%d", &t);
//                bfs(t);
//            }
//        }
//        it i = zone.begin();
//        ans = *i;
//        for(; i != zone.end(); ++i)
//            //printf("dis[%d]=%d\n",*i,dis[*i]);
//            if(dis[*i] < dis[ans]) ans = *i;
//
//        printf("%d %d\n", dis[ans], ans);
//    }
//    return 0;
//}

/*
2
1 1
7400 0
1 7400

17 2
7400 6 7401 7402 7403 7404 7405 7406
7401 6 7412 7402 7400 7406 7410 7411
7402 5 7412 7403 7400 7401 7411
7403 6 7413 7414 7404 7400 7402 7412
7404 5 7403 7414 7415 7405 7400
7405 6 7404 7415 7407 7408 7406 7400
7406 7 7400 7405 7407 7408 7409 7410 7401
7407 4 7408 7406 7405 7415
7408 4 7409 7406 7405 7407
7409 3 7410 7406 7408
7410 4 7411 7401 7406 7409
7411 5 7416 7412 7402 7401 7410
7412 6 7416 7411 7401 7402 7403 7413
7413 3 7412 7403 7414
7414 3 7413 7403 7404
7415 3 7404 7405 7407
7416 2 7411 7412
5 7409 7408 7407 7405 7415
6 7415 7404 7414 7413 7412 7416
*/
