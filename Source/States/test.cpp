#include "test.h"

namespace State
{

Test :: Test  ( Game* game )
:   State_Base      ( game )
,   m_level         ( game )
,   m_player        ( m_level, *game, game->getWindow(), m_bloodDynamic )
,   m_bloodDynamic  ( sf::Color::Red, m_level )
{
    m_game->getWindow().setViewOrigin(  m_player.getSpritePosition() );
}

float delay = 0.3f;
sf::Clock bulletDelay;

void
Test :: input ( const double dt )
{
    m_player.input( dt );

    m_game->getGameWindow().setView( m_camera );

    for ( auto& bullet : m_bullets ) bullet->update( dt );

    for ( size_t i = 0 ; i < m_bullets.size() ; i++ )
    {
        if ( m_bullets.at( i )->isFallen() )
        {
            m_bullets.erase( m_bullets.begin() + i );
        }
    }



    if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) && bulletDelay.getElapsedTime().asSeconds() >= delay )
    {
        sf::RenderWindow& win = m_game->getGameWindow();
        sf::Vector2f pos = win.mapPixelToCoords ( sf::Mouse::getPosition( win ) );

        m_bullets.emplace_back( std::make_unique<Bullet>(m_level, *m_game, m_player, m_game->getWindow(), pos ) );

        bulletDelay.restart();
    }
}

void
Test :: update ( const double dt )
{
    m_player.update( dt );


    m_game->getWindow().updateView();

    m_bloodDynamic.update( dt );
}

void
Test :: draw( const double dt )
{
    sf::RenderWindow& window = m_game->getGameWindow();
    m_level.draw    ( window, m_player.getTilePosition() );
    m_player.draw   ( window );
    m_bloodDynamic.draw( window );

    for ( auto& bullet : m_bullets ) bullet->draw( window );
}

} //Namespace State
