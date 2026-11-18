#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._materia[i])
            _materia[i] = src._materia[i]->clone();
        else
            _materia[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _materia[i];
}

MateriaSource&  MateriaSource::operator=(MateriaSource const& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _materia[i];
            if (rhs._materia[i])
                _materia[i] = rhs._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
    }
    return *this;
}

void    MateriaSource::learnMateria(AMateria* src)
{
    if (!src)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = src;
            std::cout << src->getType() << " materia learn." << std::endl;
            return ;
        }
    }
    delete src;
    std::cout << "Can not learn Materia, source is full." << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
        {
            std::cout << type << " materia created." << std::endl;
            return _materia[i]->clone();
        }
    }
    std::cout << "Can not create " << type;
    std::cout << " Materia, source has not known this type." << std::endl;
    return 0;
}
