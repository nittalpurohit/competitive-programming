class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long long int n = 0;
        long int i=0;
        for(i=0;n<k;i++)
        {
            if(s[i]-'0'>0 && s[i]-'0'<=9)
            {
                n=n*(s[i]-'0');
            }
            else
            {
                n++;
            }
        }
        //cout<<"okz"<<endl;
        while(i--)
        {
            //cout<<"i = "<<i<<" ";
            if(s[i]-'0'>0 && s[i]-'0'<=9)
            {
                //cout<<" c1"<<endl;
                n=n/(s[i]-'0');
                k%=n;
            }
            else if(k%n == 0)
            {
                //cout<<" c2"<<endl;
                //cout<<"s[i] = "<<s[i]<<endl;
                string tmp = "";
                tmp.push_back(s[i]);
                return tmp;
            }
            else
            {
               // cout<<" c3"<<endl;
                n--;
            }
        }
        return "nittal";
    }
};
