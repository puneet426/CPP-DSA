#include<iostream>
using namespace std;
int main() {
    int n,i,j,space;
    cin >> n;
    for(i=1;i<=n;i++){
       for(space=i-1;space;space--){
        cout << "  ";
       }
        for(j=i;j<=n;j++){
            
            cout <<" "<<"*";
            }
              cout << endl;
    }
  
}