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
    cout<<"Please enter c(n) of A"<<endl;
    for(int i=0;i<n;i++)
        cin>>c[i];
    cout<<"Please enter d(n) if A"<<endl;
    for(int i=0;i<n;i++)
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
    vector<double> p(n),r(n),q(n),s(n);
    p[0]=a[0];
    for(int i=0;i<n-2;i++){
        q[i]=c[i]/p[i];
        p[i+1]=a[i+1]-d[i+1]*q[i];
    }
    s[0]=d[0]/p[0];
    for(int i=1;i<n-2;i++){
        s[i]=-d[i]*s[i-1]/p[i];
    }
    s[n-2]=(c[n-2]-d[n-2]*s[n-3])/p[n-2];
    r[0]=c[n-1];
    for(int j=1;j<n-2;j++){
        r[j]=-r[j-1]*q[j-1];
    }
    r[n-2]=d[n-1]-r[n-3]*q[n-3];
    r[n-1]=a[n-1];
    for(int j=0;j<n-1;j++)
        r[n-1]-=r[j]*s[j];
    vector<double> y(n);
    y[0]=b[0]/p[0];
    for(int i=1;i<n-1;i++)
        y[i]=(b[i]-d[i]*y[i-1])/p[i];
    y[n-1]=b[n-1];
    for(int j=0;j<n-1;j++)
        y[n-1]-=r[j]*y[j];
    y[n-1]/=r[n-1];
    res[n-1]=y[n-1];
    res[n-2]=y[n-2]-s[n-2]*res[n-1];
    for(int i=n-3;i>=0;i--)
        res[i]=y[i]-q[i]*res[i+1]-s[i]*res[n-1];
    return 1;
}