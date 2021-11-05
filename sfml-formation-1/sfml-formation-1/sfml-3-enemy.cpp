/*
Dans cet example, il faudra faire d�placer un ennemi le long d'une s�rie de points configurables.
L'ennemi devra faire une pause d'une dur�e configurable � chaque arr�t, et faire demi tour selon le m�me trac�.

La vitesse du monstre doit �tre configurable.

Vous n'�tes pas oblig� d'animer le sprite, mais cela sera un bon bonus.

Afin de bien d�bugguer, il faudra afficher des petits points repr�sentants l'itin�raire du monstre, avec aussi un trac�.
Il faudra donc utiliser sf::RectangleShape et sf::VertexArray, ainsi que sf::Timer.

Vous devrez donc cr�er un class enemy{} ou struct enemy{}, avec un constructeur, 
et les m�thodes membres update(float delta) et draw(sf::RenderWindow & window).

Lorsque le personnage touche un monstre, la partie se finit avec un message game over en Texte via sf::Text, et le jeu recommence de z�ro.
Il faudra vous aider de la fonction Sprite::getGlobalBounds() et FloatRect::intersects()

Vous devrez r�utiliser, de pr�f�rence, le code de chargement de texte que vous avez �crit dans vos pr�c�dents projets.
*/

/*
Annexe: en pr�paration du projet de physique, vous pouvez commencer a cr�er une classe vehicle, que le personnage peut rentrer et sortir grace
� la touche entr�e.

*/