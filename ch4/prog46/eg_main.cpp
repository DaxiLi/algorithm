#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include<io.h>
#include <madcapcl.h>

// if u want test your program,just keep it else anotation it
#define DEBUG break;

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
    int n = 0;
    ifs >> n;
    int S[n] = {0};
    int i = 0;
    while(i < n)
    {
        ifs >> S[i];
        i++;
    }
    sort(S,S + n);
    int all_time = 0,append_time = 0;
    for (i = 0; i < n;i++)
    {
        append_time += S[i];
        all_time += append_time;
    }

    cout << "i ans:";
    // print your anwser here !
    printf("%.2f\n",1.0*all_time/n);
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

    }while(_findnext(Handle,&FileInfo) == 0);
    _findclose(Handle);
    return 0;
}
