# Cipher Commands
This C++ Program uses Command Line Arguments to read in the commands and optional/required files into the main() function.
C++ Program with Commands that will perform 4 functions:
- Perform a Rotation13 substitution
- Perform a caesar encryption given a dictionary
- Perform a caesar decryption given a dictionary
- Create a random caesar cipher dictionary

## Installation and Execution
To run the C++, MinGW was installed with versions of GCC 11.2.0 and Boost 1.77.0.
- http://bit.ly/mingw10

This program is run through Windows 10 Visual Studio Code using:
- __C/C++__ Microsoft Extension
- __Code Runner__ Jun Han Extension

Installing the code was done using PowerShell and the command:
```powershell
git clone https://github.com/cmmira/CipherCommands.git 
```

Running the code was done using Code Runner with the shortcut __Ctrl+Alt+N__, creating the input on the PowerShell, which could also be modified to input the necessary Command Line Argument:
``` powershell
cd “<CipherCommands File Location>” ; if ($?) { g++ P1Cipher.cpp -o P1Cipher } ; if ($?) { .\P1Cipher <Command Line Arguments> }
```

## Rotation 13 Letter Substitution
Command __”-r”__, rotates each letter 14 positions in the alphabet.
- This command allows an optional second argument which is the name of the file to read from. If not provided, the program will just read from standard input.
- The output of this command will be generated through standard output.

## Generate Random Caesar Cipher Dictionary
Command __”-g”__, generates a dictionary that will have each letter in the alphabet mapped to a different and unique ciphertext letter.
- Generated Cipher Dictionary will have pairs of letters, the first letter being the plaintext letter and the second letter being the corresponding ciphertext letter.
- Each plaintext letter maps to a unique ciphertext and no letter will map to itself.
- The generated dictionary will have the letter pairs shown by standard output.

## Perform Caesar Encryption/Decryption Given a Dictionary
 Command __”-e”/”-d”__ performs a caesar cipher _encryption/decryption_ using the provided dictionary file __”cdict.txt”__, where each plaintext letter is paired with a ciphertext letter. The _encryption/decryption_ uses each letter as a _plaintext/ciphertext_ letter and replaces it with the _ciphertext/plaintext_ letter that it is mapped with in the _encryption/decryption_ map container.
- This command also requires a second argument, which is the filename of the dictionary. An error will occur if there is no second argument provided 
- The format for the Caesar cipher dictionary is a file with 26 pairs of letters, one per letter of the alphabet, in alphabetical order. Each pair has two letters, the plaintext letter and the ciphertext letter.
- This command also supports an optional third argument, which is the file to read from and _encrypt/decrypt_. If it is not provided the program will read from standard input.
- The output of this command will have text input _encrypted/decrypted_ using the provided dictionary and shown through standard output. 

