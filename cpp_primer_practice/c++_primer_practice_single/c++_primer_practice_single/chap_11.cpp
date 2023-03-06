#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype> // tolower()
#include <utility> // pair
#include <unordered_map>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;
// wordCount
void wordCount(void)
{
    std::map<std::string, int> word_map = {{"fff", 1}, {"ff",2}, {"eeeg", 6}, {"edf",1}, {"vd", 1}};
    for (auto & m : word_map)
        std::cout << m.first << " occors " << m.second << (m.second > 1 ? " times" : " time") << std::endl;
}



inline std::string& tran (std::string& obj)
{
    for(auto it = obj.begin(); it != obj.end(); ++it){
        if(*it >= 'A' && *it <= 'Z')  *it = *it + 'a' - 'A';//tolower(*it);
        else if(*it == '.' || *it == ',')
            std::cout << *it << std::endl;
            //obj.erase(it);  //segmentation fault
    }
    return obj;
}

void practice_11_4(void)
{
    std::map<std::string, int> word_map;
    
    std::vector<std::string> svec = {"hhhh", "HHHh", "ASd,", "asd.", "ggggt"};
    for(auto it = svec.begin(); it != svec.end(); ++it)
    {
        ++word_map[tran(*it)];
    }
    for (auto & m : word_map)
        std::cout << m.first << " occors " << m.second << (m.second > 1 ? " times" : " time") << std::endl;
}
// practice_11_5
/*********************************************************************
 * 当查找key对应的值时，用 map
 * 当判断某个值是否存在时，用set
 *********************************************************************/

// practice_11_6
/*********************************************************************
 *  list是顺序容器, list在内存中的存储区域不是连续的，但访问顺序是连续的，这里可以将list认定为按位置访问，
 *  而vector在内存中的存储区域连续，可以按下标访问: 地址 = start + 字长 x 下标
 *  当需要按位置存储某个较大的元素，可以使用list
 *  map是关联容器，需要存储某个关键字及其对应的值时，可以使用map
 **********************************************************************/

// practice_11_9
/**********************************************************************
 * std::mao <std::string, std::list<int>>
 **********************************************************************/

// practice_11_10
/***********************************************************************
 * std::map<std::vector<int>::iterator, int>可以，vector的迭代器可以比较
 * std::map<std::list<int>::iterator, int>不可以，list的迭代器可以比较
 ***********************************************************************/

// practice_11_11
/***********************************************************************
 * typedef bool (*FuncPointerType) (const Sales_data, const Sales_data)
 * multiset<Sales_data, FuncPointerType> bookstore(compareIsbn)
 ***********************************************************************/

void practice_11_12(void)
{
    std::string str;
    int val;
    std::vector< std::pair<std::string, int> > vec;
    vec.push_back(make_pair(str, val));
    /*
     * pair 三种构造方式 
     * 即 {str, val}， make_pair(str, val)， pair<std::string, int>(str, val)
     */
}

void practice_11_14(void)
{
    std::unordered_map<std::string, std::pair<std::string, std::string>> families;
    families.insert(std::make_pair("zhang", std::make_pair("dqiang", "1997_1_1")));
    families.insert(std::make_pair("zhong", std::make_pair("ccqipng", "1997_1_1")));
    families.insert(std::make_pair("zhog", std::make_pair("bqipng", "1997_1_1")));
    families.insert(std::make_pair("zang", std::make_pair("aqiangii", "1997_1_1")));
    auto it = families.cbegin();
    std::cout << it->second.first << std::endl;
    for(auto & m : families)
        std::cout << m.second.first << std::endl;
}

void practice_11_16(void)
{
    std::map<std::string, int> imap;
    imap.insert({"aalimng", 180});
    imap.insert({"zhanghua", 181});
    auto map_it = imap.begin();
    std::map<std::string, int>::const_iterator it = --imap.cend();
    std::cout<< it->second << std::endl;
    map_it->second += 5;
    //std::cout << map_it->second << std::endl;
}

void practice_11_20(void)
{
    std::map<std::string, int> word_map;
    
    std::vector<std::string> svec = {"hhhh", "HHHh", "ASd,", "asd.", "ggggt"};
    for(auto it = svec.begin(); it != svec.end(); ++it)
    {
        auto ret = word_map.insert({tran(*it), 1});
        if(!ret.second)
            ++ret.first->second;
    }
    for (auto & m : word_map)
        std::cout << m.first << " occors " << m.second << (m.second > 1 ? " times" : " time") << std::endl;
}

void practice_11_22(void)
{
    std::map<std::string, std::vector<int>> m;
    std::vector<int> ivec = {1,2,3};
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> ret = m.insert(make_pair("weee", ivec));
    std::cout << ret.first->first << std::endl;
}

// practice_11_33
unordered_map<string, string> buildMap(ifstream &map_file) {
    unordered_map<string, string> tran_map;
    string key;
    string value;
    string line;
    while(getline(map_file, line)) {
        istringstream record(line);
        record >> key;
        record >> value;
        tran_map.insert(make_pair(key, value));
    }
    return tran_map;
}

void transform (string &s, const unordered_map<string, string> & umap)
{
    auto umap_it = umap.find(s);
    if(umap_it != umap.end())
        s = umap_it->second;
}

int wordTransform(void)
{
    const string map_file_path = "./data/chap11_map_file.txt";
    const string input_file_path = "./data/chap11_input_file.txt";

    ifstream map_file(map_file_path);
    if(!map_file.is_open()) {
        cerr << "map file open failed!" << endl;
        return -1;
    } 
    auto tran_map = buildMap(map_file);

    ifstream input_file(input_file_path);
    if(!input_file.is_open()) {
        cerr << "input file open failed!" << endl;
        return -1;
    }

    string line;
    while(getline(input_file, line)) {
        istringstream record(line);
        string word;
        while(record >> word) {
            transform(word, tran_map);
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

// practice_11_37
/***********************************************************************
 * 无序容器不需要维护关键字的有序性，使用哈希表性能更好
 * 到对于需要维护关键字有序的场景必须使用有序容器
 ***********************************************************************/

int main(int argc, char* argv[])
{
    //wordCount();
    practice_11_4();
    practice_11_12();
    practice_11_14();
    practice_11_16();
    practice_11_20();
    practice_11_22();

    // practice_11_33
    wordTransform();

    return 0;
}

