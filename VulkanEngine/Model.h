#ifndef MODEL_HPP
# define MODEL_HPP

#include <vector>
#include <memory>
#include <numeric>

#include "Camera.h"
#include "Framebuffers.h"
#include "GraphicsPipeline.h"
#include "DescriptorSets.h"
#include "Devices.h"
#include "Libraries.h"
#include "Texture.h"
#include "UniformBuffers.h"
#include "Utils.h"

namespace renderer {
    class Model {
    public:
        explicit Model(ModelType type, ModelKey color);
        virtual ~Model() = default;

        void setUp(Devices &devices, SwapChain &swapChain, GraphicsPipeline &pipeline,
                Framebuffers &framebuffers, VkCommandPool &pool, TextureMap_t &textures);
        void cleanUp(VkDevice &device);

        void setPosition(glm::vec3 position);
        void setOrientation(glm::vec3 orientation);
        void setCamera(scene::Camera_ptr_t &_camera, float ratio);

        virtual void update(std::vector<std::unique_ptr<Model>> &models);
        virtual void updateUniformBuffer(VkDevice &device, uint32_t currentImage);

        size_t getId() const;
        glm::vec3 getPosition() const;
        glm::vec3 getVelocity() const;
        ModelType getModelType() const;
        VkDescriptorSet &getDescriptorSet(size_t i);

    protected:
        glm::vec3 _velocity = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _orientation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _offset = glm::vec3(0.0f, 0.5f, 0.0f);

    private:
        const size_t _id;
        static size_t _idGen;
        const ModelType _type;
        const ModelKey _key;

        UniformBufferObject _ubo = {};
        UniformBuffers _uniforms;
        DescriptorSets _descriptorSets;
    };

    typedef std::vector<std::unique_ptr<Model>> Models_t;
}


#endif
