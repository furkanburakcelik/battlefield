#include <stdio.h>
#include <math.h>

struct Weapon
{
    char *name;
    int power;
};


struct Player
{
    char *name;
    int posX;
    int posY;
    int health;
    struct Weapon weapon;
};


int ppower(int number, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        return number * ppower(number, p - 1);
    }
}

float distance(struct Player player1, struct Player player2)
{
    float distance;
    distance = sqrt(ppower(player1.posX - player2.posX, 2) + ppower(player1.posY - player2.posY, 2));
    return distance;
}


void dealDamage(struct Player p1, struct Player p2)
{
    int damage;
    damage = p1.weapon.power / distance(p1, p2);
    printf("%s dealt %d damage to %s with %s weapon. %s has %d health left.\n", p1.name, damage, p2.name, p1.weapon.name, p2.name, p2.health - damage);
}
int main() {

    struct Weapon weapon1 = {"AK47", 100};
    struct Weapon weapon2 = {"MP4", 50};

    struct Player player1;
    player1.name = "Aaron";
    player1.posX = 0;
    player1.posY = 4;
    player1.health = 100;
    player1.weapon = weapon1;

    struct Player player2;
    player2.name = "Adam";
    player2.posX = 3;
    player2.posY = 0;
    player2.health = 100;
    player2.weapon = weapon2;

    dealDamage(player1, player2);

    return 0;
}
