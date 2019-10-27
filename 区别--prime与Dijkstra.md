
# prime 和 Dijkstra

* 相同


* 不同
```c++
    #---> prime
    for (int j = 0; j < n; ++j) {
        if (!vis[j] && data[j][t] < dst[j]) {
            dst[j] =  data[j][t] ;
        }
    }

    #---> dijkstra
    for (int j = 0; j < n; ++j) {
        if (!vis[j] && data[t][j] != INF && data[t][j] + dst[t] < dst[j]) {
            dst[j] = data[t][j] + dst[t];
        }
    }

```

