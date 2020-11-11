#include "multithreaded_application.h"


multithreaded_application::multithreaded_application() : m_waiting_to_write(false)
{
	m_render_thread = std::thread([&]
		{
			while (true)
			{
				if (!m_waiting_to_write)
				{
					m_render_data_mutex.lock();
					m_culling.Execute();
					m_renderer.Execute();
					m_render_data_mutex.unlock();
				}
			}
		});

	m_pathfinding_thread = std::thread([&]
		{
			while (true)
			{
				m_pathfinding.Execute();
			}
		});
}

void multithreaded_application::Tick()
{
	// Game mechanics

	m_input.Execute();
	m_gameLogic.Execute();
	m_physics.Execute();

	m_waiting_to_write = true;
	m_render_data_mutex.lock();
	m_waiting_to_write = false;
	m_updateRenderData.Execute();
	m_render_data_mutex.unlock();
}

