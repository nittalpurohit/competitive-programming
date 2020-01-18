class Solution {
public:
    int numDecodings(string s) 
    {
        int mod = 1000000007;
        int n = s.length();
        long long int dp[n+1];
        dp[0]=1;
        dp[1] = (s[0]=='*')?9:1;
        dp[1] = (s[0]=='0')?0:dp[1];
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0' && s[i+1]>='0' && s[i+1]<='9')
            {
                int df = s[i]-'0';
                int ds = s[i+1]-'0';
                int num = (10*df+ds);
                if(num>=1 && num<=26)
                {
                    
                }
                else
                {
                    return 0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0' && s[i-1]>='0' && s[i-1]<='9')
            {
                int df = s[i-1]-'0';
                int ds = s[i]-'0';
                int num = (10*df+ds);
                if(num>=1 && num<=26)
                {
                    
                }
                else
                {
                    return 0;
                }
            }
        }
        // cout<<"-> "<<dp[0]<<" "<<dp[1]<<endl;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]>='0' && s[i-1]<='9')
            {
                if(s[i-1]=='0' && s[i-2]=='*')
                {
                    // cout<<"c1 i = "<<i<<endl;
                    dp[i] = 2*dp[i-2];
                }
                else if(s[i-1]=='0')
                {
                    // cout<<"c2 i = "<<i<<endl;
                    dp[i] = dp[i-2];
                }
                else if((s[i-2]=='1') || (s[i-2]=='2' && s[i-1]>='1' && s[i-1]<='6'))
                {
                    // cout<<"c3 i = "<<i<<endl;
                    dp[i] = dp[i-2]+dp[i-1];
                }
                else if(s[i-2]=='*')
                {
                    // cout<<"c4 i = "<<i<<endl;
                    if(s[i-1]<='6' && s[i-1]>='0')
                        dp[i] = dp[i-1]+2*dp[i-2];
                    else
                        dp[i] = dp[i-1]+dp[i-2];
                }
                else
                {
                    // cout<<"c5 i = "<<i<<endl;
                    dp[i] = dp[i-1];
                }
            }
            else
            {
                if(i!=1 && s[i-2]=='1')
                {
                    // cout<<"c1 i = "<<i<<endl;
                    dp[i] = 9*dp[i-1]+9*dp[i-2];
                }
                else if(i!=1 && s[i-2]=='2')
                {
                    // cout<<"c2 i = "<<i<<endl;
                    dp[i] = 6*dp[i-2] + 9*dp[i-1];
                }
                else if(s[i-2]=='*')
                {
                    // cout<<"c3 i = "<<i<<endl;
                    dp[i] = 15*dp[i-2] + 9*dp[i-1];
                }
                else
                {
                    // cout<<"c4 i = "<<i<<endl;
                    dp[i] = 9*dp[i-1];
                }
            }
            dp[i]%=mod;
            // cout<<"->"<<dp[i]<<endl;
        }
        
        return dp[n];
    }
};
