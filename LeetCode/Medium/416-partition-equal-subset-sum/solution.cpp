class Solution {
public:
 int t[1001][10001];
 bool fun(vector<int>&arr, int sum,int n){
      for(int i=0;i<n+1;i++){
          for(int j=0;j<sum+1;j++){
              if(i==0)
              t[i][j] = false;
              if(j==0)
              t[i][j] = true;
              
          }
      }
      for(int i=1;i<n+1;i++){
          for(int j=1;j<sum+1;j++){
              if(arr[i-1]<=j)
              t[i][j]  = t[i-1][j-arr[i-1]] || t[i-1][j];
              else
              t[i][j] = t[i-1][j];
          }
      }
      return t[n][sum];
  }
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
       int sum = 0;
       for(int i=0;i<n;i++)
       sum = sum + arr[i]; 
       if(sum%2 !=0)
       return false;
    return fun(arr,sum/2,n);
       
    }
    
};