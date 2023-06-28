#Add the test executable

add_executable(sample8x8 sample8x8.c)

pico_set_program_name(sample8x8 "sample8x8")
pico_set_program_version(sample8x8 "0.1")

pico_enable_stdio_uart(sample8x8 1)
pico_enable_stdio_usb(sample8x8  0)

# Add the standard library to the build
target_link_libraries(sample8x8     pico_stdlib 
                                    hardware_spi
                                    )

pico_add_extra_outputs(sample8x8)

########################################
#Add the test executable

add_executable(led8x8_test led8x8_test.c)

pico_set_program_name(led8x8_test "led8x8_test")
pico_set_program_version(led8x8_test "0.1")

pico_enable_stdio_uart(led8x8_test 1)
pico_enable_stdio_usb(led8x8_test  0)

# Add the standard library to the build
target_link_libraries(led8x8_test   pico_stdlib 
                                    hardware_spi
                                    led8x8
                                    )

pico_add_extra_outputs(sample8x8)

