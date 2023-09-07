#include "Sprite2D.h"

map<unsigned int, Sprite2D*> Sprite2D::resources;

Sprite2D::Sprite2D(const char* resourceName)
{
	LoadResource(resourceName);
}

Sprite2D::~Sprite2D()
{
	UnloadResource();
}

void Sprite2D::Load()
{
	int fileCount = 0;
	char** filepaths = GetDirectoryFiles("../res", &fileCount);

	for (int i = 0; i < fileCount; i++) {
		string filepath = filepaths[i];

		if (filepath == "." || filepath == "..") continue;
		filepath = "../res/" + filepath;

		string fileExtension = GetExtension(filepath.c_str());
		string filename = GetFileNameWithoutExt(filepath.c_str());

		if (fileExtension == "png") {
			unsigned int hash = HashFunction::FunctionWhichWillHash(filename.c_str(), filename.length());
			Sprite2D* resource = new Sprite2D(filepath.c_str());
			resources[hash] = resource;
			cout << "Hash key: " << hash << " File Name: " << filename << endl;
			continue;
		}
	}


	free(filepaths);
}

void Sprite2D::Unload()
{
	for (auto& resource : resources)
	{
		delete resource.second;
	}

	resources.clear();
}

Sprite2D* Sprite2D::GetResource(const string& resourceName)
{
	unsigned int hash = HashFunction::FunctionWhichWillHash(resourceName.c_str(), resourceName.length());
	auto resourceIterator = resources.find(hash);
	if (resourceIterator == resources.end()) {
		return nullptr;
	}
	return resourceIterator->second;
}

bool Sprite2D::IsLoaded()
{
	return loadedImage.data != 0u;
}

void Sprite2D::LoadResource(const char* filename)
{
	if (IsLoaded()) {
		UnloadResource();
	}

	loadedImage = LoadImage(filename);
}

void Sprite2D::UnloadResource() 
{
	if (IsLoaded()) {
		UnloadImage(loadedImage);
	}
}