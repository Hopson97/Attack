#include "test.h"

namespace State
{

Test :: Test  ( Game* game )
:   State_Base ( game )
{
    testText.setFont( game->getFont(Font_Name::TestFont ) );
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

}

} //Namespace State
