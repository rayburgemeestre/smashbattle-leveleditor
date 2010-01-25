#pragma once

#include <vector>

// Tile sizes, dimensions and count
#define TILE_W 32
#define TILE_H 32
#define TILE_COLS 20
#define TILE_ROWS 15
#define TILE_COUNT (TILE_COLS * TILE_ROWS)

#define LEVEL_ID 0x5342 // "SB"
#define LEVEL_VERSION 2

#define LEVEL_META LEVEL_META_2

#define LEVEL_BLOCK_PSTART	0x01
#define LEVEL_BLOCK_PROP	0x02

struct LEVEL_POINT {
	short x;
	short y;
};

struct LEVEL_RECT {
	short x;
	short y;
	short w;
	short h;
};

struct LEVEL_HEADER {
	unsigned short id;
	unsigned short version;
};

struct LEVEL_META_1 {
	char name[20];
	char author[20];
	bool multiplayer;
	unsigned short max_players;
	unsigned int background_color;
	char filename_tiles[30];
	char filename_background[30];
	char filename_props[30];
};

struct LEVEL_META_2 {
	char name[20];
	char author[20];
	bool multiplayer;
	unsigned short max_players;
	unsigned int background_color;
	char filename_tiles[30];
	char filename_background[30];
	char filename_props[30];
	char filename_music[30];
};

struct LEVEL_TILE {
	unsigned short tile;
	unsigned short hp;
	bool indestructible;
	bool bouncing;
	bool show_in_preview;
};

struct LEVEL_PLAYERSTART {
	unsigned short player;
	short x;
	short y;
	bool facing_right;
};

struct LEVEL_PROP {
	LEVEL_RECT src;
	LEVEL_POINT dst;
};

class Level
{
public:
	Level();
	~Level();

	void create(const char * filename, LEVEL_META &m);
	void load(const char * filename);
	void save(const char * filename);

	bool loaded;

	LEVEL_HEADER header;
	LEVEL_META meta;
	LEVEL_TILE tile[TILE_COUNT];

	LEVEL_PLAYERSTART playerstart[4];

	std::vector<LEVEL_PROP *> * props;
};
