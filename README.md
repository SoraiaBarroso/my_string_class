# Welcome to My String
***

## Task
This project aims to create and provide an implementation of a string manipulation class in C++ without relying on 'std::string'. <br>
The challenge includes managing dynamic memory allocation, implementing various string operations, and ensuring compatibility with standard output mechanisms.

## Description
MyString is implemented as a C++ class that encapsulates a character array (char*) and provides methods for string concatenation (operator+, operator+=), substring extraction (substr), pattern replacement (replace), and searching (find, rfind). It also includes comparison methods (operator==, compare) and allows seamless integration with standard output (operator<<). Memory management is handled internally to ensure safety and efficiency.

## Installation
Compile and run:
```
g++ -o MyString my_string.cpp
./MyString
```

## Usage
MyString can be used to manipulate strings dynamically in C++ programs, offering similar functionalities to std::string but with manual memory management. Here's a basic example of how to use it:

```
int main() {
    MyString s1("Hello");
    MyString s2(" world!");

    // Concatenation using operator+
    MyString s3 = s1 + s2;
    std::cout << "Concatenated string: " << s3 << std::endl;

    // Append using operator+=
    s1 += s2;
    std::cout << "Appended string: " << s1 << std::endl;

    return 0;
}
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
