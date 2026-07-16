class Solution {
public:
    int findmaxbananas(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
          maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    long long calculatetotalhours(vector<int>& piles, int hourly){
        long long totalH = 0;
        int n = piles.size();
        for(int i = 0;i<n;i++){
            totalH += ceil((double)piles[i] / (double)hourly);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; int high = findmaxbananas(piles);
        while (low<=high){
            int mid = (low+high)/2;
            long long totalhours = calculatetotalhours(piles, mid);
            if(totalhours<= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};