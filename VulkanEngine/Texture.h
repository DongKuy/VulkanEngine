#ifndef TEXTURE_HPP
# define TEXTURE_HPP

#include <unordered_map>
#include <string>

#include "BufferManip.h"
#include "Devices.h"
#include "Libraries.h"
#include "Utils.h"

namespace renderer {

    class Texture {
    public:
        explicit Texture(ModelKey color);

        void setUp(Devices &devices, VkCommandPool &pool);
        void cleanUp(VkDevice &device);

        VkImageView &getImageView();
        VkSampler &getSampler();

    private:
        void createTextureImage(Devices &devices, VkCommandPool &pool, const std::string &textureName);
        void createTextureImageView(VkDevice &device);
        void createTextureSampler(VkDevice &device);

    private:
        VkImage _textureImage;
        VkDeviceMemory _textureImageMemory;
        VkImageView _textureImageView;
        VkSampler _textureSampler;

        const ModelKey _key;
        const std::unordered_map<ModelKey, std::string> _textureFile = {
                {ModelKey::GOUN, "Models/99-intergalactic_spaceship-obj/textures/Intergalactic Spaceship_rough.jpg"},
        };
    };

    typedef std::unordered_map<ModelKey, Texture> TextureMap_t;
}

#endif
