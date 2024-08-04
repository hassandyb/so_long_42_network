# So Long

And thanks for all the fish!

## Overview

"So Long" is a basic 2D game developed using the MiniLibX library. The game involves navigating a character through a map to collect items and reach an exit. This project aims to enhance your skills in window management, event handling, graphics, and basic gameplay mechanics.

## Project Objectives

- **Window Management**: Create and manage a window for the game display.
- **Event Handling**: Handle keyboard inputs and mouse events.
- **Graphics**: Manage textures, sprites, and display images in a window.
- **Gameplay**: Implement a simple 2D game where the player must collect items and reach the exit.

## Requirements

- **Language**: C
- **Library**: MiniLibX
- **Makefile**: Must compile your source files with flags `-Wall`, `-Wextra`, and `-Werror`. Should include rules for `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

## Mandatory Features

### Game Mechanics

- **Objective**: Collect all collectibles and reach the exit using the shortest route.
- **Controls**: Use W, A, S, and D keys (or ZQSD/arrow keys) to move the character.
- **Movement**: The player can move up, down, left, and right but cannot pass through walls.
- **Movement Display**: Display the current number of movements in the terminal.

### Graphics Management

- **Window**: Display the game in a window managed by MiniLibX.
- **Window Events**: 
  - Pressing ESC closes the window and quits the program.
  - Clicking the window's close button also exits the program cleanly.

### Map Design

- **Map File**: Use a `.ber` file to describe the map.
- **Map Components**:
  - `0` for empty space
  - `1` for walls
  - `C` for collectibles
  - `E` for the exit
  - `P` for the starting position
- **Validation**: 
  - The map must be rectangular and enclosed by walls.
  - Must contain at least one exit, one collectible, and one starting position.
  - Ensure valid paths and handle map parsing errors gracefully.

## Bonus Features

- **Enemy Patrols**: Add enemies that make the player lose if touched.
- **Sprite Animation**: Implement animations for the player or enemies.
- **Movement Display**: Show the movement count on the screen instead of the terminal.

## Setup

1. **Install MiniLibX**: Ensure you have the MiniLibX library installed. You can use the version available on school machines or install it from source.
2. **Compile**: Run `make` to compile the project.
3. **Run**: Execute the program with the map file as an argument.

   ```bash
   ./so_long map.ber
