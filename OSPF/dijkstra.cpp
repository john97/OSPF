#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cmath>
#include <ctime>
using namespace std;
#define INF INT_MAX //Infinity

const int sz=10001;
int parent[10001];
vector<pair<int,int> > a[sz]; //Adjacency list



int dis[sz][sz]; //Stores shortest distance
 void Dijkstra(int source, int n) //Algorithm for SSSP
{
    bool vis[sz]={0};
    
    for(int i=0;i<sz;i++)
        dis[source][i]=INF;
    
    for(int i=1;i<=n;i++)
    {
        parent[i]=source;
    }
    
    priority_queue< pair<int,int>,vector<pair<int,int> >,greater< pair<int,int> > > pq;
    for(int i=0;i<n;i++)
    {
        if(dis[source][i]>0)
        pq.push(make_pair(dis[source][i],i));
    }
    pq.push(make_pair(dis[source][source]=0,source));
    
    while(!pq.empty())
    {
        
        pair<int, int> curr=pq.top(); //Current vertex. The shortest distance for this has been found
        pq.pop();
        int cv=curr.second,cw=curr.first; //'cw' the final shortest distance for this vertex
    if(vis[cv])
            continue;
        
        vis[cv]=true;
        
        
        for(int i=0;i<a[cv].size();i++)         {
            if(a[cv][i].second+cw<dis[source][a[cv][i].first])
            {
                dis[source][a[cv][i].first]=a[cv][i].second+cw;
                dis[a[cv][i].first][source]=a[cv][i].second+cw;
                if(!vis[a[cv][i].first] )
                    pq.push(make_pair(dis[source][a[cv][i].first],a[cv][i].first)); //Set the new distance and add to priority queue
                    
                parent[a[cv][i].first]=curr.second;
                    
            }
        }
        
        
    }
}










int main() {
    int n,m,x,y,w,j,i,k;//Number of vertices and edges
        clock_t start, end;
        double msecs;
    cout<<"Enter number of vertices and edges in the graph\n";
    
    cin>>n>>m;
    
    for(i=0;i<m;i++) //Building Graph
    {
        cin>>x>>y>>w; //Vertex1, Vertex2, weight of edge
        a[x].push_back(make_pair(y,w));
        a[y].push_back(make_pair(x,w));
    }
    
    
    //cout<<"Enter source for Dijkstra's SSSP algorithm\n";
start = clock();
    for(j=1;j<=n;j++)
    {
        Dijkstra(j,n);
       
        
    }
    
    end = clock();
    msecs = ((double) (end - start))  / CLOCKS_PER_SEC;
    cout <<msecs<<endl;
    return 0;
}

