#include "board.h"
#include "pin_mux.h"

void SystemInitHook (void) {
  CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
  BOARD_InitPins();
  BOARD_InitBootClocks();
}
