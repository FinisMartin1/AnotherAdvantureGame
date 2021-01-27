#include "TextureLibrary.h"
#include "GraphicsDevice.h"
#include"Texture.h"

TextureLibrary::TextureLibrary(GraphicsDevice* gDevice)
{
	this->gDevice = gDevice;
	this->renderer = gDevice->getRenderer();
}

Texture* TextureLibrary::getArtAsset(std::string name)
{
	Texture*texture = new Texture(gDevice, name);
	auto it = artLibrary.find(name);
	if (it == artLibrary.end()) {
		artLibrary.insert(std::pair<string, Texture*>(name,texture));

		if (!artLibrary.find(name)->second->initialized)
		{
			auto artIter = artLibrary.find(name);
			artLibrary.erase(artIter);
		}
	}
	return artLibrary.find(name)->second;
}
