#include "test.h"

namespace State
{

Test :: Test  ( Game* game )
:   State_Base      ( game )
,   m_level         ( game )
,   m_player        ( m_level, *game, game->getWindow() )
,   m_bloodDynamic  ( sf::Color::Red, m_level )
{
    m_game->getWindow().setViewOrigin(  m_player.getSpritePosition() );
}

void
Test :: input ( const double dt )
{
    m_player.input( dt );

    m_game->getGameWindow().setView( m_camera );
}

void
Test :: update ( const double dt )
{
    m_player.update( dt );


    m_game->getWindow().updateView();

    m_bloodDynamic.addParticles( 1, m_player.getSpritePosition());

    m_bloodDynamic.update( dt );
}

void
Test :: draw( const double dt )
{
    sf::RenderWindow& window = m_game->getGameWindow();
    m_level.draw    ( window, m_player.getTilePosition() );
    m_player.draw   ( window );
    m_bloodDynamic.draw( window );
}

} //Namespace State
