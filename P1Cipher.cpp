#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void rot13(istream&, ostream&);
void GenRanDict(ostream&);

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
    // Generate Random Caesar Cipher Dictionary "-g"
    else if(cmd == "-g")
    {
        if(argc > 2)
        {
            cout << "TOO MANY ARGUMENTS" <<endl;
            return 0;
        }
        GenRanDict(cout);
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

void GenRanDict(ostream& out)
{
    const char *alpha = "abcdefghijklmnopqrstuvwxyz";
    char gen[26];
    int nlet = 26;

    strcpy(gen,alpha);
    srand(time(NULL));

    for(int i=0; i<26;)
    {
        int t = rand() %nlet;
        if(gen[t] == alpha[i]) continue;

        out << alpha[i] << gen[t] <<endl;
        gen[t] = gen[nlet-1];
        nlet--;
        i++;
    }
    return;
}