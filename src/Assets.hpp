#ifndef ASSETS_H
#define ASSETS_H

#include "AssetManager.hpp"
#include <vector>
namespace Assets {
enum AssetID { STICKMAN };
const std::vector<AssetManager::AssetMapping> assets{
    {AssetID::STICKMAN, "assets/stickman.png"},
};
} // namespace Assets

#endif
