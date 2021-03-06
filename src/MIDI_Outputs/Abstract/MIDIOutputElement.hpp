#pragma once

#include <AH/Containers/Updatable.hpp>
#include <Def/Def.hpp>
#include <Def/MIDIAddress.hpp>

BEGIN_CS_NAMESPACE

using MIDIOutputElement = AH::Updatable<>;
using MIDIOutputElementPotentiometer = AH::Updatable<Potentiometer>;

END_CS_NAMESPACE