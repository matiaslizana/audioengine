#include "GameScript.h"

GameScript::GameScript(GameObject* go) : gameObject{go}
{
	go->AddGameScript(this);
}