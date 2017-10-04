#ifndef HUNTER_HPP_INCLUDED
#define HUNTER_HPP_INCLUDED

#include <map>

#include "System/LifeForm.hpp"
#include "System/StandardEntity.hpp"
#include "System/EventManager.hpp"
#include "System/Animation.hpp"

#include "Weapons/Weapons.hpp"
#include "LightEngine/LightEngine.hpp"

enum HunterState
{
    IDLE,
    MOVING,
    SHOOTING,
    RELOADING
};

class Hunter : public StandardEntity<Hunter>, public LifeForm
{
public:
    Hunter(float x, float y);

    void updateControls(const EventManager& em);
    void update(GameWorld& world);

    void initPhysics(GameWorld* world);
    void render();

    HunterState getCurrentState() const {return _state;}
    bool isDone() const {return false;}

    static void init();

protected:
    std::vector<Weapon*> _weapons;

    Weapon*     _currentWeapon;
    int         _weaponRank;
    bool        _releasedWeaponSwap;
    bool        _clicking;
    float       _stamina;
    float       _angleTarget;
    HunterState _state;
    HunterState _lastState;

    sf::VertexArray _vertexArray;

    Light* _shootLight;
    Light* _flashlight;
    Light* _littleLight;

    float            _feetTime;
    static Animation _feetAnimation;
    static size_t    _feetTextureID;

    void _changeState(HunterState state);
    void _changeAnimation(Animation& anim, bool wait=true);
};

#endif // HUNTER_HPP_INCLUDED
