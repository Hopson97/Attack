#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
    public:
        Entity( const sf::Vector2f& size, const sf::Vector2f& position );

        void
        update              ( const float dt );

        virtual void
        uniqueUpdate        ( const float dt ) = 0;

        virtual void
        draw                ( sf::RenderWindow& window );

        const double
        getGravity          () const;

        const sf::Vector2f&
        getVelocity         () const;

        const sf::Vector2i&
        getTilePosition     ();

        const sf::Vector2f
        getSpritePosition   () const;

        const sf::Vector2f
        getSpriteSize       () const;

        void
        changeVelocity      ( const float x, const float y);

        void
        setVelocity         ( const float x, const float y);

        void
        resetXVelocity      ();

        void
        resetYVelcoity      ();

    protected:
        void
        updateTilePosition  ();

        void
        moveSprite          ();

        constexpr static double m_gravity      = 0.07;

    private:
        sf::RectangleShape  m_sprite;
        sf::Vector2i        m_tilePostion;
        sf::Vector2f        m_velocity;
};

#endif // ENTITY_H
