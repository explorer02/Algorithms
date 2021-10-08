#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,x,y;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){
      cin>>a[i][j];
     }
    }
    cin>>x>>y;
    int b[x][y];
    for(int i=0;i<x;i++){
     for(int j=0;j<y;j++){
      cin>>b[i][j];
     }
    }
    if(n==x){
      int mat[m][y];
      memset(mat,0,sizeof(mat));
      for(int i=0;i<m;i++){
       for(int j=0;j<y;j++){
       for(int k=0;k<n;k++)  mat[i][j]+=(a[i][k]*b[k][j]);
       }
      }
      cout<<"\nAnswer \n";
      for(int i=0;i<m;i++){
     for(int j=0;j<y;j++){
      cout<<mat[i][j]<<" ";
     }cout<<endl;
    }
    }
    else{
     cout<<"\nNot Possible\n";
    }
    return 0;
}
