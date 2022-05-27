int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> v={1,2,5,10,20,50,100,500,1000};
    int ans=0;
    int i=8;
    while(amount)
    {
        if(amount/v[i]>=1)
        {
            ans+=amount/v[i];
            amount=amount%v[i];
        }
        i--;
    }
    return ans;
}
