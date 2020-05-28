#include<iostream>
#include<string>

int main() {
    std::string str;
    std::cin >> str;

    int result = -2;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != 'f') continue;

        if (result == -2) {
            result = -1;
        } else {
            result = i;
            break;
        }
    }

    std::cout << result;
    return 0;
}