# __CipherCommands__
C++ Program with Commands that will perform 4 functions: 
- Perform a Rotation13 substitution
- Perform a caesar encryption given a dictionary
- Perform a caesar decryption given a dictionary
- Create a random caesar cipher dictionary.

This C++ Program uses the Command Line Arguments to read in the commands and optional/required files into the main() function.

## Rotation 13 Letter Substitution
With the command __"-r"__ the program will rotate each letter 13 positions in the alphabet.
    - This Command also allows an optional second argument which if the name of the file to read from. If not provided, the program will just read from standard input.
    - The output of this command wil be generated to the standard output.

## Generate Random Caesar Cipher Dictionary
With the command __"-g"__ the program will generate a dictionary that will have each letter in the alphabet mapped to a different and unique ciphertext letter.
    - The generated cipher dictionary wil have pairs of letters with the first letter being the plaintext letter and the second letter being the corresponding ciphertext letter.
    - Each plaintext letter will only map to a unique ciphertext and no letter will map to itself.

