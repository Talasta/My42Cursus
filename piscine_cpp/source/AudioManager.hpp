#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>


struct Sound{

    std::string name;
    sf::SoundBuffer soundBuffer;
};

class AudioManager{

public:

    AudioManager();

    void playSound(const std::string& soundName);
    void playMusic(const std::string& musicName);

    void pauseMusic();
    void resumeMusic();


private:

    std::vector<sf::Sound> m_sounds;
    sf::Music m_music;

    std::vector<Sound> m_templates;
};

#endif
