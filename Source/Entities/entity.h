#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "level.h"
#include "component_base.h"

typedef std::unique_ptr<Component::Component_Base> ComponentPtr ;

class Entity
{
    public:
        Entity( const sf::Vector2f& size, const sf::Vector2f& position, const sf::Texture& texture, const Level& level );

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
        setRotation             ( const float rotation );

        const float
        getRotation             () const;

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
        moveSprite              ( const float dt );

        void
        checkVelocityForZero    ();

        const bool
        isMoving                ();

        void
        setTextureRect          ( const sf::IntRect& txrRect );

    private:
        sf::RectangleShape  m_sprite;
        sf::Vector2i        m_tilePostion;
        sf::Vector2f        m_velocity;

        const Level&        m_level;

        bool                m_isOnGround;
        bool                m_isMoving;

        std::vector<ComponentPtr>    m_components;
};

#endif // ENTITY_H
