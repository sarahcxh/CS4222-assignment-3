CONTIKI = ../..

all: example-abc example-mesh example-collect example-trickle example-polite \
     example-rudolph1 example-rudolph2 example-rucb \
     example-runicast example-unicast example-neighbors assignment3_transmit

CONTIKI_WITH_RIME = 1
include $(CONTIKI)/Makefile.include
