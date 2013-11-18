#include<map>
#include<vector>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


#ifndef MEDIA_BUCKET_HPP
#define MEDIA_BUCKET_HPP
class MediaBucket {
private:
	//	Media
	std::map<std::string, sf::Texture> 		textures;
	std::map<std::string, sf::SoundBuffer>	soundbuffers;
	std::map<std::string, sf::Font>			fonts;

public:
	void									loadMedia(std::string filename); 				//	Loads media with resource file
	bool									loadTextureFromFile(std::string filename);		
	bool									loadSoundBufferFromFile(std::string filename);
	bool									loadFontFromFile(std::string filename);

	void									clearAll();
	void									clearTextures();
	void									clearSoundBuffers();
	void									clearFonts();
	void									removeTexture(std::string name);
	void									removeSoundBuffer(std::string name);
	void									removeFont(std::string name);

	int										getNumberOfTextures() 				const;
	int										getNumberOfSoundBuffers() 			const;
	int										getNumberOfFonts() 					const;

	sf::Texture&							getTexture(std::string name);
	sf::SoundBuffer&						getSoundBuffer(std::string name);
	sf::Font&								getFont(std::string name);
};
#endif
