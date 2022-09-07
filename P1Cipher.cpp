#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

void rot13(istream&, ostream&);
void GenRanDict(ostream&);
bool LDict(istream&, map<char,char>&, map<char,char>&);
void caesar(map<char,char>&, istream&, ostream&);

int main(int argc, char *argv[])
{
    map<char,char> cipher;
    map<char,char> reverse;
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
    // Encrypt/Decrypt Input with Caesar Cipher Dictionary "-e"/"-d"
    else if(cmd == "-e" || cmd == "-d")
    {
        if(argc > 4)
        {
            cout << "TOO MANY ARGUMENTS " <<endl;
            return 0;
        }
        if(argc < 3)
        {
            cout << "DICTIONARY NOT PROVIDED " <<endl;
            return 0;
        }

        ifstream dictionary(argv[2]);
        if(!dictionary.is_open())
        {
            cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" <<endl;
            return 0;
        }

        if(!LDict(dictionary,cipher,reverse)) return 0;

        if(argc == 4)
        {
            file.open(argv[3]);
            if(!file.is_open())
            {
                cout << argv[3] << "FILE COULD NOT BE OPENED" <<endl;
                return 0;
            }
            in = &file;
        }

        if(cmd == "-e")
        {
            caesar(cipher, *in, cout);
        }
        else
        {
            caesar(reverse, *in, cout);
        }
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

bool LDict(istream& in, map<char,char>& cipher, map<char,char>& reverse)
{
    string pair;
    for (char ch='a'; ch <= 'z'; ch++)
    {
        in >> pair;
        if(in.fail()) return false;

        if(pair.length() != 2)
        {
            cout << "FORMATTING ERROR " << pair <<endl;
            return false;
        }
        if(pair[0] != ch)
        {
            cout << "MISSING LETTER " << ch <<endl;
            return false;
        }
        if(pair[0] == pair[1])
        {
            cout << "MAPPING ERROR " << ch <<endl;
            return false;
        }

        cipher[pair[0]] = pair[1];

        if(reverse.find(pair[1]) != reverse.end())
        {
            cout << "DUPLICATE CIPHERTEXT " << pair[1] <<endl;
            return false;
        }

        reverse[pair[1]] = pair[0];
    }
    return true;
}

void caesar(map<char,char>& translate, istream& in, ostream& out)
{
    while(1)
    {
        char ch;
        ch = in.get();
        if(in.eof() || in.bad()) return;

        if(islower(ch))
            ch = translate[ch];
        else if(isupper(ch))
            ch = toupper(translate[tolower(ch)]);
        
        out.put(ch);
    }
    out << flush;
    return;
}