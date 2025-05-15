#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GButton
{
    public:
        GButton(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& text, const sf::Font& font, unsigned int font_size);

        void set_position(const sf::Vector2f& position);

        sf::Vector2f get_position() const;

        bool contains(const sf::Vector2f& point) const;

        void update(const sf::Vector2f& mouse_position);

        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape m_button;
        sf::Text m_text;
        sf::Color init_color;
};