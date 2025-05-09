#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Emergency Tycoon");
    window.setFramerateLimit(60);

    // Load Roboto roboto_regular from file
    sf::Font roboto_regular("E:/Documents/ULA/2025-A/PR3/sfml-test/src/Resources/Roboto/static/Roboto-Regular.ttf");
    sf::Font roboto_bold("E:/Documents/ULA/2025-A/PR3/sfml-test/src/Resources/Roboto/static/Roboto-Bold.ttf");

    // Title text
    sf::Text title(roboto_bold);
    title.setString("EMERGENCY TYCOON");
    title.setCharacterSize(72);
    title.setFillColor(sf::Color(240, 224, 149));
    title.setStyle(sf::Text::Bold);
    title.setOrigin(title.getLocalBounds().getCenter());
    title.setPosition(sf::Vector2f(window.getSize())/2.f);
    title.move(sf::Vector2f(0.f, -250.f)); //Move title up
    
    // Button 1 component
    sf::RectangleShape btn_1({200.f, 50.f});
    btn_1.setFillColor(sf::Color(87, 144, 116));
    btn_1.setPosition(sf::Vector2f(window.getSize())/2.f - sf::Vector2f(btn_1.getSize())/2.f);

    // Button 1 text
    sf::Text btn_txt_1(roboto_regular);
    btn_txt_1.setString("Iniciar partida");
    btn_txt_1.setCharacterSize(24);
    btn_txt_1.setFillColor(sf::Color::White);
    btn_txt_1.setStyle(sf::Text::Bold);
    btn_txt_1.setOrigin(btn_txt_1.getLocalBounds().getCenter());
    btn_txt_1.setPosition({btn_1.getGlobalBounds().getCenter()});

    // Button 2 component
    sf::RectangleShape btn_2({200.f, 50.f});
    btn_2.setFillColor(sf::Color(167, 76, 82));
    btn_2.setPosition(sf::Vector2f(window.getSize())/2.f - sf::Vector2f(btn_2.getSize())/2.f);
    btn_2.move(sf::Vector2f(0.f, 80.f)); // Move button down

    // Button 2 text
    sf::Text btn_txt_2(roboto_regular);
    btn_txt_2.setString("Salir");
    btn_txt_2.setCharacterSize(24);
    btn_txt_2.setFillColor(sf::Color::White);
    btn_txt_2.setStyle(sf::Text::Bold);
    btn_txt_2.setOrigin(btn_txt_2.getLocalBounds().getCenter());
    btn_txt_2.setPosition({btn_2.getGlobalBounds().getCenter()});

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

        //Draw title
        window.draw(title);

        // Draw button 1
        window.draw(btn_1);
        window.draw(btn_txt_1);

        // Draw button 2
        window.draw(btn_2);
        window.draw(btn_txt_2);

        window.display();
    }
}
