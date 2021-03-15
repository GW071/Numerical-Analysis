#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;
int ordered_gauss(vector<vector<double> >& A,vector<double>& res);
int main(){
    int n; 
    cout<<"Please enter the order of the matrix"<<endl;
    cin>>n;
    vector<vector<double> > A(n,vector<double>(n+1));
    cout<<"Please enter A:"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    cout<<"Please enter b:"<<endl;
    for(int i=0;i<n;i++)
        cin>>A[i][n];
    vector<double> res(n);
    if(ordered_gauss(A,res)){
        cout<<"ok,the res is:"<<endl;
        for(int i=0;i<n;i++)
            cout<<res[i]<<endl;
    }
    else {
        cout<<"error! ordered_gauss can not solve such problem"<<endl;
    }
    system("pause");
    return 0;
}
int ordered_gauss(vector<vector<double> >& A,vector<double>& res)
{
    int n=A.size();
    for(int i=0;i<n;i++){
        if(A[i][i]<0.0000001&&A[i][i]>-0.0000001)
            return 0;
        for(int j=i+1;j<n;j++){
            double m=A[j][i]/A[i][i];
            for(int k=i;k<n+1;k++){
                A[j][k]-=A[i][k]*m;
            }
        }
    }
    res[n-1]=A[n-1][n]/A[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--)
            A[i][n]-=res[j]*A[i][j];
            res[i]=A[i][n]/A[i][i];
    }
    return 1;
}