#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "planoid.h"
#include "gravector.h"


int main()
{
    const std::string program_name{"Grav Sim"};
    const float win_dim{600};

    const float deltime{0.001f};

    const int iter_loop{10};

    const float mass{160.0f};
    const sf::Vector2f posit{30.0f, 60.0f};
    const sf::Vector2f veloc{0.5f, 0.0f};

    const sf::Color background{0, 0, 0};
    const sf::Color orange{191, 127, 63};

    Planoid planed{mass, posit, veloc, deltime, orange};

    sf::RenderWindow window(sf::VideoMode(win_dim, win_dim), program_name, sf::Style::Default);

    const float bosit{abso(posit)};

    while(window.isOpen())
    {
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

        planed.display(window);

        window.display();

        for (int count{0}; count < iter_loop;++count)
        {
            planed.move();
        }
    }

    return 1;
}
