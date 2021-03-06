#include "LoadObjects.h"
#include "GameEngine.h"
#include "ScreenEngine.h"

#include <map>
#include "FreeImage.h"

using namespace std;

#ifndef GRAPHIC_ENGINE
#define GRAPHIC_ENGINE

class GraphicEngine {
  private:
    // Constants.
    const char* GRAPHICS_ENGINE_DOCUMENT_PATH = "data/Info/Out_Graphics_Engine.txt";
    const char* GRASS_TEXTURE_PATH = "data/Textures/Grass.jpg";
    const char* WOOD_TEXTURE_PATH = "data/Textures/Wood.jpg";
    const char* STONE_TEXTURE_PATH = "data/Textures/Stone.jpg";
    const char* SNAKE_TEXTURE_PATH = "data/Textures/Snake.jpg";
    const char* APPLE_TEXTURE_PATH = "data/Textures/Apple/skin.jpg";
    const char* STAR_TEXTURE_PATH = "data/Textures/Star.jpg";
    const char* EARTH_TEXTURE_PATH = "data/Textures/Earth.jpeg";
    const char* MOON_TEXTURE_PATH = "data/Textures/Moon.jpeg";
    const char* SUN_TEXTURE_PATH = "data/Textures/Sun.jpg";
    const char* MERCURY_TEXTURE_PATH = "data/Textures/Mercury.jpeg";
    const char* VENUS_TEXTURE_PATH = "data/Textures/Venus.png";
    const char* JUPITER_TEXTURE_PATH = "data/Textures/Jupiter.jpg";
    const char* MARS_TEXTURE_PATH = "data/Textures/Mars.jpg";
    const char* URANO_TEXTURE_PATH = "data/Textures/Urano.jpeg";
    const char* NEPTUNO_TEXTURE_PATH = "data/Textures/Neptuno.jpeg";
    const char* GALAXY_TEXTURE_PATH = "data/Textures/galaxy.png";
    
    const char* SNAKE_OBJECT_PATH = "data/Models/Snake.obj";
    const char* APPLE_OBJECT_PATH = "data/Models/Apple.obj";
    const char* PLANET_OBJECT_PATH = "data/Models/Planeta.obj";
    const char* STAR_OBJECT_PATH = "data/Models/Star.obj";

    
    // Document.
    ofstream Document;
    
    // Textures.
    GLuint TEXTURE_GRASS, TEXTURE_WOOD, TEXTURE_SNAKE, TEXTURE_APPLE, TEXTURE_STONE,TEXTURE_STAR,TEXTURE_EARTH,TEXTURE_MOON, TEXTURE_SUN, TEXTURE_MERCURY, TEXTURE_VENUS, TEXTURE_JUPITER, TEXTURE_MARS, TEXTURE_URANO, TEXTURE_NEPTUNO, TEXTURE_GALAXY;
    
    // Window clear color.
    int clear_color = 0;
    
    /// Cam Information.
    data_camera camera;
    
    static GraphicEngine* instance;
    GraphicEngine();
    void LoadEnv();
    void LoadModels();
    void LoadTexture(GLuint &texture, const char* texture_name);
    void DrawLight();
    void Drawcamera();
    void DrawScene();
    void DrawCharacters();
    void DrawContexto();
    void DrawEnv();
    ~GraphicEngine();

  public:
    static GraphicEngine* GetInstance();
    void Draw();
    void ruedita(bool);
    void ChangeMode();
    void Changecamera();
    void ManageTexture();
    void ManageLight();
    void MotionCamara(int,int);
};

#endif