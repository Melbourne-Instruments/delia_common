/**
 *-----------------------------------------------------------------------------
 * Copyright (c) 2023-2024 Melbourne Instruments, Australia
 *-----------------------------------------------------------------------------
 * @file  common.h
 * @brief Common definitions.
 *-----------------------------------------------------------------------------
 */
#ifndef _COMMON_H
#define _COMMON_H

#include <string>
#include <sys/types.h>

// MACRO to get the full path of a MONIQUE file
#define MONIQUE_ROOT_FILE_PATH(filename) (common::MONIQUE_ROOT_DIR + std::string(filename))
#define MONIQUE_UDATA_FILE_PATH(filename) (common::MONIQUE_UDATA_DIR + std::string(filename))
#define MONIQUE_PRESET_FILE_PATH(filename) (common::MONIQUE_PRESETS_DIR + std::string(filename))
#define MONIQUE_SCRIPTS_FILE_PATH(filename) (common::MONIQUE_SCRIPTS_DIR + std::string(filename))
#define MONIQUE_CALIBRATION_FILE(filename) (common::MONIQUE_CALIBRATION_DIR + std::string(filename))
#define MONIQUE_WT_FILE(filename) (common::MONIQUE_WT_DIR + std::string(filename))
#define MONIQUE_FIRMWARE_FILE(filename) (common::MONIQUE_FIRMWARE_DIR + std::string(filename))

namespace common {
// Constants
constexpr uint NUM_LAYERS = 2;
constexpr uint NUM_VOICES = 6;
constexpr uint MAX_NUM_WAVETABLE_FILES = 127;
constexpr float MIN_TEMPO_BPM = 20;
constexpr float MAX_TEMPO_BPM = 240;
constexpr float DEFAULT_TEMPO_BPM = 60;
constexpr char MONIQUE_ROOT_DIR[] = "/home/root/delia/";
constexpr char MONIQUE_UDATA_DIR[] = "/udata/delia/";
constexpr char MONIQUE_PRESETS_DIR[] = "/udata/delia/presets/";
constexpr char MONIQUE_WT_DIR[] = "/udata/delia/wavetables/";
constexpr char MONIQUE_SCRIPTS_DIR[] = "/home/root/delia/scripts/";
constexpr char MONIQUE_CALIBRATION_DIR[] = "/udata/delia/calibration/";
constexpr char MONIQUE_VST_CONTENTS_DIR[] = "/home/root/delia/delia_vst.vst3/Contents/";
constexpr char MONIQUE_FIRMWARE_DIR[] = "/home/root/delia/firmware/";

// GUI buffer defs
constexpr int GUI_NUM_BUFFERS = 1;
constexpr int GUI_NUM_SAMPLES = 128;
constexpr int GUI_SAMPLES_SIZE = (GUI_NUM_SAMPLES * 2) * GUI_NUM_BUFFERS;

// Tempo Note Value
enum TempoNoteValue {
    QUARTER,
    EIGHTH,
    SIXTEENTH,
    THIRTYSECOND,
    QUARTER_TRIPLETS,
    EIGHTH_TRIPLETS,
    SIXTEENTH_TRIPLETS,
    THIRTYSECOND_TRIPLETS,
    NUM_TEMPO_NOTE_VALUES
};

enum EffectType {
    FX,
    SYNTH,
    NUM_FX_TYPES
};
} // namespace common

#endif // _COMMON_H
