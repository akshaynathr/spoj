#include <iostream>
using namespace std;


int h , w = 0;
char mat[51][51];
int dist[51][51];


int dim[8][2] = { 
        { -1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1},
        };


void dfs(int i, int j , int dis){
    dist[i][j] = dis + 1;
    
    for(auto d: dim){
        int x = d[0] + i;
        int y = d[1] + j;
        if(x >= 0 && y >= 0 && x < h && y <w) { 
            if(mat[x][y] == mat[i][j] +1 && dist[x][y] < dist[i][j] +1 ){
                dfs(x,y,dis+1);
            }
        }
    }

}


int main(){
    int tc =0 ;
                int maxV =0;

    while(true) {

        cin>>h>>w;
        if(h == 0 && w ==0 ) break;
        tc++;
        for(int i=0;i<h;i++){
            cin>>mat[i];
            for(int j=0;j<w;j++){
                dist[i][j] =0;
            }
        }

        for(int i =0;i<h; i++){
            for(int j=0;j<w;j++){
                if(mat[i][j] == 'A' && dist[i][j] == 0){
                    dfs(i,j,0);
                }
            }
        }

        maxV = dist[0][0];
        for(int i =0; i<h; i++){
            for(int j=0;j<w;j++){
                maxV = max(maxV, dist[i][j]);
            }
        }
        cout << "Case " << tc << ": " << maxV << endl;

    }

    return 0;
}