// Copyright 2014 Olivier Gillet.
//
// Author: Olivier Gillet (ol.gillet@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// Driver for ADC2 - used for scanning pots.

#ifndef ELEMENTS_DRIVERS_POTS_ADC_H_
#define ELEMENTS_DRIVERS_POTS_ADC_H_

#include "stmlib/stmlib.h"

namespace clouds {

/*enum Potentiometer {
  POT_EXCITER_ENVELOPE_SHAPE,
  POT_EXCITER_BOW_LEVEL,
  POT_EXCITER_BOW_TIMBRE,
  POT_EXCITER_BOW_TIMBRE_ATTENUVERTER,
  POT_EXCITER_BLOW_LEVEL,
  POT_EXCITER_BLOW_META,
  POT_EXCITER_BLOW_META_ATTENUVERTER,
  POT_EXCITER_BLOW_TIMBRE,
  POT_EXCITER_BLOW_TIMBRE_ATTENUVERTER,
  POT_EXCITER_STRIKE_LEVEL,
  POT_EXCITER_STRIKE_META,
  POT_EXCITER_STRIKE_META_ATTENUVERTER,
  POT_EXCITER_STRIKE_TIMBRE,
  POT_EXCITER_STRIKE_TIMBRE_ATTENUVERTER,
  POT_RESONATOR_COARSE,
  POT_RESONATOR_FINE,
  POT_RESONATOR_FM_ATTENUVERTER,
  POT_RESONATOR_GEOMETRY,
  POT_RESONATOR_GEOMETRY_ATTENUVERTER,
  POT_RESONATOR_BRIGHTNESS,
  POT_RESONATOR_BRIGHTNESS_ATTENUVERTER,
  POT_RESONATOR_DAMPING,
  POT_RESONATOR_DAMPING_ATTENUVERTER,
  POT_RESONATOR_POSITION,
  POT_RESONATOR_POSITION_ATTENUVERTER,
  POT_SPACE,
  POT_SPACE_ATTENUVERTER,
  POT_LAST
};*/

enum PotsChannel {
  ADC_POSITION_POTENTIOMETER,
  ADC_PITCH_POTENTIOMETER,
  ADC_DENSITY_POTENTIOMETER,
  ADC_TEXTURE_POTENTIOMETER,
  ADC_BALANCE_POTENTIOMETER, //DRY_WET
  ADC_SPREAD_POTENTIOMETER,
  ADC_FEEDBACK_POTENTIOMETER,
  ADC_REVERB_POTENTIOMETER,
  ADC_CHANNEL_POTENTIOMETER_LAST
};

class Pots_Adc {
 public:
  Pots_Adc() { }
  ~Pots_Adc() { }
  
  void Init();
  void DeInit();
  void Scan();
  
  inline uint8_t last_read() const { return last_read_; }
  
  inline uint16_t value(uint8_t index) const { return values_[index]; }
  inline float float_value(uint8_t channel) const {
    return static_cast<float>(values_[channel]) / 65536.0f;
  }

 private:
  static uint8_t addresses_[ADC_CHANNEL_POTENTIOMETER_LAST];
  
  uint8_t index_;
  uint8_t last_read_;
  uint16_t values_[ADC_CHANNEL_POTENTIOMETER_LAST];
  
  bool state_;
  
  DISALLOW_COPY_AND_ASSIGN(Pots_Adc);
};

}  // namespace elements

#endif  // ELEMENTS_DRIVERS_POTS_ADC_H_
