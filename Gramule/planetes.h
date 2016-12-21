#ifndef PLANETES_H
#define PLANETES_H

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "planoid.h"
#include "gravector.h"

class Planetes
{
    const float m_grav;
    const float m_tau;
    const float m_mass;
    const float m_radius;
    const float m_dim;
    int m_number;
    float m_nomber;
    const float m_phi;
    const float m_mazz;
    const float m_deltime;
    sf::Color m_color;
    std::vector <Planoid> m_planeds;

public:

    Planetes(const float grav, const float mass, const float radius,
             const float dim, const int number, const float deltime,
             const sf::Color& color);

    void balancing();

    void accelerate();

    void fusion();

    void display(sf::RenderWindow& window);
};

#endif // PLANETES_H
