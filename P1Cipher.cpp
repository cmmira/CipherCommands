#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void rot13(istream&, ostream&);

int main(int argc, char *argv[])
{
    istream *in = &cin;
    ifstream file;

    if(argc == 1)
    {
        cout << "MISSING COMMAND" <<endl;
        return 0;
    }

    string cmd(argv[1]);
    // Rotation 13 Command "-r"
    if(cmd == "-r")
    {
        if(argc > 3)
        {
            cout << "TOO MANY ARGUMENTS" <<endl;
            return 0;
        }
        if(argc == 3)
        {
            file.open(argv[2]);
            if(!file.is_open())
            {
                cout << argv[2] << " FILE COULD NOT BE OPENED" <<endl;
                return 0;
            }
            in = &file;
        }

        rot13(*in, cout);
        return 0;
    }
    else
    {
        cout << cmd << "NOT A VALID COMMAND" <<endl;
        return 0;
    }

    return 0;
}

void rot13(istream& in, ostream& out)
{
    //const char alpha= "abcdefghijklmnopqrstuvwxyz"
    const char *lower = "nopqrstuvwxyzabcdefghijklm";
    const char *upper = "NOPQRSTUVWXYZABCDEFGHIJKLM";

    int ch;
    while(1)
    {
        ch = in.get();
        if (in.eof()) return;

        if(islower(ch))
        {
            ch = lower[ch - 'a'];
        }
        else if(isupper(ch))
        {
            ch = upper[ch - 'A'];
        }
        out.put(ch);
    }
}