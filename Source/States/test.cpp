#include "test.h"

#include "colours.h"

#include <iostream>

namespace State
{

Test :: Test  ( Game* game )
:   State_Base          ( game )
,   m_level             ( game )
,   m_player            ( m_level, *game, game->getWindow(), m_bloodParticles )
,   m_bloodParticles    ( sf::Color::Red, m_level )
,   m_dirtParticles     ( Colour::Brown,  m_level )
{
    //Set the games view that the cameras centre is just below the player
    m_game->getWindow().setViewOrigin(  m_player.getSpritePosition() );
    m_game->getWindow().setViewOffset( 0, -m_player.getSpriteSize().y );
}

float delay = 0.00f;
sf::Clock bulletDelay;

void
Test :: input ( const double dt )
{
    m_player.input( dt );

    //Adding of the bullets
    if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) && bulletDelay.getElapsedTime().asSeconds() >= delay )
    {
        sf::RenderWindow& win = m_game->getGameWindow();
        sf::Vector2f pos = win.mapPixelToCoords ( sf::Mouse::getPosition( win ) );

        m_bullets.emplace_back( std::make_unique<Bullet>(m_level, *m_game, m_player, m_game->getWindow(), pos, m_dirtParticles ) );

        bulletDelay.restart();
    }
}

void
Test :: update ( const double dt )
{
    for ( size_t i = 0 ; i < m_bullets.size() ; i++ )
    {
        m_bullets.at( i )->update ( dt );
        if ( m_bullets.at( i )->isFallen() )
        {
            m_bullets.erase( m_bullets.begin() + i );
        }
    }

    m_player.update( dt );


    m_game->getWindow().updateView();

    m_bloodParticles.update( dt );
    m_dirtParticles .update( dt );
}

void
Test :: draw( const double dt )
{
    sf::RenderWindow& window = m_game->getGameWindow();
    m_level.draw    ( window, m_player.getTilePosition() );
    m_player.draw   ( window );

    m_bloodParticles.draw( window );
    m_dirtParticles .draw( window );

    for ( auto& bullet : m_bullets ) bullet->draw( window );
}

} //Namespace State
