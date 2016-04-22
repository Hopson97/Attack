#ifndef EFFECTED_BY_GRAVITY_H
#define EFFECTED_BY_GRAVITY_H

#include "entity.h"
#include "level.h"
#include "window.h"
#include "Particles/dynamic_particle_batch.h"

#include "component_base.h"

namespace Component
{

class Effected_By_Gravity : public Component_Base
{
    public:
        Effected_By_Gravity( Entity& entity, const Level& level, Window& window);
        Effected_By_Gravity( Entity& entity, const Level& level, Window& window, GravityParticles& particles );
        Effected_By_Gravity( Entity& entity, const Level& level, Window& window, GravityParticles& particles, GravityParticles& particles2 );

        void
        update          ( const float dt ) override;

    private:
        void
        applyGravity    ( const float dt );

        void
        checkIfOnGround ( const float dt );

        void
        handleParticles ( const sf::Vector2f& newPos, const float newPosRight );

        void
        addParticles    ( GravityParticles* p, const size_t amountMultiplyer, const int fallIntensity, const sf::Vector2f& newPos, const float newPosRight );

        Entity&             m_entity;
        const Level&        m_level;
        Window&             m_window;

        GravityParticles*   m_groundParticles  = nullptr;
        GravityParticles*   m_landingParticles = nullptr; //For blood or other things, optional
};

} //Namespace Component

#endif // EFFECTED_BY_GRAVITY_H
