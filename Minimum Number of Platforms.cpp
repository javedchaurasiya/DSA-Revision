int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    
    int maxPlatforms=0;
    int curNoOfPlatform=0;
    int i=0,j=0;
    while(i<n&&j<n)
    {
        
        if(at[i]<=dt[j])
        {
            curNoOfPlatform++;
            maxPlatforms=max(maxPlatforms,curNoOfPlatform);
            i++;
        }
        else
        {
            curNoOfPlatform--;
            j++;
        }
    }
    return maxPlatforms;
}