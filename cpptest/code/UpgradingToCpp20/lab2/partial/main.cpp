#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <string_view>


// Which of these functions could use std::string_view instead?

bool isPalindrome(const std::string& text) {
    return std::equal(
        text.begin(), text.end(),
        text.rbegin(), text.rend()
    );
}

std::string toAllCaps(const std::string& text) {
    auto result = text;
    for (char& ch : result) {
        ch = std::toupper(ch);
    }
    return result;
}

void openFile(const std::string& fname) {
    FILE *fp = fopen(fname.c_str(), "r");
    if (fp != nullptr) fclose(fp);
}

void printOld(const std::string& text) {
    printf("%s\n", text.c_str());
}

void printNew(const std::string& text) {
    std::cout << text << "\n";
}

int toInt(const std::string& text) {
    return std::stoi(text);
}


int main()
{
    std::string s = "42";
    const char *p = "42";

    (void) isPalindrome(s);
    (void) isPalindrome(p);
    (void) isPalindrome("racecar");

    std::cout << toAllCaps(s) << '\n';
    std::cout << toAllCaps(p) << '\n';
    std::cout << toAllCaps("hello world") << '\n';

    openFile(s);
    openFile(p);
    openFile("hello-world.txt");

    printOld(s);
    printOld(p);
    printOld("hello world");

    printNew(s);
    printNew(p);
    printNew("hello world");

    (void) toInt(s);
    (void) toInt(p);
    (void) toInt("42");
}
