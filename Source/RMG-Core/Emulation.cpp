/*
 * Rosalie's Mupen GUI - https://github.com/Rosalie241/RMG
 *  Copyright (C) 2020 Rosalie Wanders <rosalie@mailbox.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3.
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "Emulation.hpp"
#include "m64p/Api.hpp"
#include "Error.hpp"

//
// Local Functions
//

static bool get_emulation_state(m64p_emu_state* state)
{
    std::string error;
    m64p_error ret;

    ret = m64p::Core.DoCommand(M64CMD_CORE_STATE_QUERY, M64CORE_EMU_STATE, state);
    if (ret != M64ERR_SUCCESS)
    {
        error = "get_emulation_state m64p::Core.DoCommand(M64CMD_CORE_STATE_QUERY) Failed: ";
        error += m64p::Core.ErrorMessage(ret);
        CoreSetError(error);
    }

    return ret == M64ERR_SUCCESS;
}

//
// Exported Functions
//

bool CorePauseEmulation(void)
{
    std::string error;
    m64p_error ret;

    if (!CoreIsEmulationRunning())
    {
        error = "CorePauseEmulation Failed: ";
        error += "cannot pause emulation when emulation isn't running!";\
        CoreSetError(error);
        return false;
    }

    ret = m64p::Core.DoCommand(M64CMD_PAUSE, 0, nullptr);
    if (ret != M64ERR_SUCCESS)
    {
        error = "CorePauseEmulation m64p::Core.DoCommand(M64CMD_PAUSE) Failed: ";
        error += m64p::Core.ErrorMessage(ret);
        CoreSetError(error);
    }

    return ret == M64ERR_SUCCESS;
}

bool CoreResumeEmulation(void)
{
    std::string error;
    m64p_error ret;

    if (!CoreIsEmulationPaused())
    {
        error = "CoreIsEmulationPaused Failed: ";
        error += "cannot resume emulation when emulation isn't paused!";
        CoreSetError(error);
        return false;
    }

    ret = m64p::Core.DoCommand(M64CMD_RESUME, 0, nullptr);
    if (ret != M64ERR_SUCCESS)
    {
        error = "CoreResumeEmulation m64p::Core.DoCommand(M64CMD_RESUME) Failed: ";
        error += m64p::Core.ErrorMessage(ret);
        CoreSetError(error);
    }

    return ret == M64ERR_SUCCESS;
}

bool CoreResetEmulation(bool hard)
{
    std::string error;
    m64p_error ret;

    if (CoreIsEmulationPaused())
    {
        error = "CoreResetEmulation Failed: ";
        error += "cannot reset emulation when paused!";
        CoreSetError(error);
        return false;
    }

    if (!CoreIsEmulationRunning())
    {
        error = "CoreResetEmulation Failed: ";
        error += "cannot reset emulation when emulation isn't running!";
        CoreSetError(error);
        return false;
    }

    ret = m64p::Core.DoCommand(M64CMD_RESET, hard, nullptr);
    if (ret != M64ERR_SUCCESS)
    {
        error = "CoreResetEmulation m64p::Core.DoCommand(M64CMD_RESET) Failed: ";
        error += m64p::Core.ErrorMessage(ret);
        CoreSetError(error);
    }

    return ret == M64ERR_SUCCESS;
}

bool CoreIsEmulationRunning(void)
{
    m64p_emu_state state = M64EMU_STOPPED;
    return get_emulation_state(&state) && state == M64EMU_RUNNING;
}

bool CoreIsEmulationPaused(void)
{
    m64p_emu_state state = M64EMU_STOPPED;
    return get_emulation_state(&state) && state == M64EMU_PAUSED;
}