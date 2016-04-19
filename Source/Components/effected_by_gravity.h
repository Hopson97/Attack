#ifndef EFFECTED_BY_GRAVITY_H
#define EFFECTED_BY_GRAVITY_H

#include "entity.h"
#include "level.h"
#include "window.h"

#include "component_base.h"

namespace Component
{

class Effected_By_Gravity : public Component_Base
{
    public:
        Effected_By_Gravity( Entity& entity, const Level& level, Window& window );

        void
        update          ( const float dt ) override;

    private:
        void
        checkGravity    ();

        void
        applyGravity    ();

        void
        checkIfOnGround ();

        Entity&         m_entity;
        const Level&    m_level;
        Window&         m_window;

};

} //Namespace Component

#endif // EFFECTED_BY_GRAVITY_H
