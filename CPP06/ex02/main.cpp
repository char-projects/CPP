#include "Identify.hpp"

int main() {
    Base* instance = Identify::generate();
    Identify::identify(instance);
    delete instance;
}
