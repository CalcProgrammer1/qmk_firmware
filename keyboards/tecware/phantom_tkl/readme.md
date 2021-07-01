# Akko 3084BT5.0 Mechanical keyboard

3084BT5.0

Based on Royal Kludge RK61 by: [Diff-fusion](https://github.com/Diff-fusion)
Hardware Supported: SN32F260

Make example for this keyboard (after setting up your build environment):

    make akko/3084_bt5:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## scan matrix steps

1. SET ALL COLS MODE to OUTPUT and write HIGH
2. SET ALL LED PINS to OUTPUT and write LOW
3. Write ALL LED PINS Low again
4. IN LOOP FOR EACH COL
   1. SET ALL COLS MODE to OUTPUT and write LOW
   2. Write ALL LED PINS Low again
   3. Write ALL ROW PINS Low
   4. SET ALL ROWS MODE to OUTPUT and write LOW
   5. sleep 20us
   6. Write current COL HIGH
   7. SET ALL ROWS MODE to Input AND not pull-up
   8. sleep 20us
   9. Read ALL ROWS
5. SET ALL COLS MODE to OUTPUT and write HIGH
6. RESET CT16B1, TC -> 0; TMRCTRL -> 10
7. Wait TMRCTRL == 0
8. RESET CT16B1 IC and SET PWM on
9. CT16B1 start, TMRCTRL CEN SETto 1
