#include"../include/MediaBucket.hpp"
#include<fstream>
#include<sstream>

void MediaBucket::loadMedia(std::string filename)
{
	std::ifstream 		file;
						file.open(filename.c_str());
	

	std::string 		parse;
	std::stringstream	ss;
	do{
		getline(file, parse);
		ss<<parse;
		ss>>parse;
		if(parse == "TEXTURE") {
			ss>>parse;
			sf::Texture 	t_text;
			t_text.loadFromFile(parse.c_str());
			parse.erase(0, parse.rfind("/")+1);
			this->textures.insert(std::pair<std::string, sf::Texture>(parse, t_text));
		} else if(parse == "SOUNDBUFFER") {
			ss>>parse;
			sf::SoundBuffer 	t_buffer;
			t_buffer.loadFromFile(parse.c_str());
			parse.erase(0, parse.rfind("/")+1);
			this->soundbuffers.insert(std::pair<std::string, sf::SoundBuffer>(parse, t_buffer));
		} else if(parse == "FONT") {
			ss>>parse;
			sf::Font	 	t_font;
			t_font.loadFromFile(parse.c_str());
			parse.erase(0, parse.rfind("/")+1);
			this->fonts.insert(std::pair<std::string, sf::Font>(parse, t_font));
		}
		ss.clear();
		parse.clear();
	}while(!file.eof());
}

bool MediaBucket::loadTextureFromFile(std::string filename)
{
	sf::Texture t_text;
	if(!t_text.loadFromFile(filename.c_str())) {
		return false;
	}
	filename.erase(0, filename.rfind("/")+1);
	this->textures.insert(std::pair<std::string, sf::Texture>(filename, t_text));
	return true;
}

bool MediaBucket::loadSoundBufferFromFile(std::string filename)
{
	sf::SoundBuffer t_buffer;
	if(!t_buffer.loadFromFile(filename.c_str())) {
		return false;
	}
	filename.erase(0, filename.rfind("/")+1);
	this->soundbuffers.insert(std::pair<std::string, sf::SoundBuffer>(filename, t_buffer));
	return true;
}

bool MediaBucket::loadFontFromFile(std::string filename)
{
	sf::Font t_font;
	if(!t_font.loadFromFile(filename.c_str())) {
		return false;
	}
	filename.erase(0, filename.rfind("/")+1);
	this->fonts.insert(std::pair<std::string, sf::Font>(filename, t_font));
	return true;
}

void MediaBucket::clearAll()
{
	this->textures.clear();
	this->soundbuffers.clear();
	this->fonts.clear();
}
	
void MediaBucket::clearTextures()
{
	this->textures.clear();
}

void MediaBucket::clearSoundBuffers()
{
	this->soundbuffers.clear();
}
	
void MediaBucket::clearFonts()
{
	this->fonts.clear();
}
	
void MediaBucket::removeTexture(std::string name)
{
	this->textures.erase(name);
}

void MediaBucket::removeSoundBuffer(std::string name)
{
	this->soundbuffers.erase(name);
}

void MediaBucket::removeFont(std::string name)
{
	this->fonts.erase(name);
}

int MediaBucket::getNumberOfTextures() const
{
	return this->textures.size();
}

int MediaBucket::getNumberOfSoundBuffers() const
{
	return this->soundbuffers.size();
}

int MediaBucket::getNumberOfFonts() const
{
	return this->fonts.size();
}

sf::Texture& MediaBucket::getTexture(std::string name)
{
	return this->textures[name.c_str()];
}

sf::SoundBuffer& MediaBucket::getSoundBuffer(std::string name)
{
	return this->soundbuffers[name.c_str()];
}

sf::Font& MediaBucket::getFont(std::string name)
{
	return this->fonts[name.c_str()];
}
