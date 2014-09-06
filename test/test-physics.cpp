#include <cppcutter.h>
#include "../src/libCyberbitGame/cyberbitGame.h"

namespace test_Physics
{
	void test_physics_add(void)
	{
		Physics *physics = new Physics();
		cppcut_assert_equal(3, physics->physics_add(1, 2), cppcut_message("add 1+2"));
	}
}
