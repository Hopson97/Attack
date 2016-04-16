#include "music_m.h"

namespace Manager
{

Music_M :: Music_M()
{
    loadSongs();
}

void
Music_M :: playSong ( const Music_Name name )
{
    m_music.at( name ).play();
}

void
Music_M :: loadSongs()
{
    const std::string songPath = "Res/Music/";
}

void
Music_M :: loadSong ( const Music_Name name, const std::string& filePath )
{
    if ( !m_music[ name ].openFromFile( filePath ) )
    {
        std::runtime_error ( "Song at " + filePath + " does not exist!");
    }
}

}
