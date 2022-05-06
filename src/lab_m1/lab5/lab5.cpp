#include "lab_m1/lab5/lab5.h"
#include "lab_m1/lab4/transform3D.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;

Lab5::Lab5()
{
}


Lab5::~Lab5()
{
}


void Lab5::Init() {
        camera = new implemented::Camera();
        camera->Set(glm::vec3(0.05f, 2.02f, 2.1f), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));

        // shadere pentru colorat
        Shader* shader1 = new Shader("shader1");
        Shader* shader2 = new Shader("shader2");
        Shader* shader3 = new Shader("shader3");
        Shader* shader4 = new Shader("shader4");
        Shader* shader5 = new Shader("shader5");
        Shader* shader6 = new Shader("shader6");

        // lumea e doar din cuburi
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;

        // perspectiva in care vad lumea
        projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);

        shader1->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "vertex1.glsl"), GL_VERTEX_SHADER);
        shader1->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "shader1.glsl"), GL_FRAGMENT_SHADER);
        shader1->CreateAndLink();
        shaders[shader1->GetName()] = shader1;
        
        shader2->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "vertex2.glsl"), GL_VERTEX_SHADER);
        shader2->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "shader2.glsl"), GL_FRAGMENT_SHADER);
        shader2->CreateAndLink();
        shaders[shader2->GetName()] = shader2;
        
        shader3->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "vertex3.glsl"), GL_VERTEX_SHADER);
        shader3->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "shader3.glsl"), GL_FRAGMENT_SHADER);
        shader3->CreateAndLink();
        shaders[shader3->GetName()] = shader3;
        
        shader4->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "vertex4.glsl"), GL_VERTEX_SHADER);
        shader4->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "shader4.glsl"), GL_FRAGMENT_SHADER);
        shader4->CreateAndLink();
        shaders[shader4->GetName()] = shader4;
        
        shader5->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "vertex5.glsl"), GL_VERTEX_SHADER);
        shader5->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "shader5.glsl"), GL_FRAGMENT_SHADER);
        shader5->CreateAndLink();
        shaders[shader5->GetName()] = shader5;
        
        shader6->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "vertex6.glsl"), GL_VERTEX_SHADER);
        shader6->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "shader6.glsl"), GL_FRAGMENT_SHADER);
        shader6->CreateAndLink();
        shaders[shader6->GetName()] = shader6;

        const int latime = 10;
        const int lungime = 20;

        int labirintRandom = rand() % 7 + 1;
        int labirint1[latime][lungime] = {
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {1,1,1,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };

        int labirint2[latime][lungime] = {
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {1,1,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };

        int labirint3[latime][lungime] = {
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };

        int labirint4[latime][lungime] = {
                 {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {1,1,1,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };

        int labirint5[latime][lungime] = {
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
                 {1,1,1,2,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,0},
                 {0,0,0,0,0,0,1,2,2,2,1,1,0,0,0,0,0,1,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}
        };

        int labirint6[latime][lungime] = {
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {1,1,1,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };

        int labirint7[latime][lungime] = {
                 {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,1,2,1,1,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {1,1,1,2,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,1,2,2,1,0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}
        };

            if (labirintRandom == 1) {
                for (int i = 0; i < latime; i++) {
                    for (int j = 0; j < lungime; j++) {
                        labirint[i][j] = labirint1[i][j];
                    }
                }
            }
            else if (labirintRandom == 2) {
                for (int i = 0; i < latime; i++) {
                    for (int j = 0; j < lungime; j++) {
                        labirint[i][j] = labirint2[i][j];
                    }
                }
            }
            else if (labirintRandom == 3) {
                for (int i = 0; i < latime; i++) {
                    for (int j = 0; j < lungime; j++) {
                        labirint[i][j] = labirint3[i][j];
                    }
                }
            }
            else if (labirintRandom == 4) {
                for (int i = 0; i < latime; i++) {
                    for (int j = 0; j < lungime; j++) {
                        labirint[i][j] = labirint4[i][j];
                    }
                }
            }
            else if (labirintRandom == 5) {
                for (int i = 0; i < latime; i++) {
                    for (int j = 0; j < lungime; j++) {
                        labirint[i][j] = labirint5[i][j];
                    }
                }
            }
            else if (labirintRandom == 6) {
                for (int i = 0; i < latime; i++) {
                    for (int j = 0; j < lungime; j++) {
                        labirint[i][j] = labirint6[i][j];
                    }
                }
            }
            else if (labirintRandom == 7) {
                for (int i = 0; i < latime; i++) {
                    for (int j = 0; j < lungime; j++) {
                        labirint[i][j] = labirint7[i][j];
                    }
                }
            }

        pozitionareCamera();
}

// pozitioneaza camera unde e jucatorul
void Lab5::pozitionareCamera() {
    int matriceX = 10;
    int matriceY = 20;
    int inalZid = 8;
    int drum = 1;
    int offset = 10;
    int lungimeZ = -6;
    int posStanga = 0;
    int lungimePlaca = 25;

    // caut sa pun prima pozitie libera
        for (int i = 0; i < matriceX * lungimePlaca; i += lungimePlaca) {
            for (int j = 0; j < matriceY * lungimePlaca; j += lungimePlaca) {
                // intru pe partea din stanga a matricei
                if (labirint[i / lungimePlaca][j / lungimePlaca] == 1) {
                    if (labirint[i / lungimePlaca][posStanga] == drum) {
                        jucatorInitialX = i / lungimePlaca;
                        jucatorInitialY = j / lungimePlaca;
                        break;
                    }
                }

            }
        }
        cameraZ = lungimeZ;
        cameraY = jucatorInitialY + offset;
        cameraX = jucatorInitialX * lungimePlaca;

        int a = 0;
        int b = -20;
        int c = 340;
        
        camera->Set(glm::vec3(cameraX, cameraY, cameraZ), glm::vec3(a, b, c), glm::vec3(0, 1, 0));
        glm::vec3 aux = camera->GetTargetPosition();
}

// pentru culoare
Mesh* Lab5::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices)
{
    unsigned int VAO = 0;
    // Create the VAO and bind it
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Create the VBO and bind it
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Send vertices data into the VBO buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    // Create the IBO and bind it
    unsigned int IBO;
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    // Send indices data into the IBO buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

    // Set vertex normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

    // Set texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

    // Set vertex color attribute
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
    // ========================================================================

    // Unbind the VAO
    glBindVertexArray(0);

    // Check for OpenGL errors
    CheckOpenGLError();

    // Mesh information is saved into a Mesh object
    meshes[name] = new Mesh(name);
    meshes[name]->InitFromBuffer(VAO, static_cast<unsigned int>(indices.size()));
    meshes[name]->vertices = vertices;
    meshes[name]->indices = indices;
    return meshes[name];
}


void Lab5::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void Lab5::desenareJucator() {
    int latimeParchet = 25;
    const int inaltimePicior = 2;
    const int inaltimeCorp = 4;
    const int inaltimeMana = 5;
    const int inaltimeCap = 7;

    // cap jucator
    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 0.5f, inaltimeCap, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);

    // corp
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet, inaltimeCorp, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet, inaltimeCorp + 1, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet, inaltimeCorp + 2, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 1, inaltimeCorp, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 1, inaltimeCorp + 1, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 1, inaltimeCorp + 2, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);

    // picioare
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet, inaltimePicior, playerY + jucatorInitialY * latimeParchet));
    modelMatrix = glm::rotate(modelMatrix, RADIANS(rotate), glm::vec3(0, 1, 0));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet, inaltimePicior + 1, playerY + jucatorInitialY * latimeParchet));
    modelMatrix = glm::rotate(modelMatrix, RADIANS(rotate), glm::vec3(0, 1, 0));
    RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 1, inaltimePicior, playerY + jucatorInitialY * latimeParchet));
    modelMatrix = glm::rotate(modelMatrix, RADIANS(rotate), glm::vec3(0, 1, 0));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 1, inaltimePicior + 1, playerY + jucatorInitialY * latimeParchet));
    modelMatrix = glm::rotate(modelMatrix, RADIANS(rotate), glm::vec3(0, 1, 0));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);

    // maini
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet - 1, inaltimeMana + 1, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet - 1, inaltimeMana, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 2, inaltimeMana + 1, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(playerX + jucatorInitialX * latimeParchet + 2, inaltimeMana, playerY + jucatorInitialY * latimeParchet));
    RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);
}

void Lab5::desenareLabirint(float deltaTimeSeconds) {
    int matriceX = 10;
    int matriceY = 20;
    int latimeParchet = 25;
    const int inamic = 2;
    const int drum = 1;
    const int zid = 0;
    int inaltimeZid = 80;

    // labirintul de desenat
    for (int i = 0; i < matriceX * latimeParchet; i += latimeParchet) {
        for (int j = 0; j < matriceY * latimeParchet; j += latimeParchet) {
            // desenare inamic
            if (labirint[i / latimeParchet][j / latimeParchet] == inamic) {
                int vitezaInamic = 5;
                glm::mat4 modelMatrix = glm::mat4(1);
                modelMatrix = glm::translate(modelMatrix, glm::vec3(i, 1, j));
                modelMatrix *= transform3D::Scale(latimeParchet, 1, latimeParchet);
                RenderMesh(meshes["box"], shaders["shader4"], modelMatrix);
                desenareInamic(i, j, vitezaInamic, deltaTimeSeconds);
            }
            // desenare drum
            if (labirint[i / latimeParchet][j / latimeParchet] == drum) {
                glm::mat4 modelMatrix = glm::mat4(1);
                modelMatrix = glm::translate(modelMatrix, glm::vec3(i, 1, j));
                modelMatrix *= transform3D::Scale(latimeParchet, 1, latimeParchet);
                RenderMesh(meshes["box"], shaders["shader1"], modelMatrix);
            }
            // desenare zid
            if (labirint[i / latimeParchet][j / latimeParchet] == zid) {
                int inaltime = inaltimeZid / 2;
                glm::mat4 modelMatrix = glm::mat4(1);
                modelMatrix = glm::translate(modelMatrix, glm::vec3(i, inaltime, j));
                modelMatrix *= transform3D::Scale(latimeParchet, inaltimeZid, latimeParchet);
                RenderMesh(meshes["box"], shaders["shader2"], modelMatrix);

                int jumatate = inaltimeZid / 2;
                inaltime = inaltimeZid + jumatate;
                modelMatrix = glm::mat4(1);
                modelMatrix = glm::translate(modelMatrix, glm::vec3(i, inaltime, j));
                modelMatrix *= transform3D::Scale(latimeParchet, inaltimeZid, latimeParchet);
                RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);
            }
        }
    }
}

void Lab5::Update(float deltaTimeSeconds) {    
    desenareJucator();
    desenareLabirint(deltaTimeSeconds);
}

void Lab5::desenareInamic(int i, int j, float deltaTimeSeconds, float viteza) {
    deplasareInamicFunctie(viteza, deltaTimeSeconds);
    int offset = 5;
    const int inaltimePicior = 2;
    const int inaltimeCorp = 4;
    const int inaltimeCap = 7;

    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + 1 + deplasareInamic, inaltimePicior, j + offset));
    RenderMesh(meshes["box"], shaders["shader6"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + 1 + deplasareInamic, inaltimeCorp - 1, j + offset));
    RenderMesh(meshes["box"], shaders["shader6"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 1 + deplasareInamic, inaltimeCorp - 2, j + offset));
    modelMatrix *= transform3D::Scale(2.5, 2.5, 2.5);
    RenderMesh(meshes["box"], shaders["shader6"], modelMatrix);

    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + deplasareInamic, inaltimePicior, j + offset));
    pozitiePiciorInamicX = deplasareInamic;
    pozitiePiciorInamicY = j;
    RenderMesh(meshes["box"], shaders["shader5"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + deplasareInamic, inaltimePicior + 1, j + offset));
    RenderMesh(meshes["box"], shaders["shader5"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i - 1 + deplasareInamic, inaltimeCorp + 1, j + offset));
    RenderMesh(meshes["box"], shaders["shader6"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + 0.5f + deplasareInamic, inaltimeCap, j + offset));
    modelMatrix *= transform3D::Scale(2, 2, 2);
    RenderMesh(meshes["box"], shaders["shader3"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + 2 + deplasareInamic, inaltimeCorp + 2, j + offset));
    modelMatrix *= transform3D::Scale(2.5, 2.5, 2.5);
    RenderMesh(meshes["box"], shaders["shader5"], modelMatrix);

    modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + 2 + deplasareInamic, inaltimeCorp + 1, j + offset));
    RenderMesh(meshes["box"], shaders["shader5"], modelMatrix);
    
}

void Lab5::deplasareInamicFunctie(float viteza, float deltaTimeSeconds) {
    bool setat = true;
    bool neSetat = false;
    int distantaDeMers = 10;
    if (stangaDreapta == false) {
        deplasareInamic -= viteza * deltaTimeSeconds - 0.001f;
    } else if (stangaDreapta == true) {
        deplasareInamic += viteza * deltaTimeSeconds + 0.01;
    }

    if (deplasareInamic >= distantaDeMers) {
        stangaDreapta = neSetat;
    }

    if (deplasareInamic <= -distantaDeMers) {
        stangaDreapta = setat;
    }
}

void Lab5::FrameEnd()
{
    DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
}


void Lab5::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


void Lab5::OnInputUpdate(float deltaTime, int mods) {
    if (window->KeyHold(GLFW_KEY_W)) {
        camera->TranslateForward(20.0f * deltaTime);
        playerY += 20.0f * deltaTime;
    }
    if (window->KeyHold(GLFW_KEY_A)) {
        camera->TranslateRight(20.0f * deltaTime);
        playerX += 20.0f * deltaTime;
    }
    if (window->KeyHold(GLFW_KEY_S)) {
        camera->TranslateForward(-20.0f * deltaTime);
        playerY -= 20.0f * deltaTime;
    }
    if (window->KeyHold(GLFW_KEY_D)) {
        camera->TranslateRight(-20.0f * deltaTime);
        playerX -= 20.0f * deltaTime;
    }
}


void Lab5::OnKeyPress(int key, int mods) {
    if (key == GLFW_KEY_L) {
        if (apasat == false) {
            playerY -= 6.1f;
            apasat = true;
        }
        else {
            playerY += 6.1f;
            apasat = false;
        }
    }
}

void Lab5::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) {
    camera->RotateFirstPerson_OX(-0.005f * deltaY);
    camera->RotateFirstPerson_OY(-0.005f * deltaX);
}


void Lab5::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) {}
