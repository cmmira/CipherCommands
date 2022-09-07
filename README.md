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
    - The generated dictionary will have the letter pairs shown by standard output.

## Perform Caesar Encryption Given a Dictionary
With the command __"-e"__ the program will perform a caesar cipher encryption using a provided dictionary file where each plaintext letter has a corresponding ciphertext letter paired with it. The encryption uses each letter as a plaintext letter and replaces it with the ciphertext letter that it is paired with in the dictionary.
    - The format for the caesar cipher dictionary is a file with 26 pairs of letters, one per letter of the alphabet, in alphabetical order. Each pair has two letters: the plaintext letter and the ciphertext letter.
    - This command also requires a second argument, which is the filename of the dictionary, and error will occur if there is no second argument provided.
    - This command also supports an optional third argument which is the file to read from and encrypt the text in the second file. If it is not provided the program will read from standard input. 
    - The output of this command will have the text input encrypted using the provided dictionary and shown through standard output. 


## Perform Caesar Decryption Given a Dictionary
with the command __"-d"__ the program will perfrom a caesar cipher decryption using the provided dictionary file where each plaintext letter has a corresponding ciphertext letter paired with it. The decryption uses each letter as a ciphertext letter and replaces it with the plaintext letter that it is mapped to in the dictionary.
    - The format for the caesar cipher dictionary is a file with 26 pairs of letters, one per letter of the alphabet, in alphabetical order. Each pair has two letters: the plaintext letter and the ciphertext letter.
    - This command also requires a second argument, which is the filename of the dictionary, and error will occur if there is no second argument provided.
    - This command also supports an optional third argument which is the file to read from and decrypt the text in the second file. If it is not provided the program will read from standard input. 
    - The output of this command will have the text input encrypted using the provided dictionary and shown through standard output.
