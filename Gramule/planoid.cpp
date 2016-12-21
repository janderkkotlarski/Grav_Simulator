#include "planoid.h"

Planoid::Planoid(const float mass, const sf::Vector2f &posit,
                 const sf::Vector2f& veloc, const float deltime,
                 const sf::Color &color)
    :m_mass(mass), m_radi(sqrt(m_mass)/3), m_posit(posit),
     m_veloc(veloc), m_accel(sf::Vector2f(0.0f, 0.0f)),
     m_deltime(deltime), m_color(color), m_circle()
{
    set_circle();
}

Planoid Planoid::becomes(Planoid& planed)
{
    return planed;
}

void Planoid::set_circle()
{
    m_circle.setRadius(m_radi);
    m_circle.setOrigin(m_radi, m_radi);
    m_circle.setPosition(m_posit);
    m_circle.setFillColor(m_color);
}

void Planoid::re_accel()
{
    m_accel = sf::Vector2f(0.0f, 0.0f);
}

void Planoid::accelide(const sf::Vector2f& accel)
{
    m_accel += accel;
}

void Planoid::add_accel()
{
    m_veloc += m_deltime*m_accel;
}

void Planoid::add_veloc()
{
    m_posit += m_deltime*m_veloc;
}

void Planoid::reposit()
{
    m_circle.setPosition(m_posit);
}

void Planoid::move()
{
    add_accel();
    add_veloc();
    reposit();
}

void Planoid::display(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

float Planoid::get_mass()
const noexcept
{
    return m_mass;
}

float Planoid::get_radi()
const noexcept
{
    return m_radi;
}

sf::Vector2f Planoid::get_posit()
const noexcept
{
    return m_posit;
}

sf::Vector2f Planoid::get_veloc()
const noexcept
{
    return m_veloc;
}

sf::Vector2f Planoid::get_accel()
const noexcept
{
    return m_accel;
}

float Planoid::get_deltime()
const noexcept
{
    return m_deltime;
}

sf::Color Planoid::get_color()
const noexcept
{
    return m_color;
}
