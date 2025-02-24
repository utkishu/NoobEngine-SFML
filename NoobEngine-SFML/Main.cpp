//#include <SFML/Graphics.hpp>
//#include "Candle/RadialLight.hpp"
//#include "Candle/LightingArea.hpp"
//
//int main() {
//	// create window
//	sf::RenderWindow w(sf::VideoMode(300, 379), "app");
//
//	// create a light source
//	candle::RadialLight light;
//	light.setRange(100);
//	light.setFade(false);
//
//	// load the image
//	sf::Texture img1;
//	if (!img1.loadFromFile("gfx/MushroomTrans.png")) {
//		exit(1);
//	}
//	sf::Sprite background(img1);
//
//	// create the lighting area
//	sf::Texture img2;
//	if (!img2.loadFromFile("gfx/Beach_Ball.png")) {
//		exit(1);
//	}
//	candle::LightingArea fog(candle::LightingArea::FOG,
//		&img1);
//	fog.setScale((float)w.getSize().x / img2.getSize().x,
//		(float)w.getSize().y / img2.getSize().y);
//
//
//
//	// main loop
//	while (w.isOpen()) {
//		sf::Event e;
//		while (w.pollEvent(e)) {
//			if (e.type == sf::Event::Closed) {
//				w.close();
//			}
//			else if (e.type == sf::Event::MouseMoved) {
//				sf::Vector2f mp(sf::Mouse::getPosition(w));
//				light.setPosition(mp);
//			}
//		}
//
//		fog.clear();
//		fog.draw(light);
//		fog.display();
//
//		w.clear();
//		w.draw(background);
//		w.draw(fog);
//		w.display();
//	}
//	return 0;
//}









//
//version 0.2 
//#include <SFML/Graphics.hpp>
//#include "Candle/RadialLight.hpp"
//#include "Candle/DirectedLight.hpp"
//#include "Candle/LightingArea.hpp"
//
//int main() {
//	// create window
//	sf::RenderWindow w(sf::VideoMode(1920, 1080), "app");
//
//	// create a light source
//	candle::RadialLight light;
//	light.setRange(1000);
//	light.setBeamAngle(45);
//	light.setFade(true);
//
//
//	//Create a second light source 
//	candle::DirectedLight light1;
//	light1.setBeamWidth(100);
//	light1.setRange(1000);
//	light1.setRotation(65);
//	light1.setColor(sf::Color::White);
//	light1.setFade(true);
//	light1.setIntensity(1);
//	light1.setOrigin(sf::Vector2f(100, 100));
//	// load the image
//	sf::Texture img1;
//	if (!img1.loadFromFile("gfx/menu.png")) {
//		exit(1);
//	}
//	sf::Sprite background(img1);
//
//	// create the lighting area
//	candle::LightingArea fog(candle::LightingArea::FOG,
//		sf::Vector2f(0.f, 0.f),
//		sf::Vector2f(1920.f, 1080.f));
//	fog.setAreaColor(sf::Color::Black);
//	fog.setAreaOpacity(0.9);
//
//
//	    // create an edge pool
//	candle::EdgeVector edges;
//	//edges.emplace_back(sf::Vector2f(200.f, 100.f),
//	//    sf::Vector2f(200.f, 300.f));
//	//
//	//edges.emplace_back(sf::Vector2f(200.f, 200.f),
//	//	sf::Vector2f(100.f, 200.f));
//
//
//
//	// main loop
//	while (w.isOpen()) {
//		sf::Event e;
//		while (w.pollEvent(e)) {
//			if (e.type == sf::Event::Closed) {
//				w.close();
//			}
//			else if (e.type == sf::Event::MouseMoved) {
//				sf::Vector2f mp(sf::Mouse::getPosition(w));
//				light.setPosition(mp);
//			}
//
//			light1.setPosition(sf::Vector2f(100, 50));
//
//		}
//		light.castLight(edges.begin(), edges.end());
//		light1.castLight(edges.begin(), edges.end());
//		fog.clear();
//		fog.draw(light1);
//		fog.draw(light);
//		fog.display();
//
//		w.clear();
//		w.draw(light1);
//		w.draw(light);
//		w.draw(background);
//		w.draw(fog);
//		w.display();
//	}
//	return 0;
//}





//Version 0.1


//#include <SFML/Graphics.hpp>
//#include "Candle/RadialLight.hpp"
//#include "Candle/LightSource.hpp"
//int main() {
//    // create window
//    sf::RenderWindow w(sf::VideoMode(1280, 400), "app");
//
//    // create a light source
//    candle::RadialLight light;
//    light.setRange(1000);
//    light.setBeamAngle(20);
//    //light.setColor(sf::Color::Green);
//
//    // create an edge pool
//    candle::EdgeVector edges;
//    edges.emplace_back(sf::Vector2f(200.f, 100.f),
//        sf::Vector2f(200.f, 300.f));
//
//	edges.emplace_back(sf::Vector2f(200.f, 200.f),
//		sf::Vector2f(100.f, 200.f));
//
//    // main loop
//    while (w.isOpen()) {
//        sf::Event e;
//        while (w.pollEvent(e)) {
//            if (e.type == sf::Event::Closed) {
//                w.close();
//            }
//            else if (e.type == sf::Event::MouseMoved) {
//                sf::Vector2f mp(sf::Mouse::getPosition(w));
//                light.setPosition(mp);
//                light.castLight(edges.begin(), edges.end());
//            }
//        }
//
//        w.clear();
//        w.draw(light);
//        w.display();
//    }
//    return 0;
//}






// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
#include <iostream>
#include "Level.h"
#include "Framework/Menu.h"
#include "Framework/TileEditor.h"
#include "Framework/TileManager.h"
#include "Framework/GameState.h"
#include "Framework/World.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "Framework/Utilities.h"
#include <Windows.h>
#include "Candle/RadialLight.hpp"
#include "Candle/DirectedLight.hpp"
#include "Candle/LightingArea.hpp"




void windowProcess(sf::RenderWindow* window, Input* in, Level* level)
{
	// Handle window events.
	sf::Event event;
	while (window->pollEvent(event))
	{
		ImGui::SFML::ProcessEvent(event);  // Let ImGui process the event first.

		if (!ImGui::GetIO().WantCaptureMouse) {  // Only handle mouse input if ImGui is not using the mouse.
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					in->setLeftMouse(Input::MouseState::DOWN);
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
					in->setRightMouse(Input::MouseState::DOWN);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					in->setLeftMouse(Input::MouseState::UP);
				}
				else if (event.mouseButton.button == sf::Mouse::Right) {
					in->setRightMouse(Input::MouseState::UP);
				}
				break;
			case sf::Event::MouseMoved:
				in->setMousePosition(event.mouseMove.x, event.mouseMove.y);
				break;
			case sf::Event::MouseWheelScrolled:
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
					in->setMouseWheelDelta(static_cast<int>(event.mouseWheelScroll.delta));
				}
				break;
			}
		}

		// Handle non-mouse specific events regardless of ImGui's interest in the mouse.
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			window->setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
			level->adjustViewToWindowSize(event.size.width, event.size.height);
			break;
		case sf::Event::KeyPressed:
			in->setKeyDown(event.key.code);
			break;
		case sf::Event::KeyReleased:
			in->setKeyUp(event.key.code);
			break;
		}
	}
}


int main()
{
	InitializeResolution();
	//Create the window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "CU4012");
	ImGui::SFML::Init(window);



	// Get the handle to the native window
	HWND hwnd = window.getSystemHandle();
	// Maximize the window
	ShowWindow(hwnd, SW_MAXIMIZE);

	sf::View view;
	sf::Vector2f viewSize = sf::Vector2f(window.getSize().x, window.getSize().y);
	view.setSize(viewSize.x, viewSize.y);
	view.setCenter(viewSize.x / 2, viewSize.y / 2);
	// Initialise input and level objects.
	Input input;
	World world;
	world.setGravity(sf::Vector2f(0, 980.f));

	TileManager tileManager;
	GameState gameState;

	Level level(&window, &input, &gameState,&view,&world,&tileManager);
	Menu menu(&window, &input, &gameState);
	TileEditor tileEditor(&window, &input, &gameState, &view, &world, &tileManager);


	gameState.setCurrentState(State::LEVEL);

	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;
	float FrameRate = 60.f;


	//Lighting Test 
	// create a light source
	std::vector<std::unique_ptr<candle::RadialLight>> lights;
	candle::RadialLight* selectedLight = nullptr;


	// create the lighting area
	candle::LightingArea fog(candle::LightingArea::FOG,
		sf::Vector2f(0.f, 0.f),
		sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	fog.setAreaColor(sf::Color::Black);
	fog.setAreaOpacity(0.9);


	std::vector<std::unique_ptr<candle::LightingArea>> areas;

	candle::LightingArea* selectedArea = nullptr;



	float CurrentLightRange = 500.f;
	float CurrentLightAngle = 50.f;
	float CurrentLightRotation = 50.f;

	candle::EdgeVector edges;
	//sf::Vector2f topLeft(320.753f, 387.573f);
	//sf::Vector2f topRight(320.753f + 300.f, 387.573f);
	//sf::Vector2f bottomRight(320.753f + 300.f, 387.573f + 78.1f);
	//sf::Vector2f bottomLeft(320.753f, 387.573f + 78.1f);

	//// Add edges (clockwise or counter-clockwise)
	//edges.emplace_back(topLeft, topRight);       // Top edge
	//edges.emplace_back(topRight, bottomRight);   // Right edge
	//edges.emplace_back(bottomRight, bottomLeft); // Bottom edge
	//edges.emplace_back(bottomLeft, topLeft);     // Left edge

	// Game Loop
	while (window.isOpen())
	{
		//Process window events
		windowProcess(&window, &input, &level);

		// Calculate delta time. How much time has passed
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();
		ImGui::SFML::Update(window, sf::seconds(deltaTime));

		if (deltaTime > 1.0f / FrameRate)
		{
			deltaTime = 1.0f / FrameRate;
		}
		//add tilemanger updatelighting function here #
		tileEditor.getTileManager()->updateLighting();

		//Doing this here rather than in the classes
		//Otherwise each class has its own window.clear and window.display
		//This interferes with the imgui window
		window.clear(sf::Color(18, 33, 43));

		switch (gameState.getCurrentState())
		{
		case(State::MENU):
			menu.handleInput(deltaTime);
			menu.update(deltaTime);
			menu.render();
			break;

		case(State::LEVEL):
			world.UpdatePhysics(deltaTime);
			level.handleInput(deltaTime);
			level.update(deltaTime);
			level.render();
			break;

		case(State::TILEEDITOR):
			world.UpdatePhysics(deltaTime);
			tileEditor.handleInput(deltaTime);
			tileEditor.update(deltaTime);
			tileEditor.render();
			level.render();
			break;
		}

		// Update input class, handle pressed keys
		// Must be done last.
		//Render imgui and SFML RenderWindow

		//Add tileeditor renderlighting function here 
		tileEditor.getTileManager()->renderLighting();

		ImGui::SFML::Render(window);
		window.display();
		input.update();
	}
	ImGui::SFML::Shutdown();
}