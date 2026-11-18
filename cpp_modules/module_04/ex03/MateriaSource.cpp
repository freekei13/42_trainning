#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): 
    _lastMateriaUsed("none"),
    _materiaCount(0) {}

MateriaSource::MateriaSource(MateriaSource const& src):
    _lastMateriaUsed(src._lastMateriaUsed),
    _materiaCount(src._materiaCount)
{
    for (int i = 0; i < _materiaCount; i++)
        _materia[i] = src._materia[i];
}

MateriaSource::~MateriaSource()
{
    delete[] _materia;
}

MateriaSource&  MateriaSource::operator=(MateriaSource const& rhs)
{
    if (this != &rhs)
    {
        _lastMateriaUsed = rhs._lastMateriaUsed;
        _materiaCount = rhs._materiaCount;
        for (int i = 0; i < _materiaCount; i++)
            _materia[i] = rhs._materia[i];
    }
    return *this;
}

void    MateriaSource::learnMateria(AMateria* src)
{
    if (_materiaCount < 4)
    {
        if (src->getType() == "cure")
        {
            _materia[_materiaCount] = new Cure();
            _materiaCount++;
        }
        else if (src->getType() == "ice")
        {
            _materia[_materiaCount] = new Ice();
            _materiaCount++;
        }
    }
    else
        std::cout << "Can't learn a new Materia, Materia source is full." << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const& type)
{
    if (_materiaCount < 4)
    {
        if (type == "cure")
        {
            _materiaCount++;
            return new Cure();
        }
        else if (type == "ice")
        {
            _materiaCount++;
            return new Ice();
        }
    }
    else
        std::cout << "Can't create a new Materia, Materia source is full." << std::endl;
}

void    MateriaSource::setLastMateriaUsed(std::string const& type)
{
    _materiaCount--;
    delete _materia[_materiaCount];
    _lastMateriaUsed = type;
}

std::string const&  MateriaSource::getLastMateriaUsed() const
{
    return _lastMateriaUsed;
}