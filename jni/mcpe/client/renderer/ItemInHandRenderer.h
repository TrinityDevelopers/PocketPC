#pragma once

#include "../MinecraftClient.h"
#include "../../item/ItemInstance.h"

class ItemInHandRenderer {
public:
	char filler0[56]; //0
	ItemInstance currentItem; //56 (from ItemInHandRenderer::render, also in ItemInHandRenderer::ItemInHandRenderer)
	MinecraftClient* minecraft; //76 (from ItemInHandRenderer::ItemInHandRenderer)
	void render(float);
};