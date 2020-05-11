        for(int i=1;i<=n-flag;i++){
            for(int j=1;j<=(i+1)/2;j++){
                if(dp[i-1][j]>dp[i-1][j-1]+a[i+flag].sv){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                	if(dp[i-1][j]==dp[i-1][j-1]+a[i+flag].sv){
                        dp[i][j]=dp[i-1][j];
                    }
               		else{
                        dp[i][j]=dp[i-1][j-1]+a[i+flag].sv;
               		}
				}
            }
        }
        