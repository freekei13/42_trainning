#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wC = new WrongCat();
    std::cout << wC->getType() << " " << std::endl;
    wC->makeSound();
    delete wC;
    
    delete i;
    delete j;
    delete meta;
    return 0;
}
