#include <cstddef>
#include <iostream>
#include <cstring>
#include <string>

class MyString {
    public:
        // Default constructor no arguments
        // MyString s1;
        MyString() : str(nullptr) {
            str = new char[1];
            str[0] = '\0';
        }

        // Constructor one argument 
        // Example: MyString s1("Hello");
        MyString(const char* string) {
            setString(string);
        }
        
        // Constructor copy another object
        // Example: const MyString s4 = s2;
        MyString(const MyString& other) {
            setString(other.str);
        }

        ~MyString() {
            delete str;
        }

        // Conversion from string to C char
        void setString(const char* new_string) {
            size_t length = strlen(new_string); 
            str = new char[length + 1];
            strcpy(str, new_string);
        }

        /* 
            Value swap copy
            MyString c;
            MyString u = "qwasar";
            c = u;
        */
        MyString& operator=(const MyString& other_string) {
            if (this != &other_string) {
                delete str;
                setString(other_string.str);
            }
            return *this;
        }

        // Concat strings with + return a new object
        MyString operator+(const MyString& other_string) const {
            size_t length = strlen(this->str) + strlen(other_string.str) + 1;
            char* new_str = new char[length];
            strcpy(new_str, this->str);
            strcat(new_str, other_string.str);
            MyString result(new_str);
            return result;
        }

        // Append with += to the end of this string
        MyString& operator+=(const MyString& other_string) {
            size_t additional_length = strlen(other_string.str);
            size_t current_length = strlen(this->str);
            char* new_str = new char[additional_length + current_length + 1];
            strcpy(new_str, this->str);
            strcat(new_str, other_string.str);
            delete str;
            str = new_str;
            return *this;
        }

        // append with append() calling += operator
        void append(const char* other) {
            *this += other;
        }

        void append(const MyString& other) {
            *this += other;
        }
        
        // find starting from the beggining string object
        size_t find(char ch) const {
            return find(ch, this->str);
        }

        // find starting from the beggining any given string
        size_t find(char ch, const char* string) const {
            size_t len = strlen(str);

            for (size_t i = 0; i < len; i++) {
                if (str[i] == ch) {
                    return i;
                } 
            }

            return std::string::npos;
        }

        // rfind starting from the beggining string object
        size_t rfind(char ch) const {
            return rfind(ch, this->str);
        }

        // rfind starting from the end any given string
        size_t rfind(char ch, const char* string) const {
            size_t len = strlen(string);

            for (size_t i = len; i > 0; i--) {
                if (string[i - 1] == ch) {
                    return i - 1;
                } 
            }

            return std::string::npos;
        }

        // Substr
        MyString substr(size_t pos, size_t len) {
            char* new_str = new char[len + 1];
            size_t index = 0;

            for (size_t i = pos; len > 0; len--, i++, index++) {
                new_str[index] = str[i];
            }

            new_str[index] = '\0';
            MyString result(new_str);
            delete [] new_str;
            return result;
        }

        // Compare with compare() and operator==()
        int compare(const MyString& other) const {
            return strcmp(this->str, other.str);
        }

        bool operator==(const MyString& other) const {
            return compare(other) == 0;
        }

        char& operator[](size_t index) {
            return str[index];
        }

        // operator<<
        friend std::ostream& operator<<(std::ostream& os, const MyString& string) {
            os << string.c_str();
            return os;
        }

        // return pointer to array that contains a null-terminated sequence of characters (i.e., a C-string) 
        const char* c_str() const {
            return str;
        }

        size_t size() const {
            return strlen(str);
        }
    private:
        char* str;
};