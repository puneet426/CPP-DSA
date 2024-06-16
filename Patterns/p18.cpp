// #include<iostream>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     int i=1;
//     while(i<=n){
//         int space = n-i;
//         while(space){
//             cout << " ";
//             space--;
//         }
//         int j=1;
//         while(j<=i){
//             cout << "*";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
    
// }
//second method
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