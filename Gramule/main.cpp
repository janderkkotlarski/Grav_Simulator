#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "planoid.h"


int main()
{
    const std::string program_name{"Grav Sim"};
    const float win_dim{200};

    const float mass{160.0f};
    const sf::Vector2f posit{30.0f, 60.0f};

    const sf::Color background{0, 0, 0};
    const sf::Color orange{191, 127, 63};

    Planoid planed{mass, posit, orange};

    sf::RenderWindow window(sf::VideoMode(win_dim, win_dim), program_name, sf::Style::Default);

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

        window.clear(background);

        planed.display(window);

        window.display();
    }

    return 1;
}