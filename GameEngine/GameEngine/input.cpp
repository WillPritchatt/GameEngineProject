#include "input.h"

void input::Update(void)
{
	m_keyboardState = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&m_event) != NULL)
	{
		//check for key down
		if (m_event.type == SDL_KEYDOWN) 
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;
			
			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				m_keysPressed[KEY_ESCAPE] = true;
				break;

			case SDLK_r:
				m_keysPressed[KEY_R] = true;
				break;

			case SDLK_g:
				m_keysPressed[KEY_G] = true;
				break;

			case SDLK_b:
				m_keysPressed[KEY_B] = true;
				break;
			}
		}

		// check for key up
		else if (m_event.type == SDL_KEYUP) 
		{
			SDL_Keycode keyPressed = m_event.key.keysym.sym;

			switch (keyPressed) 
			{
			case SDLK_r:
				m_keysPressed[KEY_R] = false;
				break;

			case SDLK_g:
				m_keysPressed[KEY_G] = false;
				break;

			case SDLK_b:
				m_keysPressed[KEY_B] = false;
				break;
			}
		}
	}
}

bool input::KeyIsPressed(SDL_Scancode key)
{
	return m_keyboardState[key];
}


input::input()
{
}

input::~input()
{
}
