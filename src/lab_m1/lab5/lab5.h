#pragma once

#include "components/simple_scene.h"
#include "lab_m1/lab5/lab_camera.h"


namespace m1
{
    class Lab5 : public gfxc::SimpleScene
    {
     public:
        Lab5();
        ~Lab5();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix) override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;

        
        Mesh* CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);
        void desenareInamic(int latime, int lungime, float viteza, float deltaTimeSeconds);

        // selectare labirint
        void pozitionareCamera();
        // desenare jucator
        void desenareJucator();
        void deplasareInamicFunctie(float viteza, float deltaTime);
        void desenareLabirint(float time);

     protected:
        implemented::Camera *camera;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget;

        // labirint
        int labirint[10][20];

        // inamic
        int inamicX[300];
        int inamicY[300];

        // jucatorul pozitionat initial
        float jucatorInitialX = 0;
        float jucatorInitialY = 0;
        float jucatorInitialZ = 0;

        // pozitie player
        float playerX = 0;
        float playerY = 0;
        float playerZ = 0;

        // camera initial
        int cameraX = 0;
        int cameraY = 0;
        int cameraZ = 0;

        // pentru a trece in modul first person
        bool firstPerson = false;

        // pentru inamici
        float deplasareInamic = 10;
        bool stangaDreapta = false;

        
        // unghiul de rotatie
        float rotate = 0;
        // first person
        bool apasat = false;

        // pentru inamic
        float pozitiePiciorInamicX = 0;
        float pozitiePiciorInamicY = 0;
    };
}   // namespace m1
