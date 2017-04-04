#pragma once

#include "input_handler.hpp"
#include "ticker.hpp"
#include "graphics/interface/window.hpp"

namespace tomovis {

class ObjectComponent : public InputHandler, public Ticker, public Window {
   public:
    virtual void draw(glm::mat4 world_to_screen) const = 0;
    virtual std::string identifier() const = 0;
    void tick(float /* time_elapsed */) override {}
    void describe() override {}
};

}  // namespace tomovis
