
#include "wokwi-api.h"
#include <stdint.h>
#include <stdbool.h>

#define BNO_ADDRESS 0x28

typedef struct {
  uint8_t reg;
  uint32_t roll_id;
  uint32_t pitch_id;
  uint32_t yaw_id;
} bno_state_t;

static bno_state_t state;

static bool on_connect(void *user_data, uint32_t address, bool read) {
  return address == BNO_ADDRESS;
}

static bool on_write(void *user_data, uint8_t data) {
  bno_state_t *s = user_data;
  s->reg = data;
  return true;
}

static uint8_t on_read(void *user_data) {
  bno_state_t *s = user_data;

  float value = 0;
  int16_t raw = 0;

  if (s->reg == 0x00) return 0xA0;
  if (s->reg == 0x01) return 0xFB;
  if (s->reg == 0x02) return 0x32;
  if (s->reg == 0x03) return 0x0F;
  if (s->reg == 0x04) return 0xF0;

  if (s->reg >= 0x1A && s->reg <= 0x1F) {
    if (s->reg <= 0x1B)
      value = attr_read_float(s->yaw_id);
    else if (s->reg <= 0x1D)
      value = attr_read_float(s->roll_id);
    else
      value = attr_read_float(s->pitch_id);

    raw = (int16_t)(value * 16.0f);

    uint8_t result = (s->reg % 2 == 0)
      ? (uint8_t)(raw & 0xFF)
      : (uint8_t)((raw >> 8) & 0xFF);

    s->reg++;
    return result;
  }

  s->reg++;
  return 0;
}

static void on_disconnect(void *user_data) {
}

void chip_init(void) {
  state.reg = 0;

  state.roll_id = attr_init_float("roll", 0);
  state.pitch_id = attr_init_float("pitch", 0);
  state.yaw_id = attr_init_float("yaw", 0);

  const i2c_config_t config = {
    .user_data = &state,
    .address = BNO_ADDRESS,
    .scl = pin_init("SCL", INPUT_PULLUP),
    .sda = pin_init("SDA", INPUT_PULLUP),
    .connect = on_connect,
    .read = on_read,
    .write = on_write,
    .disconnect = on_disconnect,
  };

  i2c_init(&config);
}
