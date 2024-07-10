#include "maze.h"
#include <stdio.h>  // Add for debug logging

/* global variables */
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];
point_t pos;
point_t dir;
point_t plane;
double time;
weapon_t weapon;  // Declare global weapon variable

/**
 * main - renders maze
 * @argc: number of arguments
 * @argv: pointer to array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
    int *maze; /* 2D array defining maze map */
    char *mapName;
    bool textured;

    /* initial values for global variables */
    pos.x = 1;
    pos.y = 12;
    dir.x = 1;
    dir.y = -0.66;
    plane.x = 0;
    plane.y = 0.66;
    time = 0;

    /* Initialize weapon properties */
    weapon.ammo = 10; // Set initial ammo count
    weapon.cooldown = 0.5; // Set cooldown time in seconds
    weapon.lastFired = -weapon.cooldown; // Initialize last fired time

    /* check user arguments and set options */
    mapName = "\0";
    textured = true;
    if (argc == 3)
    {
        if (strcmp(argv[2], "no_tex") == 0)
            textured = false;
        mapName = argv[1];
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "no_tex") == 0)
        {
            mapName = "maps/map_0";
            textured = false;
        }
        else
            mapName = argv[1];
    }
    else if (argc == 1)
        mapName = "maps/map_0";

    /* start SDL and create window and renderer */
    printf("Initializing SDL...\n");
    if (!initSDL())
    {
        fprintf(stderr, "Failed to initialize SDL\n");
        return (1);
    }
    printf("SDL initialized successfully\n");

    /* parse maze file */
    printf("Parsing maze map...\n");
    maze = NULL;
    maze = parseMap(mapName, maze);
    if (maze == NULL)
    {
        fprintf(stderr, "Failed to parse maze map\n");
        return (1);
    }
    printf("Maze map parsed successfully\n");

    if (textured)
    {
        printf("Loading textures...\n");
        loadTextures(mapName);
        printf("Textures loaded successfully\n");
    }

    /* load weapon texture */
    if (!loadWeapon("textures/gun1.png"))
    {
        fprintf(stderr, "Failed to load weapon texture\n");
        return (1);
    }

    /* loops until user exits by ESC or closing window */
    while (!quit())
    {
        /* Clear the screen */
        SDL_RenderClear(renderer);

        /* draw walls, textured floor, and textured ceiling */
        if (!textured)
            renderBGFlat();
        raycaster(maze, textured);

        /* render weapon */
        if (textured)
            renderWeapon();

        /* Update the screen */
        SDL_RenderPresent(renderer);

        /* handles user input */
        input(maze);
    }

    /* close SDL, renderer, and window */
    printf("Closing SDL...\n");
    closeSDL();
    free(maze);
    printf("SDL closed successfully\n");
    return (0);
}

root@DESKTOP-PAV54FU:/mercy_maze/src# ls
SDL.c    loadTextures.c  maze.c      raycaster.c  shootWeapon.c
input.c  maze            parseMap.c  render.c
root@DESKTOP-PAV54FU:/mercy_maze/src# cat  raycaster.c
#include "maze.h"

/**
 * raycaster - casts rays and renders walls, floor, and ceiling
 * @maze: 2D array defining maze map
 * @textured: True if user enabled textures, otherwise False
 * Return: void
 */
void raycaster(int *maze, bool textured)
{
        double cameraX; /* X coordinate in camera space */
        point_t rayPos; /* X/Y coordinates of ray pos */
        point_t rayDir; /* direction of X/Y coordinates of ray pos */
        point_t posToNext; /* length of ray from current pos to next X/Y side */
        point_t distToNext; /* length of ray from X/Y side to next X/Y side */
        double distToWall; /* distance from camera to wall */

        SDL_Point map; /* X/Y coordinates of box of maze currently in */
        SDL_Point step; /* X/Y direction to step in - always 1 or -1 */

        int hit; /* check if wall was hit */
        int side; /* check if wall hit was N/S or E/W */

        int x; /* ray counter */

        /* cast ray x for every column w */
        for (x = 0; x < SCREEN_WIDTH; x++)
        {
                /* calculate ray position and direction */
                cameraX = 2 * x / (double)(SCREEN_WIDTH) - 1;
                rayPos.x = pos.x;
                rayPos.y = pos.y;
                rayDir.x = dir.x + plane.x * cameraX;
                rayDir.y = dir.y + plane.y * cameraX;

                /* grid position on maze */
                map.x = (int)(rayPos.x);
                map.y = (int)(rayPos.y);

                /* measure distance to next X or Y intersection */
                distToNext.x = sqrt(1 + (pow(rayDir.y, 2)) / pow(rayDir.x, 2));
                distToNext.y = sqrt(1 + (pow(rayDir.x, 2)) / pow(rayDir.y, 2));

                /* calculate step and distance from pos to first X or Y */
                if (rayDir.x < 0)
                {
                        step.x = -1;
                        posToNext.x = (rayPos.x - map.x) * distToNext.x;
                }
                else
                {
                        step.x = 1;
                        posToNext.x = (map.x + 1.0 - rayPos.x) * distToNext.x;
                }

                if (rayDir.y < 0)
                {
                        step.y = -1;
                        posToNext.y = (rayPos.y - map.y) * distToNext.y;
                }
                else
                {
                        step.y = 1;
                        posToNext.y = (map.y + 1.0 - rayPos.y) * distToNext.y;
                }

                /* move to next maze square in X or Y dir until wall is hit */
                hit = 0;
                while (hit == 0)
                {
                        if (posToNext.x < posToNext.y)
                        {
                                posToNext.x += distToNext.x;
                                map.x += step.x;
                                side = 0;
                        }
                        else
                        {
                                posToNext.y += distToNext.y;
                                map.y += step.y;
                                side = 1;
                        }

                        /* check if ray hit a wall */
                        if (*((int *)maze + map.x * MAP_WIDTH + map.y) > 0)
                                hit = 1;
                }

                /* calculate distance projected in camera direction */
                if (side == 0)
                        distToWall = (map.x - rayPos.x + (1 - step.x) / 2) / rayDir.x;
                else
                        distToWall = (map.y - rayPos.y + (1 - step.y) / 2) / rayDir.y;

                /* draw walls to buffer */
                renderWalls(maze, map, rayPos, rayDir, distToWall, x, side, textured);
        }

        /* draw updated buffer with walls, floor, and ceiling to renderer */
        updateRenderer(textured);
}
