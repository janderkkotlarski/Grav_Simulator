#ifndef PLANOID_H
#define PLANOID_H

#include <cmath>
#include <SFML/Graphics.hpp>

class Planoid
{
    float m_mass;
    float m_radi;

    sf::Vector2f m_posit;
    sf::Vector2f m_veloc;
    sf::Vector2f m_accel;

    sf::Color m_color;
    sf::CircleShape m_circle;

public:

    Planoid(const float mass, const sf::Vector2f& posit, const sf::Color& color);

    void set_circle();

    void display(sf::RenderWindow& window);

    sf::Vector2f get_posit() const noexcept;
};

#endif // PLANOID_H
