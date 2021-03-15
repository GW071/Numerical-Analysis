#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int crout(vector<vector<double> >& A,vector<double> &b,vector<double>& res);
int main(){
    int n; 
    cout<<"Please enter the order of the matrix"<<endl;
    cin>>n;
    vector<vector<double> > A(n,vector<double>(n));
    cout<<"Please enter A:"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    cout<<"Please enter b:"<<endl;
    vector<double> b(n);
    for(int i=0;i<n;i++)
        cin>>b[i];
    vector<double> res(n);
    if(crout(A,b,res)){
        cout<<"ok,the res is:"<<endl;
        for(int i=0;i<n;i++)
            cout<<res[i]<<endl;
    }
    else {
        cout<<"Error! this is a singular matrix"<<endl;
    }
    system("PAUSE");
    return 0;
}
int crout(vector<vector<double> >& A,vector<double> &b,vector<double>& res){
    int n=A.size();
    for(int k=0;k<n;k++){
        for(int i=k;i<n;i++){
            double s1=0;
            for(int t=0;t<k;t++)
                s1+=A[i][t]*A[t][k];
            A[i][k]-=s1;
        }
        if(A[k][k]<0.0000001&&A[k][k]>-0.0000001)
            return 0;
        double l=1/A[k][k];
        for(int j=k+1;j<n;j++){
            double s2=0;
            for(int t=0;t<k;t++)
                s2+=A[k][t]*A[t][j];
            A[k][j]=(A[k][j]-s2)*l;
        }
    }
    vector<double> y(n);
    for(int i=0;i<n;i++){
        double s3=0;
        for(int t=0;t<i;t++)
            s3+=A[i][t]*y[t];
        y[i]=(b[i]-s3)/A[i][i];
    }
    for(int i=n-1;i>=0;i--){
        double s4;
        for(int t=i+1;t<n;t++)
            s4+=A[i][t]*res[t];
        res[i]=y[i]-s4;
    }
}