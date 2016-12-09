#include "planoid.h"

Planoid::Planoid(const float mass, const sf::Vector2f &posit, const sf::Color &color)
    :m_mass(mass), m_radi(sqrt(m_mass)), m_posit(posit),
     m_veloc(sf::Vector2f(0.0f, 0.0f)), m_accel(sf::Vector2f(0.0f, 0.0f)),
     m_color(color), m_circle()
{
    set_circle();
}

void Planoid::set_circle()
{
    m_circle.setRadius(m_radi);
    m_circle.setOrigin(m_radi, m_radi);
    m_circle.setPosition(m_posit);
    m_circle.setFillColor(m_color);
}

void Planoid::display(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

sf::Vector2f Planoid::get_posit()
const noexcept
{
    return m_posit;
}
