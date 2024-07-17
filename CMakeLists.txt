idf_component_register(SRCS

"CircularBuffer_SM.cpp"
"esp32_i2s_parallel.c"
"Font_apple4x6_256.c"
"Font_apple5x7_256.c"
"Font_apple6x10.c"
"Font_apple8x13.c"
"Font_gohufont6x11.c"
"Font_gohufont6x11b.c"
"Font_tom_thumb.c"
"Layer.cpp"
"MatrixEsp32Hub75Calc.cpp"
"MatrixFont.cpp"
"MatrixPanelMaps.cpp"

"MatrixPanelMaps.cpp"

REQUIRES driver esp_timer esp_rom soc esp_hw_support esp_common
INCLUDE_DIRS "." )
