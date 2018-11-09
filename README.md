# Enigma Cryptography
 Virtual German Enigma machine based on the World War 2 cipher machine. Class 11 Year end Project.

## How to Use
1. Download the "CP_FINAL.EXE" file and execute it or download the "CP_FINAL.CPP" file and compile it. 
2. Specify which 3 rotors to use. eg. "4 2 5"
3. Specifiy the starting combination of the rotors. eg. "a t r"
4. Enter your message (only lower case alphabets) and obtain the ciphered text.
5. To decrpyt the message, put the same rotor configurations (steps 2-3) and enter the ciphered text. The original message, without spaces, is displayed.

## Description
The program mimicks the famous World War 2 ENIGMA machines, a series of electro-mechanical rotor cipher machines used by the Germans for secure communication by their armed forces. A typical machine can consist of upto 5 rotors with certain preset configurations (that can be initialised differently by the user) of which the user can chose 3 for message ciphering. Each rotor varyingly maps all 26 letters of the alphabet to different letters. When each letter is ciphered, the rotor configurations keep moving forward, making deciphering exceptionally tricky. Deciphering of the messages is possible through the property of ENIGMA machines that the ciphered message when inputted with the same rotor configurations (as during ciphering) would result in the original message being attained. A detailed explanantion of the rotor mechaism is provided in the "Enigma_Project_Brief."

Note: The older versions of the program are provided for documentation purposes and may not work as they were written on TURBO C++. Files CP_FINAL.CPP and CP7.CPP have been updated to work on modern C++ compilers.
