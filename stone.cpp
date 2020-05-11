递推
从底向上
for (int len = 1; len <= n; ++i)
   for (int i=1, j = i + len - 1; i <=n; ++i)
      for (int k=i; k<j; ++k)
        f[i][j] = min(f[i][k] + f[k+1][j]) + sum[i..j];

递归/记忆化搜索
memset(f, -1, sizeof(f));
//f[i][i] = 0;
int dfs(int i, int j)
{
    if (f[i][j] != -1)
        return f[i][j];
    f[i][j] = 1e9 + 7;
    for (int k=i; k<j; ++k)
        f[i][j] = min(f[i][k] + f[k+1][j]) + sum[j] - sum[i-1];
    return f[i][j];
}
ans = dfs(1, n);