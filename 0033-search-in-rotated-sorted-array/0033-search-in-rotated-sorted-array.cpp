class Solution {
public:
    int search(vector<int>& A, int tarr) {
        int st = 0;
        int end = A.size()-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(A[mid]==tarr){
                 return mid;
            }
          if(A[st]<=A[mid])   //leftsorted
          {
             if(A[st]<= tarr && tarr<=A[mid]){
                end = mid-1;
             }
             else{
                st = mid+1;
             }
          }
          else{
            //right sorted
            if(A[mid]<=tarr && tarr<= A[end]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
          }
            
        }
        return -1;
    }
};