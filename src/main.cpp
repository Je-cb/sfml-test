#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Emergency Tycoon");
    window.setFramerateLimit(60);

    // Load Roboto font form file
    sf::Font font("E:/Documents/ULA/2025-A/PR3/sfml-test/src/Resources/Roboto/static/Roboto-Regular.ttf");
    
    // Temporary position
    sf::Vector2f pos(50.f, 50.f);

    // Button 1 text
    sf::Text btn_txt_1(font);
    //btn_txt_1.setPosition(pos);
    btn_txt_1.setString("Button 1");
    btn_txt_1.setCharacterSize(24);
    btn_txt_1.setFillColor(sf::Color::White);
    btn_txt_1.setStyle(sf::Text::Bold);

    // Button 2 text
    sf::Text btn_txt_2(font);
    btn_txt_2.setString("Button 2");
    btn_txt_2.setCharacterSize(24);
    btn_txt_2.setFillColor(sf::Color::White);
    btn_txt_2.setStyle(sf::Text::Bold);

    // Button component
    sf::RectangleShape btn({200.f, 50.f});
    btn.setFillColor(sf::Color(87, 144, 116));
    btn.setPosition(pos);

    btn_txt_1.setPosition(btn.getPosition() + (btn.getSize() / 2.f));

    while (window.isOpen())
    {
        
        while (const std::optional event = window.pollEvent())
        {
            
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();

        window.draw(btn);
        window.draw(btn_txt_1);

        window.display();
    }
}
