/**
 * @file monique_synth_parameters.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-07-06
 *
 * Copyright (c) 2023-2024 Melbourne Instruments
 *
 */
#pragma once
#include "common.h"
#include <array>
#include <cassert>
#include <math.h>
#include <sstream>
#include <string>

namespace Monique {
constexpr int NUM_LAYERS = 2;

typedef uint Parameter;
constexpr float PARAM_BOOL_COMP = 0.25;
enum class FxMacroParams {
    FX_1_MIX,
    FX_2_MIX,
    DELAY_FB,
    DELAY_TIME,
    DELAY_TONE,
    REVERB_TIME,
    REVERB_TONE,
    REVERB_SHIMMER,
    NUM_FX_MACRO_PARAMS
};

enum GlobalParams {
    MASTER_TUNE,
    SELECTED_LAYER,
    MORPHING,
    CV_1_OFFSET,
    CV_2_OFFSET,
    CV_1_GAIN,
    CV_2_GAIN,
    CV_1_MODE,
    CV_2_MODE,

    // not saved
    RUN_FILTER_CAL,
    RUN_VCA_CAL,
    RUN_DC_CAL,
    RUN_DC_OD_CAL,
    RELOAD_CAL,
    DEBUG_1,
    METRONOME_TRIGGER,
    ALL_NOTES_OFF,
    NUM_GLOBAL_PARAMS
};

enum PresetCommonParameters {
    LAYER_1_NUM_VOICES,
    LAYER_2_NUM_VOICES,
    MORPH_MODE,
    FX_1_TYPE,
    FX_2_TYPE,
    FX_1_SLOT,
    FX_2_SLOT,
    FX_1_MIX,
    FX_2_MIX,
    CHORUS_MODE,
    DELAY_TIME,
    DELAY_FB,
    DELAY_MODE,
    DELAY_TIME_SYNC,
    DELAY_SYNC,
    DELAY_TONE,
    REVERB_PRESET,
    REVERB_TIME,
    REVERB_PREDELAY,
    REVERB_TONE,
    REVERB_SHIMMER,
    FX_MACRO_SELECT,
    NUM_STANDARD_PRESET_COMMON_PARAMS

    // Global params for modulation go after these params
};

enum class PresetCommonModMatrixDst {
    FX_SEND_LEVEL,
    FX_MACRO_LEVEL,
    NUM_DSTS
};

enum LayerParameters {
    SPLIT_LOW_NOTE,
    SPLIT_HIGH_NOTE,
    CHANNEL_FILTER,
    OUTPUT_ROUTING,
    LAYER_VOLUME,
    OCTAVE_OFFSET,
    MIDI_MOD_SRC_1_SEL,
    MIDI_MOD_SRC_2_SEL,
    EXT_IN_GAIN,
    NUM_LAYER_PARAMS
};
enum class ParaphonicModes
{
    DISABLE,
    TIME_RETRIG,
    TIME_NO_RETRIG,
    DIST_RETRIG,
    DIST_NO_RETRIG,
    NUM_MODES
};

enum CommonParameters {
    MORPH,
    STATE,
    UNISON_VOICES,
    PARAPHONIC_MODE,
    PAN_NUM,
    PAN_MODE,
    POLY_MODE,
    LFO_1_TEMPO_SYNC,
    LFO_2_TEMPO_SYNC,
    LFO_3_TEMPO_SYNC,
    LFO_1_GLOBAL,
    LFO_2_GLOBAL,
    LFO_3_GLOBAL,
    VINTAGE_AMT,
    WT_INTERPOLATE_MODE,
    PITCH_BEND_RANGE,
    GLIDE_MODE,

    // not saved
    MIDI_PITCH_BEND,
    MIDI_AFTERTOUCH,
    MIDI_SUSTAIN,
    MIDI_EXPRESSION,
    MIDI_MODWHEEL,
    MIDI_CC_1_MOD_SOURCE,
    MIDI_CC_2_MOD_SOURCE,    
    NUM_COMMON_PARAMS
};

enum class StateParameters {
    GLIDE_AMT,
    OSC_1_COARSE,
    OSC_2_COARSE,
    OSC_3_COARSE,
    OSC_1_FINE,
    OSC_2_FINE,
    OSC_3_FINE,
    SUB_OSC,
    HARD_SYNC,
    AMP_ENV_RESET,
    FILT_ENV_RESET,
    AUX_ENV_RESET,
    AUX_ENV_SLOW,
    FILT_VEL,
    AMP_VEL,
    AUX_VEL,
    UNISON_DETUNE,
    KEY_PITCH_OFFSET,
    OSC_4_MODE,
    FILTER_HP_MODE,
    FILTER_LP_MODE,
    SPIN_RESET,
    WT_SELECT,
    LFO_1_SHAPE,
    LFO_2_SHAPE,
    LFO_3_SHAPE,
    LFO_1_SLEW,
    LFO_2_SLEW,
    LFO_3_SLEW,
    LFO_1_RETRIGGER,
    LFO_2_RETRIGGER,
    LFO_3_RETRIGGER,
    LFO_1_UNIPOLAR,
    LFO_2_UNIPOLAR,
    LFO_3_UNIPOLAR,
    LFO_1_SYNC_RATE,
    LFO_2_SYNC_RATE,
    LFO_3_SYNC_RATE,
    NUM_STATE_PARAMS
};

enum class ModMatrixSrc {

    // SLOW
    KEY_PITCH,
    KEY_VELOCITY,
    AFTERTOUCH,
    MODWHEEL,

    // FAST
    LFO_1,
    LFO_2,
    LFO_3,
    FILTER_EG,
    AMP_EG,
    AUX_EG,
    OSC_1,
    OSC_2,
    OSC_3,

    // SLOW
    PANPOSITION,
    EXPRESSION,
    CV_1,
    CV_2,
    MIDI_CC_1,
    MIDI_CC_2,
    OFFSET,
    CONSTANT,
    NUM_SRCS
};

enum class PanModes {
    OFF,
    SPREAD,
    PINGPONG,
    NUM_MODES
};
constexpr int NUM_INTERP_MODES = 2;
constexpr int MAX_PANNER_VOICES = 6;
enum class ModMatrixDst {
    OSC_1_PITCH,
    OSC_1_SHAPE,
    OSC_1_LEVEL,
    OSC_2_PITCH,
    OSC_2_SHAPE,
    OSC_2_LEVEL,
    OSC_3_PITCH,
    OSC_3_SHAPE,
    OSC_3_LEVEL,
    OSC_4_LEVEL,
    FILTER_CUTOFF_HP,
    FILTER_RESONANCE_HP,
    FILTER_CUTOFF_LP,
    FILTER_RESONANCE_LP,

    // SLOW
    OSC_4_TONE,
    LFO_1_RATE,
    LFO_1_GAIN,
    LFO_2_RATE,
    LFO_2_GAIN,
    LFO_3_RATE,
    LFO_3_GAIN,
    DRIVE,
    FILTER_EG_ATT,
    FILTER_EG_DEC,
    FILTER_EG_REL,
    FILTER_EG_SUS,
    FILTER_EG_LEVEL,
    AMP_EG_ATT,
    AMP_EG_DEC,
    AMP_EG_REL,
    AMP_EG_SUS,
    AMP_EG_LEVEL,
    AUX_EG_ATT,
    AUX_EG_DEC,
    AUX_EG_REL,
    AUX_EG_SUS,
    AUX_EG_LEVEL,
    FX_SEND,
    FX_MACRO,
    SPIN,
    PAN,
    MORPH,
    NUM_DSTS
};

// Output Routing
enum class OutputRouting {
    ONE,
    TWO,
    ONE_TWO,
    NUM_OUTPUT_ROUTING_MODES
};

// Noise Modes
enum class NoiseModes {
    WHITE,
    XOR,
    EXT_L,
    EXT_R,
    LOOP,
    NUM_NOISE_MODES
};

enum class GlideModes {
    LOG,
    LINEAR,
    PORTAMENTO_LINEAR,
    NUM_GLIDE_MODES
};
enum class LfoOscShape {
    SINE,
    TRIANGLE,
    SQUARE,
    SAWTOOTH_UP,
    SAWTOOTH_DOWN,
    RANDOM,
    NUM_SHAPES
};
constexpr int MAX_PARAM_CHANGES = 256;

// Voice Mode
enum class VoiceMode {
    AUTO_LOW,
    LEGATO,
    MONO_RETRIGGER,
    POLY,
    NUM_VOICE_MODES
};

enum class State {
    A,
    B,
    NUM_STATES
};

enum class FxType {
    NONE,
    CHORUS,
    DELAY,
    REVERB,
    NUM_FX_TYPES
};

enum class FxSlot {
    ONE,
    TWO,
    NUM_FX_SLOTS
};

enum class ChorusModes {
    I,
    II,
    I_II,
    NUM_MODES
};

// Morph mode
enum class MorphMode {
    DANCE,
    DJ,
    NUM_MODES
};

enum class CvInputMode {
    NEG_10_TO_10,
    ZERO_TO_10,
    NEG_5_TO_5,
    ZERO_TO_5,
    NUM_MODES
};

enum class ReverbPreset {
    ROOM,
    PLATE_1,
    PLATE_2,
    HALL_1,
    HALL_2,
    MUM_PRESETS
};

struct TempoSyncMultipliers {
    static constexpr uint NUM_SYNC_TEMPOS = 16;
    static constexpr float _0125 = .125f;
    static constexpr float _025 = .25f;
    static constexpr float _05 = .5f;
    static constexpr float _1D = 1.f / 1.5f;
    static constexpr float _1 = 1.f;
    static constexpr float _2 = 2.f;
    static constexpr float _2D = _2 / 1.5f;
    static constexpr float _4 = 4.f;
    static constexpr float _4D = _4 / 1.5f;
    static constexpr float _4T = _4 * (4.f / 3.f);
    static constexpr float _8 = 8.f;
    static constexpr float _8T = _8 * (4.f / 3.f);
    static constexpr float _16 = 16.f;
    static constexpr float _16T = _16 * (4.f / 3.f);
    static constexpr float _32 = 32.f;
    static constexpr float _32T = _32 * (4.f / 3.f);

    constexpr float getTempoSyncMultiplier(uint select) {
        switch (select) {
        case 0:
            return _0125 / 4.f;
            break;
        case 1:
            return _025 / 4.f;
            break;
        case 2:
            return _05 / 4.f;
            break;
        case 3:
            return _1D / 4.f;
            break;
        case 4:
            return _1 / 4.f;
            break;

        case 5:
            return _2D / 4.f;
            break;

        case 6:
            return _2 / 4.f;
            break;

        case 7:
            return _4D / 4.f;
            break;

        case 8:
            return _4 / 4.f;
            break;

        case 9:
            return _4T / 4.f;
            break;

        case 10:
            return _8 / 4.f;
            break;

        case 11:
            return _8T / 4.f;
            break;

        case 12:
            return _16 / 4.f;
            break;

        case 13:
            return _16T / 4.f;
            break;

        case 14:
            return _32 / 4.f;
            break;

        case 15:
            return _32T / 4.f;
            break;

        default:
            return 1.f / 4.f;
        }
    }
};

constexpr int NUM_VOICES = 6;
constexpr int MIDI_NOTES = 128;
constexpr int MIDI_CCS = 128;
constexpr int MON_MIDI_CHANNELS = 16;
constexpr int MAX_UNISON_VOICES = 6;
constexpr int PB_RANGE_MIN = 0;
constexpr int PB_RANGE_MAX = 12;
constexpr int PB_RANGE_NUM_POS = PB_RANGE_MIN + PB_RANGE_MAX + 1;
constexpr int OCTAVE_OFFSET_MIN = -2;
constexpr int OCTAVE_OFFSET_MAX = 2;
constexpr int OCTAVE_OFFSET_NUM_POS = std::abs(OCTAVE_OFFSET_MIN) + OCTAVE_OFFSET_MAX + 1;

constexpr int LAYER_NUM_SHIFT = 12;
constexpr int STATE_NUM_SHIFT = 11;
constexpr int PARAM_ID_MASK = 0x7FF;
constexpr int PARAM_ID_STATE_MASK = 0xFFF;
constexpr float COARSE_OCT = 2.f;
constexpr float FINE_CENTS_RANGE = 700.f;

constexpr int TOTAL_MOD_SRC = (int)ModMatrixSrc::NUM_SRCS;
constexpr int TOTAL_PRESET_COMMON_PRESET_MOD_DSTS = (int)PresetCommonModMatrixDst::NUM_DSTS;
constexpr int TOTAL_MOD_DSTS = (int)ModMatrixDst::NUM_DSTS;
constexpr int NUM_PRESET_COMMON_PARAMS = NUM_STANDARD_PRESET_COMMON_PARAMS + (TOTAL_MOD_SRC * TOTAL_PRESET_COMMON_PRESET_MOD_DSTS);
constexpr int FAST_DESTS = 14;
constexpr int SLOW_DESTS = TOTAL_MOD_DSTS - FAST_DESTS;
constexpr int FAST_SRCS = (9);
constexpr int SLOW_SRCS = TOTAL_MOD_SRC - FAST_SRCS;
constexpr int TOTAL_STATE_PARAMS = (int)StateParameters::NUM_STATE_PARAMS + (int)TOTAL_MOD_DSTS * (int)TOTAL_MOD_SRC;

constexpr auto FIRST_PRESET_COMMON_P = PresetCommonParameters::LAYER_1_NUM_VOICES;
constexpr auto LAST_PRESET_COMMON_P = PresetCommonParameters::FX_MACRO_SELECT;
constexpr auto FIRST_LAYER_P = LayerParameters::SPLIT_LOW_NOTE;
constexpr auto LAST_LAYER_P = LayerParameters::EXT_IN_GAIN;
constexpr auto FIRST_COMMON_P = CommonParameters::MORPH;
constexpr auto LAST_COMMON_P = CommonParameters::MIDI_CC_2_MOD_SOURCE;
constexpr auto FIRST_STATE_P = StateParameters::GLIDE_AMT;

constexpr int FIRST_STATE_PARAM = (int)NUM_GLOBAL_PARAMS + (int)NUM_PRESET_COMMON_PARAMS + (int)NUM_LAYER_PARAMS + (int)NUM_COMMON_PARAMS;
constexpr int NUM_PARAMS = NUM_GLOBAL_PARAMS + NUM_PRESET_COMMON_PARAMS + (NUM_LAYERS * (NUM_LAYER_PARAMS + NUM_COMMON_PARAMS + 2 * TOTAL_STATE_PARAMS));
constexpr int NUM_LAYER_0_PARAMS = NUM_GLOBAL_PARAMS + NUM_PRESET_COMMON_PARAMS + (NUM_LAYER_PARAMS + NUM_COMMON_PARAMS + 2 * TOTAL_STATE_PARAMS);

constexpr uint NUM_FX_MACRO_PARAMS = (uint)FxMacroParams::NUM_FX_MACRO_PARAMS;

enum class ParamType {
    GLOBAL,
    PRESET_COMMON,
    LAYER,
    COMMON,
    STATE
};

struct ParamDecoded {

    ParamType p_type = ParamType::GLOBAL;
    int layer_num = 0;
    State state = State::A;

    union {
        GlobalParams global_param = GlobalParams::MASTER_TUNE;
        PresetCommonParameters preset_common_param;
        LayerParameters layer_param;
        CommonParameters common_param;
        StateParameters state_param;
    };

    ParamDecoded(){

    };

    ParamDecoded(ParamType p_type_in, GlobalParams gp = (GlobalParams)0, PresetCommonParameters pcp = (PresetCommonParameters)0, LayerParameters lp = (LayerParameters)0, CommonParameters cp = (CommonParameters)0, StateParameters sp = (StateParameters)0, int layer_n = 0, State state_in = State::A) {
        p_type = p_type_in;
        switch (p_type) {
        case ParamType::GLOBAL:
            global_param = gp;
            break;
        case ParamType::PRESET_COMMON:
            preset_common_param = pcp;
            break;
        case ParamType::LAYER:
            layer_param = lp;
            layer_num = layer_n;
            break;
        case ParamType::COMMON:
            common_param = cp;
            layer_num = layer_n;
            break;
        case ParamType::STATE:
            state_param = sp;
            layer_num = layer_n;
            state = state_in;
            global_param = gp;
            break;

        default:
            break;
        }
    };

    ParamDecoded(Parameter param_id) {
        // handle global parameter decode
        if (param_id < NUM_GLOBAL_PARAMS) {
            p_type = ParamType::GLOBAL;
            global_param = (GlobalParams)param_id;
        }
        // Handle preset common params
        else if (param_id < (NUM_GLOBAL_PARAMS + NUM_PRESET_COMMON_PARAMS)) {
            p_type = ParamType::PRESET_COMMON;
            preset_common_param = (PresetCommonParameters)(param_id - NUM_GLOBAL_PARAMS);
        }
        // handle non global, decode layer ID first
        else {
            layer_num = (uint)param_id >> LAYER_NUM_SHIFT;
            param_id &= PARAM_ID_STATE_MASK;

            // handle layer & common parameters
            if (param_id < NUM_GLOBAL_PARAMS + NUM_PRESET_COMMON_PARAMS + NUM_LAYER_PARAMS) {
                p_type = ParamType::LAYER;
                layer_param = (LayerParameters)(param_id - NUM_GLOBAL_PARAMS - NUM_PRESET_COMMON_PARAMS);
            } else if (param_id < NUM_GLOBAL_PARAMS + NUM_PRESET_COMMON_PARAMS + NUM_LAYER_PARAMS + NUM_COMMON_PARAMS) {
                p_type = ParamType::COMMON;
                common_param = (CommonParameters)(param_id - NUM_GLOBAL_PARAMS - NUM_PRESET_COMMON_PARAMS - NUM_LAYER_PARAMS);
            }
            // parameter must be a state param. so decode the state first
            else {
                state = (State)((uint)param_id >> STATE_NUM_SHIFT);
                param_id &= PARAM_ID_MASK;
                p_type = ParamType::STATE;
                state_param = (StateParameters)(param_id - NUM_GLOBAL_PARAMS - NUM_PRESET_COMMON_PARAMS - NUM_LAYER_PARAMS - NUM_COMMON_PARAMS);
            }
        }
    }
};

static inline const std::array<std::string, TOTAL_PRESET_COMMON_PRESET_MOD_DSTS> preset_common_mod_dst_names_gen() {
    std::array<std::string, TOTAL_PRESET_COMMON_PRESET_MOD_DSTS> mod;
    mod.at((int)PresetCommonModMatrixDst::FX_MACRO_LEVEL) = "FX Macro Level";
    mod.at((int)PresetCommonModMatrixDst::FX_SEND_LEVEL) = "FX Send Level";
    return mod;
}

static inline const std::array<std::string, TOTAL_MOD_DSTS> mod_dst_names_gen() {
    std::array<std::string, TOTAL_MOD_DSTS> mod;
    mod.at((int)ModMatrixDst::LFO_1_RATE) = "LFO 1 Rate";
    mod.at((int)ModMatrixDst::LFO_1_GAIN) = "LFO 1 Gain";
    mod.at((int)ModMatrixDst::LFO_2_RATE) = "LFO 2 Rate";
    mod.at((int)ModMatrixDst::LFO_2_GAIN) = "LFO 2 Gain";
    mod.at((int)ModMatrixDst::LFO_3_RATE) = "LFO 3 Rate";
    mod.at((int)ModMatrixDst::LFO_3_GAIN) = "LFO 3 Gain";
    mod.at((int)ModMatrixDst::OSC_1_PITCH) = "Osc 1 Pitch";
    mod.at((int)ModMatrixDst::OSC_1_SHAPE) = "Osc 1 Shape";
    mod.at((int)ModMatrixDst::OSC_2_PITCH) = "Osc 2 Pitch";
    mod.at((int)ModMatrixDst::OSC_2_SHAPE) = "Osc 2 Shape";
    mod.at((int)ModMatrixDst::OSC_3_PITCH) = "Osc 3 Pitch";
    mod.at((int)ModMatrixDst::OSC_3_SHAPE) = "Osc 3 Shape";
    mod.at((int)ModMatrixDst::OSC_4_TONE) = "Osc 4 Tone";
    mod.at((int)ModMatrixDst::OSC_1_LEVEL) = "Osc 1 Level";
    mod.at((int)ModMatrixDst::OSC_2_LEVEL) = "Osc 2 Level";
    mod.at((int)ModMatrixDst::OSC_3_LEVEL) = "Osc 3 Level";
    mod.at((int)ModMatrixDst::OSC_4_LEVEL) = "Osc 4 Level";
    mod.at((int)ModMatrixDst::FILTER_CUTOFF_HP) = "Filter HP Cutoff";
    mod.at((int)ModMatrixDst::FILTER_RESONANCE_HP) = "Filter HP Resonance";
    mod.at((int)ModMatrixDst::FILTER_CUTOFF_LP) = "Filter LP Cutoff";
    mod.at((int)ModMatrixDst::FILTER_RESONANCE_LP) = "Filter LP Resonance";
    mod.at((int)ModMatrixDst::DRIVE) = "Drive";
    mod.at((int)ModMatrixDst::FILTER_EG_ATT) = "Filt Eg Att";
    mod.at((int)ModMatrixDst::FILTER_EG_DEC) = "Filt Eg Dec";
    mod.at((int)ModMatrixDst::FILTER_EG_SUS) = "Filt Eg Sus";
    mod.at((int)ModMatrixDst::FILTER_EG_REL) = "Filt Eg Rel";
    mod.at((int)ModMatrixDst::FILTER_EG_LEVEL) = "Filt Eg Lvl";
    mod.at((int)ModMatrixDst::AMP_EG_ATT) = "Amp Eg Att";
    mod.at((int)ModMatrixDst::AMP_EG_DEC) = "Amp Eg Dec";
    mod.at((int)ModMatrixDst::AMP_EG_SUS) = "Amp Eg Sus";
    mod.at((int)ModMatrixDst::AMP_EG_REL) = "Amp Eg Rel";
    mod.at((int)ModMatrixDst::AMP_EG_LEVEL) = "Amp Eg Lvl";
    mod.at((int)ModMatrixDst::AUX_EG_ATT) = "Aux Eg Att";
    mod.at((int)ModMatrixDst::AUX_EG_DEC) = "Aux Eg Dec";
    mod.at((int)ModMatrixDst::AUX_EG_SUS) = "Aux Eg Sus";
    mod.at((int)ModMatrixDst::AUX_EG_REL) = "Aux Eg Rel";
    mod.at((int)ModMatrixDst::AUX_EG_LEVEL) = "Aux Eg Lvl";
    mod.at((int)ModMatrixDst::FX_SEND) = "Dummy FX Send";
    mod.at((int)ModMatrixDst::FX_MACRO) = "Dummy FX Macro";
    mod.at((int)ModMatrixDst::SPIN) = "Spin";
    mod.at((int)ModMatrixDst::PAN) = "Pan";
    mod.at((int)ModMatrixDst::MORPH) = "Morph";

    // TODO: finish this list
    return mod;
}

static inline const std::array<std::string, TOTAL_MOD_SRC> mod_src_names_gen() {
    std::array<std::string, TOTAL_MOD_SRC> mod_src;
    mod_src.at((int)ModMatrixSrc::OSC_3) = "OSC_3";
    mod_src.at((int)ModMatrixSrc::OSC_1) = "OSC_1";
    mod_src.at((int)ModMatrixSrc::OSC_2) = "OSC_2";
    mod_src.at((int)ModMatrixSrc::FILTER_EG) = "Filt Eg";
    mod_src.at((int)ModMatrixSrc::AMP_EG) = "Amp Eg";
    mod_src.at((int)ModMatrixSrc::AUX_EG) = "Aux Eg";
    mod_src.at((int)ModMatrixSrc::LFO_1) = "LFO 1";
    mod_src.at((int)ModMatrixSrc::LFO_2) = "LFO 2";
    mod_src.at((int)ModMatrixSrc::LFO_3) = "LFO 3";
    mod_src.at((int)ModMatrixSrc::KEY_PITCH) = "Key Pitch";
    mod_src.at((int)ModMatrixSrc::KEY_VELOCITY) = "Key Vel";
    mod_src.at((int)ModMatrixSrc::AFTERTOUCH) = "Aftertouch";
    mod_src.at((int)ModMatrixSrc::MODWHEEL) = "Modwheel";
    mod_src.at((int)ModMatrixSrc::EXPRESSION) = "Expression";
    mod_src.at((int)ModMatrixSrc::PANPOSITION) = "Pan";
    mod_src.at((int)ModMatrixSrc::MIDI_CC_1) = "Midi CC 1";
    mod_src.at((int)ModMatrixSrc::MIDI_CC_2) = "Midi CC 2";
    mod_src.at((int)ModMatrixSrc::CV_1) = "CV 1";
    mod_src.at((int)ModMatrixSrc::CV_2) = "CV 2";
    mod_src.at((int)ModMatrixSrc::OFFSET) = "Offset";
    mod_src.at((int)ModMatrixSrc::CONSTANT) = "Constant";
    return mod_src;
}

static const auto src_names = mod_src_names_gen();
static const auto dst_names = mod_dst_names_gen();

constexpr uint get_preset_common_id_from_mod_matrix(ModMatrixSrc src, PresetCommonModMatrixDst dst) {
    uint id = (uint)PresetCommonParameters::NUM_STANDARD_PRESET_COMMON_PARAMS + ((uint)src * (uint)PresetCommonModMatrixDst::NUM_DSTS + (uint)dst);
    assert(id < NUM_PRESET_COMMON_PARAMS);
    return id;
}

constexpr uint get_state_id_from_mod_matrix(ModMatrixSrc src, ModMatrixDst dst) {
    uint id = (uint)StateParameters::NUM_STATE_PARAMS + ((uint)src * (uint)ModMatrixDst::NUM_DSTS + (uint)dst);
    assert(id < TOTAL_STATE_PARAMS);
    return id;
}

constexpr uint get_b_state_id_from_mod_matrix(ModMatrixSrc src, ModMatrixDst dst) {
    uint id = TOTAL_STATE_PARAMS + (uint)StateParameters::NUM_STATE_PARAMS + ((uint)src * (uint)ModMatrixDst::NUM_DSTS + (uint)dst);
    assert(id < TOTAL_STATE_PARAMS * 2);
    return id;
}

constexpr uint get_id_from_mod_matrix(ModMatrixSrc src, ModMatrixDst dst) {
    uint id = FIRST_STATE_PARAM + get_state_id_from_mod_matrix(src, dst);
    return id;
}

constexpr uint get_b_id_from_mod_matrix(ModMatrixSrc src, ModMatrixDst dst) {
    uint id = TOTAL_STATE_PARAMS + FIRST_STATE_PARAM + get_state_id_from_mod_matrix(src, dst);
    return id;
}

constexpr uint get_id_from_state_param(StateParameters sp) {
    return (uint)sp + FIRST_STATE_PARAM;
}

constexpr uint get_b_id_from_state_param(StateParameters sp) {
    return get_id_from_state_param(sp) + TOTAL_STATE_PARAMS;
}

constexpr uint get_id_from_layer_param(LayerParameters p) {
    return (uint)NUM_GLOBAL_PARAMS + (uint)NUM_PRESET_COMMON_PARAMS + (uint)p;
}

constexpr uint get_id_from_common_param(CommonParameters p) {
    return (uint)NUM_GLOBAL_PARAMS + (uint)NUM_PRESET_COMMON_PARAMS + (uint)LayerParameters::NUM_LAYER_PARAMS + (uint)p;
}

constexpr uint state_id(StateParameters sp) {
    return (uint)sp;
}

constexpr ModMatrixSrc get_preset_common_src_from_state_id(uint id) {

    id -= ((uint)PresetCommonParameters::NUM_STANDARD_PRESET_COMMON_PARAMS );
    id /= (uint)PresetCommonModMatrixDst::NUM_DSTS;
    assert(id < (uint)ModMatrixSrc::NUM_SRCS);
    return (ModMatrixSrc)id;
}

constexpr ModMatrixSrc get_src_from_state_id(uint id) {

    id -= (uint)StateParameters::NUM_STATE_PARAMS;
    id /= (uint)ModMatrixDst::NUM_DSTS;
    assert(id < (uint)ModMatrixSrc::NUM_SRCS);
    return (ModMatrixSrc)id;
}

constexpr ModMatrixSrc get_src_from_id(uint id) {
    id -= FIRST_STATE_PARAM;
    if (id >= TOTAL_STATE_PARAMS) {
        id -= TOTAL_STATE_PARAMS;
    }
    return get_src_from_state_id(id);
}

constexpr PresetCommonModMatrixDst get_preset_common_dst_from_state_id(uint id) {
    id -= (uint)PresetCommonParameters::NUM_STANDARD_PRESET_COMMON_PARAMS;
    id %= (uint)PresetCommonModMatrixDst::NUM_DSTS;
    assert(id < (uint)ModMatrixDst::NUM_DSTS);
    return (PresetCommonModMatrixDst)id;
}

constexpr ModMatrixDst get_dst_from_state_id(uint id) {
    id -= (uint)StateParameters::NUM_STATE_PARAMS;
    id %= (uint)ModMatrixDst::NUM_DSTS;
    assert(id < (uint)ModMatrixDst::NUM_DSTS);
    return (ModMatrixDst)id;
}

constexpr ModMatrixDst get_dst_from_id(uint id) {
    id -= FIRST_STATE_PARAM;
    if (id >= TOTAL_STATE_PARAMS) {
        id -= TOTAL_STATE_PARAMS;
    }
    return get_dst_from_state_id(id);
}

constexpr auto last_state_p = get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::MORPH);

static inline const std::array<std::string, (uint)StateParameters::NUM_STATE_PARAMS> state_params_name_gen() {
    std::array<std::string, (uint)StateParameters::NUM_STATE_PARAMS> sp;
    sp.at((int)StateParameters::GLIDE_AMT) = "Glide Time";
    sp.at((int)StateParameters::OSC_1_COARSE) = "Osc 1 Coarse Tune";
    sp.at((int)StateParameters::OSC_2_COARSE) = "Osc 2 Coarse Tune";
    sp.at((int)StateParameters::OSC_3_COARSE) = "Osc 3 Coarse Tune";
    sp.at((int)StateParameters::OSC_1_FINE) = "Osc 1 Fine Tune";
    sp.at((int)StateParameters::OSC_2_FINE) = "Osc 2 Fine Tune";
    sp.at((int)StateParameters::OSC_3_FINE) = "Osc 3 Fine Tune";
    sp.at((int)StateParameters::SUB_OSC) = "Sub Osc En";
    sp.at((int)StateParameters::HARD_SYNC) = "Hard Sync En";
    sp.at((int)StateParameters::AMP_ENV_RESET) = "Amp Eg Reset";
    sp.at((int)StateParameters::FILT_ENV_RESET) = "Filt Eg Reset";
    sp.at((int)StateParameters::AUX_ENV_RESET) = "Aux Eg Reset";
    sp.at((int)StateParameters::AUX_ENV_SLOW) = "Aux Eg Slow";
    sp.at((int)StateParameters::FILT_VEL) = "Filt Eg Vel";
    sp.at((int)StateParameters::AMP_VEL) = "Amp Eg Vel";
    sp.at((int)StateParameters::AUX_VEL) = "Aux Eg Vel";
    sp.at((int)StateParameters::UNISON_DETUNE) = "Unison Detune";
    sp.at((int)StateParameters::KEY_PITCH_OFFSET) = "Key Pitch Offset";
    sp.at((int)StateParameters::OSC_4_MODE) = "Osc 4 Mode";
    sp.at((int)StateParameters::FILTER_HP_MODE) = "Filter HP Mode";
    sp.at((int)StateParameters::FILTER_LP_MODE) = "Filter LP Mode";
    sp.at((int)StateParameters::SPIN_RESET) = "Spin Reset";
    sp.at((int)StateParameters::WT_SELECT) = "WT Select";
    sp.at((int)StateParameters::LFO_1_SLEW) = "Lfo 1 Slew";
    sp.at((int)StateParameters::LFO_2_SLEW) = "Lfo 2 Slew";
    sp.at((int)StateParameters::LFO_3_SLEW) = "Lfo 3 Slew";
    sp.at((int)StateParameters::LFO_1_RETRIGGER) = "Lfo 1 Retrigger";
    sp.at((int)StateParameters::LFO_2_RETRIGGER) = "Lfo 2 Retrigger";
    sp.at((int)StateParameters::LFO_3_RETRIGGER) = "Lfo 3 Retrigger";
    sp.at((int)StateParameters::LFO_1_UNIPOLAR) = "LFO 1 Unipolar";
    sp.at((int)StateParameters::LFO_2_UNIPOLAR) = "LFO 2 Unipolar";
    sp.at((int)StateParameters::LFO_3_UNIPOLAR) = "LFO 3 Unipolar";
    sp.at((int)StateParameters::LFO_1_SHAPE) = "Lfo 1 Shape";
    sp.at((int)StateParameters::LFO_2_SHAPE) = "Lfo 2 Shape";
    sp.at((int)StateParameters::LFO_3_SHAPE) = "Lfo 3 Shape";
    sp.at((int)StateParameters::LFO_1_SYNC_RATE) = "Lfo 1 Sync Rate";
    sp.at((int)StateParameters::LFO_2_SYNC_RATE) = "Lfo 2 Sync Rate";
    sp.at((int)StateParameters::LFO_3_SYNC_RATE) = "Lfo 3 Sync Rate";
    return sp;
}

static inline const std::array<std::string, NUM_COMMON_PARAMS> common_params_name_gen() {
    std::array<std::string, NUM_COMMON_PARAMS> cp;
    cp.at((int)CommonParameters::MORPH) = "Morph";
    cp.at((int)CommonParameters::STATE) = "State";
    cp.at((int)CommonParameters::UNISON_VOICES) = "Unison Voices";
    cp.at((int)CommonParameters::PAN_MODE) = "Pan Mode";
    cp.at((int)CommonParameters::PAN_NUM) = "Pan Num";
    cp.at((int)CommonParameters::POLY_MODE) = "Poly Mode";
    cp.at((int)CommonParameters::LFO_1_TEMPO_SYNC) = "LFO 1 Tempo Sync";
    cp.at((int)CommonParameters::LFO_2_TEMPO_SYNC) = "LFO 2 Tempo Sync";
    cp.at((int)CommonParameters::LFO_3_TEMPO_SYNC) = "LFO 3 Tempo Sync";
    cp.at((int)CommonParameters::LFO_1_GLOBAL) = "LFO 1 Global";
    cp.at((int)CommonParameters::LFO_2_GLOBAL) = "LFO 2 Global";
    cp.at((int)CommonParameters::LFO_3_GLOBAL) = "LFO 3 Global";
    cp.at((int)CommonParameters::WT_INTERPOLATE_MODE) = "WT Interpolate";
    cp.at((int)CommonParameters::VINTAGE_AMT) = "Vintage Level";
    cp.at((int)CommonParameters::PARAPHONIC_MODE) = "12 Note Mode";
    cp.at((int)CommonParameters::MIDI_PITCH_BEND) = "Midi Pitch Bend";
    cp.at((int)CommonParameters::PITCH_BEND_RANGE) = "Pitch Bend Range";
    cp.at((int)CommonParameters::MIDI_AFTERTOUCH) = "Midi Aftertouch";
    cp.at((int)CommonParameters::MIDI_MODWHEEL) = "Midi Modwheel";
    cp.at((int)CommonParameters::MIDI_EXPRESSION) = "Midi Expression";
    cp.at((int)CommonParameters::MIDI_SUSTAIN) = "Midi Sustain";
    cp.at((int)CommonParameters::MIDI_CC_1_MOD_SOURCE) = "MIDI CC 1 Mod Source";
    cp.at((int)CommonParameters::MIDI_CC_2_MOD_SOURCE) = "MIDI CC 2 Mod Source";    
    cp.at((int)CommonParameters::GLIDE_MODE) = "Glide Mode";
    return cp;
}

static inline const std::array<std::string, NUM_GLOBAL_PARAMS> global_param_name_gen() {
    std::array<std::string, NUM_GLOBAL_PARAMS> gp;
    gp.at((int)GlobalParams::MASTER_TUNE) = "Master Tune";
    gp.at((int)GlobalParams::MORPHING) = "Morphing";
    gp.at((int)GlobalParams::SELECTED_LAYER) = "Selected Layer";
    gp.at((int)GlobalParams::CV_1_OFFSET) = "CV 1 Offset";
    gp.at((int)GlobalParams::CV_1_GAIN) = "CV 1 Gain";
    gp.at((int)GlobalParams::CV_1_MODE) = "CV 1 Mode";
    gp.at((int)GlobalParams::CV_2_OFFSET) = "CV 2 Offset";
    gp.at((int)GlobalParams::CV_2_GAIN) = "CV 2 Gain";
    gp.at((int)GlobalParams::CV_2_MODE) = "CV 2 Mode";

    // unsaved parameters
    gp.at((int)GlobalParams::RUN_FILTER_CAL) = "Run Filter Cal";
    gp.at((int)GlobalParams::RUN_VCA_CAL) = "Run VCA Cal";
    gp.at((int)GlobalParams::RUN_DC_CAL) = "Run DC Cal";
    gp.at((int)GlobalParams::RUN_DC_OD_CAL) = "Run DC OD Cal";
    gp.at((int)GlobalParams::RELOAD_CAL) = "Reload Cal";
    gp.at((int)GlobalParams::DEBUG_1) = "DEBUG 1";
    gp.at((int)GlobalParams::ALL_NOTES_OFF) = "All Notes Off";
    gp.at((int)GlobalParams::METRONOME_TRIGGER) = "Metronome Trigger";
    return gp;
}

static inline const std::array<std::string, NUM_LAYER_PARAMS> layer_param_name_gen() {
    std::array<std::string, NUM_LAYER_PARAMS> lp;
    lp.at((int)LayerParameters::CHANNEL_FILTER) = "Channel Filter";
    lp.at((int)LayerParameters::LAYER_VOLUME) = "Layer Volume";
    lp.at((int)LayerParameters::SPLIT_LOW_NOTE) = "Split Low Note";
    lp.at((int)LayerParameters::SPLIT_HIGH_NOTE) = "Split High Note";
    lp.at((int)LayerParameters::OUTPUT_ROUTING) = "Output Routing";
    lp.at((int)LayerParameters::OCTAVE_OFFSET) = "Octave Offset";
    lp.at((int)LayerParameters::MIDI_MOD_SRC_1_SEL) = "Midi Mod Src 1 Sel";
    lp.at((int)LayerParameters::MIDI_MOD_SRC_2_SEL) = "Midi Mod Src 2 Sel";
    lp.at((int)LayerParameters::EXT_IN_GAIN) = "Ext In Gain";
    return lp;
}

static inline const std::array<std::string, NUM_STANDARD_PRESET_COMMON_PARAMS> preset_common_param_name_gen() {
    std::array<std::string, NUM_STANDARD_PRESET_COMMON_PARAMS> pcp;
    pcp.at((int)PresetCommonParameters::LAYER_1_NUM_VOICES) = "Layer 1 Num Voices";
    pcp.at((int)PresetCommonParameters::LAYER_2_NUM_VOICES) = "Layer 2 Num Voices";
    pcp.at((int)PresetCommonParameters::MORPH_MODE) = "Morph Mode";
    pcp.at((int)PresetCommonParameters::FX_1_MIX) = "FX 1 Mix";
    pcp.at((int)PresetCommonParameters::FX_2_MIX) = "FX 2 Mix";
    pcp.at((int)PresetCommonParameters::CHORUS_MODE) = "Chorus Mode";
    pcp.at((int)PresetCommonParameters::DELAY_FB) = "Delay Feedback";
    pcp.at((int)PresetCommonParameters::DELAY_TIME) = "Delay Time";
    pcp.at((int)PresetCommonParameters::REVERB_TIME) = "Reverb Time";
    pcp.at((int)PresetCommonParameters::REVERB_PRESET) = "Reverb Preset";
    pcp.at((int)PresetCommonParameters::REVERB_PREDELAY) = "Reverb Predelay";
    pcp.at((int)PresetCommonParameters::REVERB_TONE) = "Reverb Tone";
    pcp.at((int)PresetCommonParameters::REVERB_SHIMMER) = "Reverb Shimmer";
    pcp.at((int)PresetCommonParameters::FX_MACRO_SELECT) = "FX Macro Select";
    pcp.at((int)PresetCommonParameters::DELAY_MODE) = "Delay Mode";
    pcp.at((int)PresetCommonParameters::DELAY_TIME) = "Delay Time";
    pcp.at((int)PresetCommonParameters::DELAY_TIME_SYNC) = "Delay Time Sync";
    pcp.at((int)PresetCommonParameters::DELAY_SYNC) = "Delay Sync";
    pcp.at((int)PresetCommonParameters::DELAY_TONE) = "Delay Tone";
    pcp.at((int)PresetCommonParameters::FX_1_TYPE) = "FX 1 Type";
    pcp.at((int)PresetCommonParameters::FX_2_TYPE) = "FX 2 Type";
    pcp.at((int)PresetCommonParameters::FX_1_SLOT) = "FX 1 Slot";
    pcp.at((int)PresetCommonParameters::FX_2_SLOT) = "FX 2 Slot";
    return pcp;
}

inline constexpr Parameter gen_param_id(GlobalParams param) {
    return (Parameter)param;
}

inline constexpr Parameter gen_param_id(PresetCommonParameters param) {
    return ((Parameter)param + NUM_GLOBAL_PARAMS);
}

inline constexpr Parameter gen_param_id(LayerParameters param, int layer_num) {
    return ((Parameter)param + NUM_GLOBAL_PARAMS + NUM_PRESET_COMMON_PARAMS) | (layer_num << LAYER_NUM_SHIFT);
}

inline constexpr Parameter gen_param_id(CommonParameters param, int layer_num) {
    return ((Parameter)param + NUM_GLOBAL_PARAMS + NUM_PRESET_COMMON_PARAMS + NUM_LAYER_PARAMS) | (layer_num << LAYER_NUM_SHIFT);
}

inline constexpr Parameter gen_param_id(StateParameters param, State state, int layer_num) {
    return ((Parameter)param + FIRST_STATE_PARAM) | (layer_num << LAYER_NUM_SHIFT) | ((int)state << STATE_NUM_SHIFT);
}

inline constexpr Parameter gen_param_id(ModMatrixSrc src, ModMatrixDst dst, State state, int layer_num) {
    const auto param = get_state_id_from_mod_matrix(src, dst);
    return ((Parameter)param + FIRST_STATE_PARAM) | (layer_num << LAYER_NUM_SHIFT) | ((int)state << STATE_NUM_SHIFT);
}

inline constexpr int get_layer_id(Parameter param_id) {
    return param_id >> LAYER_NUM_SHIFT;
}

inline constexpr State get_state(Parameter param_id) {
    return (State)((param_id >> STATE_NUM_SHIFT) & 1);
}

class ParamNameGenerator {
  public:
    ParamNameGenerator(){};
    ~ParamNameGenerator(){};

    const std::array<std::string, NUM_GLOBAL_PARAMS> global_parameter_names = global_param_name_gen();
    const std::array<std::string, NUM_STANDARD_PRESET_COMMON_PARAMS> preset_common_parameter_names = preset_common_param_name_gen();
    const std::array<std::string, TOTAL_PRESET_COMMON_PRESET_MOD_DSTS> preset_common_mod_dst_names = preset_common_mod_dst_names_gen();
    const std::array<std::string, NUM_LAYER_PARAMS> layer_param_names = layer_param_name_gen();
    const std::array<std::string, NUM_COMMON_PARAMS> common_parameter_names = common_params_name_gen();
    const std::array<std::string, (uint)StateParameters::NUM_STATE_PARAMS> state_parameter_names = state_params_name_gen();
    const std::array<std::string, TOTAL_MOD_SRC> mod_src_names = mod_src_names_gen();
    const std::array<std::string, TOTAL_MOD_DSTS> mod_dst_names = mod_dst_names_gen();

    std::string get_parameter_name(Parameter pid) {
        std::string name;
        ParamDecoded parameter = ParamDecoded(pid);

        std::string layer;
        if (parameter.layer_num == 0) {
            layer = ":D0";
        } else {
            layer = ":D1";
        }
        std::string state;
        if (parameter.state == State::A) {
            state = ":A";
        } else {
            state = ":B";
        }

        switch (parameter.p_type) {
        case ParamType::GLOBAL:
            name.append(global_parameter_names.at(parameter.global_param));
            name.append(":G");
            return name;
            break;
        case ParamType::PRESET_COMMON:
            if (parameter.preset_common_param < PresetCommonParameters::NUM_STANDARD_PRESET_COMMON_PARAMS) {
                name.append(preset_common_parameter_names.at(parameter.preset_common_param));
            } else {
                name.append("Mod ");
                auto src = get_preset_common_src_from_state_id((int)parameter.preset_common_param);
                name.append(mod_src_names.at((int)src));
                name.append(":");
                auto dst = get_preset_common_dst_from_state_id((int)parameter.preset_common_param);
                name.append(preset_common_mod_dst_names.at((int)dst));
            }
            name.append(":P");
            return name;
            break;
        case ParamType::LAYER:
            name.append(layer_param_names.at(parameter.layer_param));
            name.append(layer);
            name.append(":L");
            return name;
            break;
        case ParamType::COMMON:
            name.append(common_parameter_names.at(parameter.common_param));
            name.append(layer);
            name.append(":C");
            return name;
            break;
        case ParamType::STATE:
            if (parameter.state_param < StateParameters::NUM_STATE_PARAMS) {
                name.append(state_parameter_names.at((int)parameter.state_param));
            } else {
                name.append("Mod ");
                auto src = get_src_from_state_id((int)parameter.state_param);
                name.append(mod_src_names.at((int)src));
                name.append(":");
                auto dst = get_dst_from_state_id((int)parameter.state_param);
                name.append(mod_dst_names.at((int)dst));
            }
            name.append(layer);
            name.append(state);
            return name;
            break;

        default:
            break;
        }
        assert(false);
        return "";
    }
};

constexpr int BINARY_VAL_MULT = 2;
inline float state_param_to_normalised_float(uint state_param_id, float value) {
#ifdef DEBUG
    // this will trigger if a B state param is inadvertantly input into this function
    assert(state_param_id < TOTAL_STATE_PARAMS);
#endif

    switch (state_param_id) {
    case (uint)StateParameters::SUB_OSC:
        return std::round(value) / BINARY_VAL_MULT;
        break;
    case (uint)StateParameters::HARD_SYNC:
        return std::round(value) / BINARY_VAL_MULT;
        break;
    case (uint)StateParameters::OSC_4_MODE: {
        const auto val = value / static_cast<float>(Monique::NoiseModes::NUM_NOISE_MODES);
        return val;
    } break;
    case (uint(StateParameters::OSC_1_COARSE)):
    case (uint(StateParameters::OSC_2_COARSE)):
    case (uint(StateParameters::OSC_3_COARSE)):
        return (value + COARSE_OCT) / (COARSE_OCT * 2 + 1);
        break;

    case (uint(StateParameters::OSC_1_FINE)):
    case (uint(StateParameters::OSC_2_FINE)):
    case (uint(StateParameters::OSC_3_FINE)):
        return (value + FINE_CENTS_RANGE) / (FINE_CENTS_RANGE * 2);
        break;

    case (uint)StateParameters::LFO_1_SHAPE:
    case (uint)StateParameters::LFO_2_SHAPE:
    case (uint)StateParameters::LFO_3_SHAPE:
        return ((value) / (float)(LfoOscShape::NUM_SHAPES));

    case (uint)StateParameters::KEY_PITCH_OFFSET:
        return (value / (float)MIDI_NOTES);

    case (uint)StateParameters::LFO_1_SYNC_RATE:
    case (uint)StateParameters::LFO_2_SYNC_RATE:
    case (uint)StateParameters::LFO_3_SYNC_RATE:
        return (value / (float)TempoSyncMultipliers::NUM_SYNC_TEMPOS);
        break;

    //Vel sense handling
    case (uint)StateParameters::AMP_VEL:
    case (uint)StateParameters::FILT_VEL:
    case (uint)StateParameters::AUX_VEL:

    // default matrix parameter handling
    case get_state_id_from_mod_matrix(ModMatrixSrc::KEY_PITCH, ModMatrixDst::OSC_1_PITCH)... get_state_id_from_mod_matrix(ModMatrixSrc::OFFSET, ModMatrixDst::MORPH):
        return (value / 2) + .5f;
        break;

    default:
        return value;
    }
}


static inline constexpr float state_param_from_normalised_float(uint state_param_id, float value) {
    switch (state_param_id) {
    case (uint)StateParameters::SUB_OSC:
        return std::round(value * BINARY_VAL_MULT);
        break;
    case (uint)StateParameters::HARD_SYNC:
        return std::round(value * BINARY_VAL_MULT);
        break;


    case (uint)StateParameters::OSC_4_MODE: {
        const auto val = std::round(value * static_cast<float>(Monique::NoiseModes::NUM_NOISE_MODES));
        return val;
    } break;
    case (uint)StateParameters::LFO_1_SHAPE:
    case (uint)StateParameters::LFO_2_SHAPE:
    case (uint)StateParameters::LFO_3_SHAPE:
        return std::round((value) * ((float)LfoOscShape::NUM_SHAPES));
        break;

    case (uint(StateParameters::OSC_1_COARSE)):
    case (uint(StateParameters::OSC_2_COARSE)):
    case (uint(StateParameters::OSC_3_COARSE)):
        return std::round((value) * (COARSE_OCT * 2 + 1)) - COARSE_OCT;
        break;

    case (uint(StateParameters::OSC_1_FINE)):
    case (uint(StateParameters::OSC_2_FINE)):
    case (uint(StateParameters::OSC_3_FINE)):
        return FINE_CENTS_RANGE * value * 2 - FINE_CENTS_RANGE;

    case (uint(StateParameters::KEY_PITCH_OFFSET)):
        return std::round(value * (float)MIDI_NOTES);
        break;

    case (uint)StateParameters::LFO_1_SYNC_RATE:
    case (uint)StateParameters::LFO_2_SYNC_RATE:
    case (uint)StateParameters::LFO_3_SYNC_RATE:
        return std::round(value * (float)TempoSyncMultipliers::NUM_SYNC_TEMPOS);
        break;

    //Vel sense handling
    case (uint)StateParameters::AMP_VEL:
    case (uint)StateParameters::FILT_VEL:
    case (uint)StateParameters::AUX_VEL:

    // default matrix parameter handling
    case get_state_id_from_mod_matrix(ModMatrixSrc::KEY_PITCH, ModMatrixDst::OSC_1_PITCH)... get_state_id_from_mod_matrix(ModMatrixSrc::OFFSET, ModMatrixDst::MORPH):
        return value * 2 - 1.f;
        break;

    default:
        return value;
    }
}

static const inline std::array<float, TOTAL_STATE_PARAMS> state_param_init() {
    std::array<float, TOTAL_STATE_PARAMS> parameters;
    parameters.fill(0);

    // set State param non-zero defaults
    parameters.at((uint)StateParameters::LFO_1_SLEW) = .9;
    parameters.at((uint)StateParameters::LFO_2_SLEW) = 1.0;
    parameters.at((uint)StateParameters::LFO_3_SLEW) = 1.0;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::AMP_EG_SUS)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::AMP_EG_LEVEL)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::FILTER_EG_LEVEL)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::AUX_EG_LEVEL)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::LFO_1_GAIN)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::LFO_2_GAIN)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::LFO_3_GAIN)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::OSC_2_LEVEL)) = 0.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::OSC_1_LEVEL)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::OSC_1_SHAPE)) = 0;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::FILTER_CUTOFF_HP)) = 1;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::CONSTANT, ModMatrixDst::FILTER_CUTOFF_LP)) = 1;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::LFO_1, ModMatrixDst::FILTER_CUTOFF_LP)) = 0;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::LFO_1, ModMatrixDst::FILTER_CUTOFF_HP)) = 0;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::KEY_PITCH, ModMatrixDst::OSC_1_PITCH)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::KEY_PITCH, ModMatrixDst::OSC_2_PITCH)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::KEY_PITCH, ModMatrixDst::OSC_3_PITCH)) = 1.;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::KEY_VELOCITY, ModMatrixDst::AMP_EG_LEVEL)) = 0.f;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::KEY_VELOCITY, ModMatrixDst::AUX_EG_LEVEL)) = 0.f;
    parameters.at(get_state_id_from_mod_matrix(ModMatrixSrc::KEY_VELOCITY, ModMatrixDst::FILTER_EG_LEVEL)) = 0.f;

    return parameters;
}

static const inline std::array<float, TOTAL_STATE_PARAMS> normalised_state_param_init() {
    auto init = state_param_init();
    for (int i = 0; i < (int)TOTAL_STATE_PARAMS; i++)
    {
        init.at(i)= state_param_to_normalised_float(i, init.at(i));
    }
    return init;
}

// TODO: global param init function
// TODO: layer param init function
// TODO: common param init function
static const inline std::array<float, LayerParameters::NUM_LAYER_PARAMS> layer_param_init() {
    std::array<float, LayerParameters::NUM_LAYER_PARAMS> parameters;
    parameters.fill(0);
    parameters.at((int)(LayerParameters::CHANNEL_FILTER)) = .0;
    parameters.at((int)(LayerParameters::MIDI_MOD_SRC_1_SEL)) = 70.0f / (float)MIDI_CCS;
    parameters.at((int)(LayerParameters::MIDI_MOD_SRC_2_SEL)) = 71.0f / (float)MIDI_CCS;
    return parameters;
};

static const inline std::array<float, CommonParameters::NUM_COMMON_PARAMS> common_param_init() {
    std::array<float, CommonParameters::NUM_COMMON_PARAMS> parameters;
    parameters.fill(0);
    parameters.at(((int)CommonParameters::GLIDE_MODE)) = .0;
    return parameters;
}

static const inline std::array<float, NUM_PRESET_COMMON_PARAMS> preset_common_param_init() {
    std::array<float, NUM_PRESET_COMMON_PARAMS> parameters;
    parameters.fill(0);
    parameters.at((int)(PresetCommonParameters::LAYER_1_NUM_VOICES)) = ((float)NUM_VOICES - 1) * (1 / (float)NUM_VOICES);
    parameters.at((int)(PresetCommonParameters::LAYER_2_NUM_VOICES)) = 0.0;
    return parameters;
}

static const inline std::array<float, GlobalParams::NUM_GLOBAL_PARAMS> global_param_init() {
    std::array<float, GlobalParams::NUM_GLOBAL_PARAMS> parameters;
    parameters.fill(0);
    parameters.at(((int)GlobalParams::MASTER_TUNE)) = .5;
    return parameters;
}

static const inline std::array<uint, NUM_FX_MACRO_PARAMS> fx_macro_params() {
    std::array<uint, NUM_FX_MACRO_PARAMS> params;
    params.fill(0);

    // set State param non-zero defaults
    params.at((uint)FxMacroParams::DELAY_FB) = gen_param_id(PresetCommonParameters::DELAY_FB);
    params.at((uint)FxMacroParams::FX_1_MIX) = gen_param_id(PresetCommonParameters::FX_1_MIX);
    params.at((uint)FxMacroParams::FX_2_MIX) = gen_param_id(PresetCommonParameters::FX_2_MIX);
    params.at((uint)FxMacroParams::DELAY_TIME) = gen_param_id(PresetCommonParameters::DELAY_TIME);
    params.at((uint)FxMacroParams::DELAY_TONE) = gen_param_id(PresetCommonParameters::DELAY_TONE);
    params.at((uint)FxMacroParams::REVERB_TIME) = gen_param_id(PresetCommonParameters::REVERB_TIME);
    params.at((uint)FxMacroParams::REVERB_TONE) = gen_param_id(PresetCommonParameters::REVERB_TONE);
    params.at((uint)FxMacroParams::REVERB_SHIMMER) = gen_param_id(PresetCommonParameters::REVERB_SHIMMER);
    return params;
}

inline constexpr float preset_common_param_to_normalised_float(uint param_id, float value) {

    switch (param_id) {
    case (uint)PresetCommonParameters::LAYER_1_NUM_VOICES:
        return ((value - 1) / (float)NUM_VOICES);
    case (uint)PresetCommonParameters::LAYER_2_NUM_VOICES:
        return (value / (float)NUM_VOICES);
    case (uint)PresetCommonParameters::MORPH_MODE:
        return (value / (float)MorphMode::NUM_MODES);
        break;
    case (uint)PresetCommonParameters::CHORUS_MODE:
        return (value / (float)ChorusModes::NUM_MODES);
        break;
    case (uint)PresetCommonParameters::DELAY_TIME_SYNC:
        return (value / (float)TempoSyncMultipliers::NUM_SYNC_TEMPOS);
        break;
    case (uint)PresetCommonParameters::REVERB_PRESET:
        return (value / (float)ReverbPreset::MUM_PRESETS);
        break;
    case (uint)PresetCommonParameters::FX_1_TYPE:
    case (uint)PresetCommonParameters::FX_2_TYPE:
        return (value / (float)FxType::NUM_FX_TYPES);
        break;
    case (uint)PresetCommonParameters::FX_1_SLOT:
    case (uint)PresetCommonParameters::FX_2_SLOT:
        return (value / (float)FxSlot::NUM_FX_SLOTS);
        break;

    case (uint)PresetCommonParameters::FX_MACRO_SELECT:
        return std::clamp((value / (float)FxMacroParams::NUM_FX_MACRO_PARAMS),0.f,1.f - (1.0f/(float)FxMacroParams::NUM_FX_MACRO_PARAMS));
        break;

    // default matrix parameter handling
    case get_preset_common_id_from_mod_matrix(ModMatrixSrc::KEY_PITCH, PresetCommonModMatrixDst::FX_SEND_LEVEL)... get_preset_common_id_from_mod_matrix(ModMatrixSrc::OFFSET, PresetCommonModMatrixDst::FX_MACRO_LEVEL):
        return (value / 2) + .5f;
        break;

    default:
        return value;
        break;
    }
}

inline constexpr float preset_common_from_normalised_float(uint param_id, const float value) {
    switch (param_id) {
    case (uint)PresetCommonParameters::LAYER_1_NUM_VOICES:
        return std::round(value * (float)NUM_VOICES) + 1;
        break;
    case (uint)PresetCommonParameters::LAYER_2_NUM_VOICES:
        return std::round(value * (float)NUM_VOICES);
        break;
    case (uint)PresetCommonParameters::MORPH_MODE:
        return std::round(value * (float)MorphMode::NUM_MODES);
        break;
    case (uint)PresetCommonParameters::CHORUS_MODE:
        return std::round(value * (float)ChorusModes::NUM_MODES);
        break;
    case (uint)PresetCommonParameters::DELAY_TIME_SYNC:
        return std::round(value * (float)TempoSyncMultipliers::NUM_SYNC_TEMPOS);
        break;
    case (uint)PresetCommonParameters::REVERB_PRESET:
        return std::round(value * (float)ReverbPreset::MUM_PRESETS);
        break;
    case (uint)PresetCommonParameters::FX_1_TYPE:
    case (uint)PresetCommonParameters::FX_2_TYPE:
        return std::round(value * (float)FxType::NUM_FX_TYPES);
        break;
    case (uint)PresetCommonParameters::FX_1_SLOT:
    case (uint)PresetCommonParameters::FX_2_SLOT:
        return std::round(value * (float)FxSlot::NUM_FX_SLOTS);
        break;

    case (uint)PresetCommonParameters::FX_MACRO_SELECT:
        return std::round(value * (float)FxMacroParams::NUM_FX_MACRO_PARAMS);
        break;

    // default matrix parameter handling
    case get_preset_common_id_from_mod_matrix(ModMatrixSrc::KEY_PITCH, PresetCommonModMatrixDst::FX_SEND_LEVEL)... get_preset_common_id_from_mod_matrix(ModMatrixSrc::OFFSET, PresetCommonModMatrixDst::FX_MACRO_LEVEL):
        return value * 2 - 1.f;
        break;

    default:
        return value;
        break;
    }
}

inline constexpr float to_normalised_float(CommonParameters param_id, float value) {
    switch (param_id) {
    case MORPH:
        return value;
        break;

    case CommonParameters::POLY_MODE:
        return (value / (float)(VoiceMode::NUM_VOICE_MODES));
        break;
    case CommonParameters::UNISON_VOICES:
        return ((value - 1) / (float)(MAX_UNISON_VOICES));
        break;
    case CommonParameters::PAN_MODE:
        return (value / (float)(PanModes::NUM_MODES));
        break;
    case CommonParameters::LFO_1_GLOBAL:
    case CommonParameters::LFO_2_GLOBAL:
    case CommonParameters::LFO_3_GLOBAL:
        return (value / (float)(2.f));
        break;
    case CommonParameters::PAN_NUM:
        return ((value - 1) / (float)(MAX_PANNER_VOICES));
        break;
    case CommonParameters::GLIDE_MODE:
        return (value / (float)(GlideModes::NUM_GLIDE_MODES));
        break;
    case CommonParameters::PITCH_BEND_RANGE:
        return (value + PB_RANGE_MIN) / (float)PB_RANGE_NUM_POS;
        break;

    case CommonParameters::WT_INTERPOLATE_MODE:
        return (value / (float)(NUM_INTERP_MODES));
        break;
    case CommonParameters::PARAPHONIC_MODE:
        return (value / (float)((int)ParaphonicModes::NUM_MODES));
        break;
    default:
        return value;
        break;
    }
}

inline constexpr float from_normalised_float(const CommonParameters param_id, const float value) {
    switch (param_id) {
    case MORPH:
        return value;
        break;
    case CommonParameters::POLY_MODE:
        return std::round(value * (float)(VoiceMode::NUM_VOICE_MODES));
        break;
    case CommonParameters::WT_INTERPOLATE_MODE:
        return std::round(value * (float)(NUM_INTERP_MODES));
        break;
    case CommonParameters::PARAPHONIC_MODE:
        return std::round(value * (float)(int)ParaphonicModes::NUM_MODES);
        break;
    case CommonParameters::GLIDE_MODE:
        return std::round(value * (float)(GlideModes::NUM_GLIDE_MODES));
        break;

    case CommonParameters::UNISON_VOICES:
        return 1 + std::round(value * (float)(MAX_UNISON_VOICES));
        break;
    case CommonParameters::PAN_MODE:
        return std::round(value * (float)(PanModes::NUM_MODES));
        break;
    case CommonParameters::LFO_1_GLOBAL:
    case CommonParameters::LFO_2_GLOBAL:
    case CommonParameters::LFO_3_GLOBAL:
        return std::round(value * (float)(2.f));
        break;
    case CommonParameters::PAN_NUM:
        return 1 + std::round(value * (float)(MAX_PANNER_VOICES));
        break;
    case CommonParameters::PITCH_BEND_RANGE:
        return PB_RANGE_MIN + std::round(value * (float)PB_RANGE_NUM_POS);
        break;
    case CommonParameters::MIDI_PITCH_BEND:
        return (value - 0.5f) * 2.f;
    default:
        return value;
        break;
    }
}

constexpr inline float to_normalised_float(LayerParameters param_id, float value) {
    switch (param_id) {
    case LayerParameters::SPLIT_LOW_NOTE:
    case LayerParameters::SPLIT_HIGH_NOTE:
        return value / (float)MIDI_NOTES;
        break;
    case LayerParameters::MIDI_MOD_SRC_1_SEL:
    case LayerParameters::MIDI_MOD_SRC_2_SEL:
        return value / (float)MIDI_CCS;
        break;
    case LayerParameters::CHANNEL_FILTER:
        return value / (float)(MON_MIDI_CHANNELS + 1);
        break;
    case LayerParameters::OUTPUT_ROUTING:
        return value / (float)OutputRouting::NUM_OUTPUT_ROUTING_MODES;
        break;
    case LayerParameters::OCTAVE_OFFSET:
        return (value + std::abs(OCTAVE_OFFSET_MIN)) / (float)OCTAVE_OFFSET_NUM_POS;
        break;

    default:
        return value;
        break;
    }
}

constexpr inline float to_normalised_float(GlobalParams param_id, float value) {
    switch (param_id) {
    case GlobalParams::CV_1_MODE:
    case GlobalParams::CV_2_MODE:
        return value / (float)CvInputMode::NUM_MODES;
        break;

        case GlobalParams::CV_1_GAIN:
        case GlobalParams::CV_1_OFFSET:
        case GlobalParams::CV_2_GAIN:
        case GlobalParams::CV_2_OFFSET:
        return value / 2 + 0.5f;
        break;
    case GlobalParams::METRONOME_TRIGGER:
    return value /2.f;
    default:
        return value;
        break;
    }
}

inline float from_normalised_float(LayerParameters param_id, float value) {
    switch (param_id) {
    case LayerParameters::SPLIT_LOW_NOTE:
    case LayerParameters::SPLIT_HIGH_NOTE:
        return std::round(value * (float)MIDI_NOTES);
        break;
    case LayerParameters::MIDI_MOD_SRC_1_SEL:
    case LayerParameters::MIDI_MOD_SRC_2_SEL:
        return std::round(value * (float)MIDI_CCS);
        break;
    case LayerParameters::CHANNEL_FILTER:
        return std::round(value * (float)(MON_MIDI_CHANNELS + 1));
        break;
    case LayerParameters::OUTPUT_ROUTING:
        return std::round(value * (float)OutputRouting::NUM_OUTPUT_ROUTING_MODES);
        break;
    case LayerParameters::OCTAVE_OFFSET:
        return OCTAVE_OFFSET_MIN + std::round(value * (float)OCTAVE_OFFSET_NUM_POS);
        break;

    default:
        return value;
        break;
    }
}

inline float from_normalised_float(GlobalParams param_id, float value) {
    switch (param_id) {
    case GlobalParams::CV_1_MODE:
    case GlobalParams::CV_2_MODE:
        return std::round(value * (float)CvInputMode::NUM_MODES);
        break;
        case GlobalParams::CV_1_GAIN:
        case GlobalParams::CV_1_OFFSET:
        case GlobalParams::CV_2_GAIN:
        case GlobalParams::CV_2_OFFSET:
        return value * 2 - 1;
        break;
    case GlobalParams::METRONOME_TRIGGER:
        return std::round(value * 2);

    default:
        return value;
        break;
    }
}

inline float to_normalised_float(const Parameter param_id, const float value) {
    ParamDecoded param = ParamDecoded(param_id);

    switch (param.p_type) {
    case ParamType::GLOBAL:
        return to_normalised_float(param.global_param, value);
        break;
    case ParamType::PRESET_COMMON:
        return preset_common_param_to_normalised_float((uint)param.preset_common_param, value);
        break;
    case ParamType::LAYER:
        return to_normalised_float(param.layer_param, value);
        break;
    case ParamType::COMMON:
        return to_normalised_float(param.common_param, value);
        break;
    case ParamType::STATE:
        return state_param_to_normalised_float((uint)param.state_param, value);
        break;
    default:
        assert(false);
    }
    return 0;
}

inline float from_normalised_float(Parameter param_id, float value) {

    ParamDecoded param = ParamDecoded(param_id);
    switch (param.p_type) {
    case ParamType::GLOBAL:
        return from_normalised_float(param.global_param, value);
        break;
    case ParamType::PRESET_COMMON:
        return preset_common_from_normalised_float((uint)param.preset_common_param, value);
        break;
    case ParamType::LAYER:
        return from_normalised_float(param.layer_param, value);
        break;
    case ParamType::COMMON:
        return from_normalised_float(param.common_param, value);
        break;
    case ParamType::STATE:
        return state_param_from_normalised_float((uint)param.state_param, value);
        break;
    default:
        assert(false);
    }

    return 0;
}

} // namespace Monique
