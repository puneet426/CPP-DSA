#include<iostream>
using namespace std;
int main(){
    int n,i,j,s,st;
    cin>>n;
    for(i=1;i<=n;i++){
        for(s=n-i;s;s--){
            cout<<"  ";
        }
        for(j=1;j<=i;j++){
            cout<<" "<<j;
        }
        for(st=i-1;st;st--){
            cout<<" "<<st;
        }
        cout<<endl;
    }
}