#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "component_base.h"

typedef std::unique_ptr<Component::Component_Base> ComponentPtr ;

class Entity
{
    public:
        Entity( const sf::Vector2f& size, const sf::Vector2f& position, const sf::Texture& texture );

        void
        update                  ( const float dt );

        virtual void
        uniqueUpdate            ( const float dt ) = 0;

        virtual void
        draw                    ( sf::RenderWindow& window );

        const double
        getGravity              () const;

        const sf::Vector2f&
        getVelocity             () const;

        const sf::Vector2i&
        getTilePosition         ();

        const sf::Vector2f&
        getSpritePosition       () const;

        const sf::Vector2f&
        getSpriteSize           () const;

        void
        changeVelocity          ( const float x, const float y);

        void
        setVelocity             ( const float x, const float y);

        void
        resetXVelocity          ();

        void
        resetYVelocity          ();

        const bool
        isOnGround              () const;

        void
        setIfOnGround           ( const bool onGround );

        void
        addComponent            ( ComponentPtr comp );

    protected:
        void
        updateTilePosition      ();

        void
        moveSprite              ();

        void
        checkVelocityForZero    ();

        const bool
        isMoving                ();

        void
        setTextureRect          ( const sf::IntRect& txrRect );

        constexpr static double m_gravity      = 0.07;

    private:
        sf::RectangleShape  m_sprite;
        sf::Vector2i        m_tilePostion;
        sf::Vector2f        m_velocity;

        bool                m_isOnGround;
        bool                m_isMoving;

        std::vector<ComponentPtr>    m_components;
};

#endif // ENTITY_H
