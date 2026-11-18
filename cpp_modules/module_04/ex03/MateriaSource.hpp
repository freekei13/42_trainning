#ifndef	MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class   MateriaSource: public IMateriaSource
{
    private:
        std::string _lastMateriaUsed;
        AMateria*   _materia[4];
        int         _materiaCount;
    public:
        MateriaSource();
        MateriaSource(MateriaSource const& src);
        ~MateriaSource();
        MateriaSource&  operator=(MateriaSource const& rhs);

        void    learnMateria(AMateria* src);
        AMateria*   createMateria(std::string const& type);
        void    setLastMateriaUsed(std::string const& type);
        std::string const&    getLastMateriaUsed() const;
};

#endif