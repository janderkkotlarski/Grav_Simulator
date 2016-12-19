#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "planoid.h"
#include "gravector.h"


int main()
{
    const std::string program_name{"Grav Sim"};
    const float win_dim{600};

    const float fps(40.0f);
    const float spf(1.0f/fps);

    const float deltime{0.001f};

    const int iter_loop{1000};

    const float grav{0.0001f};

    const float mass{160.0f};
    const sf::Vector2f posit{0.5f*win_dim, 0.25f*win_dim};
    const sf::Vector2f posid{0.5f*win_dim, 0.75f*win_dim};
    const sf::Vector2f veloc{0.5f, 0.0f};
    const sf::Vector2f velok{-0.5f, 0.0f};

    const sf::Color background{0, 0, 0};
    const sf::Color orange{191, 127, 63};
    const sf::Color purple{127, 63, 191};

    Planoid planet{mass, posit, veloc, deltime, orange};
    Planoid planed{mass, posid, velok, deltime, purple};

    sf::RenderWindow window(sf::VideoMode(win_dim, win_dim), program_name, sf::Style::Default);

    const float bosit{abso(posit)};

    while(window.isOpen())
    {
        sf::Clock watch;
        sf::Time timer;
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        window.clear(background);

        planet.display(window);
        planed.display(window);

        window.display();

        for (int count{0}; count < iter_loop;++count)
        {
            planet.re_accel();
            planed.re_accel();

            planet.accelide(vectorize(dist(planet.get_posit(), planed.get_posit()), gravit(grav, planet, planed)));
            planed.accelide(vectorize(dist(planed.get_posit(), planet.get_posit()), gravit(grav, planed, planet)));

            planet.move();
            planed.move();
        }

        timing(watch, timer, spf);
    }

    return 1;
}
