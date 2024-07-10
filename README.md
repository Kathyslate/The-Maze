<h1><center>Maze Creating a 3D maze with raycasting using C and SDL2</center></h1>

# Introduction
The Maze Project is an immersive game built in C using SDL (Simple DirectMedia Layer). Embark on a journey through intricate mazes, utilizing raycasting for realistic rendering. This project aims to combine learning with interactive gameplay, offering a hands-on experience in game development. Dive in and explore the world of 3D gaming with The Maze Project!

# Features
2D maze exploration

Basic enemy AI

Collision detection

Camera movement

Rain effect for enhanced visual experience

### Project blogs articles
Satson <>

MucheruM <https://www.linkedin.com/pulse/portfolio-project-blog-post-creating-maze-game-peter-mucheru-eij0f>

Kathyslate <>

### Authors:
Satson Bamidele Johnson <satsunjohnson@gmail.com>

Mucheru Maina <petermucheru420@gmail.com> <https://www.linkedin.com/in/peter-mucheru-heru/>

Oyetunde mercy omobolaji <mercyoyetunde98@gmail.com> 


# Requirements
GNU Make

GCC

SDL2

SDL2_image


# Installation
Clone this repo
```bash
git clone https://github.com/Kathyslate/The-Maze.git
```

### Windows
Open powershell and Install WSL using the following command

```bash 
wsl --install
```

Open WSL terminal, update and upgrade to the latest applications 

```bash
sudo apt update && sudo apt upgrade -y
```

Install the necessary building essencials like gcc for the C code compilation
```bash
sudo apt install build-essential -y
```

Install SDL2 libraries
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev -y
```
Install the X server  to handle graphical display on WSL

[`Xserver`](https://sourceforge.net/projects/vcxsrv/)

Check environment variables and set DISPLAY manually if configured incorrectly
```bash 
echo $DISPLAY
```

Set it manually
```bash
export DISPLAY=:0
```

### Linux

```bash
sudo apt update && sudo apt upgrade -y
```

Install the necessary building essencials like gcc for the C code compilation
```bash
sudo apt install build-essential -y
```

Install SDL2 libraries
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev -y
```

# Compiling
```bash
make
```


# Running
After successfully compiling run the program using following command:

```bash
./maze
```


# Usage

### Controls
```W``` or ```↑``` : move forward

```S``` or ```↓``` : move backward

```A``` or ```←``` : rotate camera left 

```D``` or ```→``` : rotate camera right 

```Q``` : strafe left 

```E``` : strafe right 

```F``` : toggle fullscreen 

```ESC``` : quit


# Source Files

main.c - Entry point of the game

shootweapn.c - Weapon handling

loadTexture.c - Texture rendering functions

input.c -  Quit, define maze map, check input for movement handling

maze.c -  Main.c handling

raycaster.c - Wall rendering and collision

parseMap.c - Collision detection

render.c - Rendering walls, background, weapon parsing

SDL.c - Close texture render & Upadate

rain.c - Rain effect


# Contributors
Fork the repository

Create a new branch (git checkout -b feature-branch)

Commit your changes (git commit -am 'Add new feature')

Push to the branch (git push origin feature-branch)

Create a new Pull Request


### Resources
SDL2 API

LazyFoo Beginning Game Programming

Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi

LodeV Raycasting Tutorial

Game Engine Black Book


