# **Maze: A 3D Game with SDL and Raycasting**

Maze is a portfolio project developed as part of my completion of the foundation level of the ALX Software Engineering program.
Maze is an immersive 3D game built using SDL (Simple DirectMedia Layer) version 2.0.2 and Raycasting technology. In the game, players navigate through a maze, exploring its depths and seeking a way out.

## **Maze: Game Features**

+ [x] **Controls:**
  Players can move in four directions during the game using the keyboard. Additionally, there is a visibility button for toggling the 2D map on and off. The following controls are used to maneuver while playing the game:
    + ```W``` - Move forward
    + ```S``` - Move backward
    + ```A``` - Look left
    + ```D``` - Look right
    + ```M``` - Turn off 2D map visibility
    + ```N``` - Turn on 2D map visibility
    + ```Mouse Movement``` - Rotate left or right

+ [x] **Collision Detection:**
  If a player encounters a wall, movement is restricted until the player changes direction.

+ [x] **Simultaneous Movement and Rotation:**
  Maze allows for fluid movement and rotation simultaneously. The forward key and the side direction keys can be used together, as well as the backward key and the side direction keys. Just as shown below:
    + ```W``` and ```A``` or ```D```
    + ```S``` and ```A``` or ```D```

## **Maze: How to Play**

+ [x] **Download or clone this repository**
  Clone this repository:

  ```bash
  git clone https://github.com/thisisteey/Maze.git
  ```

+ [x] **Compiling**
  The repository is compiled with the use of gcc. Before compilation, ensure the following are present on your device, as each device compatability gives the best experience:
  + Linux
    + SDL2 (version 2.0.2) to install use ```make linux_install```
    Once installed, compile using:

    ```bash
    make linux
    ```
  + Mac
    + SDL2 (version 2.0.2 and above) to install use ```brew install SDL2```
    Once installed, compile using:

    ```bash
    make mac
    ```
  + Windows
    + SDL2 (version 2.0.2) - Download and install SDL2 developement libraries
    + gcc and make (you can install using chocolatey)
    Once dependencies are installed, compile using:

    ```bash
    make
    ```

+ [x] **Running/Execution**
  After successful compilation, execute the program using the following command:

  ```bash
  ./maze default
  ```

Here ```default``` refers to the name of the file found in the maps folder.

***Enjoy Maze!***

## Directories

[`headers`](https://github.com/thisisteey/Maze/tree/master/headers)

Contains all the header files of the game.

[`images`](https://github.com/thisisteey/Maze/tree/master/images)

Contains all images files and Texture sources

https://www.seekpng.com

[`maps`](https://github.com/thisisteey/Maze/tree/master/maps)

Contains the map data files of the game.

[`src`](https://github.com/thisisteey/Maze/tree/master/src)

Contains all the source code files which are written in C.

## Author(s)

Taiwo Adeoye Dada [@thisisteey](https://github.com/thisisteey) <dadataiwo82@yahoo.com>
