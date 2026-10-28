#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    std::fstream file(av[1]);
    std::string content;
    std::string allContent;
    std::string s1(av[2]);
    std::string s2(av[3]);
    while (std::getline(file, content))
    {
        while (content.find(s1) != std::string::npos)
        {
            std::size_t found = content.find(s1);
            std::size_t len = s1.length();
            content.erase(found, len);
            content.insert(found, s2);
        }
        allContent.append(content + "\n");
    }
    std::string fileName(av[1]);
    fileName.insert(fileName.find("."), ".replace");
    std::ofstream fileReplace(fileName);
    fileReplace << allContent;
}