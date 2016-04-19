#include "test.h"

namespace State
{

Test :: Test  ( Game* game )
:   State_Base  ( game )
,   m_level     ( game )
,   m_player    ( m_level, *game, game->getWindow() )
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
}

void
Test :: draw( const double dt )
{
    m_level.draw( m_game->getGameWindow(), m_player.getTilePosition() );

    m_player.draw ( m_game->getGameWindow() );
}

} //Namespace State
