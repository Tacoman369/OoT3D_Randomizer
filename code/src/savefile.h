#ifndef _SAVEFILE_H_
#define _SAVEFILE_H_

#include "z3D/z3D.h"

#define SAVEFILE_SCENES_DISCOVERED_IDX_COUNT 4
#define SAVEFILE_ENTRANCES_DISCOVERED_IDX_COUNT 66

u8 SaveFile_GetMedallionCount(void);
u8 SaveFile_GetStoneCount(void);
u8 SaveFile_GetDungeonCount(void);
u8 SaveFile_GetIsSceneDiscovered(u8 sceneNum);
void SaveFile_SetSceneDiscovered(u8 sceneNum);
u8 SaveFile_GetIsEntranceDiscovered(u16 entranceIndex);
void SaveFile_SetEntranceDiscovered(u16 entranceIndex);
void SaveFile_SetStartingInventory(void);
void SaveFile_SetTradeItemAsOwned(u8 itemId);
void SaveFile_UnsetTradeItemAsOwned(u8 itemId);
u32 SaveFile_TradeItemIsOwned(u8 itemId);
void SaveFile_SetOwnedTradeItemEquipped(void);
void SaveFile_ResetItemSlotsIfMatchesID(u8 itemSlot);
u8 SaveFile_InventoryMenuHasSlot(u8 adult, u8 itemSlot);
void SaveFile_InitExtSaveData(u32 fileBaseIndex);
void SaveFile_LoadExtSaveData(u32 saveNumber);
void SaveFile_SaveExtSaveData(u32 saveNumber);
void SaveFile_EnforceHealthLimit(void);
u8 SaveFile_SwordlessPatchesEnabled(void);

// Increment the version number whenever the ExtSaveData structure is changed
#define EXTSAVEDATA_VERSION 11

typedef enum {
    EXTINF_BIGGORONTRADES,
    EXTINF_HASTIMETRAVELED,
    EXTINF_MASTERSWORDFLAGS,
    EXTINF_SIZE,
} ExtInf;

typedef struct {
    u32 version;            // Needs to always be the first field of the structure
    u8 extInf[EXTINF_SIZE]; // Used for various bit flags
    struct {
        Vec3i pos;
        s32  yaw;
        s32  playerParams;
        s32  entranceIndex;
        s32  roomIndex;
        s32  set;
        s32  tempSwchFlags;
        s32  tempCollectFlags;
    }   fwStored;
    u32 playtimeSeconds;
    u32 scenesDiscovered[SAVEFILE_SCENES_DISCOVERED_IDX_COUNT];
    u32 entrancesDiscovered[SAVEFILE_ENTRANCES_DISCOVERED_IDX_COUNT];
    // Ingame Options, all need to be s8
    s8 option_EnableBGM;
    s8 option_EnableSFX;
    s8 option_SilenceNavi;
    s8 option_IgnoreMaskReaction;
    s8 option_SkipSongReplays;
} ExtSaveData;

#ifdef DECLARE_EXTSAVEDATA
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN ExtSaveData gExtSaveData;

#endif //_SAVEFILE_H_
