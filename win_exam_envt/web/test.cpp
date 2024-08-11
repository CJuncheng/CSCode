#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

void parse_arg(int argc, char*argv[]){
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
        {
            cout << atoi(optarg) << endl;
            break;
        }
        case 'l':
        {
            cout <<  atoi(optarg) << endl;
            break;
        }
        case 'm':
        {
            cout << atoi(optarg) << endl;
            break;
        }
        case 'o':
        {
            cout << atoi(optarg) << endl;
            break;
        }
        case 's':
        {
           cout << atoi(optarg) << endl;
            break;
        }
        case 't':
        {
            cout << atoi(optarg) << endl;
            break;
        }
        case 'c':
        {
            cout << atoi(optarg) << endl;
            break;
        }
        case 'a':
        {
            cout << atoi(optarg) << endl;
            break;
        }
        default:
            break;
        }
    }
}


int main(int argc, char* argv[])
{
    parse_arg(argc, argv);
    return 0;
}