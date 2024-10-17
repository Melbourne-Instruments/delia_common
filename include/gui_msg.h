/**
 *-----------------------------------------------------------------------------
 * Copyright (c) 2023-2024 Melbourne Instruments, Australia
 *-----------------------------------------------------------------------------
 * @file  gui_msg.h
 * @brief GUI Message definitions for MONIQUE.
 *-----------------------------------------------------------------------------
 */
#ifndef _GUI_MSG_H
#define _GUI_MSG_H

#include <cstring>

// Constants
constexpr uint MAX_PARAMS = 20;
constexpr uint LIST_MAX_LEN = 128;
constexpr uint STD_STR_LEN = 40;
constexpr uint EDIT_NAME_STR_LEN = 20;

// Layer status
enum Layer : int {
    LAYER_1 = 0,
    LAYER_2
};

// Sound scope mode
enum SoundScopeMode : int {
    SCOPE_MODE_OFF = 0,
    SCOPE_MODE_OSC,
    SCOPE_MODE_XY
};

// Soft Button ID
enum class SoftButtonId {
    BUTTON_1,
    BUTTON_2
};

// Screen Orientation
enum class ScreenOrientation {
    LEFT_RIGHT,
    RIGHT_LEFT
};

// GUI message type
enum GuiMsgType : int {
    SET_LEFT_STATUS = 0,
    SET_LAYER_STATUS,
    SET_MIDI_STATUS,
    SET_TEMPO_STATUS,
    SHOW_HOME_SCREEN,
    SHOW_LIST_ITEMS,
    LIST_SELECT_ITEM,
    SELECT_LAYER_NAME,
    SET_SOFT_BUTTONS_TEXT,
    SET_SOFT_BUTTONS_STATE,
    SHOW_NORMAL_PARAM,
    SHOW_ADSR_ENV_PARAM,
    SHOW_VCF_CUTOFF_PARAM,
    SHOW_NORMAL_PARAM_UPDATE,
    SHOW_ADSR_ENV_PARAM_UPDATE,
    SHOW_VCF_CUTOFF_PARAM_UPDATE,
    SHOW_ENUM_PARAM_UPDATE,
    SHOW_ENUM_PARAM_UPDATE_VALUE,
    SHOW_EDIT_NAME,
    EDIT_NAME_SELECT_CHAR,
    EDIT_NAME_CHANGE_CHAR,
    SHOW_MSG_BOX,
    SHOW_MSG_POPUP,
    CLEAR_BOOT_WARNING_SCREEN,
    SET_SYSTEM_COLOUR,
    SCREEN_CAPTURE
};

struct SetLeftStatusMsg {
    char status[STD_STR_LEN];
    bool modified;
};

struct SetLayerStatusMsg {
    Layer current_layer;
    bool twelve_note_mode;
    uint l1_num_voices;
    uint l2_num_voices;
};

struct SelectLayerNameMsg {
    Layer selected_layer;
};

struct SetMidiStatusMsg {
    bool midi_active;
};

struct SetTempoStatusMsg {
    char tempo_value[STD_STR_LEN];
};

struct ShowHomeScreenMsg {
    char preset_name[STD_STR_LEN];
    bool preset_modified;
    SoundScopeMode scope_mode;
};

struct ShowListItemsMsg {
    uint num_items;
    uint selected_item;
    char list_items[LIST_MAX_LEN][STD_STR_LEN];
    bool process_enabled_state;
    bool list_item_enabled[LIST_MAX_LEN];
    bool list_item_separator[LIST_MAX_LEN];
};

struct ListSelectItemMsg {
    uint selected_item;
    bool wt_list;
};

struct SetSoftButtonsTextMsg {
    char button1_text[STD_STR_LEN];
    char button2_text[STD_STR_LEN];
};

struct SetSoftButtonsStateMsg {
    int button1_state;
    int button2_state;
};

struct ShowNormalParamMsg {
    char name[STD_STR_LEN];
    char value_string[STD_STR_LEN];
    char display_string[STD_STR_LEN];
    char value_tag[STD_STR_LEN];
    uint num_items;
    uint selected_item;
    char list_items[LIST_MAX_LEN][STD_STR_LEN];
    bool list_item_enabled[LIST_MAX_LEN];
    bool list_item_separator[LIST_MAX_LEN];
    bool force_show_list;
    bool show_scope;
    char l1_patch_name[STD_STR_LEN];
    char l2_patch_name[STD_STR_LEN];
    ScreenOrientation screen_orientation;
};

struct ShowAdsrEnvParamMsg {
    char name[STD_STR_LEN];
    char value_string[STD_STR_LEN];
    char display_string[STD_STR_LEN];
    float attack;
    float decay;
    float sustain;
    float release;
    float level;
    uint num_items;
    uint selected_item;
    char list_items[LIST_MAX_LEN][STD_STR_LEN];
    bool list_item_enabled[LIST_MAX_LEN];
    bool list_item_separator[LIST_MAX_LEN];
};

struct ShowVcfCutoffParamMsg {
    char name[STD_STR_LEN];
    char value_string[STD_STR_LEN];
    char display_string[STD_STR_LEN];
    float hp_filter;
    float lp_filter;
    uint num_items;
    uint selected_item;
    char list_items[LIST_MAX_LEN][STD_STR_LEN];
    bool list_item_enabled[LIST_MAX_LEN];
    bool list_item_separator[LIST_MAX_LEN];
};

struct ShowNormalParamUpdateMsg {
    char name[STD_STR_LEN];
    char value_string[STD_STR_LEN];
    char display_string[STD_STR_LEN];
    char value_tag[STD_STR_LEN];
    int selected_item;
    ScreenOrientation screen_orientation;
};

struct ShowAdsrEnvParamUpdateMsg {
    char name[STD_STR_LEN];
    char value_string[STD_STR_LEN];
    char display_string[STD_STR_LEN];
    float attack;
    float decay;
    float sustain;
    float release;
    float level;
    int selected_item;
};

struct ShowVcfCutoffParamUpdateMsg {
    char name[STD_STR_LEN];
    char value_string[STD_STR_LEN];
    char display_string[STD_STR_LEN];
    float hp_filter;
    float lp_filter;
    int selected_item;
};

struct ShowEnumParamUpdateMsg {
    char name[STD_STR_LEN];
    uint num_items;
    uint selected_item;
    char list_items[LIST_MAX_LEN][STD_STR_LEN];
    bool wt_list;
};

struct ShowEditNameMsg {
    char name[STD_STR_LEN];
};

struct EditNameSelectCharMsg {
    uint selected_char;
};

struct EditNameChangeCharMsg {
    uint change_char;
};

struct ShowMsgBoxMsg {
    bool show;
    bool show_hourglass;
    char line_1[STD_STR_LEN];
    char line_2[STD_STR_LEN];
    char line_3[STD_STR_LEN];
};

struct ShowMsgPopupMsg {
    char line_1[STD_STR_LEN];
    char line_2[STD_STR_LEN];
};

struct SetSystemColour {
    char colour[STD_STR_LEN];
};

// GUI message
struct GuiMsg {
    GuiMsgType type;

    union {
        SetLeftStatusMsg left_status;
        SetLayerStatusMsg layer_status;
        SetMidiStatusMsg midi_status;
        SetTempoStatusMsg tempo_status;
        ShowHomeScreenMsg home_screen;
        ShowListItemsMsg list_items;
        ListSelectItemMsg list_select_item;
        SelectLayerNameMsg select_layer_name;
        SetSoftButtonsTextMsg soft_buttons_text;
        SetSoftButtonsStateMsg soft_buttons_state;
        ShowNormalParamMsg show_normal_param;
        ShowAdsrEnvParamMsg show_adsr_env_param;
        ShowVcfCutoffParamMsg show_vcf_cutoff_param;
        ShowNormalParamUpdateMsg show_normal_param_update;
        ShowAdsrEnvParamUpdateMsg show_adsr_env_param_update;
        ShowVcfCutoffParamUpdateMsg show_vcf_cutoff_param_update;
        ShowEnumParamUpdateMsg enum_param_update;
        ShowEditNameMsg edit_name;
        EditNameSelectCharMsg edit_name_select_char;
        EditNameChangeCharMsg edit_name_change_char;
        ShowMsgBoxMsg msg_box;
        ShowMsgPopupMsg msg_popup;
        SetSystemColour system_colour;
    };

    // Constructors
    GuiMsg() { std::memset(&show_normal_param, 0, sizeof(show_normal_param)); }

    GuiMsg(GuiMsgType t) :
        type(t) { std::memset(&show_normal_param, 0, sizeof(show_normal_param)); }

    ~GuiMsg() {}
};

// QT metatypes
#ifdef QT_VERSION
Q_DECLARE_METATYPE(SetLeftStatusMsg);
Q_DECLARE_METATYPE(SetLayerStatusMsg);
Q_DECLARE_METATYPE(SetMidiStatusMsg);
Q_DECLARE_METATYPE(SetTempoStatusMsg);
Q_DECLARE_METATYPE(ShowHomeScreenMsg);
Q_DECLARE_METATYPE(ShowListItemsMsg);
Q_DECLARE_METATYPE(ListSelectItemMsg);
Q_DECLARE_METATYPE(SelectLayerNameMsg);
Q_DECLARE_METATYPE(SetSoftButtonsTextMsg);
Q_DECLARE_METATYPE(SetSoftButtonsStateMsg);
Q_DECLARE_METATYPE(ShowNormalParamMsg);
Q_DECLARE_METATYPE(ShowAdsrEnvParamMsg);
Q_DECLARE_METATYPE(ShowVcfCutoffParamMsg);
Q_DECLARE_METATYPE(ShowNormalParamUpdateMsg);
Q_DECLARE_METATYPE(ShowAdsrEnvParamUpdateMsg);
Q_DECLARE_METATYPE(ShowVcfCutoffParamUpdateMsg);
Q_DECLARE_METATYPE(ShowEnumParamUpdateMsg);
Q_DECLARE_METATYPE(ShowEditNameMsg);
Q_DECLARE_METATYPE(EditNameSelectCharMsg);
Q_DECLARE_METATYPE(EditNameChangeCharMsg);
Q_DECLARE_METATYPE(ShowMsgBoxMsg);
Q_DECLARE_METATYPE(ShowMsgPopupMsg);
Q_DECLARE_METATYPE(SetSystemColour);
#endif

#endif // _GUI_MSG_H
