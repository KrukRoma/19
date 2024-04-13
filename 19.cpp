#include <iostream>

using namespace std;

class String {
private:
    static int objectCount; 
    char* str; 
    int length; 

public:
    String() : String(80) {}

    String(int size) : length(size) {
        str = new char[length + 1];
        objectCount++;
    }

    String(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            length++;
        }
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = s[i];
        }
        str[length] = '\0';
        objectCount++;
    }

    ~String() {
        delete[] str;
        objectCount--;
    }

    void input() {
        cout << "Enter a string: ";
        cin.getline(str, length);
    }

    void display() const {
        cout << "String: " << str << endl;
    }

    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

int main() {
    String s1;
    s1.input();
    s1.display();

    String s2(50);
    s2.input();
    s2.display();

    String s3("Hello, world!");
    s3.display();

    cout << "Number of created string objects: " << String::getObjectCount() << endl;

    return 0;
}

