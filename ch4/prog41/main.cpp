#include <iostream>
#include <string>
#include<io.h>
#include <madcapcl.h>


using namespace std;



void resolve(string fileName){
    cout << fileName <<endl;
}

int main(int argv,char** argc){
    string baseDir,testDir,answerDir,testFile;
    int index = 0;
    baseDir = baseDir.substr(0,index + 1);
    index = baseDir.rfind('\\');
    testDir = baseDir + "test\\";
    testFile = testDir + "*.in";
    answerDir = baseDir + "answer\\";
    // 遍历所有输入文件
    _finddata_t FileInfo;
    long Handle = _findfirst(testDir.c_str(),&FileInfo);
    if(Handle == -1l){
        printf("has no found files\n");
        _findclose(Handle);
        return 0;
    }
    do{
        resolve(FileInfo.name);
    }while(_findnext(Handle,&FileInfo) == 0);
    _findclose(Handle);
    return 0;
}
