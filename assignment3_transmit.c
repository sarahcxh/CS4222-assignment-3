/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "board-peripherals.h"
#include <stdio.h>
#include "net/rime/rime.h"
#include <stdio.h>
/*---------------------------------------------------------------------------*/

static char message[50];
static void send(char message[], int size);
static int packetCounter;

PROCESS(transmit_process, "unicasting...");
AUTOSTART_PROCESSES(&transmit_process);

static const struct unicast_callbacks unicast_callbacks = {};
static struct unicast_conn uc;

static void send(char message[], int size){
	linkaddr_t addr;
	printf("%s\n",message);
	packetbuf_copyfrom(message, strlen(message));

	// COMPUTE THE ADDRESS OF THE RECEIVER FROM ITS NODE ID, FOR EXAMPLE NODEID 0xBA04 MAPS TO 0xBA AND 0x04 RESPECTIVELY
	// In decimal, if node ID is 47620, this maps to 186 (higher byte) AND 4 (lower byte)
	addr.u8[0] = 186; // HIGH BYTE or 186 in decimal (186 is 0xBA) TODO: CHANGE
    addr.u8[1] = 4; // LOW BYTE or 4 in decimal TODO: CHANGE
    if(!linkaddr_cmp(&addr, &linkaddr_node_addr)) {
        unicast_send(&uc, &addr);
    }

}

PROCESS_THREAD(transmit_process, ev, data) {

	PROCESS_EXITHANDLER(unicast_close(&uc);)
	PROCESS_BEGIN();
	unicast_open(&uc, 146, &unicast_callbacks);

	packetCounter = 1;

	// Just keep sending packets
    while (1) {
        send(packetCounter, sizeof(packetCounter))
        packetCounter++;
    }

	PROCESS_END();
}

/*---------------------------------------------------------------------------*/
