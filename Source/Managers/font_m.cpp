#include "font_m.h"

#include <stdexcept>

namespace Manager
{

Font_M :: Font_M()
{
    loadFonts();
}

void
Font_M :: loadFonts ()
{
    const static std::string FontPath = "Res/Fonts/";

    loadFont( Font_Name::TestFont, FontPath + "vtks gix.ttf");
}

void
Font_M :: loadFont ( const Font_Name name, const std::string& path )
{
    if ( !m_fonts[ name ].loadFromFile( path ) )
    {
        std::runtime_error ( "Font at " + path + " does not exist." );
    }
}

const sf::Font&
Font_M :: getFont ( const Font_Name name ) const
{
    return m_fonts.at( name );
}



}
