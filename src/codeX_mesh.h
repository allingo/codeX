/*
 * CodeX Studio Copyright.
 */
#ifndef __CODEX_MESH_H__
#define __CODEX_MESH_H__

#include "codeX_base.h"
#include <vector>
#include <assimp/mesh.h>
#include <assimp/types.h>
#include <assimp/scene.h>
#include <assimp/material.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include "codeX_texture.h"
#include "codeX_opengl_wrapper.h"

#define INDEX_BUFFER 0    
#define POS_VB       1
#define NORMAL_VB    2
#define TEXCOORD_VB  3    
#define WVP_MAT_VB   4
#define WORLD_MAT_VB 5

namespace Assert
{
    struct MeshEntry
    {
        MeshEntry();
        ~MeshEntry();
        void Init(const std::vector<Vertex>& Vertices,
                  const std::vector<unsigned int>& Indices);

        GLuint VB;
        GLuint IB;
        unsigned int NumIndices;
        unsigned int MaterialIndex;
    };

    class Mesh
    {
        public:
            Mesh();
            ~Mesh();
            bool LoadMesh(const std::string& Filename);
            void Render();
        private:
            bool InitFromScene(const aiScene* pScene, const std::string& Filename);
            void InitMesh(unsigned int Index, const aiMesh* paiMesh);
            bool InitMaterials(const aiScene* pScene, const std::string& Filename);
            void Clear();
            std::vector<MeshEntry> m_Entries;
            std::vector<Texture*> m_Textures;
    };
}
#endif
