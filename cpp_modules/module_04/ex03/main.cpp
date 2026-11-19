#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure()); //materia in param is destroyed(delete)
    AMateria* cure = new Cure();
    src->learnMateria(cure);

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);


    //bob->equip(tmp); can not equip the same pointer -> segfault(double free)
    //bob->equip(src->createMateria("ice")); // equip without declare a variable -> cause leak when unequip
    
    AMateria* ice = new Ice();
    AMateria* cur = new Cure();
    bob->equip(ice);
    bob->equip(cur);
    bob->equip(cur);

    bob->use(0, *me);
    bob->use(1, *me);

    bob->unequip(0);
    bob->use(0, *me);

    delete ice; // this materia is unequip, so need to delete.
    delete bob;
    delete me;
    delete src;
    
    return 0;
}