![a_very_long_night](https://github.com/pandorasjuicebox/DAU-2023-Project/assets/30426576/5cc00aab-ab77-4350-8fc4-841328935068)

## Contents
* [Introduction](#introduction)
* [Installation](#running-the-game)
  * [Prerequisites](#prerequisites) 
  * [Building](#building)
* [Gameplay](#gameplay)
  * [The Goal](#the-goal)
  * [Mechanics](#mechanics)
* [Controls](#controls)
* [Acknowledgements](#acknowledgements)
 
## Introduction
Where are you? You don't know. All you know is that you woke up, picked up a strange note on the ground telling you, <i>"The game ends at 100"</i>.

## Running the Game
### Prerequisites
* <i>A Very Long Night</i> was developed in C++ with Visual Studio Code and the API developed for Develop at Ubisoft.
* Because Visual Studio Code is no longer supported on MacOS, you must either use a Microsoft Windows operating system or a hardware virtualization software like Parallels.
* As of this document's writing, I used [Parallels 19](https://www.parallels.com).

### Building
* To build this project properly, you need to download all the files in this repository.
* To run the game, use the file `GameTest.cpp`.

## Gameplay

* <i>A Very Long Night</i> is a top down platformer featuring simple, sword-based combat.
* It is inspired by old arcade-style games, and <i>Journey of the Prairie King</i> within the popular farming game <i>Stardew Valley</i>.

### The Goal
* Getting through a whole level, and eventually the whole game, is dependent on both the player's technique and skill.
* The main goal of the gameplay is to survive each "wave" or level until its end.

### Mechanics
* The player has a health bar with 9 bars and 3 "lives".
    * You lose a "life" when that health bar depletes.
    * "Medkits" are available during the active level.
    * "lives" can only be replenished by a "Life Vial" that can only be accessed through a secret level.
    * Secret levels are triggered by the player at random.
* Instead of rewarding the player with weapon upgrades, you are using the same sword the whole time.
* The amount of enemies per level varies, determined using `rand()` with a specific-yet-expanding range. For example, you can have somewhere between 10-100 enemies during a level, but in the next, that ceiling of 100 increases.
* You can only move by walking backwards.
* The game "ends" when you reach a score of 100.

### Controls
* To move the player, you use the standard WASD buttons for directional keys.
* To attack, press `F` while walking backwards in a specified direction.

## Acknowledgements

To be continued

