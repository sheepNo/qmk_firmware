ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

DEFERRED_EXEC_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
RGBlIGHT_ENABLE = no
COMBO_ENABLE = yes
