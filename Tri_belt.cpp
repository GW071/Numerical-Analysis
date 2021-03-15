#include<vector>
#include<iostream>
#include<initializer_list>
#include<stdlib.h>
using namespace std;
int max(initializer_list<int> ls);
int min(initializer_list<int> ls);
int Tri_belt(vector<vector<double> >& C,vector<double> &b,vector<double>& res,int r,int s);
int main(){
    int n,r,s; 
    cout<<"Please enter the order of the matrix"<<endl;
    cin>>n;
    cout<<"Please enter the r and s of matrix"<<endl;
    cin>>r>>s;
    if(r>=n||s>=n){
        cout<<"Error! r or s can not be bigger than n!"<<endl;
        return 0;
    }
    vector<vector<double> > C(r+s+1,vector<double>(n));
    cout<<"Please enter A:"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>C[i-j+s][j];
        }
    cout<<"Please enter b:"<<endl;
    vector<double> b(n);
    for(int i=0;i<n;i++)
        cin>>b[i];
    vector<double> res(n);
    if(Tri_belt(C,b,res,r,s)){
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
int max(initializer_list<int> ls){
    int max_=0;
    for(auto i=ls.begin();i!=ls.end();i++){
        if(max_<*i)max_=*i;
    }
    return max_;
}
int min(initializer_list<int> ls){
    int min_=100000000;
    for(auto i=ls.begin();i!=ls.end();i++){
        if(min_>*i)min_=*i;
    }
    return min_;
}
int Tri_belt(vector<vector<double> >& C,vector<double> &b,vector<double>& res,int r,int s){
    int n=b.size();
    for(int k=0;k<n;k++){
        int temp1=min({k+s+1,n});
        for(int j=k;j<temp1;j++){
            double s1=0;
            for(int t=max({0,k-r,j-s});t<k;t++)
                s1+=C[k-t+s][t]*C[t-j+s][j];
            C[k-j+s+1][j]-=s1;
        }
        int temp2=min({k+r+1,n});
        for(int i=k+1;i<temp2;i++){
            double s2=0;
            for(int t=max({0,i-r,k-s});t<k;t++)
                s2+=C[i-t+s][k]*C[t-t+s][k];
            C[i-k+s][k]=(C[i-k+s][k]-s2)/C[s][k];
        }
        for(int i=0;i<n;i++){
            for(int t=max({0,i-r});t<i;t++)
                b[i]-=b[t]*C[i-t+s][t];
        }
        for(int i=n-1;i>=0;i--){
            double s3=0;
            int temp3=min({i+s+1,n});
            for(int t=i+1;t<temp3;t++)
                s3+=C[i-t+s][t];
            res[i]=(b[i]-s3)/C[s][i];
        }
    }
    return 1;
}
