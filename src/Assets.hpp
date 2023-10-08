#ifndef ASSETS_H
#define ASSETS_H

#include "AssetManager.hpp"
#include <vector>
namespace Assets {
enum AssetID { STICKMAN, PLATFORM };
const std::vector<AssetManager::AssetMapping> assets{
    {AssetID::STICKMAN, "assets/stickman.png"},
    {AssetID::PLATFORM, "assets/platform.png"}};
} // namespace Assets

#endif
