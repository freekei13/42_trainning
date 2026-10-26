#include "Zombie.hpp"

int main()
{
    Zombie* heapZombie = newZombie("Henry");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Pierre");
}