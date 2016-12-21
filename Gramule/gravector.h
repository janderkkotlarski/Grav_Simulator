#ifndef GRAVECTOR_H
#define GRAVECTOR_H

#include <cmath>
#include <SFML/Graphics.hpp>

#include "planoid.h"

class Gravector
{
public:
    float abso(const sf::Vector2f& vect);

    float absqr(const sf::Vector2f& vect);

    sf::Vector2f dist(const sf::Vector2f& posit_1, const sf::Vector2f& posit_2);

    sf::Vector2f vectorize(const sf::Vector2f& vect, const float scalar);

    float gravit(const float grav, Planoid& plan_1, Planoid& plan_2);

    float rand_to_frac(const unsigned int rand, const unsigned int maxim);

    void timing(sf::Clock& watch, sf::Time& timer, const float spf);

};

#endif // GRAVECTOR_H
