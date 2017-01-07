#include <husky_simulator/husky_sim_plugin.hh>

namespace gazebo {

	MoveHusky::MoveHusky() : ModelPlugin() {
		printf("Hello World!\n");
	}

	void MoveHusky::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf) {

	}
}