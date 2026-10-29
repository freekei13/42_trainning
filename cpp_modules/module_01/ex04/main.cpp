#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: 3 arguments needed" << std::endl;
        return (1);
    }
    if (!av[1][0] || !av[2][0])
    {
        std::cerr << "Error: argument invalide" << std::endl;
        return (1);
    }
    std::ifstream file(av[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: fail to open " << av[1] << std::endl;
        return (1);
    }
    std::string content;
    std::string allContent;
    std::string s1(av[2]);
    std::string s2(av[3]);
    while (std::getline(file, content))
    {
        std::size_t pos = 0;
        while (content.find(s1, pos) != std::string::npos)
        {
            std::size_t found = content.find(s1, pos);
            content.erase(found, s1.length());
            content.insert(found, s2);
            pos += found + s2.length();
        }
        allContent.append(content + "\n");
    }
    std::string fileName(av[1]);
    fileName.append(".replace");
    std::ofstream fileReplace(fileName.c_str());
    if (!fileReplace.is_open())
    {
        std::cerr << "Error: fail to open " << fileName << std::endl;
        return (1);
    }
    std::cout << "Success: " << fileName << " is created: "
        << "\"" << s1 << "\"" << " are replaced by "
        << "\"" << s2 << "\"" << std::endl;
    fileReplace << allContent;
}