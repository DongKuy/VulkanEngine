#ifndef MESH_H
# define MESH_H

#include <vector>
#include <unordered_map>

#include "BufferManip.h"
#include "Devices.h"
#include "Libraries.h"
#include "Utils.h"
#include "Vertex.h"

namespace renderer {
    class Mesh {
    public:
        explicit Mesh(ModelType type);

        void setUp(Devices &devices, VkCommandPool &pool);
        void cleanUp(VkDevice &device);

        VkBuffer &getVertexBuffer();
        VkBuffer &getIndexBuffer();
        uint32_t getIndicesSize() const;

    private:
        void loadModel();
        void createVertexBuffer(Devices &devices, VkCommandPool &pool);
        void createIndexBuffer(Devices &devices, VkCommandPool &pool);

    private:
        std::vector<Vertex> _vertices;
        std::vector<uint32_t> _indices;

        VkBuffer _vertexBuffer;
        VkDeviceMemory _vertexBufferMemory;
        VkBuffer _indexBuffer;
        VkDeviceMemory _indexBufferMemory;

        const ModelType _type;
        const std::unordered_map<ModelType, std::string> _modelFile = {
                {ModelType::SHIPMODEL, "Models/99-intergalactic_spaceship-obj/Intergalactic_Spaceship-(Wavefront).obj"},
                {ModelType::CASAMODEL, "Models/low_poly_tree/Lowpoly_tree_sample.obj"}
        };

    };

    typedef std::unordered_map<ModelType, Mesh> MeshMap_t;
}

#endif
