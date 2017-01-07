#include <gazebo/gazebo.hh>
#include <boost/bind.hpp>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/common/Plugin.hh>

namespace gazebo
{
  class MoveHusky : public ModelPlugin
  {
    public: MoveHusky();
    public: void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);
  };

  GZ_REGISTER_MODEL_PLUGIN(MoveHusky)
}