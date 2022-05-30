#include <algorithm>
#include <charconv>
#include <cstdio>
#include <iostream>
#include <string>
#include <string_view>


// Which of these functions could use std::string_view instead?

bool isPalindrome(std::string_view text) { // no change
    return std::equal(
        text.begin(), text.end(),
        text.rbegin(), text.rend()
    );
}

std::string toAllCaps(std::string_view text) {
    auto result = std::string(text);  // explicit conversion needed
    for (char& ch : result) {
        ch = std::toupper(ch);
    }
    return result;
}

void openFile(const std::string& fname) {
    FILE *fp = fopen(fname.c_str(), "r");
    if (fp != nullptr) fclose(fp);
}

void printOld(std::string_view text) {
    printf("%.*s\n", static_cast<int>(text.size()), text.data());
}

void printNew(std::string_view text) { // no change
    std::cout << text << "\n";
}

int toInt(const std::string& text) {
    return std::stoi(text);
}

int toIntAlternative(std::string_view text) {

    // `stoi` is affected by the current locale; `from_chars` is not.

    // `from_chars` is low-level to a degree approaching self-parody.
    // If you use it in your codebase, please treat it like raw `new`;
    // write it only once, inside some helper function, and then use
    // the helper function.

    int result;
    const char *last = text.data() + text.size();
    auto [ptr, ec] = std::from_chars(text.data(), last, result);
    if (ec != std::errc() || (ptr != last)) {
        result = 0;
    }
    return result;
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
