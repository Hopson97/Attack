#ifndef GAME_H
#define GAME_H

#include "Util/window.h"

#include "States/handler.h"

#include "Managers/texture_m.h"
#include "Managers/font_m.h"
#include "Managers/sound_m.h"

class Game
{
    public:
        Game        ();

        void
        runLoop     ();

        State::Handler&
        getStates   ();

        const sf::Texture&
        getTexture  ( const Texture_Name name ) const;

        const sf::Font&
        getFont     ( const Font_Name name ) const;

        const sf::SoundBuffer&
        getSound    ( const Sound_Name name ) const;

        sf::RenderWindow&
        getWindow   ();

    private:
        Window m_window;
        State::Handler m_states;

        const double
        calculateDeltaTime ( sf::Clock& c, sf::Time& t );

        Manager::Font_M     m_fonts;
        Manager::Texture_M  m_textures;
        Manager::Sound_M    m_sounds;
};

#endif // GAME_H
