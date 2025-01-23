class Solution 
{
    public:
    int fib(int n) 
    {
        return fibonacci(n);    
    }
    int fibonacci(int n)
    {
        vector<int>memo(n+1,-1);
        return fibonaccihelper(n,memo);
    }
    int fibonaccihelper(int n,vector<int>& memo)
    {
        if(n<=1)
        {
            return n;
        }
        if(memo[n] != -1)
            return memo[n];
        memo[n] = fibonaccihelper(n-1,memo) + fibonaccihelper(n-2,memo);
        return memo[n];
    }
};
