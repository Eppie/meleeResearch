#include <stdint.h>

#define SSBM_FUNC_MEMCPY 0x80003220 // memcpy (void *dest, void *src, int len)
#define SSBM_FUNC_MEMMOVE 0x800031F4 // memmove (void *dest, void *src, int len)
#define SSBM_FUNC_MEMSET 0x80003130 // memset (void *addy, int value, int len)
#define SSBM_FUNC_MEMCMP 0x803238C8 // memcmp (void *one, void *two, int len)
#define SSBM_FUNC_STRCPY 0x80301E58 // strcpy (needs to be verified)

#define SSBM_FUNC_DOAIRDEATH 0x800D40B8 // DoAirDeath (player_t *)
#define SSBM_FUNC_DOHITSCREENDEATH 0x800D4780 // DoHitScreenDeath (player_t *)
#define SSBM_FUNC_DOGROUNDDEATH 0x800D3BC8 // DoGroundDeath (player_t *)

#define SSBM_FUNC_PLAYSOUND 0x8038cff4
#define SSBM_FUNC_PLAYMENUSOUND 0x80024030
#define SSBM_FUNC_PLAYMENUBACK 0x8017435c
#define SSBM_FUNC_PLAYMENUFORWARD 0x80174338
#define SSBM_FUNC_PLAYMENUSELECT 0x80174380
#define SSBM_FUNC_PLAYMUSIC 0x80023f28
#define SSBM_FUNC_STOPMUSIC 0x800236dc
#define SSBM_FUNC_STOPALLSOUND 0x8038bd6c

#define SSBM_FUNC_GETCHARPOINTER 0x80034110
#define SSBM_FUNC_MAINCHARLOOP 0x8006ad10 // Executes once per character per frame while in-game
#define SSBM_FUNC_SETSTOCKCOUNT 0x80033c60 // Set a player's stock count
#define SSBM_FUNC_LOSESTOCK 0x80033ce0 // Decrement a player's stock count by 1
#define SSBM_FUNC_LOADACTIONSTATE 0x800693ac
#define SSBM_FUNC_INITACTIONSTATE 0x8008cfac
#define SSBM_FUNC_ACTIONSTATEIASACHECK 0x8006b808
#define SSBM_FUNC_ENDSTOCKGAME 0x8016c080 // Ends the game but doesn't go to score screen
#define SSBM_FUNC_PLAYERCOUNT 0x8016b558 // Return the number of players in the current game
#define SSBM_FUNC_GETCHARSUNLOCKED 0x80164840 // Who cares
#define SSBM_FUNC_CHECKSTALEMOVES 0x8003722c // Who cares

#define SSBM_VAL_PERCENTDISPLAY1 0x804530E0 // P1 on-screen percentage display (high 16 bits)
#define SSBM_VAL_PERCENTDISPLAY2 0x80453F70 // P2 on-screen percentage display (high 16 bits)
#define SSBM_VAL_PERCENTDISPLAY3 0x80454E00 // P3 on-screen percentage display (high 16 bits)
#define SSBM_VAL_PERCENTDISPLAY4 0x80455C90 // P4 on-screen percentage display (high 16 bits)

struct static_player_block_t { //0xE90 bytes long
	long unknown1;
	long playerType; /*0x04: long, player type (external index)*/
	long slotType; /*0x08: long, slot type (human, cpu, demo, none)*/
	long unknown2;
	float x; /*0x10: float, X coordinate (horizontal)*/
	float y; /*0x14: float, Y coordinate (vertical)*/
	float z; /*0x18: float, Z coordinate?  (depth)*/
	// TODO: Insert required spacing
	uint8_t isComputer; /*0x44: byte, bool computer?*/
	uint8_t controllerIndex; /*0x45: byte, controller index*/
	uint16_t displayedHealth; /*0x60: short, currently /displayed/ health. (ALWAYS counts up)*/
	uint16_t startingHealth; /*0x62: short, health start value.*/
	// TODO: Insert required spacing
	uint32_t currentCoins; /*0x90: int, current coins*/
	uint32_t totalCoins; /*0x94: int, total collected.*/
	// TODO: Insert required spacing
	uint8_t multiSpawn; /*0xAC: byte, flag 0x40 means "eligible for multi spawn"*/
	// TODO: Insert required spacing
	uint32_t* playerPointer; /*0xB0: void*, pointer to player_t*/
	uint32_t* nanaPointer; /*0xB4: void*, pointer to player_t for nana, if applicable*/
};

/*
 * Returns the selected player's percent.
 * @param int playerNumber Specifies which player's percent to get. 1-indexed.
 * @return uint16_t The percent of the selected player, or 0 if the input was invalid.
 */
uint16_t getPlayerPercent( int playerNumber ) {
		uint32_t* p1Percent = SSBM_VAL_PERCENTDISPLAY1;
		uint32_t* p2Percent = SSBM_VAL_PERCENTDISPLAY2;
		uint32_t* p3Percent = SSBM_VAL_PERCENTDISPLAY3;
		uint32_t* p4Percent = SSBM_VAL_PERCENTDISPLAY4;
	switch( playerNumber ) {
		case 1:
			return *p1Percent >> 16;
		case 2:
			return *p2Percent >> 16;
		case 3:
			return *p3Percent >> 16;
		case 4:
			return *p4Percent >> 16;
		default:
			return 0;
	}
}

int _main() {
	// built in functions setup
	/*uint16_t *( *endStockGame )() = SSBM_FUNC_ENDSTOCKGAME;*/
	// APPEARS TO BE 0-indexed!
	uint32_t *( *getPointerToCharacter )( int ) = SSBM_FUNC_GETCHARPOINTER;
	/*void *( *PlayMenuForwardSound )() = SSBM_FUNC_PLAYMENUFORWARD;*/
	/*uint32_t *( *getPlayerCount )() = SSBM_FUNC_PLAYERCOUNT;*/

	if( getPlayerPercent( 1 ) > 100 ) {
		uint32_t* player1Pointer = getPointerToCharacter( 1 );
		uint32_t* p1Percent = SSBM_VAL_PERCENTDISPLAY1;
		*p1Percent = player1Pointer;
		/*endStockGame();*/
	}
}
