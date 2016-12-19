#ifndef GRAVECTOR_H
#define GRAVECTOR_H

#include <cmath>
#include <SFML/Graphics.hpp>


float abso(const sf::Vector2f& vect)

{
    return sqrt(vect.x*vect.x + vect.y*vect.y);
}

sf::Vector2f dist(const sf::Vector2f& posit_1, const sf::Vector2f& posit_2)
{
    return posit_2 - posit_1;
}

sf::Vector2f vectorize(const sf::Vector2f& vect, const float scalar)
{
    return scalar*vect/abso(vect);
}

float gravit(const float grav, Planoid& plan_1, Planoid& plan_2)
{
    return grav*plan_1.get_mass()*plan_2.get_mass()/abso(dist(plan_1.get_posit(), plan_2.get_posit()));
}

void timing(sf::Clock& watch, sf::Time& timer, const float spf)
{
    // assert(spf> 0.0f);
    timer = watch.getElapsedTime();

    while(timer.asSeconds() < spf)
    {
        timer = watch.getElapsedTime();
    }
}

#endif // GRAVECTOR_H
