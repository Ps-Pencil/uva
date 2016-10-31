#include <cstdio>
#include <cstring>
#include <vector>
#include "geometry.h"
using namespace std;

int main(){
  int w,p;
  vector<pipe> pipes;
  vector<point> wells;
  while(scanf("%d %d",&w,&p)>0)
    {
      vector<int> adj[1000];
      pipes.clear();
      wells.clear();
      for(int i=0;i<w;i++)
        {
          int a,b;
          scanf("%d %d",&a,&b);
          wells.push_back(point(a,b));
        }
      for(int i=0;i<p;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        pipe x;
        x.wellno = a-1;
        x.start = wells[a-1];
        x.end = point(b,c);
        pipes.push_back(x);
      }
      for(int i=0;i<p;i++){
        for(int j=i+1;i<p;j++){
          if(pipes[i].wellno != pipes[j].wellno && intersect(pipes[i],pipes[j])){
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }
    }
}
