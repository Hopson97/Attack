#include "game.h"

#include "States/test.h"

Game :: Game ()
{
    m_states.changeState( new State::Test ( this ) );
}


void
Game :: runLoop ()
{
    sf::Clock dtClock;
    dtClock.restart();

    while ( m_window.isOpen() )
    {
        if ( !m_states.empty() )
        {
            double dt = calculateDeltaTime( dtClock );

            m_window.clear( );

            m_states.peekState()->input ( dt );
            m_states.peekState()->update( dt );
            m_states.peekState()->draw  ( dt );

            m_window.update();
        }
        else
        {
            m_window.close();
            break;
        }
    }
}

const double
Game :: calculateDeltaTime ( sf::Clock& c )
{
    sf::Time dt = c.restart();
    return dt.asSeconds();
}

State::Handler&
Game :: getStates ()
{
    return m_states;
}

const sf::Texture&
Game :: getTexture ( const Texture_Name name ) const
{
    return m_textures.getTexture( name );
}

const sf::Font&
Game :: getFont ( const Font_Name name ) const
{
    return m_fonts.getFont( name );
}

const sf::SoundBuffer&
Game :: getSound ( const Sound_Name name ) const
{
    return m_sounds.getSound ( name );
}

void
Game :: playMusic   ( const Music_Name name )
{
    m_music.playSong( name );
}

sf::RenderWindow&
Game :: getWindow   ()
{
    return m_window.get();
}
