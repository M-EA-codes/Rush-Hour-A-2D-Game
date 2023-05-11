# Rush-Hour-A-2D-Game
This is a basic 2D game implemented using SFML (Simple and Fast Multimedia Library) which involves moving a car to its destination by avoiding collisions with other cars and obstacles on the way.

Installation
Before running the game, make sure to have SFML installed. It can be downloaded from the official website: https://www.sfml-dev.org/download.php
Clone this repository using the command:
git clone https://github.com/M-EA-codes/Rush-Hour-A-2D-Game.git
Compile the game using a C++ compiler that supports SFML, for example g++. On Linux, you can use the following command to compile:

g++ -c -std=c++11 RushHour.cpp -lsfml-graphics -lsfml-window -lsfml-system

Then link the object file with SFML libraries using the following command:
g++ RushHour.o -o RushHour -lsfml-graphics -lsfml-window -lsfml-system
Finally, run the game using the command:
Copy code
./RushHour

**How to play**
Use the arrow keys to move the car.
The aim of the game is to move the car to its destination without colliding with any other cars or obstacles.
Each time the car collides with another car, the score will decrease by 4 points.
If the car reaches its destination without any collisions, the player will receive 10 points.
The game is over when the time runs out (set to 3 minutes by default) or the player's score reaches 0.

**Game Controls**
Press **P** to start the game.
Press **L** to view the leaderboard.
Press **ESC** to quit the game.
**Credits**
This game is created by M Ejaz Alvi as part of my semester project.
The graphics library used is SFML.
The code is based on the OpenGL code provided in the CSE165 course at UC San Diego.
