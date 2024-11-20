#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;

public:
    MyString(const char* s = nullptr) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy_s(str, strlen(s) + 1, s);
        }
        else {
            str = new char[1];
            str[0] = '\0';
        }
    }

    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
    }

    ~MyString() {
        delete[] str;
    }

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);
        return *this;
    }

    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString s1("Hello, world!");
    MyString s2 = s1;
    s1.display();
    s2.display();
    MyString s3;
    s3 = s1;
    s3.display();
    return 0;
}
