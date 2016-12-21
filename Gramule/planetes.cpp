#include "planetes.h"


Planetes::Planetes(const float grav, const float mass, const float radius,
                   const float dim, const int number, const float deltime,
                   const sf::Color& color)
    : m_grav(grav), m_tau(2.0f*std::acos(-1)), m_mass(mass), m_radius(radius), m_dim(dim),
      m_number(number), m_nomber(static_cast<float>(number)), m_phi(m_tau/m_nomber),
      m_mazz(m_mass/m_nomber), m_deltime(deltime), m_color(color), m_planeds()
{
    balancing();
}

void Planetes::balancing()
{
    float force{0.0f};

    float kount{1.0f};

    for (int count{1}; count < m_number; ++count)
    {
        const float w_x{-m_radius*std::sin(m_tau*kount/m_nomber)};
        const float w_y{m_radius*(1 - std::cos(m_tau*kount/m_nomber))};

        const float w_2{w_x*w_x + w_y*w_y};

        const float forke{m_mazz*m_mazz*m_grav/w_2};

        force += forke*std::sin(0.5f*m_tau*kount/m_nomber);

        kount += 1.0f;
    }

    const float weloc{5.0f*std::sqrt(force*m_radius/m_mazz)};

    const sf::Vector2f mids{0.5f*m_dim, 0.5f*m_dim};

    kount = 0.0f;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::minstd_rand0 rand(seed);

    const unsigned int maxim{rand.max()};


    float randy{0.0f};



    Gravector gravar;

    for (int count{0}; count < m_number; ++count)
    {

        randy = gravar.rand_to_frac(rand(), maxim);

        const sf::Vector2f wan{randy*m_radius*std::sin(m_tau*kount/m_nomber),
                               randy*-m_radius*std::cos(m_tau*kount/m_nomber)};

        const sf::Vector2f posit{mids + wan};

        randy = gravar.rand_to_frac(rand(), maxim);

        randy = 0.0f;

        const sf::Vector2f veloc{randy*weloc*std::cos(m_tau*kount/m_nomber),
                                 randy*weloc*std::sin(m_tau*kount/m_nomber)};


        Planoid planed(m_mazz, posit, veloc, m_deltime, m_color);

        m_planeds.push_back(planed);

        kount += 1.0f;
    }
}

void Planetes::accelerate()
{
    for (int count{0}; count < m_number; ++count)
    {
        m_planeds[count].re_accel();
    }

    Gravector gravar;

    for (int count{0}; count < m_number - 1; ++count)
    {
        for (int kount{count + 1}; kount < m_number; ++kount)
        {
            m_planeds[count].accelide(gravar.vectorize(gravar.dist(m_planeds[count].get_posit(),
            m_planeds[kount].get_posit()), gravar.gravit(m_grav, m_planeds[count], m_planeds[kount])));
            m_planeds[kount].accelide(gravar.vectorize(gravar.dist(m_planeds[kount].get_posit(),
            m_planeds[count].get_posit()), gravar.gravit(m_grav, m_planeds[kount], m_planeds[count])));
        }
    }

    for (int count{0}; count < m_number; ++count)
    {
        m_planeds[count].move();
    }
}

void Planetes::fusion()
{
    Gravector gravar;

    for (int count{0}; count < m_number - 1; ++count)
    {
        for (int kount{count + 1}; kount < m_number; ++kount)
        {
            if (gravar.abso(gravar.dist(m_planeds[count].get_posit(), m_planeds[kount].get_posit())) < m_planeds[count].get_radi() + m_planeds[kount].get_radi())
            {
                const float mass_a{m_planeds[count].get_mass()};
                const float mass_b{m_planeds[kount].get_mass()};
                const float mass_c{mass_a + mass_b};

                const sf::Vector2f posit_a{m_planeds[count].get_posit()};
                const sf::Vector2f posit_b{m_planeds[kount].get_posit()};
                const sf::Vector2f posit_c{(mass_a*posit_a + mass_b*posit_b)/mass_c};

                const sf::Vector2f veloc_a{m_planeds[count].get_veloc()};
                const sf::Vector2f veloc_b{m_planeds[kount].get_veloc()};
                const sf::Vector2f veloc_c{(mass_a*veloc_a + mass_b*veloc_b)/mass_c};

                Planoid planed(mass_c, posit_c, veloc_c, m_planeds[count].get_deltime(), m_planeds[count].get_color());

                std::vector <Planoid> planets;

                for (int qount{0}; qount < count; ++qount)
                {
                    planets.push_back(m_planeds[qount]);
                }

                for (int qount{count + 1}; qount < kount; ++qount)
                {
                    planets.push_back(m_planeds[qount]);
                }

                for (int qount{kount + 1}; qount < m_planeds.size(); ++qount)
                {
                    planets.push_back(m_planeds[qount]);
                }

                while (m_planeds.size() > 0)
                {
                    m_planeds.pop_back();
                }

                for (int qount{0}; qount < planets.size(); ++qount)
                {
                    m_planeds.push_back(planets[qount]);
                }

                m_planeds.push_back(planed);

                m_number = m_planeds.size();
                m_nomber = static_cast<float>(m_number);
            }
        }
    }
}

void Planetes::display(sf::RenderWindow& window)
{
    for (int count{0}; count < m_number; ++count)
    {
        m_planeds[count].display(window);
    }
}
