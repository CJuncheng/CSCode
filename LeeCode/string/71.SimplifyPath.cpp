#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string simplifyPath(string path) {
    vector<string> dirs;
    for(auto i = path.begin(); i!=path.end();){
        ++i;
        auto j = find(i, path.end(), '/');
        auto name = string(i,j);
        if(!name.empty()&&name!=".") {
            if(name==".."){
                if(!dirs.empty()&&name=="..") 
                    dirs.pop_back();
            }
            else dirs.push_back(name);
        }
        i = j;
    }
    
    if(dirs.empty()) return "/";
    else {
        string result;
        for(auto &s : dirs){
            result+="/"+s;
        }
        return result;
    }
}

int main (int argc, char* argv[])
{
    const string path = "/home/";
    string ret = simplifyPath(path);
    std::cout << ret << std::endl;
    return 0;

}