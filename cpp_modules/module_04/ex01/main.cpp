#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    
    delete i;
    delete j;

    Animal* animal[100];
    for (int i = 0; i < 100; i++)
    {
        if (i < 50)
            animal[i] = new Cat();
        else
            animal[i] = new Dog();
    }

    for (int i = 0; i < 100; i++)
        animal[i]->makeSound();
    
    for (int i = 0; i < 100; i++)
        delete animal[i];
    
    return 0;
}
