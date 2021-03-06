#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int pursue(vector<double>& a,vector<double>& c,vector<double>& d,vector<double>& b,vector<double>& res);
int main(){
    int n;
    cout<<"Please enter the order of the matrix"<<endl;
    cin>>n;
    vector<double> a(n),d(n),c(n),b(n),res(n);
    cout<<"Please enter a(i) of A"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Please enter c(n) of A from 1 to n-1"<<endl;
    for(int i=0;i<n-1;i++)
        cin>>c[i];
    cout<<"Please enter d(n) if A from 2 to n"<<endl;
    for(int i=1;i<n;i++)
        cin>>d[i];
    cout<<"Please enter b"<<endl;
    for(int i=0;i<n;i++)
        cin>>b[i];
    if(pursue(a,c,d,b,res))
        for(int i=0;i<n;i++)
            cout<<res[i];
    system("pause");

}
int pursue(vector<double>& a,vector<double>& c,vector<double>& d,vector<double>& b,vector<double>& res){
    int n=a.size();
    vector<double> p(n),r(n),q(n);
    for(int i=0;i<n;i++){
        r[i]=d[i];
    }
    p[0]=a[0];
    for(int i=0;i<n-1;i++){
        q[i]=c[i]/p[i];
        p[i+1]=a[i+1]-d[i+1]*q[i];
    }
    vector<double> y(n);
    y[0]=b[0]/p[0];
    for(int i=1;i<n;i++)
        y[i]=(b[i]-d[i]*y[i-1])/p[i];
    res[n-1]=y[n-1];
    for(int i=n-2;i>=0;i--)
        res[i]=y[i]-q[i]*res[i+1];
    return 1;
}
