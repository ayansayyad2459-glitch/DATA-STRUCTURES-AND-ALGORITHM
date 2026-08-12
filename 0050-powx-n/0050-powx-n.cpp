class Solution {
public:
   double power(double x, long long n){
    // base case
    if(n==0) return 1;

    // recursive call
    double half = power(x,n/2);

    // if n is even
    if(n%2==0){
        return half*half;
    }
    // if n is odd
    else{
        return half*half*x;
    }
   }
    double myPow(double x, int n) {
        long long N= n;
        if(N<0){
            return 1 / power(x, -N);
        }
        return power(x,N);
    }
};

// class Solution {
// public:
//     double myPow(double x, int n) {
//         long long N = n; // Use long long to prevent overflow
//         if (N < 0) {
//             x = 1 / x;
//             N = -N;
//         }
        
//         double ans = 1;
//         double current_product = x;
        
//         while (N > 0) {
//             // If N is odd, multiply the answer by the current product
//             if (N % 2 == 1) {
//                 ans = ans * current_product;
//             }
//             // Square the product and halve the power
//             current_product = current_product * current_product;
//             N = N / 2;
//         }
//         return ans;
//     }
// };