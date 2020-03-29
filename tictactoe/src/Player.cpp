#include <Player.h>
Player::Player()
{
    p = 1;
}

void Player::changePlayer()
{
    if (p == 1)
    {
        p = 2;
    }
    else
        p = 1;
}
int Player::getPlayer()
{
    return p;
}