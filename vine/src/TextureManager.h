#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <string>
#include <map>
#include <SDL2/SDL.h>

namespace Vine {
    class TextureManager
    {
    private:
        static std::map<std::string, SDL_Texture*> _textures;
    public:
        ~TextureManager();

        static void addTexture(SDL_Renderer& renderer, const std::string filepath, const std::string textureName);
        static SDL_Texture* getTexture(const std::string textureName);
    };
};

#endif
