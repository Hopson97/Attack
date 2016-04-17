#ifndef EFFECTED_BY_GRAVITY_H
#define EFFECTED_BY_GRAVITY_H

#include "entity.h"
#include "level.h"

class Effected_By_Gravity
{
    public:
        Effected_By_Gravity( Entity& entity, const Level& level );

        void
        update          ();

    private:
        void
        checkGravity    ();

        void
        applyGravity    ();

        void
        checkIfOnGround ();

        Entity&   m_entity;
        const Level&    m_level;
};

#endif // EFFECTED_BY_GRAVITY_H
