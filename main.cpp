//
// Created by ozgur ural on 28/11/21.
//

#include <stdlib.h>

#include <iostream>
#include <vector>

#define ZERO 0
#define ALPHABETH_LENGTH 26
#define ASCII32 32
#define ASCIIA 65
#define ASCIIZU 90
#define ASCIIAL 97
#define ASCIIZL 122

std::vector<char> message;
std::vector<char> encrypted_message;
std::vector<char> decrpyted_message;

int* p;
unsigned int i;
size_t length;

void toUpperCase(std::vector<char>& text, int length)
{
    for (i = 0; i < length; i++) {
        if (text[i] >= ASCIIAL && text[i] <= ASCIIZL) {
            text[i] -= ASCII32;
        }
    }
}

void printString(std::vector<char> text, int length)
{
    for (i = 0; i < length; i++) {
        std::cout << static_cast<char>(text[i] + ASCIIA);
    }
    std::cout << std::endl;
}

size_t getInput(std::vector<char>& message)
{
    char a;
    while (1) {
        a = getchar();
        if (a == '\n') {
            break;
        }
        else if ((a >= 'A' && a <= 'Z') || (a >='a' && a <= 'z')) {
            message.push_back(a); 
        }
    }
    return message.size();
}

void getUserInput() {
    length = getInput(message);
    toUpperCase(message, length);
}

void randomKeyGenerator() {
    for (i = 0; i < length; i++) {
        std::cout << static_cast<char>(p[i] + ASCIIA);
    }
    std::cout << std::endl;
}

void decryptMessage() {
    for (i = 0; i < length; i++) {
        if ((encrypted_message[i] - p[i]) < ZERO) {
            decrpyted_message.push_back(static_cast<char>(encrypted_message[i] - p[i] + ALPHABETH_LENGTH));
        }
        else if ((encrypted_message[i] - p[i]) >= ZERO) {
            decrpyted_message.push_back(static_cast<char>(encrypted_message[i] - p[i]));
        }
        else {
            decrpyted_message.push_back(static_cast<char>(encrypted_message[i]));
        }
    }
    printString(decrpyted_message, length);
}

void encryptMessage() {
    p = (int*)malloc(message.size() * sizeof(int));

    for (i = 0; i < length; i++) {
        p[i] = rand() % ALPHABETH_LENGTH;
        if (message[i] >= ASCIIA && message[i] <= ASCIIZU) {
            encrypted_message.push_back(static_cast<char>((message[i] - ASCIIA + p[i]) % ALPHABETH_LENGTH));
        }
        else if (message[i] >= ASCIIAL && message[i] <= ASCIIZL) {
            encrypted_message.push_back(static_cast<char>((message[i] - ASCIIAL + p[i]) % ALPHABETH_LENGTH));
        }
        else {
            encrypted_message.push_back(static_cast<char>(message[i]));
        }
    }
    printString(encrypted_message, length);
}

int main() {

    // Initialize random number generator
    srand (time(nullptr));

    std::cout << std::endl << "Enter Message to Encrypt:" << std::endl;
    getUserInput();

    std::cout << std::endl << "Encypted Message:" << std::endl;
    encryptMessage();

    std::cout << std::endl << "Key for decryption:" << std::endl;
    randomKeyGenerator();

    std::cout << std::endl << "Decrypted Message:" << std::endl;
    decryptMessage();

    return 0;
}