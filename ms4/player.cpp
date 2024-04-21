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

// Player constructor
Player::Player()
{
    position = Position(0, 0);
    direction = Direction::NORTH;
}

// initialise the player's position, direction and moves
void Player::initialisePlayer(Position *position, Direction direction)
{
    this->position = *position;
    this->direction = direction;
    moves = 0;
}

// turn the player's direction based on the given turn direction
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

// get the next forward position based on the player's direction without updating the player's position
Position Player::getNextForwardPosition()
{
    // next position - initialise to current position
    Position nextPosition = position;
    if (direction == NORTH)
    {
        nextPosition.y--;
    }
    else if (direction == EAST)
    {
        nextPosition.x++;
    }
    else if (direction == SOUTH)
    {
        nextPosition.y++;
    }
    else if (direction == WEST)
    {
        nextPosition.x--;
    }
    return nextPosition;
}

// update the player's position based on the postion found by getNextForwardPosition
void Player::updatePosition(Position position)
{
    // update player's position
    this->position = position;
    // update moves
    moves++;
}

// display the player's direction with the corresponding arrow
void Player::displayDirection()
{

    if (direction == NORTH)
    {
        printf(DIRECTION_ARROW_OUTPUT_NORTH);
    }
    else if (direction == EAST)
    {
        printf(DIRECTION_ARROW_OUTPUT_EAST);
    }
    else if (direction == SOUTH)
    {
        printf(DIRECTION_ARROW_OUTPUT_SOUTH);
    }
    else if (direction == WEST)
    {
        printf(DIRECTION_ARROW_OUTPUT_WEST);
    }
}
