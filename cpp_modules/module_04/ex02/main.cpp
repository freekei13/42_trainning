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

    const Animal* animal[100];
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

    Dog* a = new Dog();

    for (int i = 0; i < 100; i++)
        a->setIdea(i, "Idea_");
    for (int i = 0; i < 100; i++)
        std::cout << "a: " << &a->getIdea(i) << std::endl;
    for (int i = 0; i < 100; i++)
        std::cout << "a: " << a->getIdea(i) << std::endl;
    Dog* b = new Dog();
    *b = *a;
    for (int i = 0; i < 100; i++)
        std::cout << "b: " << b->getIdea(i) << std::endl;
    for (int i = 0; i < 100; i++)
        std::cout << "b: " << &b->getIdea(i) << std::endl;
    for (int i = 0; i < 100; i++)
        b->setIdea(i, "Dog Idea");
    for (int i = 0; i < 100; i++)
        std::cout << "b: " << b->getIdea(i) << std::endl;
    for (int i = 0; i < 100; i++)
        std::cout << "a: " << a->getIdea(i) << std::endl;
    
    Dog* c = new Dog(*a);
    for (int i = 0; i < 100; i++)
        std::cout << "c: " << c->getIdea(i) << std::endl;
    for (int i = 0; i < 100; i++)
        c->setIdea(i, "Other Idea");
    for (int i = 0; i < 100; i++)
        std::cout << "c: " << c->getIdea(i) << std::endl;
    for (int i = 0; i < 100; i++)
        std::cout << "a: " << a->getIdea(i) << std::endl;

    c->setIdea(101, "test idea");
    std::cout << c->getIdea(103) << std::endl;

    
    delete a;
    delete b;
    delete c;

    return 0;
}
