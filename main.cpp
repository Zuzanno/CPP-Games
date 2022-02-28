#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

    sf::RenderWindow window(sf::VideoMode(1200,1000), "Pong!");
    sf::RectangleShape pl1(sf::Vector2f(50.f, 200.f));
    sf::RectangleShape pl2(sf::Vector2f(50.f, 200.f));
    sf::RectangleShape ball(sf::Vector2f(25.f,25.f));
    sf::FloatRect BallHitbox = ball.getGlobalBounds();
    sf::FloatRect pl1Hitbox = pl1.getGlobalBounds();
    sf::FloatRect pl2Hitbox = pl2.getGlobalBounds();
    float stepx = 6.f;
    float ystep = 6.f;
    float stepy = 6.f;
    
    
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(144);
    
    //Rectangle 1 pos
    pl1.setPosition(10.f, 400.f);
    pl2.setPosition(1140.f,400.f);
    ball.setPosition(590.f,480.f);
    
    while(window.isOpen())
    { 
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            
        }
        
        //Rect1 movement
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            pl1.move(0.f,6.f);
            pl1.move(0.f,0.f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            pl1.move(0.f,-6.f);
            pl1.move(0.f,0.f);
        }
        
        //Rect2 Movement
        if(pl2.getPosition().y >= 800)
        {
            ystep = -6.f;
        }
        else if(pl2.getPosition().y <= 0)
        {
            ystep = 6.f;
        }
        
        pl2.move(0.f, ystep);
        
        /*//Ball bounds
        if(BallHitbox.intersects(pl1.getGlobalBounds()))
        {
            if(ball.getPosition().x >  pl1.getPosition().x)
            {
                stepx = -6.f;
            }
            else if(ball.getPosition().x < 0)
            {
                stepx = 6.f;
            }
            if(ball.getPosition().y > pl1.getPosition().y)
            {
                stepy = -6.f;
            }
            else if(ball.getPosition().y < 0)
            {
                stepy = 6.f;
            }
            
            ball.move(stepx, stepy);    
        }*/
        
        //Rect1 Collision
            //Top Collision
        if(pl1.getPosition().y <= 0)
        {
            pl1.setPosition(pl1.getPosition().x, 0.f);    
        } 
            //Bottom Collision
        if(pl1.getPosition().y >= 800)
        {
            pl1.setPosition(pl1.getPosition().x, 800.f);
        }
        //Test ball collision
        if(ball.getPosition().x >= 60)
        {
            ball.setPosition(ball.getPosition().x, ball.getPosition().y);   
        }
        
        //rect2 Collision
            //Top Collision
        if(pl2.getPosition().y <= 0)
        {
            pl2.setPosition(pl2.getPosition().x, 0.f);
        }
        if(pl2.getPosition().y >= 800)
        {
            pl2.setPosition(pl2.getPosition().x, pl2.getPosition().y);
        }
            
        //Ball movement
        if(ball.getPosition().x >  1190)
        {
            stepx = -6.f;
        }
        else if(ball.getPosition().x < 0)
        {
            stepx = 6.f;
        }
        if(ball.getPosition().y > 990)
        {
            stepy = -6.f;
        }
        else if(ball.getPosition().y < 0)
        {
            stepy = 6.f;
        }	
        
        ball.move(stepx, stepy);
        
        
        window.clear(sf::Color::Black);
        window.draw(pl1);
        window.draw(pl2);
        window.draw(ball);
        window.display();
        
    }
    
    return 0;

}