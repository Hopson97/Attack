#include "test.h"

namespace State
{

Test :: Test  ( Game* game )
:   State_Base  ( game )
,   m_level     ( game )
{

}

void
Test :: input ( const double dt )
{

}

void
Test :: update ( const double dt )
{

}

void
Test :: draw( const double dt )
{
    m_level.draw( m_game->getWindow() );
}

} //Namespace State
