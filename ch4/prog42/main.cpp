#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
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
    int k = 0;
    ifs >> k;
    int L[k] = {0};
    int M[k] = {0};
    int i = 0;
    int min = 0,max = 0;
    while(i < k)
    {
        ifs >> L[i];
        M[i] = L[i];
        i++;
    }
    i = 0;
    while(i < k - 1){
        sort(L + i,L + k);
        L[i + 1] = L[i] + L[i + 1];
        min += (L[i + 1] - 1);
        i++;
    }
    for (int i = k - 2;i >=0;i--)
    {
        sort(M,M + i + 2);
        M[i] = M[i + 1] + M[i];
        max += M[ i] - 1;
    }
    cout << "i ans:" << max << " " << min <<endl;
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
        // break;
    }while(_findnext(Handle,&FileInfo) == 0);
    _findclose(Handle);
    return 0;
}
