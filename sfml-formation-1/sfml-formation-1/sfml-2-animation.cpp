#include <SFML/Graphics.hpp>
using namespace sf;
/*
Dans cet example, vous allez devoir animer un personnage lors de son d�placement.
Toujours en utilisant Sprite::setTextureRect(), vous devrez alterner entre plusieurs sous r�gions de la texture fournie, � une fr�quence adapt�e.

Vous pouvez soit utiliser un sf::Timer avec Timer::getElapsedTime(), soit utiliser un accumulateur en float, sachant que SFML
peut verrouiller la fr�quence d'affichage � 60.

Il faudra �galement choisir la texture appropri�e en fonction de la direction de mouvement du personnage.
Il faudra penser � remettre la texture du h�ros dans son �tat de repos lorsque le personnage s'arr�te.

En exercice suppl�mentaire, vous pouvez faire tourner une �p�e en demi cercle autour du personnage.

// https://imgur.com/a/vVmZnXt

*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    // limite les FPS � 60
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}