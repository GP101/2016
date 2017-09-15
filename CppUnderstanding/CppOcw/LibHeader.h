#pragma once

#include "LibSource.h"

extern bool            g_isGameLoop;
extern int             g_keyvalue[256];

void ClearKeyvalues();
void SetOnUpdateCallback(ON_UPDATE_CALLBACK pOnUpdate);
void GameLoop();
