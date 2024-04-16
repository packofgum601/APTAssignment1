#include "player.h"

Position::Position()
{
    // initialise x and y to 0
    x = 0;
    y = 0;
}

Position::Position(int x, int y)
{
    // initialise x and y to the values passed in
    this->x = x;
    this->y = y;
}

Player::Player()
{
    // initialise position to (0,0), direction to NORTH
    position = Position(0, 0);
    direction = NORTH;
}

void Player::initialisePlayer(Position *position, Direction direction)
{
    // initialise the player's position, direction and moves
    this->position = *position;
    this->direction = direction;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    // turn the player's direction based of the turn direction
    if (turnDirection == TURN_LEFT)
    {
        if (direction == NORTH)
        {
            direction = WEST;
        }
        else if (direction == WEST)
        {
            direction = SOUTH;
        }
        else if (direction == SOUTH)
        {
            direction = EAST;
        }
        else if (direction == EAST)
        {
            direction = NORTH;
        }
    }
    else if (turnDirection == TURN_RIGHT)
    {
        if (direction == NORTH)
        {
            direction = EAST;
        }
        else if (direction == EAST)
        {
            direction = SOUTH;
        }
        else if (direction == SOUTH)
        {
            direction = WEST;
        }
        else if (direction == WEST)
        {
            direction = NORTH;
        }
    }
}

Position Player::getNextForwardPosition()
{
    // move player forward based on direction
    if (direction == NORTH)
    {
        return Position(position.x, position.y - 1);
    }
    else if (direction == EAST)
    {
        return Position(position.x + 1, position.y);
    }
    else if (direction == SOUTH)
    {
        return Position(position.x, position.y + 1);
    }
    else if (direction == WEST)
    {
        return Position(position.x - 1, position.y);
    }
    return Position();
}

void Player::updatePosition(Position position)
{
    // print arrow based on direction
}

void Player::displayDirection()
{
    // display the direction of the player with arrow symbols using if statements
    return updatePosition(position);
}
