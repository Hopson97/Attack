#include "window.h"

#include <GL/glew.h>

Window :: Window()
{
    //General window stuff
    m_window.create ( sf::VideoMode(winInfo::WIDTH, winInfo::HEIGHT),
                      "Window",
                      sf::Style::Default,
                      sf::ContextSettings(24) );

    m_window.setFramerateLimit ( 60 );

    //GLEW set up
    glewExperimental = GL_TRUE;
    glewInit();

    //OpenGL set up
    glViewport  (0, 0, winInfo::WIDTH, winInfo::HEIGHT);
    glEnable    (GL_DEPTH_TEST);
    glEnable    (GL_CULL_FACE);
    glCullFace  (GL_BACK);


}

sf::RenderWindow&
Window :: get()
{
    return m_window;
}

void
Window :: clear ( RGBA colour )
{
    colour.check(); //Check if the RGB values are in the 0.0 <= x <= 1.0 range

    glClearColor( colour.r, colour.g, colour.b, colour.a );
    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void
Window :: update ()
{
    m_window.display();
    winEvents();
}

const bool
Window :: isOpen ()
{
    return m_window.isOpen();
}

void
Window :: winEvents ()
{
    sf::Event e;

    while ( m_window.pollEvent ( e ) )
    {
        if ( e.type == sf::Event::Closed )
        {
            m_window.close();
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
        {
            m_window.close();
        }
    }
}

void
Window :: close ()
{
    m_window.close();
}
