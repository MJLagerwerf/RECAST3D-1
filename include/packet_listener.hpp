#pragma once

#include <vector>

#include "packets.hpp"

namespace tomovis {

class PacketListener {
   public:
    virtual void handle(Packet& packet) = 0;
};

class PacketPublisher {
   public:
    void send(Packet& packet) {
        for (auto listener : listeners_) {
            listener->handle(packet);
        }
    }

    void add_listener(PacketListener* listener) {
        listeners_.push_back(listener);
    }

   private:
    std::vector<PacketListener*> listeners_;
};

}  // namespace tomovis
