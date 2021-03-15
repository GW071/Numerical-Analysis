#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define abs(x) (x>0?x:-x)
int main_gauss(vector<vector<double> >& A,vector<double>& res);
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
    if(main_gauss(A,res)){
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
int main_gauss(vector<vector<double> >& A,vector<double>& res)
{
    int n=A.size();
    for(int i=0;i<n;i++){
        double max=0;
        int index=n-1;
        for(int j=i;j<n;j++){
            if(abs(A[j][i])>max){
                max=abs(A[j][i]);
                index=j;
            }
        }
        double temp;
        for(int j=i;j<n+1;j++){
            temp=A[i][j];
            A[i][j]=A[index][j];
            A[index][j]=temp;
        }
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