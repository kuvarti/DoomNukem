#pragma once

#define MAP_WIDTH 6
#define MAP_HEIGHT 6
#include "commonStructures.h"

// TODO: After generating better map system use this struct
typedef struct s_sectorlst
{
	int x;
	int y;
	int sector;
	struct s_sectorlst *next;
} t_sectorlst;

typedef	struct s_surface {
	unsigned char	transparency;	//* Value used for 0-255
	int				placeholder;	//! need texture system for here
	float			height;
}	t_surface;

typedef struct s_wall {
	t_2dVector	wallStart;
	t_2dVector	wallEnd;
	t_surface	texture;
	int			portal;
}	t_wall;


typedef	struct s_sector {
	int			sectorNo;
	t_wall		*walls;
	int			wallCount;
	t_surface	Floor;
	t_surface	Ceiling;
	int			placeholder;	//! need item system
}	t_sector;

typedef struct s_map{
	t_sector	*sector;
}	t_map;

int		getMap(char *file);
void	init2dVector(void *p);
void	initSurface(void *p);
void	initSector(void *p);
void	initWall(void *p);