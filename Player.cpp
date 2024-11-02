// Player.cpp
#include "Player.h"
#include <iostream>
#include <cmath> // For sqrt

const float PLAYER_VEL = 0.5f; // Horizontal velocity
const float GRAVITY = 0.2f; // Gravity
const float MAX_FALL_SPEED = 1.0f;
const float JUMP_HEIGHT = 100.0f; // Desired jump height

// Calculate initial jump velocity based on desired jump height and gravity
const float JUMP_STRENGTH = std::sqrt(2 * GRAVITY * JUMP_HEIGHT);

void Player::init()
{
    playerRect = { 100.0f, 100.0f, 10.0f, 10.0f }; // x, y, width, height
    velX = 0.0f;
    velY = 0.0f;
    isJumping = false;
    leftPressed = false;
    rightPressed = false;
    levelComplete = false; // Initialize here
    std::cout << "Player initialized." << std::endl;
}

void Player::update(const std::vector<Platform>& platforms, const Goal& goal)
{
    // Apply gravity
    velY += GRAVITY;
    if (velY > MAX_FALL_SPEED)
    {
        velY = MAX_FALL_SPEED;
    }

    // Update horizontal velocity based on key states
    if (leftPressed && !rightPressed)
    {
        velX = -PLAYER_VEL;
    }
    else if (rightPressed && !leftPressed)
    {
        velX = PLAYER_VEL;
    }
    else
    {
        velX = 0.0f;
    }

    // Move the player left or right
    playerRect.x += velX;

    // Move the player up or down
    playerRect.y += velY;

    // Check for collisions
    checkCollision(platforms, goal);

    // Keep the player within the screen bounds
    if (playerRect.x < 0)
    {
        playerRect.x = 0;
    }
    else if (playerRect.x + playerRect.w > 800)
    {
        playerRect.x = 800 - playerRect.w;
    }

    if (playerRect.y < 0)
    {
        playerRect.y = 0;
    }
    else if (playerRect.y + playerRect.h > 600)
    {
        playerRect.y = 600 - playerRect.h;
    }
}
