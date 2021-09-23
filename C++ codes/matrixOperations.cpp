#include <iostream>
using namespace std;
int main(){
    int mat[4][4]={1,0,3,0,0,6,0,8,0,10,0,0,0,14,15,0},count=0;
    cout<<endl<<"Given Matrix:"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (mat[i][j]!=0)
            count++;
        }
    }
    cout<<endl<<"No. of non-zero elements: "<<count<<endl;
    int sparse[count][3],x=1;
    sparse[0][0]=4;
    sparse[0][1]=4;
    sparse[0][2]=count;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (mat[i][j]!=0){
                sparse[x][0]=i;
                sparse[x][1]=j;
                sparse[x][2]=mat[i][j];
                x++;
            }
        }
    }
    cout<<endl<<"Sparse Matrix:"<<endl;
    for(int i=0;i<count+1;i++){
        for(int j=0;j<3;j++)
        cout<<sparse[i][j]<<"\t";
        cout<<endl;
    }
return 0;
}