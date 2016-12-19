#ifndef PLANETES_H
#define PLANETES_H

#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "planoid.h"

class Planetes
{
    int m_number;
    std::vector <Planoid> m_planeds;



public:

    Planetes(const int number);


    // planed

    void add_planed();

};

#endif // PLANETES_H
