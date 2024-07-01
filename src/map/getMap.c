#include "map.h"
#include "global.h"

void	*getAndInitStruct(int number, size_t size, void (* initStruct)(void *)){
	void	*ret = NULL;
	int		i = -1;

	ret = malloc(size * (number + 1));
	while (++i <= number) {
		initStruct((char *)ret + i * size);
	}
	return ret;
}

char	*getFullText(int file) {
	char	*ret = 0, *buf = 0;

	if (buf)
		free(buf);
	buf = get_next_line(file);
	while (1) {
		ret = ft_gnl_strjoin(ret, buf);
		free(buf);
		buf = get_next_line(file);
		if (!buf)
			break;
	}
	return (ret);
}

t_wall	*parseWalls(char **mapLines, int cursor, int len) {
	t_wall	*ret;
	char	**line;
	int		wallCursor, tmp = cursor - 1;

	ret = (t_wall *)getAndInitStruct(len, sizeof(t_wall), &initWall);
	if (!ret)
		return (ft_printf("Some errors occurred while initializing Walls.") ? NULL: NULL);
	while ((++tmp - cursor) < len) {
		wallCursor = tmp - cursor;
		line = ft_split(mapLines[tmp], ' ');
		ret[wallCursor].wallStart.x = ft_atoi(line[0]);
		ret[wallCursor].wallStart.y = ft_atoi(line[1]);
		ret[wallCursor].wallEnd.x = ft_atoi(line[2]);
		ret[wallCursor].wallEnd.y = ft_atoi(line[3]);
		ret[wallCursor].portal = ft_atoi(line[4]);
		ret[wallCursor].texture.transparency = ft_atoi(line[5]);
		//TODO: Texture number
		ft_freesplit(line);
	}
	return (ret);
}

int	parseSector(char **mapLines) {
	int		i = -1, tmp = 0;
	int		sectorCursor = 0, wallCount;
	char	**line;
	while (1) {
		if (!tmp && ft_strnstr(mapLines[++i], "[Sector]", 9)) {
			tmp = i + 1;
			continue;
		}
		if (ft_strnstr(mapLines[++i], "[Wall]", 7)) {
			break;
		}
	}
	gameEnv->map.sector = (t_sector *)getAndInitStruct(i - tmp, sizeof(t_sector), &initSector);
	if (!gameEnv->map.sector) {
		return (!ft_printf("Some errors occurred while initializing Sectors."));
	}
	while (1) {
		line = ft_split(mapLines[tmp++], ' ');
		wallCount = ft_atoi(line[2]);
		gameEnv->map.sector[sectorCursor].sectorNo = ft_atoi(line[0]);
		gameEnv->map.sector[sectorCursor].wallCount = wallCount;
		gameEnv->map.sector[sectorCursor].Floor.height = atof(line[3]);
		gameEnv->map.sector[sectorCursor].Ceiling.height = atof(line[5]);
		gameEnv->map.sector[sectorCursor].walls = parseWalls(mapLines, (i + 1) + ft_atoi(line[1]), wallCount);
		if (wallCount != 0 && gameEnv->map.sector[sectorCursor].walls == NULL) 
			ft_printf("Some errors occurred while parsing %d. sector walls. The program will denied error and continue.", gameEnv->map.sector[sectorCursor].sectorNo);
		else if (wallCount > 0 && gameEnv->map.sector[sectorCursor].walls == NULL)
			return 0;
		if (tmp == i)
			break;
		else
			sectorCursor++;
		ft_freesplit(line);
	}
	if (line)
		ft_freesplit(line);
	return 1;
}

int   getMap(char *file)
{
	char	*fileText, **lines;
	int fd = open(file, O_RDONLY);

	if (fd < 0) {
		return (!ft_printf("File Not Found :%s\n", file));
	}
	fileText = getFullText(fd);
	lines = ft_split(fileText, '\n');
	free(fileText);
	if (!lines) {
		return (!ft_printf("Some errors occurred during reading file."));
	}
	close(fd);
	if (!parseSector(lines))
		return (!ft_printf("Map is not properly parsed."));
	ft_freesplit(lines);
	return 1;
}