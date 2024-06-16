#include<iostream>
using namespace std;
int main() {
    int n,i,j,space;
    cin >> n;
    for(i=1;i<=n;i++){
       for(space=n-i;space;space--){
        cout << " ";
       }
        for(j=1;j<=i;j++){
            
            cout <<" "<<"*";
            }
              cout << endl;
    }
  
}