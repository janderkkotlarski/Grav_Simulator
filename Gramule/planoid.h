#ifndef PLANOID_H
#define PLANOID_H

#include <cmath>
#include <SFML/Graphics.hpp>

class Planoid
{
    const float m_mass;
    float m_radi;

    sf::Vector2f m_posit;
    sf::Vector2f m_veloc;
    sf::Vector2f m_accel;

    const float m_deltime;

    sf::Color m_color;
    sf::CircleShape m_circle;

    void set_circle();

    void add_accel();

    void add_veloc();

    void reposit();


public:

    Planoid(const float mass, const sf::Vector2f& posit,
            const sf::Vector2f& veloc, const float deltime,
            const sf::Color& color);

    Planoid becomes(Planoid& planed);

    void move();

    void re_accel();

    void accelide(const sf::Vector2f& accel);

    void display(sf::RenderWindow& window);

    float get_mass() const noexcept;

    float get_radi() const noexcept;

    sf::Vector2f get_posit() const noexcept;

    sf::Vector2f get_veloc() const noexcept;

    sf::Vector2f get_accel() const noexcept;

    float get_deltime() const noexcept;

    sf::Color get_color() const noexcept;
};

#endif // PLANOID_H
