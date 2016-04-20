#include "entity.h"

#include "tile_info.h"

Entity :: Entity( const sf::Vector2f& size, const sf::Vector2f& position, const sf::Texture& texture, const Level& level  )
:   m_sprite    ( size )
,   m_level     ( level )
{
    m_sprite.setPosition( position );
    m_sprite.setTexture ( &texture );
}

void
Entity :: update ( const float dt )
{
    updateTilePosition();

    for ( auto& component : m_components )
    {
        component->update ( dt );
    }

    uniqueUpdate ( dt );
    moveSprite   ( dt );

    setVelocity ( getVelocity().x * 0.8, getVelocity().y );

    checkVelocityForZero();

    if ( !getVelocity().x == 0 )
        m_isMoving = true;
    else
        m_isMoving = false;
}

void
Entity :: draw ( sf::RenderWindow& window )
{
    window.draw( m_sprite );
}

void
Entity :: updateTilePosition ()
{
    int x = m_sprite.getPosition().x  / Tile::TILE_SIZE;;
    int y = m_sprite.getPosition().y  / Tile::TILE_SIZE;

    m_tilePostion = { x, y };
}

void
Entity :: moveSprite ( const float dt )
{
    m_sprite.move( m_velocity * dt );
}

const double
Entity :: getGravity () const
{
    return m_gravity;
}

const sf::Vector2f&
Entity :: getVelocity () const
{
    return m_velocity;
}

const sf::Vector2i&
Entity :: getTilePosition ()
{
    updateTilePosition();
    return m_tilePostion;
}

const sf::Vector2f&
Entity :: getSpritePosition () const
{
    return m_sprite.getPosition();
}

const sf::Vector2f&
Entity :: getSpriteSize       () const
{
    return m_sprite.getSize();
}

void
Entity :: changeVelocity ( const float x, const float y)
{
    m_velocity.x += x;
    m_velocity.y += y;
}

void
Entity :: setVelocity ( const float x, const float y)
{
    m_velocity = { x, y };
}

void
Entity :: setRotation ( const float rotation )
{
    m_sprite.setRotation( rotation );
}

const float
Entity :: getRotation () const
{
    return m_sprite.getRotation();
}

void
Entity :: resetXVelocity ()
{
    m_velocity.x = 0;
}

void
Entity :: resetYVelocity ()
{
    m_velocity.y = 0;
}

const bool
Entity :: isOnGround () const
{
    return m_isOnGround;
}

void
Entity :: setIfOnGround ( const bool onGround )
{
    m_isOnGround = onGround;
}

void
Entity :: addComponent  ( ComponentPtr comp )
{
    m_components.push_back( std::move( comp ) );
}

void
Entity :: checkVelocityForZero ()
{
    const float bound = 0.01;

    if ( getVelocity().x < bound &&  getVelocity().x > -bound ) setVelocity(  0, getVelocity().y );
    if ( getVelocity().y < bound &&  getVelocity().y > -bound ) setVelocity(  getVelocity().x, 0 );
}

const bool
Entity :: isMoving ()
{
    return m_isMoving;
}

void
Entity :: setTextureRect ( const sf::IntRect& txrRect )
{
    m_sprite.setTextureRect( txrRect );
}
