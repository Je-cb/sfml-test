#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class GButton
{
    public:
        GButton(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& text, const sf::Font& font, unsigned int font_size)
        : m_button(size), m_text(font, text, font_size), init_color(color)
        {
            // Initialize button properties
            m_button.setFillColor(color);
            m_button.setOrigin(size / 2.f);
            m_button.setPosition(position);

            // Initialize text properties
            m_text.setCharacterSize(font_size);
            m_text.setFillColor(sf::Color::White);
            m_text.setStyle(sf::Text::Bold);
            m_text.setOrigin(m_text.getLocalBounds().getCenter());
            m_text.setPosition(m_button.getGlobalBounds().getCenter());
            m_text.setFont(font);
            m_text.setString(text);
            m_text.setStyle(sf::Text::Bold);
        }

        void set_position(const sf::Vector2f& position)
        {
            m_button.setPosition(position);
            m_text.setPosition(m_button.getGlobalBounds().getCenter());
        }

        sf::Vector2f get_position() const
        {
            return m_button.getPosition();
        }

        bool contains(const sf::Vector2f& point) const
        {
            return m_button.getGlobalBounds().contains(point);
        }

        void update(const sf::Vector2f& mouse_position)
        {

            if (contains(mouse_position))
            {
                m_button.setFillColor(sf::Color(100, 100, 100)); // Change color on hover
                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    m_button.setFillColor(sf::Color(50,50,50)); // Change color on click
                    //start or exit game
                }
            }
            else
            {
                m_button.setFillColor(init_color); // Reset color
            }
        }

        void draw(sf::RenderWindow& window)
        {   
            window.draw(m_button);
            window.draw(m_text);
        }

        private:
            sf::RectangleShape m_button;
            sf::Text m_text;
            sf::Color init_color;
};

int main()
{
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Emergency Tycoon");
    window.setFramerateLimit(60);

    //Load background sprite and scale to window 
    sf::Texture bg_texture;
    if(!bg_texture.loadFromFile("E:/Documents/ULA/2025-A/PR3/sfml-test/src/Resources/img/background2.jpg")){}
    sf::Sprite background(bg_texture);
    background.setScale({
        window.getSize().x / background.getLocalBounds().size.x,
        window.getSize().y / background.getLocalBounds().size.y
    });

    // Load Roboto font from file
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

    // Create objects for buttons
    GButton button1({200.f, 50.f}, {window.getSize().x / 2.f, window.getSize().y / 2.f}, sf::Color(87, 144, 116), "Iniciar partida", roboto_regular, 24);
    GButton button2({200.f, 50.f}, {window.getSize().x / 2.f, window.getSize().y / 2.f}, sf::Color(167, 76, 82), "Salir", roboto_regular, 24);
    button2.set_position(button1.get_position() + sf::Vector2f(0.f, 80.f)); // Move button down

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

        //Draw background
        window.draw(background);

        //Draw title
        window.draw(title);

        //Draw buttons
        button1.draw(window);
        button2.draw(window);

        // Update button states
        sf::Vector2f mouse_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        button1.update(mouse_position);
        button2.update(mouse_position);

        window.display();
    }
}
