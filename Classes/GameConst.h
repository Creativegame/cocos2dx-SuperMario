#ifndef SuperMario_GameConst_h
#define SuperMario_GameConst_h

static const short bg1shu[] = {-1,1,0,2,-1,1,2,3}; 
static const short bg2shu[] = {3,3,-1,3,-1,3,3,-1};
static  float JUMPTIME=2.0f;
//static int MAP_MOVE_SPEED=10;
#define MAP_MOVE_SPEED 90 //px per 0.1sec
#define HERO_OFFSET_X 60
#define HERO_OFFSET_Y 0

#define HERO_STATE_COMMON 100
#define HERO_STATE_WALKRIGHT 101
#define HERO_STATE_JUMP  102
#define HERO_STATE_WALKLEFT 103

#define  CONT_UP 1
#define  CONT_DOWN 2
#define  CONT_LEFT 3
#define  CONT_RIGHT 4

#define  CONT_A 5
#define  CONT_B 6
#define  CONT_AA 7
#define  CONT_BB 8

#define ANIMATE_RIGHT_TAG 11
#define ANIMATE_RIGHT_R_MAP_TAG 12
#define MAP_MOVE_R_TOHERO_TAG 13

//about mainscene touch 
#define TOUCH_MODE_RIGHT 200
#define TOUCH_MODE_LEFT 201
#define TOUCH_MODE_UP 202
#define TOUCH_MODE_DOWN 203
#define TOUCH_MODE_ClICK 204
#define TOUCH_CLICK_LIM 10
#define TOUCH_ACTION_LIM 30

#define  TILE_TYPE_DI 1000
#define  TILE_TYPE_BICK 1001
#define  TILE_TYPE_WHAT 1002
#define  TILE_TYPE_TONG 1004
#define  TILE_TYPE_STEEL 1003

static float MONSTER1_MOVE_SPEED=1.0f;
static float MONSTER2_MOVE_SPEED=0.5f;
static float MONSTER2_MOVE_SPEED_FAST=3.0f;

static int SCENE_NUM=0;



#endif
