#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "planoid.h"
#include "planetes.h"
#include "gravector.h"


int main()
{
    const std::string program_name{"Grav Sim"};
    const float win_dim{600};

    const float fps(40.0f);
    const float spf(1.0f/fps);

    const float deltime{0.001f};

    const int iter_loop{1000};

    const float grav{0.01f};

    const float mass{100.0f};
    const sf::Vector2f posit{0.5f*win_dim, 0.45f*win_dim};
    const sf::Vector2f posid{0.5f*win_dim, 0.55f*win_dim};
    const sf::Vector2f veloc{1.9f, 0.0f};
    const sf::Vector2f velok{-1.9f, 0.0f};

    const sf::Color background{0, 0, 0};
    const sf::Color orange{191, 127, 63};
    const sf::Color purple{127, 63, 191};
    const sf::Color teal{63, 127, 191};

    Planoid planet{mass, posit, veloc, deltime, orange};
    Planoid planed{mass, posid, velok, deltime, purple};

    Planetes planes(grav, mass, 0.2f*win_dim, win_dim, 5, deltime, teal);

    Gravector gravar;

    sf::RenderWindow window(sf::VideoMode(win_dim, win_dim), program_name, sf::Style::Default);

    // const float bosit{abso(posit)};

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

        // planet.display(window);
        // planed.display(window);

        planes.display(window);

        window.display();

        for (int count{0}; count < iter_loop;++count)
        {
            // planet.re_accel();
            // planed.re_accel();

            // planet.accelide(gravar.vectorize(gravar.dist(planet.get_posit(), planed.get_posit()), gravar.gravit(grav, planet, planed)));
            // planed.accelide(gravar.vectorize(gravar.dist(planed.get_posit(), planet.get_posit()), gravar.gravit(grav, planed, planet)));

            planes.accelerate();
            planes.fusion();

            // planet.move();
            // planed.move();
        }

        gravar.timing(watch, timer, spf);
    }

    return 1;
}
