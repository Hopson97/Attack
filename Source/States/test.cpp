#include "test.h"

namespace State
{

Test :: Test  ( Game* game )
:   State_Base  ( game )
,   m_level     ( game )
,   m_player    ( m_level, *game )
{

}

void
Test :: input ( const double dt )
{
    m_player.input( dt );
}

void
Test :: update ( const double dt )
{
    m_player.update( dt );

    m_camera.setCenter( m_player.getSpritePosition() );
    m_camera.setSize( m_game->getWindow().getSize().x, m_game->getWindow().getSize().y );
    m_game->getWindow().setView( m_camera );
}

void
Test :: draw( const double dt )
{
    m_level.draw( m_game->getWindow(), m_player.getTilePosition() );

    m_player.draw ( m_game->getWindow() );
}

} //Namespace State
