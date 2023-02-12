#include "Game.h"
#include "utility/Logger.h"
#include "utility/Localization.h"
#include <filesystem>
#include "utility/SystemTimer.h"
#include "gamestate/GameState.h"
#include "gamestate/SplashScreenState.h"
#include "Buffer.h"
#include "VertexArray.h"


bool Game::Initialize() {
    isRunning = true;

    if(!Settings::Load(std::filesystem::current_path().string() + "/Data/Settings.configuration")) { //TODO get path string elsewhere?
        Logger::Log("Client - Could not load settings file.");
        return false;
    }

    if(!Localization::LoadLanguage(static_cast<Languages>(std::stoi(Settings::GetSetting("Language"))))) {
        Logger::Log("Client - Could not load language file.");
        return false;
    }

    window = new Window(new WindowData(
            Localization::GetString("Title"),
            static_cast<bool>(std::stoi(Settings::GetSetting("WindowedModeEnabled"))),
            static_cast<uint32>(std::stoul(Settings::GetSetting("ResolutionWidth"))),
            static_cast<uint32>(std::stoul(Settings::GetSetting("ResolutionHeight"))),
            static_cast<bool>(std::stoi(Settings::GetSetting("VSyncEnabled")))));



    GameState::Initialize(new SplashScreenState);

    return true;
}


void Game::Run() {
    const uint32 UPDATES_PER_SECOND = 30;
    const uint32 SKIP_TICKS = 1000 / UPDATES_PER_SECOND;
    const uint32 MAX_FRAME_SKIP = 5;

    uint64 nextGameUpdate = SystemTimer::GetTickCountSinceInitialization();
    uint32 loops;
    float interpolation;

    while(isRunning) {
        loops = 0;

        while(SystemTimer::GetTickCountSinceInitialization() > nextGameUpdate && loops < MAX_FRAME_SKIP) {
            GameState::GetCurrentGameState()->Update();
            ProcessEvents();
            ProcessInput();
            Update();

            nextGameUpdate += SKIP_TICKS;
            loops++;
        }

        interpolation = float(SystemTimer::GetTickCountSinceInitialization() +  - nextGameUpdate) / float();
        Render(interpolation);
    }
}


void Game::Shutdown() {
    window->Close();
    Settings::SaveToFile(std::filesystem::current_path().string() + "/Data/Settings.configuration"); //TODO get path string elsewhere?
}


void Game::ProcessInput() {
    glfwPollEvents();

    if(glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE ) == GLFW_PRESS) {
        isRunning = false;
    }
}


void Game::ProcessEvents() {

}


void Game::Update() {

}


void Game::Render(float interpolation) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //TESTING
    float vertices[] = {
            -0.5f, -0.5f,
             0.5f, -0.5f,
             0.5f,  0.5f,
            -0.5f,  0.5f
    };

    uint32 indices[] = {
            0, 1, 2,
            2, 3, 0
    };

    Reference<VertexArray> va(new VertexArray());
    Reference<VertexBuffer> vb(new VertexBuffer(vertices, 4 * 2 * sizeof(float)));

    std::string name = "Position";
    //Set the layout of the vertex buffer
    vb->SetLayout({
        { BufferElement(name, ShaderDataType::Float2) }
    });

    //Add the vertex buffer and its layout to the vertex array
    va->AddVertexBuffer(vb);

    Reference<IndexBuffer> ib(new IndexBuffer(indices, 6));

    va->SetIndexBuffer(ib);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);


    glfwSwapBuffers(window->GetWindow());
    // view_position = position + (speed * interpolation) for updating rendered things between frames
}


/*
    CREATING ENTITIES WITH SPECIFIC COMPONENTS
    for(auto i = 0u; i < 10u; ++i) {
        const auto entity = registry.create();
        registry.emplace<TransformComponent>(entity, Vector2(1.0, 1.0), Vector2(1.0, 1.0), 1.0f);
    }

 */