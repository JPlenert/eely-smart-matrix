/*
 * SmartMatrix Library - Main Refresh Class
 *
 * Copyright (c) 2020 Louis Beaudoin (Pixelmatix)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef SmartMatrix4_h
#define SmartMatrix4_h

// Temporary definition for FastLED Compatibility: to get the CRGB<->rgb24 conversion, FastLED expects SmartMatrix_h or SmartMatrix3_h to be definied, and defining SmartMatrix_h causes problems
#ifndef SmartMatrix3_h
#define SmartMatrix3_h
#endif

// I got this version code from FastLED, thanks!
#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 4)
#define SM_HAS_PRAGMA_MESSAGE
#endif

#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
#include "esp_system.h"
#include "esp_sleep.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"

#include "MatrixCommon.h"
#include "CircularBuffer_SM.h"

#include "Layer_Scrolling.h"
#include "Layer_Indexed.h"
#include "Layer_Background.h"

#include "MatrixCommonHub75.h"

#ifndef MATRIX_HARDWARE_H
#pragma GCC error "No MatrixHardware*.h file included - You must include one at the top of your sketch"
#endif

#include "MatrixPanelMaps.h"

#include "MatrixEsp32Hub75Refresh.h"
#include "MatrixEsp32Hub75Calc.h"

#define BACKGROUND_MEMSECTION

#define SMARTMATRIX_ALLOCATE_BUFFERS(matrix_name, width, height, pwm_depth, buffer_rows, panel_type, option_flags) \
    SmartMatrixHub75Refresh<pwm_depth, width, height, panel_type, option_flags> matrix_name##Refresh; \
    SmartMatrixHub75Calc<pwm_depth, width, height, panel_type, option_flags> matrix_name

#define SMARTMATRIX_ALLOCATE_BACKGROUND_LAYER(layer_name, width, height, storage_depth, background_options) \
    typedef RGB_TYPE(storage_depth) SM_RGB;                                                                 \
    static SMLayerBackground<RGB_TYPE(storage_depth), background_options> layer_name(width, height)  

#define SMARTMATRIX_ALLOCATE_SCROLLING_LAYER(layer_name, width, height, storage_depth, scrolling_options) \
    typedef RGB_TYPE(storage_depth) SM_RGB;                                                                 \
    static SMLayerScrolling<RGB_TYPE(storage_depth), scrolling_options> layer_name(width, height)  

#define SMARTMATRIX_ALLOCATE_INDEXED_LAYER(layer_name, width, height, storage_depth, indexed_options) \
    typedef RGB_TYPE(storage_depth) SM_RGB;                                                                 \
    static SMLayerIndexed<RGB_TYPE(storage_depth), indexed_options> layer_name(width, height)  

#include "MatrixEsp32Hub75Refresh_Impl.h"
#include "MatrixEsp32Hub75Calc_Impl.h"

#endif
