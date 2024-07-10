<center><h1>Maze Creating a 3D maze with raycasting using C and SDL2</h1></center>

## Introduction
The Maze Project is an immersive game built in C using SDL (Simple DirectMedia Layer). Embark on a journey through intricate mazes, utilizing raycasting for realistic rendering. This project aims to combine learning with interactive gameplay, offering a hands-on experience in game development. Dive in and explore the world of 3D gaming with The Maze Project!

### Project blogs articles
Satson <>

MucheruM <https://www.linkedin.com/pulse/portfolio-project-blog-post-creating-maze-game-peter-mucheru-eij0f>

Kathyslate <>

### Authors:
Satson<@gmail.com>

Mucheru Maina <petermucheru420@gmail.com> <https://www.linkedin.com/in/peter-mucheru-heru/>

Oyetunde mercy omobolaji <mercyoyetunde98@gmail.com> 


## Installation
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
[`src`](https://sourceforge.net/projects/vcxsrv/)

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

## Compiling
```bash
make
```

## Running
After successfully compiling run the program using following command:

```bash
./maze
```

## Usage

### Controls
```W``` or ```↑``` : move forward

```S``` or ```↓``` : move backward

```A``` or ```←``` : rotate camera left 

```D``` or ```→``` : rotate camera right 

```Q``` : strafe left 

```E``` : strafe right 

```F``` : toggle fullscreen 

```ESC``` : quit


## Contributors
### Resources
SDL2 API

LazyFoo Beginning Game Programming

Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi

LodeV Raycasting Tutorial

Game Engine Black Book


