#include <iostream>
#include <string>

int main()
{
    std::string stringVar = "HI THIS IS BRAIN";
    std::string* stringPtr = &stringVar;
    std::string& stringRef = stringVar;

    std::cout << "The memory address of stringVar: " << &stringVar << std::endl;
    std::cout << "The memory address held by stringPtr: " << stringPtr << std::endl;
    std::cout << "The memory address held by stringRef: " << &stringRef << std::endl;
    std::cout << std::endl;
    std::cout << "The value of stringVar: " << stringVar << std::endl;
    std::cout << "The value pointed by stringPtr: " << *stringPtr << std::endl;
    std::cout << "The value pointed by stringRef: " << stringRef << std::endl;
}