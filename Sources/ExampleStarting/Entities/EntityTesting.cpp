#include "EntityTesting.hpp"

Model *EntityTesting::g_model = nullptr;
Texture *EntityTesting::g_diffuse = nullptr;

EntityTesting::EntityTesting(ISpatialStructure<Entity*> *structure, const Transform &transform) :
	Entity(structure, transform)
{
	if (g_model == nullptr)
	{
		g_model = new Model("Resources/Models/ModelSphere.obj");
	}

	if (g_diffuse == nullptr)
	{
		g_diffuse = new Texture("Resources/Guis/White.png");
	}

	AddComponent(new ComponentModel(g_model, g_diffuse));
	AddComponent(new ComponentMaterial(0.0f, 0.0f));
	AddComponent(new ComponentLight(Light(Colour(0.0f, 0.3f, 1.0f), 30.0f), Vector3(0.0f, 3.0f, 0.0f)));
}