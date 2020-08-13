#include "TextureManager.h"
#include <SDL2_Image/SDL_image.h>
#include <spdlog/spdlog.h>

std::map<std::string, SDL_Texture*> Vine::TextureManager::_textures;

Vine::TextureManager::~TextureManager()
{
    for (auto& texture : _textures)
    {
        SDL_DestroyTexture(texture.second);
    }
}

void Vine::TextureManager::addTexture(SDL_Renderer& renderer, const std::string filepath, const std::string textureName)
{
    spdlog::info("Adding texture from: \"{}\"", filepath);
    SDL_Surface* tmpSurface = IMG_Load(filepath.c_str());

    if (!tmpSurface)
    {
        spdlog::error("Unable to load surface");
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(&renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    _textures.emplace(textureName, texture);
}

SDL_Texture* Vine::TextureManager::getTexture(const std::string textureName)
{
    spdlog::info("Getting texture: \"{}\"", textureName);

    return _textures.at(textureName);
}
