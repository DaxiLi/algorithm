#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include<io.h>
#include <madcapcl.h>


using namespace std;



void resolve(string fileName,string ansFileName){
    cout << fileName <<endl;
    ifstream ifs(fileName,ios::in);
    if (!ifs.is_open())
    {
        cout << "open file fail!" <<endl;
        return;
    }
    // todo something here !


    // int n,m,d;
    // ifs >> n>>m>>d;
    // int w[n][m] = {0},v[n][m] = {0},res[n] = {0};
    // int stack[n + 1] = {0};     // 每一层的 当前分支
    // int index = 0;              // 指向当前层级
    // int min_weight = INT_MAX;   // 最优结果
    // int weight = 0,value = 0;   // 临时计数器
    // /* 输入 */
    // for (int i = 0; i < n;i ++)
    // {
    //     for (int j = 0;j < m;j++)
    //     {
    //         ifs >> v[i][j];
    //     }
    // }
    // for (int i = 0; i < n;i++)
    // {
    //      for (int j = 0;j < m;j++)
    //     {
    //         ifs >> w[i][j];
    //     }
    // }
    // while (index >= 0)
    // {
    //     // 树的最后一个
    //     // 钱超支
    //     // 重量不是最优
    //     // 裁掉，返回上一层
    //     if (stack[index] >= m || value > d || weight > min_weight)
    //     {
    //         // 将当前层分支重置，返回上一层
    //         stack[index] = 0;
    //         index--;
    //         // 将上一层的累加结果 减掉
    //         weight -= w[index][stack[index]];
    //         value -= v[index][stack[index]];
    //         // 继续上一层的下一个子节点
    //         stack[index]++;
    //         continue;
    //     }
    //     // 树的最底层 叶子
    //     if (index >= n)
    //     {
    //         // 这是一种完整的方案
    //         // 且能到达这里，一定是一个新的优值
    //         for (int i = 0;i < n;i ++)
    //         {
    //             res[i] = stack[i];
    //         }
    //         // index 为 n stack不用重置
    //         index--;
    //         // 将上一层的累加结果 减掉
    //         weight -= w[index][stack[index]];
    //         value -= v[index][stack[index]];
    //         // 继续上一层的下一个子节点
    //         stack[index]++;
    //         continue;
    //     }
    //     weight += w[index][stack[index]];
    //     value += v[index][stack[index]];
    //     index++;
    //     // 将下一层分支重置
    //     // stack[index] = 0;
    // }




    int n = 0,m = 0,d = 0;
    // n 元件数  m 供应商数  d 总价格
    ifs >> n>>m>>d;
    int v[n][m] = {0},w[n][m] = {0};
    for (int i = 0;i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
        ifs >> v[i][j];
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0; j < m;j++)
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
        weight += w[index][stack[index]];
        value += v[index][stack[index]];
        index++;

    }
    cout << "i ans:";
    // print your anwser here !
    cout << min_weight <<endl;
    for (int val : res)
    {
        cout << val + 1<< " ";
    }
    cout <<endl;
    cout << "t ans:" << ifstream(ansFileName).rdbuf() << endl <<endl;
}

int main(int argv,char** argc){
    string baseDir,testDir,answerDir,testFile;
    int index = 0;
    baseDir = argc[0];
    index = baseDir.rfind('\\');
    baseDir = baseDir.substr(0,index + 1);
    testDir = baseDir + "test\\";
    testFile = testDir + "*.in";
    answerDir = baseDir + "answer\\";
    _finddata_t FileInfo;
    long Handle = _findfirst(testFile.c_str(),&FileInfo);
    if(Handle == -1l){
        printf("has no found files\n");
        _findclose(Handle);
        return 0;
    }
    do{
        string fname = FileInfo.name;
        string ans_name =  fname.substr(0,fname.rfind('.') + 1) + "out";
        resolve(testDir + fname,answerDir + ans_name);

        // if u want test your program,just keep it else anotation it
        // break;
    }while(_findnext(Handle,&FileInfo) == 0);
    _findclose(Handle);
    return 0;
}
