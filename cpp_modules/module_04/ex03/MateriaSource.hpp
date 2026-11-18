#ifndef	MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class   MateriaSource: public IMateriaSource
{
    private:
        AMateria*   _materia[4];
    public:
        MateriaSource();
        MateriaSource(MateriaSource const& src);
        ~MateriaSource();
        MateriaSource&  operator=(MateriaSource const& rhs);

        void    learnMateria(AMateria* src);
        AMateria*   createMateria(std::string const& type);
};

#endif