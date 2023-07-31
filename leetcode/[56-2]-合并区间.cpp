void insertsort(struct Interval *intervals, int intervalsSize)
{
    for (int i = 1; i < intervalsSize; i++)
    {
        for(int j=0; j<i; j++)
        {
            if (intervals[j].start > intervals[i].start)
            {
                struct Interval tmp = intervals[j];
                intervals[j] = intervals[i];
                intervals[i] = tmp;
            }
        }
    }
}
void selectsort(struct Interval *intervals, int intervalsSize)
{
    int k;
    for (int i = 0; i < intervalsSize-1; i++)
    {
        k=i;
        for (int j = k + 1; j < intervalsSize; j++)
        {
            if (intervals[j].start < intervals[k].start)
            {
                k = j;

            }
        }
        if (i!=k)
        {
            struct Interval tmp = intervals[i];
            intervals[i] = intervals[k];
            intervals[k] = tmp;
        }
    }
}
void quicksort(struct Interval *intervals, int start, int end)
{
    int i, j;
    struct Interval temp;
    if (start > end)
    {
        return;
    }
    temp = intervals[start];
    i = start;
    j = end;
    while (i != j)
    {
        while (i < j && intervals[j].start >= temp.start)
        {
            j--;
        }
        while (i < j && intervals[i].start <= temp.start)
        {
            i++;
        }
        if (i < j)
        {
            struct Interval tmp = intervals[i];
            intervals[i] = intervals[j];
            intervals[j] = tmp;
        }
    }
    intervals[start] = intervals[i];
    intervals[i] = temp;
    quicksort(intervals, start, i - 1);
    quicksort(intervals, i + 1, end);
}
struct Interval *merge(struct Interval *intervals, int intervalsSize, int *returnSize)
{
    // 创建足够大小的 足够返回
    struct Interval *target = (struct Interval *)malloc(sizeof(struct Interval *) * intervalsSize);
    if (intervalsSize <= 0)
    {
        *returnSize = 0;
        return target;
    }

    // for (int i = 0; i < intervalsSize - 1; i++)
    // {
    //     for (int j = 0; j < intervalsSize - 1 - i; j++)
    //     {
    //         if (intervals[j].start > intervals[j + 1].start)
    //         {
    //             // 根据start元素的大小排序 冒泡排序
    //             struct Interval tmp = intervals[j];
    //             intervals[j] = intervals[j + 1];
    //             intervals[j + 1] = tmp;
    //         }
    //     }
    // }
    // quicksort(intervals, 0, intervalsSize - 1);
    // selectsort(intervals, intervalsSize);
    insertsort(intervals, intervalsSize);

    int count = 0;
    for (int i = 0; i < intervalsSize - 1; i++)
    {
        // 如果满足条件 合并
        if (intervals[i].end >= intervals[i + 1].start)
        {
            // 更新start的值
            intervals[i + 1].start = intervals[i].start;
            // 更新end的值
            intervals[i + 1].end = intervals[i + 1].end > intervals[i].end ? intervals[i + 1].end : intervals[i].end;
        }
        else
        {
            // 如果不需要合并 那么把它记录下来
            target[count++] = intervals[i];
        }
    }
    // 处理最后一个节点
    target[count++] = intervals[intervalsSize - 1];
    *returnSize = count;
    return target;
}
