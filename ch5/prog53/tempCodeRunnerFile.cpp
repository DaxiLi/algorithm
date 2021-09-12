int n = 0,m = 0,d = 0;
    // n 元件数  m 供应商数  d 总价格
    ifs >> n>>m>>d;
    int v[n][m] = {0},w[n][m] = {0};
    for (int i = 0;i < n;i++)
    {
        for (int j = 0; J < m;j++)
        {
        ifs >> v[i][j];
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0; J < m;j++)
        {
            ifs >> w[i][j];
        }
    }
    int value = 0;
    int weight = 0;
    int min_weight = INT_MAX;
    int index = 0;
    int stack[n + 1] = {0};
    int res[n] = {0};
    while(1)
    {
        // 遍历完成所有子节点 返回上一层的下一个节点
        // 重量不是最优 截断
        // 钱超了 截断
        if (stack[index] >= m || value > d || weight > min_weight)
        {
            stack[index] = 0;
            index--;
            // 到达根节点 
            if (index < 0)
            {
                break;
            }
            weight -= w[index][stack[index]];
            value -= v[index][stack[index]];
            stack[index]++;
            continue;
        }
        // 到达叶子 返回 并判断结果
        if (index >= n)
        {
            if (weight < min_weight)
            {
                min_weight = weight;
                for (int j = 0;j < n;j++)
                {
                    res[j] = stack[j];
                }
            }
            index--;
            // 到达根节点 
            if (index < 0)
            {
                break;
            }
            // 恢复现场
            weight -= w[index][stack[index]];
            value -= v[index][stack[index]];
            stack[index]++;
            // cout << stack[index];
            continue;
        }
        
        // cout <<"index:"<<index<<endl;
        // cout << "stack:"<<stack[index]<<endl;
        weight += w[index][stack[index]];
        value += v[index][stack[index]];
        index++;

    }