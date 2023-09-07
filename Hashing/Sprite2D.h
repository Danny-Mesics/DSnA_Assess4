#pragma once
#include <iostream>
#include <typeinfo>
#include <map>
#include "Raylib/include/raylib.h"
#include "Hash.h"
using namespace std;

class Sprite2D
{
public:
	Sprite2D(const char* resourceName);
	~Sprite2D();

	static map<unsigned int, Sprite2D*> resources;
	static void Load();
	static void Unload();
	static Sprite2D* GetResource(const string &resource);

#pragma region Sprite Memebers
private:
	bool IsLoaded();
	void LoadResource(const char* filename);
	void UnloadResource();
	Image loadedImage;
#pragma endregion
};

