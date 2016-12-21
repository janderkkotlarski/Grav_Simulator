#include "gravector.h"

float Gravector::abso(const sf::Vector2f& vect)
{
    return std::sqrt(vect.x*vect.x + vect.y*vect.y);
}

float Gravector::absqr(const sf::Vector2f& vect)
{
    return vect.x*vect.x + vect.y*vect.y;
}

sf::Vector2f Gravector::dist(const sf::Vector2f& posit_1, const sf::Vector2f& posit_2)
{
    return posit_2 - posit_1;
}

sf::Vector2f Gravector::vectorize(const sf::Vector2f& vect, const float scalar)
{
    return scalar*vect/abso(vect);
}

float Gravector::gravit(const float grav, Planoid& plan_1, Planoid& plan_2)
{
    return grav*plan_1.get_mass()*plan_2.get_mass()/absqr(dist(plan_1.get_posit(), plan_2.get_posit()));
}

float Gravector::rand_to_frac(const unsigned int rand, const unsigned int maxim)
{
    return static_cast<float>(rand)/static_cast<float>(maxim);
}

void Gravector::timing(sf::Clock& watch, sf::Time& timer, const float spf)
{
    // assert(spf> 0.0f);
    timer = watch.getElapsedTime();

    while(timer.asSeconds() < spf)
    {
        timer = watch.getElapsedTime();
    }
}
