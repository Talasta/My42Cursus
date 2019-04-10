#include "AudioManager.hpp"

#include "Vars.hpp"


AudioManager* audioManager;

AudioManager::AudioManager()
{
    audioManager = this;
    m_music.setLoop(true);
}

void AudioManager::playSound(const std::string& soundName)
{
    sf::SoundBuffer* soundBuffer;
    bool newBuffer = true;

    for(unsigned char i = 0; i != m_templates.size(); ++i)
    {
        if(soundName == m_templates[i].name)
        {
            newBuffer = false;
            soundBuffer = &(m_templates[i].soundBuffer);
            break;
        }
    }

    if(newBuffer)
    {
        unsigned char index = m_templates.size();
        m_templates.emplace_back(Sound());
        m_templates[index].soundBuffer.loadFromFile("data/audio/sound/" + soundName + ".wav");
        m_templates[index].name = soundName;
        soundBuffer = &(m_templates[index].soundBuffer);
    }

    bool newSound = true;

    for(unsigned char i = 0; i != m_sounds.size(); ++i)
    {
        if(m_sounds[i].getStatus() == sf::Sound::Stopped)
        {
            newSound = false;
            m_sounds[i].setBuffer(*soundBuffer);
            m_sounds[i].play();
            break;
        }
    }

    if(newSound)
    {
        m_sounds.emplace_back(sf::Sound(*soundBuffer));
        m_sounds[m_sounds.size() - 1].play();
    }
}

void AudioManager::playMusic(const std::string& musicName)
{
    m_music.openFromFile("data/audio/music/" + musicName + ".ogg");
    m_music.play();
}

void AudioManager::pauseMusic()
{
    m_music.pause();
}

void AudioManager::resumeMusic()
{
    m_music.play();
}
