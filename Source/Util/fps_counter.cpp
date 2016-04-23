#include "fps_counter.h"

#include <string>
#include <iostream>

FPS_Counter :: FPS_Counter ( const Game& game, const Window& window )
:   m_window    ( window )
{
    m_text.setFont( game.getFont(Font_Name::Arial));
    m_text.setCharacterSize( 20 );
}

void
FPS_Counter :: update ()
{
    m_text.setPosition( m_window.getCenter().x - (m_window.getSize().x / 2),
                        m_window.getCenter().y - (m_window.getSize().y / 2 )
                    );

    frameTimes +=   getFPS( fpsClock.restart() );
    fpsCount ++;
    if ( fpsClock2.getElapsedTime().asSeconds() >= 0.1f ) {
        m_text.setString( std::to_string(frameTimes / fpsCount ) );
        frameTimes  = 0;
        fpsCount    = 0;
        fpsClock2.restart();
    }
}

void
FPS_Counter :: draw ( sf::RenderWindow& window )
{
    window.draw( m_text );
}

float
FPS_Counter :: getFPS(const sf::Time& time)
{
    //Converts the time to seconds
    return (1000000.0f / time.asMicroseconds());
}
