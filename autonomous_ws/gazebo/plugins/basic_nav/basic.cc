#include <gazebo/gazebo.hh>

namespace gazebo
{
  class MoveHusky : public ModelPlugin
  {
    public: MoveHusky() : ModelPlugin()
            {
              printf("Hello World!\n");
            }

    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
            {
            }
  };
  GZ_REGISTER_WORLD_PLUGIN(MoveHusky)
}