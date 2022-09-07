#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    istream *in = &cin;

    if(argc == 1)
    {
        cout << "MISSING COMMAND" <<endl;
        return 0;
    }

    string cmd(argv[1]);
    cout << cmd <<endl;
    
    return 0;
}