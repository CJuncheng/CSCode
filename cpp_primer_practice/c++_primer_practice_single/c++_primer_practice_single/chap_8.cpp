#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

// practice_8_1
std::istream & f (std::istream &in)
{
	int v;
	while(in>>v, !in.eof()) { // 直到遇到文件结束符才停止读取
		if(in.bad())
			throw runtime_error("IO流错误");
		if(in.fail()) {
			cerr << "数据错误，请重试：" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	in.clear();
	return in;
}

// practice_8_3
/***********************************************************************
 * 遇到文件结束符，或遇到IO流错误，或者读入无效数据；  
 ***********************************************************************/
void practice_8_4(void)
{
	const string input_path = "./data/data_8_4.txt";
	ifstream ifs;
	ifs.open(input_path);
	if(!ifs.is_open()){
		cerr << "无法打开输入文件" << std::endl;
	}
	string line;
	vector<string> words;
	while(getline(ifs, line))
		words.push_back(line);

	std::cout << "Print words: ";
    for(auto it = words.cbegin(); it != words.cend(); ++it){
        std::cout << *it << std::endl;
    }
	
}

void practice_8_5(void)
{
	const string input_path = "./data/data_8_4.txt";
	ifstream ifs;
	ifs.open(input_path);
	if(!ifs.is_open()){
		cerr << "无法打开输入文件" << std::endl;
	}
	string word;
	vector<string> words;
	while(ifs >> word)
		words.push_back(word);

	std::cout << "Print words: " << std::endl;
    for(auto it = words.cbegin(); it != words.cend(); ++it){
        std::cout << *it << std::endl;
    }
	
}

void practice_8_9(void)
{
	ostringstream msg;
	msg << "Hello World" << std::endl;
	istringstream iss(msg.str());
	string word;
	while(iss>>word)
	{
		std:: cout << word << std::endl;
	}
	//f(iss);
}

int practice_8_10(void)
{
	const string input_path = "./data/data_8_4.txt"; 
	ifstream ifs(input_path);
	if(!ifs.is_open()) {
		cerr << "打开文件失败" << endl;
		return -1;
	}
	string line;
	vector<string> words;
	while(getline(ifs, line))
		words.push_back(line);
	ifs.close();

	for(auto it = words.begin(); it != words.end(); ++it) {
		istringstream iss(*it);
		string word;
		cout << "words[" << std::distance(words.begin(), it) << "]: "; 
		while(iss >> word) {
			cout << word << " ";
		}
		cout << endl;
	}
	return 0;
}

// practice_8_13
typedef struct {
	string name;
	vector<string> phones; 
} PersonInfo;

int practice_8_13(void)
{
	const string input_path = "./data/data_8_13.txt";
	ifstream ifs(input_path);
	if (!ifs.is_open()) {
		cerr << "文件打开失败" << endl;
		return -1;
	}
	string line, word;
	vector<PersonInfo> people;
	while(getline(ifs, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while(record>>word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	for(auto & personInfo : people) {
		cout << personInfo.name << ": ";
		const size_t size = personInfo.phones.size()-1; //减少循环体中函数调用的开销
		for(size_t i = 0; i < size; i += 2){  //循环展开效率更高
			cout << personInfo.phones[i] << " ";
			cout << personInfo.phones[i+1] << " ";
		}
		cout<<endl;
	}
	return 0;
}


int main (int argc, char* argv[])
{
	// practice_8_1
	//cout << "请输入一个整数， 按Ctrl+Z结束" << endl;
	//f(cin);	

	//practice_8_4();
	//practice_8_5();
	practice_8_9();
	practice_8_10();
	practice_8_13();

    return 0;
}
