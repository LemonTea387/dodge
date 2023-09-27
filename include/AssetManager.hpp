#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "RenderWindow.hpp"
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <map>
#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

// Error loggging
#include <iostream>
class AssetManager {
  typedef uint32_t AssetID;
  typedef std::shared_ptr<SDL_Texture> ResourceP;
  typedef std::map<AssetID, ResourceP> AssetCollection;

public:
  typedef std::pair<AssetID, std::string> AssetMapping;
  /**
   * Delete the copy constructor. We don't want to be able to have multiple
   * instances of the AssetManager, so we don't allow copying it.
   */
  AssetManager(AssetManager const &) = delete;

  /**
   * Deletes the assignment operator. Similarly to the copy constuctor, we don't
   * want to be able to assign the GetInstance() to any other object since we
   * only want a single instance of AssetManager to be available.
   */
  void operator=(const AssetManager &) = delete;
  static AssetManager &GetInstance() {
    static AssetManager instance;
    return instance;
  }

  void LoadAssets(RenderWindow &renderWindow,
                  const std::vector<AssetMapping> &assetMap) {
    for (auto &map : assetMap) {
      LoadAsset(renderWindow, map);
    }
  };

  void LoadAsset(RenderWindow &renderWindow, const AssetMapping idStringPair) {
    // Loads the texture
    SDL_Surface *loadedSurface = IMG_Load(idStringPair.second.c_str());
    if (loadedSurface == nullptr) {
      std::cerr
          << "ERROR - [AssetManager]{LoadAsset} : Surface loading failed, "
          << IMG_GetError() << std::endl;
      return;
    }
    SDL_Texture *newTexture =
        SDL_CreateTextureFromSurface(renderWindow.GetRenderer(), loadedSurface);
    if (newTexture == nullptr) {
      std::cerr
          << "ERROR - [AssetManager]{LoadAsset} : Texture creation failed, "
          << IMG_GetError() << std::endl;
      // Remember to free this
      SDL_FreeSurface(loadedSurface);
      return;
    }
    // No longer required
    SDL_FreeSurface(loadedSurface);

    m_AssetMap.insert(
        {idStringPair.first,
         std::shared_ptr<SDL_Texture>(newTexture, SDL_DestroyTexture)});
  }
  const ResourceP GetTexture(AssetID id) const { return m_AssetMap.at(id); }

private:
  AssetManager(){};
  ~AssetManager(){};
  AssetCollection m_AssetMap;
};

#endif
