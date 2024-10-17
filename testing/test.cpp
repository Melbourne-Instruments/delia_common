#include <cassert>
#include <cstdio>
#include <iostream>
#include <string_view>
#include <vector>

#include "common.h"
#include "monique_synth_parameters.h"

constexpr float param_error_thresh = 0.001;

// Testing Helper Functions
void test_synth_parameter(int param_id, float test_val) {
    float test1 = Monique::from_normalised_float(param_id, test_val);

    float error = std::fabs(Monique::to_normalised_float(param_id, test1) - test_val);
    if (error > param_error_thresh)
        printf("\n param %d, test: %f error: %f", param_id, test_val, error);
}

void test_name(std::string name) {
    assert(name != ":G");
    assert(name != ":P");
    assert(name != ":D0:C");
    assert(name != ":D1:C");
    assert(name != ":L");
    assert(name != ":A");
    assert(name != ":B");
}

int main() {
    using namespace Monique;
    {
        float test = to_normalised_float((Parameter)2, 0.5);
        test = from_normalised_float((Parameter)2, test);

        ParamNameGenerator name_generator;
        printf("\n run parameter tests for synth params");
        auto state_param_def = state_param_init();
        auto com_p_def = common_param_init();
        auto global_p_def = global_param_init();
        auto layer_p_def = layer_param_init();

        std::array<float, NUM_LAYER_0_PARAMS> param_default;
        int p_i = 0;
        for (float val : global_p_def) {
            param_default.at(p_i++) = val;
        }
        for (float val : layer_p_def) {
            param_default.at(p_i++) = val;
        }
        for (float val : com_p_def) {
            param_default.at(p_i++) = val;
        }
        for (float val : state_param_def) {
            param_default.at(p_i++) = val;
        }

        for (uint i = 0; i < FIRST_STATE_PARAM + TOTAL_STATE_PARAMS; i++) {
            auto name = name_generator.get_parameter_name((Parameter)i);
            printf("\ntest %d, %s def: %f", i, name.c_str(), param_default.at(i));

            test_name(name_generator.get_parameter_name(i));
            // test the given parameter at 3 different values
            test_synth_parameter(i, 1.0);
            test_synth_parameter(i, .5);
            test_synth_parameter(i, .0);
        }
        printf("\n test synth parameter helpers");

        static const std::string first_global = name_generator.get_parameter_name(GlobalParams::MASTER_TUNE);
        assert(first_global == "Master Tune:G");
        assert(MASTER_TUNE == 0);
        std::string last_global = name_generator.get_parameter_name(GlobalParams::ALL_NOTES_OFF);
        assert(last_global == "All Notes Off:G");
        assert(ALL_NOTES_OFF == (NUM_GLOBAL_PARAMS - 1));

        // test first & last layer param
        assert(FIRST_LAYER_P == 0);
        auto name = name_generator.get_parameter_name(gen_param_id(LayerParameters::SPLIT_LOW_NOTE, 0));
        assert(name == "Split Low Note:D0:L");
        assert(LAST_LAYER_P == (NUM_LAYER_PARAMS - 1));
        name = name_generator.get_parameter_name(gen_param_id(LayerParameters::CHANNEL_FILTER, 0));
        assert(name == "Channel Filter:D0:L");

        // test first & last common param
        assert(FIRST_COMMON_P == 0);
        assert(name_generator.get_parameter_name(gen_param_id(CommonParameters::MORPH, 0)) == "Morph:D0:C");
        assert(LAST_COMMON_P == (NUM_COMMON_PARAMS - 1));
        auto n_l = name_generator.get_parameter_name(gen_param_id(CommonParameters::MIDI_MODWHEEL, 0));
        assert(n_l == "Midi Modwheel:D0:C");

        // test first and last normal state params
        assert((uint)FIRST_STATE_P == 0);
        name = name_generator.get_parameter_name(gen_param_id(StateParameters::GLIDE_AMT, State::A, 0));
        assert(name == "Glide Time:D0:A");
        name = name_generator.get_parameter_name(gen_param_id(StateParameters::GLIDE_AMT, State::B, 0));
        assert(name == "Glide Time:D0:B");
        assert((uint)StateParameters::LFO_3_SYNC_RATE == ((uint)StateParameters::NUM_STATE_PARAMS - 1));
        assert(name_generator.get_parameter_name(gen_param_id(StateParameters::LFO_3_SYNC_RATE, State::A, 0)) == "Lfo 3 Sync Rate:D0:A");
        assert(name_generator.get_parameter_name(gen_param_id(StateParameters::LFO_3_SYNC_RATE, State::B, 0)) == "Lfo 3 Sync Rate:D0:B");

        // test first Mod matrix param
        {
            auto dst = ModMatrixDst::OSC_1_PITCH;
            auto src = ModMatrixSrc::KEY_PITCH;
            assert((uint)dst == 0);
            assert((uint)src == 0);
            uint mod_param = gen_param_id(src, dst, State::A, 0);
            auto name = name_generator.get_parameter_name(mod_param);
            assert(name == "Mod Key Pitch:Osc 1 Pitch:D0:A");
            mod_param = gen_param_id(src, dst, State::B, 0);
            name = name_generator.get_parameter_name(mod_param);
            assert(name == "Mod Key Pitch:Osc 1 Pitch:D0:B");
        }
        {
            // test last Mod matrix param
            auto dst = ModMatrixDst::MORPH;
            auto src = ModMatrixSrc::CONSTANT;
            assert((uint)dst == (uint)ModMatrixDst::NUM_DSTS - 1);
            assert((uint)src == (uint)ModMatrixSrc::NUM_SRCS - 1);

            uint mod_param = gen_param_id(src, dst, State::A, 0);
            auto name = name_generator.get_parameter_name(mod_param);
            assert(name == "Mod Constant:Morph:D0:A");
            mod_param = gen_param_id(src, dst, State::B, 0);
            name = name_generator.get_parameter_name(mod_param);
            assert(name == "Mod Constant:Morph:D0:B");
        }
    }
}