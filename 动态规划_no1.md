
# 初级动态规划
* 斐波那契数列
* 最长不下降子序列
* 最大子序列和
* 最长公共子序列

## 斐波那契数列
1、1、2、3、5、8、13、21、34、.....
 
* 递归版本
```$c++
    if (n==0 || n==1)  
        return 1;
    else  
        return F(n-1) + F(n-2);
```
 
 * 递推
 ```$c++
    A[0] = A[1] = 1;
    for (i =2; i <= n ; i++)
	    A[i]=A[i-1] + A[i-2];
    return A[n];
```



## 最长不下降子序列

* 原理
> f[i] = 1  
> f[i]=max{f[j]+1}（a[j]<=a[i] 且 j<i）


* 代码
```$c++
    # 第一种写法
    void code1{
        for(i = 0; i < n; i++) {
           dp[i] = 1;
           for(j = 0; j < i; j++){
            if(data[j] <= data[i] && dp[j] + 1 > dp[i])
                 dp[i] = dp[j] + 1;
           }
        }
    }

    # 第二种写法
   void code2{
        for(i = 0; i < n; i++) {
           dp[i] = 1;
           for(j = 0; j < i; j++){
            if(data[j] <= data[i])
                dp[i] = max( dp[i], dp[j] + 1 );
           }
       }
   }
```


## 最大子序列和

* 原理

* 输入
> -5 6 -1 5 4 -7
* 输出
> 14

* 代码
```$xslt
    for(i = 0; i < n; i++) {
        if(dp[i-1] > 0) dp[i] = dp[i-1] + data[i];
        else dp[i] = data[i];
    }
```

## 最长公共子序列

* 原理
> 状态转移方程:  
>   dp[i][j]=dp[i-1][j-1]+1  
>   dp[i][j]=max(dp[i - 1][j] ,dp[i][j - 1])  

* 输入
> abcfbc  
> abfcab 
* 输出
> 4

* 代码
```$xslt
	for(int i=0;i<str1.size();i++){
		for(int j=0;j<str2.size();j++){
			if(str1[i] == str2[j]){
				dp[i+1][j+1]=dp[i][j]+1;
			}else{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
```
