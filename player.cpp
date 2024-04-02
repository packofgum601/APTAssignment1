#include "player.h"

Position::Position()
{
    //initialise x and y to 0
    x = 0;
    y = 0;

    

}


Position::Position(int x, int y)
{
    //initialise x and y to the values passed in   
    this->x = x;
    this->y = y;

}

Player::Player()
{
    //initialise position to (0,0), direction to NORTH
    position = Position(0,0);
    direction = NORTH;
    
    

}

void Player::initialisePlayer(Position* position, Direction direction)
{
    //initialise the player's position, direction and moves
    this->position = *position;
    this->direction = direction;
    
    

}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
}

Position Player::getNextForwardPosition()
{
    //TODO
    return Position();

}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection()
{
    //display the direction of the player with arrow symbols using if statements
    if(direction == NORTH){
        std::cout << "↑";
    } else if(direction == EAST){
        std::cout << "→";
    } else if(direction == SOUTH){
        std::cout << "↓";
    } else if(direction == WEST){
        std::cout << "←";
    
    }

}
