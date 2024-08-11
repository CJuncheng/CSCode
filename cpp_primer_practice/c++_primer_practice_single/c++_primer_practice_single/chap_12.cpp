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
#include <memory>
#include <stdexcept>
#include <initializer_list>
#include <cstring>

using namespace std;

class StrBlob{
public:
    StrBlob(): data(make_shared<vector<string>>()){}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)){}
    size_t size() {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const string& str) {data->push_back(str); }
    void pop_back(){
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    } 
    string& front(){
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& back(){
        check(0, "back on empty StrBlob");
        return data->back();
    }
    string& front() const {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& back() const {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;
    void check(size_t i, const string& msg) const {
        if(i>=data->size())
            throw out_of_range(msg);
    }
};


void practice_12_2(void){
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;
    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;
}

shared_ptr<vector<int>> practice_12_6(void){
   shared_ptr<vector<int>> p = make_shared<vector<int>>(10);
   return p;
}

void practice_12_23(void){
    const char* c1 = "Hello ";
    const char* c2 = "World";
    char *r = new char[strlen(c1)+strlen(c2)+1];
    strcpy(r, c1);
    strcat(r, c2);
    cout << r << endl;

    string s1 = "Hello ";
    string s2 = "World";
    strcpy(r, (s1+s2).c_str());
    cout << r << endl;

    delete[] r;
}

void practice_12_24(void){
    
    char *r = new char[20];
    int idx = 0;
    char c;
    while(scanf("%c", &c)){
        if(isspace(c)) break;
        r[idx++] = c;
        if(idx==20) {
            printf("达到数组容量上限\n");
            break;
        }
    }
    r[idx] = 0;
    printf("%s\n", r);
    //cout << r << endl;
    delete[] r;
}


void practice_12_26(void){
    const int n = 10;
    allocator<string> alloc;
    string* const p = alloc.allocate(n); // 分配内存
    string s;
    string* q = p;
    while(cin >> s && q != (p+n)){
        alloc.construct(q++, s); // 在已经分配的内存基础上，构造对象
    }
    const size_t size = q-p;
    cout << size << endl;
    for(size_t i = 0; i < size; ++i)
        cout << p[i] << endl;

    while(q != p){ //释放已经构造的string
        alloc.destroy(--q);
    }
    alloc.deallocate(p, size); // 释放内存
}

/*
int main(int argc, char* argv[])
{
    practice_12_2();
    shared_ptr<vector<int>> p = practice_12_6();
    for(size_t i = 0; i < p->size(); ++i){
        cout << (*p)[i] << endl;
    }
    
    //practice_12_23();
    //practice_12_24();
    practice_12_26();

    return 0;
}
*/


/*********************************************
 * 文本查询练习
 *********************************************/ 
class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	typedef std::vector<std::string>::size_type line_no;
	typedef std::set<line_no>::const_iterator line_it;
	QueryResult(std::string s, 
	            std::shared_ptr<std::set<line_no>> p, 
	            std::shared_ptr<std::vector<std::string>> f):
		sought(s), lines(p), file(f) { }
	std::set<line_no>::size_type size() const  { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const   { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;  // word this query represents
	std::shared_ptr<std::set<line_no>> lines; // lines it's on
	std::shared_ptr<std::vector<std::string>> file;  //input file
};

std::ostream &print(std::ostream&, const QueryResult&);
ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    //os << qr.sought << " occurs " << qr.lines->size() << " "
    //   << make_plural(qr.lines->size(), "time", "s") << endl;

    // print each line in which the word appeared
	for (auto num : *qr.lines) // for every element in the set 
		// don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") " 
		   << *(qr.file->begin() + num) << endl;

	return os;
}

class TextQuery{
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const; 
    void display_map();        // debugging aid: print the map
private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // maps each word to the set of the lines in which that word appears
    std::map<std::string, 
	         std::shared_ptr<std::set<line_no>>> wm;  

	// canonicalizes text: removes punctuation and makes everything lower case
    static std::string cleanup_str(const std::string&);
};

// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {       // for each line in the file
		file->push_back(text);        // remember this line of text
		int n = file->size() - 1;     // the current line number
		istringstream line(text);     // separate the line into words
		string word;               
		while (line >> word) {        // for each word in that line
            word = cleanup_str(word);
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word]; // lines is a shared_ptr 
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>); // allocate a new set
            lines->insert(n);      // insert this line number
		}
	}
}

// not covered in the book -- cleanup_str removes
// punctuation and converts all text to lowercase so that
// the queries operate in a case insensitive manner
string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it) {
        if (!ispunct(*it))
            ret += tolower(*it);
    }
    return ret;
}

QueryResult
TextQuery::query(const string &sought) const
{
	// we'll return a pointer to this set if we don't find sought
	static shared_ptr<set<line_no>> nodata(new set<line_no>); 

    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(cleanup_str(sought));

	if (loc == wm.end()) 
		return QueryResult(sought, nodata, file);  // not found
	else 
		return QueryResult(sought, loc->second, file);
}



// debugging routine, not covered in the book
void TextQuery::display_map()
{
    auto iter = wm.cbegin(), iter_end = wm.cend();

    // for each word in the map
    for ( ; iter != iter_end; ++iter) {
        cout << "word: " << iter->first << " {";

        // fetch location vector as a const reference to avoid copying it
        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin(),
                        loc_iter_end = text_locs->cend();

        // print all line numbers for this word
        while (loc_iter != loc_iter_end)
        {
            cout << *loc_iter;

            if (++loc_iter != loc_iter_end)
                 cout << ", ";

         }

         cout << "}\n";  // end list of output this word
    }
    cout << endl;  // finished printing entire map
}

/*
void runQueries(ifstream &infile)
{
	// infile is an ifstream that is the file we want to query
    TextQuery tq(infile);  // store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q") break;
		// run the query and print the results
        print(cout, tq.query(s)) << endl;
    }
}
*/

// program takes single argument specifying the file to query
int main(int argc, char **argv)
{
    // open the file from which user will query words
    ifstream infile;
	// open returns void, so we use the comma operator XREF(commaOp) 
	// to check the state of infile after the open
    if (argc < 2 || !(infile.open(argv[1]), infile)) {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }
	//runQueries(infile);
    return 0;
}

