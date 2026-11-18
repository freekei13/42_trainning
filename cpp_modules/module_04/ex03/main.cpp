#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure()); 

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);


    // bob->equip(tmp); can not equip the same pointer -> segfault(double free)
    bob->equip(src->createMateria("ice")); // equip without declare a variable -> cause leak when unequip
    bob->equip(src->createMateria("cure"));
    bob->equip(src->createMateria("ice"));
    bob->equip(src->createMateria("cure"));
    bob->equip(src->createMateria("ice"));

    bob->use(0, *me);
    bob->use(1, *me);

    bob->unequip(0);
    bob->use(0, *me);

    delete bob;
    delete me;
    delete src;
    
    return 0;
}