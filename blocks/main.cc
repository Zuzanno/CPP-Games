#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(800,800), "Blocks");
    sf::RectangleShape sq1(sf::Vector2f(50.f, 50.f));
    sf::RectangleShape sq2(sf::Vector2f(50.f, 50.f));
    sf::RectangleShape sq3(sf::Vector2f(50.f, 50.f));
    sf::SoundBuffer sound1;
    sf::SoundBuffer sound2;
    sf::SoundBuffer sound3;
    
    if(!sound1.loadFromFile("chime1.wav"))
    {
        return -1;
    }
    
    if(!sound2.loadFromFile("chime2.wav"))
    {
        return -1;
    }
    
    if(!sound3.loadFromFile("chime3.wav"))
    {
        return -1;
    }
    
    sf::Sound chime1;
    chime1.setBuffer(sound1);
    
    sf::Sound chime2;
    chime2.setBuffer(sound2);
    
    sf::Sound chime3;
    chime3.setBuffer(sound3);
    
    sq1.setFillColor(sf::Color::Red);
    sq2.setFillColor(sf::Color::Green);
    sq3.setFillColor(sf::Color::Blue);
    
    float stepx1 = 1.3;
    float stepy1 = 1.3;
     
    float stepx2 = 0.05;
    float stepy2 = 0.05;
    
    float stepx3 = 5.5;
    float stepy3 = 0.1;
    
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(144);
    
    sq1.setPosition(400.f, 350.f);
    sq2.setPosition(400.f, 400.f);
    sq3.setPosition(400.f, 350.f);
    
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        
        if(sq1.getPosition().x > 750)
        {
            stepx1 = -1.25;
            chime2.setPitch(1.5);
            chime2.play();
        }
        else if(sq1.getPosition().x < 0)
        {
            stepx1 = 1.25;
            chime2.setPitch(1.5);
            chime2.play();
        }
        if(sq1.getPosition().y > 750)
        {
            stepy1 = -1.25;
            chime2.setPitch(1.f);
            chime2.play();
        }
        else if(sq1.getPosition().y < 0)
        {
            stepy1 = 1.25;
            chime2.setPitch(1.f);
            chime2.play();
        }
        
        if(sq2.getPosition().x > 750)
        {
            stepx2 = -0.05;
            chime3.play();
        }
        else if(sq2.getPosition().x < 0)
        {
            stepx2 = 0.05;
            chime3.play();
        }
        if(sq2.getPosition().y > 750)
        {
            stepy2 = -0.05;
            chime3.play();
        }
        else if(sq2.getPosition().y < 0)
        {
            stepy2 = 0.05;
            chime3.play();
        }
        
        if(sq3.getPosition().x > 750)
        {
            stepx3 = -5.5;
            chime1.setPitch(0.8);
            chime1.play();
        }
        else if(sq3.getPosition().x < 0)
        {
            stepx3 = 5.5;
            chime1.setPitch(1.f);
            chime1.play();
        }
        if(sq3.getPosition().y > 750)
        {
            stepy3 = -0.1;
            chime1.play();
        }
        else if(sq3.getPosition().y < 0)
        {
            stepy3 = 0.1;
            chime1.play();
        }
        
        sq1.move(stepx1, stepy1);
        sq2.move(stepx2, stepy2);
        sq3.move(stepx3, stepy3);
        
        window.clear(sf::Color::Black);
        window.draw(sq1);
        window.draw(sq2);
        window.draw(sq3);
        window.display();
    }
    return 0;        
}