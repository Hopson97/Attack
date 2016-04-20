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

void
Test :: input ( const double dt )
{
    m_player.input( dt );

    m_game->getGameWindow().setView( m_camera );

    if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
    {
        sf::Vector2i pos = sf::Mouse::getPosition( m_game->getGameWindow() );

        m_bullets.emplace_back( std::make_unique<Bullet>(m_level, *m_game, m_player, m_game->getWindow(), sf::Vector2f(pos.x, pos.y) ) );
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
