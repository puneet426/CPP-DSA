#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter the number of rows: ";
    cin>>n;
    for(int i=1; i<=n; i++){
        for(j=1;j<=i;j++){
            cout<<i;
        }
        cout<<endl;
    }
}